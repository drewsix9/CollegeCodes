#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void toUpper_VowelCount(char str[]);

int main() {

	char str[100];

	printf("Enter a string: ");
	scanf("%s",str);

	toUpper_VowelCount(str);

	return 0;
}

void toUpper_VowelCount(char str[]) {
	int len = strlen(str);
	int count=0;
	for(int i=0; i<len; i++) {
		str[i] = toupper(str[i]);
		if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
			count++;
		}
	}

	printf("\n");
	for(int i=0; i<len; i++) {
		printf("%c ",str[i]);
	}
	printf("\nNumber of vowels: %d",count);
}