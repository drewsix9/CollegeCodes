#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int numWordtoInt(char str[]) {
  map<string, int> wordToNum = {
      {"zero", 0},
      {"one", 1},
      {"two", 2},
      {"three", 3},
      {"four", 4},
      {"five", 5},
      {"six", 6},
      {"seven", 7},
      {"eight", 8},
      {"nine", 9},
      {"ten", 10},
      {"eleven", 11},
      {"twelve", 12},
      {"thirteen", 13},
      {"fourteen", 14},
      {"fifteen", 15},
      {"sixteen", 16},
      {"seventeen", 17},
      {"eighteen", 18},
      {"nineteen", 19},
      {"twenty", 20},
      {"thirty", 30},
      {"forty", 40},
      {"fifty", 50},
      {"sixty", 60},
      {"seventy", 70},
      {"eighty", 80},
      {"ninety", 90},
      {"one hundred", 100},
  };

  int result = 0;

  char *word = strtok(str, " ");
  while (word != NULL) {
    if (wordToNum.find(word) != wordToNum.end()) {
      result += wordToNum[word];
    } else {
      cout << "Error: Invalid word found in input: " << word << endl;
      exit(EXIT_FAILURE);
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
    cout << "Enter number: ";
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