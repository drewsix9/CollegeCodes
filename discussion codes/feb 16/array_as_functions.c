#include <stdio.h>
#include <stdbool.h>

// A - 0 = 1, 2, 4, 0
// B - U = 4;
// C - E = 1, 3, 5, 7, 8, 9, 0
// D - EXIT

void printBanO(int arr[], int n);
void printBanU(int arr[], int n);
void printBanE(int arr[], int n);
bool istwenty(int num);
bool isforty(int num);
bool isseventy(int num);
bool iseighty(int num);
bool isninety(int num);

int main() {
	char choice;
	int arr[100];
	int n = 0;
	int arr2[100];

	printf("Enter choice: ");
	scanf("%c", &choice);

	if (choice == 'A' || choice == 'a') {
		printf("\nBanning letter 'O'");
		printf("\nEnter how many numbers: ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printBanO(arr, n);
	}

	if (choice == 'B' || choice == 'b') {
		printf("\nBanning letter 'U'");
		printf("\nEnter how many numbers: ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printBanU(arr, n);
	}

	if (choice == 'C' || choice == 'c') {
		printf("\nBanning letter 'E'");
		printf("\nEnter how many numbers: ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printBanE(arr, n);
	}

	if (choice == 'D' || choice == 'd') {
	}
	return 0;
}

void printBanO(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		int quot = 0;
		int rem = 0;
		for (;;) {
			quot = temp / 10;
			rem = temp % 10;
			if (rem == 1 || rem == 2 || rem == 4 || rem == 0) {
			} else if (!isforty(arr[i]) || arr[i] != 14) {
				printf("%d ", arr[i]);
				break;
			}
			temp = quot;
			if (quot == 0) {
				break;
			}
		}
	}
}

void printBanU(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		int quot = 0;
		int rem = 0;
		for (;;) {
			quot = temp / 10;
			rem = temp % 10;
			if (rem == 4) {
			} else if (arr[i] != 14) {
				printf("%d ", arr[i]);
				break;
			}
			temp = quot;
			if (quot == 0) {
				break;
			}
		}
	}
}

void printBanE(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		int quot = 0;
		int rem = 0;
		for (;;) {
			quot = temp / 10;
			rem = temp % 10;
			if (rem == 1 || rem == 3 || rem == 5 || rem == 7 || rem == 8 || rem == 9 || rem == 0) {
			} else if (!istwenty(arr[i]) || !isseventy(arr[i]) || !iseighty(arr[i]) || !isninety(arr[i]) || arr[i] != 10 || arr[i] != 11 || arr[i] != 12 || arr[i] != 13 || arr[i] != 14 || arr[i] != 15 || arr[i] != 16 || arr[i] != 17 || arr[i] != 18 || arr[i] != 19) {
				printf("%d ", arr[i]);
				break;
			}
			temp = quot;
			if (quot == 0) {
				break;
			}
		}
	}
}

bool istwenty(int num) {
	int temp = num;
	int quot = 0;
	int rem = 0;
	for (int i = 0; i < 1; i++) {
		quot = temp / 10;
		rem = temp % 10;
		if (rem == 2) {
			return true;
		}
	}
}

bool isforty(int num) {
	int temp = num;
	int quot = 0;
	int rem = 0;
	for (int i = 0; i < 1; i++) {
		quot = temp / 10;
		rem = temp % 10;
		if (rem == 4) {
			return true;
		}
	}
}

bool isseventy(int num) {
	int temp = num;
	int quot = 0;
	int rem = 0;
	for (int i = 0; i < 1; i++) {
		quot = temp / 10;
		rem = temp % 10;
		if (rem == 7) {
			return true;
		}
	}
}

bool iseighty(int num) {
	int temp = num;
	int quot = 0;
	int rem = 0;
	for (int i = 0; i < 1; i++) {
		quot = temp / 10;
		rem = temp % 10;
		if (rem == 8) {
			return true;
		}
	}
}

bool isninety(int num) {
	int temp = num;
	int quot = 0;
	int rem = 0;
	for (int i = 0; i < 1; i++) {
		quot = temp / 10;
		rem = temp % 10;
		if (rem == 9) {
			return true;
		}
	}
}
