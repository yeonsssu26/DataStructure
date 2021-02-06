#include "Application.h"

void Application::Run() {
	while (1) {
		m_Command = GetCommand();

		switch (m_Command) {
		case 1:
			AddContents(); break;			// ������ ������ �Է¹޾� ����Ʈ�� �߰�
		case 2:
			DeleteContents(); break;		// �������� �̸��� �Է¹޾� ����Ʈ���� ����
		case 3:
			ReplaceContents(); break;		// �������� ������ ���� �Էµ� ������ ����
		case 4:
			RetrieveContents(); break;		// �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش� �������� ã�� ȭ�鿡 ���
		case 5:
			DisplayAllContents(); break;	// ����Ʈ�� ����� ��� �������� ȭ�鿡 ���
		case 6:
			MakeEmpty(); break;				// ����Ʈ�� �Էµ� ��� ������ ����
		case 7:
			ReadDataFromFile(); break;		// load list data from a file
		case 8:
			WriteDataToFile(); break;		// save list data into a file
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n"; break; // ����ó��
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command -----" << endl;
	cout << "\t 1 : Add Content" << endl;
	cout << "\t 2 : Delete Content" << endl;
	cout << "\t 3 : Replace Content" << endl;
	cout << "\t 4 : Print Content info" << endl;
	cout << "\t 5 : Print all on screen" << endl;
	cout << "\t 6 : Make empty list" << endl;
	cout << "\t 7 : Get from file" << endl;
	cout << "\t 8 : Put to file" << endl;
	cout << "\t 0 : Quit" << endl;

	cout << endl << "\tChoose a Command-->";
	cin >> command;
	cout << endl;

	return command;
}

void Application::AddContents() { // case 1

	if (m_List.IsFull()) {
		cout << "fail to add the content\nArray is full" << endl;
	}
	else {
		ItemType item;
		item.SetRecordFromKB();	// input the new record

		int checkAdd = m_List.Add(item); // add the new record

		if (checkAdd == -1) { // fail to add
			cout << "fail to add the content\nthe content is already Exist";
		}
		else { // success to add
			cout << "success add" << endl;
			DisplayAllContents();	// print output
		}
	}
}

void Application::DeleteContents() { // case 2

	ItemType item;
	item.SetIdFromKB(); // input the record which is deleted

	int checkDelete = m_List.Delete(item); // delete the record

	if (checkDelete == -1) { // fail to delete
		cout << "fail to delete the content\nthe content is not exist" << endl;
	}
	else { // success to delete
		cout << "success delete" << endl;
		DisplayAllContents(); // print output
	}
}

void Application::ReplaceContents() { // case 3

	cout << "Enter new content info" << endl;

	ItemType item;
	item.SetRecordFromKB(); // input the new info of the record

	int checkReplace = m_List.Replace(item); // replace the record
	if (checkReplace == -1) { // fail to replace
		cout << "fail to replace the content\nthe content is not exist" << endl;
	}
	else { // success to replace
		cout << "success replace" << endl;
		DisplayAllContents(); // print output
	}
}

void Application::RetrieveContents() { // case 4

	ItemType item;
	item.SetIdFromKB(); // input the data which is searched

	int checkRetrieve = m_List.Retrieve(item); // search
	if (checkRetrieve == -1) { // fail to search
		cout << "fail to retrieve the content\n" << endl;
	}
	else { // success to search
		cout << "success retrieve" << endl;
		DisplayAllContents(); // print output
	}
}

void Application::DisplayAllContents() { // case 5

	cout << "\n\tCurrent list" << endl;

	m_List.ResetPointer(); // m_curPointer = -1
	ItemType data;
	int currIdx = m_List.GetNextItem(data); // m_curPointer = 0
	int len = m_List.GetLength();
	while (currIdx != -1 && currIdx < len) { // currIdx�� -1�� �ƴ� ���� ��ü ���̺��� ���� ���� loop�� ����
		data.DisplayRecordOnScreen(); // print record of the current index
		currIdx = m_List.GetNextItem(data); // currIdx++
	}
}

void Application::MakeEmpty() { // case 6
	m_List.MakeEmpty(); // make list empty
}

int Application::OpenInFile(char* fileName) {

	m_InFile.open(fileName);

	if (!m_InFile)
		return 0; // file open fail
	return 1; // file open success
}

int Application::OpenOutFile(char* fileName) {

	m_OutFile.open(fileName);

	if (!m_OutFile)
		return 0; // file open fail
	return 1; // file open success
}

int Application::ReadDataFromFile() { // case 7

	int idx = 0;
	ItemType data; // �б�� �ӽú���

	char fileName[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : "; cin >> fileName;

	// file open
	if (!OpenInFile(fileName))
		return 0; // file open error

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof()) {

		data.ReadDataFromFile(m_InFile);	// ���Ͽ��� �л� ���� �о����

		if (m_InFile.eof()) break; // ������ ���ڿ����� �Ǵ� �� while�� ����

		m_List.Add(data);
	}

	// file close
	m_InFile.close();

	// ���� list ���
	DisplayAllContents();

	return 1; // success
}

int Application::WriteDataToFile() { // case 8

	ItemType data; // ����� �ӽú���

	char fileName[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : "; cin >> fileName;

	// file open
	if (!OpenOutFile(fileName)) {
		return 0; // fail
	}

	m_List.ResetPointer(); // list pointer �ʱ�ȭ

	// list�� ��� �����͸� ���Ͽ� ����
	int len = m_List.GetLength();
	int currIdx = m_List.GetNextItem(data);
	while (currIdx != -1 && currIdx < len) {
		data.WriteDataFromFile(m_OutFile);
		currIdx = m_List.GetNextItem(data);
	}

	m_OutFile.close(); // close file

	return 1; // success
}