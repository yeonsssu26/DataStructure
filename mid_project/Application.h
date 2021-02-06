#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <string>

#include "MultimediaContent.h"
#include "FavoriteContent.h"
#include "SortedLinkedList.h"
#include "Character.h"
#include "Event.h"
#include "Location.h"

using namespace std;

/**
*	application class for item management simply.
*/
class Application {
public:

	//Constructor
	Application();


	//Destructor
	~Application() {}


	//// program �⺻ ���� �Լ� /////////////////////////////////////////////////////////////////////////

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();


	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();


	// Multimedia Contents ���� �Լ�

	/**
	*	@brief	Add new Multimedia Content into list.
	*	@pre	list should be initialized.
	*	@post	new Multimedia Content is added into the list.
	*	@return	none
	*/
	void AddMC();


	/**
	*	@brief	delete the given Multimedia Content into list.
	*	@pre	list should be initialized.
	*	@post	the given Multimedia Content is deleted out the list.
	*	@return	none
	*/
	void DeleteMC();


	/**
	*	@brief	replace the given Multimedia Content in the list.
	*	@pre	list should be initialized.
	*	@post	the given Multimedia Content is replaced from the list.
	*	@return	none
	*/
	void ReplaceMC();


	/**
	*	@brief	make Multimedia Content List Empty
	*	@pre	none
	*	@post	Multimedia Content List doesn't have node
	*	@return	none
	*/
	void MakeEmptyMC();


	/*
	*	@brief	Display All Multimedia Content in the list on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	none
	*/
	void displayAllMC();  


	//// Favorite Contents ���� �Լ� /////////////////////////////////////////////////////////////////////////

	/**
	*	@brief	Add new Favorite Content into list.
	*	@pre	list should be initialized.
	*	@post	new Favorite Content is added into the list.
	*	@return	none
	*/
	void AddFC();


	/**
	*	@brief	delete the given Favorite Content into list.
	*	@pre	list should be initialized.
	*	@post	the given Favorite Content is deleted out the list.
	*	@return	none
	*/
	void DeleteFC();

	/**
	*	@brief	make Favorite Content List Empty
	*	@pre	none
	*	@post	Favorite Content List doesn't have node
	*	@return	none
	*/
	void MakeEmptyFCPic();
	void MakeEmptyFCMov();


	/*
	*	@brief	Display All Favorite Content in the list on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	none
	*/
	void displayAllFCPic();
	void displayAllFCMov();


	//// Event ���� �Լ� /////////////////////////////////////////////////////////////////////////

	/*
	*	@brief	copy Event if event name is same
	*	@pre	EventList should exist
	*	@post	Event object is copyed
	*	@return	if find the event and success to copy the event then return 1, else return 0
	*/
	int GetEvent(Event& _event);


	/*
	*	@brief	check if event name exist
	*	@pre	EventList should exist
	*	@post	none.
	*	@return	if find the event then return 1, else return 0
	*/
	int checkEventName(string _eventName);
	

	/*
	*	@brief	find event by event name and display detail info of all Multimedia Contents those in Event object
	*	@pre	EventList should exist
	*	@post	none.
	*	@return	none
	*/
	void FindEventDisplayMC();


	/*
	*	@brief	Display one Event in the list on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	none
	*/
	void PrintEvent();


	//// Character ���� �Լ� /////////////////////////////////////////////////////////////////////////

	/*
	*	@brief	copy Character if character name is same
	*	@pre	CharacterList should exist
	*	@post	Character object is copyed
	*	@return	if find the character and success to copy the character then return 1, else return 0
	*/
	int GetCharacter(Character& _character);


	/*
	*	@brief	check if event name exist
	*	@pre	EventList should exist
	*	@post	none.
	*	@return	if find the event then return 1, else return 0
	*/
	int checkCharacterName(string _characterName);


	/*
	*	@brief	find event by event name and display detail info of all Multimedia Contents those in Character object
	*	@pre	CharacterList should exist
	*	@post	none.
	*	@return	none
	*/
	void FindCharacterDisplayMC();


	/*
	*	@brief	Display one Character in the list on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	none
	*/
	void PrintCharacter();


	//// Location ���� �Լ� /////////////////////////////////////////////////////////////////////////

	/*
	*	@brief	copy Location if location name is same
	*	@pre	LocationList should exist
	*	@post	Location object is copyed
	*	@return	if find the location and success to copy the location then return 1, else return 0
	*/
	int GetLocation(Location& _location);


	/*
	*	@brief	check if location name exist
	*	@pre	LocationList should exist
	*	@post	none.
	*	@return	if find the location then return 1, else return 0
	*/
	int checkLocationName(string _locationName);


	/*
	*	@brief	find location by location name and display detail info of all Multimedia Contents those in Location object
	*	@pre	LocationList should exist
	*	@post	none.
	*	@return	none
	*/
	void FindLocationDisplayMC();


	/*
	*	@brief	Display one Location in the list on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	none
	*/
	void PrintLocation();

	//// �� ���� �Լ���

	/*
	*	@brief	find multimedia contents by combination of keys(Location, Character, Event)
	*	@pre	LocationList should exist
	*	@post	none.
	*	@return	none
	*/
	void FindContentsByTag();

	/*
	*	@brief	find Multimedia Contents by Period (ex : �Ⱓ�Է� (2019.09.11 ~ 2020.10.01) > �ش� �Ⱓ�� ���� ������ ���)
	*	@pre	Multimedia Contents List should exist
	*	@post	none.
	*	@return	none
	*/
	void FindContentsByPeriod();



private:
	SortedLinkedList<MultimediaContent> MC_List;	// Multimedia Contents ��ü�� �����ϴ� SortedLinkedList�� ������ List
	SortedLinkedList<FavoriteContent> FC_Pic_List;	// Favorite Contents ��ü�� �����ϴ� SortedLinkedList�� ������ List
	SortedLinkedList<FavoriteContent> FC_Mov_List;	// Favorite Contents ��ü�� �����ϴ� SortedLinkedList�� ������ List

	SortedLinkedList<Character> characterList;	// Character ��ü�� �����ϴ� SortedLinkedList�� ������ List
	SortedLinkedList<Event> eventList;			// Event ��ü�� �����ϴ� SortedLinkedList�� ������ List
	SortedLinkedList<Location> LocationList;	// Location ��ü�� �����ϴ� SortedLinkedList�� ������ List

	int command;				// ������ command�� �����ϴ� ����
	int countMC;				// Multimedia contents�� ����
	int countFCPic;				// Favorite Picture contents�� ����
	int countFCMov;				// Favorite Movie contents�� ����
	int countCharacter;			// Character ��
	int countEvent;				// Event ��
	int countLocation;			// Location ��
	
};

#endif _APPLICATION_H