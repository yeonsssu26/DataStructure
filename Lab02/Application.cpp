#include "Application.h"

void Application::Run() {
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddContents();
			break;
		case 2:		//delete
			DeleteContents();
			break;
		case 3:		//replace
			ReplaceItem();
			break;
		case 4:		//search by id.
			SearchById_SequenceSearch();
			break;
		case 5:	//search by binary search.
			SearchByID_BinarySearch();
			break;
		case 6:		//search by name.
			SearchByName();
			break;
		case 7:		// display all the records in list on screen.
			DisplayAllContents();
			break;
		case 8:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by Binary Search" << endl;
	cout << "\t   6 : Search item by name" << endl;
	cout << "\t   7 : Print all on screen" << endl;
	cout << "\t   8 : Make empty list" << endl;
	cout << "\t   9 : Get from file" << endl;
	cout << "\t   10 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::AddContents() { // case 1

	ItemType addTarget;
	addTarget.SetRecordFromKB();	// input

	int checkAdd = m_List.Add(addTarget); // add

	if (checkAdd == -1) { // fail
		cout << "\n\tfail to add the content\n\tthe content is already exist";
	}
	else if (checkAdd == -2) {
		cout << "\n\tfail to add the content\n\tthe list is full";
	}
	else { // success
		cout << "\n\tsuccess add" << endl << endl;
		DisplayAllContents();	// print output
	}
}

void Application::DeleteContents() { // case 2

	ItemType deleteTarget;
	deleteTarget.SetIdFromKB(); // input

	int checkDelete = m_List.Delete(deleteTarget); // delete

	if (checkDelete == -1) { // fail
		cout << "\n\tfail to delete the content\n\tthe content is not exist" << endl;
	}
	else if (checkDelete == -2) {
		cout << "\n\tfail to delete the content\n\tthe list is empty" << endl;
	}
	else {
		cout << "\n\tsuccess delete" << endl;
		DisplayAllContents(); // print output
	}

}

void Application::ReplaceItem() { // case 3

	cout << "Enter new content info" << endl;

	ItemType newData;
	newData.SetRecordFromKB();

	int checkReplace = m_List.Replace(newData);
	if (checkReplace == -1) {
		cout << "\n\tfail to replace the content\n\tthe content is not exist" << endl;
	}
	else if (checkReplace == -2) {
		cout << "\n\tfail to replace the content\n\tthe list is empty" << endl;
	}
	else {
		cout << "\n\tsuccess replace" << endl;
		DisplayAllContents(); // print output
	}
}

void Application::SearchById_SequenceSearch() { // case 4

	cout << "Enter search target " << endl;

	ItemType searchTarget; // find
	searchTarget.SetIdFromKB();

	int checkRetrieve = m_List.Retrieve_SequentialSearch(searchTarget);
	if (checkRetrieve == -1) {
		cout << "\n\tfail to retrieve the content\n" << endl;
	}
	else {
		cout << "\n\tsuccess retrieve" << endl;
		searchTarget.DisplayRecordOnScreen(); // print output
	}
}

void Application::SearchByID_BinarySearch() { // case 5

	cout << "Enter search target" << endl;

	ItemType searchTarget; // find
	searchTarget.SetIdFromKB();

	int checkRetrieve = m_List.Retrieve_BinarySearch(searchTarget);
	if (checkRetrieve == -1) {
		cout << "\n\tfail to retrieve the content\n" << endl;
	}
	else {
		cout << "\n\tsuccess retrieve" << endl;
		searchTarget.DisplayRecordOnScreen(); // print output
	}
}

void Application::SearchByName() { // case 6

	cout << "Enter search target ";

	ItemType searchTarget;
	searchTarget.SetNameFromKB();

	SearchAllItmeByName(searchTarget);

}

void Application::SearchAllItmeByName(ItemType& inData) { // case 6

	ItemType currItem; // tmp 변수
	int res = 0; // count name // res = 0 : fail to find

	m_List.ResetPointer();
	while (m_List.GetNextItem(currItem) != -1) {

		if (currItem.GetName().find(inData.GetName()) != -1) { //만약 해당 리스트의 이름에 inData의 이름이 존재하면
			if (res == 0) // 처음 찾은 경우 (같은 이름 여러개 가능)
				cout << "<============I FOUND ITEM !==========>" << endl;
			currItem.DisplayRecordOnScreen(); // print output
			res++;
		}
	}

	if (res == 0) // fail to find
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	else
		cout << "<====================================>" << endl;

}

void Application::DisplayAllContents() { // case 7

	cout << "\tdisplay all current contents" << endl << endl;

	m_List.ResetPointer();

	ItemType data;
	int currIdx = m_List.GetNextItem(data);

	for (int i = 0; i < m_List.GetLength(); i++) {
		data.DisplayRecordOnScreen();
		currIdx = m_List.GetNextItem(data);
	}

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
	ItemType data; // 읽기용 임시변수

	char fileName[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : "; cin >> fileName;

	// file open
	if (!OpenInFile(fileName))
		return 0; // file open error

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof()) {

		data.ReadDataFromFile(m_InFile);	// 파일에서 학생 정보 읽어오기

		if (m_InFile.eof()) break; // 마지막 문자열인지 판단 후 while문 종료

		m_List.Add(data);
	}

	// file close
	m_InFile.close();

	// 현재 list 출력
	DisplayAllContents();

	return 1; // success
}

int Application::WriteDataToFile() { // case 8

	ItemType data; // 쓰기용 임시변수

	char fileName[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : "; cin >> fileName;

	// file open
	if (!OpenOutFile(fileName)) {
		return 0; // fail
	}

	m_List.ResetPointer(); // list pointer 초기화

	// list의 모든 데이터를 파일에 쓰기
	int len = m_List.GetLength();
	int currIdx = m_List.GetNextItem(data);
	while (currIdx != -1 && currIdx < len) {
		data.WriteDataFromFile(m_OutFile);
		currIdx = m_List.GetNextItem(data);
	}

	m_OutFile.close(); // close file

	return 1; // success
}