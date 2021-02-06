#include "MultimediaContent.h"
ostream& operator<<(ostream& outputStream, const MultimediaContent& item) {
	cout << "ID : " << item.GetId() << endl;
	cout << "Type : " << item.GetType() << endl;
	cout << "Name : " << item.GetName() << endl;
	cout << "Time : " << item.GetTime() << endl;
	cout << "Category : " << item.GetCategory() << endl;
	cout << "Event : " << item.GetEvent() << endl;
	cout << "Story : " << item.GetStory() << endl;
	cout << "Characters : " << item.GetCharacters() << endl;

	return outputStream;
}

MultimediaContent::MultimediaContent() {
	contentId = -1;
	contentType = -1;
	contentName = "";
	createTime = "";
	category = "";
	eventName = "";
	eventStory = "";
	characters = "";
}

int MultimediaContent::GetId() const {
	return this->contentId;
}

int MultimediaContent::GetType() const {
	return this->contentType;
}

string MultimediaContent::GetName() const {
	return this->contentName;
}

string MultimediaContent::GetTime() const {
	return this->createTime;
}

string MultimediaContent::GetCategory() const {
	return this->category;
}

string MultimediaContent::GetEvent() const {
	return this->eventName;
}

string MultimediaContent::GetStory() const {
	return this->eventStory;
}

string MultimediaContent::GetCharacters() const {
	return this->characters;
}

void MultimediaContent::SetId(int inId) {
	this->contentId = inId;
}

void MultimediaContent::SetType(int inType) {
	this->contentType = inType;
}

void MultimediaContent::SetName(string inName) {
	this->contentName = inName;
}

void MultimediaContent::SetTime(string inTime) {
	this->createTime = inTime;
}

void MultimediaContent::SetCategory(string inCategory) {
	this->category = inCategory;
}

void MultimediaContent::SetEvent(string inEvent) {
	this->eventName = inEvent;
}

void MultimediaContent::SetStory(string inStory) {
	this->eventStory = inStory;
}

void MultimediaContent::SetCharacters(string inCharacter) {
	this->characters = inCharacter;
}

void MultimediaContent::SetRecord(int inId, int inType, string inName, string inTime, string inCategory, string inEvent, string inStory, string inCharacter) {
	SetId(inId);
	SetType(inType);
	SetName(inName);
	SetTime(inTime);
	SetCategory(inCategory);
	SetEvent(inEvent);
	SetStory(inStory);
	SetCharacters(inCharacter);
}

void MultimediaContent::DisplayIdOnScreen() {
	cout << "\tId : " << this->contentId << endl;
}

void MultimediaContent::DisplayTypeOnScreen() {
	cout << "\tType : " << this->contentType << endl;
}

void MultimediaContent::DisplayNameOnScreen() {
	cout << "\tName : " << this->contentName << endl;
}

void MultimediaContent::DisplayTimeOnScreen() {
	cout << "\tTime : " << this->createTime << endl;
}

void MultimediaContent::DisplayCategoryOnScreen() {
	cout << "\tCategory : " << this->category << endl;
}

void MultimediaContent::DisplayEventOnScreen() {
	cout << "\tEvent : " << this->eventName << endl;
}

void MultimediaContent::DisplayStoryOnScreen() {
	cout << "\tStory : " << this->eventStory << endl;
}

void MultimediaContent::DisplayCharactersOnScreen() {
	cout << "\tEvent : " << this->eventName << endl;
}

void MultimediaContent::DisplayRecordOnScreen() {
	DisplayIdOnScreen();
	DisplayTypeOnScreen();
	DisplayNameOnScreen();
	DisplayTimeOnScreen();
	DisplayCategoryOnScreen();
	DisplayEventOnScreen();
	DisplayStoryOnScreen();
	DisplayCharactersOnScreen();
}

void MultimediaContent::SetIdFromKB() {
	cout << "Id : "; cin >> this->contentId;
}

void MultimediaContent::SetTypeFromKB() {
	cout << "Type : "; cin >> this->contentType;
}

void MultimediaContent::SetNameFromKB() {
	cout << "Name : "; cin >> this->contentName;
}

void MultimediaContent::SetTimeFromKB() {
	cout << "Time : "; cin >> this->createTime;
}

void MultimediaContent::SetCategoryFromKB() {
	cout << "Category : "; cin >> this->category;
}

void MultimediaContent::SetEventFromKB() {
	cout << "Event : "; cin >> this->eventName;
}

void MultimediaContent::SetStoryFromKB() {
	cout << "Story : "; cin >> this->eventStory;
}

void MultimediaContent::SetCharactersFromKB() {
	cout << "Characters : "; cin >> this->characters;
}

void MultimediaContent::SetRecordFromKB() {
	SetIdFromKB();
	SetTypeFromKB();
	SetNameFromKB();
	SetTimeFromKB();
	SetCategoryFromKB();
	SetEventFromKB();
	SetStoryFromKB();
	SetCharactersFromKB();
}

int MultimediaContent::ReadDataFromFile(ifstream& fin) {
	if (!fin) {
		cout << "File Input Error" << endl;
		return -1;
	}

	fin >> contentId;
	fin >> contentType;
	fin >> contentName;
	fin >> createTime;
	fin >> category;
	fin >> eventName;
	fin >> eventStory;
	fin >> characters;

	return 1;
}

int MultimediaContent::WriteDataFromFile(ofstream& fout) {
	if (!fout) {
		cout << "File Output Error" << endl;
		return 0; // fail
	}

	fout << contentId << "\t";
	fout << contentType << "\t";
	fout << contentName << "\t";
	fout << createTime << "\t";
	fout << category << "\t";
	fout << eventName << "\t";
	fout << eventStory << "\t";
	fout << characters << endl;

	return 1; // success
}

bool MultimediaContent::operator<(MultimediaContent otherItem) const {
	if (this->contentId < otherItem.GetId())
		return true;
	else
		return false;
}

bool MultimediaContent::operator>(MultimediaContent otherItem) const {
	if (this->contentId > otherItem.GetId())
		return true;
	else
		return false;
}

bool MultimediaContent::operator==(MultimediaContent otherItem) const {
	if (this->contentId == otherItem.GetId())
		return true;
	else
		return false;
}

void MultimediaContent::operator=(MultimediaContent otherItem) {
	this->contentId = otherItem.GetId();
	this->contentType = otherItem.GetType();
	this->contentName = otherItem.GetName();
	this->createTime = otherItem.GetTime();
	this->category = otherItem.GetCategory();
	this->eventName = otherItem.GetEvent();
	this->eventStory = otherItem.GetStory();
	this->characters = otherItem.GetCharacters();
}