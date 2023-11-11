#include <stdio.h>
#include <stdlib.h>

int main() {
	int h,m,s,newh,hpassed,dayspassed;

	printf("Enter Military time in this format: \"HH:MM:SS\"\t ");
	scanf("%d:%d:%d",&h,&m,&s);

	if (h>23 && m>59 && s>59) {
		printf("Invalid Format!");
		
	}
	
	printf("Enter How Many Hours Passed:\t");
	scanf("%d",&hpassed);
	
	dayspassed = (h + hpassed) / 24;
	newh = (h + hpassed) % 24;
	
	printf("\n--------------------------------\nDays Passed: %d\nNew Time: %d:%d:%d",dayspassed, newh, m,s);


	return 0;
}