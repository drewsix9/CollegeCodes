#include <iostream>
#include <list>
#include <string>

using namespace std;

class HashTable {
  static const int size = 10;
  list<pair<int, string>> list[size]; // [num, name]

public:
  bool isEmpty() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += list[i].size();
    }
    if (!sum) {
      return 1;
    }
    return 0;
  }

  int hashFunction(int key) { return key % size; }

  void insertItem(int key, string value) {
    bool found = 0;
    int hashKey = hashFunction(key);
    for (auto &[first, second] : list[hashKey]) {
      if (first == key) {
        found = 1;
        second = value;
        cout << "\nItem already exist, inserting new value!";
        break;
      }
    }
    if (!found) {
      list[hashKey].emplace_back(key, value);
      cout << "\nItem inserted!";
    }
  }

  void removeItem(int key) {
    bool found = 0;
    int hashKey = hashFunction(key);
    auto &cell = list[hashKey];
    auto itr = begin(cell);
    for (; itr != end(cell); itr++) {
      if (itr->first == key) {
        found = 1;
        itr = cell.erase(itr);
        cout << "\nItem removed!";
        break;
      }
    }
    if (!found) {
      cout << "\nKey does not exist";
    }
  }

  string operator[](int key) {
    return list[hashFunction(key)].front().second;
  }

  void print() {
    for (int i = 0; i < size; i++) {
      for (auto &[key, value] : list[i]) {
        cout << "\nKey: " << key << " Value: " << value;
      }
    }
  }
};

int main() {
  int choice, num;
  string str;
  HashTable HS;
  while (1) {
    cout << "\n\n0 - Exit\n1 - Insert\n2 - Remove\n3 - Search\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num(key): ";
      cin >> num;
      cout << "\nEnter name(value): ";
      cin >> str;
      HS.insertItem(num, str);
      break;
    case 2:
      cout << "\nEnter num(key) to delete: ";
      cin >> num;
      HS.removeItem(num);
      break;
    case 3:
      cout << "\nEnter num(key) to search: ";
      cin >> num;
      cout << "\nResult: " << HS[num];
      break;
    }
    HS.print();
  }
}