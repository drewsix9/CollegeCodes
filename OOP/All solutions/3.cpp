/*
reverse the word if it contains strictly double consecutive same vowel letter

input: hello wooorld book

output: hello wooorld koob
*/

#include <cstring>
#include <iostream>

using namespace std;

int main() {

  const char *vowels = "aeiouAEIOU";

  char str[100];
  cout << "Enter a string: ";
  cin.getline(str, 100);
  cout << str;

  cout << "\nOutput: ";
  char *word = strtok(str, " ");
  while (word != NULL) {
    char *hasVowel = strpbrk(word, vowels);
    if (hasVowel != NULL) {
      strrev(word);
    }
    cout << word << " ";
    word = strtok(NULL, " ");
  }
}