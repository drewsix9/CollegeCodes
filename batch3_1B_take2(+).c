/*enter pila ka inputs then
if sa imu inputs naay number na mo repeat itself eh print nija
output
enter inputs: 3
num1: 56
num2: 55.34
55.34
num3: 321.862
321.862
mao rgud na
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int input;
	char num[100];


	printf("Enter how many inputs:\t");
	scanf("%d",&input);

	for (int i=1; i<=input; i++) {
		printf("\nEnter input %d:\t",i);
		scanf("%s",&num);

		int is_repeating=0;

		//checks if there is repeating
		for(int j=0; j<=strlen(num); j++) {
			for(int k=0; k<=strlen(num); k++) {

				if (num[j]==num[k] && j!=k) {
					is_repeating=1;
				}
			}
		}
		if (is_repeating==1) {
			printf("\n%s\n",num);
		}
	}

	return 0;
}