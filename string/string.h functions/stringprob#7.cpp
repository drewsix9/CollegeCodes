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
  cout << "Enter string lines (0 to stop):\n";
  while (getline(cin, input) && input != "0")
  {
    strs.push_back(input);
  }

  int maxUnique = 0;
  string max;
  for (auto str : strs)
  {
    unordered_set<string> set;
    stringstream stream(str);

    while (stream >> input)
    {
      set.insert(input);
    }

    int count = set.size();
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