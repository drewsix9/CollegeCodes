#include <iostream>

using namespace std;

int GCD(int x, int y) {
  while (y != 0) {
    int temp = x;
    x = y;
    y = temp % y;
  }
  return x;
}

int main() {
  int x, y;
  cout << "Enter two numbers:\n";
  cin >> x >> y;
  cout << "The GCD of " << x << " and " << y << " is: " << GCD(x, y);
}