#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool areAnagrams(string s, string t) {
  string sPattern, tPattern;

  vector<int> freqS(26, 0), freqT(26, 0);
  for (char c : s) {
    if (isalpha(c)) {
      freqS[c - 'a']++;
    }
  }
  for (int n : freqS) {
    sPattern += to_string(n);
  }

  for (char c : t) {
    if (isalpha(c)) {
      freqT[c - 'a']++;
    }
  }
  for (int n : freqT) {
    tPattern += to_string(n);
  }

  cout << sPattern << "\n"
       << tPattern << "\n\n";

  return sPattern == tPattern;
}

int main() {
  string s = "schoolmaster";
  string t = "the classroom";

  cout << boolalpha << areAnagrams(s, t);
}