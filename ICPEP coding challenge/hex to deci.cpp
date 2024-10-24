#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int hashMap(char c) {
  std::string map = "0123456789ABCDEF";
  auto it = map.find(c);
  return ((it != string::npos) ? static_cast<int>(it) : -1);
}

int hexToDeci(string s) {
  int sum = 0, pow = 1, prod, rem;
  while (s.size() > 0) {
    rem = hashMap(s.back());
    if (rem == -1) {
      cout << "\n[WARNING] Wrong Input!";
      return -1;
    }
    prod = rem * pow;
    pow *= 16;
    sum += prod;
    s.pop_back();
  }
  return sum;
}

int main() {
  string input;
  cout << "\nEnter Hexadecimal: ";
  cin >> input;
  cout << "\nOutput: " << hexToDeci(input);
}
