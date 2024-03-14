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
  char str[100], key[100];
  cout << "Enter a string: ";
  cin.getline(str, 100);
  cout << "Enter a string to be removed: ";
  cin.getline(key, 100);
  int i = 0;
  char *ptr = str;
  cout << "\nOutput: ";
  while (i < strlen(str)) {
    if (strncmp(ptr, key, strlen(key)) == 0) {
      ptr += strlen(key);
      i += strlen(key);
    } else {
      cout << *ptr;
      ptr++;
      i++;
    }
  }
}