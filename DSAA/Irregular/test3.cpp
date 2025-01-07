#include <iostream>

using namespace std;

void printPrimeFactors(int num) {
  int i = 2;
  while (num > 1) {
    if (num % i == 0) {
      cout << i << " ";
      num /= i;
    } else {
      i++;
    }
  }
}

int main() {
  int num = 0;
  cout << "Enter a number: ";
  cin >> num;
  printPrimeFactors(num);
  return 0;
}