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
			/// /////////////////error : eventList�� event��ü ���� �� �� >> event��ü���� Ȯ��
			/// </summary>
			eventItem.Add(addTarget);	// ���� �̺�Ʈ�� add�ϰ�
			eventList.Add(eventItem);	// �̺�Ʈ list�� add�Ѵ�
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

		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Event List*****" << endl;
		eventList.DisplayAll(); // print all
		cout << endl;

	}

}

void Application::DeleteMC() { // �ش� ID�� ���� MC �ϳ��� ����

	cout << "\n\tChoose Content to Delete" << endl;
	MC_List.DisplayAll();

	// setup delete target : MC
	MultimediaContent deleteTarget;
	deleteTarget.SetIdFromKB(); // input
	MC_List.Retrieve(deleteTarget);	// deleteTarget�� id�� �־��µ� > MC ��ü���� ������


	// setup delete target : Event
	Event EventItem;
	EventItem.SetRecord(deleteTarget);
	GetEvent(EventItem); // EventList�� �ɷ��ִ� �ش� Event��ünode�� �״�� �޾ƿͼ� ����

	/*cout << "FOR CHECK" << endl;
	cout << EventItem << endl;*/
	// >> ��� �� ã�Ƽ�


	// 1) MC_List �ȿ��� �ش� id�� ���� contents ����
	MC_List.Delete(deleteTarget);
	countMC--;

	// 2) �ش� ID(pk)�� ���� Event��ü ���� MC���� ����
	EventItem.Delete(deleteTarget);	// Event ��ü���� �����


	// 3) EventList �ȿ��� �ش� id�� ���� contents ����
	eventList.Delete(EventItem);	// Evnet List���� �����
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
		eventItem.Replace(replaceTarget);	// event �ٲٰ�


		// 1) ���Ӱ� �ٲ� event�� ���� eventList�� �����ϴ��� check
		check = SetEventName(eventItem.GetEventName());


		// 2) �ش� event�� eventList���� �A�� (delete)
		eventList.Delete(eventItem);


		// 3) �������� �ʴ´ٸ� > �ش� event�� eventList�� ���� (add)
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
		int cntMC = item.GetLength();

		string pk;
		cout << "\nDisplay " << item.GetEventName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			pk = eventList[i].pk;
			cout << "PK : " << pk << endl;

			// 4) ������ pk�� >> ��� Multimedia Content�� ã�Ƽ� >> ���
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

	if (found) return 1;	// �̹� �����ϴ� �̺�Ʈ �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �̺�Ʈ �̸� >> �߰�����
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

	if (found) return 1;	// �̹� �����ϴ� �̺�Ʈ �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �̺�Ʈ �̸� >> �߰�����

}