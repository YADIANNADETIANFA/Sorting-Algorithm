#include<iostream>
#include<cstdio>
using namespace std;

int maxbit(int data[], int n)
{
	int d = 1;
	int max = data[0];
	for (int i = 1; i < n; ++i)// 找出最大值
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
	int d = maxbit(data, n);// 求data中最大数具有的位数，决定循环几次
	int* tmp = new int[n];//辅助空间，排完的数组总要有个地方存着
	int* count = new int[10];// 10 个桶
	int radix = 1;
	for (int i = 1; i <= d; ++i)
	{
		for (int j = 0; j < 10; ++j)// 每次清零桶计数器
		{
			count[j] = 0;
		}
		for (int j = 0; j < n; ++j)// 统计每个桶中的记录数
		{
			int k = (data[j] / radix) % 10;
			count[k]++;
		}
		for (int j = 1; j < 10; ++j)// 分配tmp的位置
			count[j] = count[j - 1] + count[j];// count[j] 中 是 j 桶 和比 j 小的桶中的记录数的和
		for (int j = n - 1; j >= 0; --j)// 倒着来，将所有桶中记录依次收集到tmp中
		{
			int k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (int j = 0; j < n; ++j) // 将临时数组复制回data
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