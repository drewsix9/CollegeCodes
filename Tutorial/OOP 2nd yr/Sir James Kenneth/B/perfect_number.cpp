
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isPerfectNumber(int num) {
  int divisorSum = 0;
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0) {
      divisorSum += i;
    }
  }
  return divisorSum == num;
}

class Encryption {
  // protected so that derived classes can access them
protected:
  // static keyword is used to make the variable common to all objects of the class
  static const string encryptStringHash;
  static const string encryptIntHash;
  static const int shiftEncrypt = 5;
  static const int shiftDecrypt = 6;
};

// Defining the static variables
const string Encryption::encryptStringHash = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
const string Encryption::encryptIntHash = "0123456789";

class StringEncryptDecrypt : public Encryption {
public:
  static string stringEncrypt(string str) {
    string encryptedStr = "";
    for (char c : str) {
      int index = encryptStringHash.find(c);
      encryptedStr += encryptStringHash[(index + shiftEncrypt) % 52];
    }
    return encryptedStr;
  }
  static string stringDecrypt(string str) {
    string decryptedStr = "";
    for (char c : str) {
      int index = encryptStringHash.find(c);
      decryptedStr += encryptStringHash[(index - shiftDecrypt + 52) % 52];
    }
    return decryptedStr;
  }
};

class IntEncryptDecrypt : public Encryption {
public:
  static string intEncrypt(int num) {
    string str = to_string(num);
    string decryptedStr = "";
    for (char c : str) {
      int index = encryptIntHash.find(c);
      decryptedStr += encryptIntHash[(index + shiftEncrypt) % 10];
    }
    return decryptedStr;
  }
  static string intDecrypt(int num) {
    string str = to_string(num);
    string decryptedStr = "";
    for (char c : str) {
      int index = encryptIntHash.find(c);
      decryptedStr += encryptIntHash[(index - shiftDecrypt + 10) % 10];
    }
    return decryptedStr;
  }
};

int main() {
  string input, str;
  cout << "Enter a input: ";
  getline(cin, input);
  cout << "\nOutput: ";
  stringstream ss(input); // Used to split words
  while (ss >> str) {     // Splitting words and checking if it is a string or an integer
    if (isalpha(str[0])) {
      if (isPerfectNumber(str.length())) {
        cout << StringEncryptDecrypt::stringEncrypt(str) << " ";
      } else {
        cout << StringEncryptDecrypt::stringDecrypt(str) << " ";
      }
    } else {
      if (isPerfectNumber(stoi(str))) {
        cout << IntEncryptDecrypt::intEncrypt(stoi(str)) << " ";
      } else {
        cout << IntEncryptDecrypt::intDecrypt(stoi(str)) << " ";
      }
    }
  }
}