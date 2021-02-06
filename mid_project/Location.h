#pragma once

#ifndef _LOCATION_H
#define _LOCATION_H

#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"
#include "Event.h"

using namespace std;

class Location {
public:
	// Constructor
	Location(void);


	// Destructor
	~Location() {}


	/**
	*	@brief	Add new brief info of Multimedia Contents into LocationList.
	*	@pre	LocationList should be initialized.
	*	@post	new MC_Info is added into the LocationList.
	*	@return	none
	*/
	void Add(MultimediaContent _mc);


	/**
	*	@brief	delete the given brief info of Multimedia Contents into LocationList.
	*	@pre	LocationList should be initialized.
	*	@post	the given MC_Info is deleted out the LocationList.
	*	@return	none
	*/
	void Delete(MultimediaContent _mc);


	/**
	*	@brief	replace the given brief info of Multimedia Contents in the CharacterList.
	*	@pre	LocationList should be initialized.
	*	@post	the given MC_Info is replaced out the LocationList.
	*	@return	none
	*/
	void Replace(MultimediaContent _mc);


	/**
	*	@brief	search the given brief info of Multimedia Contents in the LocationList.
	*	@pre	LocationList should be initialized.
	*	@post	the given MC_Info is replaced out the list.
	*	@return	return 1 if success to find, if not return 0
	*/
	int Retrieve(string pk);


	/**
	*	@brief	Set location name from keyboard.
	*	@pre	none.
	*	@post	location name is set.
	*   @return	none
	*/
	void SetLocationFromKB();


	/**
	*	@brief	Set Location method value by Multimedia Contents
	*	@pre	none
	*	@post	location name, location List
	*	@return	none
	*/
	void SetRecord(MultimediaContent _mc);


	/**
	*	@brief	Get pointer of Location List
	*	@pre	LocationList should be initialized.
	*	@post	none
	*	@return pointer of Location List
	*/
	MC_Info* GetLocationList();


	/**
	*	@brief	Get LocationName(pk) of Location object
	*	@pre	LocationList should be initialized.
	*	@post	none
	*	@return	Location name (pk)
	*/
	string GetLocationName();


	/**
	*	@brief	Get LocationList length which means number of MC_info
	*	@pre	LocationList should be initialized.
	*	@post	none
	*	@return	length of LocationList
	*/
	int GetMCcount();


	/**
	*	@brief	operator < overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '<', false if not
	*/
	bool operator<(Location otherItem) const;


	/**
	*	@brief	operator > overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '>', false if not
	*/
	bool operator>(Location otherItem) const;


	/**
	*	@brief	operator == overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if this.id == data.id, false if not.
	*/
	bool operator==(Location otherItem) const;


	/**
	*	@brief	operator = overloading
	*	@pre	two item types should be initialized.
	*	@param	item to copy
	*	@return	none
	*/
	void operator=(Location otherItem);


	/**
	*	@brief	operator << overloading
	*	@pre	none
	*	@param	target item to cout
	*	@return	ostream& object
	*/
	friend ostream& operator<<(ostream& outputStream, const Location& item);

protected:
	int countMC;				// length of LocationList
	string LocationName;		// Location Name (pk)
	MC_Info* LocationList;		// 해당 Location를 갖는 MC_List의 핵심 info 저장 (MC id, MC name)

};

#endif _LOCATION_H
