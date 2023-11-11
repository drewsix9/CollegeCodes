#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Value {
  int freq = 0;
  vector<int> pos{};
  Value() : freq(0), pos({}) {}
};

int main() {
  int n;
  cout << "Enter # of sets: ";
  cin >> n;

  vector<vector<int>> nums;

  for (int i = 0; i < n; i++) {
    cout << "\nEnter set " << i + 1 << ": ";
    int temp;
    while (cin >> temp && temp != 0) {
      nums[i].push_back(temp);
    }
  }

  unordered_map<int, Value> map;
  for (int i = 0; i < nums.size(); i++) {
    for (int j : nums[i]) {
      map[j].freq++;
      map[j].pos.push_back(i + 1);
    }
  }

  cout << "\nOutput:\n";
  for (auto i : map) {
    if (i.second.freq > 1) {
      cout << i.first << " occurred " << i.second.freq << " times @ Sets ";
      for (int n : i.second.pos) {
        cout << n << " ";
      }
      cout << "\n";
    }
  }
}