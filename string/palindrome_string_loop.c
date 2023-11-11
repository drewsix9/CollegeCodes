#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int n;

	printf("Enter how many inputs:\t");
	scanf("%d",&n);

	for (int i=1; i<=n; i++) {

		char string1[50];

		printf("\nEnter string:\t");
		scanf("%s",&string1);

		int is_pal = 1;
		int len = strlen(string1);
		int mid = len/2;

		for (int j=0; j<=mid; j++) {
			if (string1[j] != string1[len-j-1]) {
				is_pal = 0;
			}
		}

		if (is_pal == 1) {
			printf("%s\n - is a palindrome",string1);
		}
		if (is_pal == 0) {
			printf("%s\n - is NOT palindrome",string1);
		}
	}
	return 0;
}
