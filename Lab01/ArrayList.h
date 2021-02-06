#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
class ArrayList {
public:

	/**
	*	default constructor.
	*/
	ArrayList() {
		m_Length = 0;
		ResetPointer();
	}

	/**
	*	destructor.
	*/
	~ArrayList() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetPointer();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list is empty, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Get a index of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	index of records in current list.
	*/
	int GetIndex(ItemType& data);

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(ItemType& data);

	/**
	*	@brief	search the given data in the list
	*	@pre	list
	*	@post	none
	*	@param	data
	*	@return	if there is the given data in the list, print info of the data and return the index of the data, otherwise return -1
	*/
	int Retrieve(ItemType data);

	/**
	*	@brief	add the given data in the list
	*	@pre	list
	*	@post	list which is added the new data
	*	@param	data to be added
	*	@return	if the list is not full and the given data is not existed, return the index of the added data, otherwise return -1
	*/
	int Add(ItemType data);

	/**
	*	@brief	delete the given data in the list
	*	@pre	list
	*	@post	list which is deleted the given data
	*	@param	data to be deleted
	*	@return	if the list is not empty and the given data is existed, return the index of the deleted data, otherwise return -1
	*/
	int Delete(ItemType data);

	/**
	*	@brief	replace the given data in the list
	*	@pre	list
	*	@post	list which is replaced the given data
	*	@param	data to be replaced
	*	@return	if the list is not empty and the given data is existed, return the index of the replaced data, otherwise return -1
	*/
	int Replace(ItemType data);

protected:
	ItemType m_Array[MAXSIZE];		// ���ڵ带 ������ ItemType ��ü�迭
	int m_Length;					// ����Ʈ�� ����� ���ڵ� ��
	int m_CurPointer;				// current pointer

};
#endif _ARRAYLISH_H