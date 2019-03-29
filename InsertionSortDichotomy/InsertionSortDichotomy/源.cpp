#include<cstdio>
#include<iostream>
using namespace std;

void InsertionSortDichotomy(int A[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		int get = A[i];
		int left = 0;
		int right = i - 1;

		while (left <= right)//这个循环还是需要推的，背下来再说
		{
			int mid = (left + right) / 2;
			if (A[mid] > get)
				right = mid - 1;
			else
				left = mid + 1;
		}

		for (int j = i-1; j >= left; --j)
			A[j + 1] = A[j];

		A[left] = get;
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
	InsertionSortDichotomy(A, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", A[i]);
	}
	delete[] A;
	return 0;
}