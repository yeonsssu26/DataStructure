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
			return i; // �ش� �ε��� return
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
		m_Array[m_Length] = data; // data�� list�� ���� ���� ����
		addIdx = m_Length++; // �������θ� return�ϱ� ���� ���Կ� �������� ���, ������ġ�� addIdx�� �����ϰ�
							 // ��ü���̸� ������Ŵ
	}

	return addIdx; // -1 : fail // else : success
}

int ArrayList::Delete(ItemType data) {

	int deleteIdx = Retrieve(data);

	if (deleteIdx != -1) { // find
		m_Array[deleteIdx] = m_Array[m_Length - 1]; // �� �ڿ� �ִ� ���ڵ带 ������ ���ڵ��� �ε����� �ű�
		m_Length--; // ��ü ���̸� ����
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