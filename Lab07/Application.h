#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
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
	void SearchMC();
	//void ReplaceMC(); //·¦8±¸ÇöÁ¶°Ç ¾Æ´Ô
	void MakeEmptyMC();
	void displayAllMC();

	// Event
	int GetEvent(Event& _event);
	int SetEventName(string _eventName);
	void FindEventDisplayMC();
	void DisplayEvent();

protected:
	int command;
	BinarySearchTree<MultimediaContent> MC_List;
	BinarySearchTree<Event> eventList;

	int countMC;
	int countEvent;
};

#endif _APPLICATION_H