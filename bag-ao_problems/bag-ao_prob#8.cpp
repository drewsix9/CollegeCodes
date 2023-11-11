#include <iostream>
#include <string>
#include <sstream>
#include <map>

/*
  Input: abcc efffgh ijkli
  Output: ab egh jkl
*/

using namespace std;

int main()
{
  string input, word;
  cout << "Enter inputs: ";
  getline(cin, input);

  stringstream stream(input);
  while (stream >> word)
  {
    map<char, int> m;
    for (int i = 0; i < int(word.size()); i++)
    {
      m[word[i]]++;
    }

    for (auto it = m.begin(); it != m.end();)
    {
      if (it->second > 1)
      {
        it = m.erase(it);
      }
      else
      {
        ++it;
      }
    }

    for (auto c : word)
    {
      if (m.find(c) != m.end())
      {
        cout << c;
      }
    }

    cout << " ";
  }
}