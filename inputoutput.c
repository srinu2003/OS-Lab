#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main()
{
    int fd[2];
    char buf1[25] = "just a test\n";
    char buf2[100];
    fd[0] = open("tfile",O_RDWR);
    fd[1] = open("tfile",O_RDWR);
    write(fd[0],buf1,strlen(buf1));
    printf("\nEnter your text now...");
    gets(buf1);
    write(fd[0],buf1,strlen(buf1));
    write(1, buf2, read(fd[1],buf2,sizeof(buf2)));
    close(fd[0]);
    close(fd[1]);
    printf("\n");
    return 0;
}