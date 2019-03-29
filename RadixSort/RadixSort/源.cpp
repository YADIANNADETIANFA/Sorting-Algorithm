#include<iostream>
#include<cstdio>
using namespace std;

int maxbit(int data[], int n)
{
	int d = 1;
	int max = data[0];
	for (int i = 1; i < n; ++i)// �ҳ����ֵ
	{
		if (data[i] > max)
			max = data[i];
	}
	int radix = 10;
	while (max > radix)
	{
		++d;
		radix *= 10;
	}
	return d;
}

void radixSort(int data[], int n)
{
	int d = maxbit(data, n);// ��data����������е�λ��������ѭ������
	int* tmp = new int[n];//�����ռ䣬�����������Ҫ�и��ط�����
	int* count = new int[10];// 10 ��Ͱ
	int radix = 1;
	for (int i = 1; i <= d; ++i)
	{
		for (int j = 0; j < 10; ++j)// ÿ������Ͱ������
		{
			count[j] = 0;
		}
		for (int j = 0; j < n; ++j)// ͳ��ÿ��Ͱ�еļ�¼��
		{
			int k = (data[j] / radix) % 10;
			count[k]++;
		}
		for (int j = 1; j < 10; ++j)// ����tmp��λ��
			count[j] = count[j - 1] + count[j];// count[j] �� �� j Ͱ �ͱ� j С��Ͱ�еļ�¼���ĺ�
		for (int j = n - 1; j >= 0; --j)// ��������������Ͱ�м�¼�����ռ���tmp��
		{
			int k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (int j = 0; j < n; ++j) // ����ʱ���鸴�ƻ�data
			data[j] = tmp[j];
		radix *= 10;
	}
	delete[] count;
	delete[] tmp;
	count = nullptr;
	tmp = nullptr;
}

int main()
{
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		data[i] = temp;
	}
	radixSort(data, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t", data[i]);
	}
	delete[] data;
	return 0;
}