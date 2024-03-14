/*
enter a string of binary inputs
convert to decimal, if it has '.' do not convert

input: 1101 1011 101 1.1

output: 13   11   5   1.1
*/
#include <cstring>
#include <iostream>

using namespace std;

bool hasDot(float n) {
  return n - (int)n != 0;
}

int deciToBin(int n) {
  int binary = 0, prod = 0, pow = 1;
  while (n > 0) {
    prod = n % 10 * pow;
    pow *= 2;
    binary += prod;
    n /= 10;
  }
  return binary;
}

int main() {
  char str[100];
  cout << "Enter a string of binary inputs: ";
  cin.getline(str, 100);

  cout << "\nOutput: ";
  char *token = strtok(str, " ");
  while (token != NULL) {
    float n = atof(token); // convert to float
    if (hasDot(n)) {
      cout << n << " ";
    } else {
      cout << deciToBin((int)n) << " ";
    }
    token = strtok(NULL, " ");
  }
}