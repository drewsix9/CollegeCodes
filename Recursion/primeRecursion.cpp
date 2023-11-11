#include <iostream>

using namespace std;

int isPrimeRec(int num, int div) { // actual recursive function
  if (div == num / 2 + 1)
    return 1;

  if (num % div == 0) {
    return 0;
  }

  return isPrimeRec(num, div + 1);
}

int isPrimeBase(int num, int div) { // Base-case function
  if (num == 2 || num == 3)
    return 1;
  else if (num == 1)
    return 0;

  return isPrimeRec(num, div);
}

int main() {
  while (1) {

    int num;
    cout << "\nEnter number: ";
    cin >> num;
    cout << "Output: " << (isPrimeBase(num, 2) ? "is Prime" : "is Composite");
  }
  return 0;
}