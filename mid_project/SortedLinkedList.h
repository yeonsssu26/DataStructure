//#pragma once
//#ifndef _SORTED_LINKED_LIST_H
//#define _SORTED_LINKED_LIST_H
//
//#include <iostream>
//using namespace std;
//
//// Structure for NodeType to use in Linked structure.
//template <class ItemType>
//struct NodeType;
////{
////	ItemType data;		// A data for each node.
////	NodeType* next;		// A node pointer to point succeed node.
////};
//
//
//// Simple Sorted list class for managing items.
//template <class ItemType>
//class SortedLinkedList
//{
//public:
//
//	// Constructor
//	SortedLinkedList() {}
//
//
//	// Destructor
//	~SortedLinkedList() {}
//
//
//	/**
//	*	@brief	Get Number of node in the list.
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	none
//	*	@return	length of SortedLinkedList
//	*/
//	int GetLength() const;
//
//
//	/**
//	*	@brief	Get Next data of node and copy the data by call by ref
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	next data is copied to input parameter
//	*	@return	next node of data
//	*/
//	void GetNextItem(ItemType& item);
//
//
//	/**
//	*	@brief	search the right place and add new node in the SortedLinkedList.
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	new node is added into the SortedLinkedList.
//	*	@return return 1 if success add, else return 0
//	*/
//	int Add(ItemType item);
//
//
//	/**
//	*	@brief	delete the target node
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	the target node is deleted out the SortedLinkedList.
//	*	@return	return 1 if success delete, else return 0
//	*/
//	int Delete(ItemType item);
//
//
//	/**
//	*	@brief	replace node in the list.
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	the given node is replaced from the SortedLinkedList.
//	*	@return	return 1 if replace, else return 0
//	*/
//	int Replace(ItemType item);
//
//
//	/**
//	*	@brief	search the target node in the list and copy the node
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	node is copied (deep copy > by call by ref)
//	*	@return	return 1 if retrieve, else return 0
//	*/
//	int Retrieve(ItemType& item);
//
//
//	// isFull �Լ� �������� ���� > LinkedList Ư���� ���ʿ�
//	/*bool isFull(); */
//
//
//	/**
//	*	@brief	check if the SortedLinkedList is Empty
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	none
//	*	@return	return true if empty, else return false
//	*/
//	bool isEmpty();
//
//
//	/**
//	*	@brief	make the SortedLinkedList is Empty
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	SortedLinkedList become Empty
//	*	@return	none
//	*/
//	void MakeEmpty();
//
//
//	/**
//	*	@brief	make Location pointer and preLocation pointer NULL
//	*	@pre	none
//	*	@post	Location pointer and preLocation pointer become NULL pointer
//	*	@return	none
//	*/
//	void ResetPointer();
//
//
//	/*
//	*	@brief	Display All SortedLinkedList node on screen.
//	*	@pre	none.
//	*	@post	none.
//	*	@return	none
//	*/
//	void DisplayAll();
//
//
//	/**
//	*	@brief	Get current Node address
//	*	@pre	SortedLinkedList should be initialized.
//	*	@post	none
//	*	@return	current Node address
//	*/
//	ItemType* GetDataLocation();
//
//
//protected:
//	int length;							// Number of node in the list.
//
//	NodeType<ItemType>* startPoint;		// Pointer for pointing a first node.
//	NodeType<ItemType>* preLocation;	// Node pointer for pointing before current node
//	NodeType<ItemType>* Location;		// Node pointer for pointing current node to use iteration.
//
//};
//
//#endif _SORTED_LINKED_LIST_H

#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
using namespace std;


/**
*	Structure for NodeType to use in Linked structure.
*/
template <class ItemType>
struct NodeType
{
	ItemType data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	Simple unsorted list class for managing items.
*/
template <class ItemType>
class SortedLinkedList
{
public:

	SortedLinkedList();
	~SortedLinkedList();

	int GetLength() const;
	void GetNextItem(ItemType& item);

	int Add(ItemType item);
	int Delete(ItemType item);
	int Replace(ItemType item);
	int Retrieve(ItemType& item);		// Retrieve >> if find >> get data

	/*bool isFull(); */// isFull �Լ� �������� ���� >> LinkedList Ư���� ���ʿ�
	bool isEmpty();
	void MakeEmpty();
	void ResetPointer();
	void DisplayAll();

	ItemType* GetDataLocation();
	ItemType* GetNextDataLocation();


protected:
	NodeType<ItemType>* startPoint;		// Pointer for pointing a first node.
	NodeType<ItemType>* preLocation;	// Node pointer for pointing before current node
	NodeType<ItemType>* Location;		// Node pointer for pointing current node to use iteration.
	int length;							// Number of node in the list.
};

template <class ItemType>
SortedLinkedList<ItemType>::SortedLinkedList() {

	startPoint = NULL;
	preLocation = NULL;
	Location = NULL;
	length = 0;

}
template <class ItemType>
SortedLinkedList<ItemType>::~SortedLinkedList() {

	// ����Ʈ���� ��� node ����
	MakeEmpty();

}

template <class ItemType>
void SortedLinkedList<ItemType>::MakeEmpty() {

	// ����Ʈ���� ��� ��� �����ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<ItemType>* tempPtr;

	// ����Ʈ�� �պ��� ���� >> node�� ��� ������ ������ �ݺ�
	while (startPoint != NULL) {
		tempPtr = startPoint;			// ����Ʈ �� ���� node >> ������ target node
		startPoint = tempPtr->next;		// ������ node�� ���� node�� �հ� �̾���
		delete tempPtr;					// ���� �����ϸ� dangling pointer�� �߻��� �� ���� >> �������� ����!
	}

	length = 0;

}

template <class ItemType>
int SortedLinkedList<ItemType>::GetLength() const {
	return length;
}

template <class ItemType>
int SortedLinkedList<ItemType>::Add(ItemType item) {

	// preLocation, Location ������ �ʱ�ȭ
	ResetPointer();

	// ����Ʈ�� �߰��� ���ο� node ��ü ���� �� set up
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode->data = item;
	newNode->next = NULL;


	// �� list (node�� �ϳ��� ����Ǿ� ���� ���� list)
	if (length == 0) {
		startPoint = newNode; // list �� �տ� newNode ����

		preLocation = Location;
		Location = startPoint;

	}

	// list�� node�� �ϳ� �̻� ����Ǿ� �ִ� ���
	else {

		// getNextItem()�� ���� > preLocation, Location ������ ���Ž� �ʿ�
		ItemType dummy;

		// ���� ������ node�� �̵� �� newNode ����
		while (1) {

			GetNextItem(dummy);

			if (Location->data > newNode->data) {

				if (preLocation == NULL) {

					newNode->next = Location;
					startPoint = newNode;
					break;

				}
				else {

					newNode->next = Location;
					preLocation->next = newNode;
					break;

				}

			}

			if (Location->next == NULL) {


				Location->next = newNode;
				break;

			}

		}

	}

	length++; // node�� add������ >> ��������
	
	return 1;

}

template <class ItemType>
int SortedLinkedList<ItemType>::Delete(ItemType item) {

	// preLocation, Location ������ �ʱ�ȭ
	ResetPointer();
	Location = startPoint;

	bool moreToSearch, found;
	moreToSearch = (Location != NULL); // true
	found = false;

	while (moreToSearch && !found) { // list�� ���� �ƴϸ鼭, ���� ã�� �������� >> �ݺ��Ѵ�


		if (Location->data == item) { // find >> ���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��

			found = true;

			if (preLocation == NULL) { // ������ �׸� ������ �ٸ� ���Ұ� ���� ��

				startPoint = Location->next;	// ������ �׸� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.

			}
			else {

				preLocation->next = Location->next;	// ������ node�� ���� node�� ����Ŵ
				delete Location;	// node ����

			}

			length--; // ���������Ƿ� >> ���̰���

		}
		else { // not find >> preLocation, Location ������ �̵�

			// ������ ����
			preLocation = Location;
			Location = Location->next;

			// moreToSearch ����
			moreToSearch = (Location != NULL); // moreToSearch�� true(Location != NULL)�̸� >> while�� �ݺ�

		}
	}

	if (found) return 1;	// success
	else return 0;			// fail

}

template <class ItemType>
int SortedLinkedList<ItemType>::Replace(ItemType item) {

	// preLocation, Location ������ �ʱ�ȭ
	ResetPointer();
	Location = startPoint;

	bool moreToSearch, found;
	moreToSearch = (Location != NULL); // true;
	found = false;

	ItemType dummy;

	while (moreToSearch && !found) {
		if (Location->data == item) {
			found = true;	// �ش� ��ġ ã��
			Location->data = item; // ġȯ
		}
		else {
			GetNextItem(dummy); // move preLocation and Location pointer
			moreToSearch = (Location != NULL); // ���ŵ� ������ >> check moreToSearch
		}
	}

	if (found) return 1;	// replace success
	else return 0;			// replace fail

}


template <class ItemType>
int SortedLinkedList<ItemType>::Retrieve(ItemType& item) { // Node�� pk�� ��ġ�ϸ� >> item�� Node�� data ���� >> call-by-ref

	ResetPointer();
	Location = startPoint;

	bool moreToSearch, found;
	moreToSearch = (Location != NULL);
	found = false;

	ItemType dummy;
	while (moreToSearch && !found) {

		if (Location->data == item) { // pk ��ġ
			found = true;
			item = Location->data; // data�� �ִ� ���� >> item�� ����
		}
		else {

			if (Location->next == NULL) break;	// Location->next == NULL�� ��� >> GetNextItem���� �̵��� pointer�� ����Ű�� data�� �������� �ʾ� error�߻�

			GetNextItem(dummy);					// move preLocation, Location pointer
			moreToSearch = (Location != NULL); // ���ŵ� pointer >> check moreToSearch
		}

	}

	if (found) return 1;	// success
	else return 0;			// fail


}

template <class ItemType>
void SortedLinkedList<ItemType>::ResetPointer() {

	// preLocation, Location �����ͺ��� �ʱ�ȭ
	preLocation = NULL;
	Location = NULL;

}

template <class ItemType>
void SortedLinkedList<ItemType>::GetNextItem(ItemType& item) { // preLocation�� Location ������ �Ѵ� �̵���Ų�� (�������ڵ�� ����)

	// Location�� NULL�� �� ���� ��� node�� ����Ű�� �ʴ� �����̹Ƿ� >> ���� node�� 1�� node�� ����Ű�� ��
	if (Location == NULL) {
		Location = startPoint;
	}

	// Location�� ���� node�� ����Ű�� ��
	else {

		// prelocation���� ����
		preLocation = Location;

		// Location �̵�
		Location = Location->next;
	}

	// item�� �̵��� Location�� data�� ����
	item = Location->data;

}

template <class ItemType>
void SortedLinkedList<ItemType>::DisplayAll() {

	ResetPointer();
	Location = startPoint;

	while (!Location == NULL) {
		cout << Location->data << endl;
		Location = Location->next;
	}

}

template <class ItemType>
bool SortedLinkedList<ItemType>::isEmpty() {
	return (Location == NULL);
}

template <class ItemType>
ItemType* SortedLinkedList<ItemType>::GetDataLocation() {
	if (Location == NULL) return NULL;
	else return &(Location->data);
}

template <class ItemType>
ItemType* SortedLinkedList<ItemType>::GetNextDataLocation() {
	if (Location->next == NULL) return NULL;
	else return &(Location->next->data);
}

#endif	// LINKED_LIST