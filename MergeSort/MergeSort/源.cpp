#include<cstdio>
#include<iostream>
//#include<limits>

using namespace std;

void Merge(int A[], int left, int mid, int right)//合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
	int len = right - left + 1;
	int* temp = new int[len];//辅助空间
	int index = 0;
	int i = left;//前一子数组的起始原始
	int j = mid+1;//后一子数组的起始元素
	
	while (i <= mid && j <= right)// 带等号保证归并排序的稳定性
	{
		temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];//前面没有++，后面才有++
	}

	while (i <= mid)
		temp[index++] = A[i++];
	while (j <= right)
		temp[index++] = A[j++];
	for (int i = left; i <= right; ++i)//归并后放回到A中
		A[i] = temp[i - left];
}

void MergeSortRecursion(int A[], int left,int right) // 递归实现的归并排序(自顶向下)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	MergeSortRecursion(A, left, mid);
	MergeSortRecursion(A, mid + 1, right);
	Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)// 非递归(迭代)实现的归并排序(自底向上)
{
	int left;
	int mid;
	int right;
	for (int i = 1; i < len; i *= 2)// (前一个)子数组的大小i初始为1，每轮翻倍
	{
		left = 0;
		while (left + i <= len - 1)//后一子数组存在，需要归并；    left+i是后一子数组的起始下标值
		{
			mid = left + i - 1;
			right = (mid + i) < (len - 1) ? (mid + i) : (len - 1);//后一子数组大小可能不够
			Merge(A, left, mid, right);
			left = right + 1;//归并每一轮后面的内容
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* A1 = new int[n];
	int* A2 = new int[n];
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		A1[i] = temp;
		A2[i] = temp;
	}
	printf("For Recursion:\n");
	MergeSortRecursion(A1, 0, n - 1);
	for (int i = 0; i < n; ++i)
		printf("%d\n", A1[i]);
	printf("\n");

	printf("For Iteration:\n");
	MergeSortIteration(A2, n);
	for (int i = 0; i < n; ++i)
		printf("%d\n", A2[i]);

	return 0;
}
