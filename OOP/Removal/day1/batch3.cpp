#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sortVowels(string s) {
  string vowels("aeiouAEIOU");
  vector<int> pos;

  for (int i = 0; i < s.size(); i++) {
    if (vowels.find(s[i]) == string::npos && !isspace(s[i])) {
      pos.push_back(i);
    }
  }

  for (int i = 0; i < pos.size() - 1; i++) {
    for (int j = i + 1; j < pos.size(); j++) {
      if (s[pos[i]] > s[pos[j]])
        swap(s[pos[i]], s[pos[j]]);
    }
  }
  return s;
}

int main() {
  string str;
  cout << "Enter input: ";
  cin >> str;
  cout << "\nOutput: " << sortVowels(str);
  return 0;
}