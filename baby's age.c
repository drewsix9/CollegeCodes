#include <stdio.h>

int main(){
	
	int pr_age, t_age, pe_age, b_age;
	
	printf("Input Programmer's age: \t");
	scanf("%d", &pr_age);
	printf("Input Teacher's age: \t");
	scanf("%d", &t_age);
	printf("Input Peter's age\t");
	scanf("%d", &pe_age);
	
	b_age = (pr_age * t_age) / pe_age + 1;
	
	printf("\nThe Baby's age is: %d\n", b_age);
	
	return 0;
}