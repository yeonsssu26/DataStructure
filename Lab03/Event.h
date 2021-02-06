#ifndef _EVENT_H
#define _EVENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"

#define maxsize 5

using namespace std;

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
	void Print();

protected:
	int countContent;	// length
	string eventName;
	string eventStory;
	string* EventList;
};

#endif _EVENT_H