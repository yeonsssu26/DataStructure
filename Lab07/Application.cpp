#include "Application.h"

Application::Application() {
	command = 0;
	countMC = 0;
	countEvent = 0;
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
			SearchMC();
			break;
		case 4:
			displayAllMC();
			break;
		case 5:
			MakeEmptyMC();
			break;
		case 6:
			FindEventDisplayMC();
			break;
		case 7:
			DisplayEvent();
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
	MC_List.PrintTree(cout);
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t--- ID - Command -----" << endl;
	cout << "\t    1. Add MC" << endl;
	cout << "\t    2. Delete MC" << endl;
	cout << "\t    3. Search MC" << endl;
	cout << "\t    4. Print MC" << endl;
	cout << "\t    5. Make MC Empty" << endl;
	cout << "\t    6. Find Event and Display All MC" << endl;
	cout << "\t    7. Print Event" << endl;
	cout << "\t    0. Quit" << endl << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::AddMC() {

	// Add MultimediaContent
	MultimediaContent addTarget;
	addTarget.SetRecordFromKB(); // input by keyboard
	addTarget.SetRecord();		 // automatically set up

	MC_List.Add(addTarget);
	countMC++;

	// Add Event
	Event eventItem;
	eventItem.SetRecord(addTarget);
	eventItem.Add(addTarget);	// 먼저 이벤트에 add하고
	eventList.Add(eventItem);	// 이벤트 list에 add한다
	countEvent++;

	cout << "\n\t*****Multimedia Content List*****" << endl;
	MC_List.PrintTree(cout); 
	cout << endl;

	cout << "\n\t*****Event List*****" << endl;
	eventList.PrintTree(cout);
	cout << endl;

}

void Application::DeleteMC() { // 해당 ID를 갖는 MC 하나만 삭제

	cout << "\n\tChoose Content to Delete" << endl;
	MC_List.PrintTree(cout);

	// setup delete target : MC
	MultimediaContent deleteTargetMC; bool found = false;
	deleteTargetMC.SetIdFromKB(); // input

	MC_List.RetrieveItem(deleteTargetMC, found);
	if (found == true) {

		Event deleteTargetEv; found = false;
		deleteTargetEv.SetRecord(deleteTargetMC);
		eventList.RetrieveItem(deleteTargetEv, found);
		if (found == true) {
			eventList.DeleteItem(deleteTargetEv);
		}
		MC_List.DeleteItem(deleteTargetMC);
		
		// print res
		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.PrintTree(cout);
		cout << "\n\t*****Event List*****" << endl;
		eventList.PrintTree(cout);
	}
	else {
		cout << "\n\tNot Found" << endl;
	}
}

void Application::SearchMC() {

	MultimediaContent searchTarget; bool found = false;
	searchTarget.SetIdFromKB(); // input

	MC_List.RetrieveItem(searchTarget, found);
	if (found == true) {
		cout << "\n\tFound!" << endl;
		searchTarget.DisplayRecordOnScreen();
	}
	else cout << "\n\tNot Found!" << endl;
}

// Lab08 구현 조건 아님 // 일단 제외하고 구현하겠습니다.
//void Application::ReplaceMC() {
//
//	cout << "\n\tChoose Content to Replace" << endl;
//	MC_List.PrintTree(cout);
//
//	MultimediaContent replaceTarget; bool found = false;
//	replaceTarget.SetIdFromKB();
//	MC_List.RetrieveItem(replaceTarget, found);
//
//	if (found == true) {
//		MultimediaContent preItem = replaceTarget; // item : before replace
//
//		cout << "\n\tEnter New info" << endl;
//		string pk = replaceTarget.GetId();
//		replaceTarget.SetId(pk);
//		replaceTarget.SetRecordFromKB();
//		replaceTarget.SetName();
//
//		Event eventItem; // set new Item by new info
//		eventItem.SetRecord(replaceTarget);
//
//	}
//
//	MC_List.Replace(replaceTarget, foundMC);
//	eventItem.Replace(replaceTarget);	// event 바꾸고
//
//
//	if (check == 1) { // success find
//
//		//cout << "\n\tEnter New info" << endl;
//		//string pk = replaceTarget.GetId();
//		//replaceTarget.SetId(pk);
//		//replaceTarget.SetRecordFromKB();
//		//replaceTarget.SetName();
//
//		//Event eventItem;
//		//eventItem.SetRecord(replaceTarget);
//
//		//MC_List.Replace(replaceTarget);
//		//eventItem.Replace(replaceTarget);	// event 바꾸고
//
//
//		// 1) 새롭게 바꾼 event가 기존 eventList에 존재하는지 check
//		check = SetEventName(eventItem.GetEventName());
//
//
//		// 2) 해당 event를 eventList에서 뺸다 (delete)
//		eventList.Delete(eventItem);
//
//
//		// 3) 존재하지 않는다면 > 해당 event를 eventList에 삽입 (add)
//		if (check == 0) {
//			eventList.Add(eventItem);
//		}
//
//		cout << "\n\t*****Multimedia Content List*****" << endl;
//		MC_List.PrintTree(cout); // print all
//		cout << endl;
//
//		cout << "\n\t*****Event List*****" << endl;
//		eventList.PrintTree(cout); // print all
//		cout << endl;
//
//	}
//	else if (check == 0) { // fail find
//		cout << "\n\tCannot find the data" << endl;
//		cout << "\n\tReplace Fail" << endl;
//	}
//
//}

void Application::displayAllMC() {
	MC_List.PrintTree(cout);
}

void Application::DisplayEvent() {
	eventList.PrintTree(cout);
}

void Application::FindEventDisplayMC() { // 이벤트 이름 입력받고 >> eventList에서 찾고 >> 찾은 event에 소속된 Multimedia Contents의 "자세한" 정보를 화면에 출력

	cout << "Choose Event" << endl;
	eventList.PrintTree(cout);

	// 1) Event이름 입력받고
	Event item;
	item.SetEventFromKB();

	// 2) EventList에서 해당 Event이름을 가지는 Event객체를 찾고
	int foundEv = GetEvent(item);
	if (foundEv == 0) {
		cout << "\ncannot find event in eventList" << endl;
	}
	else { // 찾는 eventName을 갖는 event객체가 존재한다면

		MC_Info* eventList = item.GetEventList();
		int cntMC = item.GetLength();

		string pk;
		cout << "\nDisplay " << item.GetEventName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			pk = eventList[i].pk;
			cout << "PK : " << pk << endl;

			// 3) 각각의 pk로 >> 모든 Multimedia Content를 찾아서 >> 출력
			MultimediaContent dummy; bool foundMC = false;
			dummy.SetId(pk);

			MC_List.RetrieveItem(dummy, foundMC);
			if (foundMC == true) {
				dummy.DisplayRecordOnScreen();
			}
			else {
				cout << "Not Exist" << endl;
			}
		}
	}
}

int Application::GetEvent(Event& _event) {

	bool found = false;
	eventList.RetrieveItem(_event, found);

	if (found) return 1;	// 이미 존재하는 이벤트 이름 >> 추가불가
	else return 0;			// 존재하지 않는 이벤트 이름 >> 추가가능

}