
#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::Node::Node() : key(-1), val(-1), next(nullptr) {}
LinkedList::Node::Node(int key, int val) : key(key), val(val) {}

ostream &
operator<<(ostream &os, const LinkedList &list) {
  LinkedList::Node *curr = list.head;
  while (curr) {
    os << curr->val << " -> ";
    curr = curr->next;
  }
  os << "nullptr";
  return os;
}