#include<cstdio>
#include<iostream>

using namespace std;

void InsertionSort(int A[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		int get = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > get)
		{
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = get;
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
	InsertionSort(A, n);
	for (int i = 0; i < n; ++i)
		printf("%d", A[i]);
	delete[] A;
	return 0;
}