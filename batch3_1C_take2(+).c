//Batch 3:
//Ngayu ug inputs , then ask for the number of digit, I print Ang whole number and
//also Ang number nga dli the same Ang number of digits sa gi input nimo nga number.
//I ban Ang dli whole num and Ang number of digit nga the same sa input num of dig.

/*
Digit:2
Sample :
10.2
10
104
342

Output:
104
342
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int n,dig;
	float num,cast;

	printf("Enter how many digits to allow: ");
	scanf("%d",&dig);

	printf("Enter how many inputs: ");
	scanf("%d",&n);

	for (int i=1; i<=n; i++) {
		printf("\nEnter input %d: ",i);
		scanf("%f",&num);

		cast = num - (int)num;
		int temp = (int)num;

		if (cast!=0) {
			continue;
		}

		int count=0;
		while(temp>0) {
			temp/=10;
			count++;
		}

		if(count==dig) {
			continue;
		} else {
			printf("%d",(int)num);
		}
	}
	return 0;
}

