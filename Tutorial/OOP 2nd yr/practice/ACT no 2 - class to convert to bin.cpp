#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class ClassToConvertToBin {
private:
  int *arr;
  int size;

public:
  ClassToConvertToBin(int *arr, int size); // constructor
  void display();
  bool isPrime(int num);
  int convertToBin(int num);
};

int main() {
  int arr[100];
  char str[100];
  cout << "Enter elements of array: ";
  cin.getline(str, 100); // input numbers in a single line
  // tokenizing the input string
  char *token = strtok(str, " ");
  int n = 0;
  while (token != NULL) {
    arr[n] = atoi(token); // convert string to integer
    token = strtok(NULL, " ");
    n++;
  }
  ClassToConvertToBin obj(arr, n);
  obj.display();
  return 0;
}

ClassToConvertToBin::ClassToConvertToBin(int *arr, int size) { // constructor
  cout << "Constructor called" << endl;
  this->arr = new int[size]; // dynamic memory allocation
  this->size = size;
  for (int i = 0; i < size; i++) {
    this->arr[i] = arr[i]; // this->array[i] is the class member while arr[i] is the parameter
  }
}

void ClassToConvertToBin::display() {
  cout << "Output: ";
  for (int i = 0; i < size; i++) {
    if (isPrime(arr[i])) {
      cout << convertToBin(arr[i]) << " ";
    } else {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}

bool ClassToConvertToBin::isPrime(int num) {
  if (num <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int ClassToConvertToBin::convertToBin(int num) {
  int binary = 0, rem, pwr = 1;
  while (num > 0) {
    rem = num % 2;
    num /= 2;
    binary += rem * pwr;
    pwr *= 10;
  }
  return binary;
}