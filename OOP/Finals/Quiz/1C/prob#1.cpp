#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int BintoDeci(int num)
{
  int prod, power = 1, sum = 0;
  while (num > 0)
  {
    prod = (num % 10) * power;
    power *= 2;
    sum += prod;
    num /= 10;
  }
  return sum;
}

int main()
{
  string input, temp;
  cout << "Enter inputs: ";
  getline(cin, input);

  cout << "\nOutput: ";
  stringstream stream(input);
  while (stream >> temp)
  {
    int num = stoi(temp);
    cout << BintoDeci(num) << " ";
  }
}