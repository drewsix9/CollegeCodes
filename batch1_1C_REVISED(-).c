#include <stdio.h>
#include <stdlib.h>

int checkprime(int num);

int main() {

	int temp[4];
	int prime[2];
	int comp[2];
	int x,y;

	printf("Enter 4 inputs:\t");
	for(int i=1; i<=4; i++) {
		scanf("%d",&temp[i]);
	}

	for(int i=1; i<=4; i++) {
		x=1;
		if(checkprime(temp[i])==0) {
			prime[x] = temp[i];
			x++;
			if(x>2) {
				printf("\n Error");
			}
		}
		y=1;
		if(checkprime(temp[i])!=0) {
			comp[y] = temp[i];
			y++;
			if(y>2) {
				printf("\n Error");
			}
		}
	}

	printf("\n\n prime:%d",prime[1]);
	printf("\n\n prime:%d",prime[2]);
	printf("\n\n comp:%d",comp[1]);
	printf("\n\n comp:%d",comp[2]);

	return 0;
}

int checkprime(int num) {
	int factor=0;


	for(int i=2; i<num; i++) {
		if(num%i==0) {
			factor++;
		}
	}
	return factor;
}