#include <stdio.h>

int main() {
	char name[100];
	printf("What is your name?\t");
	scanf("%s", &name);
	printf("\n\nMy Name is: %s", name);
	return 0;
}