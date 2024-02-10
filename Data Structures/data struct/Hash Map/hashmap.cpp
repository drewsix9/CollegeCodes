#include "hashmap.h"

HashMap::HashMap() {
  table = new LinkedList[1000];
}

HashMap::~HashMap() {
  delete[] table;
}

void HashMap::put(int key, int value) {
  LinkedList::Node *curr = table[hash(key)].head;
  while (curr->next) {
    if (curr->key == key) {
      curr->val = value;
      return;
    }
    curr = curr->next;
  }
  curr->next = new LinkedList::Node(key, value);
}

int HashMap::get(int key) {
  LinkedList::Node *curr = table[hash(key)].head->next;
  while (curr) {
    if (curr->key == key) {
      return curr->val;
    }
    curr = curr->next;
  }
  return -1;
}

void HashMap::remove(int key) {
  LinkedList::Node *curr = table[hash(key)].head;
  while (curr->next) {
    if (curr->next->key == key) {
      LinkedList::Node *del = curr->next;
      curr->next = curr->next->next;
      delete del;
      return;
    }
    curr = curr->next;
  }
}

int HashMap::hash(int key) {
  return key % 1000;
}
