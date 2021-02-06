#include "ItemType.h"

int ItemType::GetId() const {
	return this->contentId;
}

int ItemType::GetType() const {
	return this->contentType;
}

string ItemType::GetName() const {
	return this->contentName;
}

string ItemType::GetTime() const {
	return this->createTime;
}

string ItemType::GetCategory() const {
	return this->category;
}

string ItemType::GetEvent() const {
	return this->eventName;
}

string ItemType::GetStory() const {
	return this->eventStory;
}

string ItemType::GetCharacters() const {
	return this->characters;
}

void ItemType::SetId(int inId) {
	this->contentId = inId;
}

void ItemType::SetType(int inType) {
	this->contentType = inType;
}

void ItemType::SetName(string inName) {
	this->contentName = inName;
}

void ItemType::SetTime(string inTime) {
	this->createTime = inTime;
}

void ItemType::SetCategory(string inCategory) {
	this->category = inCategory;
}

void ItemType::SetEvent(string inEvent) {
	this->eventName = inEvent;
}

void ItemType::SetStory(string inStory) {
	this->eventStory = inStory;
}

void ItemType::SetCharacters(string inCharacter) {
	this->characters = inCharacter;
}

void ItemType::SetRecord(int inId, int inType, string inName, string inTime, string inCategory, string inEvent, string inStory, string inCharacter) {
	SetId(inId);
	SetType(inType);
	SetName(inName);
	SetTime(inTime);
	SetCategory(inCategory);
	SetEvent(inEvent);
	SetStory(inStory);
	SetCharacters(inCharacter);
}

void ItemType::DisplayIdOnScreen() {
	cout << "\tId : " << this->contentId << endl;
}

void ItemType::DisplayTypeOnScreen() {
	cout << "\tType : " << this->contentType << endl;
}

void ItemType::DisplayNameOnScreen() {
	cout << "\tName : " << this->contentName << endl;
}

void ItemType::DisplayTimeOnScreen() {
	cout << "\tTime : " << this->createTime << endl;
}

void ItemType::DisplayCategoryOnScreen() {
	cout << "\tCategory : " << this->category << endl;
}

void ItemType::DisplayEventOnScreen() {
	cout << "\tEvent : " << this->eventName << endl;
}

void ItemType::DisplayStoryOnScreen() {
	cout << "\tStory : " << this->eventStory << endl;
}

void ItemType::DisplayCharactersOnScreen() {
	cout << "\tEvent : " << this->eventName << endl;
}

void ItemType::DisplayRecordOnScreen() {
	DisplayIdOnScreen();
	DisplayTypeOnScreen();
	DisplayNameOnScreen();
	DisplayTimeOnScreen();
	DisplayCategoryOnScreen();
	DisplayEventOnScreen();
	DisplayStoryOnScreen();
	DisplayCharactersOnScreen();
}

void ItemType::SetIdFromKB() {
	cout << "Id : "; cin >> this->contentId;
}

void ItemType::SetTypeFromKB() {
	cout << "Type : "; cin >> this->contentType;
}

void ItemType::SetNameFromKB() {
	cout << "Name : "; cin >> this->contentName;
}

void ItemType::SetTimeFromKB() {
	cout << "Time : "; cin >> this->createTime;
}

void ItemType::SetCategoryFromKB() {
	cout << "Category : "; cin >> this->category;
}

void ItemType::SetEventFromKB() {
	cout << "Event : "; cin >> this->eventName;
}

void ItemType::SetStoryFromKB() {
	cout << "Story : "; cin >> this->eventStory;
}

void ItemType::SetCharactersFromKB() {
	cout << "Characters : "; cin >> this->characters;
}

void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetTypeFromKB();
	SetNameFromKB();
	SetTimeFromKB();
	SetCategoryFromKB();
	SetEventFromKB();
	SetStoryFromKB();
	SetCharactersFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) { // 학생정보를 파일에서 읽는 함수
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
}

int ItemType::WriteDataFromFile(ofstream& fout) { // 학생정보를 파일로 출력하는 함수
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

RelationType ItemType::CompareByID(const ItemType& data) { // ID(pk)를 기준으로 학생정보를 비교하는 함수
	if (this->GetId() > data.contentId) {
		return GREATER;
	}
	else if (this->GetId() < data.contentId) {
		return LESS;
	}
	else { // this->GetId() == data.m_id
		return EQUAL;
	}
}