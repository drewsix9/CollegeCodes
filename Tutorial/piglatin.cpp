#include <cstring>
#include <iostream>

using namespace std;

// int main() {
//   string vowels = "aeiouAEIOU";
//   string str, temp;
//   cout << "Enter a phrase: ";
//   getline(cin, str);

//   stringstream ss(str);

//   cout << "Pig Latin: ";
//   while (ss >> temp) {
//     if (vowels.find(temp[0]) != string::npos) { // if the first letter is a vowel
//       cout << temp << "ay ";
//     } else { // if the first letter is a consonant
//       cout << temp.substr(1) << temp[0] << "ay ";
//     }
//   }
// }

int main() {
  char vowels[] = "aeiouAEIOU";
  char str[100];
  cout << "Enter a phrase: ";
  fgets(str, 100, stdin);
  str[strlen(str) - 1] = '\0'; // remove the newline character

  cout << "Pig Latin: ";

  char *token = strtok(str, " ");
  while (token != NULL) {
    if (strchr(vowels, token[0]) != NULL) { // if the first letter is a vowel
      cout << token << "ay ";
    } else { // if the first letter is a consonant
      cout << token + 1 << token[0] << "ay ";
    }
    token = strtok(NULL, " ");
  }
}