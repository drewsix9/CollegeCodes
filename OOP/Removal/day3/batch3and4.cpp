#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int isPrime(int num) {
  if (num <= 1)
    return 0;
  else if (num == 2 || num == 3)
    return 1;

  for (int i = 2; i < num / 2 + 1; i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

int digCount(int num) {
  if (num == 0)
    return 0;
  return 1 + digCount(num / 10);
}

int breakerFunction(int num, int dig) {
  int sum = 0, div = pow(10, dig), rem;
  while (num > 0) {
    rem = num % div;
    if (digCount(rem) == dig) {
      sum += rem;
    }
    num /= div;
  }
  return sum;
}

int main() {
  int temp, dig;
  vector<int> nums;
  cout << "Enter input: ";
  while (cin >> temp && temp != 0) {
    nums.push_back(temp);
  }

  cout << "Enter how many digits to group: ";
  cin >> dig;

  cout << "\nOutput: ";
  for (int n : nums) {
    if (isPrime(breakerFunction(n, dig))) {
      cout << n << " ";
    }
  }
  return 0;
}