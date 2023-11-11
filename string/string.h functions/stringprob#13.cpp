#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  string input, token, key;
  cout << "Enter input: ";
  getline(cin, input);

  cout << "Enter substring to search: ";
  cin >> key;

  const char *ptr = input.c_str(); // getting the pointer
  cout << *ptr << endl;

  cout << "\nOutput:\n";
  int wordCount = 0;
  stringstream stream(input);
  while (stream >> token)
  {
    wordCount++;
    int start = 0;
    int pos = token.find(key);
    while (pos != string::npos)
    {
      cout << "word: " << wordCount << " pos: " << pos << endl;
      start = pos + 1;
      pos = token.find(key, start);
    }
  }
  return 0;
}