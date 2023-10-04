#include<stdio.h>
void main(){
	int a = 1,b=0,n,c=a+b;
	printf("Enter number of terms:");
	scanf("%d",&n);
	if(n==1){
		printf("%d\n",b);
	}else if(n>1){
		printf("%d,%d,",b,a);
		n -=2;
		//printf("sdg%dsfg",n);
		while(n>0){
			c = a+b ;
			printf("%d,",c);
			b = a;
			a = c;
			n--;
		}
		printf("\n");
	}else{printf("Enter Natural numbers!");}
}	
