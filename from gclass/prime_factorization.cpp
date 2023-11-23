#include <iostream>
#include <vector>

using namespace std;

void primeFactors(int n) {
  cout << "Prime factors of " << n << ": ";
  int i = 2;
  while (n != 1) {
    if (n % i == 0) {
      n /= i;
      cout << i << " ";
    } else {
      i++;
    }
  }
}

int isPrime(int num) {
  if (num == 2 || num == 3)
    return 1;
  else if (num == 1)
    return 0;

  for (int i = 2; i < num / 2 + 1; i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

vector<int> primeFact(int num, vector<int> &primes) {
  vector<int> res;
  int i = 0;

  while (num > 1 && i < primes.size()) {
    if (num % primes[i] == 0) {
      res.push_back(primes[i]);
      num /= primes[i];
    } else {
      i++;
    }
  }
  return res;
}

int main() {
  int num;
  vector<int> primes;

  cout << "Enter input: ";
  cin >> num;

  for (int i = 1; i < 100; i++) {
    if (isPrime(i))
      primes.push_back(i);
  }

  cout << "\nOutput: ";
  for (int n : primeFact(num, primes)) {
    cout << n << " ";
  }
}