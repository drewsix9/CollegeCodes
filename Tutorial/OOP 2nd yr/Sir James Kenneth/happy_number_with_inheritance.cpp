#include <iostream>
#include <string>

using namespace std;

string reverseStr(string &str) {
  for (int i = 0; i < str.length() / 2; i++) {
    swap(str[i], str[str.length() - 1 - i]);
  }
  return str;
}

class Number {
public:
  int num;
  Number(int num) : num(num) {}
};

class HappyNumber : public Number {
public:
  HappyNumber(int num) : Number(num) {}
  bool isHappy() {
    int sum = 0;
    while (num > 0) {
      int digit = num % 10;
      sum += digit * digit;
      num /= 10;
    }
    if (sum == 1) {
      return true;
    } else if (sum == 4) {
      return false;
    } else {
      num = sum;
      return isHappy();
    }
  }
};

int main() {
  string input;
  cout << "Enter input: ";
  getline(cin, input);
  cout << input << endl;
  HappyNumber hn = HappyNumber(input.length());
  cout << input << " has a length of " << input.length() << endl;
  cout << "Output: " << (hn.isHappy() ? input : reverseStr(input)) << endl;
}