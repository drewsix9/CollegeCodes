#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cout << "Enter number: ";
  cin >> str;

  int res = 0;
  for (char c : str) {
    res *= 10;
    res += c - '0';
  }
  cout << "Output: " << res << endl;
}