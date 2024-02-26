#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int BintoDec(int num) {
  int rem = 0, sum = 0, prod = 0, power = 1;
  while (num > 0) {
    rem = num % 10;
    prod = rem * power;
    power *= 2;
    sum += prod;
    num /= 10;
  }
  return sum;
}

int main() {
  string input, temp;
  cout << "Enter inputs: ";
  getline(cin, input);

  cout << "\nOutput: ";
  stringstream stream(input);
  while (stream >> temp) {
    if (temp.find(".") != string::npos) {
      cout << temp << " ";
    } else {
      int num = stoi(temp);
      cout << BintoDec(num) << " ";
    }
  }
}