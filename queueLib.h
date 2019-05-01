#ifndef QUEUELIB_H
#define QUEUELIB_H

template <class DT>
class queue
{
	DT *arr;
	int size;
	int front;
	int rear;
	int cap;

public:
	queue(int);

	void enQueue(DT);
	DT deQueue();
	bool isFull();
	bool isEmpty();
	DT getFront();

};

template <class DT>
queue<DT>::queue(int size)
{
	arr = new DT[size];
	this->size = size;
	front = 0;
	rear = 0;
	cap = 0;

}

template <class DT>
void queue<DT>::enQueue(DT data)
{
	if (!isFull())
	{
		arr[rear] = data;

		cap++;
		rear++;

		rear = rear%size;
	}
	else
	{
		cout << "\n Capacity is Full";
	}
}

template <class DT>
DT queue<DT>::deQueue()
{
	if (!isEmpty())
	{
		DT val;
		val = arr[front];

		front++;

		front = front%size;
		cap--;

		return val;
	}
	else
	{
		return -1;
	}
}


template <class DT>
bool queue<DT>::isFull()
{
	if (cap == size)
		return true;
	else
		return false;
}

template <class DT>
bool queue<DT>::isEmpty()
{
	if (cap == 0)
		return true;
	else
		return false;
}


template<class DT>
DT queue<DT>::getFront()
{
	if (!isEmpty())
	{
		int val;
		val = arr[front];

		return val;

	}
	else
	{
		return -1;
	}
}

#endif // !QUEUELIB_H
