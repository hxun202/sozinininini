#include <iostream>

using namespace std;

template <typename T>

class Vector
{
private:
	int count;
	int capacity;

	T* pointer;

public:
	Vector()
	{
		count = 0;
		capacity = 0;
		pointer = nullptr;
	}

	void resize(int newSize)
	{
		for (int i = 0; i < capacity; i++)
		{

		}
	}
};

int main()
{
	Vector<int> vector;

	return 0;
}