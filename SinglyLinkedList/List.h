#pragma once
#include <iostream>
using namespace std;
template<class T>
class List{
private:	
	struct Node {
		T value;
		Node* next;
	};
	Node* head;
	Node* tail; 
	int size;
	bool IsValidPos(int pos)const {
		return pos > 0 && pos <= size;
	}
public:

	List() : head(nullptr), tail(nullptr),size(0) {}
	List(const List& other){
		head = tail = nullptr;
		size=other.size;
			for (Node* elem = other.head; elem != nullptr; elem = elem->next)
				AddToTail(elem->value);
	}
	List(List&& other) {
		size = other.size;
		head = other.head;
		tail = other.tail;
		other.head = other.tail = nullptr;
		other.size = 0;
	}
	List& operator=(const List& other) {
		if (this != &other) {
			if (!IsEmpty())
				DeleteAll();
			head = tail = nullptr;
			size = other.size;
				for (Node* elem = other.head; elem != nullptr; elem = elem->next)
					AddToTail(elem->value);
		}
		return *this;
	}
	List& operator=(List&& other) {
		if (this != &other) {
			if (!IsEmpty())
				DeleteAll();
			size = other.size;
			head = other.head;
			tail = other.tail;
			other.head = other.tail = nullptr;
			other.size = 0;
		}
		return *this;
	}
	void DeleteAll() {
		while (!IsEmpty()) {
			DeleteHead();
		}
	}
	~List(){
		DeleteAll();
	}

	bool IsEmpty() const{
		return head == nullptr;
	}
	void AddToHead(const T&value){
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = head;
		head = newElem;
		if (tail == nullptr)
			tail = head;
		++size;
	}

	void AddToTail(const T&value){
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;
	
		if (IsEmpty())
			head = tail = newElem;
		
		else{
			tail->next = newElem;
			tail = newElem;
		}
		++size;
	}

	void DeleteHead(){
		if (IsEmpty()) 
			return;
		Node* temp = head->next;
		delete head;
		if (temp == nullptr)
			head = tail = nullptr;
		else
			head = temp;
		--size;
	}

	void DeleteTail(){
		if (head == nullptr) 
			return;
		if (head->next == nullptr){
			delete head;
			head = tail = nullptr;	
		}
		else{
			Node* current = head;
			for (; current->next->next != nullptr; current = current->next) {}
			delete current->next;
			current->next = nullptr;
			tail = current;
		}
		--size;
	}

	void Print() const{
		for (Node* current = head; current != nullptr; current = current->next)
			cout << current->value<<" ";
		cout << endl;
	}
	T Find(int pos)const {
		if (!IsValidPos(pos)) {
			cout << "Incorrect position.\n";
			return T();
		}
		if (pos == 1)
			return head->value;
		else if (pos == size)
			return tail->value;

		Node* current = head;
		for (int i = 1; i < pos; i++) 
			current = current->next;
		
		return current->value;
	}
	void AddToPos(int pos,T value) {
		if (!(pos > 0 && pos <= size+1)) {
			cout << "Incorrect position.\n";
			return;
		}
		if (pos == 1)
			AddToHead(value);
		else if (pos == size + 1)
			AddToTail(value);
		else {
			Node* newElem = new Node;
			newElem->value = value;
			Node* current = head;
			for (int i = 1; i < pos-1; i++)
				current = current->next;
			newElem->next = current->next;
			current->next = newElem;
			++size;
		}
		
	}
	void DelteFromPos(int pos) {
		if (!IsValidPos(pos)) {
			cout << "Incorrect position.\n";
			return;
		}
		if (pos == 1)
			DeleteHead();
		else if (pos == size)
			DeleteTail();
		else {
			Node* current = head;
			for (int i = 1; i < pos - 1; i++)
				current = current->next;
			Node* del = current->next;
			current->next = current->next->next;
			delete del;
			--size;
		}
		
	}
	int GetCount()const {
		return size;
	}
};

