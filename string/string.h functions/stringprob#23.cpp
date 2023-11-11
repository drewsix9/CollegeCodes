#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int isPalindrome(string &str)
{
  if (str.length() == 1)
    return 1;

  int mid = str.length() / 2;
  for (int i = 0; i < mid; i++)
  {
    if (str[i] != str[str.length() - i - 1])
    {
      return 0;
    }
  }
  return 1;
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
    string temp = token;
    int mid;
    if (temp.length() % 2 == 0)
    {
      mid = temp.length() / 2;
    }
    else
    {
      mid = (temp.length() / 2) + 1;
    }
    for (int i = mid, j = 0; i < temp.length() - 1; j++, i++)
    {
      swap(temp[i], temp[temp.length() - j - 1]);
    }
    if (isPalindrome(temp))
    {
      cout << token << " ";
    }
  }
}