#include <iostream>
#include <string>
#include <unordered_set>
#include <list>

using namespace std;

class Solution
{
public:
  string substringWithUnique(string s)
  {
    list<char> l;
    unordered_set<char> set;
    int i = 0;
    l.push_back(s[i++]);
    set.insert(l.back());
    int maxCount = 0;
    string sub;
    while (i < s.length())
    {
      if (set.count(s[i]) == 0)
      {
        l.push_back(s[i++]);
        set.insert(l.back());
        if (l.size() > maxCount)
        {
          maxCount = l.size();
          sub.clear();
          for (char c : l)
          {
            sub += c;
          }
        }
      }
      else
      {
        set.erase(l.front());
        l.pop_front();
      }
    }
    return sub;
  }
};

int main()
{
  string input;
  cout << "Enter string: ";
  getline(cin, input);

  Solution sol;
  cout << "\noutput: ";
  cout << sol.substringWithUnique(input);
}