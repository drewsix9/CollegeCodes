#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int isBinary(string &str)
{
  if (str.find_first_not_of("01") != string::npos)
  {
    return 0;
  }
  return 1;
}

int main()
{
  string input, token;
  cout << "Enter string: ";
  getline(cin, input);

  vector<string> strs;
  cout << "\nOutput: ";
  stringstream stream(input);
  while (stream >> token)
  {
    if (isBinary(token))
    {
      strs.push_back(token);
    }
  }

  for (auto i = strs.begin(); i != strs.end(); i++)
  {
    for (auto j = i + 1; j != strs.end(); j++)
    {
      if (i->compare(*j) < 0)
      {
        swap(*i, *j);
      }
    }
  }

  for (auto str : strs)
  {
    cout << str << " ";
  }
}