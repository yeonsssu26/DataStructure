#include "Application.h"

Application::Application() {
	command = 0;
}

void Application::Run() {

	while (1)
	{
		try {
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
				MakeEmptyMC();
				break;
			case 5:
				AddFC();
				break;
			case 6:
				DeleteFC();
				break;
			case 7:
				ReplaceFC();
				break;
			case 8:
				MakeEmptyFC();
				break;
			case 9:
				PrintEvent();
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
		catch (FullQueue e)
		{
			e.print();
		}

		catch (EmptyQueue e)
		{
			e.print();
		}

	}

}

void Application::MakeEmptyMC()
{
	MC_List.MakeEmpty();
	MC_List.Print();
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
	cout << "\t    4. Make MC Empty" << endl;
	cout << "\t    5. Add FC" << endl;
	cout << "\t    6. Delete FC" << endl;
	cout << "\t    7. Replace FC" << endl;
	cout << "\t    8. Make FC Empty" << endl;
	cout << "\t    9. Print Event" << endl;
	cout << "\t    0. Quit" << endl << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::AddMC() {

	MultimediaContent addTarget;
	addTarget.SetRecordFromKB(); // input

	int check = MC_List.EnQueue(addTarget); // add

	if (check == 1) { // success
		event.Add(addTarget);
		MC_List.Print(); // print all
	}

}

void Application::DeleteMC() {

	MultimediaContent deleteTarget;
	deleteTarget.SetRecordFromKB(); // input

	int check = MC_List.DeQueue(deleteTarget); // add

	if (check == 1) { // success
		event.Delete(deleteTarget);
		MC_List.Print(); // print all
	}

}

void Application::ReplaceMC() {

	cout << "Enter New info (DON'T CHANGE PK)" << endl;

	MultimediaContent replaceTarget;
	replaceTarget.SetRecordFromKB();

	int check = MC_List.Replace(replaceTarget);

	if (check == 1) { // success
		event.Replace(replaceTarget);
		MC_List.Print(); // print all
	}

}

void Application::AddFC() {

	cout << "Choose Content to Add" << endl << endl;
	MC_List.Print();

	MultimediaContent item;
	item.SetRecordFromKB();
	int idx = MC_List.Retrieve(item);

	if (idx == -1) {
		cout << "not exist" << endl;
	}
	else {
		FavoriteContent addTarget;
		addTarget.SetRecord(item);

		int check = FC_List.EnQueue(addTarget); // add

		if (check == 1) { // success
			cout << "Success Add to FC" << endl << endl;
			FC_List.Print(); // print all
		}
	}
}

void Application::DeleteFC() {

	cout << "Choose Content to Delete" << endl << endl;
	MC_List.Print();

	MultimediaContent item;
	item.SetRecordFromKB();
	int idx = MC_List.Retrieve(item);

	if (idx == -1) {
		cout << "not exist" << endl;
	}
	else {
		FavoriteContent deleteTarget;
		deleteTarget.SetRecord(item);

		int check = FC_List.DeQueue(deleteTarget); // delete

		if (check == 1) { // success
			cout << "Success Add to FC" << endl << endl;
			FC_List.Print(); // print all
		}
	}
}

void Application::ReplaceFC() {

	cout << "Choose Content to Replace" << endl << endl;
	MC_List.Print();

	MultimediaContent item;
	item.SetRecordFromKB();
	int idx = MC_List.Retrieve(item);

	if (idx == -1) {
		cout << "not exist" << endl;
	}
	else {
		FavoriteContent replaceTarget;
		replaceTarget.SetRecord(item);

		int check = FC_List.Replace(replaceTarget); // delete

		if (check == 1) { // success
			cout << "Success replace to FC" << endl << endl;
			FC_List.Print(); // print all
		}
	}

}

void Application::MakeEmptyFC()
{
	FC_List.MakeEmpty();
	FC_List.Print();
}

void Application::PrintEvent() {
	cout << "Event" << endl;
	event.Print();

}