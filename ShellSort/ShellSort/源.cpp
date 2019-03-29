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
		for (int i = h; i < n; ++i)//�����������Ҫԭ���Ǳ�֤��Ԫ�ص�ǰ���Ѿ����ź������
		{                          //��ͬ����ͬʱ�������ü����������h�ķ��飬ͬʱ�����Ų�������
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