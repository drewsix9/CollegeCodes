#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, num[100], prime[100], comp[100], k=0, l=0;

	printf("Enter how many inputs: ");
	scanf("%d",&n);

	printf("Enter inputs:\n");
	for (int i=0; i<n; i++) {
		scanf("%d",&num[i]);
	}

	for (int i=0; i<n; i++) {
		int count = 0;
		for(int j=2; j<num[i]; j++) {
			if(num[i]%j==0) {
				count++;
			}
		}
		if (count==0) {
			prime[k] = num[i];
			k++;
		}
		if (count!=0) {
			comp[l] = num[i];
			l++;
		}
	}

	printf("\nThere are %d prime numbers present\n\n",k);
	for (int i=0; i<k; i++) {
		printf("%d ",prime[i]);
	}

	printf("\nThere are %d comp numbers present\n\n",l);
	for (int i=0; i<l; i++) {
		printf("%d ",comp[i]);
	}
	return 0;
}
