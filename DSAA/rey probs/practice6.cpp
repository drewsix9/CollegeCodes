#include <iostream>
#include <set>
using namespace std;

bool isPrime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

class LinkedList {
  class Node {
    int processA(int *nums) {
      int res = 0;
      for (int i = 0; i < 3; i++) {
        if (isPrime(nums[i])) {
          res = max(res, nums[i]);
        }
      }
      if (res == 0) {
        int largComp = 0;
        for (int i = 0; i < 3; i++) {
          if (!isPrime(nums[i])) {
            largComp = max(largComp, nums[i]);
          }
        }
        while (!isPrime(largComp)) {
          ++largComp;
        }
        res = largComp;
      }
      return res;
    }

    int processB(int *nums) {
      int res = 999;
      for (int i = 0; i < 3; i++) {
        if (!isPrime(i)) {
          res = min(res, nums[i]);
        }
      }
      if (res == 999) {
        int largPrime = 0, smallPrime = 0;
        for (int i = 0; i < 3; i++) {
          if (isPrime(i)) {
            largPrime = max(largPrime, nums[i]);
            smallPrime = min(largPrime, nums[i]);
          }
        }
        res = largPrime * smallPrime;
      }
      return res;
    }

  public:
    int dataA;
    int dataB;
    Node *next;
    Node() : next(nullptr) {
      int nums[3];
      cout << "\nEnter 3 nums:\n";
      for (int i = 0; i < 3; i++) {
        cout << "Enter num " << i + 1 << ": ";
        cin >> nums[i];
      }
      this->dataA = processA(nums);
      this->dataB = processB(nums);
    }
  };
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void insert() {
    if (!head) {
      head = new Node();
      return;
    }
    Node *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new Node();
  }

  void check() {
    set<pair<int, int>> unique;
    Node *prev = nullptr;
    Node *ptr = head;
    while (ptr) {
      pair<int, int> temp = {ptr->dataA, ptr->dataB};
      if (unique.find(temp) == unique.end()) { // if it is not found
        unique.insert(temp);
      } else {
        break;
      }
      prev = ptr;
      ptr = ptr->next;
    }
    if (ptr) {
      cout << "\n[INFO] Deleted a duplicate Node!";
      Node *delNode = ptr;
      prev->next = nullptr;
      delete delNode;
    }
  }

  void print() {
    if (!head) {
      return;
    }
    cout << "\nOutput:\n";
    Node *ptr = head;
    while (ptr) {
      cout << "\nFirst: " << ptr->dataA << " Second: " << ptr->dataB;
      ptr = ptr->next;
    }
  }
};

int main() {
  LinkedList li;
  int choice;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert Node\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      li.insert();
      break;
    case 2:
      li.print();
      break;
    }
    li.check();
    li.print();
  }
}
