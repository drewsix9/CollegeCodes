#include <iostream>
#include <string>

using namespace std;

// Function to reverse a string
string reverseStr(string &str) {
  int size = str.length();
  // Swap characters from start and end
  for (int i = 0; i < size / 2; i++) {
    int temp = str[i];
    str[i] = str[size - i - 1];
    str[size - i - 1] = temp;
  }
  return str;
}

// Function to remove pair of characters from a string
string removePairChars(string &str) {
  int size = str.length();
  // Iterate through the string
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      // If pair found, remove both characters
      if (str[i] == str[j]) {
        str.erase(j, 1);
        str.erase(i, 1);
        size -= 2;
        i = -1;
        break;
      }
    }
  }
  return str;
}

// Function to sort a string
string sortStr(string &str) {
  int size = str.length();
  // Bubble sort algorithm
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      // Swap if current character is greater than next
      if (str[i] > str[j]) {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  return str;
}

// Class to represent a number
class Number {
public:
  int num;
  Number(int x) : num(x) {} // Constructor to initialize the number
};

// Class to check if a number is happy or not
class HappyNumber : public Number {
public:
  HappyNumber(int num) : Number(num) {} // Constructor to initialize the number
  bool isHappy() {
    int sum = 0;
    // Calculate the sum of squares of digits
    while (num > 0) {
      int digit = num % 10;
      sum += digit * digit;
      num /= 10;
    }
    // If sum is 1, then number is happy
    if (sum == 1) {
      return true;
    } else if (sum == 4) { // If sum is 4, then number is not happy
      return false;
    } else {
      num = sum;
      return isHappy(); // Recursively check if new number is happy
    }
  }
};

int main() {
  string input;
  cout << "Enter input: ";
  getline(cin, input);
  HappyNumber hn = HappyNumber(input.length());
  // Check if length of input is a happy number
  if (hn.isHappy()) {
    string sorted = sortStr(input);
    cout << "input length is HAPPY number" << endl;
    // If happy, sort the string and remove pair of characters
    cout << "Output:" << removePairChars(sorted) << endl;
  } else {
    cout << "input length is UNHAPPY number" << endl;
    // If not happy, reverse the string
    cout << "Output:" << reverseStr(input) << endl;
  }
}