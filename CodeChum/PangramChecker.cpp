#include <bits/stdc++.h>

using namespace std;

bool isPangram(string str) {
  for (int i = 0; i < 26; i++) {
    char c = (char)(i + 'a');
    if (str.find(c) == string::npos && str.find((char)(c - 32)) == string::npos) {
      return false;
    }
  }
  return true;
}

int main() {
  string str;
  cout << "Enter a string: ";
  cin >> str;
  if (isPangram(str)) {
    cout << str << " is a pangram.";
  } else {
    cout << str << " is not a pangram.";
  }
}