#include <stdio.h>

int main() {
	int n=0,nn=0,arr[100],num,ins[100],pos[100];

	printf("Enter number of input(s): ");
	scanf("%d",&n);

	printf("Enter inputs: ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}

	printf("\nEnter elements to be inserted: ");
	do {
		scanf("%d",&num);
		if(num!=0) {
			ins[nn] = num;
			nn++;
		}
	} while(num!=0);

loop1:
	printf("\nEnter the positions: ");
	for(int i=0; i<nn; i++) {
		scanf("%d",&num);
		if(num > n) {
			printf("Input is invalid. Try Again.");
			goto loop1;
		} else {
			pos[i] = num-1;
		}
	}

	int temp;
	for(int i=0; i<nn; i++) { //elements to be inserted
		temp = arr[pos[i]];
		arr[pos[i]] = ins[i];
		n++;
		for(int k=(n-2); k>=pos[i]; k--) {
			arr[k+1] = arr[k];
		}
		arr[pos[i]+1] = temp;
	}

	printf("\n");
	printf("\nAFTER:  ");
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}

	return 0;
}
