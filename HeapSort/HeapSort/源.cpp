#include<cstdio>
#include<iostream>

using namespace std;

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void Heapify(int A[], int i, int size)
{
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	int max = i;

	if (left_child<size && A[left_child]>A[max])
	{
		max = left_child;
	}
	if (right_child<size && A[right_child]>A[max])
	{
		max = right_child;
	}

	if (i != max)
	{
		Swap(A, i, max);
		Heapify(A, max, size);
	}
}

void BuildHeap(int A[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
		Heapify(A, i, n);//从上往下堆排序，只能保证当前最大值点在上面，保证不了绝对最大值点在上面。即容易导致上面的点有可能要小于下面的点

	return;

}

void HeapSort(int A[], int n)//n是数组A中，元素的个数
{
	BuildHeap(A, n);
	int heap_size = n;
	while (heap_size > 1)
	{
		--heap_size;
		Swap(A, 0, heap_size);
		Heapify(A, 0, heap_size);//Heapify(A, 0, heap_size-1)是错的！！！！！！！！！！
	}
}

int main()
{
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		A[i] = temp;
	}
	HeapSort(A, n);
	for (int i = 0; i < n; ++i)
		printf("%d", A[i]);
	delete[] A;
	return 0;
}
