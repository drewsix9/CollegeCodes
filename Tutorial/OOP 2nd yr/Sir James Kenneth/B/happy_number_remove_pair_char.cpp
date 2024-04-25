#include <iostream>
#include <string>

using namespace std;

string reverseStr(string &str) {
  int size = str.length();
  for (int i = 0; i < size / 2; i++) {
    swap(str[i], str[size - i - 1]);
  }
  return str;
}

string removePairChars(string &str) {
  int size = str.length();
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (str[i] == str[j]) {
        str.erase(j, 1);
        str.erase(i, 1);
        size -= 2;
        i = -1;
        break;
      }
    }
  }
  return str;
}

string sortStr(string &str) {
  int size = str.length();
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (str[i] > str[j]) {
        swap(str[i], str[j]);
      }
    }
  }
  return str;
}

class Number {
public:
  int num;
  Number(int x) : num(x) {}
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
  HappyNumber hn = HappyNumber(input.length());
  if (hn.isHappy()) {
    string sorted = sortStr(input);
    cout << "input length is HAPPY number" << endl;
    cout << "Output:" << removePairChars(sorted) << endl;
  } else {
    cout << "input length is UNHAPPY number" << endl;
    cout << "Output:" << reverseStr(input) << endl;
  }
}