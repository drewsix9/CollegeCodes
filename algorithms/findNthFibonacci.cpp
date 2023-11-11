#include <iostream>

using namespace std;

int findNthFibo(int n) {
  if (n == 0)
    return 0;
  if (n == 1) {
    return 1;
  }
  return findNthFibo(n - 1) + findNthFibo(n - 2);
}

int main() {
  int num;
  while (1) {
    cout << "\nEnter num: ";
    cin >> num;
    cout << num << " fibonacci = " << findNthFibo(num);
  }
}