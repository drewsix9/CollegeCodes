#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

bool isPrime (int arr);
int main() {
	int n,arr[MAX],ins_n=0,ins[MAX],num,pos[MAX];

	printf("Enter number of input(s): ");
	scanf("%d",&n);

	printf("Enter input(s): ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}

	printf("Enter elements to be inserted: ");
	do {
		scanf("%d",&num);
		if(num!=0) {
			ins[ins_n]=num;
			ins_n++;
		}
	} while(num!=0);

	int i=0;
	printf("Enter the positions: ");
	while(i<ins_n) {
		scanf("%d",&num);
		pos[i]=num-1;
		i++;
	}

	int cant[MAX];
	int cant_n=0;
	int factor;
	int count=0;
	for(int i=0; i<ins_n; i++) {
		factor=0;
//		printf("Checking: %d\n",arr[pos[i]+count]);
		for(int k=2; k<arr[pos[i]+count]; k++) {
			if(arr[pos[i]+count]%k==0) {
				factor++;
				break;
			}
		}
		if(factor==0) {
			for(int j=n; j>pos[i]; j--) {
				arr[j] = arr[j-1];
			}
			arr[pos[i]] = ins[i];
			n++;
			count++;
		} else {
			cant[cant_n]= ins[i];
			cant_n++;
		}
//		printf("\nIteration %d: ",i);
//		for(int i=0; i<n; i++) {
//			printf("%d ",arr[i]);
//		}
//		printf("\n");
	}

	printf("\nArray after insertion: ");
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}

	printf("\n");
	for(int i=0; i<cant_n; i++) {
		printf("Element %d cannont be inserted ",cant[i]);
	}

	return 0;
}

bool isPrime (int num) {
	int factor=0;
	for(int i=2; i<num; i++) {
		if(num%i==0) {
			return false;
		}
	}
	return true;
}

