// Problem: Print Binary Numbers

// Description: Write a program that takes a positive integer n as input and prints the first n binary numbers in ascending order. A binary number is a number expressed in the base-2 numeral system, which consists of only 0s and 1s.

// Implement a program that accomplishes the following:

// Read a positive integer n from the user.
// Print the first n binary numbers in ascending order, each on a new line.

// Example:

// Input:
// n = 5

// Output:
// 1
// 10
// 11
// 100
// 101

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void printBinNumbers(int n) {
    cout << "\nOutput: ";
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++) {
      string num = q.front();
      q.pop();
      cout << num << " ";
      q.push(num + "0");
      q.push(num + "1");
    }
  }

  void toBinary(int n) {
    cout << "\nOutput: ";
    for (int num = 1; num <= n; num++) {
      int deci = num;
      int rem = 0, sum = 0, power = 1, prod = 0;
      while (deci > 0) {
        rem = deci % 2;
        prod = rem * power;
        sum += prod;
        power *= 10;
        deci /= 2;
      }
      cout << sum << " ";
    }
  }
};

int main() {
  Solution sol;
  sol.printBinNumbers(10);
  sol.toBinary(10);
}