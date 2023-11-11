
// [A] Binary
// [B] Octal
// [C] Hexadecimal

// Enter input: 456
// Enter Choice: C
// Hexadecimal: 1C8

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int deciToBin(string s) {
  int num = stoi(s);
  int prod, pow = 1, sum = 0;
  while (num > 0) {
    prod = (num % 2) * pow;
    pow *= 10;
    sum += prod;
    num /= 2;
  }
  return sum;
}

int deciToOctal(string s) {
  int num = stoi(s);
  int sum = 0, prod, pow = 1;
  while (num > 0) {
    prod = (num % 8) * pow;
    pow *= 10;
    sum += prod;
    num /= 8;
  }
  return sum;
}

char hashMap(int n) {
  string map = "0123456789ABCDEF";
  return map[n];
}

string deciToHexa(string s) {
  int num = stoi(s), rem;
  string res = "";
  while (num > 0) {
    rem = num % 16;
    res += hashMap(rem);
    num /= 16;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  while (1) {
    string input;
    char choice;
    cout << "\n\n[A] - Binary";
    cout << "\n[B] - Octal";
    cout << "\n[C] - Hexa";
    cout << "\nEnter decimal num: ";
    cin >> input;
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
    case 'A':
      cout << "\nBinary: " << deciToBin(input);
      break;
    case 'B':
      cout << "\nOctal: " << deciToOctal(input);
      break;
    case 'C':
      cout << "\nHexa: " << deciToHexa(input);
      break;
    default:
      cout << "\nWrong input!";
      break;
    }
  }
}