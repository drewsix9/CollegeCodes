#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isPrime(int num) {
  if (num <= 1)
    return 0;
  if (num == 2 || num == 3)
    return 1;
  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

string reverse(string str) {
  for (int i = 0; i < str.length() / 2; i++) {
    swap(str[i], str[str.length() - i - 1]);
  }
  return str;
}

int getSum(int num) {
  int res = 0;
  while (num) {
    res += num % 10;
    num /= 10;
  }
  return res;
}

int main() {
  string str, token;
  cout << "Enter inputs: ";
  getline(cin, str);

  stringstream ss(str);

  cout << "\nOutput: ";
  while (ss >> token) {
    int num = stoi(token);
    if (isPrime(getSum(num))) {
      cout << reverse(token) << " ";
    } else {
      cout << token << " ";
    }
  }
}
