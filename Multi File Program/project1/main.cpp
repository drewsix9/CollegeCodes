#include "tree.h"
#include <bits/stdc++.h>

using namespace std;

void insertRand(int n, Tree &t) {
  srand(time(0));
  for (int i = 0; i < n; i++) {
    int num = 1 + rand() % 20;
    cout << "\nInserting " << num;
    t.insert(t.root, num);
  }
  t.display(t.root, 10);
}

int main(int argc, char **argv) {
  Tree tree;
  int n, c;
  while (1) {
    cout << "\n\n[0] - Exit\n[1] - Insert\n[2] - Insert N Random\n[3] - Delete\nEnter choice: ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
    case 1:
      cout << "Enter num to insert: ";
      cin >> n;
      tree.insert(tree.root, n);
      break;
    case 2:
      cout << "Enter number of random nums to insert: ";
      cin >> n;
      insertRand(n, tree);
      break;
    case 3:
      cout << "Enter num to delete: ";
      cin >> n;
      tree.deleteNode(tree.root, n);
      break;
    }
    cout << setw(20) << setfill('_') << " " << endl;
    tree.display(tree.root, 10);
  }

  return 0;
}
