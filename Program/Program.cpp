#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	int size;
	int capacity;

	Bucket* bucket;

public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket[capacity];

		for (int i = 0; i < capacity; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}

	template <typename KEY>
	unsigned int hash_fuction(KEY key)
	{
		return (unsigned int)key % capacity;
	}

	template<>
	unsigned int hash_fuction(const char* key)
	{
		unsigned int sum = 0;

		for (int i = 0; *key != '\0'; i++)
		{
			sum += key[i];

			key = key + 1;
		}

		return sum % capacity;
	}

	void insert(KEY key, VALUE value)
	{
		// 해쉬 함수를 통해서 값을 받는 임시 변수
		int hashIndex = hash_fuction(key);

		// 새로운 노드를 생서합니다.
		Node* newNode = new Node;

		newNode->key = key;

		newNode->value = value;

		newNode->next = nullptr;

		// 노드가 1개라도 존재하지 않는다면 
		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]의 head 포인터가 newNode를 가리키게 합니다.
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		// bucket[hashIndex]의 count를 증가시킵니다.
		bucket[hashIndex].count++;

		size++;
	}

	const int& bucket_count()
	{
		return capacity;
	}

	const float& load_factor()
	{
		return size;
	}
};

int main()
{
	HashTable<const char *, int> hashtable;

	hashtable.insert("Abyssal Mask", 3000);
	hashtable.insert("Bami's Cinder", 1000);
	hashtable.insert("Chain Vest", 800);

	return 0;
}