#include <iostream>
#include <vector>

using namespace std;

int isPrime(int num) {
  if (num == 2 || num == 3)
    return 1;
  else if (num <= 1)
    return 0;

  for (int i = 2; i < num / 2 + 1; i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

void primeFact(int num, const vector<int> primes) {
  int i = 0;
  while (num > 1 && i < primes.size()) {
    if (num % primes[i] == 0) {
      cout << primes[i] << " ";
      num /= primes[i];
    } else {
      i++;
    }
  }
}

int main() {
  int temp, maxComp = 0, minComp = 100;
  cout << "Enter inputs (0 to stop): ";
  while (cin >> temp && temp != 0) {
    if (!isPrime(temp)) {
      maxComp = max(maxComp, temp);
      minComp = min(minComp, temp);
    }
  }

  vector<int> primes;
  for (int i = 2; i <= 100; i++) {
    if (isPrime(i))
      primes.push_back(i);
  }

  cout << "\nMax: " << maxComp << " - ";
  primeFact(maxComp, primes);
  cout << "\nMin: " << minComp << " - ";
  primeFact(minComp, primes);
}