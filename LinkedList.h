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
	};
	Node* head;
	int listSize;
public:
	class OutOfBounds {};
	LinkedList();
	~LinkedList();
	void addItem(T);
	T removeItem(T);
	bool isInList(T) const;
	bool isEmpty() const;
	int size() const;
	T seeAt(int) const;
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
void LinkedList<T>::addItem(T data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->link = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* currentNode = head;
		while (currentNode->link != nullptr) {
			currentNode = currentNode->link;
		}
		currentNode->link = newNode;
	}
	listSize++;
}

template <class T>
T LinkedList<T>::removeItem(T item) {
	if (head == nullptr)												//Condition for no items
		return -99999999;
	Node* currentNode = head;
	if (currentNode->data == item && currentNode->link == nullptr) {    //Condition for list with one item
		listSize--;
		T i = currentNode->data;
		delete currentNode;
		head = nullptr;
		return i;
	}
	else {
		Node* lastNode = head;
		currentNode = currentNode->link;
		while (currentNode != nullptr) {
			if (currentNode->data == item) {
				listSize--;
				T i = currentNode->data;
				lastNode->link = currentNode->link;
				delete currentNode;
				return i;
			}
			lastNode = currentNode;
			currentNode = currentNode->link;
		}
		return -9999999;
	}
}

template<class T>
int LinkedList<T>::size() const {
	return listSize;
}

template <class T>
T LinkedList<T>::seeAt(int index) const{
	if (index > listSize - 1) 
		throw OutOfBounds();
	/*Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == data)
            return current->data;
        count++;
        current = current->link;
    }
	throw OutOfBounds();*/
}

template <class T>
bool LinkedList<T>::isInList(T key) const{
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
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