#include "SortedList.h"

void SortedList::MakeEmpty() {
	m_Length = 0;
}

void SortedList::ResetPointer() {
	m_CurPointer = -1;
}

bool SortedList::IsFull() {
	if (m_Length >= MAXSIZE)
		return true;
	return false;
}

bool SortedList::IsEmpty() {
	if (m_Length == 0)
		return true;
	return false;
}

int SortedList::GetLength() {
	return m_Length;
}

int SortedList::GetIndex(ItemType& data) {
	for (int i = 0; i < m_Length; i++) {
		if (data.GetId() == m_Array[i].GetId())
			return i; // 해당 인덱스 return
	}
	return -1; // cannot find
}

int SortedList::GetNextItem(ItemType& nextData) {

	m_CurPointer++; // move the iterator to the next item

	if (m_CurPointer != MAXSIZE) {
		nextData = m_Array[m_CurPointer]; // get the next item
		return m_CurPointer; // return the index of the next item
	}

	return -1;// if fail to get the next next item, return -1
}

int SortedList::Retrieve_SequentialSearch(ItemType& searchData) {
	
	this->ResetPointer(); // m_CurPointer = -1

	ItemType data;
	int currIdx = this->GetNextItem(data); // m_CurPointer = 0

	bool moreToSearch = (currIdx < m_Length);
	bool found = false;

	while (currIdx != -1 && moreToSearch) {

		if (searchData < data) { // item is not in the list
								 // check case LESS : comparison을 줄일 수 있음
								 // LESS check 안하면 작아서 없는데 끝까지 searching하게 됨
			return -1;
		}
		else if (searchData > data) { // continue to find
			currIdx = this->GetNextItem(data);
			moreToSearch = (currIdx < m_Length);
		}
		else if (searchData == data) { // find
			searchData = data; // call-by-ref // operator overloading 
			found = true;
			break;
		}
	}

	if (found == false) {
		return -1; // fail
	}
	else {
		searchData = data;
		return 1; // success
	}
}

int SortedList::Retrieve_BinarySearch(ItemType& searchData) {
	int first, last, mid;
	first = 0; last = m_Length - 1;

	bool moreToSearch = (first <= last); // true
	bool found = false;
	ItemType data;

	while (moreToSearch && !found) { // 둘 중 하나만 false만 이어도 break

		mid = (first + last) / 2;
		data = m_Array[mid];

		if (searchData < data) { // LESS
			last = mid - 1;
		}
		else if (searchData > data) { // GREATER
			first = mid + 1;
		}
		else if (searchData == data) { // find
			searchData = data;
			found = true;
		}
		moreToSearch = (first <= last); // check more to search 
	}
	if (found) return 1; // success
	else return -1; // fail
}

int SortedList::Add(ItemType addData) {

	if (this->IsFull()) return -2; // check is the list full

	if (this->IsEmpty()) { // if the list is empty

		m_Array[0] = addData; // add the given data to the index 0
		m_Length++; // list 전체 길이 증가

		return 1; // success
	}

	//int currIdx = 0;
	this->ResetPointer(); // m_Array의 m_curPointer = -1로 초기화

	ItemType data; // m_Array의 레코드 값을 하나씩 받을 tmp 변수
	int currIdx = this->GetNextItem(data); // m_curPointer = 0

	bool moreToSearch = (currIdx < m_Length); // moretToSearch = true

	while (moreToSearch && data.GetId() != -1) {

		if (addData == data) { // 이미 List에 있는 data는 추가하지 않는다
			return -1; // fail to add
		}
		else if (addData > data) { // currIdx++
			currIdx = this->GetNextItem(data);
		}
		else if (addData < data) {
			moreToSearch = (currIdx < m_Length);
			break;
		}
	}


	if (currIdx == -1) {
		m_Array[m_Length] = addData; // 맨뒤에 add
	}
	else {

		// 뒤로 한칸씩 밀고
		for (int i = m_Length; i > currIdx; i--) {
			m_Array[i] = m_Array[i - 1];
		}

		// add
		m_Array[currIdx] = addData;

	}

	// 전체 길이 증가
	this->m_Length++;

	return 1; // success
}

int SortedList::Delete(ItemType data) {

	if (IsEmpty()) return -2; // fail : empty list

	this->ResetPointer();
	ItemType currItem;
	int currIdx = this->GetNextItem(currItem);
	int len = this->GetLength();

	while (currIdx != -1 && currIdx < len) {
		if (currItem == data) {

			// 땡겨서 삭제 : 한 칸씩 앞으로 옮기면 삭제됨
			for (int i = currIdx; i < len; i++) {
				m_Array[i] = m_Array[i + 1];
			}

			// 전체길이 줄이기
			this->m_Length--;

			return 1; // success
		}
		else {
			currIdx = this->GetNextItem(currItem);
		}
	}

	return -1; // fail : not exist
}

int SortedList::Replace(ItemType data) {

	if (IsEmpty()) return -2; // fail : empty list

	this->ResetPointer(); // m_Array의 m_curPointer = -1로 초기화
	ItemType currData; // m_Array의 레코드 값을 하나씩 받을 tmp 변수
	int currIdx = this->GetNextItem(currData); // m_curPointer = 0

	bool moreToSearch = (currIdx < m_Length); // moretToSearch = true

	while (moreToSearch && currIdx != -1) {

		if (currData == data) { // currData.getId() == data.getId()

			m_Array[currIdx] = data; // replace
			return 1;
		}
		else {
			currIdx = this->GetNextItem(currData); // currIdx++
		}
	}

	return -1; // fail
}