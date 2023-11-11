//  return true if a number is a sum of two prime numbers, return false if otherwise
#include <iostream>

using namespace std;

bool isPrime(int num) {
  if (num == 2 || num == 3)
    return 1;
  else if (num <= 1)
    return 0;

  for (int i = 2; i < num / 2 + 1; i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

bool isSatisfied(int num) {
  for (int i = 0; i <= num; i++) {
    int diff = num - i;
    if (isPrime(diff) && isPrime(i)) {
      cout << num << " = " << diff << " + " << i;
      return 1;
    }
  }
  return 0;
}

int main() {
  int num;
  cout << "\nEnter num: ";
  cin >> num;
  cout << ((isSatisfied(num)) ? "\nHas a sum of two prime numbers" : "FALSE!");
}