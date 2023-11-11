#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int isVowel(char c)
{
  string vowels = "aeiouAEIOU";
  if (vowels.find_first_of(c) == string::npos)
  {
    return 0;
  }
  return 1;
}

int main()
{
  string input, token;
  cout << "Enter input: ";
  getline(cin, input);

  cout << "\nOutput: ";
  stringstream stream(input);
  while (stream >> token)
  {
    if (isVowel(token[0]))
    {
      token += "ay";
      cout << token << " ";
    }
    else
    {
      token += token[0];
      token += "ay";
      token.erase(0, 1);
      cout << token << " ";
    }
  }
}