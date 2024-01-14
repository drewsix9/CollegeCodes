#include <ctime>
#include <iostream>
#include <math.h>
#include <thread> // Include this for the sleep_for function

using namespace std;

bool isPrimeSqrt(int num) {
  if (num <= 1)
    return false;

  if (num == 2)
    return true;

  for (int i = 2; i < sqrt(num) + 1; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

bool isPrime(int num) {
  if (num <= 1)
    return false;

  for (int i = 2; i < (num); i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}
bool isPrimeTimes(int num) {
  if (num <= 1)
    return false;

  for (int i = 2; i * i <= (num); i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  auto timeStart = clock();
  for (int i = 0; i < 100; i++) {
    if (isPrimeTimes(i)) {
      cout << i << endl;
    }
  }
  auto timeEnd = clock();
  cout << "Time taken: " << (timeEnd - timeStart) / (double)CLOCKS_PER_SEC << " seconds" << endl;
  cin.get();
}