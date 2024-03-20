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

  char *ptr = str;                               // Declare a pointer to the character array 'str'
  int i = 0;                                     // Initialize a counter variable
  cout << "\nOutput: ";                          // Print a message to the console
  while (i < strlen(str)) {                      // Loop through the characters in 'str'
    if (strncmp(ptr, word, strlen(word)) == 0) { // If the current sequence of characters in 'str' matches 'word'
      ptr += strlen(word);                       // Move the pointer forward by the length of 'word'
      i += strlen(word);                         // Increment the counter by the length of 'word'
    } else {                                     // If the current sequence of characters in 'str' does not match 'word'
      cout << *ptr;                              // Print the current character to the console
      ptr++;                                     // Move the pointer forward by one
      i++;                                       // Increment the counter by one
    }
  }
}