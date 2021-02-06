#include "FavoriteContent.h"

FavoriteContent::FavoriteContent() {
	contentId = "";
	contentName = "";
	eventName = "";
}

string FavoriteContent::GetId() const {
	return contentId;
}

string FavoriteContent::GetName() const {
	return contentName;
}

string FavoriteContent::GetEvent() const {
	return eventName;
}

void FavoriteContent::SetRecord(MultimediaContent _mc) {
	contentId = _mc.GetId();
	contentName = _mc.GetName();
	eventName = _mc.GetEvent();
}

void FavoriteContent::Display() {
	cout << "\tId : " << contentId << endl;
	cout << "\tName : " << contentName << endl;
	cout << "\tEvent : " << eventName << endl;
}

bool FavoriteContent::operator<(FavoriteContent otherItem) const {
	
	// pk를 기준으로 비교연산함
	/*if (contentId < otherItem.GetId()) return true;
	else return false;*/

	// name을 기준으로 비교연산함
	if (this->contentName < otherItem.GetName()) return true;
	else return false;
}

bool FavoriteContent::operator>(FavoriteContent otherItem) const {

	// pk를 기준으로 비교연산함
	/*if (contentId > otherItem.GetId()) return true;
	else return false;*/

	// name을 기준으로 비교연산함
	if (this->contentName > otherItem.GetName()) return true;
	else return false;

}

bool FavoriteContent::operator==(FavoriteContent otherItem) const {

	// pk를 기준으로 비교연산함
	/*if (contentId == otherItem.GetId()) return true;
	else return false;*/

	// name을 기준으로 비교연산함
	if (this->contentName == otherItem.GetName()) return true;
	else return false;

}

void FavoriteContent::operator=(FavoriteContent otherItem) {
	contentId = otherItem.GetId();
	contentName = otherItem.GetName();
	eventName = otherItem.GetEvent();
}

ostream& operator<<(ostream& outputStream, const FavoriteContent& item) {
	cout << "ID : " << item.GetId() << endl;
	cout << "Name : " << item.GetName() << endl;
	cout << "Event : " << item.GetEvent() << endl;

	return outputStream;
}