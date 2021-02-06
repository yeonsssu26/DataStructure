#include "Event.h"

Event::Event(void) {
	countMC = 0;
	eventName = "";
	eventStory = "";
	EventList = new MC_Info[maxsize]; // MC_List�� pk�� �ش� content�� �̸� ����
									  // unsorted >> �ð����� sorted�� ����
									  // sort ���� >> pk�� �ȵ� >> eventName �����ټ�
}

Event::~Event() {

	//// ���⿡�� error�� �ɸ� ///////////////////////////////////////////////////////////////////////
	//delete[] EventList;

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

void Event::Print() {
	cout << "\n========print========" << endl << endl;
	cout << "eventName : " << eventName << endl;
	cout << "eventStory : " << eventStory << endl;
	cout << "=====================" << endl << endl;
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

void Event::SetRecord(MultimediaContent _mc) {
	eventName = _mc.GetEvent();
	eventStory = _mc.GetStory();
	EventList->pk = _mc.GetId();
}

string Event::GetEventName() {
	return eventName;
}

string Event::GetEventStory() {
	return eventStory;
}

bool Event::operator>(Event otherItem) const {
	if (EventList->pk > otherItem.EventList->pk) return true;
	else return false;
}

bool Event::operator<(Event otherItem) const {
	if (EventList->pk < otherItem.EventList->pk) return true;
	else return false;
}

bool Event::operator==(Event otherItem) const {
	if (EventList->pk == otherItem.EventList->pk) return true;
	else return false;
}

void Event::operator=(Event otherItem) {
	EventList = otherItem.EventList;
	countMC = otherItem.countMC;
	eventName = otherItem.GetEventName();
	eventStory = otherItem.GetEventStory();
}

ostream& operator<<(ostream& outputStream, const Event& item) {

	cout << "Event Name : " << item.eventName << endl;

	return outputStream;
}

void Event::SetEventFromKB() {
	cout << "\tEvent >> "; cin >> eventName;
}

string Event::GetPK() {
	return EventList->pk;
}

int Event::GetLength() {
	return countMC;
}

MC_Info* Event::GetEventList() {
	return EventList;
}

int Event::GetMCcount() {
	return countMC;
}