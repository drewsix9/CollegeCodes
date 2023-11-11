#include <iostream>

using namespace std;

int countDigits(int num) {
  if (num == 0)
    return 0;

  return 1 + countDigits(num / 10);
}

int main() {
  int num;
  cout << "Enter number: ";
  cin >> num;
  cout << "Output: " << countDigits(num);
  return 0;
}