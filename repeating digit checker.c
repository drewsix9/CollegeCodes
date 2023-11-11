#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int num;

	// Get the number from the user
	printf("Enter an integer: ");
	scanf("%d", &num);

	// Check if there is a repeating digit
	bool repeat = false;
	int digits[10] = {0}; // Initialize all elements to 0
	while (num > 0) {
		int digit = num % 10; // Get the last digit of the number
		digits[digit]++; // Increment the count for this digit
		if (digits[digit] > 1) { // Check if the count is greater than 1
			repeat = true; // We have a repeating digit
			break; // No need to continue checking
		}
		num /= 10; // Remove the last digit from the number
	}

	// Print the result
	if (repeat) {
		printf("There is a repeating digit in the number.\n");
	} else {
		printf("There are no repeating digits in the number.\n");
	}

	return 0;
}