#include "linkedlist.hcpp"
#include <iostream>
using namespace std;

Node::Node() : _key(-1), _val(-1), next(nullptr) {}
Node::Node(int key, int val) : _key(key), _val(val) {}