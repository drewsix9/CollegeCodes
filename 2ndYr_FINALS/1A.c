#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
	int factor;
	for(int i=2;i<num;i++){
		if(num % i == 0){
			return false;
			}
		}
		return true;
	}


int main (){
	int num,n=0,arr[100];
	
	for(int i=0;i<100;i++)
	{
		arr[i]=0;
	}
	
	do
	{
		printf("Enter inputs: ");
		scanf("%d",&num);
		if(num!=0)
		{
			arr[n] = num;
			n++;
		}
	}while(num!=0);
	
	printf("\nBefore:");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	int temp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(isPrime(arr[i]) && isPrime(arr[j]) && arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	printf("\nAfter:");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}
