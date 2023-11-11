#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  string input, token, max;
  int maxCount = 0;
  cout << "Enter string: ";
  getline(cin, input);

  stringstream stream(input);
  while (stream >> token)
  {
    if (maxCount < token.length())
    {
      max = token;
      maxCount = token.length();
    }
  }

  cout << "\nOutput: "
       << "\"" << max
       << "\"";
  return 0;
}