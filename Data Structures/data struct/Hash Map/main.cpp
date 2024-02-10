#include "hashmap.hcpp"
#include <iostream>

using namespace std;

int main() {
  HashMap map;
  map.put(1, 2);
  map.put(2, 3);
  map.put(3, 4);
  cout << map.get(1) << endl;
  cout << map.get(2) << endl;
  cout << map.get(3) << endl;
  map.remove(2);
  cout << map.get(2) << endl;
  return 0;
  // print 2, 3, 4, -1
}