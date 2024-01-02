#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main() {
  key_t key = ftok("shmfile", 65);
  int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
  char *str = (char *)shmat(shmid, (void *)0, 0);
  printf("Data read from memory: %s\n", str);
  shmdt(str);
  shmctl(shmid, IPC_RMID, NULL);
  return 0;
}