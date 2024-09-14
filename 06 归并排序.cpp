#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*�ϲ�*/
void Merge(int arr[], int l, int m, int r,int *p)
{
	int idx = 0;
	int i = l;
	int j = m + 1;
	while (i <= m && j <= r)//ע������
	{
		//�жϣ��ĸ�С���Ǹ��Ž���������
		if (arr[i] <= arr[j])//Ϊ���ȶ��ԣ������õȺ�
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}
		//ѭ������������һ�߿��ˣ�����ѭ��Ҫ�������棩
		//��߻��У��ұ߿���
	while (i <= m)
	{
		p[idx++] = arr[i++];
	}
	while (j <= r)
	{
		p[idx++] = arr[j++];
	}
	//�������鿽����ԭ����������
	for (int i = l,j=0; i <= r; i++,j++)
	{
		arr[i] = p[j];
	}
	
}
//�鲢�ӿ�
void MergeSort(int arr[], int begin, int end, int* p)
{
	int mid = (begin + end) / 2;
	if (begin >=end)//���ݡ�������־
	{
		return;
	}
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	//�ݹ����˺ϲ�
	Merge(arr, begin, mid, end,p);

}

void MergeSort(int arr[], int size)
{
	int* p = new int[size];
	MergeSort(arr, 0, size - 1, p);
	delete[]p;
}
//���Դ���
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