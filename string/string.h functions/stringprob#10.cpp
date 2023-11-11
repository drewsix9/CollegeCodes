#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
  string input, token, sub;
  cout << "Enter inputs: ";
  getline(cin, input);

  cout << "Enter substring: ";
  getline(cin, sub);

  vector<string> strs;
  stringstream stream(input);
  while (stream >> token)
  {
    strs.push_back(token);
  }

  cout << "\nOutput: ";
  for (auto str : strs)
  {
    int count = 0, start = 0;
    int pos = str.find_first_of(sub);
    while (pos != string::npos)
    {
      count++;
      start = pos + 1;
      pos = str.find_first_of(sub, start);
    }
    cout << count << " ";
  }
}