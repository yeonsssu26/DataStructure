#pragma once

#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <iostream>
using namespace std;

#include "ItemType.h"
#include "DoublyLinkedList.h"


class Application
{
public:
	Application(){}
	~Application(){}
	void Run();
	int GetCommand();
	void DisplayAll();
private:
	DoublyLinkedList<ContentsType*> m_List;	// Base class
};

#endif