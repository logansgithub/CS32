#pragma once
#ifndef LinkedList_h

#include <iostream>
#include <string>
//using namespace std;

typedef  std::string ItemType;

struct Node {
	ItemType value;
	Node *next;
};
class LinkedList {
private:
	Node * head;
	
public:
	LinkedList() : head(nullptr) { }
	LinkedList(const LinkedList& rhs);
	~LinkedList();
	/*const*/ LinkedList& operator=(const LinkedList& rhs);
	void insertToFront(const ItemType &val);
	void printList() const;
	bool get(int i, ItemType& item) const;
	void reverseList();
	void printReverse() const;
	void append(const LinkedList &other);
	void swap(LinkedList &other);
	int size() const;
};

#endif // !LinkedList_h
