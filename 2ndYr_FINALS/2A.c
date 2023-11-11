#include <stdio.h>

int main(){
	int num,n=0,nn=0,arr[100],pos[100],ins[100];
	
	for(int i=0;i<100;i++)
	arr[i] = 0;
	
	do
	{
		printf("Enter inputs: ");
		scanf("%d",&num);
		if(num!=0){
			arr[n] = num;
			n++;
			}
	}while(num!=0);
	
	do
	{
		printf("\nEnter elements to be inserted :");
		scanf("%d",&num);
		if(num!=0){
			ins[nn] = num;
			nn++;
		}
	}while(num!=0);

	loop1:
	for(int i=0;i<nn;i++){
		printf("\nEnter positions :");
		scanf("%d",&num);
		if(num > n){
			printf("\nWrong Input. Try Again.");
			goto loop1;
			}
			pos[i] = num-1;
		}
		
	int temp;
	for(int i=0;i<nn;i++){
		temp = arr[pos[i]];
		arr[pos[i]] = ins[i];
		n++;
		for(int j=(n-2);j>=(pos[i]+1);j--){
				arr[j+1] = arr[j];
		}
		arr[pos[i]+1] = temp;
	}
	
	printf("\nAfter: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
	}
