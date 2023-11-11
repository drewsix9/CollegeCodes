#include <stdio.h>

int main (){
	
	float diameter, pi=3.14, area, radius;
	
	printf("Enter the diameter:\n");
	scanf("%f", &diameter);
	
	radius = diameter/2;
	area = pi * radius * radius;
	
	printf("Area of the circular pillar = %.2f", area);
	
	return 0;
}