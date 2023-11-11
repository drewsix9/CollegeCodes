// return true if a string is palindrome, return false if not

#include <iostream>
#include <string>

using namespace std;

bool isPal(string s) {
  if (s.size() == 1 || s.size() == 0)
    return 1;
  if (s.front() != s.back())
    return 0;

  return isPal(s.substr(1, s.size() - 2));
}

int main() {
  while (1) {
    string str;
    cout << "\n\nEnter string: ";
    cin >> str;
    cout << ((isPal(str)) ? "\nis Palindrome!" : "\nis NOT Palindrome!");
  }
}