// Problem: Frequency Counting
// Given a sequence of numbers, write a program to count the frequency of each number and generate a new sequence that represents the count of each number in the original sequence.

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

vector<int> process(vector<int> v) {
  map<int, int> map;
  for (int n : v) {
    map[n]++;
  }
  vector<int> res;
  for (int n : v) {
    res.push_back(map[n]);
  }
  return res;
}

void printV(vector<int> v) {
  cout << "                        ";
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
}

int main() {
  int size, num;
  vector<int> v;
  cout << "\nEnter how many interations: ";
  cin >> size;
  cout << "\nEnter initial sequence: ";
  while (cin >> num && num != 0)
    v.push_back(num);

  queue<vector<int>> q;
  q.push(v);
  while (size > 0) {
    vector<int> vFront = process(q.front());
    printV(vFront);
    q.push(vFront);
    q.pop();
    size--;
  }
}