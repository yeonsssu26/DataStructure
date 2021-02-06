#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <fstream>
#include <string>

#define maxsize 5

using namespace std;


class FullQueue
{
public:
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


class EmptyQueue
{
public:
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

template <class RecordType>	//generic data�� ���� template ����
class CircularQueueType
{
public:
	CircularQueueType(void); // default constructor
	CircularQueueType(int _maxsize); // constructor which has size parameter
	~CircularQueueType(void); // destructor
	bool IsFull() const;
	bool IsEmpty() const;
	int EnQueue(RecordType item);
	int DeQueue(RecordType& item);
	int Retrieve(RecordType item);
	RecordType ReturnRetrieve(int id);
	int Replace(RecordType item);
	void MakeEmpty();
	void Print();

private:
	int front;
	int rear;
	int MaxQueue; // reserved space�� ������ ��üũ��
	RecordType* items;	// Pointer for a stack.
};

template<class RecordType>
CircularQueueType<RecordType>::CircularQueueType(void) {

	// maxsize�� reserved space�� ����
	// MaxQueue�� reserved space�� ����
	MaxQueue = maxsize + 1;

	// idx == MaxQueue�� reserved space�� ����
	// �ʱ�ȭ : front == rear
	front = MaxQueue - 1;
	rear = MaxQueue - 1;

	// ����ť �����Ҵ�
	items = new RecordType[MaxQueue];

}

template<class RecordType>
CircularQueueType<RecordType>::CircularQueueType(int _maxsize) {

	MaxQueue = _maxsize + 1;

	front = MaxQueue - 1;
	rear = MaxQueue - 1;

	items = new RecordType[MaxQueue];

}

template<class RecordType>
CircularQueueType<RecordType>::~CircularQueueType(void) {

	// ����ť �����Ҵ� ����
	delete[] items;

}

template<class RecordType>
bool CircularQueueType<RecordType>::IsFull() const {

	return ((rear + 1) % MaxQueue == front);

	/*if ((rear + 1) % MaxQueue == front) return true;		// ���� ������
	else return false;*/

}

template<class RecordType>
bool CircularQueueType<RecordType>::IsEmpty()const {

	return (front == rear);

	/*if (front == rear) return true;		// ���� ������
	else return false;*/

}

template<class RecordType>
int CircularQueueType<RecordType>::EnQueue(RecordType item) {

	if (IsFull()) {
		throw FullQueue();	// error
		return 0;			// fail
	}
	else {

		rear = (rear + 1) % MaxQueue;	// move rear
		items[rear] = item;				// insert item to circular queue
		return 1;

	}

}

template<class RecordType>
int CircularQueueType<RecordType>::DeQueue(RecordType& item) {

	if (IsEmpty()) {
		throw EmptyQueue(); // error
		return 0;			// fail
	}
	else {

		front = (front + 1) % MaxQueue; // move front
		item = items[front]; // copy deleted item
		return 1; // success

	}

}

template <class RecordType>
int CircularQueueType<RecordType>::Retrieve(RecordType item) {

	for (int i = 0; i < maxsize; i++) {
		if (items[i] == item) {
			return i; // success
		}
	}

	return -1; // fail
}

template<class RecordType>
int CircularQueueType<RecordType>::Replace(RecordType item) {

	int idx = Retrieve(item); // find idx of the replace target content

	if (idx == -1) {
		cout << "\tfail replace\n\tthe replace target content is not exist" << endl; // fail > print error message
		return 0; // fail
	}
	else {
		items[idx] = item; // success > replace
		return 1; // success
	}

}

template<class RecordType>
void CircularQueueType<RecordType>::MakeEmpty() {

	rear = front;
	// front = rear; // �� �� � �� �����ϵ� �������

}

template<class RecordType>
void CircularQueueType<RecordType>::Print() {

	if (IsEmpty()) {
		//throw EmptyQueue(); // Empty Stack�� throw�ϸ� ���α׷��� ����Ǿ �ٽ� Enqueue�� �� ����
		cout << "Empty Queue!" << endl;
	}
	else {
		cout << "\n*****print*****" << endl << endl;
		int start = front, end = rear;
		while (start != end) {

			// �� ������ ���� : while break ���� ����
			cout << items[(start + 1) % MaxQueue] << endl;
			start = (start + 1) % MaxQueue;

		}cout << endl;
	}

}

#endif _QUEUE_H