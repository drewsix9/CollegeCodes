#include <iostream>

using namespace std;

void primeFactors(int n) {
  cout << "Prime factors of " << n << ": ";
  int i = 2;
  while (n != 1) {
    if (n % i == 0) {
      n /= i;
      cout << i << " ";
    } else {
      i++;
    }
  }
}

int main() {
  int num;
  cin >> num;
  primeFactors(num);
  return 0;
}