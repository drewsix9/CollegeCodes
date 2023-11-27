#include <bits/stdc++.h>

using namespace std;

string removeDuplicateToUpper(string str) {
  string res;
  string order;
  set<char> set;
  for (char c : str) {
    if (set.count(c) == 0) {
      order += c;
      set.insert(c);
    }
  }
  for (char c : order) {
    res += toupper(c);
  }
  return res;
}

int main() {
  string str;
  cout << "Enter a string: ";
  getline(cin, str);
  cout << "Result: " << removeDuplicateToUpper(str);
}