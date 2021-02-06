#include "ArrayList.h"

void ArrayList::MakeEmpty() {
	m_Length = 0;
}

void ArrayList::ResetPointer() {
	m_CurPointer = -1;
}

bool ArrayList::IsFull() {
	if (m_Length >= MAXSIZE)
		return true;
	return false;
}

bool ArrayList::IsEmpty() {
	if (m_Length == 0)
		return true;
	return false;
}

int ArrayList::GetLength() {
	return m_Length;
}

int ArrayList::GetIndex(ItemType& data) {
	for (int i = 0; i < m_Length; i++) {
		if (data.GetId() == m_Array[i].GetId())
			return i; // 해당 인덱스 return
	}
	return -1; // cannot find
}

int ArrayList::GetNextItem(ItemType& nextData) {

	m_CurPointer++; // move the iterator to the next item

	if (m_CurPointer != MAXSIZE) {
		nextData = m_Array[m_CurPointer]; // get the next item
		return m_CurPointer; // return the index of the next item
	}
	return -1; // if fail to get the next next item, return -1
}

int ArrayList::Retrieve(ItemType data) {

	ResetPointer(); // m_CurPointer = -1
	ItemType currData;

	int currIdx = GetNextItem(currData); // m_CurPointer = 0
	int len = GetLength();

	// find
	while (currIdx != -1 && currIdx < len) {
		if (currData.CompareByID(data) == EQUAL) // currData.getId() == data.getId()
			return currIdx; // success to search
		else // currData.getId() != data.getId()
			currIdx = GetNextItem(currData); // move the iterator to the next item
	}

	return -1; // fail to search the given data
}

int ArrayList::Add(ItemType data) {

	int checkExist = Retrieve(data); // check already exist
	int addIdx = -1;

	if (checkExist == -1) { // can add
		m_Array[m_Length] = data; // data를 list의 가장 끝에 삽입
		addIdx = m_Length++; // 성공여부를 return하기 위해 삽입에 성공했을 경우, 삽입위치를 addIdx에 저장하고
							 // 전체길이를 증가시킴
	}

	return addIdx; // -1 : fail // else : success
}

int ArrayList::Delete(ItemType data) {

	int deleteIdx = Retrieve(data);

	if (deleteIdx != -1) { // find
		m_Array[deleteIdx] = m_Array[m_Length - 1]; // 맨 뒤에 있는 레코드를 삭제할 레코드의 인덱스로 옮김
		m_Length--; // 전체 길이를 줄임
	}

	return deleteIdx; // -1 : fail // else : success
}

int ArrayList::Replace(ItemType data) {

	int replaceIdx = Retrieve(data);

	if (replaceIdx != -1) { // find
		m_Array[replaceIdx] = data; // replace
	}

	return replaceIdx; // -1 : fail // else : success
}