#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, arr[100], num, ins[100], nn, pos[100],k,nnn=0,cant_ins[100];

	for(int i=0; i<100; i++) {
		arr[i] = 0;
	}

	printf("Enter number of inputs: ");
	scanf("%d",&n);

	printf("\nEnter input(s): ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}

	printf("\nEnter elements to be inserted (0=stop): ");
	do {
		scanf("%d",&num);
		if(num!=0) {
			ins[nn] = num;
			nn++;
		}
	} while(num!=0);

	printf("\nEnter position to be inserted: ");
loop1 :
	for(int i=0; i<nn; i++) {
		scanf("%d",&num);
		if(num > n) {
			printf("\nWrong input. Try again: ");
			goto loop1;
		}
		pos[i] = num;
	}

//	printf("\n\nBEFORE: ");
//	for(int i=0; i<n; i++) {
//		printf("%2d ",arr[i]);
//	}

	int factor,temp;
	for(int i=0; i<nn; i++) {
		factor=0;
		for(int j=2; j<arr[pos[i]-1]; j++) {
			if(arr[pos[i]-1]%j==0) {
				factor++;
				break;
			}
		}
		if(factor==0) {
//			insert code for inserting
			temp = arr[pos[i]-1];
			arr[pos[i]-1] = ins[i];
			n++;
			for(int k=(n-2); k>=pos[i]; k--) {
				arr[k+1] = arr[k];
			}
			arr[pos[i]] = temp;
			i++;
		} else {
			cant_ins[nnn]=ins[i];
			nnn++;
		}
	}
	printf("\n");
	printf("\nArray after insertion:  ");
	for(int i=0; i<n; i++) {
		printf("%2d ",arr[i]);
	}

	for(int i=0; i<nnn; i++) {
		printf("\nElement %d cannot be inserted\n",cant_ins[i]);
	}
	return 0;
}
