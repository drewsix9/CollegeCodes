#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
	if (num <= 1) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int n;

	// Get the number of inputs from the user
	printf("Enter the number of float inputs: ");
	scanf("%d", &n);

	// Get the inputs from the user
	for (int i = 0; i < n; i++) {
		float num;
		printf("Enter a float: ");
		scanf("%f", &num);

		// Check if the number is an integer
		bool is_int = (int)num == num;
		if (is_int) {
			// Check if the integer is prime
			int int_num = (int)num;
			if (is_prime(int_num)) {
				// Print the integer in binary form
				if (int_num == 0) {
					printf("0\n");
				} else {
					char binary[32];
					int index = 0;
					while (int_num > 0) {
						binary[index] = '0' + int_num % 2;
						int_num /= 2;
						index++;
					}
					for (int j = index - 1; j >= 0; j--) {
						printf("%c", binary[j]);
					}
					printf("\n");
				}
			} else {
				// Print the integer
				printf("%d\n", int_num);
			}
		} else {
			// Print the float
			printf("%f\n", num);
		}
	}

	return 0;
}
