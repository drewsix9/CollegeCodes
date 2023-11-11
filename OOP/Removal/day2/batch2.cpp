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

int main() {
  vector<int> nums;
  cout << "Enter input: ";
  int temp, val;
  while (cin >> temp && temp != 0) {
    nums.push_back(temp);
  }

  cout << "Enter insert value: ";
  cin >> val;

  cout << "\nOutput: ";
  for (int n : nums) {
    if (isPrime(n)) {
      cout << val << " ";
    }
    cout << n << " ";
  }
  return 0;
}