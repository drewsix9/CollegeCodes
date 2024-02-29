#include <cstring>
#include <iostream>

using namespace std;

bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int addDigits(int num) {
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  int arr[100];
  int num = 1;
  int n = 0;
  cout << "Enter inputs: ";
  while (1) {
    cin >> num;
    if (num == 0) {
      break;
    }
    arr[n] = num;
    n++;
  }

  cout << "\nOutput: ";
  for (int i = 0; i < n; i++) {
    if (!isPrime(addDigits(arr[i]))) {
      cout << arr[i] << " ";
    }
  }
}