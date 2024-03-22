#include <cstring>
#include <iostream>

using namespace std;

bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int wordToInt(char *str, char **saveptr) {
  // If the string is "zero", return 0
  if (strcmp(str, "zero") == 0)
    return 0;
  // If the string is "one hundred", return 100
  if (strcmp(str, "one hundred") == 0)
    return 100;

  // Array of words representing numbers from 1 to 90
  const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

  // Corresponding integer values for the words
  int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90};

  // Variable to store the result
  int result = 0;

  // Split the string into words separated by "-"
  char *word = strtok_r(str, "-", saveptr);
  while (word != NULL) {
    bool isFound = 0;
    // Loop through the words array
    for (int i = 0; i < 27; i++) {
      // If the word matches with the word in the array
      if (strcmp(word, words[i]) == 0) {
        isFound = 1;
        // Add the corresponding value to the result
        result += values[i];
        break;
      }
    }
    // If the word is not found in the array, print an error message and exit
    if (!isFound) {
      cout << "Error: Invalid word found in input: " << word << endl;
      exit(EXIT_FAILURE);
    }
    // Get the next word
    word = strtok_r(NULL, "-", saveptr);
  }
  // Return the result
  return result;
}

int main() {
  // String to store the input
  char str[100];
  cout << "Enter input: ";
  // Read the input
  cin.getline(str, 100);

  char *saveptr;
  cout << "\nOutput: ";
  // Split the string into words separated by " "
  char *token = strtok(str, " ,");
  while (token != NULL) {
    // If the integer representation of the word is prime, print the word
    if (isPrime(wordToInt(token, &saveptr))) {
      cout << token << " ";
    }
    // Get the next word
    token = strtok(NULL, " ,");
  }
}
