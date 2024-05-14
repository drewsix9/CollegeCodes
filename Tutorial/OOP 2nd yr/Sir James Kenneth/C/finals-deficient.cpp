#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool isDeficientNumber(int num) {
  int divisors[100] = {};
  int divisorSum = 0;
  int n = 0;
  for (int i = 1; i <= num; i++) {
    if (num % i == 0) {
      divisorSum += i;
      divisors[n] = i;
      n++;
    }
  }
  // for (int i = 0; i < n; i++) {
  //   cout << divisors[i] << " ";
  // }
  // cout << "\nDivisor sum: " << divisorSum << endl;
  return divisorSum < num * 2;
}

char encryptDeficientChar(char c) {
  return (c - 'a' + 5 + 26) % 26 + 'A';
}
char encryptNotDeficientChar(char c) {
  if (isupper(c)) {
    return (c - 'A' + 5) % 26 + 'A';
  } else {
    return (c - 'a' + 5) % 26 + 'a';
  }
}

string stringEncrypt(string &input) {
  string res;
  for (char c : input) {
    if (isspace(c))
      res += c;
    else if (isDeficientNumber(c)) {
      cout << c << " is deficient\n";
      res += encryptDeficientChar(c);
    } else {
      cout << c << " is NOT deficient\n";
      res += encryptNotDeficientChar(c);
    }
  }
  return res;
}

int main() {
  // string input;
  // cout << "Enter a input: ";
  // getline(cin, input);
  // cout << "\nOutput: ";
  // cout << stringEncrypt(input) << endl;

  // for (int i = 0; i < 26; i++) {
  //   cout << (char)('a' + i) << " " << 'a' + i << " -> " << boolalpha << isDeficientNumber('a' + i) << "\t" << (char)('a' + i - 32) << " " << 'a' + i + 32 << " -> " << boolalpha << isDeficientNumber('a' + i + 32) << endl;
  // }

  for (int i = 1; i <= 26; i++) {
    cout << boolalpha << isDeficientNumber(i) << endl;
  }

  // cout << boolalpha << isDeficientNumber(120) << endl;
}