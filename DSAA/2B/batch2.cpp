#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

string freq(int num) {
  // stores the order of numbers
  vector<int> v;
  string res;
  // stores frequency of each digit, [digit,count]
  map<int, int> freq;
  string str = to_string(num);
  for (char c : str) {
    // if c does not exist in map
    if (freq.find(c - '0') == freq.end()) {
      v.push_back(c - '0');
    }
    // increment frequency of current digit (creates a new [digit,count] pair if digit does not exist in the map)
    freq[c - '0']++;
  }
  // building the string to be returned
  for (int n : v) {
    // freq[n] is the frequency count of n
    res += to_string(freq[n]) + to_string(n);
  }
  return res;
}

int main() {
  queue<int> q;
  int MAX, input;
  cout << "\nEnter max size: ";
  cin >> MAX;
  cout << "\nEnter input: ";
  cin >> input;
  cout << "\nOutput:\n";
  q.push(input);
  // while queue is not empty and MAX is greater than zero
  while (!q.empty() && MAX > 0) {
    int curr = q.front();
    // processes and prints the current/front value
    cout << freq(curr) << endl;
    // dequeue the front
    q.pop();
    // enqueue the processed value
    q.push(stoi(freq(curr)));
    MAX--;
  }
}