#include <stdio.h>
#include <stdlib.h>

int main() {
	int h,m,s,newh;

	printf("Enter Military time in this format: \"HH:MM:SS\"\t ");
	scanf("%d:%d:%d",&h,&m,&s);

	if(h<=12) {
		printf("\n%d:%d:%d\n",h,m,s);
	} 
	else if (h>=13 && h<=23 && m<60 && s<60) {
		newh = h-12;
		printf("\n%d:%d:%d\n",newh,m,s);
	} else {
		printf("Wrong Format!");
	}

	return 0;
}