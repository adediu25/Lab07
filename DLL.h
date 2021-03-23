#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h> 

using namespace std;

template <class T>
class doubleLL
{

private:
	struct Node {
		int data;
		struct Node* prev;
		struct Node* next;
	};
	Node* head;
	int listSize;

public:
	class OutOfBounds {};
	doubleLL();
	~doubleLL();
	void addItem(T*);
	T* removeItem(T*);
	bool isInList(T*) const;
	bool isEmpty() const;
	int size() const;
	T* seeAt(int) const;
	void reversePrint() const;
	void print() const;
};

template <class T>
doubleLL<T>::doubleLL()
{
	head = nullptr;
	listSize = 0;
}

template <class T>
doubleLL<T>::~doubleLL() {
	Node* currentNode = head;
	while (currentNode != nullptr) {
		Node* nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
}

template<class T>
void doubleLL<T>::addItem(T* data)
{
	listSize++;
	Node* newNode = new Node();
	newNode->data = *data;

	// Condition for empty list
	if (head == nullptr) {
		head = newNode;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		return;
	}
	else {
		Node* currentNode = head;
		// Check if newNode should be first in the list
		if (currentNode->data >= *data) {
			head = newNode;
			newNode->next = currentNode;
			newNode->prev = nullptr;
			currentNode->prev = newNode;
		}
		else {
			// Else iterate through list
			while (currentNode->next != nullptr) {
				// Insert newNode after currentNode if the 
				// node after current is greater than or
				// equal to newNode
				if (currentNode->next->data >= *data) {
					newNode->next = currentNode->next;
					currentNode->next->prev = newNode;
					newNode->prev = currentNode;
					currentNode->next = newNode;
					return;
				}
				else
					currentNode = currentNode->next;
			}
			// Insert newNode at end of list if it is greater
			// than all existing elements
			currentNode->next = newNode;
			newNode->next = nullptr;
			newNode->prev = currentNode;
		}
	}
}


template<class T>
T* doubleLL<T>::removeItem(T* item)
{
	Node* currentNode, * prevNode; 
	currentNode = head;
	// When list is empty
	if (head == nullptr)
		return nullptr;
	// When list only has one item and removing that item
	else if (currentNode->data == *item && currentNode->next == nullptr) {
		head = nullptr;
		listSize--;
		T* ret = &(currentNode->data);
		delete currentNode;
		return ret;
	}
	// When removing first item in list
	else if (currentNode->data == *item) {
		head = currentNode->next;
		currentNode->next->prev = nullptr;
		listSize--;
		T* ret = &(currentNode->data);
		delete currentNode;
		return ret;
	}
	else {
		currentNode = currentNode->next;
		prevNode = head;
		// Traverse list
		while (currentNode->next != nullptr) {
			// Remove if it is desired item
			if (currentNode->data == *item) {
				listSize--;
				currentNode->next->prev = prevNode;
				prevNode->next = currentNode->next;
				T* ret = &(currentNode->data);
				delete currentNode;
				return ret;
			}
			currentNode = currentNode->next;
			prevNode = prevNode->next;
		}
		// When item is last in the list
		if (currentNode->data == *item) {
			listSize--;
			prevNode->next = nullptr;
			T* ret = &(currentNode->data);
			delete currentNode;
			return ret;
		}
		else
			return nullptr;
	}
}

template <class T>
void doubleLL<T>::print() const
{
	Node* q;
	q = head;
	cout << "Doubly linked list items:" << endl;
	while (q != nullptr)
	{
		cout << q->data << endl;
		q = q->next;
	}
}


template<class T>
int doubleLL <T>::size()const
{
	return listSize;
}


template <class T>
void doubleLL<T>::reversePrint() const
{
	cout << "Reversed list:\n";
	if (isEmpty())
		return;
	Node* currentNode = head;
	while (currentNode->next != nullptr) {
		currentNode = currentNode->next;
	}
	cout << currentNode->data << endl;
	while (currentNode->prev != nullptr) {
		currentNode = currentNode->prev;
		cout << currentNode->data << endl;
	}
}

template <class T>
bool doubleLL <T>::isEmpty() const {
	if (head == nullptr)
		return true;
	else
		return false;
}


template <class T>
bool doubleLL <T>::isInList(T* key) const {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == *key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}


template <class T>
T* doubleLL<T>::seeAt(int index) const {
	if (index > listSize - 1)
		throw OutOfBounds();
	Node* current = head;
	int count = 0;
	while (current != nullptr) {
		if (count == index)
			return &(current->data);
		count++;
		current = current->next;
	}
}