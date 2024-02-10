
#include "linkedlist.h"
using namespace std;

#ifndef HASHMAP_CPP
#define HASHMAP_CPP

class HashMap {
public:
  LinkedList *table;
  HashMap();
  ~HashMap();
  void put(int key, int value);
  int get(int key);
  void remove(int key);
  int hash(int key);
};

#endif // HASHMAP_CPP