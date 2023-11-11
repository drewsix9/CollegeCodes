#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_reversal(char string[],int len);

int main() {

	char str[100];

	printf("Enter string: ");
	scanf("%s",str);
	int len = strlen(str);

	string_reversal(str,len);

	printf("\n\n Reversed: ");
	for(int i=0; i<len; i++) {
		printf("%c ",str[i]);
	}
	return 0;
}


void string_reversal(char str[],int len) {

	for(int i=0; i<len/2; i++) {
		
		int temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
		
		printf("\nIteration %d: ",i);
		for(int j=0; j<len; j++) {
			printf("%c",str[j]);
		}
	}
}