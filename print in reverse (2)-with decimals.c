#include <stdio.h>
#include <math.h>

int main() {

	float num,rem,quot;

	printf("Enter a number to be reversed:\t");
	scanf("%f", &num);

	for (;;) {

		quot = num / 10;
		rem = fmod(num,10);
		printf("%d", rem);
		num = quot; //Swap values

		if (quot == 0) {
			break;
		}
	}

	return 0;
}