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

template <class RecordType>	//generic data을 위해 template 선언
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
	int MaxQueue; // reserved space를 포함한 전체크기
	RecordType* items;	// Pointer for a stack.
};

template<class RecordType>
CircularQueueType<RecordType>::CircularQueueType(void) {

	// maxsize는 reserved space를 제외
	// MaxQueue는 reserved space를 포함
	MaxQueue = maxsize + 1;

	// idx == MaxQueue는 reserved space로 쓴다
	// 초기화 : front == rear
	front = MaxQueue - 1;
	rear = MaxQueue - 1;

	// 원형큐 동적할당
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

	// 원형큐 동적할당 해제
	delete[] items;

}

template<class RecordType>
bool CircularQueueType<RecordType>::IsFull() const {

	return ((rear + 1) % MaxQueue == front);

	/*if ((rear + 1) % MaxQueue == front) return true;		// 위와 동일함
	else return false;*/

}

template<class RecordType>
bool CircularQueueType<RecordType>::IsEmpty()const {

	return (front == rear);

	/*if (front == rear) return true;		// 위와 동일함
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
	// front = rear; // 둘 중 어떤 걸 선택하든 상관없음

}

template<class RecordType>
void CircularQueueType<RecordType>::Print() {

	if (IsEmpty()) {
		//throw EmptyQueue(); // Empty Stack을 throw하면 프로그램이 종료되어서 다시 Enqueue할 수 없음
		cout << "Empty Queue!" << endl;
	}
	else {
		cout << "\n*****print*****" << endl << endl;
		int start = front, end = rear;
		while (start != end) {

			// 이 순서가 맞음 : while break 조건 때문
			cout << items[(start + 1) % MaxQueue] << endl;
			start = (start + 1) % MaxQueue;

		}cout << endl;
	}

}

#endif _QUEUE_H