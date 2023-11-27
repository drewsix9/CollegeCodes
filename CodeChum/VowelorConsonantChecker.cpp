#include <ctype.h>
#include <iostream>
#include <set>

using namespace std;

int main() {
  set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
  char c;
  cout << "Enter a letter: ";
  cin >> c;
  if (!isalpha(c)) {
    cout << "Invalid input";
    return 1;
  }
  if (vowels.count(c) > 0) {
    cout << c << " is a vowel";
  } else {
    cout << char(toupper(c)) << " is a consonant";
  }
}