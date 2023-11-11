#include <iostream>

using namespace std;

int isPrime(int num) {
  if (num <= 1)
    return 0;

  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int solution(int num) {
  if (isPrime(num)) {
    do {
      num++;
      for (int i = 2; i < num; i++) {
        if (num % i == 0) {
          break;
        }
      }
    } while (!isPrime(num));
    return num;
  } else {
    do {
      num--;
      for (int i = 2; i < num; i++) {
        if (num % i == 0) {
          return num;
        }
      }
    } while (isPrime(num));
  }
}

int main() {
  int num;
  cout << "Enter input: ";
  cin >> num;
  cout << "\nOutput: " << solution(num);
  return 0;
}