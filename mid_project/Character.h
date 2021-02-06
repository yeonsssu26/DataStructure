#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"
#include "Event.h"

using namespace std;

class Character {
public:

	// Constructor
	Character(void);


	// Destructor
	~Character() {}


	/**
	*	@brief	Add new brief info of Multimedia Contents into CharacterList.
	*	@pre	CharacterList should be initialized.
	*	@post	new MC_Info is added into the CharacterList.
	*	@return	none
	*/
	void Add(MultimediaContent _mc);


	/**
	*	@brief	delete the given brief info of Multimedia Contents into CharacterList.
	*	@pre	CharacterList should be initialized.
	*	@post	the given MC_Info is deleted out the CharacterList.
	*	@return	none
	*/
	void Delete(MultimediaContent _mc);


	/**
	*	@brief	replace the given brief info of Multimedia Contents in the CharacterList.
	*	@pre	CharacterList should be initialized.
	*	@post	the given MC_Info is replaced out the CharacterList.
	*	@return	none
	*/
	void Replace(MultimediaContent _mc);


	/**
	*	@brief	search the given brief info of Multimedia Contents in the CharacterList.
	*	@pre	CharacterList should be initialized.
	*	@post	the given MC_Info is replaced out the list.
	*	@return	return 1 if success to find, if not return 0
	*/
	int Retrieve(string ContentName);


	/**
	*	@brief	Set character name from keyboard.
	*	@pre	none.
	*	@post	character name is set.
	*   @return	none
	*/
	void SetCharacterFromKB();


	/**
	*	@brief	Set Character method value by Multimedia Contents
	*	@pre	none
	*	@post	character name, character List
	*	@return	none
	*/
	void SetRecord(MultimediaContent _mc);


	/**
	*	@brief	Get pointer of Character List
	*	@pre	CharacterList should be initialized.
	*	@post	none
	*	@return pointer of Character List
	*/
	MC_Info* GetCharacterList();


	/**
	*	@brief	Get characterName(pk) of Character object
	*	@pre	CharacterList should be initialized.
	*	@post	none
	*	@return	Character name (pk)
	*/
	string GetCharacterName();

	
	/**
	*	@brief	Get CharacterList length which means number of MC_info
	*	@pre	CharacterList should be initialized.
	*	@post	none
	*	@return	length of CharacterList
	*/
	int GetMCcount();


	/**
	*	@brief	operator < overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '<', false if not
	*/
	bool operator<(Character otherItem) const;


	/**
	*	@brief	operator > overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if '>', false if not
	*/
	bool operator>(Character otherItem) const;
	
	
	/**
	*	@brief	operator == overloading
	*	@pre	two item types should be initialized.
	*	@param	target item for comparing.
	*	@return	return true if this.id == data.id, false if not.
	*/
	bool operator==(Character otherItem) const;


	/**
	*	@brief	operator = overloading
	*	@pre	two item types should be initialized.
	*	@param	item to copy
	*	@return	none
	*/
	void operator=(Character otherItem);


	/**
	*	@brief	operator << overloading
	*	@pre	none
	*	@param	target item to cout
	*	@return	ostream& object
	*/
	friend ostream& operator<<(ostream& outputStream, const Character& item);

protected:
	int countMC;				// length of CharacterList
	string CharacterName;		// Character Name (pk)
	MC_Info* CharacterList;		// 해당 Character를 갖는 MC_List의 핵심 info 저장 (MC id, MC name)

};

#endif _CHARACTER_H
