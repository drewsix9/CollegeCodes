/*Input how many numbers:
Nya if Ang number is not a whole number , just print
If whole number then naay repeating digit na above 5 , convert to octal,
if whole number sya na way repeating dig , print the original number ra.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {

	float num,cast;
	int input;

	printf("Enter how many inputs:\t");
	scanf("%d",&input);


	//outer loop for inputs
	for(int i=1; i<=input; i++) {

		cast=0;

		printf("\n\nEnter input %d:\t",i);
		scanf("%f",&num);
		printf("\n");

		//casting
		cast=num-(int)num;

		if (cast==0) {

			printf("\n%.2f(a whole number)\n",num);

			int quot1=0;
			int rem1=0;
			int temp=(int)num; // OUR NUMBER IN INTEGER TYPE.
			int arr1[99]= {0};
			int j=1;
			int count=0;

			for(;;) {
				count++;
				quot1=temp/10;
				rem1=temp%10;
				arr1[j]=rem1;
				j++;
				temp=quot1;
				if(quot1==0) {
					break;
				}
			}

			int numCount[MAX]= {1};
			int is_greaterthan5[MAX]= {0};
			int count2=0;
			int arr2[100]= {0};
			
			
			for(int k=1; k<=count; k++) {

				for (int l=1; l<=count; l++) {
					if (arr1[k]==arr1[l] && k!=l) {
						numCount[k]++;
					}
					if(arr1[k]>5) {
						is_greaterthan5[k]=1;
					}

				}
			}
			for(int m=1; m<=count; m++) {

				if(numCount[m]!=1 && is_greaterthan5[m]==1) {

					int c=1,quot2=0,rem2=0;
					int tempp=temp;

					//Convert to Octal
					for(;;) {
						count2++;
						quot2=tempp/8;
						rem2=tempp%8;
						arr2[c]=rem2;
						c++;
						tempp=quot2;
						if(quot2==0) {
							break;
						}
					}
					printf ("\nOctal:\t");

					for (int x = count2 - 1; x >= 0; x--) {
						printf ("%d", arr2[x]);
					}
				}
			}
		} else {
			printf("\n%.2f(not a whole number)\n",num);

		}
	}
	return 0;
}