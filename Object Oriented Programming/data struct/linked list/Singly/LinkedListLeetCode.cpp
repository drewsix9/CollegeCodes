#include <initializer_list>
#include <iostream>
using namespace std;

class LinkedList {
  class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int d) : val(d), next(nullptr) {}
    ListNode(int d, ListNode *n) : val(d), next(n) {}
  };

public:
  ListNode *head;
  LinkedList() : head(nullptr) {}
  LinkedList(initializer_list<int> list) {
    head = nullptr;
    for (int n : list) {
      this->insert(n);
    }
  }

  void insert(int d) {
    if (!head) {
      head = new ListNode(d);
      return;
    }
    ListNode *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new ListNode(d);
  }

  void print() {
    if (!head) {
      return;
    }
    ListNode *ptr = head;
    cout << "\nOutput: ";
    while (ptr) {
      cout << ptr->val << " ";
      ptr = ptr->next;
    }
  }

  ListNode *swapNodesByPair() {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;
    ListNode *curr = head;
    while (curr && curr->next) {
      // Save pointers
      ListNode *nextPair = curr->next->next;
      ListNode *second = curr->next;
      // change
      second->next = curr;
      curr->next = nextPair;
      prev->next = second;
      // update
      prev = curr;
      curr = nextPair;
    }
    return dummy->next;
  }

  bool isPalindrome() {
    if (!head || !head->next) {
      return true;
    }
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *prev = nullptr;
    while (slow) {
      ListNode *tmp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = tmp;
    }
    ListNode *left = head, *right = prev;
    while (left && right) {
      if (left->val != right->val) {
        return false;
      }
      left = left->next;
      right = right->next;
    }
    return true;
  }

  ListNode *removeElements(int val) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy, *curr = head;
    while (curr) {
      if (curr->val == val) {
        ListNode *delNode = curr;
        if (curr->next) {
          prev->next = delNode->next;
        } else {
          prev->next = nullptr;
        }
        delete delNode;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return dummy->next;
  }

  ListNode *deleteMiddle() {
    if (!head || !head->next) {
      head = nullptr;
    }
    ListNode *prev = nullptr, *slow = head, *fast = head;
    while (fast && fast->next) {
      prev = slow;
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *delNode = slow;
    prev->next = slow->next;
    delete delNode;
    return head;
  }

  ListNode *deleteDuplicatesOfSortedList() {
    ListNode *ptr = head;
    while (ptr && ptr->next) {
      ListNode *next = ptr->next;
      if (ptr->val == next->val) {
        while (next && ptr->val == next->val) {
          next = next->next;
        }
        ptr->next = next;
        ptr = next;
      } else {
        ptr = ptr->next;
      }
    }
    return head;
  }
  // reorder list where:
  // L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
  ListNode *reorderList() {
    if (!head || !head->next) {
      return head;
    }
    // moving slow to middle of list
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *second = slow->next;
    // ending the fist half
    slow->next = nullptr;
    ListNode *prev = nullptr;
    // reversing the second half
    while (second) {
      ListNode *tmp = second->next;
      second->next = prev;
      prev = second;
      second = tmp;
    }
    ListNode *first = head;
    second = prev;
    // perform the reordering
    while (first && second) {
      // saving ptrs
      ListNode *fNext = first->next, *sNext = second->next;
      // changing
      first->next = second;
      second->next = fNext;
      first = fNext;
      second = sNext;
    }
    return head;
  }

  void removeNthFromEnd(int n) {
    if (!head || (!head->next && n == 1)) {
      head = nullptr;
      return;
    }
    ListNode *fast = head, *dummy = new ListNode(0, head);
    while (n > 0 && fast) {
      fast = fast->next;
      n--;
    }
    ListNode *slow = head, *prev = dummy;
    while (fast) {
      prev = slow;
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *delNode = slow;
    prev->next = slow->next;
    delete delNode;
    head = dummy->next;
  }
  // swap nodes in pair
  ListNode *swapNodes(int k) {
    if (!head) {
      return nullptr;
    }
    ListNode *dummy = new ListNode(0, head);
    ListNode *currA = dummy, *prevA = nullptr;
    while (k > 0 && currA) {
      prevA = currA;
      currA = currA->next;
      k--;
    }
    ListNode *fast = currA->next, *slow = head, *prevB = nullptr;
    while (fast) {
      prevB = slow;
      slow = slow->next;
      fast = fast->next;
    }
    ListNode *currB = slow;
    prevA->next = currB;
    prevB->next = currA;
    ListNode *tmp = currA->next;
    currA->next = currB->next;
    currB->next = tmp;
    return dummy->next;
  }

  // reverse nodes in k groups
  ListNode *reverseKGroup(int k) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prevGroup = dummy;
    while (1) {
      ListNode *kth = getKth(prevGroup, k);
      if (!kth) {
        break;
      }
      ListNode *nxtGroup = kth->next;
      // reversing
      ListNode *prev = kth->next, *curr = prevGroup->next;
      while (curr != nxtGroup) {
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
      }
      ListNode *temp = prevGroup->next;
      prevGroup->next = kth;
      prevGroup = temp;
    }
    return dummy->next;
  }

  ListNode *getKth(ListNode *n, int k) {
    while (n && k > 0) {
      n = n->next;
      k--;
    }
    return n;
  }
};

int main() {

  LinkedList li({1, 2, 3, 4, 5});
  // li.head = li.swapNodesByPair();
  // cout << boolalpha << li.isPalindrome();
  // li.head = li.removeElements(0);
  // li.deleteMiddle();
  // li.head = li.deleteDuplicatesOfSortedList();
  // li.head = li.reorderList();
  // li.head = li.removeNthFromEnd(2);
  // li.head = li.swapNodes(4);
  li.head = li.reverseKGroup(3);
  li.print();
}