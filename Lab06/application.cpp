#include "Application.h"
#include <iomanip>

void Application::Run()
{
	ContentsType* newData;
	int ex = 1;
	int command;
	while (1)
	{
		newData = NULL;
		command = GetCommand();

		switch (command)
		{
		case 0:
			ex = 0;
			return;
		case 1:
			newData = new Music();
			newData->read();
			break;
		case 2:
			newData = new Music();
			break;
		case 3:
			newData = new Picture();
			break;
		case 4:
			newData = new Picture();
			break;
		case 5:
			newData = new Video();
			break;
		case 6:
			newData = new Video();
			break;
		case 7:
			DisplayAll();
			break;
		default:
			cout << " Invalid Command. Try Again \n";
		}
		if (newData != NULL)
		{
			//newData->print();
			m_List.Add(newData);
		}
		cout << "\n";
	}
}

#define MAXCOMMANDS 4

int Application::GetCommand() {
	int select;
	while (1) {
		cout << "\t=" << setw(41) << setfill('=') << "=\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  0: Quit" << "|\n";

		cout << "\t|" << left << setw(40) << setfill(' ') << "  1: ���� �����ϱ�" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  2: ���� ��Ϻ���" << "|\n";

		cout << "\t|" << left << setw(40) << setfill(' ') << "  3: ���� �����ϱ�" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  4: ���� ��Ϻ���" << "|\n";

		cout << "\t|" << left << setw(40) << setfill(' ') << "  5: ������ �����ϱ�" << "|\n";
		cout << "\t|" << left << setw(40) << setfill(' ') << "  6: ������ ��Ϻ���" << "|\n";

		cout << "\t|" << left << setw(40) << setfill(' ') << "  7: ��ü ����" << "|\n";
		cout << "\t=" << right << setw(41) << setfill('=') << "=\n";
		cout << "\t  Select a function --> ";

		if (cin.fail() || !(cin >> select) || select < 0 || select>MAXCOMMANDS)	// input fail or input value is out of bound
		{
			cout << "\t    ### Invalid Command Number. Select again  ####" << endl;
			cin.clear();	//clear flag
			cin.ignore(INT_MAX, '\n');	//empty input buffer
		}
		else {
			cin.clear();  // clear flag
			cin.ignore(INT_MAX, '\n');  // empty input buffer
			return select;
		}
	}
}


void Application::DisplayAll()
{
	// list�� ��� �����͸� ȭ�鿡 ���
	ContentsType* data;
	DoublyIterator<ContentsType*> itor(m_List);
	data = itor.Next();
	while (itor.NextNotNull())
	{
		data->print();
		data = itor.Next();
	}
}