#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
  string input, replace, del, token;
  cout << "Enter input: ";
  getline(cin, input);
  cout << "Enter word to delete: ";
  cin >> del;
  cout << "Enter word to replace: ";
  cin >> replace;

  cout << "\nOutput: ";
  stringstream stream(input);
  while (stream >> token)
  {
    if (token != del)
    {
      cout << token << " ";
    }
    else
    {
      cout << replace << " ";
    }
  }
}