#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//index: 0 1 2 3 4 5
//  10 2 3 4 5 ~

int main() {
	int n=0,arr[MAX],ins[100],ins_n=0,num,factor;

	printf("Enter number of inputs: ");
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
	int pos[ins_n];

	printf("Enter the positions: ");
	for(int i=0; i<ins_n; i++) {
		scanf("%d",&num);
		pos[i] = num-1;
	}

	int add=0;
	for(int i=0; i<ins_n; i++) {
		printf("\n%d\n",pos[i]);
		factor=0;
		for(int j=2; j<arr[pos[i]]; j++) {
			if(arr[pos[i]]%j==0) {
				factor++;
				break;
			}
		}
		//index: 0 1 2 3 4 5
		//  	10 23 2 3 4 5
		if(factor==0) {
			pos[i+1] += add;				// to be FIXED
			for(int l=n; l>pos[i]; l--) {
				arr[l] = arr[l-1];
			}
			arr[pos[i]] = ins[i];
			n++;
			add++;

			printf("\nIteration %d: ",i);
			for(int o=0; o<n; o++) {
				printf("%d ",arr[o]);
			}
			printf("\n");
		} else {
			printf("Element %d cannot be inserted.",ins[i]);
		}
	}

	printf("\nArray after insertion: ");
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
	return 0;
}
