#include<stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include<iostream>
#include <list>

using namespace std;



class HashEntry {
public:
	int key;
	int value;
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}
};

class HashMap {
private:
	HashEntry **table;
	int TABLE_SIZE;
public:
	HashMap(int TABLE_SIZE) {
		table = new HashEntry*[TABLE_SIZE];
		this->TABLE_SIZE = TABLE_SIZE;
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	int get(int key) {
		int hash = (key % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] == NULL)
			return -1;
		else
			return table[hash]->getValue();
	}

	void put(int key, int value) {
		int hash = (key % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}
	void rehash() {
		HashEntry **table1;
		int originalsize = TABLE_SIZE;
		table1 = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table1[i] = table[i];
		this->TABLE_SIZE = 2 * TABLE_SIZE;

		table = new HashEntry*[TABLE_SIZE];

		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
		for (int i = 0; i < originalsize; i++)
			if (table1[i] != NULL)
			{
				int val = table1[i]->getValue();
				int key = table1[i]->getKey();
				put(key, val);
			}
		for (int i = 0; i < originalsize; i++)
			if (table1[i] != NULL)
				delete table1[i];
		delete[] table1;
	}
	void display() {
		int a, b;
		for (int i = 0;i < TABLE_SIZE;i++)
		{
			
			{
				cout << table[i]->getValue();
			}
		}
	}
	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}
};

int partition(int a[], int start, int end)
{

	int pivot = a[end];
	int smallindex = start;
	for (int i = start;i < end;i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[smallindex]);
			smallindex++;
		}
	}
	swap(a[smallindex], a[end]);
	cout << endl;
	for (int i = 0;i < 8;i++)
		cout << a[i];
	cout << endl;
	return smallindex;

}

void quicksort(int a[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(a, start, end);
		quicksort(a, start, pivot - 1);
		quicksort(a, pivot + 1, end);
	}
}
int main() {
	
	HashMap a(10);
	a.put(5, 5);
	a.put(6, 5);
	
	cout << endl;
	cout <<a.get(5);
	a.rehash();
	a.display();
	a.put(3, 4);
	cout << a.get(3);
	
	return 0;
}
