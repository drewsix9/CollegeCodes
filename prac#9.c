#include <stdio.h>
/*
Input:
4 2
2
5
6
8
Output:
3
*/
int main() {
	int n,divisor,num,count=0;

	scanf("%d %d",&n,&divisor);
	for(int i=0; i<n; i++) {
		scanf("%d",&num);
		if(num%divisor==0) {
			++count;
		}
	}

	printf("\n\n%d",count);
	return 0;
}
