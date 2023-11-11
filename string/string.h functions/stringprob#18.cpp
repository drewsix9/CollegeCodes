#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int isVowel(char c)
{
  string vowels = "aeiouAEIOU";
  if (vowels.find(c) != string::npos)
  {
    return 1;
  }
  return 0;
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
    int pos = token.length() - 3;

    if (isVowel(token[pos]))
    {
      token.erase(pos + 1, 2);
      cout << token << " ";
    }
    else
    {
      token.insert(0, 1, token[pos]);
      token.erase(pos + 1, 3);
      cout << token << " ";
    }
  }

  return 0;
}