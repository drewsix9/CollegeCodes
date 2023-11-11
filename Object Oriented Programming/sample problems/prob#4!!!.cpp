/*
  You are given a list of n integers. You need to implement a data structure that supports the following operations efficiently:

  add(x): Add the integer x to the list.
  remove(x): Delete the integer x from the list.
  find(x): Find the position of the integer x in the list, or return -1 if x is not present.
*/

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class LinkedList {
private:
	class ListNode {
	public:
		int data;
		ListNode *next;
		ListNode(int d):data(d),next(nullptr) {}
		ListNode(int d, ListNode *n):data(d),next(n) {}
	};
	ListNode *head;
public:
	LinkedList():head(nullptr) {}
	void add(int n) {
		if(!head) {
			head = new ListNode(n);
			cout<<"\n[INFO] Successfully added!";
			return;
		}

		ListNode *ptr=head;

		while(ptr->next) {
			ptr=ptr->next;
		}
		ptr->next = new ListNode(n);
		cout<<"\n[INFO] Successfully added!";
		print();
	}

	void remove(int d) {
		int count=-1;
		if(!head) {
			cout<<"\n[WARNING] List is empty!";
			return;
		}
		ListNode *curr = head;
		ListNode *prev = nullptr;
		while(curr && curr->data!=d) {
			prev = curr;
			curr=curr->next;
		}
		if(!curr) {
			cout<<"\n[INFO] Input num does not exist in list";
			return;
		}
		if(curr==head) {
			head = curr->next;
			cout<<"\n[INFO] Successfully removed!";
			print();
			return;
		}
		prev->next = curr->next;
		cout<<"\n[INFO] Successfully removed!";
		delete curr;
		print();
	}

	void print() {
		if(!head) {
			cout<<"\n[WARNING] List is empty!";
			return;
		}
		cout<<"\nOutput: ";
		ListNode *ptr = head;
		while(ptr) {
			cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
	}

	void find(int n) {
		int count = 0;
		if(!head) {
			cout<<"\n[WARNING] List is empty!";
			return;
		}
		ListNode *ptr = head;

		while(ptr && ptr->data !=n) {
			ptr=ptr->next;
			count++;
		}
		if(!ptr) {
			cout<<"\n[INFO] Int n is found at index: "<<-1;
			return;
		}
		cout<<"\n[INFO] Int "<<n<<" is found at index: "<<count;
	}

};

int main() {
	LinkedList<int> list;

	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.find(5);
	list.find(9);

}
