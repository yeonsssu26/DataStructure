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
	contentType = -1;
	contentId = "";
	contentName = "";
	createTime = "";
	category = "";
	eventName = "";
	eventStory = "";
	characters = "";
}

string MultimediaContent::GetId() const {
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

void MultimediaContent::SetId() {

	string cutday = createTime.substr(createTime.length() - 8, 2);
	string cutmin = createTime.substr(createTime.length() - 5, 2);
	string cutsec = createTime.substr(createTime.length() - 2);

	contentId = "#" + cutday + cutmin + cutsec;
}

void MultimediaContent::SetId(string inId) {
	contentId = inId;
}

void MultimediaContent::SetType(int inType) {
	this->contentType = inType;
}

void MultimediaContent::SetName(string inName) {
	this->contentName = inName;
}

void MultimediaContent::SetName() {
	// 키보드 입력이 끝난 후 contentName뒤에 파일형식을 붙여줌
	if (contentType == 1) {
		contentName += ".image";
	}
	else if (contentType == 2) {
		contentName += ".prara";
	}
	else if (contentType == 3) {
		contentName += ".mov";
	}
	else {
		contentName += ".other";
	}
}

void MultimediaContent::SetTime() { // set local time

	struct tm curr_time;
	time_t now = time(0);
	localtime_s(&curr_time, &now);

	string year = to_string(curr_time.tm_year + 1900);

	int getMonth = curr_time.tm_mon + 1; string month;
	if (getMonth < 10) {
		month = "0" + to_string(getMonth);
	}
	else {
		month = to_string(getMonth);
	}

	int getDay = curr_time.tm_mday; string day;
	if (getDay < 10) {
		day = "0" + to_string(getDay);
	}
	else {
		day = to_string(getDay);
	}

	int gethour = curr_time.tm_hour; string hour;
	if (gethour < 10) {
		hour = "0" + to_string(gethour);
	}
	else {
		hour = to_string(gethour);
	}

	int getmin = curr_time.tm_min; string min;
	if (getmin < 10) {
		min = "0" + to_string(getmin);
	}
	else {
		min = to_string(getmin);
	}

	int getsec = curr_time.tm_sec; string sec;
	if (getsec < 10) {
		sec = "0" + to_string(getsec);
	}
	else {
		sec = to_string(getsec);
	}

	this->createTime = year + "." + month + "." + day + "." + hour + "." + min + "." + sec;
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

void MultimediaContent::SetRecord(int inType, string inName, string inCategory, string inEvent, string inStory, string inCharacter) {
	SetType(inType);
	SetName(inName);
	SetCategory(inCategory);
	SetEvent(inEvent);
	SetStory(inStory);
	SetCharacters(inCharacter);

	SetTime();
	SetId();
}

void MultimediaContent::SetRecord() {
	SetTime();
	SetId();
	SetName();
}

void MultimediaContent::DisplayIdOnScreen() {
	cout << "\tId : " << this->contentId << endl;
}

void MultimediaContent::DisplayTypeOnScreen() {

	string type;
	if (contentType == 1) type = "사진";
	else if (contentType == 2) type = "파라노마사진";
	else if (contentType == 3) type = "동영상";
	else type = "기타type";

	cout << "\tType : " << this->contentType << " : " << type << endl;

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
	cout << "\tId >> "; cin >> this->contentId;
}

void MultimediaContent::SetNameFromKB() {
	cout << "\tName >> "; cin >> this->contentName;
}

void MultimediaContent::SetTypeFromKB() {
	cout << "\tType [1:사진 2:파라노마사진 3:동영상] >> ";
	cin >> this->contentType;
}

void MultimediaContent::SetCategoryFromKB() {
	cout << "\tCategory [일상 / 기념일 / 여행] >> "; cin >> this->category;
}

void MultimediaContent::SetEventFromKB() {
	cout << "\tEvent >> "; cin >> this->eventName;
}

void MultimediaContent::SetStoryFromKB() {
	cout << "\tEvent Story >> "; cin >> this->eventStory;
}

void MultimediaContent::SetCharactersFromKB() {
	cout << "\tCharacters >> "; cin >> this->characters;
}

void MultimediaContent::SetRecordFromKB() {

	SetNameFromKB();
	SetTypeFromKB();
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
	if (this->contentName < otherItem.GetName())
		return true;
	else
		return false;
}

bool MultimediaContent::operator>(MultimediaContent otherItem) const {
	if (this->contentName > otherItem.GetName())
		return true;
	else
		return false;
}

bool MultimediaContent::operator==(MultimediaContent otherItem) const {
	if (this->contentName == otherItem.GetName())
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