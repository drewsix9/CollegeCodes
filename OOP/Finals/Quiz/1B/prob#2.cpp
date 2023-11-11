#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  string input, del;
  cout << "Enter inputs: ";
  getline(cin, input);

  cout << "\nEnter string to be removed: ";
  cin >> del;

  cout << "\nOutput: ";
  int n = del.length();
  size_t it = input.find(del);
  while (it != string::npos)
  {
    input.erase(it, n);
    it = input.find(del);
  }
  cout << input;
  return 0;
}