#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void DecitoBin(int num)
{
  int sum = 0, rem, prod = 0, power = 1;
  while (num > 0)
  {
    rem = num % 2;
    prod = rem * power;
    power *= 10;
    sum += prod;
    num /= 2;
  }
  cout << setfill('0') << setw(8) << sum << " ";
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
    int num = stoi(token);
    DecitoBin(num);
  }
  return 0;
}