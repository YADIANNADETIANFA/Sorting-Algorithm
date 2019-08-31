#include<cstdio>
#include<exception>
#include<cstdlib>//rand(),srand()头文件
#include<ctime>
using namespace std;
//为什么说快排是不稳定的？ https://blog.csdn.net/wusuopuBUPT/article/details/22743315
int RandomInRange(int, int);//声明
void Swap(int*, int*);
int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw exception("Invalid Parameters");
	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (index != small)
			{
				Swap(&data[index], &data[small]);
			}
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
	{
		try
		{
			QuickSort(data, length, start, index - 1);
		}
		catch (exception& e)
		{
			printf("Invalid Parameters.");
		}
	}

	if (index < end)
	{
		try
		{
			QuickSort(data, length, index + 1, end);
		}
		catch (exception& e)
		{
			printf("Invalid Parameters.");
		}
	}
}

int RandomInRange(int start, int end)
{
	if (start < end)
	{
		srand(time(NULL));//rand()产生的随机数在每次运行的时候都是与上一次相同的。若要不同,用函数srand()初始化它。
		return start + rand() % (end - start);//可以利用srand((unsigned int)(time(NULL))的方法，产生不同的随机数种子，因为每一次运行程序的时间是不同的。
	}
	return start;
}

void Swap(int* elem1, int* elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void Print(int data[],int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%u\n", data[i]);
	}
}
int main()
{
	int num[9] = { 1,2,3,2,2,2,5,4,2 };
	int length = sizeof(num) / sizeof(num[0]);
	QuickSort(num, 9, 0, length-1);
	Print(num,length);//数组作函数参数的时候退化为普通指针，不再是数组首地址，所以在别的函数中无法计算数组长度，要先计算好了再传过去
	return 0;
}

/*void Print(int data[])
{
	for (int i = 0; i < sizeof(num)/sizeof(num[0]); ++i)
	{
		printf("%u\n", data[i]);
	}
}
int main()
{
	int num[9] = { 1,2,3,2,2,2,5,4,2 };
	QuickSort(num, 9, 0, sizeof(num)/sizeof(num[0]) - 1);
	Print(num);//如果这么做的话，只会打出num的首个元素，而不是打印出num全部。
	return 0;
}*/
