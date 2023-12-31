#include <iostream>

using namespace std;

class CircularQueue {
public:
  int head, tail, size, capacity, *arr;
  CircularQueue();
  bool isFull();
  bool isEmpty();
  void enqueue(int n);
  void dequeue();
  void printQueue();
};

CircularQueue::CircularQueue() {
  cout << "Enter size of queue: ";
  cin >> this->capacity;
  this->arr = new int[capacity];
  this->head = this->tail = 0;
  this->size = 0;
}

bool CircularQueue::isFull() {
  return this->size == this->capacity;
}

bool CircularQueue::isEmpty() {
  return this->size == 0;
}

void CircularQueue::enqueue(int n) {
  if (isFull()) {
    cout << "[WARNING] Queue is full" << endl;
    return;
  }
  this->arr[this->tail] = n;
  this->tail = (this->tail + 1) % this->capacity;
  this->size++;
}

void CircularQueue::dequeue() {
  if (isEmpty()) {
    cout << "[WARNING] Queue is empty" << endl;
    return;
  }
  this->head = (this->head + 1) % this->capacity;
  this->size--;
}

void CircularQueue::printQueue() {
  if (isEmpty()) {
    cout << "[WARNING] Queue is empty" << endl;
    return;
  }
  cout << "Queue: ";
  for (int i = this->head; i < this->head + this->size; i++) {
    cout << this->arr[i % this->capacity] << " ";
  }
  cout << endl;
}

int main() {
  CircularQueue queue;
  int choice, n;
  while (1) {
    cout << "0. Exit" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "Enter number to enqueue: ";
      cin >> n;
      queue.enqueue(n);
      break;
    case 2:
      queue.dequeue();
      break;
    default:
      cout << "Invalid choice" << endl;
    }
    queue.printQueue();
  }
}