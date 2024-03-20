/*
Input a string and a word to be deleted

Input: hello world hoord
string to be removed: or

Output: hello wld hod
*/

#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char str[100];
  char word[100];
  cout << "Enter a string: ";
  cin.getline(str, 100);
  cout << "Enter a word to delete: ";
  cin.getline(word, 100);

  char *ptr = str;
  int i = 0;
  cout << "\nOutput: ";
  while (i < strlen(str)) {
    if (strncmp(ptr + i, word, strlen(word)) == 0) {
      i += strlen(word);
    } else {
      cout << *(ptr + i);
      i++;
    }
  }
}