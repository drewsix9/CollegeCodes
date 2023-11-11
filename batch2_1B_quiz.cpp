// ask for float n numbers, 1,3,6,7
// get prime and comp
// if prime print in binary

#include <iostream>
#include <vector>

using namespace std;

int isPrime(int n) {
  if (n <= 1)
    return 0;
  if (n == 2 || n == 3)
    return 1;
  for (int i = 2; i < n / 2 + 1; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int toBinary(float n) {
  int num = (int)n;
  int sum = 0, prod = 0, pow = 1;
  while (num > 0) {
    prod = (num % 2) * pow;
    pow *= 10;
    sum += prod;
    num /= 2;
  }
  return sum;
}

int main() {
  vector<float> v;

  float temp;
  while (cin >> temp && temp != 0) {
    v.push_back(temp);
  }

  for (float n : v) {
    if (isPrime(n)) {
      cout << toBinary(n) << " ";
    } else {
      cout << n << " ";
    }
  }
}