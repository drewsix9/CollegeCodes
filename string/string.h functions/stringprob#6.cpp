#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

int main()
{
  vector<string> strs;

  string input;

  cout << "Enter input string: ";
  getline(cin, input);

  stringstream stream(input);
  string token;
  while (stream >> token)
  {
    strs.push_back(token);
  }

  string Max;
  int maxUnique = 0;
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
      Max = str;
    }
  }

  cout << "\nOutput: " << Max << " " << maxUnique;

  return 0;
}