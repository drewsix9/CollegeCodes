#include <ostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
  int key;
  int val;
  Node *next;

  // constructors
  Node();
  Node(int key, int val);
};

#endif // LINKEDLIST_H