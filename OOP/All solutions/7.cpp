/*
input: hello world orleans
string to be reversed: orl

output: hello wlrod lroeans
*/

#include <cstring>
#include <iostream>

using namespace std;

void printReverse(char *str, int size) {
  for (int i = size - 1; i >= 0; i--) {
    cout << str[i];
  }
}

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
    if (strncmp(ptr, key, strlen(key)) == 0) { // if the key is found in the string
      printReverse(key, strlen(key));          // print the key in reverse
      ptr += strlen(key);
      i += strlen(key);
    } else {
      cout << *ptr;
      ptr++;
      i++;
    }
  }
}