#include<cstdio>
#include<iostream>

using namespace std;

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void CockTailSort(int A[], int n)
{
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		for (int i = left; i < right; ++i)
		{
			if (A[i] > A[i + 1])
				Swap(A[i], A[i + 1]);
		}
		--right;

		for (int j = right; j > left; --j)
		{
			if (A[j] < A[j - 1])
				Swap(A[j], A[j - 1]);
		}
		++left;
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

	CockTailSort(A, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", A[i]);
	}
	delete[] A;
	return 0;
}