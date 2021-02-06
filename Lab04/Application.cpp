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
			AddFC();
			break;
		case 7:
			DeleteFC();
			break;
		case 8:
			displayAllFC();
			break;
		case 9:
			MakeEmptyFC();
			break;
		case 10:
			PrintEvent();
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
	cout << "\t    6. Add FC" << endl;
	cout << "\t    7. Delete FC" << endl;
	cout << "\t    8. Print FC" << endl;
	cout << "\t    9. Make FC Empty" << endl;
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

		// Add_MC������ FC_List�� �ڵ����� ������ �ȵ�

		Event eventItem;
		eventItem.SetRecord(addTarget);

		check = checkEventName(eventItem.GetEventName());
		if (check == 0) {
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


	// setup delete target : FC
	FavoriteContent FCitem;
	FCitem.SetRecord(deleteTarget);


	// setup delete target : Event
	Event EventItem;
	EventItem.SetRecord(deleteTarget);
	GetEvent(EventItem); // EventList�� �ɷ��ִ� �ش� Event��ünode�� �״�� �޾ƿͼ� ����


	// 1) MC_List �ȿ��� �ش� id�� ���� contents ����
	MC_List.Delete(deleteTarget);
	countMC--;


	// 2) FC_List �ȿ��� �ش� id�� ���� contents ����
	FC_List.Delete(FCitem);


	// 3) �ش� ID(pk)�� ���� Event��ü ���� MC���� ����
	EventItem.Delete(deleteTarget);	// Event ��ü���� �����


	// 4) EventList �ȿ��� �ش� id�� ���� contents ����
	eventList.Delete(EventItem);	// Evnet List���� �����
	countEvent--;


	// print res
	if (MC_List.isEmpty()) {
		cout << "\n\tMultimedia Content List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;
	}

	if (FC_List.isEmpty()) {
		cout << "\n\Favorite Content List is Empty" << endl;
	}
	else {
		cout << "\n\t*****Favorite Content List*****" << endl;
		FC_List.DisplayAll(); // print all
		cout << endl;
	}

	if (eventList.isEmpty()) {
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

		FavoriteContent FCitem;
		FCitem.SetRecord(replaceTarget);

		Event eventItem;
		eventItem.SetRecord(replaceTarget);

		MC_List.Replace(replaceTarget);
		FC_List.Replace(FCitem);
		eventItem.Replace(replaceTarget);	// event �ٲٰ�


		// 1) ���Ӱ� �ٲ� event�� ���� eventList�� �����ϴ��� check
		check = checkEventName(eventItem.GetEventName());


		// 2) �ش� event�� eventList���� �A�� (delete)
		eventList.Delete(eventItem);


		// 3) �������� �ʴ´ٸ� > �ش� event�� eventList�� ���� (add)
		if (check == 0) {
			eventList.Add(eventItem);
		}

		cout << "\n\t*****Multimedia Content List*****" << endl;
		MC_List.DisplayAll(); // print all
		cout << endl;

		cout << "\n\t*****Favorite Content List*****" << endl;
		FC_List.DisplayAll(); // print all
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
		item.SetIdFromKB();

		// ��ü ������ ���縦 ���� �޾ƿ���
		int check = MC_List.Retrieve(item);

		if (check == 0) {
			cout << "\n\tnot exist" << endl;
		}
		else {

			// MC item�� FC_List�� ����
			FavoriteContent addTarget;
			addTarget.SetRecord(item);
			int check = FC_List.Add(addTarget);

			cout << "\n\tSuccess Add to FC" << endl;
			FC_List.DisplayAll();

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
		FC_List.DisplayAll();

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
			int check = FC_List.Delete(deleteTarget);

			if (check == 1) { // success
				cout << "\n\tSuccess Delete from FC" << endl << endl;
				FC_List.DisplayAll(); // print all
			}
		}

	}

}

void Application::MakeEmptyFC()
{
	FC_List.MakeEmpty();
	FC_List.DisplayAll();

	cout << "\tMake Favorite Content List Empty SUCCESS!" << endl;
}

void Application::PrintEvent() {
	eventList.DisplayAll();
}

void Application::displayAllMC() {
	MC_List.DisplayAll();
}

void Application::displayAllFC() {
	FC_List.DisplayAll();
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
		cout << "\nDisplay " <<  item.GetEventName() << "'s Multimedia Contents" << endl;
		for (int i = 0; i < cntMC; i++) {

			pk = eventList[i].pk;
			cout << "PK : " << pk << endl;

			// 4) ������ pk�� >> ��� Multimedia Content�� ã�Ƽ� >> ���

			MultimediaContent dummy;
			MC_List.ResetPointer();
			MC_List.GetNextItem(dummy);

			MultimediaContent* curr = MC_List.GetDataLocation();

			bool moreToSearch, found;
			moreToSearch = (curr != NULL); found = false;

			while (moreToSearch && !found) {

				if (dummy.GetId() == pk) {

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
		}

	}

	if (found) return 1;	// �̹� �����ϴ� �̺�Ʈ �̸� >> �߰��Ұ�
	else return 0;			// �������� �ʴ� �̺�Ʈ �̸� >> �߰�����

}