#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
  if (num == 2 || num == 3)
    return 1;
  if (num <= 1)
    return 0;

  for (int i = 2; i < num / 2 + 1; i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

int main() {

  vector<int> v;
  int size = 0, num;
  cout << "\nEnter size: ";
  cin >> size;

  cout << "\nEnter inputs: ";
  while (v.size() != size) {
    cin >> num;
    v.push_back(num);
  }

  cout << "\nOutput: ";
  for (int n : v) {
    cout << n << " ";
  }

  vector<int> ins;
  vector<int> pos;

  cout << "\nEnter nums to insert (0 to stop): ";
  while (cin >> num && num != 0) {
    ins.push_back(num);
  }
  int pos_size = 0;
  cout << "\nEnter pos to insert: ";
  while (ins.size() != pos_size) {
    cin >> num;
    pos.push_back(num);
    pos_size++;
  }

  // main logic
  for (int i = 0; i < pos.size(); i++) {
    if (isPrime(v[pos[i]])) {
      auto it = v.begin() + pos[i];
      v.insert(it, ins[i]); // Insert at position
    }
  }

  cout << "\nOutput: ";
  for (int n : v) {
    cout << n << " ";
  }
}