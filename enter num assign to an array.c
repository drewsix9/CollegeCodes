#include <stdio.h>
#include <string.h>


int main() {
	char input[1001];
	int arr[1000];

	// Take the number as string
	printf("Enter the number: ");
	scanf("%s", input);

	// Convert ASCII to decimal
	for (int i = 0; i < strlen(input); i++) {
		arr[i] = input[i] - '0';
	}

	// Checks the results
	for(int i=0; i<strlen(input); i++) {
		printf("array%d: %d\n",i,arr[i]);
	}

	return 0;
}
