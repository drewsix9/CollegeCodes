/*
REVERSE the word if it has not repeated.
STRICTLY inputing of inputs must be done in one line

Input: hello hi hi world

Output: olleh hi hi dlrow
*/

#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char str[100];
  char array[100][100]; // each word can store up to 100 characters, and there can be up to 100 words
  cout << "Enter a string: ";
  cin.getline(str, 100);
  char *word = strtok(str, " ");
  int n = 0;
  while (word != NULL) {
    strcpy(array[n], word);
    n++;
    word = strtok(NULL, " ");
  }

  int freq[100];
  memset(freq, 0, 100 * sizeof(int)); // sets all the values of freq to 0

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(array[i], array[j]) == 0) {
        freq[i]++;
        freq[j]++;
      }
    }
  }

  cout << "\nOutput: ";
  for (int i = 0; i < n; i++) {
    if (freq[i] == 0) {
      strrev(array[i]);
    }
    cout << array[i] << " ";
  }
}