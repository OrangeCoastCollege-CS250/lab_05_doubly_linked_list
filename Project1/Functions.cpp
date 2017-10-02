/*
	Badajoz, Seve

	CS A150
	October 1, 2017	

	Lab 05
*/

#include "DoublyList.h"

// Definition function print
void DoublyList::print() const {
	Node * curr = first;
	while (curr != nullptr) {
		cout << curr->getData() << " ";
		curr = curr->getNext();
	}
	cout << endl;
}

// Definition function reversePrint
void DoublyList::reversePrint() const {
	Node * curr = last;
	while (curr != nullptr) {
		cout << curr->getData() << " ";
		curr = curr->getPrev();
	}
	cout << endl;
}

// Definition function front
int DoublyList::front() const {
	return first->getData();
}

// Definition function back
int DoublyList::back() const {
	return last->getData();
}

// Definition function copyToList
void DoublyList::copyToList(DoublyList& canvasList) const {
	Node * curr = first;
	while (curr != nullptr) {
		canvasList.insertFront(curr->getData());
		curr = curr->getNext();
		canvasList.count++;
	}
}

// Definition function insertInOrder 
void DoublyList::insertInOrder(const int insertedNum) {
	bool inserted = false;
	if (count < 1) {
		insertFront(insertedNum);
		inserted = true;
	}
	else {
		Node * curr = first;
		if (curr->getData() >= insertedNum) {
			insertFront(insertedNum);
			inserted = true;
		}
		else {
			while (curr->getNext() != nullptr && !inserted) {
				if (curr->getNext()->getData() >= insertedNum) {
					Node * insertNode = new Node(insertedNum, curr, curr->getNext());
					curr->getNext()->setPrev(insertNode);
					curr->setNext(insertNode);
					inserted = true;
					count++;
				}
				else {
					curr = curr->getNext();
				}
			}
			if (!inserted) {
				last->setNext(new Node(insertedNum, last, nullptr));
				last = last->getNext();
				inserted = true;
				count++;
			}
		}
	}
}