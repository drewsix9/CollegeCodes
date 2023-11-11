#include <iostream>
#include <map>
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
  int temp;
  vector<int> nums;
  map<int, int> map;

  cout << "Enter input: ";
  while (cin >> temp && temp != 0) {
    nums.push_back(temp);
    if (isPrime(temp)) {
      map[temp]++;
    }
  }

  vector<int> keysToErase;
  for (auto &[key, freq] : map) {
    if (freq == 1) {
      keysToErase.push_back(key);
    }
  }

  for (int n : keysToErase) {
    map.erase(n);
  }

  cout << "\nOutput: ";
  for (int n : nums) {
    if (map[n] == 0) {
      cout << n << " ";
    }
  }
  return 0;
}