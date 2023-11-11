#include <stdio.h>
#include <unistd.h>

int main(){

	printf("Hi.");
	for (;;){
	
	usleep(1000000);
	printf(".");
	}
	return 0;
}