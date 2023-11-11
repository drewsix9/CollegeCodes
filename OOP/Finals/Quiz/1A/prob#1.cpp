#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int solution(string &str)
{
  string vowels("aeiouAEIOU");
  unordered_map<char, int> m;

  for (auto c : str)
  {
    if (vowels.find(c) != string::npos)
    {
      m[c]++;
    }
  }

  for (auto i : m)
  {
    if (i.second == 2)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  string input, temp;
  cout << "Enter input: ";
  getline(cin, input);

  stringstream stream(input);
  while (stream >> temp)
  {
    if (solution(temp))
    {
      string str(temp.rbegin(), temp.rend());
      cout << str << " ";
    }
    else
    {
      cout << temp << " ";
    }
  }

  return 0;
}