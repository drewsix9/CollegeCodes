#include <bits/stdc++.h>

using namespace std;

string compressed(string str) {
  string res;
  for (int i = 0; i < str.size(); i++) {
    int n = 1;
    while (str[i] == str[i + 1]) {
      n++;
      i++;
    }
    res += str[i] + to_string(n);
  }
  return res;
}

int main() {
  string str;
  cout << "Enter a string: ";
  cin >> str;
  cout << "Compressed string: " << compressed(str);
}