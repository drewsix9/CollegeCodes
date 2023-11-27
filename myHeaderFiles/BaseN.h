#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isBinary(int n) {
  while (n > 0) {
    if (n % 10 > 1) {
      return false;
    }
    n /= 10;
  }
  return true;
}

int BintoDeci(int n) {
  int sum = 0, pow = 1, prod = 0;
  while (n > 0) {
    prod = n % 10 * pow;
    pow *= 2;
    sum += prod;
    n /= 10;
  }
  return sum;
}

int DecitoBin(int n) {
  int sum = 0, pow = 1, prod = 0;
  while (n > 0) {
    prod = n % 2 * pow;
    pow *= 10;
    sum += prod;
    n /= 2;
  }
  return sum;
}

int OctaltoDeci(int n) {
  int sum = 0, pow = 1, prod = 0;
  while (n > 0) {
    prod = n % 10 * pow;
    pow *= 8;
    sum += prod;
    n /= 10;
  }
  return sum;
}

int DecitoOctal(int n) {
  int sum = 0, pow = 1, prod = 0;
  while (n > 0) {
    prod = n % 8 * pow;
    pow *= 10;
    sum += prod;
    n /= 8;
  }
  return sum;
}

int HexaHashMap(char c) {
  if (isalpha(c)) {
    c = toupper(c);
  }
  string hex = "0123456789ABCDEF";
  int pos = hex.find(c);
  if (pos == string::npos) {
    return -1;
  }
  return static_cast<int>(pos);
}

int HextoDeci(string str) {
  int sum = 0, pow = 1;
  reverse(str.rbegin(), str.rend());
  for (char c : str) {
    int value = HexaHashMap(c);
    if (value == -1) {
      cout << "Invalid Hexadecimal input";
      return -1;
    }
    sum += value * pow;
    pow *= 16;
  }
  return sum;
}