#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*ѡ������*/
//ÿ��ѡ����С�� ֻ����һ�� 
void ChioceSort(int arr[], int size)
{
	for (int n = 0;n < size-1;n++)//���һ��������
	{
		int min = arr[n];
		int j = n;
		for (int i = n+1; i < size; i++)
		{
			//����ȳ�ʼֵС �ͼ�¼���ֵ���±� �������ֵ��Ϊ��Сֵ
			if (min > arr[i])
			{
				min = arr[i];//���¼�¼��Сֵ
				j = i;//��¼�±�
			}
		}
		//����λ��
		arr[j] = arr[n];
		arr[n] = min;
	}
}
//��������
//��ǰ��ĵ�������ģ�Ȼ��ӵڶ���Ԫ�ؿ�ʼ�����ȥ
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)//�ӵڶ���Ԫ�ؿ�ʼ
	{
		int j = i - 1;
		int val = arr[i];
		for (; j >=0; j--)//�Ӻ���ǰ����
		{
			if (arr[j] <=val)//�����������뵽arr[j]֮ǰ����j��ʼ��i-1�±��1
			{
				break;
			}
			arr[j + 1] = arr[j];//��Ϊ�ǴӺ���ǰ���������԰�ǰ���ֵ��������Ϳ�������±�+1
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