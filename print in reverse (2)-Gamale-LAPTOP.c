#include <stdio.h>

int main() {

	int num,rem,quot;

	printf("Enter a number to be reversed:\t");
	scanf("%d", &num);

	for (;;) {

		quot = num / 10;
		rem = num % 10;
		printf("%d", rem);
		num = quot; //Swap values

		if (quot == 0) {
			break;
		}
	}

	return 0;
}