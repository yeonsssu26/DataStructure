#include "Application.h"

Application::Application() {
	command = 0;

	countMC = 0;
	countFCPic = 0;
	countFCMov = 0;
	countEvent = 0;
	countCharacter = 0;
	countLocation = 0;
}

void Application::Run() {

	while (1)
	{
		command = GetCommand();

		switch (command)
		{
		case 1:
			AddMC();
			break;
		case 2:
			DeleteMC();
			break;
		case 3:
			ReplaceMC();
			break;
		case 4:
			displayAllMC();
			break;
		case 5:
			MakeEmptyMC();
			break;

		case 6:
			AddFC();
			break;
		case 7:
			DeleteFC();
			break;
		case 8:
			displayAllFCPic();
			displayAllFCMov();
			break;
		case 9:
			MakeEmptyFCPic();
			MakeEmptyFCMov();
			break;

		case 10:
			PrintEvent();
			break;
		case 11:
			PrintCharacter();
			break;
		case 12:
			PrintLocation();
			break;

		case 13:
			FindEventDisplayMC();
			break;
		case 14:
			FindCharacterDisplayMC();
			break;
		case 15:
			FindLocationDisplayMC();
			break;
		case 16:
			FindContentsByTag();
			break;
		case 17:
			FindContentsByPeriod();
			break;

		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}

	}

}

void Application::MakeEmptyMC()
{
	MC_List.MakeEmpty();
	MC_List.DisplayAll();
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t--- ID - Command -----" << endl;

	cout << "\t    1. Add MC" << endl;
	cout << "\t    2. Delete MC" << endl;
	cout << "\t    3. Replace MC" << endl;
	cout << "\t    4. Print MC" << endl;
	cout << "\t    5. Make MC Empty" << endl;

	cout << "\t    6. Add FC" << endl;
	cout << "\t    7. Delete FC" << endl;
	cout << "\t    8. Print FC" << endl;
	cout << "\t    9. Make FC Empty" << endl;

	cout << "\t    10. Print Event" << endl;
	cout << "\t    11. Print Character" << endl;
	cout << "\t    12. Print Location" << endl;

	cout << "\t    13. Find Event and Display All MC" << endl;
	cout << "\t    14. Find Character and Display All MC" << endl;
	cout << "\t    15. Find Location and Display All MC" << endl;
	cout << "\t    16. Search Contents by Tag" << endl;
	cout << "\t    17. Search Contents by Period" << endl;

	cout << "\t    0. Quit" << endl << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command; cout << endl;

	return command;
}

void Application::AddMC() {

	MultimediaContent addTarget;

	string beforeChange, MCname; cout << "\tName >> "; cin >> MCname;
	
	// 사용자가 초기에 입력한 이름을 저장해둔다.
	beforeChange = MCname;

	// 이미 존재하는 이름이 아닌지 check한다
	if (countMC != 0) {

		MultimediaContent dummy;
		MC_List.ResetPointer();
		MC_List.GetNextItem(dummy);

		bool change = false, moreToSearch = true;
		int newIdx = 2; int start = 0;

		for (int i = 0; i < countMC; i++) {

			if (dummy.GetName() == MCname) {
				change = true;
				MCname = beforeChange + to_string(newIdx);
				newIdx++;
			}

			if (i != countMC - 1) {
				MC_List.GetNextItem(dummy);
			}

		}

		if (change == true) { // 중복되는 이름 존재 >> 자동으로 이름을 바꿨음을 알림
			cout << "\n사용자가 처음 입력한 " << beforeChange << "은(는) 이미 존재하는 이름입니다." << endl;
			cout << "따라서 프로그램에 의해 자동으로 " << MCname << "으로 변경되었습니다." << endl << endl;
		}

	}


	// 중복여부가 검증된 이름을 저장함
	addTarget.SetName(MCname);

	// 이름 외의 다른 정보들을 입력받음
	addTarget.SetRecordFromKB(); // input by keyboard

	// automatically set up (pk, time, name뒤에 type붙이기)
	addTarget.SetRecord();

	int check = MC_List.Add(addTarget); // add
	countMC++;

	if (check == 1) { // success

		Event eventItem;
		eventItem.SetRecord(addTarget);
		
		Character characterItem;
		characterItem.SetRecord(addTarget);

		Location locationItem;
		locationItem.SetRecord(addTarget);
		

		// 1
		check = checkEventName(eventItem.GetEventName());
		if (check == 0) {
			eventItem.Add(addTarget);	// 먼저 Event add하고
			eventList.Add(eventItem);	// Event list에 add한다
			countEvent++;
		}
		else {

			// 기존에 존재하는 해당 event 객체 찾아서
			GetEvent(eventItem);

			// 거기에 mc정보 추가하고 mcCount 증가시켜야
			eventItem.Add(addTarget);

			// 업데이트 된 eventItem을 달아줘야 >> 일단 원래 Event객체 지우고(delete) >> 새로운 Event객체 달기(add)
			eventList.Delete(eventItem);	// Evnet List에서 지운다

			eventList.Add(eventItem);		// Event List에 추가한다

		}
		
		// 2
		check = checkCharacterName(characterItem.GetCharacterName());
		if (check == 0) {

			characterItem.Add(addTarget);	// 먼저 Character에 add하고
			characterList.Add(characterItem);	// Character list에 add한다
			countCharacter++;
		}
		else {

			// 기존에 존재하는 해당 Character 객체 찾아서
			GetCharacter(characterItem);

			// 거기에 mc정보 추가하고 mcCount 증가시켜야
			characterItem.Add(addTarget);

			// 업데이트 된 CharacterItem을 달아줘야 >> 일단 원래 Character객체 지우고(delete) >> 새로운 Character객체 달기(add)
			characterList.Delete(characterItem);		// Character List에서 지운다

			characterList.Add(characterItem);		// Character List에 추가한다

		}


		// 3
		check = checkLocationName(locationItem.GetLocationName());

		if (check == 0) {

			locationItem.Add(addTarget);	// 먼저 Location add하고
			LocationList.Add(locationItem);	// Location list에 add한다
			countLocation++;

		}
		else {

			// 기존에 존재하는 해당 Location 객체 찾아서
			GetLocation(locationItem);

			// 거기에 mc정보 추가하고 mcCount 증가시켜야
			locationItem.Add(addTarget);

			// 업데이트 된 LocationItem을 달아줘야 >> 일단 원래 Location객체 지우고(delete) >> 새로운 Location객체 달기(add)
			LocationList.Delete(locationItem);	// Location List에서 지운다
			LocationList.Add(locationItem);		// Location List에 추가한다

		}


		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Event List*****" << endl;
		eventList.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Character List*****" << endl;
		characterList.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Location List*****" << endl;
		LocationList.DisplayAll(); // print all
		cout << endl;

	}

}

void Application::DeleteMC() { // 해당 ID를 갖는 MC 하나만 삭제

	cout << "\n\tChoose Content to Delete" << endl;
	MC_List.DisplayAll();

	// setup delete target : MC
	MultimediaContent deleteTarget;
	//deleteTarget.SetIdFromKB(); // input
	deleteTarget.SetNameFromKB();
	int check = MC_List.Retrieve(deleteTarget);	// deleteTarget에 id만 있었는데 > MC 전체내용 복사함

	if (check == 0) { // fail

		cout << "존재하지 않는 contents입니다" << endl;

	}
	else { // success

		// 1) Setup Target
		// setup delete target : FC
		FavoriteContent FCitem;
		FCitem.SetRecord(deleteTarget);

		// setup delete target : Event
		Event EventItem;
		EventItem.SetRecord(deleteTarget);
		GetEvent(EventItem); // EventList에 걸려있는 해당 Event객체node를 그대로 받아와서 쓴다

		// setup delete target : Character
		Character CharacterItem;
		CharacterItem.SetRecord(deleteTarget);
		GetCharacter(CharacterItem); // CharacterList에 걸려있는 해당 Character객체node를 그대로 받아와서 쓴다

		// setup delete target : Location
		Location LocationItem;
		LocationItem.SetRecord(deleteTarget);
		GetLocation(LocationItem); // LocationList에 걸려있는 해당 Location객체node를 그대로 받아와서 쓴다


		// 2) MC_List 안에서 해당 id를 갖는 contents 삭제
		MC_List.Delete(deleteTarget);
		countMC--;


		// 3) FC_List 안에서 해당 name(pk)을 갖는 contents 삭제
		int FCexist;
		if (deleteTarget.GetType() == 1) { // pic
			FCexist = FC_Pic_List.Delete(FCitem);
			if (FCexist == 1) {
				countFCPic--;
			}
		}
		else if (deleteTarget.GetType() == 2) { // mov
			FCexist = FC_Mov_List.Delete(FCitem);
			if (FCexist == 1) {
				countFCMov--;
			}
		}


		// 4) LocationList, CharacterList, EventList에서 해당 contents 삭제

		// 해당 name(pk)를 갖는 Event객체 안의 MC정보 삭제
		if (EventItem.GetMCcount() == 1) { // 해당 이벤트를 가진 MC가 하나(지울 대상)뿐일 때

			// Event 객체에서 지운다
			EventItem.Delete(deleteTarget);
			
			// EventList 안에서 해당 id를 갖는 contents 삭제
			eventList.Delete(EventItem);	// Evnet List에서 지운다
			countEvent--;

		}
		else {
			EventItem.Delete(deleteTarget);	// Event 객체에서 지운다
		}


		// 해당 name(pk)를 갖는 Character객체 안의 MC정보 삭제
		if (CharacterItem.GetMCcount() == 1) {

			// Character 객체에서 지운다
			CharacterItem.Delete(deleteTarget);

			// characterList 안에서 해당 id를 갖는 contents 삭제
			characterList.Delete(CharacterItem);	// Character List에서 지운다
			countCharacter--;

		}
		else {
			CharacterItem.Delete(deleteTarget);	// Event 객체에서 지운다
		}


		// 해당 name(pk)를 갖는 Location객체 안의 MC정보 삭제
		if (LocationItem.GetMCcount() == 1) {

			// Location 객체에서 지운다
			LocationItem.Delete(deleteTarget);

			// LocationList 안에서 해당 id를 갖는 contents 삭제
			LocationList.Delete(LocationItem);	// Location List에서 지운다
			countLocation--;


		}
		else {
			LocationItem.Delete(deleteTarget);	// Event 객체에서 지운다
		}

	}

	
	// print res
	if (countMC == 0) {
		cout << "\n\tMultimedia Content List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;
	}

	if (countFCPic == 0) {
		cout << "\n\tFavorite Picture Content List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Favorite Picture Content List*****" << endl;
		FC_Pic_List.DisplayAll(); // print all
		cout << endl;
	}

	if (countFCMov == 0) {
		cout << "\n\tFavorite Movie Content List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Favorite Movie Content List*****" << endl;
		FC_Mov_List.DisplayAll(); // print all
		cout << endl;
	}


	// 1
	if (countEvent == 0) {
		cout << "\n\tEvent List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Event List*****" << endl;
		eventList.DisplayAll(); // print all
		cout << endl;
	}


	// 2
	if (countCharacter == 0) {
		cout << "\n\tCharacter List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Character List*****" << endl;
		characterList.DisplayAll(); // print all
		cout << endl;
	}


	// 3
	if (countLocation == 0) {
		cout << "\n\tLocation List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Location List*****" << endl;
		LocationList.DisplayAll(); // print all
		cout << endl;
	}

}

void Application::ReplaceMC() {

	cout << "\n\tChoose Content to Replace" << endl;
	MC_List.DisplayAll();

	MultimediaContent replaceTarget; // item : after replace
	replaceTarget.SetNameFromKB();

	int check = MC_List.Retrieve(replaceTarget);
	MultimediaContent preItem = replaceTarget; // item : before replace
	
	
	if (check == 1) { // success find

		cout << "\n\tEnter New info" << endl;

		// id는 변하지 않는다.
		string pk = replaceTarget.GetId();
		replaceTarget.SetId(pk);

		// 새로운 정보를 입력받는다
		replaceTarget.SetRecordFromKB();

		// 바뀌기 전 내용에 대한 객체를 setup
		FavoriteContent FCitem; FCitem.SetRecord(replaceTarget);
		Event preEvent; preEvent.SetRecord(preItem); 
		Character preCharacter; preCharacter.SetRecord(preItem); 
		Location preLocation; preLocation.SetRecord(preItem); 
		
		// set up FC, Event, Location, Character object
		Event eventItem; eventItem.SetRecord(replaceTarget);
		Character characterItem; characterItem.SetRecord(replaceTarget);
		Location locationItem; locationItem.SetRecord(replaceTarget);


		// replace MC_List
		MC_List.Replace(replaceTarget); 

		// replace FC_List (pic or mov)
		if (replaceTarget.GetType() == 1) { // pic
			FC_Pic_List.Replace(FCitem);
		}
		else if (replaceTarget.GetType() == 2) { // mov
			FC_Mov_List.Replace(FCitem);
		}

		// 1
		if (eventItem.GetMCcount() == 1) { // 해당 이벤트 객체에 MC가 하나만 존재할 경우 >> 이벤트리스트에서 해당 객체를 아예 삭제
			eventList.Delete(preEvent);
			countEvent--;
			if (eventList.Retrieve(eventItem) == 0) {
				eventList.Add(eventItem);
				countEvent++;
			}
		}
		else { // 해당 이벤트 객체에 MC가 두개 이상 존재할 경우 >> 이벤트리스트에서 해당 객체를 삭제하면 안됨
			eventItem.Delete(replaceTarget); // 이벤트 객체에서 해당 MC컨텐츠만 삭제
		}

		// 2
		LocationList.Delete(preLocation);
		countLocation--;
		if (LocationList.Retrieve(locationItem) == 0) {
			LocationList.Add(locationItem);
			countLocation++;
		}
		else {
			locationItem.Delete(replaceTarget);
		}

		// 3
		characterList.Delete(preCharacter);
		countCharacter--;
		if (characterList.Retrieve(characterItem) == 0) {
			characterList.Add(characterItem);
			countCharacter++;
		}
		else {
			characterItem.Delete(replaceTarget);
		}


		// print result
		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Favorite Picture Content List*****" << endl;
		FC_Pic_List.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Favorite Movie Content List*****" << endl;
		FC_Mov_List.DisplayAll(); // print all
		cout << endl;



		// 1
		cout << "\n\t*****Event List*****" << endl;
		eventList.DisplayAll(); // print all
		cout << endl;

		// 2
		cout << "\n\t*****Character List*****" << endl;
		characterList.DisplayAll(); // print all
		cout << endl;

		// 3
		cout << "\n\t*****Location List*****" << endl;
		LocationList.DisplayAll(); // print all
		cout << endl;

	}
	else if (check == 0) { // fail find
		cout << "\n\tCannot find the data" << endl;
		cout << "\n\tReplace Fail" << endl;
	}

}

void Application::AddFC() {

	// check if MC_List is Empty
	if (countMC == 0) { // MC_List.isEmpty() >> 자꾸 empty로 떠서 일단 count 변수 사용함
		cout << "\n\tMultimedia List is Empty" << endl;
		cout << "\tFail Add Favorite Content" << endl;
	}
	else {

		cout << "\n\tChoose Content to Add" << endl;
		MC_List.DisplayAll();

		// 키보드로 아이디만 입력하고
		MultimediaContent item;
		item.SetNameFromKB();

		// 전체 내용은 복사를 통해 받아오기
		int check = MC_List.Retrieve(item);

		if (check == 0) {
			cout << "\n\tnot exist" << endl;
		}
		else {

			// MC item을 FC_List에 삽입
			FavoriteContent addTarget;
			addTarget.SetRecord(item);

			
			if (item.GetType() == 1) {
				FC_Pic_List.Add(addTarget);

				cout << "\n\tSuccess Add to FC Picture" << endl;
				FC_Pic_List.DisplayAll();
			}
			else if (item.GetType() == 2) {
				FC_Mov_List.Add(addTarget);

				cout << "\n\tSuccess Add to FC Movie" << endl;
				FC_Mov_List.DisplayAll();
			}


		}

	}

}

void Application::DeleteFC() {

	// check if MC_List is Empty
	if (countMC == 0) { // MC_List.isEmpty() error 고치기
		cout << "\n\tMultimedia List is Empty" << endl;
		cout << "\tFail Add Favorite Content" << endl;
	}
	else {

		cout << "\n\tChoose Content to Delete" << endl;
		FC_Pic_List.DisplayAll(); cout << endl;
		FC_Mov_List.DisplayAll(); cout << endl;

		// 키보드로 아이디만 입력하고
		MultimediaContent item;
		item.SetRecordFromKB();
		item.SetRecord();

		// find여부를 알아내고 전체 내용은 복사를 통해 받아오기
		int idx = MC_List.Retrieve(item);

		if (idx == 0) {
			cout << "\n\tnot exist" << endl;
		}
		else {
			// MC item의 info를 FC객체 deleteTarget에 저장
			FavoriteContent deleteTarget;
			deleteTarget.SetRecord(item);


			// delete
			if (item.GetType() == 1) { // pic
				
				int check = FC_Pic_List.Delete(deleteTarget);

				if (check == 1) { // success
					cout << "\n\tSuccess Delete from FC Picture" << endl << endl;
					FC_Pic_List.DisplayAll(); // print all
				}

			}
			else if (item.GetType() == 2) { // mov
				int check = FC_Mov_List.Delete(deleteTarget);

				if (check == 1) { // success
					cout << "\n\tSuccess Delete from FC Movie" << endl << endl;
					FC_Mov_List.DisplayAll(); // print all
				}
			}

		}

	}

}

void Application::MakeEmptyFCPic()
{
	FC_Pic_List.MakeEmpty();
	FC_Pic_List.DisplayAll();

	cout << "\tMake Favorite Picture Content List Empty SUCCESS!" << endl;
}

void Application::MakeEmptyFCMov()
{
	FC_Mov_List.MakeEmpty();
	FC_Mov_List.DisplayAll();

	cout << "\tMake Favorite Movie Content List Empty SUCCESS!" << endl;
}

void Application::PrintEvent() {
	eventList.DisplayAll();
}

void Application::PrintCharacter() {
	characterList.DisplayAll();
}

void Application::PrintLocation() {
	LocationList.DisplayAll();
}

void Application::displayAllMC() {
	MC_List.DisplayAll();
}

void Application::displayAllFCPic() { 
	cout << "즐겨찾기 해둔 사진 목록입니다." << endl;
	FC_Pic_List.DisplayAll(); cout << endl;
}

void Application::displayAllFCMov() {
	cout << "즐겨찾기 해둔 동영상 목록입니다." << endl;
	FC_Mov_List.DisplayAll(); cout << endl;
}

void Application::FindEventDisplayMC() { // 이벤트 이름 입력받고 >> eventList에서 찾고 >> 찾은 event에 소속된 Multimedia Contents의 "자세한" 정보를 화면에 출력

	cout << "Choose Event" << endl;
	eventList.DisplayAll();

	// 1) Event이름 입력받고
	Event item;
	item.SetEventFromKB();

	// 2) EventList에서 해당 Event이름을 가지는 Event객체를 찾고
	int found = GetEvent(item);
	if (found == 0) {
		cout << "\ncannot find event in eventList" << endl;
	}
	else { // 찾는 eventName을 갖는 event객체가 존재한다면

		MC_Info* eventList = item.GetEventList();
		int cntMC = item.GetMCcount();

		string name;
		cout << "\nDisplay " << item.GetEventName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			name = eventList[i].ContentName;

			// 4) 각각의 pk로 >> 모든 Multimedia Content를 찾아서 >> 출력
			MultimediaContent dummy;
			MC_List.ResetPointer();
			MC_List.GetNextItem(dummy);

			MultimediaContent* curr = MC_List.GetDataLocation();

			bool moreToSearch, found;
			moreToSearch = (curr != NULL); found = false;

			while (moreToSearch && !found) {

				if (dummy.GetName() == name) { //dummy.GetId() == pk

					found = true;
					dummy.DisplayRecordOnScreen(); cout << endl;

				}
				else {

					MC_List.GetNextItem(dummy);
					moreToSearch = (curr != NULL);
					if (MC_List.GetNextDataLocation() == NULL) break;

				}


			}

		}

	}

}


int Application::checkEventName(string _eventName) {


	// EventList에서 해당 Event이름을 가지는 Event객체를 찾고
	Event dummy;

	eventList.ResetPointer();
	Event* curr = eventList.GetDataLocation();

	bool found = false;
	for (int i = 0; i < countEvent; i++) {

		eventList.GetNextItem(dummy);


		if (_eventName == dummy.GetEventName()) {

			found = true;
			break;
		}

	}

	if (found) return 1;	// 이미 존재하는 이벤트 이름 >> 추가불가
	else return 0;			// 존재하지 않는 이벤트 이름 >> 추가가능
}

int Application::GetEvent(Event& _event) {

	Event dummy;

	eventList.ResetPointer();
	eventList.GetNextItem(dummy);				// 첫 번째 노드로 이동
	Event* curr = eventList.GetDataLocation();  // 첫번째 노드의 주소를 줌

	bool moreToSearch, found;
	moreToSearch = (curr != NULL); found = false;
	while (moreToSearch && !found) {

		if (curr->GetEventName() == _event.GetEventName()) {
			found = true;
			_event = dummy;
			break;
		}
		else {
			eventList.GetNextItem(dummy);
			moreToSearch = (curr != NULL);
			if (eventList.GetNextDataLocation() == NULL) break;
		}

	}

	if (found) return 1;	// 이미 존재하는 이벤트 이름 >> 추가불가
	else return 0;			// 존재하지 않는 이벤트 이름 >> 추가가능

}


int Application::GetCharacter(Character& _character) {

	Character dummy;

	characterList.ResetPointer();
	characterList.GetNextItem(dummy);					// 첫 번째 노드로 이동
	Character* curr = characterList.GetDataLocation();  // 첫번째 노드의 주소를 줌

	bool moreToSearch, found;
	moreToSearch = (curr != NULL); found = false;
	while (moreToSearch && !found) {

		if (curr->GetCharacterName() == _character.GetCharacterName()) {

			found = true;
			_character = dummy;
			break;
		}
		else {

			characterList.GetNextItem(dummy);
			moreToSearch = (curr != NULL);
			if (characterList.GetNextDataLocation() == NULL) break;

		}

	}

	if (found) return 1;	// 이미 존재하는 인물 이름 >> 추가불가
	else return 0;			// 존재하지 않는 인물 이름 >> 추가가능


}

int Application::GetLocation(Location& _location) {


	Location dummy;

	LocationList.ResetPointer();
	LocationList.GetNextItem(dummy);					// 첫 번째 노드로 이동
	Location* curr = LocationList.GetDataLocation();	// 첫번째 노드의 주소를 줌

	bool moreToSearch, found;
	moreToSearch = (curr != NULL); found = false;
	while (moreToSearch && !found) {

		if (curr->GetLocationName() == _location.GetLocationName()) {
			found = true;
			_location = dummy;
			break;
		}
		else {
			LocationList.GetNextItem(dummy);
			moreToSearch = (curr != NULL);
			if (LocationList.GetNextDataLocation() == NULL) break;
		}

	}

	if (found) return 1;	// 이미 존재하는 장소 이름 >> 추가불가
	else return 0;			// 존재하지 않는 장소 이름 >> 추가가능


}

int Application::checkCharacterName(string _characterName) {

	// characterList에서 해당 Event이름을 가지는 Event객체를 찾고
	Character dummy;

	characterList.ResetPointer();
	Character* curr = characterList.GetDataLocation();

	bool found = false;
	for (int i = 0; i < countCharacter; i++) {

		characterList.GetNextItem(dummy);

		if (_characterName == dummy.GetCharacterName()) {
			found = true;
			break;
		}

	}

	if (found) return 1;	// 이미 존재하는 이벤트 이름 >> 추가불가
	else return 0;			// 존재하지 않는 이벤트 이름 >> 추가가능

}

int Application::checkLocationName(string _locationName) {

	// LocationList에서 해당 Event이름을 가지는 Event객체를 찾고
	Location dummy;

	LocationList.ResetPointer();
	Location* curr = LocationList.GetDataLocation();

	bool found = false;
	for (int i = 0; i < countLocation; i++) {

		LocationList.GetNextItem(dummy);

		if (_locationName == dummy.GetLocationName()) {
			found = true;
			break;
		}

	}

	if (found) return 1;	// 이미 존재하는 이벤트 이름 >> 추가불가
	else return 0;			// 존재하지 않는 이벤트 이름 >> 추가가능

}

void Application::FindCharacterDisplayMC() { // 이벤트 이름 입력받고 >> eventList에서 찾고 >> 찾은 event에 소속된 Multimedia Contents의 "자세한" 정보를 화면에 출력

	cout << "Choose Character" << endl;
	characterList.DisplayAll();

	// 1) Character이름 입력받고
	Character item;
	item.SetCharacterFromKB();

	// 2) characterList에서 해당 Event이름을 가지는 Event객체를 찾고
	int found = GetCharacter(item);
	if (found == 0) {
		cout << "\ncannot find character in characterList" << endl;
	}
	else { // 찾는 eventName을 갖는 event객체가 존재한다면

		MC_Info* characterList = item.GetCharacterList();
		int cntMC = item.GetMCcount();

		string name;
		cout << "\nDisplay " << item.GetCharacterName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			name = characterList[i].ContentName;

			// 4) 각각의 pk로 >> 모든 Multimedia Content를 찾아서 >> 출력

			MultimediaContent dummy;
			MC_List.ResetPointer();
			MC_List.GetNextItem(dummy);

			MultimediaContent* curr = MC_List.GetDataLocation();

			bool moreToSearch, found;
			moreToSearch = (curr != NULL); found = false;

			while (moreToSearch && !found) {

				if (dummy.GetName() == name) {

					found = true;
					dummy.DisplayRecordOnScreen(); cout << endl;

				}
				else {

					MC_List.GetNextItem(dummy);
					moreToSearch = (curr != NULL);

				}

			}

		}

	}

}

void Application::FindLocationDisplayMC() { // Location 이름 입력받고 >> eventList에서 찾고 >> 찾은 event에 소속된 Multimedia Contents의 "자세한" 정보를 화면에 출력

	cout << "Choose Location" << endl;
	LocationList.DisplayAll();

	// 1) Event이름 입력받고
	Location item;
	item.SetLocationFromKB();

	// 2) EventList에서 해당 Event이름을 가지는 Event객체를 찾고
	int found = GetLocation(item);
	if (found == 0) {
		cout << "\ncannot find Location in eventList" << endl;
	}
	else { // 찾는 LocationName을 갖는 event객체가 존재한다면

		MC_Info* locationList = item.GetLocationList();
		int cntMC = item.GetMCcount();

		string name;
		cout << "\nDisplay " << item.GetLocationName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			name = locationList[i].ContentName;

			// 4) 각각의 pk로 >> 모든 Multimedia Content를 찾아서 >> 출력

			MultimediaContent dummy;
			MC_List.ResetPointer();
			MC_List.GetNextItem(dummy);

			MultimediaContent* curr = MC_List.GetDataLocation();

			bool moreToSearch, found;
			moreToSearch = (curr != NULL); found = false;

			while (moreToSearch && !found) {

				if (dummy.GetName() == name) {

					found = true;
					dummy.DisplayRecordOnScreen(); cout << endl;

				}
				else {

					MC_List.GetNextItem(dummy);
					moreToSearch = (curr != NULL);

				}

			}

		}

	}

}

void Application::FindContentsByPeriod() { // 기간입력 (2019.09.11 ~ 2020.10.01) > 해당 기간을 갖는 컨텐츠 출력


	cout << "찾고 싶은 contents가 생성된 기간을 입력하세요 >> "; string startDate, endDate;
	cin >> startDate >> endDate;

	MultimediaContent dummy;
	MC_List.ResetPointer();
	MC_List.GetNextItem(dummy);

	MultimediaContent* curr = MC_List.GetDataLocation();
	bool moreToSearch = true;

	int count = 0;
	cout << "해당 기간의 contents를 검색합니다." << endl;
	for (int i = 0; i < countMC; i++) {

		if (dummy.GetTime() >= startDate && dummy.GetTime() <= endDate) {
			dummy.DisplayRecordOnScreen(); cout << endl; // contents 전체 정보 출력
			count++;
		}

		if (i != countMC - 1) {
			MC_List.GetNextItem(dummy);
		}

	}

	if (count == 0) cout << "해당 기간의 contents가 존재하지 않습니다." << endl;

}



void Application::FindContentsByTag() {

	// 콘텐츠를 하나 이상의 키를 조합하여 검색
	// ex) 김유식, 생일사진 > 해당 컨텐츠 모두 찾아서 > 출력
	// 키 : Character, Event, Location > 이 중 어떤 걸 선택?

	cout << "콘텐츠를 하나 이상의 키를 조합하여 검색합니다" << endl;

	cout << "몇 개의 Tag를 사용하나요? (1~3) >> "; int cntTag; cin >> cntTag;
	cout << "키로 사용할 Tag를 선택하세요. (Character, Event, Location) >> ";  string s1, s2, s3;
	if (cntTag == 1) {
		cin >> s1;
	}
	else if (cntTag == 2) {
		cin >> s1 >> s2;
	}
	else if (cntTag == 3) {
		cin >> s1 >> s2 >> s3;
	}
	else {
		cout << "1~3 사이의 숫자를 입력하세요" << endl;
	}

	
	string _character = "default", _event = "default", _location = "default";
	if (s1 == "Character" || s2 == "Character" || s3 == "Character") {
		cout << "Tag된 인물을 입력하세요 >> "; cin >> _character;
	}
	if (s1 == "Event" || s2 == "Event" || s3 == "Event") {
		cout << "Tag된 이벤트를 입력하세요 >> "; cin >> _event;
	}
	if (s1 == "Location" || s2 == "Location" || s3 == "Location") {
		cout << "Tag된 장소를 입력하세요 >> "; cin >> _location;
	}

	
	// 순회하기 위해서
	MultimediaContent dummy;
	MC_List.ResetPointer();
	MC_List.GetNextItem(dummy);

	// Tag개수 나눠서 푼다
	if (cntTag == 1) { // Tag 1개일 때

		if (_character != "default") {


			for (int i = 0; i < countMC; i++) {
				if (_character == dummy.GetCharacters()) {
					dummy.DisplayRecordOnScreen(); cout << endl;
				}
				
				MC_List.GetNextItem(dummy);
				if (MC_List.GetNextDataLocation() == NULL) break;
			}


		}
		else if (_event != "default") {


			for (int i = 0; i < countMC; i++) {
				if (_event == dummy.GetEvent()) {
					dummy.DisplayRecordOnScreen(); cout << endl;
				}
				
				MC_List.GetNextItem(dummy);
				if (MC_List.GetNextDataLocation() == NULL) break;
			}


		}
		else if (_location != "default") {


			for (int i = 0; i < countMC; i++) {
				if (_location == dummy.GetLocation()) {
					dummy.DisplayRecordOnScreen(); cout << endl;
				}
				
				MC_List.GetNextItem(dummy);
				if (MC_List.GetNextDataLocation() == NULL) break;
			}


		}

	}
	else if (cntTag == 2) { // Tag 2개일 때

		if (_character == "default") {

			for (int i = 0; i < countMC; i++) {
				if (_event == dummy.GetEvent() && _location == dummy.GetLocation()) {
					dummy.DisplayRecordOnScreen(); cout << endl;
				}
				
				MC_List.GetNextItem(dummy);
				if (MC_List.GetNextDataLocation() == NULL) break;
			}

		}
		else if (_event == "default") {


			for (int i = 0; i < countMC; i++) {
				if (_character == dummy.GetCharacters() && _location == dummy.GetLocation()) {
					dummy.DisplayRecordOnScreen(); cout << endl;
				}
				
				MC_List.GetNextItem(dummy);
				if (MC_List.GetNextDataLocation() == NULL) break;
			}


		}
		else if (_location == "default") {



			for (int i = 0; i < countMC; i++) {
				if (_character == dummy.GetCharacters() && _event == dummy.GetEvent()) {
					dummy.DisplayRecordOnScreen(); cout << endl;
				}
				
				MC_List.GetNextItem(dummy);
				if (MC_List.GetNextDataLocation() == NULL) break;
			}


		}

	}
	else if (cntTag == 3) { // Tag 3개일 때

		for (int i = 0; i < countMC; i++) {
			if (_character == dummy.GetCharacters() && _event == dummy.GetEvent() && _location == dummy.GetLocation()) {
				dummy.DisplayRecordOnScreen(); cout << endl;
			}
			
			MC_List.GetNextItem(dummy);
			if (MC_List.GetNextDataLocation() == NULL) break;
		}

	}

}