#include <cstring>
#include <iostream>

using namespace std;

void sortWords(char *arrayofwords[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strlen(arrayofwords[i]) > strlen(arrayofwords[j])) {
        char *temp = arrayofwords[i];
        arrayofwords[i] = arrayofwords[j];
        arrayofwords[j] = temp;
      }
    }
  }
}

int main() {
  char str[100];
  cout << "Enter input: ";
  cin.getline(str, 100);

  char *arrayofwords[100];
  char *token = strtok(str, " ");
  int n = 0;

  while (token != NULL) {
    arrayofwords[n] = token;
    token = strtok(NULL, " ");
    n++;
  }

  sortWords(arrayofwords, n);

  cout << "Output: ";
  for (int i = 0; i < n; i++) {
    cout << arrayofwords[i] << " ";
  }
}