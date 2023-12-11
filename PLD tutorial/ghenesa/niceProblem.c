#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isVowel(char c) {
  char *vowels = "aeiouAEIOU";
  char *ptr = strchr(vowels, c);
  return (ptr ? 1 : 0); // single line if else statement // a.k.a ternary operator
}

int main() {
  char conso[26];
  char vowels[26];
  int nConso = 0;
  int nVowel = 0;
  for (int i = 0; i < 26; i++) {
    char c = 'a' + i;
    if (!isVowel(c)) {
      conso[nConso] = c;
      nConso++;
    } else {
      vowels[nVowel] = c;
      nVowel++;
      int n = 1;
      while (n <= 3) {
        vowels[nVowel] = c;
        nVowel++;
        n++;
      }
    }
  }

  char str[100];
  printf("%s", "Enter string input:\n");
  fgets(str, 100, stdin);
  int n = strlen(str);
  for (int i = 0; i < n; i++) {
    char curr = str[i];
    int isCapital = 0;
    if (isupper(curr)) {
      isCapital = 1;
      curr = tolower(curr);
    }
    if (isalpha(curr)) {
      if (isVowel(curr)) { // vowel
        char *firstAppearanceOfVowel = strchr(vowels, curr);
        int pos = (firstAppearanceOfVowel - vowels);
        if (isCapital) {
          char c = toupper(conso[pos + 1]);
          printf("%c", c);
        } else {
          printf("%c", conso[pos + 1]);
        }
      } else { // consonant
        char *firstAppearanceOfConso = strchr(conso, curr);
        int pos = firstAppearanceOfConso - conso;
        if (isCapital) {
          char c = toupper(vowels[pos]);
          printf("%c", c);
        } else {
          printf("%c", vowels[pos]);
        }
      }
    } else {
      printf(" ");
    }
  }
}

// bcdfghjklmnpqrstvwxyz - consonant
// aaaaeeeeiiiioooouuuuu

// gieford
// emharoa

// bem
// ahi
