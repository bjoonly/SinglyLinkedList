#pragma once
#include<iostream>
using namespace std;
template<class T>
class StackList {
	struct Node {
		T value;
		Node* next;
	};
	Node*head;
public:
	StackList() :head(nullptr) {}
	StackList(const StackList& other) {
		Node* temp=nullptr;
		head = nullptr;
		for (Node *currentOther = other.head,*current=nullptr; currentOther != nullptr; currentOther = currentOther->next) {
			temp = new Node;
			temp->value = currentOther->value;
			temp->next = nullptr;
			if (head == nullptr) {
				head = temp;
				current = temp;
			}
			else {
				current->next = temp;
				current = current->next;
			}
		}
	}
	StackList& operator=(const StackList& other) {
		if (!IsEmpty())
			Clear();
		if (this != &other) {
			Node* temp = nullptr;
			head = nullptr;
			for (Node* currentOther = other.head, *current = nullptr; currentOther != nullptr; currentOther = currentOther->next) {
				temp = new Node;
				temp->value = currentOther->value;
				temp->next = nullptr;
				if (head == nullptr) {
					head = temp;
					current = temp;
				}
				else {
					current->next = temp;
					current = current->next;
				}
			}
		}
		return *this;
	}
	~StackList() {
		Clear();
	}
	void Push(const T&value) {
		Node* newNode = new Node;
		newNode->value = value;
		if (IsEmpty())
			newNode->next = nullptr;
		else
			newNode->next = head;
		head = newNode;
	}

	T Pop() {
		if (IsEmpty())
			return T();
	
		Node* temp = head->next;
		T value = head->value;
		delete head;
		head = temp;
		return value;
	}

	T Peek()const {
		if (IsEmpty())
			return T();
		return head->value;
	}

	void Clear() {
		for (Node* current = head; current != nullptr; current = head) {
			head = head->next;
			delete current;
		}

	}

	bool IsEmpty()const {
		return head == nullptr;
	}

	void Print()const {
		for (Node* current = head; current != nullptr; current = current->next)
			cout << current->value << " ";
		cout << endl;
	}

	int GetCount()const {
		int count = 0;
		for (Node* current = head; current != nullptr; current = current->next)
			++count;
		return count;
	}

};

