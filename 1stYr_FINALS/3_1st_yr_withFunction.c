#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int n, arr[100], deci_arr[100];

    printf("Enter number of inputs: ");
    scanf("%d",&n);

    printf("\nEnter input(s): ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        deci_arr[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int num = arr[i], quot, rem, prod;
        int power = 1, sum = 0;
        for(;;) {
            quot = num / 10;
            rem = num % 10;
            prod = rem * power;
            sum += prod;
            power *= 2;
            num = quot;
            if(quot == 0) {
                break;
            }
        }
        deci_arr[i] = sum;
    }

    printf("\n Decimal: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", deci_arr[i]);
    }

    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isPrime(deci_arr[i]) && isPrime(deci_arr[j]) && deci_arr[i] > deci_arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                temp = deci_arr[i];
                deci_arr[i] = deci_arr[j];
                deci_arr[j] = temp;
            }
        }
    }

    printf("\n Output: ");
    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }

    printf("\n Decimal: ");
    for(int i = 0; i < n; i++) {
        printf("%d ",deci_arr[i]);
    }

    return 0;
}
