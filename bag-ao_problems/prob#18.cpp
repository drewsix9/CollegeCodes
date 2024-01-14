#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MyStackQueueLL {
public:
  class Node {
  public:
    T val;
    Node *next;
    Node(T val) : val(val), next(nullptr) {}
    Node(T val, Node *n) : val(val), next(n) {}
  };
  int _size;
  Node *head, *tail;
  MyStackQueueLL();
  bool isFull();
  bool isEmpty() { return head == nullptr; }
  void push(T n);
  void pop();
  void enqueue(T n);
  void dequeue();
  void printLL();
  Node *getFront() { return head; }
  Node *getTail() { return tail; }
};

bool isPrime(int num);
bool inputValidation(string num);
bool isPalindrome(string num);
int helper(string num, double &res);

int main() {
  MyStackQueueLL<double> LL;
  string num;
  double res;
  int choice, condition;
  while (1) {
    cout << "\n\n-----Linked List Operations-----" << endl;
    cout << "[0]: Exit" << endl;
    cout << "[1]: Push" << endl;
    cout << "[2]: Pop" << endl;
    cout << "[3]: Enqueue" << endl;
    cout << "[4]: Dequeue" << endl;
    cout << "Enter choice : ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (LL.isFull()) {
        cout << "[WARNING] Linked list is full" << endl;
        break;
      }
      do {
        cout << "Enter number to push: ";
        cin >> num;
      } while (!inputValidation(num));
      // TODO
      condition = helper(num, res);
      if (condition == 1) {
        cout << "[INFO] Input number satisfies Condition 1" << endl;
      } else if (condition == 2) {
        cout << "[INFO] Input number satisfies Condition 2" << endl;
      } else if (condition == 3) {
        cout << "[INFO] Input number did not meet any conditions, Popping from stack..." << endl;
        LL.pop();
      }
      if (condition != 3) {
        LL.push(res);
      }
      break;
    case 2:
      LL.pop();
      break;
    case 3:
      if (LL.isFull()) {
        cout << "[WARNING] Linked list is full" << endl;
        break;
      }
      do {
        cout << "Enter number to enqueue: ";
        cin >> num;
      } while (!inputValidation(num));
      // TODO
      condition = helper(num, res);
      if (condition == 1) {
        cout << "[INFO] Input number satisfies Condition 1" << endl;
      } else if (condition == 2) {
        cout << "[INFO] Input number satisfies Condition 2" << endl;
      } else if (condition == 3) {
        cout << "[INFO] Input number did not meet any conditions, Dequeuing from queue..." << endl;
        LL.dequeue();
      }
      if (condition != 3) {
        LL.enqueue(res);
      }
      // TODO
      break;
    case 4:
      LL.dequeue();
      break;
    default:
      cout << "[WARNING] Invalid choice" << endl;
      break;
    }
    LL.printLL();
  }
  cin.ignore();
  cin.get();
}

bool isPrime(int num) {
  if (num <= 1)
    return false;

  for (int i = 2; i * i <= (num); i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

bool inputValidation(string num) {
  bool boolean = num.find_first_of(".") != string::npos;
  if (!boolean) {
    cout << "[WARNING] Invalid input. Try again" << endl;
  }
  return boolean;
}

bool isPalindrome(string num) {
  string first = num.substr(0, num.find_first_of("."));
  string second = num.substr(num.find_first_of(".") + 1);
  reverse(second.begin(), second.end());
  return first == second;
}

int helper(string num, double &res) {
  string first = num.substr(0, num.find_first_of("."));
  string second = num.substr(num.find_first_of(".") + 1);
  string resStr;
  int ifirst = 0, isecond = 0, condition = 0;
  for (char c : first) {
    ifirst += c - '0';
  }
  for (char c : second) {
    isecond += c - '0';
  }
  if (isPalindrome(num)) {
    resStr = to_string(ifirst) + "." + to_string(isecond);
    condition = 1;
  } else if ((isPrime(ifirst) ^ isPrime(isecond))) {
    resStr = num;
    condition = 2;
  } else {
    condition = 3;
  }
  res = (condition != 3 ? stod(resStr) : 0.0);
  return condition;
}

template <typename T>
MyStackQueueLL<T>::MyStackQueueLL() {
  head = nullptr;
  tail = nullptr;
  cout << "Enter Stack/Queue size: ";
  cin >> _size;
}

template <typename T>
bool MyStackQueueLL<T>::isFull() {
  if (!head) {
    return false;
  }
  int n = 0;
  Node *ptr = head;
  while (ptr && n <= _size) {
    n++;
    ptr = ptr->next;
  }
  return n >= _size;
}

template <typename T>
void MyStackQueueLL<T>::push(T n) {
  if (!head) {
    head = new Node(n);
    tail = head;
    return;
  }
  Node *newHead = new Node(n, head);
  head = newHead;
}

template <typename T>
void MyStackQueueLL<T>::pop() {
  if (!head) {
    cout << "[INFO] Linked list is empty" << endl;
    return;
  }
  Node *ptr = head->next;
  delete head;
  head = ptr;
}

template <typename T>
void MyStackQueueLL<T>::enqueue(T n) {
  if (!head) {
    head = new Node(n);
    tail = head;
    return;
  }
  Node *ptr = head;
  while (ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = new Node(n);
  tail = ptr->next;
}

template <typename T>
void MyStackQueueLL<T>::dequeue() {
  if (!head) {
    cout << "[INFO] Linked list is empty" << endl;
    return;
  }
  Node *ptr = head->next;
  delete head;
  head = ptr;
}

template <typename T>
void MyStackQueueLL<T>::printLL() {
  if (!head) {
    cout << "\n[INFO] Linked list is empty" << endl;
    return;
  }
  cout << "\n\nTop of Stack/Front of Queue" << endl;
  cout << "          |" << endl;
  cout << "          v" << endl;
  cout << "\nOutput: ";
  Node *ptr = head;
  while (ptr) {
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
}
