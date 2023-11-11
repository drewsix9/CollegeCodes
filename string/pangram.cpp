#include <iostream>
#include <string>

using namespace std;

bool isPangram(string s) {
  int freq[26];
  for (char c : s) {
    if (isalpha(c)) {
      freq[tolower(c) - 'a']++;
    }
  }
  for (int n : freq) {
    if (n == 0) {
      return 0;
    }
  }
  return 1;
}

bool isPangram2(string s) {
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  for (char c : alpha) {
    if (s.find(c) == string::npos) {
      return 0;
    }
  }
  return 1;
}

int main() {
  string str = "the quick brown fox jumps over the lazy dog";
  cout << boolalpha << isPangram2(str);
}