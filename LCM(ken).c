#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int x=36;
	int y=24,b;
	b=y;
	
	for(;;){
	
		if (b%x==0 && b%y==0){
			printf("%d",b);
			break;
		}
		b++;
	}
	return 0;
}
