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


// Class destructor : 리스트내의 모든 node 제거
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList(){
	MakeEmpty();
}

// 개수제한은 없지만, 실제 메모리가 가득 차서 더 이상 할당이 불가능한 경우 시스템 예외 처리
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

// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty() {
	
	DoublyNodeType<T>* tmpPtr;
	DoublyIterator<T> iter(*this); // iterator 객체의 생성자 > 현재리스트의 주소 넘김

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

		DoublyNodeType<T>* newNode = new DoublyNodeType<T>; // 새 노드 할당
		newNode->data = item;
		newNode->prev = nullptr;
		newNode->next = nullptr;
		
		if (startPtr == nullptr) { // 리스트가 비어있는 경우

			startPtr = newNode; // 시작포인터에 새노드 연결
			endPtr = startPtr;  // 끝포인터도 새노드 가리킴

		}
		else { // 리스트에 노드가 1개 이상 연결되어 있는 경우

			DoublyIterator<T> iter(*this); // pointer역할을 하는 iterator 객체 선언
			DoublyNodeType<T>* iterNode; // iterator로 DDL을 순회할 때 각각의 node를 가리킬 포인터

			while (iter.NotNull()) {

				iterNode = iter.currPtr; // GetCurrentNode는 return by value이므로 수정 및 실 메모리 접근 불가해서 사용 못함

				if (newNode->data < iterNode->data) { // 넣으려고 하는 게 더 작음

					// 현위치 앞에 연결 > 새노드를 기존노드에 연결
					newNode->next = iterNode;
					
					// 맨앞
					if (length == 1) {

						// 시작포인터로 새노드 가리킴
						startPtr = newNode;

					}

					// 중간
					else {

						// "새노드의 prev포인터"가 "현재위치의 이전노드"를 가리킴 (새노드가 앞노드)
						newNode->prev = iterNode->prev;

						// "현재위치의 이전노드의 next포인터"가 "새노드"를 가리킴 (앞노드가 새노드)
						newNode->prev->next = newNode;

					}

					// "현재위치의 prev포인터"가 "새노드"를 가리킴 (뒷노드가 새노드)
					iterNode->prev = newNode;
					break;

				}
				else {

					// 맨뒤
					if (!iter.NextNotNull()) { // 리스트의 마지막노드 일 때


						// "현재위치의 next포인터"가 "새노드"를 가리킴 > 새노드를 리스트 맨 뒤에 연결 (앞에서 뒤연결)
						iterNode->next = newNode;

						// 리스트 맨 뒤에 연결된 "새노드의 prev포인터"는 "현재노드"를 가리킴 (뒤에서 앞연결)
						newNode->prev = iterNode;

						// 끝포인터로 새노드 가리킴
						endPtr = newNode;
						
						// 삽입이 끝났으므로 while문 종료
						break;

					}
					else
						iter.Next(); // 리스트의 마지막노드가 아니므로 다음 노드로 이동
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

	DoublyIterator<T> iter(*this); // pointer역할을 하는 iterator 객체 선언
	bool found = false;
	int count = 0;	// 몇 번째에 위치하고 있는지 return하기 위해서
					// iterator를 이용하면서 currPtr을 동시에 사용할 수 없어서 count변수 사용 ????

	while (iter.NotNull()) { // 빈 리스트가 아니라면 탐색
		
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


// 특정 요소를 찾아 삭제하는 함수
template <typename T>
int DoublySortedLinkedList<T>::Delete(T data) {

	// 급해서 조교님 코드 복붙
	DoublyNodeType<T>* pNode = startPtr;
	int positionIndex = Retrieve(data);
	if (positionIndex) {
		for (int i = 1; i < positionIndex; i++) {
			pNode = pNode->next;
		}
		if (pNode->next != nullptr) {	// 끝이 아니면
			pNode->next->prev = pNode->prev;
		}
		else endPtr = pNode->prev;
		if (pNode->prev != nullptr) {	// 처음이 아니면
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
	int targetNodePos = Retrieve(data); // 삭제될 노드의 위치

	if (targetNodePos != 0) { // 삭제될 노드가 리스트에 존재한다면

	}
	*/

}

// 특정 요소를 찾아 새로운 내용으로 대치시키는 함수
template <typename T>
void DoublySortedLinkedList<T>::Replace(T data) {

	// 급해서 조교님 코드 복붙
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

	DoublyIterator<T> iter(*this); // pointer역할을 하는 iterator 객체 선언
	while (iter.NotNull()) {
		cout << iter.GetCurrentNode().data << endl;
		iter.Next();
		if (!iter.NextNotNull()) break;
	}

}


#endif	// LINKED_LIST