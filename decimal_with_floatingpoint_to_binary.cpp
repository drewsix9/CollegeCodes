// Online C++ compiler to run C++ program online
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int mytobinary(int num) {
  int rem, sum = 0, place = 0, prod = 0;
  while (num != 0) {
    rem = num % 2;
    prod = rem * pow(10, place++);
    sum += prod;
    num = num / 2;
  }
  return sum;
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

  int bin = mytobinary(whole);

  string partInBin = baseTenWithDeciToBinary(part);

  cout << "\nbase-2: " << bin << "." << partInBin;
  return 0;
}