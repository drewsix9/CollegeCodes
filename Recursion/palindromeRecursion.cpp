#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string s) {
  if (s.size() == 1 || s.size() == 0) {
    return 1;
  }

  if (s.front() == s.back()) {
    string sub = s.substr(1, s.length() - 2);
    return isPalindrome(sub);
  } else {
    return false;
  }
}

int main() {
  cout << ((isPalindrome("kayak")) ? "is Palindrome!" : "is NOT Palindrome!");
}