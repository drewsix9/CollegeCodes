#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void string_remove_vowel(char arr[]);

int main() {

	char string[] = "Dan Mathew Gamale";

	string_remove_vowel(string);

	return 0;
}

void string_remove_vowel(char arr[]) {
	int len = strlen(arr);

	for(int i=0; i<len; i++) {
		if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u' ||
		        arr[i]=='A' || arr[i]=='E' || arr[i]=='I' || arr[i]=='O' || arr[i]=='U') {
			for(int j=i; j<len-1; j++) {
				arr[j] = arr[j+1];
			}
			len--;
		}
	}

	printf("\n");
	for(int i=0; i<len; i++) {
		printf("%c",arr[i]);
	}
}
