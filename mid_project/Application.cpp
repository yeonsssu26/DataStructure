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
	
	// ����ڰ� �ʱ⿡ �Է��� �̸��� �����صд�.
	beforeChange = MCname;

	// �̹� �����ϴ� �̸��� �ƴ��� check�Ѵ�
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

		if (change == true) { // �ߺ��Ǵ� �̸� ���� >> �ڵ����� �̸��� �ٲ����� �˸�
			cout << "\n����ڰ� ó�� �Է��� " << beforeChange << "��(��) �̹� �����ϴ� �̸��Դϴ�." << endl;
			cout << "���� ���α׷��� ���� �ڵ����� " << MCname << "���� ����Ǿ����ϴ�." << endl << endl;
		}

	}


	// �ߺ����ΰ� ������ �̸��� ������
	addTarget.SetName(MCname);

	// �̸� ���� �ٸ� �������� �Է¹���
	addTarget.SetRecordFromKB(); // input by keyboard

	// automatically set up (pk, time, name�ڿ� type���̱�)
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
			eventItem.Add(addTarget);	// ���� Event add�ϰ�
			eventList.Add(eventItem);	// Event list�� add�Ѵ�
			countEvent++;
		}
		else {

			// ������ �����ϴ� �ش� event ��ü ã�Ƽ�
			GetEvent(eventItem);

			// �ű⿡ mc���� �߰��ϰ� mcCount �������Ѿ�
			eventItem.Add(addTarget);

			// ������Ʈ �� eventItem�� �޾���� >> �ϴ� ���� Event��ü �����(delete) >> ���ο� Event��ü �ޱ�(add)
			eventList.Delete(eventItem);	// Evnet List���� �����

			eventList.Add(eventItem);		// Event List�� �߰��Ѵ�

		}
		
		// 2
		check = checkCharacterName(characterItem.GetCharacterName());
		if (check == 0) {

			characterItem.Add(addTarget);	// ���� Character�� add�ϰ�
			characterList.Add(characterItem);	// Character list�� add�Ѵ�
			countCharacter++;
		}
		else {

			// ������ �����ϴ� �ش� Character ��ü ã�Ƽ�
			GetCharacter(characterItem);

			// �ű⿡ mc���� �߰��ϰ� mcCount �������Ѿ�
			characterItem.Add(addTarget);

			// ������Ʈ �� CharacterItem�� �޾���� >> �ϴ� ���� Character��ü �����(delete) >> ���ο� Character��ü �ޱ�(add)
			characterList.Delete(characterItem);		// Character List���� �����

			characterList.Add(characterItem);		// Character List�� �߰��Ѵ�

		}


		// 3
		check = checkLocationName(locationItem.GetLocationName());

		if (check == 0) {

			locationItem.Add(addTarget);	// ���� Location add�ϰ�
			LocationList.Add(locationItem);	// Location list�� add�Ѵ�
			countLocation++;

		}
		else {

			// ������ �����ϴ� �ش� Location ��ü ã�Ƽ�
			GetLocation(locationItem);

			// �ű⿡ mc���� �߰��ϰ� mcCount �������Ѿ�
			locationItem.Add(addTarget);

			// ������Ʈ �� LocationItem�� �޾���� >> �ϴ� ���� Location��ü �����(delete) >> ���ο� Location��ü �ޱ�(add)
			LocationList.Delete(locationItem);	// Location List���� �����
			LocationList.Add(locationItem);		// Location List�� �߰��Ѵ�

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

void Application::DeleteMC() { // �ش� ID�� ���� MC �ϳ��� ����

	cout << "\n\tChoose Content to Delete" << endl;
	MC_List.DisplayAll();

	// setup delete target : MC
	MultimediaContent deleteTarget;
	//deleteTarget.SetIdFromKB(); // input
	deleteTarget.SetNameFromKB();
	int check = MC_List.Retrieve(deleteTarget);	// deleteTarget�� id�� �־��µ� > MC ��ü���� ������

	if (check == 0) { // fail

		cout << "�������� �ʴ� contents�Դϴ�" << endl;

	}
	else { // success

		// 1) Setup Target
		// setup delete target : FC
		FavoriteContent FCitem;
		FCitem.SetRecord(deleteTarget);

		// setup delete target : Event
		Event EventItem;
		EventItem.SetRecord(deleteTarget);
		GetEvent(EventItem); // EventList�� �ɷ��ִ� �ش� Event��ünode�� �״�� �޾ƿͼ� ����

		// setup delete target : Character
		Character CharacterItem;
		CharacterItem.SetRecord(deleteTarget);
		GetCharacter(CharacterItem); // CharacterList�� �ɷ��ִ� �ش� Character��ünode�� �״�� �޾ƿͼ� ����

		// setup delete target : Location
		Location LocationItem;
		LocationItem.SetRecord(deleteTarget);
		GetLocation(LocationItem); // LocationList�� �ɷ��ִ� �ش� Location��ünode�� �״�� �޾ƿͼ� ����


		// 2) MC_List �ȿ��� �ش� id�� ���� contents ����
		MC_List.Delete(deleteTarget);
		countMC--;


		// 3) FC_List �ȿ��� �ش� name(pk)�� ���� contents ����
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


		// 4) LocationList, CharacterList, EventList���� �ش� contents ����

		// �ش� name(pk)�� ���� Event��ü ���� MC���� ����
		if (EventItem.GetMCcount() == 1) { // �ش� �̺�Ʈ�� ���� MC�� �ϳ�(���� ���)���� ��

			// Event ��ü���� �����
			EventItem.Delete(deleteTarget);
			
			// EventList �ȿ��� �ش� id�� ���� contents ����
			eventList.Delete(EventItem);	// Evnet List���� �����
			countEvent--;

		}
		else {
			EventItem.Delete(deleteTarget);	// Event ��ü���� �����
		}


		// �ش� name(pk)�� ���� Character��ü ���� MC���� ����
		if (CharacterItem.GetMCcount() == 1) {

			// Character ��ü���� �����
			CharacterItem.Delete(deleteTarget);

			// characterList �ȿ��� �ش� id�� ���� contents ����
			characterList.Delete(CharacterItem);	// Character List���� �����
			countCharacter--;

		}
		else {
			CharacterItem.Delete(deleteTarget);	// Event ��ü���� �����
		}


		// �ش� name(pk)�� ���� Location��ü ���� MC���� ����
		if (LocationItem.GetMCcount() == 1) {

			// Location ��ü���� �����
			LocationItem.Delete(deleteTarget);

			// LocationList �ȿ��� �ش� id�� ���� contents ����
			LocationList.Delete(LocationItem);	// Location List���� �����
			countLocation--;


		}
		else {
			LocationItem.Delete(deleteTarget);	// Event ��ü���� �����
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

		// id�� ������ �ʴ´�.
		string pk = replaceTarget.GetId();
		replaceTarget.SetId(pk);

		// ���ο� ������ �Է¹޴´�
		replaceTarget.SetRecordFromKB();

		// �ٲ�� �� ���뿡 ���� ��ü�� setup
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
		if (eventItem.GetMCcount() == 1) { // �ش� �̺�Ʈ ��ü�� MC�� �ϳ��� ������ ��� >> �̺�Ʈ����Ʈ���� �ش� ��ü�� �ƿ� ����
			eventList.Delete(preEvent);
			countEvent--;
			if (eventList.Retrieve(eventItem) == 0) {
				eventList.Add(eventItem);
				countEvent++;
			}
		}
		else { // �ش� �̺�Ʈ ��ü�� MC�� �ΰ� �̻� ������ ��� >> �̺�Ʈ����Ʈ���� �ش� ��ü�� �����ϸ� �ȵ�
			eventItem.Delete(replaceTarget); // �̺�Ʈ ��ü���� �ش� MC�������� ����
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
	if (countMC == 0) { // MC_List.isEmpty() >> �ڲ� empty�� ���� �ϴ� count ���� �����
		cout << "\n\tMultimedia List is Empty" << endl;
		cout << "\tFail Add Favorite Content" << endl;
	}
	else {

		cout << "\n\tChoose Content to Add" << endl;
		MC_List.DisplayAll();

		// Ű����� ���̵� �Է��ϰ�
		MultimediaContent item;
		item.SetNameFromKB();

		// ��ü ������ ���縦 ���� �޾ƿ���
		int check = MC_List.Retrieve(item);

		if (check == 0) {
			cout << "\n\tnot exist" << endl;
		}
		else {

			// MC item�� FC_List�� ����
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
	if (countMC == 0) { // MC_List.isEmpty() error ��ġ��
		cout << "\n\tMultimedia List is Empty" << endl;
		cout << "\tFail Add Favorite Content" << endl;
	}
	else {

		cout << "\n\tChoose Content to Delete" << endl;
		FC_Pic_List.DisplayAll(); cout << endl;
		FC_Mov_List.DisplayAll(); cout << endl;

		// Ű����� ���̵� �Է��ϰ�
		MultimediaContent item;
		item.SetRecordFromKB();
		item.SetRecord();

		// find���θ� �˾Ƴ��� ��ü ������ ���縦 ���� �޾ƿ���
		int idx = MC_List.Retrieve(item);

		if (idx == 0) {
			cout << "\n\tnot exist" << endl;
		}
		else {
			// MC item�� info�� FC��ü deleteTarget�� ����
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
	cout << "���ã�� �ص� ���� ����Դϴ�." << endl;
	FC_Pic_List.DisplayAll(); cout << endl;
}

void Application::displayAllFCMov() {
	cout << "���ã�� �ص� ������ ����Դϴ�." << endl;
	FC_Mov_List.DisplayAll(); cout << endl;
}

void Application::FindEventDisplayMC() { // �̺�Ʈ �̸� �Է¹ް� >> eventList���� ã�� >> ã�� event�� �Ҽӵ� Multimedia Contents�� "�ڼ���" ������ ȭ�鿡 ���

	cout << "Choose Event" << endl;
	eventList.DisplayAll();

	// 1) Event�̸� �Է¹ް�
	Event item;
	item.SetEventFromKB();

	// 2) EventList���� �ش� Event�̸��� ������ Event��ü�� ã��
	int found = GetEvent(item);
	if (found == 0) {
		cout << "\ncannot find event in eventList" << endl;
	}
	else { // ã�� eventName�� ���� event��ü�� �����Ѵٸ�

		MC_Info* eventList = item.GetEventList();
		int cntMC = item.GetMCcount();

		string name;
		cout << "\nDisplay " << item.GetEventName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			name = eventList[i].ContentName;

			// 4) ������ pk�� >> ��� Multimedia Content�� ã�Ƽ� >> ���
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


	// EventList���� �ش� Event�̸��� ������ Event��ü�� ã��
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

	if (found) return 1;	// �̹� �����ϴ� �̺�Ʈ �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �̺�Ʈ �̸� >> �߰�����
}

int Application::GetEvent(Event& _event) {

	Event dummy;

	eventList.ResetPointer();
	eventList.GetNextItem(dummy);				// ù ��° ���� �̵�
	Event* curr = eventList.GetDataLocation();  // ù��° ����� �ּҸ� ��

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

	if (found) return 1;	// �̹� �����ϴ� �̺�Ʈ �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �̺�Ʈ �̸� >> �߰�����

}


int Application::GetCharacter(Character& _character) {

	Character dummy;

	characterList.ResetPointer();
	characterList.GetNextItem(dummy);					// ù ��° ���� �̵�
	Character* curr = characterList.GetDataLocation();  // ù��° ����� �ּҸ� ��

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

	if (found) return 1;	// �̹� �����ϴ� �ι� �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �ι� �̸� >> �߰�����


}

int Application::GetLocation(Location& _location) {


	Location dummy;

	LocationList.ResetPointer();
	LocationList.GetNextItem(dummy);					// ù ��° ���� �̵�
	Location* curr = LocationList.GetDataLocation();	// ù��° ����� �ּҸ� ��

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

	if (found) return 1;	// �̹� �����ϴ� ��� �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� ��� �̸� >> �߰�����


}

int Application::checkCharacterName(string _characterName) {

	// characterList���� �ش� Event�̸��� ������ Event��ü�� ã��
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

	if (found) return 1;	// �̹� �����ϴ� �̺�Ʈ �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �̺�Ʈ �̸� >> �߰�����

}

int Application::checkLocationName(string _locationName) {

	// LocationList���� �ش� Event�̸��� ������ Event��ü�� ã��
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

	if (found) return 1;	// �̹� �����ϴ� �̺�Ʈ �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �̺�Ʈ �̸� >> �߰�����

}

void Application::FindCharacterDisplayMC() { // �̺�Ʈ �̸� �Է¹ް� >> eventList���� ã�� >> ã�� event�� �Ҽӵ� Multimedia Contents�� "�ڼ���" ������ ȭ�鿡 ���

	cout << "Choose Character" << endl;
	characterList.DisplayAll();

	// 1) Character�̸� �Է¹ް�
	Character item;
	item.SetCharacterFromKB();

	// 2) characterList���� �ش� Event�̸��� ������ Event��ü�� ã��
	int found = GetCharacter(item);
	if (found == 0) {
		cout << "\ncannot find character in characterList" << endl;
	}
	else { // ã�� eventName�� ���� event��ü�� �����Ѵٸ�

		MC_Info* characterList = item.GetCharacterList();
		int cntMC = item.GetMCcount();

		string name;
		cout << "\nDisplay " << item.GetCharacterName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			name = characterList[i].ContentName;

			// 4) ������ pk�� >> ��� Multimedia Content�� ã�Ƽ� >> ���

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

void Application::FindLocationDisplayMC() { // Location �̸� �Է¹ް� >> eventList���� ã�� >> ã�� event�� �Ҽӵ� Multimedia Contents�� "�ڼ���" ������ ȭ�鿡 ���

	cout << "Choose Location" << endl;
	LocationList.DisplayAll();

	// 1) Event�̸� �Է¹ް�
	Location item;
	item.SetLocationFromKB();

	// 2) EventList���� �ش� Event�̸��� ������ Event��ü�� ã��
	int found = GetLocation(item);
	if (found == 0) {
		cout << "\ncannot find Location in eventList" << endl;
	}
	else { // ã�� LocationName�� ���� event��ü�� �����Ѵٸ�

		MC_Info* locationList = item.GetLocationList();
		int cntMC = item.GetMCcount();

		string name;
		cout << "\nDisplay " << item.GetLocationName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			name = locationList[i].ContentName;

			// 4) ������ pk�� >> ��� Multimedia Content�� ã�Ƽ� >> ���

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

void Application::FindContentsByPeriod() { // �Ⱓ�Է� (2019.09.11 ~ 2020.10.01) > �ش� �Ⱓ�� ���� ������ ���


	cout << "ã�� ���� contents�� ������ �Ⱓ�� �Է��ϼ��� >> "; string startDate, endDate;
	cin >> startDate >> endDate;

	MultimediaContent dummy;
	MC_List.ResetPointer();
	MC_List.GetNextItem(dummy);

	MultimediaContent* curr = MC_List.GetDataLocation();
	bool moreToSearch = true;

	int count = 0;
	cout << "�ش� �Ⱓ�� contents�� �˻��մϴ�." << endl;
	for (int i = 0; i < countMC; i++) {

		if (dummy.GetTime() >= startDate && dummy.GetTime() <= endDate) {
			dummy.DisplayRecordOnScreen(); cout << endl; // contents ��ü ���� ���
			count++;
		}

		if (i != countMC - 1) {
			MC_List.GetNextItem(dummy);
		}

	}

	if (count == 0) cout << "�ش� �Ⱓ�� contents�� �������� �ʽ��ϴ�." << endl;

}



void Application::FindContentsByTag() {

	// �������� �ϳ� �̻��� Ű�� �����Ͽ� �˻�
	// ex) ������, ���ϻ��� > �ش� ������ ��� ã�Ƽ� > ���
	// Ű : Character, Event, Location > �� �� � �� ����?

	cout << "�������� �ϳ� �̻��� Ű�� �����Ͽ� �˻��մϴ�" << endl;

	cout << "�� ���� Tag�� ����ϳ���? (1~3) >> "; int cntTag; cin >> cntTag;
	cout << "Ű�� ����� Tag�� �����ϼ���. (Character, Event, Location) >> ";  string s1, s2, s3;
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
		cout << "1~3 ������ ���ڸ� �Է��ϼ���" << endl;
	}

	
	string _character = "default", _event = "default", _location = "default";
	if (s1 == "Character" || s2 == "Character" || s3 == "Character") {
		cout << "Tag�� �ι��� �Է��ϼ��� >> "; cin >> _character;
	}
	if (s1 == "Event" || s2 == "Event" || s3 == "Event") {
		cout << "Tag�� �̺�Ʈ�� �Է��ϼ��� >> "; cin >> _event;
	}
	if (s1 == "Location" || s2 == "Location" || s3 == "Location") {
		cout << "Tag�� ��Ҹ� �Է��ϼ��� >> "; cin >> _location;
	}

	
	// ��ȸ�ϱ� ���ؼ�
	MultimediaContent dummy;
	MC_List.ResetPointer();
	MC_List.GetNextItem(dummy);

	// Tag���� ������ Ǭ��
	if (cntTag == 1) { // Tag 1���� ��

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
	else if (cntTag == 2) { // Tag 2���� ��

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
	else if (cntTag == 3) { // Tag 3���� ��

		for (int i = 0; i < countMC; i++) {
			if (_character == dummy.GetCharacters() && _event == dummy.GetEvent() && _location == dummy.GetLocation()) {
				dummy.DisplayRecordOnScreen(); cout << endl;
			}
			
			MC_List.GetNextItem(dummy);
			if (MC_List.GetNextDataLocation() == NULL) break;
		}

	}

}