#include <cmath>
#include <iostream>
#include <string>

using namespace std;

float HexToDeci(string input, string hash) {
  int sum = 0, index = input.find("."), ipow = 1;

  if (index == string::npos) { // no decimal point
    for (int i = input.size() - 1; i >= 0; i--) {
      sum += hash.find(input[i]) * ipow;
      ipow *= 16;
    }
    return sum;
  } else { // found decimal point
    float fsum = 0, fpow = 1;
    for (int i = index - 1; i >= 0; i--) {
      fsum += hash.find(input[i]) * fpow;
      fpow *= 16;
    }
    fpow = pow(16, -1);
    for (int i = index + 1; i < input.size(); i++) {
      fsum += hash.find(input[i]) * fpow;
      fpow /= 16;
    }
    return fsum;
  }
}

int main() {
  string hash = "0123456789ABCDEF";
  cout << "Enter Hexadecimal: ";
  string input;
  getline(cin, input);

  cout << "\nOutput: " << HexToDeci(input, hash);
}