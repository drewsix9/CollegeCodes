#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string str, token;
  cout << "Enter a phrase: ";
  getline(cin, str);

  map<string, int> wordsMappedtoCount; // map to store the count of each word
  vector<string> words;                // vector to store the words in the order they appear

  stringstream ss(str);
  while (ss >> token) {
    words.push_back(token);
    wordsMappedtoCount[token]++;
  }

  cout << "Output: ";
  for (int i = 0; i < words.size(); i++) {
    if (wordsMappedtoCount[words[i]] == 1) {
      cout << words[i] << " ";
    }
  }
}