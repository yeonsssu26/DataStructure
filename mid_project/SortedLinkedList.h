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
//	// isFull 함수 구현하지 않음 > LinkedList 특성상 불필요
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

	/*bool isFull(); */// isFull 함수 구현하지 않음 >> LinkedList 특성상 불필요
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

	// 리스트내의 모든 node 제거
	MakeEmpty();

}

template <class ItemType>
void SortedLinkedList<ItemType>::MakeEmpty() {

	// 리스트내의 모든 노드 제거하고 리스트의 length를 초기화
	NodeType<ItemType>* tempPtr;

	// 리스트의 앞부터 삭제 >> node가 모두 삭제될 때까지 반복
	while (startPoint != NULL) {
		tempPtr = startPoint;			// 리스트 맨 앞의 node >> 삭제할 target node
		startPoint = tempPtr->next;		// 삭제할 node의 다음 node를 앞과 이어줌
		delete tempPtr;					// 삭제 먼저하면 dangling pointer가 발생할 수 있음 >> 마지막에 삭제!
	}

	length = 0;

}

template <class ItemType>
int SortedLinkedList<ItemType>::GetLength() const {
	return length;
}

template <class ItemType>
int SortedLinkedList<ItemType>::Add(ItemType item) {

	// preLocation, Location 포인터 초기화
	ResetPointer();

	// 리스트에 추가할 새로운 node 객체 선언 및 set up
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode->data = item;
	newNode->next = NULL;


	// 빈 list (node가 하나도 연결되어 있지 않은 list)
	if (length == 0) {
		startPoint = newNode; // list 맨 앞에 newNode 연결

		preLocation = Location;
		Location = startPoint;

	}

	// list에 node가 하나 이상 연결되어 있는 경우
	else {

		// getNextItem()을 통해 > preLocation, Location 포인터 갱신시 필요
		ItemType dummy;

		// 가장 마지막 node로 이동 후 newNode 삽입
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

	length++; // node를 add했으니 >> 길이증가
	
	return 1;

}

template <class ItemType>
int SortedLinkedList<ItemType>::Delete(ItemType item) {

	// preLocation, Location 포인터 초기화
	ResetPointer();
	Location = startPoint;

	bool moreToSearch, found;
	moreToSearch = (Location != NULL); // true
	found = false;

	while (moreToSearch && !found) { // list의 끝이 아니면서, 아직 찾지 못했으면 >> 반복한다


		if (Location->data == item) { // find >> 현재 가리키는 원소의 값과 item의 값이 일치할 때

			found = true;

			if (preLocation == NULL) { // 삭제할 항목 이전에 다른 원소가 없을 때

				startPoint = Location->next;	// 삭제한 항목 다음 원소를 첫번째 원소로 한다.

			}
			else {

				preLocation->next = Location->next;	// 삭제할 node의 다음 node를 가리킴
				delete Location;	// node 삭제

			}

			length--; // 삭제했으므로 >> 길이감소

		}
		else { // not find >> preLocation, Location 포인터 이동

			// 포인터 갱신
			preLocation = Location;
			Location = Location->next;

			// moreToSearch 갱신
			moreToSearch = (Location != NULL); // moreToSearch가 true(Location != NULL)이면 >> while문 반복

		}
	}

	if (found) return 1;	// success
	else return 0;			// fail

}

template <class ItemType>
int SortedLinkedList<ItemType>::Replace(ItemType item) {

	// preLocation, Location 포인터 초기화
	ResetPointer();
	Location = startPoint;

	bool moreToSearch, found;
	moreToSearch = (Location != NULL); // true;
	found = false;

	ItemType dummy;

	while (moreToSearch && !found) {
		if (Location->data == item) {
			found = true;	// 해당 위치 찾음
			Location->data = item; // 치환
		}
		else {
			GetNextItem(dummy); // move preLocation and Location pointer
			moreToSearch = (Location != NULL); // 갱신된 포인터 >> check moreToSearch
		}
	}

	if (found) return 1;	// replace success
	else return 0;			// replace fail

}


template <class ItemType>
int SortedLinkedList<ItemType>::Retrieve(ItemType& item) { // Node의 pk가 알치하면 >> item에 Node의 data 복사 >> call-by-ref

	ResetPointer();
	Location = startPoint;

	bool moreToSearch, found;
	moreToSearch = (Location != NULL);
	found = false;

	ItemType dummy;
	while (moreToSearch && !found) {

		if (Location->data == item) { // pk 일치
			found = true;
			item = Location->data; // data에 있는 내용 >> item에 복사
		}
		else {

			if (Location->next == NULL) break;	// Location->next == NULL일 경우 >> GetNextItem에서 이동된 pointer가 가리키는 data가 존재하지 않아 error발생

			GetNextItem(dummy);					// move preLocation, Location pointer
			moreToSearch = (Location != NULL); // 갱신된 pointer >> check moreToSearch
		}

	}

	if (found) return 1;	// success
	else return 0;			// fail


}

template <class ItemType>
void SortedLinkedList<ItemType>::ResetPointer() {

	// preLocation, Location 포인터변수 초기화
	preLocation = NULL;
	Location = NULL;

}

template <class ItemType>
void SortedLinkedList<ItemType>::GetNextItem(ItemType& item) { // preLocation과 Location 포인터 둘다 이동시킨다 (조교님코드와 상이)

	// Location이 NULL일 때 아직 어떠한 node도 가리키지 않는 상태이므로 >> 다음 node인 1번 node를 가리키게 함
	if (Location == NULL) {
		Location = startPoint;
	}

	// Location이 다음 node를 가리키게 함
	else {

		// prelocation부터 갱신
		preLocation = Location;

		// Location 이동
		Location = Location->next;
	}

	// item에 이동된 Location의 data를 복사
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