#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "SortedList.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:

	/**
	*	default constructor.
	*/
	Application() {
		m_Command = 0;
	}

	/**
	*	destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	none
	*/
	void AddContents();

	/**
	*	@brief	delete the given record into list.
	*	@pre	list should be initialized.
	*	@post	the given record is deleted out the list.
	*	@return	none
	*/
	void DeleteContents();

	/**
	*	@brief	replace the given record in the list.
	*	@pre	list should be initialized.
	*	@post	the given record is replaced out the list.
	*	@return	none
	*/
	void ReplaceItem();

	/**
	*	@brief	search the given record sequencially in the list.
	*	@pre	list should be initialized.
	*	@post	the given record is sequencially searched in the list.
	*	@return	none
	*/
	void SearchById_SequenceSearch();

	/**
	*	@brief	binary search the given record in the list.
	*	@pre	list should be initialized.
	*	@post	the given record is binary searched in the list.
	*	@return	none
	*/
	void SearchByID_BinarySearch();

	/**
	*	@brief	search the given record by name in the list.
	*	@pre	list should be initialized.
	*	@post	the given name of the record is searched in the list.
	*	@return	none
	*/
	void SearchByName();

	/**
	*	@brief	search the given record by name in the list.
	*	@pre	list should be initialized.
	*	@post	the given name of the record is searched in the list.
	*	@return	none
	*/
	void SearchAllItmeByName(ItemType& inData);

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContents();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif _APPLICATION_H