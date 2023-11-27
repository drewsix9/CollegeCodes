#include <bits/stdc++.h>

using namespace std;

void reverseSentence(string str) {
  stringstream ss(str);
  string temp;
  vector<string> words;
  while (getline(ss, temp, ' ')) {
    words.push_back(temp);
  }
  reverse(words.rbegin(), words.rend());
  for (string s : words) {
    cout << s << " ";
  }
}

int main() {
  string str;
  cout << "Enter a sentence: ";
  getline(cin, str);
  reverseSentence(str);
}