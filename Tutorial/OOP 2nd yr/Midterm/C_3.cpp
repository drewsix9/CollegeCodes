#include <cstring>
#include <iostream>

using namespace std;

int hexToDeci(char *str, int size) {
  char hex[] = "0123456789ABCDEF";
  int result = 0, pow = 1;
  for (int i = size - 1; i >= 0; i--) {
    char *found = strchr(hex, str[i]);
    if (!found) {
      cout << "Invalid hex digit: " << str[i] << endl;
      return -1;
    }
    int n = found - hex;
    result += n * pow;
    pow *= 16;
  }
  return result;
}

int main() {
  char str[100];
  cout << "Enter number: ";
  cin >> str;
  cout << "Decimal equivalent: " << hexToDeci(str, strlen(str)) << endl;
}