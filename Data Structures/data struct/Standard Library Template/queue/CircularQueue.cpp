#include <iostream>

using namespace std;

class CircularQueue {
public:
  int head, tail, size, capacity, *arr;
  CircularQueue();  // constructor
  ~CircularQueue(); // destructor
  bool isFull() const;
  bool isEmpty() const;
  void enqueue(int n);
  void dequeue();
  void printQueue();
};

CircularQueue::CircularQueue() {
  cout << "Enter size of queue: ";
  cin >> capacity;
  arr = new int[capacity];
  head = tail = 0;
  size = 0;
}

bool CircularQueue::isFull() const {
  return size == capacity;
}

bool CircularQueue::isEmpty() const {
  return size == 0;
}

void CircularQueue::enqueue(int n) {
  if (isFull()) {
    cout << "[WARNING] Queue is full" << endl;
    return;
  }
  arr[tail] = n;
  tail = (tail + 1) % capacity;
  size++;
  cout << "[INFO] Successfully enqueued!" << endl;
}

void CircularQueue::dequeue() {
  if (isEmpty()) {
    cout << "[WARNING] Queue is empty" << endl;
    return;
  }
  head = (head + 1) % capacity;
  size--;
  cout << "[INFO] Successfully dequeued!" << endl;
}

void CircularQueue::printQueue() {
  if (isEmpty()) {
    cout << "[WARNING] Queue is empty" << endl;
    return;
  }
  cout << "Queue: ";
  for (int i = head; i < head + size; i++) {
    cout << arr[i % capacity] << " ";
  }
  cout << endl;
}

CircularQueue::~CircularQueue() {
  delete[] arr;
  cout << "[INFO] Successfully destroyed!" << endl;
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
