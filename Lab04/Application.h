#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"
#include "FavoriteContent.h"
#include "SortedLinkedList.h"
#include "Event.h"


/**
*	application class for item management simply.
*/
class Application {
public:
	/**
	*	default constructor.
	*/
	Application();

	/**
	*	destructor.
	*/
	~Application() {}

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

	/**
	*	@brief	Add new Multimedia Content into SortedLinkedList.
	*	@pre	SortedLinkedList should be initialized.
	*	@post	new Multimedia Content is added into the SortedLinkedList.
	*	@return	none
	*/
	void AddMC();

	/**
	*	@brief	delete the given Multimedia Content into SortedLinkedList.
	*	@pre	SortedLinkedList should be initialized.
	*	@post	the given Multimedia Content is deleted out the list.
	*	@return	none
	*/
	void DeleteMC();

	/**
	*	@brief	replace the given record in the list.
	*	@pre	list should be initialized.
	*	@post	the given record is replaced out the list.
	*	@return	none
	*/
	void ReplaceMC();
	void MakeEmptyMC();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	none
	*/
	void AddFC();

	/**
	*	@brief	delete the given record into list.
	*	@pre	list should be initialized.
	*	@post	the given record is deleted out the list.
	*	@return	none
	*/
	void DeleteFC();

	void MakeEmptyFC();

	void PrintEvent();




	void displayAllMC();
	void displayAllFC();



	/*
	FindNDisplayEvent(): 이벤트 이름을 입력받아서 eventList에서 찾고, 찾은 event에 소속된 콘텐츠의 자세한 정보를 화면에 출력한다.
	*/
	void FindEventDisplayMC(); // 이벤트 이름 입력받고 >> eventList에서 찾고 >> 찾은 event에 소속된 Multimedia Contents의 "자세한" 정보를 화면에 출력


	int checkEventName(string _eventName);


	int GetEvent(Event& _event);

protected:
	int command;
	SortedLinkedList<MultimediaContent> MC_List;
	SortedLinkedList<FavoriteContent> FC_List;
	SortedLinkedList<Event> eventList;

	int countMC;
	int countEvent;

};

#endif _APPLICATION_H