#include <bits/stdc++.h>

using namespace std;

bool areAnagrams(string s, string t) {
  if (s.empty() || t.empty()) {
    return false;
  }
  if (s.size() != t.size()) {
    return false;
  }
  set<char> charSet;
  for (char c : s) {
    charSet.insert(tolower(c));
  }
  for (char c : t) {
    if (charSet.count(tolower(c)) > 0) {
      charSet.erase(tolower(c));
    }
  }
  return (charSet.empty() ? true : false);
}

int main() {
  string s, t;
  cout << "Enter first string: ";
  cin >> s;
  cout << "Enter second string: ";
  cin >> t;
  if (areAnagrams(s, t)) {
    cout << s << " and " << t << " are anagrams.";
  } else {
    cout << s << " and " << t << " are not anagrams.";
  }
}