#include <cstring>
#include <iostream>

using namespace std;

char incrementChar(char c) {
  // Convert the character 'c' to its corresponding integer value by subtracting the ASCII value of '0'
  int intValue = c - '0';

  // Increment the integer value by 1
  intValue = intValue + 1;

  // Convert the incremented integer value back to its corresponding character by adding the ASCII value of '0'
  char result = intValue + '0';

  // Return the incremented character
  return result;

  // The above code can be written in a single line as follows:
  // return (char)((c - '0') + 1 + '0');
}

bool hasConsecutiveDigits(char *token) {
  int len = strlen(token);
  // len - 1 because we want to end right before the last character
  for (int i = 0; i < len - 1; i++) {
    if (token[i + 1] == incrementChar(token[i])) {
      return true;
    }
  }
  return false;
}

int main() {
  char str[100];
  cout << "Enter inputs: ";
  cin.getline(str, 100);

  cout << "\nOutput: ";
  char *token = strtok(str, " ");
  while (token != NULL) {
    if (!hasConsecutiveDigits(token)) {
      cout << token << " ";
    }
    token = strtok(NULL, " ");
  }
}