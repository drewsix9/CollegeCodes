#include <iostream>
#include <set>
#include <string>

using namespace std;

class StringClass {
public:
  string str;

  StringClass(string str) : str(str) {}
};

class AnagramClass : public StringClass {

  set<string> anagrams; // SETS ARE USED TO AVOID DUPLICATE ANAGRAMS

public:
  AnagramClass(string str) : StringClass(str) {}

  void generateAnagrams() {
    int size = str.length();
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i != j) {
          string temp = str;
          swap(temp[i], temp[j]);
          anagrams.insert(temp);
        }
      }
    }
  }

  void printAnagrams() {
    for (string anagram : anagrams) {
      cout << anagram << endl;
    }
  }
};

int main() {
  string input;
  cout << "Enter string: ";
  getline(cin, input);
  AnagramClass anagram(input);
  anagram.generateAnagrams();
  cout << "Anagrams of " << input << " are: " << endl;
  anagram.printAnagrams();
}