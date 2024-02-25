#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char vowels[] = "aeiouAEIOU";
  char ch;
  printf("Enter a character: ");
  scanf("%c", &ch);

  // strchr returns a pointer to the first occurrence of the character ch in the string vowels
  char *result = strchr(vowels, ch);

  if (result != NULL)
    printf("%c is a vowel.\n", ch);
  else
    printf("%c is a consonant.\n", ch);
}