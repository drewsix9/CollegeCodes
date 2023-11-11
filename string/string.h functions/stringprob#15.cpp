#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

int isUnique(string &str)
{
  unordered_set<char> c;
  for (int i = 0; i < str.length(); i++)
  {
    c.insert(str[i]);
  }

  if (c.size() != str.length())
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

  int maxUnique = 0;
  string max;
  stringstream stream(input);
  while (stream >> token)
  {
    if (isUnique(token))
    {
      int count = token.length();
      if (count > maxUnique)
      {
        maxUnique = count;
        max = token;
      }
    }
  }

  cout << max;

  return 0;
}