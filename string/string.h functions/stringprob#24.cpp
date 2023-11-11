#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int isPalindrome(string str)
{
  if (str.length() == 1)
    return 1;

  int mid = str.length();
  for (int i = 0; i < mid; i++)
  {
    if (str[i] != str[str.length() - i - 1])
      return 0;
  }
  return 1;
}

string ignoreVowel(string &str)
{
  string vowels = "aeiouAEIOU";
  int pos = str.find_first_not_of(vowels);

  return str.substr(pos);
}

int main()
{
  string input, token;
  cout << "Enter inputs: ";
  getline(cin, input);

  cout << "\nOutput:\n";
  stringstream stream(input);
  while (stream >> token)
  {
    if (isPalindrome(ignoreVowel(token)))
    {
      cout << token << " is palindrome" << endl;
    }
  }
  return 0;
}