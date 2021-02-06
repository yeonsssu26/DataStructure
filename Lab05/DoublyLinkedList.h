#pragma once
#ifndef _SORTED_LINKED_LIST_H
#define _SORTED_LINKED_LIST_H
#include <iostream>
using namespace std;

template <typename T>
class DoublyIterator;

template <typename T>
struct DoublyNodeType
{
	T data;					// A data for each node.
	DoublyNodeType* prev;	// A node pointer of previous node.
	DoublyNodeType* next;	// A node pointer of next node.
};

template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;
public:
	DoublySortedLinkedList();
	~DoublySortedLinkedList();

	bool IsFull();
	bool IsEmpty();
	void MakeEmpty();
	int GetLength() const;

	int Add(T item);
	int Delete(T data);
	int Retrieve(T& item);
	void Replace(T data);
	void DisplayAll();


private:
	DoublyNodeType<T>* startPtr;	// Pointer for pointing a first node.
	DoublyNodeType<T>* endPtr;		// Pointer for pointing a last node.
	int length;		// Number of node in the list.
};


// Class constructor
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList(){
	length = 0;
	startPtr = nullptr;
	endPtr = nullptr;
}


// Class destructor : ����Ʈ���� ��� node ����
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList(){
	MakeEmpty();
}

// ���������� ������, ���� �޸𸮰� ���� ���� �� �̻� �Ҵ��� �Ұ����� ��� �ý��� ���� ó��
template <typename T>
bool DoublySortedLinkedList<T>::IsFull() {
	//try {
	//	DoublyNodeType<T>* temp = nullptr;	// if there is not memory left, temp would not be initialized as NULL and
	//	delete temp;						// deleting temp(pointer) could not be executed.
	//	return false;
	//}
	//catch (bad_alloc& e_ba) {
	//	cerr << "bad_alloc exception caught : " << e_ba.what() << endl;
	//	return true;
	//}

	return false;

}

// Determines whether the list is empty.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty() {
	return startPtr == nullptr;
}

// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty() {
	
	DoublyNodeType<T>* tmpPtr;
	DoublyIterator<T> iter(*this); // iterator ��ü�� ������ > ���縮��Ʈ�� �ּ� �ѱ�

	while (iter.NotNull()) {
		tmpPtr = iter.currPtr;
		iter.Next();
		delete tmpPtr;
	}

	length = 0;
}

// Get number of elements in the list.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const {
	return length;
}


// Add item into this list.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item) {
	if (!IsFull()) {

		DoublyNodeType<T>* newNode = new DoublyNodeType<T>; // �� ��� �Ҵ�
		newNode->data = item;
		newNode->prev = nullptr;
		newNode->next = nullptr;
		
		if (startPtr == nullptr) { // ����Ʈ�� ����ִ� ���

			startPtr = newNode; // ���������Ϳ� ����� ����
			endPtr = startPtr;  // �������͵� ����� ����Ŵ

		}
		else { // ����Ʈ�� ��尡 1�� �̻� ����Ǿ� �ִ� ���

			DoublyIterator<T> iter(*this); // pointer������ �ϴ� iterator ��ü ����
			DoublyNodeType<T>* iterNode; // iterator�� DDL�� ��ȸ�� �� ������ node�� ����ų ������

			while (iter.NotNull()) {

				iterNode = iter.currPtr; // GetCurrentNode�� return by value�̹Ƿ� ���� �� �� �޸� ���� �Ұ��ؼ� ��� ����

				if (newNode->data < iterNode->data) { // �������� �ϴ� �� �� ����

					// ����ġ �տ� ���� > ����带 ������忡 ����
					newNode->next = iterNode;
					
					// �Ǿ�
					if (length == 1) {

						// ���������ͷ� ����� ����Ŵ
						startPtr = newNode;

					}

					// �߰�
					else {

						// "������� prev������"�� "������ġ�� �������"�� ����Ŵ (����尡 �ճ��)
						newNode->prev = iterNode->prev;

						// "������ġ�� ��������� next������"�� "�����"�� ����Ŵ (�ճ�尡 �����)
						newNode->prev->next = newNode;

					}

					// "������ġ�� prev������"�� "�����"�� ����Ŵ (�޳�尡 �����)
					iterNode->prev = newNode;
					break;

				}
				else {

					// �ǵ�
					if (!iter.NextNotNull()) { // ����Ʈ�� ��������� �� ��


						// "������ġ�� next������"�� "�����"�� ����Ŵ > ����带 ����Ʈ �� �ڿ� ���� (�տ��� �ڿ���)
						iterNode->next = newNode;

						// ����Ʈ �� �ڿ� ����� "������� prev������"�� "������"�� ����Ŵ (�ڿ��� �տ���)
						newNode->prev = iterNode;

						// �������ͷ� ����� ����Ŵ
						endPtr = newNode;
						
						// ������ �������Ƿ� while�� ����
						break;

					}
					else
						iter.Next(); // ����Ʈ�� ��������尡 �ƴϹǷ� ���� ���� �̵�
				}
			}
		}
		length++;

		return 1;
	}
	else {
		return 0;
	}
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Retrieve(T& item) {

	DoublyIterator<T> iter(*this); // pointer������ �ϴ� iterator ��ü ����
	bool found = false;
	int count = 0;	// �� ��°�� ��ġ�ϰ� �ִ��� return�ϱ� ���ؼ�
					// iterator�� �̿��ϸ鼭 currPtr�� ���ÿ� ����� �� ��� count���� ��� ????

	while (iter.NotNull()) { // �� ����Ʈ�� �ƴ϶�� Ž��
		
		count++;
		
		if (item == iter.GetCurrentNode().data) { // found
			item = iter.GetCurrentNode().data;
			found = true;
			break;
		}
		else if (item < iter.GetCurrentNode().data) { // not exist
			break;
		}
		else { // more to search
			iter.Next();
		}

	}

	if (found) return count;
	else return 0;
}


// Ư�� ��Ҹ� ã�� �����ϴ� �Լ�
template <typename T>
int DoublySortedLinkedList<T>::Delete(T data) {

	// ���ؼ� ������ �ڵ� ����
	DoublyNodeType<T>* pNode = startPtr;
	int positionIndex = Retrieve(data);
	if (positionIndex) {
		for (int i = 1; i < positionIndex; i++) {
			pNode = pNode->next;
		}
		if (pNode->next != nullptr) {	// ���� �ƴϸ�
			pNode->next->prev = pNode->prev;
		}
		else endPtr = pNode->prev;
		if (pNode->prev != nullptr) {	// ó���� �ƴϸ�
			pNode->prev->next = pNode->next;
		}
		else startPtr = pNode->next;
		delete pNode;
		length--;
		return 1;
	}
	else return 0;



	/*
	// myTry
	DoublyNodeType<T>* iterNode = startPtr;
	int targetNodePos = Retrieve(data); // ������ ����� ��ġ

	if (targetNodePos != 0) { // ������ ��尡 ����Ʈ�� �����Ѵٸ�

	}
	*/

}

// Ư�� ��Ҹ� ã�� ���ο� �������� ��ġ��Ű�� �Լ�
template <typename T>
void DoublySortedLinkedList<T>::Replace(T data) {

	// ���ؼ� ������ �ڵ� ����
	T target = data;
	DoublyNodeType<T>* pNode = startPtr;
	int positionIndex = Retrieve(target);
	for (int i = 1; i < positionIndex; i++) {
		pNode = pNode->next;
	}
	pNode->data = data;

}


template <typename T>
void DoublySortedLinkedList<T>::DisplayAll() {

	DoublyIterator<T> iter(*this); // pointer������ �ϴ� iterator ��ü ����
	while (iter.NotNull()) {
		cout << iter.GetCurrentNode().data << endl;
		iter.Next();
		if (!iter.NextNotNull()) break;
	}

}


#endif	// LINKED_LIST