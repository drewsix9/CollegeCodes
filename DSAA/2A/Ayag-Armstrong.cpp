#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

struct Node {
  int value;
  struct Node *next;
} *start;

class SLL {
private:
  int size = 0;

public:
  void insBeg();
  Node *create(int);
  void insLast();
  void insPos();
  void delPos();
  void display();
  void update();
  void sortAsc();
  void sortDesc();
  int isArm(int);

  SLL() {
    start = NULL;
  }
};

int main() {
  SLL single;
  int choice = 999;
  while (choice != 0) {
    cout << "1-Insert at the Beginning\n2-Insert at the End\n3-Insert at Position #\n4-Delete at Position\n5-Diplay\n6-Sort Descending\n7-Sort Ascending\n8-Display\nOption #: ";
    cin >> choice;
    cout << "=========================================================\n";
    switch (choice) {
    case 1:
      single.insBeg();
      break;
    case 2:
      single.insLast();
      break;
    case 3:
      single.insPos();
      break;
    case 4:
      single.delPos();
      break;
    case 5:
      single.display();
      break;
    case 6:
      single.sortDesc();
      single.display();
      break;
    case 7:
      single.sortAsc();
      single.display();
      break;
    case 8:
      single.update();
      break;
    default:
      cout << "Undefinde Option." << endl;
      break;
    }
    cout << "---------------------------------------------------------\n";
  }
}

Node *SLL::create(int num) {
  struct Node *temp;
  temp = new (struct Node);
  temp->value = num;
  temp->next = NULL;
  return temp;
}

void SLL::insBeg() {
  int num;
  cout << "Input number: ";
  cin >> num;
  struct Node *temp, *move;
  temp = create(num);  // assign your num to a node
  if (start == NULL) { // if the list is empty, instert temp node at the start
    start = temp;
  } else { // assign your whole list to move(from start), then insert temp at start, then com
    move = start;
    start = temp;
    start->next = move;
  }
  cout << num << " has been added to the beginning of the list.\n";
  size++; // increment size
}

void SLL::insLast() {
  int num;
  cout << "Input number: ";
  cin >> num;
  struct Node *temp, *find;
  temp = create(num);
  find = start;
  while (find->next != NULL) {
    find = find->next;
  }
  find->next = temp;
  cout << num << " has been added at the end of the list.\n";
  size++;
}

void SLL::insPos() {
  int num, pos, i = 1;
  cout << "Input number: ";
  cin >> num;
  cout << "Input position: ";
  cin >> pos;
  struct Node *temp, *find, *move;
  move = start;
  temp = create(num);
  if (pos < 1 || pos > size) {
    cout << "Out of Range\n";
    return;
  }
  if (pos == 1) {
    start = temp;
    start->next = move;
    cout << num << " has been inserted at the position " << pos << ".\n";
    size++;
    return;
  }
  while (i < pos) {
    find = move;
    move = move->next;
    i++;
  }
  find->next = temp;
  temp->next = move;
  cout << num << " has been inserted at the position " << pos << ".\n";
  size++;
}

void SLL::delPos() {
  int pos, i = 1;
  cout << "Input position: ";
  cin >> pos;
  struct Node *find, *del;
  del = start;
  if (pos < 1 || pos > size || start == NULL) {
    cout << "Out of Range\n";
    return;
  }
  if (pos == 1) {
    cout << start->value << " has been deleted from position " << pos << endl;
    start = start->next;
    size--;
    return;
  }
  while (i < pos) {
    find = del;
    del = del->next;
    i++;
  }
  cout << del->value << " has been deleted from position " << pos << endl;
  find->next = del->next;
  size--;
  return;
}

void SLL::display() {
  int i = 1;
  struct Node *temp;
  if (start == NULL) {
    cout << "The List is Empty" << endl;
    return;
  }
  temp = start;
  while (i <= size) {
    cout << "(" << i << ")" << temp->value << " -> ";
    temp = temp->next;
    i++;
  }
  cout << "NULL" << endl;
}

void SLL::update() {
  int pos, i = 1, num;
  cout << "Input position: ";
  cin >> pos;
  if (pos < 1 || pos > size) {
    cout << "Out of Range." << endl;
    return;
  }
  cout << "Input number: ";
  cin >> num;
  struct Node *find;
  find = start;
  while (i < pos) {
    find = find->next;
    i++;
  }
  find->value = num;
  cout << "Position " << pos << " has been updated.\n";
}

void SLL::sortDesc() {
  struct Node *temp, *nxt;
  int va;
  if (start == NULL) {
    cout << "The List is empty" << endl;
    return;
  }
  temp = start;
  while (temp != NULL) {
    if (isArm(temp->value) == 0) {
      for (nxt = temp->next; nxt != NULL; nxt = nxt->next) {
        if (isArm(nxt->value) == 0) {
          if (nxt->value > temp->value) {
            va = temp->value;
            temp->value = nxt->value;
            nxt->value = va;
          }
        }
      }
    }
    temp = temp->next;
  }
}
void SLL::sortAsc() {
  struct Node *temp, *nxt;
  int va;
  if (start == NULL) {
    cout << "The List is empty" << endl;
    return;
  }
  temp = start;
  while (temp != NULL) {
    if (isArm(temp->value) == 1) {
      for (nxt = temp->next; nxt != NULL; nxt = nxt->next) {
        if (isArm(nxt->value) == 1) {
          if (nxt->value < temp->value) {
            va = temp->value;
            temp->value = nxt->value;
            nxt->value = va;
          }
        }
      }
    }
    temp = temp->next;
  }
}
int SLL::isArm(int x) {
  int temp = x, coun = 0, sum = 0;
  while (temp) {
    temp = temp / 10;
    coun++;
    if (temp == 0) {
      break;
    }
  }
  temp = x;
  while (temp) {
    int rightD = temp % 10;
    sum = sum + pow(rightD, coun);
    temp = temp / 10;
  }
  if (sum == x) {
    return 1;
  } else {
    return 0;
  }
}
