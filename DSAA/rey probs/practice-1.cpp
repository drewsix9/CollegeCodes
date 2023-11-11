#include <algorithm>
#include <iostream>
#include <map>
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
  vector<int> vec;
  Stack() : vec({}) {}

  bool isEmpty() { return vec.empty(); }
  int &top() {
    return vec.front();
  }
  vector<int>::iterator begin() { return vec.begin(); }
  vector<int>::iterator end() { return vec.end(); }
  vector<int> &returnVec() { return vec; }

  void push(int num) {
    vec.insert(vec.begin(), num);
    cout << "\n[INFO] Successfully pushed " << num;
  }

  void pop() { vec.erase(vec.begin()); }

  void printBinStk() {
    cout << "\n             top";
    cout << "\n              |";
    cout << "\n              V";
    cout << "\nBinary Stack: ";
    for (int n : vec) {
      cout << binToDeci(n) << " ";
    }
  }

  void printOctStk() {
    cout << "\n             top";
    cout << "\n              |";
    cout << "\n              V";
    cout << "\nOctal Stack:  ";
    for (int n : vec) {
      cout << octalToDeci(n) << " ";
    }
  }

  Stack rev() {
    reverse(vec.begin(), vec.end());
    return *this;
  }

  Stack operator()(Stack s) {
    Stack res;
    while (!s.isEmpty()) {
      res.push(s.top());
      s.pop();
    }
    return res.rev();
  }
};

bool hasDuplicate(Stack &bStk, Stack &oStk) {
  map<int, int> map; // [deci, 1/0]
  for (auto it = bStk.begin(); it != bStk.end(); it++) {
    if (map[binToDeci(*it)] > 0) {
      return 1;
    } else {
      map[binToDeci(*it)]++;
    }
  }
  for (auto it = oStk.begin(); it != oStk.end(); it++) {
    if (map[octalToDeci(*it)] > 0) {
      return 1;
    } else {
      map[octalToDeci(*it)]++;
    }
  }
  return 0;
}

void removeDuplicate(Stack &bStk, Stack &oStk) {
  vector<int> vB;
  vector<int> vO;
  map<int, int> map; //[deci, count]

  while (!bStk.isEmpty()) {
    vB.push_back(bStk.top());
    bStk.pop();
  }

  while (!oStk.isEmpty()) {
    vO.push_back(oStk.top());
    oStk.pop();
  }

  for (int n : vB) {
    map[binToDeci(n)]++;
    if (map[binToDeci(n)] > 1) {
      map[binToDeci(n)] = 0;
    }
  }
  for (int n : vO) {
    map[octalToDeci(n)]++;
    if (map[octalToDeci(n)] > 1) {
      map[octalToDeci(n)] = 0;
    }
  }

  Stack resB;
  for (int n : vB) {
    if (map[binToDeci(n)] > 0) {
      resB.push(n);
    }
  }
  bStk = resB.rev();

  Stack resO;
  for (int n : vO) {
    if (map[octalToDeci(n)] > 0) {
      resO.push(n);
    }
  }
  oStk = resO.rev();
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
      cout << "\n";
      removeDuplicate(binStk, octStk);
    }
    binStk.printBinStk();
    octStk.printOctStk();
  }
}
