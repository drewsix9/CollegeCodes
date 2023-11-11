/*
Enter the numbers ending with 0. Add the numbers according to its place value. If it is a prime number print, else print 0.

Input: 103 456 789 0
3+6+9 = 18 print 0
0+5+8 = 13 print 13
1+4+7 = 12 print 0
*/

#include <string.h>
#include <stdio.h>

int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int size;
    printf("Enter # of inputs: ");
    scanf("%d", &size);

    int arr[size];
    int quot[size]; // initializing each quotient to be used later

    printf("Enter inputs: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // finding the highest degree
    int MaxCount = 0;
    for (int i = 0; i < size; i++)
    {
        int temp = arr[i];
        quot[i] = arr[i]; // storing the arr[i] to quot[i], as this will be useful in the loop below
        int count = 0;
        while (temp > 0) // counting how many places each input is
        {
            temp /= 10;
            count++;
        }
        if (count > MaxCount)
        {
            MaxCount = count;
        }
    }

    for (int i = 0; i < MaxCount; i++)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += quot[i] % 10;    // adding the quotient of each sum
            quot[i] = quot[i] / 10; // updating the value of quot[i]
        }
        if (isPrime(sum))
        {
            printf("sum = %d\n", sum);
        }
        else
        {
            printf("sum = 0\n");
        }
    }

    return 0;
}