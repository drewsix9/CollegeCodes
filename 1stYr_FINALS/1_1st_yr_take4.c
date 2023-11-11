#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {
	int n,arr[MAX],num,ins[MAX],ins_n=0,newArr[MAX];

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

//	for(int i=0; i<n; i++) {
//		for(int j=0; j<ins_n; j++) {
//			if(i == pos[j] ) {
//				int factor=0;
//				for(int k=2; k<arr[pos[j]]; k++) {
//					if(arr[pos[j]]%k==0) {
//						factor++;
//						break;
//					}
//				}
//				if(factor==0) {
//					for(int l=n; l>pos[j]; l--) {
//						newArr[l] = arr[l-1];
//					}
//					newArr[pos[j]] = ins[j];
//				}
//			} else {
//				newArr[i] = arr[i];
//			}
//		}
//	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<ins_n; j++) {
			if(i == pos[j] ) {
				
			} else {
				newArr[i] = arr[i];
			}
		}
	}

	printf("\n");
	for(int i=0; i<n; i++) {
		printf("%d ",newArr[i]);
	}

	return 0;
}
