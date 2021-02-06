#pragma once
#ifndef _FAVORIECONTENT_H
#define _FAVORIECONTENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"

using namespace std;

class FavoriteContent {
public:
	
	// Constructor
	FavoriteContent();


	// Destructor
	~FavoriteContent() {}


	/**
	*	@brief	Get content id.
	*	@pre	content id is set.
	*	@post	none.
	*	@return	content id.
	*/
	string GetId() const;


	/**
	*	@brief	Get content name.
	*	@pre	content name is set.
	*	@post	none.
	*	@return	content name.
	*/
	string GetName() const;


	/**
	*	@brief	Get event name.
	*	@pre	event name is set.
	*	@post	none.
	*	@return	event name.
	*/
	string GetEvent() const;


	/**
	*	@brief	Set content record.
	*	@pre	none.
	*	@post	content record is set.
	*	@param	inId	content id.
	*	@param	inName	content name.
	*	@param	inEvent	content event.
	*/
	void SetRecord(MultimediaContent _mc);


	/**
	*	@brief	Display an content record on screen.
	*	@pre	content record is set.
	*	@post	content record is on screen.
	*/
	void Display();


	/**
	*	@brief	operator < overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '<', false if not
	*/
	bool operator<(FavoriteContent otherItem) const;


	/**
	*	@brief	operator > overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '>', false if not
	*/
	bool operator>(FavoriteContent otherItem) const;


	/**
	*	@brief	operator == overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if this.id == data.id, false if not.
	*/
	bool operator==(FavoriteContent otherItem) const;


	/**
	*	@brief	operator = overloading
	*	@pre	two item types should be initialized.
	*	@param	item to copy
	*	@return	none
	*/
	void operator=(FavoriteContent otherItem);


	/**
	*	@brief	operator << overloading
	*	@pre	none
	*	@param	target item to cout
	*	@return	ostream& object
	*/
	friend ostream& operator<<(ostream& outputStream, const FavoriteContent& item);

protected:
	string contentId;					// ÄÜÅÙÃ÷ ID (PK)
	string contentName;					// ÄÜÅÙÃ÷ ÆÄÀÏ¸í
	string eventName;					// ÀÌº¥Æ®¸í (ex : °íµîÇÐ±³ Á¹¾÷½Ä, 24¼¼ »ýÀÏ)
};

#endif _FAVORIECONTENT_H