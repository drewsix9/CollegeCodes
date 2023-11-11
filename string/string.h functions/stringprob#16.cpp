#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int isPrime(int num)
{
  if (num < 1)
    return 0;

  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int countUnique(string &str)
{
  unordered_set<char> set;
  for (char c : str)
  {
    set.insert(c);
  }
  return set.size();
}

int main()
{
  string input, token;
  cout << "Enter inputs: ";
  getline(cin, input);

  cout << "\nOutput: ";
  stringstream stream(input);
  while (stream >> token)
  {
    int count = countUnique(token);
    if (isPrime(count))
    {
      reverse(token.begin(), token.end());
      // string temp(token.rbegin(), token.rend());
      cout << token << " ";
    }
    else
    {
      cout << token << " ";
    }
  }
}