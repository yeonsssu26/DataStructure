#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <string>
#include "DoublyIterator.h"
#include "DoublyLinkedList.h"
#include "MultimediaContent.h"
#include "Event.h"

using namespace std;
class Application {
public:
	// for run application
	Application();
	~Application() {}
	void Run();
	int GetCommand();
	
	// Multimedia Content
	void AddMC();
	void DeleteMC();
	void ReplaceMC();
	void MakeEmptyMC();
	void displayAllMC();

	// Event
	int GetEvent(Event& _event);
	int SetEventName(string _eventName);
	void FindEventDisplayMC();
	void DisplayEvent();

protected:
	int command;
	DoublySortedLinkedList<MultimediaContent> MC_List;
	DoublySortedLinkedList<Event> eventList;

	int countMC;
	int countEvent;
};

#endif _APPLICATION_H