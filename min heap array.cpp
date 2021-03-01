#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

class minHeap
{
private:
	int size;
	int capacity;
	vector<int> heap;

	int parent(int i)
	{
		return (i - 1 ) / 2;
	}
	int left(int i)
	{
		return 2 * i + 1 ;
	}
	int right(int i)
	{
		return 2 * i + 2;
	}

public:

	minHeap();  // constructor
	void insert(int k);
     int extractMin();
	 void heapify(int i);
     void printHeap(); 

};
minHeap:: minHeap() //constructor
{
	size =0;
	heap.resize= capacity;
	this->capacity = capacity;
}

void minHeap:: insert(int k)
{
	if (size == capacity )
	{
		cout<<"Min Heap is FULL "<<endl;
		   return;
	}
	size++;
	int i = size - 1;
	heap[i] = k;

	while (i != 0 && heap[parent(i)] > heap[i])
	{
		swap(heap[i], heap[parent(i)] > heap[i])
		{
			i = parent(i);
		}
	}
}



int main()
{
	minHeap m;


	system("pause");
	return;
}