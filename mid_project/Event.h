#pragma once

#ifndef _EVENT_H
#define _EVENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"

#define maxsize 100

using namespace std;

struct MC_Info{
	string pk;
	string ContentName;
};

class Event {
public:

	// Constructor
	Event(void);


	// Destructor
	~Event() {}


	/**
	*	@brief	Add new brief info of Multimedia Contents into EventList.
	*	@pre	EventList should be initialized.
	*	@post	new MC_Info is added into the EventList.
	*	@return	none
	*/
	void Add(MultimediaContent _mc);


	/**
	*	@brief	delete the given brief info of Multimedia Contents into EventList.
	*	@pre	EventList should be initialized.
	*	@post	the given MC_Info is deleted out the EventList.
	*	@return	none
	*/
	void Delete(MultimediaContent _mc);


	/**
	*	@brief	replace the given brief info of Multimedia Contents in the EventList.
	*	@pre	EventList should be initialized.
	*	@post	the given MC_Info is replaced out the list.
	*	@return	none
	*/
	void Replace(MultimediaContent _mc);


	/**
	*	@brief	search the given brief info of Multimedia Contents in the EventList.
	*	@pre	EventList should be initialized.
	*	@post	the given MC_Info is replaced out the list.
	*	@return	return 1 if success to find, if not return 0
	*/
	int Retrieve(string pk);


	/**
	*	@brief	Set event name from keyboard.
	*	@pre	none.
	*	@post	event name is set.
	*   @return	none
	*/
	void SetEventFromKB();


	/**
	*	@brief	Set Event method value by Multimedia Contents
	*	@pre	none
	*	@post	event name, event story, eventList
	*	@return	none
	*/
	void SetRecord(MultimediaContent _mc);


	/**
	*	@brief	Get pointer of Event List
	*	@pre	EventList should be initialized.
	*	@post	none
	*	@return pointer of Event List
	*/
	MC_Info* GetEventList();


	/**
	*	@brief	Get EventName(pk) of Event object
	*	@pre	EventList should be initialized.
	*	@post	none
	*	@return	Event name (pk)
	*/
	string GetEventName();


	/**
	*	@brief	Get Event Desciprtion
	*	@pre	EventList should be initialized.
	*	@post	none
	*	@return	EventStory
	*/
	string GetEventStory();


	/**
	*	@brief	Get EventList length which means number of MC_info
	*	@pre	EventList should be initialized.
	*	@post	none
	*	@return	length of EventList
	*/
	int GetMCcount();


	/**
	*	@brief	operator < overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '<', false if not
	*/
	bool operator<(Event otherItem) const;


	/**
	*	@brief	operator > overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '>', false if not
	*/
	bool operator>(Event otherItem) const;


	/**
	*	@brief	operator == overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if this.id == data.id, false if not.
	*/
	bool operator==(Event otherItem) const;


	/**
	*	@brief	operator = overloading
	*	@pre	two item types should be initialized.
	*	@param	item to copy
	*	@return	none
	*/
	void operator=(Event otherItem);


	/**
	*	@brief	operator << overloading
	*	@pre	none
	*	@param	target item to cout
	*	@return	ostream& object
	*/
	friend ostream& operator<<(ostream& outputStream, const Event& item);

protected:
	int countMC;			// length of EventList
	string EventName;		// Event Name (pk)
	string EventStory;		// Event Description
	MC_Info* EventList;		// 해당 Event를 갖는 MC_List의 핵심 info 저장 (MC id, MC name)

};

#endif _EVENT_H