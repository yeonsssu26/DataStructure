#include "Character.h"

Character::Character(void) {
	countMC = 0;
	CharacterName = "";
	CharacterList = new MC_Info[maxsize];	 // MC_List의 pk와 해당 content의 이름 저장
}

void Character::Add(MultimediaContent _mc) {

	string pk = _mc.GetId();
	string contentName = _mc.GetCharacters();
	MC_Info newInfo = { pk, contentName };

	CharacterList[countMC] = newInfo;
	countMC++;

}

void Character::Delete(MultimediaContent _mc) {

	string pk = _mc.GetId();
	int idx = Retrieve(pk);

	CharacterList[idx] = CharacterList[countMC];
	countMC--;

}

void Character::Replace(MultimediaContent _mc) {

	string pk = _mc.GetId();
	int idx = Retrieve(pk);
	CharacterList[idx].ContentName = _mc.GetCharacters();

}


int Character::Retrieve(string ContentName) {

	int idx = -1;
	for (int i = 0; i < maxsize; i++) {
		if (CharacterList[i].ContentName == ContentName) { // find
			idx = i;
		}
	}
	if (idx == -1) return 0;	 // fail
	else return idx;			 // success

}

void Character::SetRecord(MultimediaContent _mc) {
	CharacterName = _mc.GetCharacters();
	CharacterList->pk = _mc.GetId();
	CharacterList->ContentName = _mc.GetCharacters();
}

string Character::GetCharacterName() {
	return CharacterName;
}

bool Character::operator>(Character otherItem) const {

	// pk를 기준으로 비교연산함
	/*if (CharacterList->pk > otherItem.CharacterList->pk) return true;
	else return false;*/

	// name을 기준으로 비교연산함
	if (CharacterList->ContentName > otherItem.CharacterList->ContentName) return true;
	else return false;

}


void Character::SetCharacterFromKB() {
	cout << "\tCharacter >> "; cin >> CharacterName;
}

//string Character::GetPK() {
//	return CharacterList->pk;
//}

MC_Info* Character::GetCharacterList() {
	return CharacterList;
}

int Character::GetMCcount() {
	return countMC;
}

bool Character::operator<(Character otherItem) const {

	// pk를 기준으로 비교연산함
	/*if (CharacterList->pk < otherItem.CharacterList->pk) return true;
	else return false;*/

	// name을 기준으로 비교연산함
	if (CharacterList->ContentName < otherItem.CharacterList->ContentName) return true;
	else return false;
}

bool Character::operator==(Character otherItem) const {

	// pk를 기준으로 비교연산함
	/*if (CharacterList->pk == otherItem.CharacterList->pk) return true;
	else return false;*/

	// name을 기준으로 비교연산함
	/*if (CharacterList->ContentName == otherItem.CharacterList->ContentName) return true;
	else return false;*/

	if (this->CharacterName == otherItem.GetCharacterName()) return true;
	else return false;
}

void Character::operator=(Character otherItem) {

	CharacterName = otherItem.GetCharacterName();
	countMC = otherItem.countMC;

	for (int i = 0; i < countMC; i++) { // CharacterList = otherItem.CharacterList;
		CharacterList[i].pk = otherItem.CharacterList[i].pk;
		CharacterList[i].ContentName = otherItem.CharacterList[i].ContentName;
	}

}

ostream& operator<<(ostream& outputStream, const Character& item) {
	cout << "Character Name : " << item.CharacterName << endl;
	return outputStream;
}
