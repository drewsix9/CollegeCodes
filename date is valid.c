// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
//--------------------------------
#include <stdio.h>
#include <stdlib.h>

int main() {

	int year, month, day, is_valid;
	printf("Enter date MM/DD/YYYY: \n ");
	scanf("%d/%d/%d", &month, &day, &year);

	if ((year>=1000 && year<=9999) && (month<=12 && month>=1) && (day<=31)) {


		if ((year%4==0 && year%100!=0) || (year%400==0)) {


			if ((month==2) && (day<=29)) {

				is_valid=1;
			}
		} else if ((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (day<=31)) {
			is_valid=1;
		} else {
			is_valid=0;
		}
	} else {

		is_valid=0;
	}

	if (is_valid ==1) {

		printf("Date is Valid");
	} else {

		printf("Date is Invalid");
	}
	return 0;
}
