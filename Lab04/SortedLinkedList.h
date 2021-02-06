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

//template <class ItemType>
//int SortedLinkedList<ItemType>::Add(ItemType item) {
//
//	// preLocation, Location ������ �ʱ�ȭ
//	ResetPointer();
//
//	// ����Ʈ�� �߰��� ���ο� node ��ü ���� �� set up
//	NodeType<ItemType>* newNode = new NodeType<ItemType>;
//	newNode->data = item;
//	newNode->next = NULL;
//
//
//	// �� list (node�� �ϳ��� ����Ǿ� ���� ���� list)
//	if (length == 0) {
//		startPoint = newNode; // list �� �տ� newNode ����
//	}
//
//	// list�� node�� �ϳ� �̻� ����Ǿ� �ִ� ���
//	else {
//
//		// getNextItem()�� ���� > preLocation, Location ������ ���Ž� �ʿ�
//		ItemType dummy;
//
//		// ���� ������ node�� �̵� �� newNode ����
//		while (1) {
//
//			GetNextItem(dummy);	// preLocation, Location ������ ���� >> ���� node�� �̵�
//
//			if (Location->data > newNode->data) { // ����!
//
//
//				/*preLocation = Location;*/
//
//
//
//				if (preLocation == NULL) { // �� list�� �ƴϰ�, ���� �� node�� ������ �� >> ���� �� ����
//
//					newNode->next = Location;
//					startPoint = newNode;
//					//break;
//
//				}
//				else { // �� list�� �ƴϰ�, preLocation�ڿ� ���ο� node�� ������ �� >> �߰� ����
//
//					newNode->next = Location;
//					preLocation->next = newNode;
//					//break;
//
//				}
//
//
//
//				/*Location = Location->next;
//				break;*/
//
//
//
//			}
//
//			if (Location->next == NULL) { // Location �����Ͱ� ������ node�� ����Ű�� >> ���� �� ����
//
//				// ������ node�� ���ο� node ����
//				Location->next = newNode;
//				break;
//
//			}
//
//		}
//
//	}
//
//	length++; // node�� add������ >> ��������
//
//	//delete newNode;
//
//
//	return 1;
//
//}
//
//template <class ItemType>
//int SortedLinkedList<ItemType>::Delete(ItemType item) {
//
//	// preLocation, Location ������ �ʱ�ȭ
//	ResetPointer();
//	Location = startPoint;
//
//	bool moreToSearch, found;
//	moreToSearch = (Location != NULL); // true
//	found = false;
//
//	while (moreToSearch && !found) { // list�� ���� �ƴϸ鼭, ���� ã�� �������� >> �ݺ��Ѵ�
//
//		if (Location->data == item) { // find >> ���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
//
//			found = true;
//
//			if (preLocation == NULL) { // ������ �׸� ������ �ٸ� ���Ұ� ���� ��
//
//				startPoint = Location->next;	// ������ �׸� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
//
//			}
//			else {
//
//				preLocation->next = Location->next;	// ������ node�� ���� node�� ����Ŵ
//				delete Location;	// node ����
//
//			}
//
//			length--; // ���������Ƿ� >> ���̰���
//
//		}
//		else { // not find >> preLocation, Location ������ �̵�
//
//			// ������ ����
//			preLocation = Location;
//			Location = Location->next;
//
//			// moreToSearch ����
//			moreToSearch = (Location != NULL); // moreToSearch�� true(Location != NULL)�̸� >> while�� �ݺ�
//
//		}
//	}
//
//	if (found) return 1;	// success
//	else return 0;			// fail
//
//}


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


		//cout << endl << "check : SortedLinkedList>Add" << endl;
		///*cout << (preLocation == NULL) << endl;*/
		///*cout << (Location == NULL) << endl << endl;*/
		//if (Location == NULL) cout << "Location is NULL" << endl;
		//else cout << "Location is NOT NULL" << endl;


	}

	// list�� node�� �ϳ� �̻� ����Ǿ� �ִ� ���
	else {

		// getNextItem()�� ���� > preLocation, Location ������ ���Ž� �ʿ�
		ItemType dummy;

		// ���� ������ node�� �̵� �� newNode ����
		while (1) {

			GetNextItem(dummy);	// preLocation, Location ������ ���� >> ���� node�� �̵�

			if (Location->data > newNode->data) { // ����!


				// Ʋ����??????????
				/*preLocation = Location;*/



				if (preLocation == NULL) { // �� list�� �ƴϰ�, ���� �� node�� ������ �� >> ���� �� ����

					newNode->next = Location;
					startPoint = newNode;
					break;

				}
				else { // �� list�� �ƴϰ�, preLocation�ڿ� ���ο� node�� ������ �� >> �߰� ����

					newNode->next = Location;
					preLocation->next = newNode;
					break;

				}


				// Ʋ����
				/*Location = Location->next;
				break;*/



			}

			if (Location->next == NULL) { // Location �����Ͱ� ������ node�� ����Ű�� >> ���� �� ����

				// ������ node�� ���ο� node ����
				Location->next = newNode;
				break;

			}

		}

	}

	length++; // node�� add������ >> ��������

	//delete newNode;


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

	/*cout << endl << "check : SortedLinkedList > isEmpty" << endl;
	if (Location == NULL) {
		cout << "Location is NULL" << endl;
		cout << "EMPTY" << endl;
	}
	else {
		cout << "Location is NOT NULL" << endl;
		cout << "NOT EMPTY" << endl;
	}*/

	return (Location == NULL);
}

//template <class ItemType>
//void SortedLinkedList<ItemType>::findByPK(string _pk) {
//
//	ItemType list;
//
//
//}

//T* SortedLinkedList::getData() { if (Location != NULL) return &(Location->data); }
template <class ItemType>
ItemType* SortedLinkedList<ItemType>::GetDataLocation() {

	if (Location == NULL) return NULL;
	else return &(Location->data);

}


//template <class ItemType>
//int RetrieveByPk(string _pk) {
//
//	
//	ResetPointer();
//	Location = startPoint;
//
//	bool moreToSearch, found;
//	moreToSearch = (Location != NULL);
//	found = false;
//
//	ItemType dummy;
//	while (moreToSearch && !found) {
//
//		if (Location->data == item) { // pk ��ġ
//			found = true;
//			item = Location->data; // data�� �ִ� ���� >> item�� ����
//		}
//		else {
//
//			if (Location->next == NULL) break;	// Location->next == NULL�� ��� >> GetNextItem���� �̵��� pointer�� ����Ű�� data�� �������� �ʾ� error�߻�
//
//			GetNextItem(dummy);					// move preLocation, Location pointer
//			moreToSearch = (Location != NULL); // ���ŵ� pointer >> check moreToSearch
//		}
//
//	}
//
//	if (found) return 1;	// success
//	else return 0;			// fail
//
//
//
//}

//template <class ItemType>
//NodeType<ItemType>* SortedLinkedList<ItemType>::getNextLocation() {
//
//	return Location->next;
//
//}




#endif	// LINKED_LIST