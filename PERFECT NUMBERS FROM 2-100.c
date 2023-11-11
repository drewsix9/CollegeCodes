#include <stdio.h>

int main(){
	
	int multiple, j, k, rem;
	
	printf("This Programs writes all Perfect numbers from 2-100\n\n");
	
	for (j=2;j<=100;j++){
		
		multiple = 0; //resets the value of multiple
		
		for (k=1;k<j;k++){
			
			rem = j % k;
			if (rem == 0){
				multiple = multiple + k;
			}
		}
	if (multiple == j){
		
		printf("%d ", j);
	}
	}
	return 0;
}