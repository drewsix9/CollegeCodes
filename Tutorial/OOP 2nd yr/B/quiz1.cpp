#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
  string str;
  cout << "Enter inputs: ";
  getline(cin, str);

  cout << "\nOutput: ";
  int i = 0, j = i + 1;
  while (j < str.length()) {
    j = i + 1;
    if (str[i] == str[j]) { // if the current character is equal to the next
      while (str[i] == str[j]) {
        j++;
      }
    } else {
      cout << str[i];
    }
    i = j;
  }
}
