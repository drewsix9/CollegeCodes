#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int isPrime(int num)
{
  if (num < 1)
    return 0;

  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

int main()
{
  vector<string> strs;
  string input, token;
  cout << "Enter inputs: ";
  getline(cin, input);

  int maxCount = 0;
  string max;
  stringstream stream(input);
  while (stream >> token)
  {
    int count = token.length();
    reverse(token.begin(), token.end());
    strs.push_back(token);
    if (count > maxCount)
    {
      max = token;
      maxCount = count;
    }
  }

  cout << "\nOutput: ";
  for (int i = 0; i < maxCount; i++)
  {
    int sum = 0;
    for (auto str : strs)
    {
      string sub = str.substr(i, 1);
      int num = stoi(sub);
      sum += num;
    }
    if (isPrime(sum))
    {
      cout << sum << " ";
    }
    else
    {
      cout << 0 << " ";
    }
  }

  return 0;
}
