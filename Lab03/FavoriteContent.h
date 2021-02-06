#ifndef _FAVORIECONTENT_H
#define _FAVORIECONTENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"

using namespace std;

class FavoriteContent {
public:
	FavoriteContent();
	~FavoriteContent() {}

	/**
	*	@brief	Get content id.
	*	@pre	content id is set.
	*	@post	none.
	*	@return	content id.
	*/
	int GetId() const;

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

	bool operator<(FavoriteContent otherItem) const;
	bool operator>(FavoriteContent otherItem) const;
	bool operator==(FavoriteContent otherItem) const;
	void operator=(FavoriteContent otherItem);

	friend ostream& operator<<(ostream& outputStream, const FavoriteContent& item);

protected:
	int contentId;						// ÄÜÅÙÃ÷ ID (PK)
	string contentName;					// ÄÜÅÙÃ÷ ÆÄÀÏ¸í
	string eventName;					// ÀÌº¥Æ®¸í (ex : °íµîÇÐ±³ Á¹¾÷½Ä, 24¼¼ »ýÀÏ)
};

#endif _FAVORIECONTENT_H