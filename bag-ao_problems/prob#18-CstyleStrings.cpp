
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdlib.h>

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
char *intToStr(int num);
bool isPrime(int num);
bool inputValidation(char *num);
bool isPalindrome(char *num);
int helper(char *num, double &res);

int main() {
  MyStackQueueLL<double> LL;
  char num[100];
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
        cin.ignore();
        fgets(num, 100, stdin);
        num[strlen(num) - 1] = '\0';
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

char *intToStr(int num) {
  int n = 0, temp = num;
  while (temp) {
    n++;
    temp /= 10;
  }
  char *res = new char[n + 1];
  sprintf(res, "%d", num);
  return res;
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

bool inputValidation(char *num) {
  bool boolean = strchr(num, '.') != nullptr;
  if (!boolean) {
    cout << "[WARNING] Invalid input. Try again" << endl;
  }
  return boolean;
}

bool isPalindrome(char *num) {
  char *test = strcpy(new char[strlen(num) + 1], num);
  char *first = strtok(test, ".");
  char *second = strtok(nullptr, ".");
  strrev(second);

  return strcmp(first, second) == 0 ? true : false;
}

int helper(char *num, double &res) {
  char *test = strcpy(new char[strlen(num) + 1], num);
  char *first = strtok(test, ".");
  char *second = strtok(nullptr, ".");
  char *resStr = new char[strlen(first) + strlen(second) + 2];
  int ifirst = 0, isecond = 0, condition = 0;
  for (size_t i = 0; i < strlen(first); i++) {
    ifirst += first[i] - '0';
  }
  for (size_t i = 0; i < strlen(second); i++) {
    isecond += second[i] - '0';
  }
  if (isPalindrome(num)) {
    char *ifirstStr = intToStr(ifirst);
    char *isecondStr = intToStr(isecond);
    resStr = strcat(strcat(strcpy(resStr, ifirstStr), "."), isecondStr);
    condition = 1;
  } else if ((isPrime(ifirst) ^ isPrime(isecond))) {
    resStr = num;
    condition = 2;
  } else {
    condition = 3;
  }
  res = (condition != 3 ? atof(resStr) : 0.0);
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
