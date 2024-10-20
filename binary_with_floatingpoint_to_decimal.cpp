#include <cmath>
#include <iostream>
using namespace std;

int toDecimal(int num) {
  int sum = 0, pwr = 0;
  while (num > 0) {
    int rem = num % 10;
    sum += rem * pow(2, pwr++);
    num /= 10;
  }
  return sum;
}

int toDecimal2(int num) {
  int sum = 0, pwr = 1;
  while (num > 0) {
    int rem = num % 10;
    sum += rem * pwr;
    pwr *= 2;
    num /= 10;
  }
  return sum;
}

int main() {
  float num;
  cout << "Enter base-2 with floating point: ";
  cin >> num;
  int whole = static_cast<int>(num);
  float part = num - whole;

  int deci = toDecimal2(whole);

  // string partInBin = baseTenWithDeciToBinary(part);

  cout << "\nbase-2: " << deci;
  // cout << "\nbase-2: " << deci << "." << partInBin;
  return 0;
}