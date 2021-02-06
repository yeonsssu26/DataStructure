#include "Location.h"

Location::Location(void) {
	countMC = 0;
	LocationName = "";
	LocationList = new MC_Info[maxsize]; // MC_List�� pk�� �ش� content�� �̸� ����
									  // unsorted >> �ð����� sorted�� ����
									  // sort ���� >> pk�� �ȵ� >> eventName �����ټ�
}


void Location::Add(MultimediaContent _mc) {

	string pk = _mc.GetId();
	string contentName = _mc.GetLocation();
	MC_Info newInfo = { pk, contentName };

	LocationList[countMC] = newInfo;
	countMC++;

}

void Location::Delete(MultimediaContent _mc) {

	string pk = _mc.GetId();
	int idx = Retrieve(pk);

	LocationList[idx] = LocationList[countMC];
	countMC--;

}

void Location::Replace(MultimediaContent _mc) {

	string pk = _mc.GetId();
	int idx = Retrieve(pk);
	LocationList[idx].ContentName = _mc.GetEvent();

}


int Location::Retrieve(string pk) {

	int idx = -1;
	for (int i = 0; i < maxsize; i++) {
		
		if (LocationList[i].pk == pk) { // find
			idx = i;
		}

	}
	if (idx == -1) return 0;	 // fail
	else return idx;			 // success

}

void Location::SetRecord(MultimediaContent _mc) {
	LocationList->pk = _mc.GetId();
	LocationList->ContentName = _mc.GetLocation();
	LocationName = _mc.GetLocation();
}

string Location::GetLocationName() {
	return LocationName;
}

void Location::SetLocationFromKB() {
	cout << "\tLocation >> "; cin >> LocationName;
}


MC_Info* Location::GetLocationList() {
	return LocationList;
}

int Location::GetMCcount() {
	return countMC;
}

bool Location::operator>(Location otherItem) const {

	// name�� �������� �񱳿�����
	if (LocationList->ContentName > otherItem.LocationList->ContentName) return true;
	else return false;

}

bool Location::operator<(Location otherItem) const {

	// name�� �������� �񱳿�����
	if (LocationList->ContentName < otherItem.LocationList->ContentName) return true;
	else return false;

}

bool Location::operator==(Location otherItem) const {
	
	// name�� �������� �񱳿�����
	if (this->LocationName == otherItem.GetLocationName()) return true;
	else return false;

}

void Location::operator=(Location otherItem) {
	
	LocationName = otherItem.GetLocationName();
	countMC = otherItem.countMC;
	
	for (int i = 0; i < countMC; i++) { // LocationList = otherItem.LocationList;
		LocationList[i].pk = otherItem.LocationList[i].pk;
		LocationList[i].ContentName = otherItem.LocationList[i].ContentName;
	}

}

ostream& operator<<(ostream& outputStream, const Location& item) {
	cout << "Location Name : " << item.LocationName << endl;
	return outputStream;
}