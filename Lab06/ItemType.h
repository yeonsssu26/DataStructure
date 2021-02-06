#pragma once
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <string>
using namespace std;

// base class
class ContentsType {
public:
	virtual void print() = 0; // 순수가상함수
	virtual void read() = 0;
protected:
	string name; // contents name
};

// derived class 1
class Music : public ContentsType {
public:
	virtual void print() {
		cout << "Music : " << name << endl;
	}
	virtual void read() {
		cout << "Enter Music name : ";
		cin >> name;
	}
private:
};

// derived class 2
class Picture : public ContentsType {
public:
	virtual void print() {
		cout << "Picture : " << name << endl;
	}
	virtual void read() {
		cout << "Enter Picture name : ";
		cin >> name;
	}
private:
};

// derived class 3
class Video : public ContentsType {
public:
	virtual void print() {
		cout << "Video : " << name << endl;
	}
	virtual void read() {
		cout << "Enter Video name : ";
		cin >> name;
	}
private:
};
#endif _ITMETYPE_H