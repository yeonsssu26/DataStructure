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


	/*
	
	// 해당 함수 추가 ///////////////////////////////////////////////////////////////////////////////////
	Rearrange_FC: 키보드로부터 조건을 입력받아서 FC의 보는 순서(들어온 순, 이름 순, 자주보는 순, 등)를 바꾼다.
	
	*/




	FavoriteContent();
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

	bool operator<(FavoriteContent otherItem) const;
	bool operator>(FavoriteContent otherItem) const;
	bool operator==(FavoriteContent otherItem) const;
	void operator=(FavoriteContent otherItem);

	friend ostream& operator<<(ostream& outputStream, const FavoriteContent& item);

protected:
	string contentId;						// 콘텐츠 ID (PK)
	string contentName;					// 콘텐츠 파일명
	string eventName;					// 이벤트명 (ex : 고등학교 졸업식, 24세 생일)
};

#endif _FAVORIECONTENT_H