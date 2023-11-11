#include <iostream>

using namespace std;

bool isPalindrome(int num) {
  int div = 1;
  while (num >= div * 10) {
    div *= 10;
  }

  while (num > 0) {
    int left = num / div;
    int right = num % 10;

    if (left != right)
      return 0;

    // removes most significant and least significant digits
    num = (num % div) / 10;
    div /= 100;
  }
  return 1;
}

int main() {
  while (1) {
    int num;
    cout << "\nEnter num: ";
    cin >> num;
    cout << boolalpha << isPalindrome(num) << endl;
  }
}