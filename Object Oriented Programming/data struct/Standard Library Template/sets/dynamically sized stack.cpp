#include <iostream>

using namespace std;

bool isBinary(int n) {
  while (n > 0) {
    if (n % 10 > 1) {
      return false;
    }
    n /= 10;
  }
  return true;
}

int BintoDeci(int n) {
  int sum = 0, pow = 1, prod = 0;
  while (n > 0) {
    prod = n % 10 * pow;
    pow *= 2;
    sum += prod;
    n /= 10;
  }
  return sum;
}

class Stack {
private:
  int *arr;
  int capacity;
  int size;

public:
  Stack() : size(-1) {
    cout << "Enter size of stack: ";
    cin >> this->capacity;
    arr = new int[capacity];
  };
  void insert(int d);
  void pop();
  void displayBinary();
  void displayDecimal();
  void increaseCapacity();
  int getCapacity() { return this->capacity; }
  int getSize() { return this->size; }
};

int main() {
  Stack stk;
  int n, c;
  while (1) {
    cout << "\n\n---Operations---";
    cout << "\n[0] - Exit";
    cout << "\n[1] - Insert";
    cout << "\n[2] - Pop";
    cout << "\n[3] - Display Binary";
    cout << "\n[4] - Display Decimal of Binary";
    cout << "\n[5] - Display Stack Capacity";
    cout << "\n[6] - Display Stack Size";
    cout << "\nChoose operation : ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num to insert: ";
      cin >> n;
      while (!isBinary(n)) {
        cout << "Error: Input is not a binary!";
        cout << "\nEnter num to insert: ";
        cin >> n;
      }
      stk.insert(n);
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      stk.displayBinary();
      break;
    case 4:
      stk.displayDecimal();
      break;
    case 5:
      cout << "\nCapacity: " << stk.getCapacity();
      break;
    case 6:
      cout << "\nSize: " << stk.getSize();
      break;
    default:
      break;
    }
  }
}

void Stack::insert(int d) {
  size++;
  if (size >= capacity) {
    increaseCapacity();
  }
  arr[size] = d;
}

void Stack::pop() {
  if (size == 0) {
    cout << "\n[WARNING] Stack is empty";
    return;
  }
  size--;
}

void Stack::displayBinary() {
  cout << "\nStack (Binary): ";
  for (int i = 0; i <= this->size; i++) {
    cout << arr[i] << " ";
  }
}

void Stack::displayDecimal() {
  cout << "\nStack (Decimal): ";
  for (int i = 0; i <= this->size; i++) {
    cout << BintoDeci(arr[i]) << " ";
  }
}

void Stack::increaseCapacity() {
  capacity *= 2;
  int *newArr = new int[capacity];
  for (int i = 0; i < capacity / 2; i++) {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
  cout << "\nCapacity increased";
}
