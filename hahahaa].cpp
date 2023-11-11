// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
#include <stdio.h>
#include <stdlib.h>

int main() {

// 31 = jan(1) march(3) may(5) july(7) august(8) oct(10) december(12)
// 30 = april(4) june(6) sept(9) nov(11)

	int m,d,y,valid=1, leap=0;
	printf("Enter the date MM/DD/YYYY\n");
	scanf("%d,%d,%d",&m,&d,&y);

	if (y >= 1000 && y <= 9999) {

		if ((y % 4 == 0 && y % 100) != 0 || (y % 400 == 0)) {
			leap = 1;
		}
		if (m == 2) {
			if (leap!=0 && d == 29) {
				valid = 1;
			} else if (d > 28) {
				valid = 0;
			}

		}

		if (m >= 1 && m <= 12) {

			if (m == 4 || m == 6 || m == 9 || m == 11) {
				if (d >=1 && d <=30) {
				} else if (d > 30) {
					valid = 0;
				}


			}

		}

	}

	else {
		valid = 0;

	}
	if (valid == 1) {
		printf ("Date is valid");
	}
	if (valid == 0) {

		printf ("Date is invalid");
	}
	return 0;
}

// months 1-12, days 1-31,
// feb 28 or 29 evry 4 years