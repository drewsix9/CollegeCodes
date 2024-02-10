#include <ostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
  class Node {
  public:
    int key;
    int val;
    Node *next;

    // constructors
    Node();
    Node(int key, int val);
  };
  Node *head;
  LinkedList();

  // output to stream
  friend ostream &operator<<(std::ostream &os, const LinkedList &list);
};

#endif // LINKEDLIST_H