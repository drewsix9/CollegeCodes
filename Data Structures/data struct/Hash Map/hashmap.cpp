#include "hashmap.hcpp"

HashMap::HashMap() {
  table = vector<Node *>(1000, new Node());
}

void HashMap::put(int key, int value) {
  Node *curr = table[hash(key)];
  while (curr->next) {
    if (curr->key == key) {
      curr->val = value;
      return;
    }
    curr = curr->next;
  }
  curr->next = new Node(key, value);
}

int HashMap::get(int key) {
  Node *curr = table[hash(key)]->next;
  while (curr) {
    if (curr->key == key) {
      return curr->val;
    }
    curr = curr->next;
  }
  return -1;
}

void HashMap::remove(int key) {
  Node *curr = table[hash(key)];
  while (curr->next) {
    if (curr->next->key == key) {
      Node *del = curr->next;
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
