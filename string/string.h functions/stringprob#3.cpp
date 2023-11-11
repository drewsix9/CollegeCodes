#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<string> strs;
  string temp;

  cout << "Enter inputs (0 to stop): ";
  while (cin >> temp && temp != "0")
  {
    strs.push_back(temp);
  }

  string suffix = strs.front();
  for (auto itr : strs)
  {
    if (suffix.length() > itr.length())
    {
      suffix = itr;
    }
  }

  reverse(suffix.begin(), suffix.end());
  for (auto itr : strs)
  {
    string temp = itr;
    reverse(temp.begin(), temp.end());

    while (temp.find(suffix) == temp.npos)
    {
      suffix.pop_back();
    }
  }

  reverse(suffix.begin(), suffix.end());

  if (suffix.length() > 0)
  {
    cout << "\nLongest Common Suffix: " << suffix;
  }
  else
  {
    cout << " \nNo Common Suffix!";
  }

  return 0;
}