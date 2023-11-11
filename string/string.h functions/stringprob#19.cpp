#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int isPrime(int num)
{
  if (num < 1)
    return 0;

  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

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
    if (isPrime(token.length()))
    {
      for (int i = 0; i < token.length(); i++)
      {
        if (!isVowel(token[i]))
        {
          cout << token[i];
        }
      }
    }
    else
    {
      for (int i = 0; i < token.length(); i++)
      {
        if (isVowel(token[i]))
        {
          cout << token[i];
        }
      }
    }
    cout << " ";
  }
}