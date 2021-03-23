#pragma once
#include <iostream>

using std::cout;

template <class T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* link;
		Node() {};
		Node(const Node&) = default;
	};
	Node* head;
	int listSize;
public:
	class OutOfBounds {};
	LinkedList();
	~LinkedList();
	void addItem(T*);
	T* removeItem(T*);
	bool isInList(T*) const;
	bool isEmpty() const;
	int size() const;
	T* seeAt(int) const;
	void print() const;
};

////////////////////
// Implementation //
////////////////////

template <class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	listSize = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node* currentNode = head;
	while (currentNode != nullptr) {
		Node* nextNode = currentNode->link;
		delete currentNode;
		currentNode = nextNode;
	}
}

template <class T>
void LinkedList<T>::addItem(T* data) {
	listSize++;
	Node* newNode = new Node();
	newNode->data = *data;
	
	// Condition for empty list
	if (head == nullptr) {
		head = newNode;
		newNode->link = nullptr;
		return;
	}
	else {
		Node* currentNode = head;
		// Check if newNode should be first in the list
		if (currentNode->data >= *data) {
			head = newNode;
			newNode->link = currentNode;
		}
		else {
			// Else iterate through list
			while (currentNode->link != nullptr) {
				// Insert newNode after currentNode if the 
				// node after current is greater than or
				// equal to newNode
				if (currentNode->link->data >= *data) {
					newNode->link = currentNode->link;
					currentNode->link = newNode;
					return;
				}
				else
					currentNode = currentNode->link;
			}
			// Insert newNode at end of list if it is greater
			// than all existing elements
			currentNode->link = newNode;
			newNode->link = nullptr;
		}
	}
}

template <class T>
T* LinkedList<T>::removeItem(T* item) {
	if (head == nullptr)												//Condition for no items
		return nullptr;
	Node* currentNode = head;
	if (currentNode->data == *item && currentNode->link == nullptr) {    //Condition for list with one item
		listSize--;
		T* i = &(currentNode->data);
		head = nullptr;
		return i;
	}
	else if (currentNode->data == *item) {							//Condition for removing first item
		listSize--;
		T* i = &(currentNode->data);
		head = currentNode->link;
		return i;
	}
	else {
		Node* lastNode = head;
		currentNode = currentNode->link;
		while (currentNode != nullptr) {
			if (currentNode->data == *item) {
				listSize--;
				T* i = &(currentNode->data);
				lastNode->link = currentNode->link;
				return i;
			}
			lastNode = currentNode;
			currentNode = currentNode->link;
		}
		return nullptr;
	}
}

template<class T>
int LinkedList<T>::size() const {
	return listSize;
}

template <class T>
T* LinkedList<T>::seeAt(int index) const{
	if (index > listSize - 1) 
		throw OutOfBounds();
	Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (count == index)
            return &(current->data);
        count++;
        current = current->link;
    }
}

template <class T>
bool LinkedList<T>::isInList(T* key) const{
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == *key) {
			return true;
		}
		temp = temp->link;
	}
	return false;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
	if (head == nullptr)
		return true;
	else
		return false;
}

template <class T>
void LinkedList<T>::print() const{
	Node* temp = head;
	cout << "The linked list elements are: \n";
	while (temp != nullptr) {
		cout << temp->data << "\n";
		temp = temp->link;
	}
}