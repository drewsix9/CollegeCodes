#include <bits\stdc++.h>

using namespace std;

bool isVowel(char c) {
  string vowel = "aeiouAEIOU";
  return ((vowel.find(c) != string::npos) ? 1 : 0);
}

void sortVowels(string &str) {
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      if (isVowel(str[i]) && isVowel(str[j]) && str[i] > str[j]) {
        swap(str[i], str[j]);
      }
    }
  }
}

int main() {
  string str;
  cout << "\nEnter string: ";
  cin >> str;
  cout << "\nOutput: ";
  sortVowels(str);
  cout << str;
}