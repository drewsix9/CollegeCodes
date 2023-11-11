/*
Input how many numbers,
Nya if Ang number is not a whole number , just print
If whole number then naay repeating digit na above 5 , convert to octal,
if whole number sya na way repeating dig , print the original number ra.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {

	float num,cast;
	int input,temp;
	char text;
	
//	printf("Problem from Batch2_1C:\n\nInput how many numbers,\nNya if Ang number is not a whole number , just print\nIf whole number then naay repeating digit na above 5 , convert to octal,\nif whole number sya na way repeating dig , print the original number ra.\n");
//	printf("\nEnter any letter to continue: \t");
//	scanf("%s",&text);

	printf("\n");
	printf("Enter how many inputs:\t");
	scanf("%d",&input);

	for(int i = 1; i <= input; i++) {

		printf("\nEnter input %d:\t",i);
		scanf("%f",&num);

		//casting
		cast = num - (int)num;

		//our input in int form.
		temp = (int)num;

		if (cast==0) {
			
			int quot1=0,rem1=0;
			int counttemp=temp;
			int arr1[MAX]={0};
			int o=1;
			int count1=0;

			for(;;) {
				count1++;
				quot1=counttemp/10;
				rem1=counttemp%10;
				arr1[o]=rem1;
				o++;
				counttemp=quot1;
				if(quot1==0) {
					break;
				}
			}
			
			int is_repeating=0;
			int is_greaterthan5=0;
			
			for (int j=1; j<=count1; j++) {
				
				for (int k=1; k<=count1; k++) {
					
					if (arr1[j]==arr1[k] && j!=k && arr1[j]>5) {
						is_repeating=1;
						is_greaterthan5=1;
					}
				}
			}
			
			if(is_repeating==1 && is_greaterthan5==1) {
				int p=1,quot2=0,rem2=0;
				int octaltemp=temp;
				int arr2[MAX]= {0};

				for(;;) {
					quot2=octaltemp/8;
					rem2=octaltemp%8;
					arr2[p]=rem2;
					p++;
					octaltemp=quot2;
					if(quot2==0) {
						break;
					}
				}
				printf("\nOctal:\t");
				
				for(int l=count1+1;l>=1;l--){
					printf("%d",arr2[l]);
				}
				printf("\n");
			} else {
				printf("\n%.2f (a whole number)\n",num);
			}
		} else {
			printf("\n%.2f (not a whole number)\n",num);
		}
	}
	
	printf("\n\n\n\n\n-=By drewsix9 =-\n");

	return 0;
}
