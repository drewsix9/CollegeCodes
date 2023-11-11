// Problem: Hot Potato Game

// Description: In the Hot Potato game, children form a circle and pass around a potato while music plays. When the music stops, the child holding the potato is eliminated. The game continues until only one child remains. You need to implement a simulation of the Hot Potato game.

// Write a program that takes the following input:

// An integer n representing the number of children in the game.
// An integer k representing the elimination count.
// The program should simulate the Hot Potato game and determine the order in which the children are eliminated. The program should print the sequence of eliminations, starting from the child who is eliminated first until the last child remaining.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  void HotPotato(int n, int k) {

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      q.push(i);
    }

    cout << "\nOutput: ";
    while (q.size() > 1) {

      // enqueue the 1 to (k-1) elements
      for (int i = 0; i < k - 1; i++) {
        int curr = q.front();
        q.pop();
        q.push(curr);
      }

      // dequeue the kth element/front
      int elim = q.front();
      q.pop();
      cout << elim << " ";
    }
  }
};

int main() {
  Solution sol;
  int n = 7;
  int k = 3;
  sol.HotPotato(n, k);
}