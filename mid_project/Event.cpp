#include "Event.h"

Event::Event(void) {
	countMC = 0;
	EventName = "";
	EventStory = "";
	EventList = new MC_Info[maxsize]; // MC_List의 pk와 해당 content의 이름 저장
									  // unsorted >> 시간나면 sorted로 수정
									  // sort 기준 >> pk는 안됨 >> eventName 가나다순
}


void Event::Add(MultimediaContent _mc) {

	string pk = _mc.GetId();
	string contentName = _mc.GetName();
	MC_Info newInfo = { pk, contentName };

	EventList[countMC] = newInfo;
	countMC++;

}

void Event::Delete(MultimediaContent _mc) {

	string pk = _mc.GetId();
	int idx = Retrieve(pk);

	EventList[idx] = EventList[countMC];
	countMC--;

}

void Event::Replace(MultimediaContent _mc) {

	string pk = _mc.GetId();
	int idx = Retrieve(pk);
	EventList[idx].ContentName = _mc.GetEvent();

}

int Event::Retrieve(string pk) {

	int idx = -1;
	for (int i = 0; i < maxsize; i++) {
		if (EventList[i].pk == pk) { // find
			idx = i;
		}
	}
	if (idx == -1) return 0;	 // fail
	else return idx;			 // success

}

//void Event::Print() {
//	cout << "\n========print========" << endl << endl;
//	cout << "eventName : " << EventName << endl;
//	cout << "eventStory : " << EventStory << endl;
//	cout << "=====================" << endl << endl;
//}

void Event::SetRecord(MultimediaContent _mc) {
	EventName = _mc.GetEvent();
	EventStory = _mc.GetStory();
	EventList->pk = _mc.GetId();
}

string Event::GetEventName() {
	return EventName;
}

string Event::GetEventStory() {
	return EventStory;
}

void Event::SetEventFromKB() {
	cout << "\tEvent >> "; cin >> EventName;
}

//string Event::GetPK() {
//	return EventList->pk;
//}

MC_Info* Event::GetEventList() {
	return EventList;
}


int Event::GetMCcount() {
	return countMC;
}

bool Event::operator>(Event otherItem) const {
	
	// WRONG
	/*if (EventList->pk > otherItem.EventList->pk) return true;
	else return false;*/

	// RIGHT >> '>' 연산자 사용
	/*if (this->EventName > otherItem.GetEventName()) return true;
	else return false;*/

	// RIGHT >> string header의 compare함수 사용
	if (this->EventName.compare(otherItem.GetEventName()) == 1) return true;
	else return false;

}

bool Event::operator<(Event otherItem) const {

	// WRONG
	/*if (EventList->pk < otherItem.EventList->pk) return true;
	else return false;*/

	// RIGHT >> '<' 연산자 사용
	/*if (this->EventName < otherItem.GetEventName()) return true;
	else return false;*/

	// RIGHT >> string header의 compare함수 사용
	if (this->EventName.compare(otherItem.GetEventName()) == -1) return true;
	else return false;

}

bool Event::operator==(Event otherItem) const {

	// WRONG
	/*if (EventList->pk == otherItem.EventList->pk) return true;
	else return false;*/

	// RIGHT >> '==' 연산자 사용
	/*if (this->EventName == otherItem.GetEventName()) return true;
	else return false;*/

	// RIGHT >> string header의 compare함수 사용
	if (this->EventName.compare(otherItem.GetEventName()) == 0) return true;
	else return false;

}

void Event::operator=(Event otherItem) {
	EventName = otherItem.GetEventName();
	EventStory = otherItem.GetEventStory();
	countMC = otherItem.countMC;
	
	for (int i = 0; i < countMC; i++) { // EventList = otherItem.EventList;
		EventList[i].pk = otherItem.EventList[i].pk;
		EventList[i].ContentName = otherItem.EventList[i].ContentName;
	}
}

ostream& operator<<(ostream& outputStream, const Event& item) {
	cout << "Event Name : " << item.EventName << endl;
	return outputStream;

}