#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*选择排序*/
//每趟选出最小的 只交换一次 
void ChioceSort(int arr[], int size)
{
	for (int n = 0;n < size-1;n++)//最后一个不用排
	{
		int min = arr[n];
		int j = n;
		for (int i = n+1; i < size; i++)
		{
			//如果比初始值小 就记录这个值的下标 并将这个值设为最小值
			if (min > arr[i])
			{
				min = arr[i];//重新记录最小值
				j = i;//记录下标
			}
		}
		//交换位置
		arr[j] = arr[n];
		arr[n] = min;
	}
}
//插入排序
//把前面的当做有序的，然后从第二个元素开始插入进去
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)//从第二个元素开始
	{
		int j = i - 1;
		int val = arr[i];
		for (; j >=0; j--)//从后往前遍历
		{
			if (arr[j] <=val)//满足条件插入到arr[j]之前（从j开始到i-1下标加1
			{
				break;
			}
			arr[j + 1] = arr[j];//因为是从后往前遍历，所以把前面的值赋给后面就可以完成下标+1
		}
		arr[j + 1] = val;
	}
}

void test01()
{
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		arr[i] = val;
	}
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	InsertSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}
int main()
{
	//test07();
	//test08();
	test01();
	system("pause");
	return 0;
}