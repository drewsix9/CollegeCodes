#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int size(int num) {
  int count = 1;
  while (num / 10 > 0) {
    num /= 10;
    count++;
  }
  return count;
}

int evaluate(int x, int y, char c) {
  switch (c) {
  case '*':
    return x * y;
    break;
  case '/':
    return x / y;
    break;
  case '+':
    return x + y;
    break;
  case '-':
    return x - y;
    break;
  }
  return 0;
}

int main() {
  string str;
  cout << "\nEnter expression: ";
  cin >> str;

  int par = str.find_first_of("(");
  if (par != -1) {
    int close = str.find(")");
    int j = par + 1;
    int res = 0;
    int x = str[j] - '0';
    int y = str[close - 1] - '0';
    res = evaluate(x, y, str[j + 1]);
    if (size(res) > 1) {
      int div = size(res) - 1;
      int i = 1;
      while (res > 0) {
        int pwr = pow(10, div);
        char c = (res / pwr) + '0';
        div--;
        str.insert(close + i, 1, c);
        i++;
        res = res % pwr;
      }
      str.erase(par, close - par + 1);
    } else {
      str[close] = res + '0';
      str.erase(par, close - par);
    }
    cout << str;
  }
  int opr = str.find_first_of("*/+-");
  int x = 0, y = 0;
  int j = opr - 1, pow = 1;
  if (j != 0) {
    while (j >= 0) {
      int n = str[j] - '0';
      x += n * pow;
      pow *= 10;
      j--;
    }
  } else {
    x = str[j] - '0';
  }
  int i = str.size() - 1;
  pow = 1;
  while (i > opr) {
    int n = str[i] - '0';
    y += n * pow;
    pow *= 10;
    i--;
  }
  int res = 0;
  res = evaluate(x, y, str[opr]);
  cout << "\nOuput: " << res;
}