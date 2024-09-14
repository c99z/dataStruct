#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*合并*/
void Merge(int arr[], int l, int m, int r,int *p)
{
	int idx = 0;
	int i = l;
	int j = m + 1;
	while (i <= m && j <= r)//注意条件
	{
		//判断，哪个小把那个放进新数组里
		if (arr[i] <= arr[j])//为了稳定性，这里用等号
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}
		//循环结束代表有一边空了（下列循环要放在外面）
		//左边还有，右边空了
	while (i <= m)
	{
		p[idx++] = arr[i++];
	}
	while (j <= r)
	{
		p[idx++] = arr[j++];
	}
	//把新数组拷贝到原来的数组里
	for (int i = l,j=0; i <= r; i++,j++)
	{
		arr[i] = p[j];
	}
	
}
//归并接口
void MergeSort(int arr[], int begin, int end, int* p)
{
	int mid = (begin + end) / 2;
	if (begin >=end)//“递”结束标志
	{
		return;
	}
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	//递归完了合并
	Merge(arr, begin, mid, end,p);

}

void MergeSort(int arr[], int size)
{
	int* p = new int[size];
	MergeSort(arr, 0, size - 1, p);
	delete[]p;
}
//测试代码
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
	MergeSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}