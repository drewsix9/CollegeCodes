#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string input;
  vector<string> strs;

  cout << "Enter inputs (0 to stop): ";
  while (cin >> input && input != "0")
  {
    strs.push_back(input);
  }

  string small = strs.front();
  for (auto str : strs)
  {
    if (small.length() > str.length())
    {
      small = str;
    }
  }

  char common;
  for (int i = 0; i < small.length(); i++)
  {
    common = small[i];
    int isCommon = 1;
    for (auto str : strs)
    {
      if (str.find(small[i]) == string::npos)
      {
        isCommon = 0;
        break;
      }
    }
    if (isCommon == 1)
      break;
  }

  cout << "common: " << common << endl;

  for (auto str : strs)
  {
    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] != common)
      {
        cout << str[i];
      }
    }
    cout << " ";
  }

  return 0;
}