// Problem: Frequency Counting
// Given a sequence of numbers, write a program to count the frequency of each number and generate a new sequence that represents the count of each number in the original sequence.

#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

string say(int num) {
  vector<int> v;
  string res;
  map<int, int> freq;
  string str = to_string(num);
  for (char c : str) {
    int current = c - '0';
    if (freq[current] == 0)
      v.emplace_back(current);
    freq[current]++;
  }
  for (int n : v)
    res += to_string(freq[n]) + to_string(n);
  return res;
}

int main() {
  queue<int> q;
  int max, input;
  cout << "\nEnter max size: ";
  cin >> max;
  cout << "\nEnter input: ";
  cin >> input;
  cout << "\nOutput:\n";

  while (max > 0) {
    int current = q.front();
    string n = say(current);
    cout << n << endl;
    q.pop();
    q.push(stoi(n));
    max--;
  }
}