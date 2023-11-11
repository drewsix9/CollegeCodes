#include <iostream>

using namespace std;

int fib(int num) {
  if (num == 1)
    return 1;
  else if (num == 0)
    return 0;

  return fib(num - 1) + fib(num - 2);
}

int main() {
  int num;
  cout << "Enter number: ";
  cin >> num;
  cout << "Output: " << fib(num);
  return 0;
}