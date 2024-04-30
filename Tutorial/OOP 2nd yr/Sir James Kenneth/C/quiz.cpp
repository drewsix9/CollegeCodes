#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class Number {
public:
  int num;
  Number(int x) : num(x) {}
};

class HappyNumber : public Number {
public:
  HappyNumber(int num) : Number(num) {}
  bool isHappy() {
    int n = num;
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      sum += digit * digit;
      n /= 10;
    }
    if (sum == 1) {
      return true;
    } else if (sum == 4) {
      return false;
    } else {
      num = sum;
      return isHappy();
    }
  }
};

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

class GetDuplicateCharacters : public StringClass {
public:
  map<char, int> charCount;
  string duplicateChars;

  GetDuplicateCharacters(string str) : StringClass(str) {
    for (char c : str) {
      charCount[c]++;
    }
    for (auto it : charCount) {
      if (it.second > 1) {
        duplicateChars += it.first;
      }
    }
  }

  void printDuplicateCharacters() {
    cout << duplicateChars << endl;
  }
};

int main() {
  string input;
  cout << "Enter input: ";
  getline(cin, input);
  HappyNumber hn(input.length());
  cout << "Output:\n";
  if (hn.isHappy()) {
    AnagramClass ac(input);
    ac.generateAnagrams();
    ac.printAnagrams();
  } else {
    GetDuplicateCharacters gdc(input);
    gdc.printDuplicateCharacters();
  }
}