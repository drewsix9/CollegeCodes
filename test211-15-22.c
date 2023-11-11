#include <stdio.h>

int main() {

	int num, quot, rem;
	
	printf("Enter num:");
		scanf("%d",&num);

	for (;;) {

		quot=num/10;
		rem=num%10;
		printf("%d",rem);
		
		if (quot==0) {
			printf("%d",rem);
	
		}
		break;
	}



	return 0;
}