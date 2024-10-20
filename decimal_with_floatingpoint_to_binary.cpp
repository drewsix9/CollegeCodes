#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int toBinary(int num) {
  int rem, pwr = 0;
  uint64_t sum = 0;
  while (num != 0) {
    rem = num % 2;
    sum += rem * pow(10, pwr++);
    num = num / 2;
  }
  return sum;
}

int toBinary2(int num) {
  int sum = 0, pwr = 1;
  while (num > 0) {
    int rem = num % 2;
    sum += rem * pwr;
    pwr *= 10;
    num /= 2;
  }
  return sum;
}

string stoBinary(int num) {
  if (num == 0)
    return "0";

  string result = "";
  while (num > 0) {
    result = (num % 2 == 0 ? "0" : "1") + result;
    num /= 2;
  }
  return result;
}

string baseTenWithDeciToBinary(float num) {
  int whole = static_cast<int>(num);
  float part = num - whole;
  string res;
  while (part != 0.0) {
    float temp = part * 2;
    whole = static_cast<int>(temp);
    res += to_string(whole);
    part = temp - whole;
    if (res.length() > 32) {
      break;
    }
  }
  return res;
}

int main() {
  float num;
  cout << "Enter base-10 with floating point: ";
  cin >> num;
  int whole = static_cast<int>(num);
  float part = num - whole;

  uint64_t bin = toBinary2(whole);

  string partInBin = baseTenWithDeciToBinary(part);

  cout << "\nbase-2: " << bin << "." << partInBin;
  return 0;
}