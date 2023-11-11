#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
  string input;
  cout << "Enter inputs: ";
  getline(cin, input);

  vector<string> strs;
  stringstream stream(input);
  string token;
  while (stream >> token)
  {
    strs.push_back(token);
  }

  int maxUnique = 0;
  string max;

  for (auto str : strs)
  {
    unordered_set<char> c;
    for (int i = 0; i < str.length(); i++)
    {
      c.insert(str[i]);
    }
    int count = c.size();
    if (count > maxUnique)
    {
      maxUnique = count;
      max = str;
    }
  }

  cout << "\nOutput: "
       << "\"" << max << "\""
       << " - " << maxUnique;

  return 0;
}