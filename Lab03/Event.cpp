#include "Event.h"

Event::Event(void) {
	countContent = 0;
	eventName = "";
	eventStory = "";
	EventList = new string[maxsize];
}

Event::~Event() {
	delete[] EventList;
}

void Event::Add(MultimediaContent _mc) {
	eventName = _mc.GetName();
	eventStory = _mc.GetStory();

	EventList[countContent++] = eventName;
}

void Event::Delete(MultimediaContent _mc) {
	int idx = -1;
	for (int i = 0; i < countContent; i++) {
		if (EventList[i] == _mc.GetName()) {
			eventName = "";
			eventStory = "";

			EventList[i] = EventList[countContent - 1];
			countContent--;
		}
	}
	if (idx == -1) cout << "fail to delete Event" << endl;
}

void Event::Replace(MultimediaContent _mc) {
	int idx = -1;
	for (int i = 0; i < countContent; i++) {
		if (EventList[i] == _mc.GetName()) {
			eventStory = _mc.GetStory();
		}
	}
	if (idx == -1) cout << "fail to delete Event" << endl;
}

void Event::Print() {
	cout << "eventName : " << eventName << endl;
	cout << "eventStory : " << eventStory << endl;
}