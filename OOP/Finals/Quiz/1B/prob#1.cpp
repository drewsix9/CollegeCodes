#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
  string input, temp;
  cout << "Enter inputs: ";
  getline(cin, input);

  vector<string> v;
  unordered_map<string, int> m;

  stringstream stream(input);
  while (stream >> temp)
  {
    v.push_back(temp);
    m[temp]++;
  }

  for (auto i : v)
  {
    if (m[i] > 1)
    {
      cout << i << " ";
    }
    else
    {
      string str(i.rbegin(), i.rend());
      cout << str << " ";
    }
  }

  return 0;
}