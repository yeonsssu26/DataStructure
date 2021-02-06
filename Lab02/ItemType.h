#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };

/**
*	item information class.
*/
class ItemType {
public:
	/**
	*	default constructor.
	*/
	ItemType() {
		contentId = -1;
		contentType = -1;
		contentName = "";
		createTime = "";
		category = "";
		eventName = "";
		eventStory = "";
		characters = "";
	}

	/**
	*	destructor.
	*/
	~ItemType() {}

	/**
	*	@brief	Get content id.
	*	@pre	content id is set.
	*	@post	none.
	*	@return	content id.
	*/
	int GetId() const;

	/**
	*	@brief	Get content type.
	*	@pre	content type is set.
	*	@post	none.
	*	@return	content type.
	*/
	int GetType() const;

	/**
	*	@brief	Get content name.
	*	@pre	content name is set.
	*	@post	none.
	*	@return	content name.
	*/
	string GetName() const;

	/**
	*	@brief	Get content time.
	*	@pre	content time is set.
	*	@post	none.
	*	@return	content time.
	*/
	string GetTime() const;

	/**
	*	@brief	Get category.
	*	@pre	category is set.
	*	@post	none.
	*	@return	category.
	*/
	string GetCategory() const;

	/**
	*	@brief	Get event name.
	*	@pre	event name is set.
	*	@post	none.
	*	@return	event name.
	*/
	string GetEvent() const;

	/**
	*	@brief	Get event story.
	*	@pre	content event is set.
	*	@post	none.
	*	@return	content event.
	*/
	string GetStory() const;

	/**
	*	@brief	Get characters.
	*	@pre	characters is set.
	*	@post	none.
	*	@return	characters.
	*/
	string GetCharacters() const;

	/**
	*	@brief	Set content id.
	*	@pre	none.
	*	@post	content id is set.
	*	@param	inId	content id.
	*/
	void SetId(int inId);

	/**
	*	@brief	Set content type.
	*	@pre	none.
	*	@post	content type is set.
	*	@param	inType	content type.
	*/
	void SetType(int inType);

	/**
	*	@brief	Set content name.
	*	@pre	none.
	*	@post	content name is set.
	*	@param	inName	content name.
	*/
	void SetName(string inName);

	/**
	*	@brief	Set content time.
	*	@pre	none.
	*	@post	content time is set.
	*	@param	inTime	content time.
	*/
	void SetTime(string inTime);

	/**
	*	@brief	Set content category.
	*	@pre	none.
	*	@post	content category is set.
	*	@param	inCategory	content category.
	*/
	void SetCategory(string inCategory);

	/**
	*	@brief	Set content event.
	*	@pre	none.
	*	@post	content event is set.
	*	@param	inEvent	content event.
	*/
	void SetEvent(string inEvent);

	/**
	*	@brief	Set event story.
	*	@pre	none.
	*	@post	event story is set.
	*	@param	inEvent	event story.
	*/
	void SetStory(string inStory);

	/**
	*	@brief	Set characters.
	*	@pre	none.
	*	@post	characters is set.
	*	@param	inCharacters characters.
	*/
	void SetCharacters(string inCharacter);

	/**
	*	@brief	Set content record.
	*	@pre	none.
	*	@post	content record is set.
	*	@param	inId	content id.
	*	@param	inType	content type.
	*	@param	inName	content name.
	*	@param	inTime	content time.
	*	@param	inCategory	content category.
	*	@param	inEvent	content event.
	*	@param	inEvent	event story.
	*	@param	inCharacters characters.
	*/
	void SetRecord(int inId, int inType, string inName, string inTime, string inCategory, string inEvent, string innStory, string inCharacter);

	/**
	*	@brief	Display content id on screen.
	*	@pre	content id is set.
	*	@post	content id is on screen.
	*/
	void DisplayIdOnScreen();

	/**
	*	@brief	Display content type on screen.
	*	@pre	content type is set.
	*	@post	content type is on screen.
	*/
	void DisplayTypeOnScreen();

	/**
	*	@brief	Display content name on screen.
	*	@pre	content name is set.
	*	@post	content name is on screen.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	Display content time on screen.
	*	@pre	content time is set.
	*	@post	content time is on screen.
	*/
	void DisplayTimeOnScreen();

	/**
	*	@brief	Display category on screen.
	*	@pre	category is set.
	*	@post	category is on screen.
	*/
	void DisplayCategoryOnScreen();

	/**
	*	@brief	Display event on screen.
	*	@pre	event is set.
	*	@post	event is on screen.
	*/
	void DisplayEventOnScreen();

	/**
	*	@brief	Display event story on screen.
	*	@pre	event story is set.
	*	@post	event story is on screen.
	*/
	void DisplayStoryOnScreen();

	/**
	*	@brief	Display characters on screen.
	*	@pre	characters is set.
	*	@post	characters is on screen.
	*/
	void DisplayCharactersOnScreen();

	/**
	*	@brief	Display an content record on screen.
	*	@pre	content record is set.
	*	@post	content record is on screen.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	Set content id from keyboard.
	*	@pre	none.
	*	@post	content id is set.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set content type from keyboard.
	*	@pre	none.
	*	@post	content type is set.
	*/
	void SetTypeFromKB();

	/**
	*	@brief	Set cotent name from keyboard.
	*	@pre	none.
	*	@post	cotent name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set content time from keyboard.
	*	@pre	none.
	*	@post	content time is set.
	*/
	void SetTimeFromKB();

	/**
	*	@brief	Set content category from keyboard.
	*	@pre	none.
	*	@post	content category is set.
	*/
	void SetCategoryFromKB();

	/**
	*	@brief	Set event from keyboard.
	*	@pre	none.
	*	@post	event is set.
	*/
	void SetEventFromKB();

	/**
	*	@brief	Set event story from keyboard.
	*	@pre	none.
	*	@post	event story is set.
	*/
	void SetStoryFromKB();

	/**
	*	@brief	Set character from keyboard.
	*	@pre	none.
	*	@post	character is set.
	*/
	void SetCharactersFromKB();

	/**
	*	@brief	Set content record from keyboard.
	*	@pre	none.
	*	@post	content record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataFromFile(ofstream& fout);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const ItemType& data);


	// 주석 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	bool operator<(ItemType otherItem) const;
	bool operator>(ItemType otherItem) const;
	bool operator==(ItemType otherItem) const;
	void operator=(ItemType otherItem);

protected:
	int contentId;						// 콘텐츠 ID (PK)
	int contentType;					// 콘텐츠 종류 (ex : 1-사진, 2-파라노마사진, 3-동영상)

	string contentName;					// 콘텐츠 파일명
	string createTime;					// 생성날짜 및 시간
	string category;					// 콘텐츠 카테고리 (ex : 인물, 장소, 사물)
	string eventName;					// 이벤트명 (ex : 고등학교 졸업식, 24세 생일)
	string eventStory;					// 이벤트 내용 (ex : 연수와 함께 경희대에서 찍은 사진)
	string characters;					// 콘텐츠 등장인물
};

#endif _ITEMTYPE_H