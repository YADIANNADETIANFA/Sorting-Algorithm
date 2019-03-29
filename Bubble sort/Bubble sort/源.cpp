#include<cstdio>
#include<iostream>

using namespace std;

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void BubbleSort(int A[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (A[j] > A[j + 1])//������j����д��i��������
				Swap(A[j], A[j + 1]);//������j
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* A = new int[n];//����û�а취���ܱ���n
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		A[i] = temp;
	}
	BubbleSort(A, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", A[i]);
	}

	delete[] A;

	return 0;
}