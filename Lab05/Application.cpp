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
			ReplaceMC();
			break;
		case 4:
			displayAllMC();
			break;
		case 5:
			MakeEmptyMC();
			break;
		case 6:

			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		case 10:
			DisplayEvent();
			break;
		case 11:
			FindEventDisplayMC();
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


	cout << "\t    10. Print Event" << endl;
	cout << "\t    11. Find Event and Display All MC" << endl;
	cout << "\t    0. Quit" << endl << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::AddMC() {

	MultimediaContent addTarget;
	addTarget.SetRecordFromKB(); // input by keyboard
	addTarget.SetRecord();		 // automatically set up

	int check = MC_List.Add(addTarget); // add
	countMC++;

	if (check == 1) { // success

		Event eventItem;
		eventItem.SetRecord(addTarget);

		check = SetEventName(eventItem.GetEventName()); // error

		if (check == 0) {




			/// <summary>
			/// /////////////////error : eventList에 event객체 연결 안 됨 >> event객체부터 확인
			/// </summary>
			eventItem.Add(addTarget);	// 먼저 이벤트에 add하고
			eventList.Add(eventItem);	// 이벤트 list에 add한다
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

		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Event List*****" << endl;
		eventList.DisplayAll(); // print all
		cout << endl;

	}

}

void Application::DeleteMC() { // 해당 ID를 갖는 MC 하나만 삭제

	cout << "\n\tChoose Content to Delete" << endl;
	MC_List.DisplayAll();

	// setup delete target : MC
	MultimediaContent deleteTarget;
	deleteTarget.SetIdFromKB(); // input
	MC_List.Retrieve(deleteTarget);	// deleteTarget에 id만 있었는데 > MC 전체내용 복사함


	// setup delete target : Event
	Event EventItem;
	EventItem.SetRecord(deleteTarget);
	GetEvent(EventItem); // EventList에 걸려있는 해당 Event객체node를 그대로 받아와서 쓴다

	/*cout << "FOR CHECK" << endl;
	cout << EventItem << endl;*/
	// >> 결과 못 찾아서


	// 1) MC_List 안에서 해당 id를 갖는 contents 삭제
	MC_List.Delete(deleteTarget);
	countMC--;

	// 2) 해당 ID(pk)를 갖는 Event객체 안의 MC정보 삭제
	EventItem.Delete(deleteTarget);	// Event 객체에서 지운다


	// 3) EventList 안에서 해당 id를 갖는 contents 삭제
	eventList.Delete(EventItem);	// Evnet List에서 지운다
	countEvent--;


	// print res
	if (MC_List.IsEmpty()) {
		cout << "\n\tMultimedia Content List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;
	}

	if (eventList.IsEmpty()) {
		cout << "\n\Event List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Event List*****" << endl;
		eventList.DisplayAll(); // print all
		cout << endl;
	}

}

void Application::ReplaceMC() {

	cout << "\n\tChoose Content to Replace" << endl;
	MC_List.DisplayAll();

	MultimediaContent replaceTarget; // item : after replace
	replaceTarget.SetIdFromKB();

	int check = MC_List.Retrieve(replaceTarget);
	MultimediaContent preItem = replaceTarget; // item : before replace
	if (check == 1) { // success find

		cout << "\n\tEnter New info" << endl;
		string pk = replaceTarget.GetId();
		replaceTarget.SetId(pk);
		replaceTarget.SetRecordFromKB();
		replaceTarget.SetName();

		Event eventItem;
		eventItem.SetRecord(replaceTarget);

		MC_List.Replace(replaceTarget);
		eventItem.Replace(replaceTarget);	// event 바꾸고


		// 1) 새롭게 바꾼 event가 기존 eventList에 존재하는지 check
		check = SetEventName(eventItem.GetEventName());


		// 2) 해당 event를 eventList에서 뺸다 (delete)
		eventList.Delete(eventItem);


		// 3) 존재하지 않는다면 > 해당 event를 eventList에 삽입 (add)
		if (check == 0) {
			eventList.Add(eventItem);
		}

		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Event List*****" << endl;
		eventList.DisplayAll(); // print all
		cout << endl;

	}
	else if (check == 0) { // fail find
		cout << "\n\tCannot find the data" << endl;
		cout << "\n\tReplace Fail" << endl;
	}

}

void Application::displayAllMC() {
	MC_List.DisplayAll();
}

void Application::DisplayEvent() {
	eventList.DisplayAll();
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
		int cntMC = item.GetLength();

		string pk;
		cout << "\nDisplay " << item.GetEventName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			pk = eventList[i].pk;
			cout << "PK : " << pk << endl;

			// 4) 각각의 pk로 >> 모든 Multimedia Content를 찾아서 >> 출력
			MultimediaContent dummy;
			DoublyIterator<MultimediaContent> iter(MC_List);

			while (iter.NotNull()) {

				if (dummy.GetId() == iter.GetCurrentNode().data.GetId()) {
					dummy.DisplayRecordOnScreen(); cout << endl;
				}
				else {
					iter.Next();
				}

			}
		}
	}

}


int Application::SetEventName(string _eventName) {

	Event dummy;
	DoublyIterator<Event> iter(eventList);

	bool found = false;
	while (iter.NotNull() && !found) {
		if (_eventName == dummy.GetEventName()) {
			found = true;
			break;
		}
		else {
			iter.Next();
		}

		if (!iter.NextNotNull()) break;
	}

	if (found) return 1;	// 이미 존재하는 이벤트 이름 >> 추가불가
	else return 0;			// 존재하지 않는 이벤트 이름 >> 추가가능
}

int Application::GetEvent(Event& _event) {

	Event dummy;
	DoublyIterator<Event> iter(eventList);

	bool found = false;
	while (iter.NotNull() && !found) {
		if (iter.GetCurrentNode().data.GetEventName() == _event.GetEventName()) {
			_event = dummy;
			found = true;
			break;
		}
		else {
			iter.Next();
		}
	}

	if (found) return 1;	// 이미 존재하는 이벤트 이름 >> 추가불가
	else return 0;			// 존재하지 않는 이벤트 이름 >> 추가가능

}