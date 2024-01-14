#include <iostream>

using namespace std;

#ifndef MYSTACKQUEUELL_H
#define MYSTACKQUEUELL_H

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

#endif