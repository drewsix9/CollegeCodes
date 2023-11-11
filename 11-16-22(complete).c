// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
// Alt + up/down - to move the line of code up or down
//--------------------------------
#include <stdio.h>
#include <stdlib.h>

int main() {

    int num,temp,digits,quot,rem,factor=0,sum=0;

    printf("Enter number:\t");
    scanf("%d",&num);

    printf("Enter how many digits:\t");
    scanf("%d", &digits);

    temp=num;
    for(int i=0; i<digits; i++) {
        quot=num/10;
        rem=num%10;
        sum=sum+rem; //adding all digits
        num=quot;
    }

//    for(;;){
//        quot=num/10;
//        rem=num%10;
//        sum=sum+rem;
//        if (quot==0){
//            break;
//        }
//        num=quot;
//    }

//    printf("\nTotal: %d",sum);

    for (int j=2; j<sum; j++) {

        if (sum%j==0) {
            factor++;
        }
    }
    if (factor==0) {
        printf("\n%d ",temp);
    }
    return 0;
}