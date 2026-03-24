#include <iostream>
#define SIZE 5

using namespace std;

template <typename T>

class Queue
{
private:
	int rear;
	int front;

	T container[SIZE];

public:
	Queue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "linear queue overflow" << endl;
		}
		else
		{
			container[rear++] = data;
		}
	}
};

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);
	queue.push(60);

	return 0;
}