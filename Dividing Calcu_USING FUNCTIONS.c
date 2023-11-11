#include <stdio.h>

int InputNum();

int main(){
	 float dividend, divisor, quot;
	 
	 dividend = InputNum(); //Declares the num you inputed as the dividend.
	 divisor = InputNum(); //Declares the num you inputed as the divisor.
	 
	 quot = dividend / divisor;
	 
	 if(divisor==0){
	 	printf("\nError");
	 }
	 
	 else{
	 	printf("\nQuotient of %.2f and %.2f is %.2f", dividend, divisor, quot);
	 }
	 return 0;
}

int InputNum(){
	
	float num;
	printf("Enter your number: \t");
	scanf("%f", &num);
	return num;
	
}