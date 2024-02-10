#include "hashmap.hcpp"

HashMap::HashMap() {
  table = vector<Node *>(1000);
  for (int i = 0; i < 1000; i++) {
    table[i] = new Node();
  }
}

void HashMap::put(int key, int value) {
  Node *curr = table[hash(key)];
  while (curr && curr->next) {
    if (curr->_key == key) {
      curr->_val = value;
      return;
    }
    curr = curr->next;
  }
  curr->next = new Node(key, value);
}

int HashMap::get(int key) {
  Node *curr = table[hash(key)]->next;
  while (curr) {
    if (curr->_key == key) {
      return curr->_val;
    }
    curr = curr->next;
  }
  return -1;
}

void HashMap::remove(int key) {
  Node *curr = table[hash(key)];
  while (curr && curr->next) {
    if (curr->next->_key == key) {
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
