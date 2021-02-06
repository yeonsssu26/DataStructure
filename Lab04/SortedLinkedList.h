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

//template <class ItemType>
//int SortedLinkedList<ItemType>::Add(ItemType item) {
//
//	// preLocation, Location 포인터 초기화
//	ResetPointer();
//
//	// 리스트에 추가할 새로운 node 객체 선언 및 set up
//	NodeType<ItemType>* newNode = new NodeType<ItemType>;
//	newNode->data = item;
//	newNode->next = NULL;
//
//
//	// 빈 list (node가 하나도 연결되어 있지 않은 list)
//	if (length == 0) {
//		startPoint = newNode; // list 맨 앞에 newNode 연결
//	}
//
//	// list에 node가 하나 이상 연결되어 있는 경우
//	else {
//
//		// getNextItem()을 통해 > preLocation, Location 포인터 갱신시 필요
//		ItemType dummy;
//
//		// 가장 마지막 node로 이동 후 newNode 삽입
//		while (1) {
//
//			GetNextItem(dummy);	// preLocation, Location 포인터 갱신 >> 다음 node로 이동
//
//			if (Location->data > newNode->data) { // 연결!
//
//
//				/*preLocation = Location;*/
//
//
//
//				if (preLocation == NULL) { // 빈 list가 아니고, 제일 앞 node에 삽입할 때 >> 제일 앞 삽입
//
//					newNode->next = Location;
//					startPoint = newNode;
//					//break;
//
//				}
//				else { // 빈 list가 아니고, preLocation뒤에 새로운 node를 삽입할 때 >> 중간 삽입
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
//			if (Location->next == NULL) { // Location 포인터가 마지막 node를 가리키면 >> 가장 끝 삽입
//
//				// 마지막 node와 새로운 node 연결
//				Location->next = newNode;
//				break;
//
//			}
//
//		}
//
//	}
//
//	length++; // node를 add했으니 >> 길이증가
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
//	// preLocation, Location 포인터 초기화
//	ResetPointer();
//	Location = startPoint;
//
//	bool moreToSearch, found;
//	moreToSearch = (Location != NULL); // true
//	found = false;
//
//	while (moreToSearch && !found) { // list의 끝이 아니면서, 아직 찾지 못했으면 >> 반복한다
//
//		if (Location->data == item) { // find >> 현재 가리키는 원소의 값과 item의 값이 일치할 때
//
//			found = true;
//
//			if (preLocation == NULL) { // 삭제할 항목 이전에 다른 원소가 없을 때
//
//				startPoint = Location->next;	// 삭제한 항목 다음 원소를 첫번째 원소로 한다.
//
//			}
//			else {
//
//				preLocation->next = Location->next;	// 삭제할 node의 다음 node를 가리킴
//				delete Location;	// node 삭제
//
//			}
//
//			length--; // 삭제했으므로 >> 길이감소
//
//		}
//		else { // not find >> preLocation, Location 포인터 이동
//
//			// 포인터 갱신
//			preLocation = Location;
//			Location = Location->next;
//
//			// moreToSearch 갱신
//			moreToSearch = (Location != NULL); // moreToSearch가 true(Location != NULL)이면 >> while문 반복
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


		//cout << endl << "check : SortedLinkedList>Add" << endl;
		///*cout << (preLocation == NULL) << endl;*/
		///*cout << (Location == NULL) << endl << endl;*/
		//if (Location == NULL) cout << "Location is NULL" << endl;
		//else cout << "Location is NOT NULL" << endl;


	}

	// list에 node가 하나 이상 연결되어 있는 경우
	else {

		// getNextItem()을 통해 > preLocation, Location 포인터 갱신시 필요
		ItemType dummy;

		// 가장 마지막 node로 이동 후 newNode 삽입
		while (1) {

			GetNextItem(dummy);	// preLocation, Location 포인터 갱신 >> 다음 node로 이동

			if (Location->data > newNode->data) { // 연결!


				// 틀린듯??????????
				/*preLocation = Location;*/



				if (preLocation == NULL) { // 빈 list가 아니고, 제일 앞 node에 삽입할 때 >> 제일 앞 삽입

					newNode->next = Location;
					startPoint = newNode;
					break;

				}
				else { // 빈 list가 아니고, preLocation뒤에 새로운 node를 삽입할 때 >> 중간 삽입

					newNode->next = Location;
					preLocation->next = newNode;
					break;

				}


				// 틀린듯
				/*Location = Location->next;
				break;*/



			}

			if (Location->next == NULL) { // Location 포인터가 마지막 node를 가리키면 >> 가장 끝 삽입

				// 마지막 node와 새로운 node 연결
				Location->next = newNode;
				break;

			}

		}

	}

	length++; // node를 add했으니 >> 길이증가

	//delete newNode;


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
//		if (Location->data == item) { // pk 일치
//			found = true;
//			item = Location->data; // data에 있는 내용 >> item에 복사
//		}
//		else {
//
//			if (Location->next == NULL) break;	// Location->next == NULL일 경우 >> GetNextItem에서 이동된 pointer가 가리키는 data가 존재하지 않아 error발생
//
//			GetNextItem(dummy);					// move preLocation, Location pointer
//			moreToSearch = (Location != NULL); // 갱신된 pointer >> check moreToSearch
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