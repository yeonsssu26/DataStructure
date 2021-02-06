/////////////////////////////////
//// Rearrange 함수 추가해야함////
/////////////////////////////////

#ifndef _EVENT_H
#define _EVENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"

#define maxsize 5

using namespace std;

struct MC_Info {
	string pk;
	string ContentName;
};

class Event {
public:
	Event(void);
	~Event();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	none
	*/
	void Add(MultimediaContent _mc);

	/**
	*	@brief	delete the given record into list.
	*	@pre	list should be initialized.
	*	@post	the given record is deleted out the list.
	*	@return	none
	*/
	void Delete(MultimediaContent _mc);

	/**
	*	@brief	replace the given record in the list.
	*	@pre	list should be initialized.
	*	@post	the given record is replaced out the list.
	*	@return	none
	*/
	void Replace(MultimediaContent _mc);
	int Retrieve(string pk);
	void Print();

	void SetEventFromKB();
	void SetRecord(MultimediaContent _mc);

	MC_Info* GetEventList();
	string GetPK();
	string GetEventName();
	string GetEventStory();
	int GetLength();
	int GetMCcount();

	bool operator<(Event otherItem) const;
	bool operator>(Event otherItem) const;
	bool operator==(Event otherItem) const;
	void operator=(Event otherItem);

	friend ostream& operator<<(ostream& outputStream, const Event& item);

protected:
	int countMC;			// length
	string eventName;		// pk
	string eventStory;
	MC_Info* EventList;		// 해당 Event를 갖는 MC_List의 핵심 info 저장 (MC id, MC name)
};

#endif _EVENT_H
