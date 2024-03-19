#include <cstring>
#include <iostream>

using namespace std;

int numWordtoInt(char str[]) {

  if (strcmp(str, "zero") == 0)
    return 0;
  const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred"};
  int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 3, 4, 5, 6, 7, 8, 9, 100};
  int result = 0;
  char *word = strtok(str, " ");
  while (word != NULL) {
    for (int i = 0; i < 28; i++) {
      if (i == 27) { // If word is "hundred", multiply result by 100
        result *= 10;
        break;
      }
      if (strcmp(word, words[i]) == 0) {
        result *= 10;
        result += values[i];
        break;
      }
    }
    word = strtok(NULL, " ");
  }
  return result;
}

void sort(char arrStr[][100], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      char temp1[50], temp2[50];
      strcpy(temp1, arrStr[i]);
      strcpy(temp2, arrStr[j]);
      if (numWordtoInt(temp1) > numWordtoInt(temp2)) {
        char temp[50];
        strcpy(temp, arrStr[i]);
        strcpy(arrStr[i], arrStr[j]);
        strcpy(arrStr[j], temp);
      }
    }
  }
}

int main() {
  char str[100];
  char arrStr[100][100];
  int n = 0;
  printf("Enter how many numbers: ");
  cin >> n;
  cin.ignore(); // Ignore newline
  for (int i = 0; i < n; i++) {
    char temp[100];
    printf("Enter number: ");
    cin.getline(str, 100);
    strcpy(temp, str);
    cout << "Number: " << numWordtoInt(str) << endl;
    strcpy(arrStr[i], temp);
  }
  sort(arrStr, n);
  cout << "\n\nOutput: ";
  for (int i = 0; i < n; i++) {
    cout << arrStr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  return 0;
}
