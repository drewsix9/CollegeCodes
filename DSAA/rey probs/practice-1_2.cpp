#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int octalToDeci(int num) {
  int sum = 0, prod = 0, pow = 1;
  while (num > 0) {
    prod = (num % 10) * pow;
    pow *= 8;
    sum += prod;
    num /= 10;
  }
  return sum;
}

int binToDeci(int num) {
  int sum = 0, prod = 0, pow = 1;
  while (num > 0) {
    prod = (num % 10) * pow;
    pow *= 2;
    sum += prod;
    num /= 10;
  }
  return sum;
}

bool isBinary(int num) {
  while (num > 0) {
    if (num % 10 > 1) {
      return 0;
    }
    num /= 10;
  }
  return 1;
}

class Stack {
public:
  vector<int> v;
  Stack() : v({}) {}

  bool isEmpty() { return v.empty(); }
  void push(int d) { v.insert(v.begin(), d); }
  void pop() { v.erase(v.begin()); }

  void printBinStk() {
    cout << "\nBinary Stack: ";
    for (int n : v) {
      cout << binToDeci(n) << " ";
    }
  }

  void printOctStk() {
    cout << "\nOctal Stack: ";
    for (int n : v) {
      cout << octalToDeci(n) << " ";
    }
  }
};

bool hasDuplicate(Stack &bStk, Stack &oStk) {
  set<int> set;
  for (int n : bStk.v) {
    if (set.find(binToDeci(n)) != set.end()) {
      return 1;
    }
    set.insert(binToDeci(n));
  }
  for (int n : oStk.v) {
    if (set.find(octalToDeci(n)) != set.end()) {
      return 1;
    }
    set.insert(octalToDeci(n));
  }
  return 0;
}

void removeDuplicate(Stack &bStk, Stack &oStk) {
  map<int, int> map; //[deci, count]
  for (int n : bStk.v) {
    map[binToDeci(n)]++;
    if (map[binToDeci(n)] > 1) {
      map[binToDeci(n)] = 0;
    }
  }
  for (int n : oStk.v) {
    map[octalToDeci(n)]++;
    if (map[octalToDeci(n)] > 1) {
      map[octalToDeci(n)] = 0;
    }
  }

  for (auto it = bStk.v.begin(); it != bStk.v.end(); it++) {
    if (map[binToDeci(*it)] <= 0) {
      bStk.v.erase(it);
      it--;
    }
  }
  for (auto it = oStk.v.begin(); it != oStk.v.end(); it++) {
    if (map[octalToDeci(*it)] <= 0) {
      oStk.v.erase(it);
      it--;
    }
  }
}

int main() {
  Stack binStk;
  Stack octStk;
  int num, choice;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Push to Stack\nEnter choice:  ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num: ";
      cin >> num;
      if (isBinary(num)) {
        binStk.push(num);
      } else {
        octStk.push(num);
      }
      break;
    }
    while (hasDuplicate(binStk, octStk)) {
      cout << "\nFound duplicate decimal values in both stacks, removing from stack";
      removeDuplicate(binStk, octStk);
    }
    binStk.printBinStk();
    octStk.printOctStk();
  }
}
