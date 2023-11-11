#include <iostream>

using namespace std;

int fact(int num) {
  if (num == 1) {
    return 1;
  }
  return num * fact(num - 1);
}

int main() {
  int num;
  while (1) {
    cout << "\nEnter num: ";
    cin >> num;
    cout << num << " factorial = " << fact(num);
  }
}
