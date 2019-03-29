#include<cstdio>
#include<iostream>

using namespace std;

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void SeletionSort(int A[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (A[j] < A[min])//这里是小于min
			{
				min = j;
			}
		}
		if (min != i)
			Swap(A[i], A[min]);
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
	SeletionSort(A, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", A[i]);
	}
	delete[] A;
	return 0;
}