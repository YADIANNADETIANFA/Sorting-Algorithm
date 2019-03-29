#include<cstdio>
#include<iostream>
//#include<limits>

using namespace std;

void Merge(int A[], int left, int mid, int right)//�ϲ��������ź��������A[left...mid]��A[mid+1...right]
{
	int len = right - left + 1;
	int* temp = new int[len];//�����ռ�
	int index = 0;
	int i = left;//ǰһ���������ʼԭʼ
	int j = mid+1;//��һ���������ʼԪ��
	
	while (i <= mid && j <= right)// ���Ⱥű�֤�鲢������ȶ���
	{
		temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
	}

	while (i <= mid)
		temp[index++] = A[i++];
	while (j <= right)
		temp[index++] = A[j++];
	for (int i = left; i <= right; ++i)//�鲢��Żص�A��
		A[i] = temp[i - left];
}

void MergeSortRecursion(int A[], int left,int right) // �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	MergeSortRecursion(A, left, mid);
	MergeSortRecursion(A, mid + 1, right);
	Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)// �ǵݹ�(����)ʵ�ֵĹ鲢����(�Ե�����)
{
	int left;
	int mid;
	int right;
	for (int i = 1; i < len; i *= 2)// (ǰһ��)������Ĵ�Сi��ʼΪ1��ÿ�ַ���
	{
		left = 0;
		while (left + i <= len - 1)//��һ��������ڣ���Ҫ�鲢��    left+i�Ǻ�һ���������ʼ�±�ֵ
		{
			mid = left + i - 1;
			right = (mid + i) < (len - 1) ? (mid + i) : (len - 1);//��һ�������С���ܲ���
			Merge(A, left, mid, right);
			left = right + 1;//�鲢ÿһ�ֺ��������
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