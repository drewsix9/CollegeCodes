// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
#include<stdio.h>

int main(void) {
	int day, mon, year, is_leap = 0, is_valid = 1;

	printf("Enter a date (MM/DD/YYYY) :");
	scanf("%d/%d/%d", &mon, &day, &year);

	if (year >= 1000 && year <= 9999) {

		//  check whether year is a leap year
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			is_leap = 1;
		}

		// check whether mon is between 1 and 12
		if(mon >= 1 && mon <= 12) {
			// check for days in feb
			if (mon == 2) {
				if (is_leap!=0 && day == 29) {
					is_valid = 1;
				} else if (day > 28) {
					is_valid = 0;
				}
			}

			// check for days in April, June, September and November
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
				if (day > 30) {
					is_valid = 0;
				}
			}

			// check for days in rest of the months
			// i.e Jan, Mar, May, July, Aug, Oct, Dec
			else if(day > 31) {
				is_valid = 0;
			}
		}

		else {
			is_valid = 0;
		}

	} else {
		is_valid = 0;
	}

	if(is_valid) {
		printf("Date is valid.");
	}

	else {
		printf("Date is invalid.");
	}

	return 0;
}