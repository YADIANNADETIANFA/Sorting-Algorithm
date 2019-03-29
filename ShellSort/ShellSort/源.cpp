#include<cstdio>
#include<iostream>

using namespace std;

void ShellSort(int A[], int n)
{
	int h = 0;
	while (h <= n)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (int i = h; i < n; ++i)//插入排序的首要原则是保证该元素的前面已经是排好序的了
		{                          //不同分组同时处理，即好几个间隔都是h的分组，同时进行着插入排序
			int get = A[i];
			int j = i - h;
			while (j >= 0 && A[j] > get)
			{
				A[j + h] = A[j];
				j -= h;
			}
			A[j + h] = get;
		}
		h = (h - 1) / 3;
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
	ShellSort(A, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", A[i]);
	}
	delete[] A;
	return 0;
}