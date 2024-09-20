#include <iostream>
#include <stdlib.h>
#include <functional>
#include <time.h>
#include <algorithm>
using namespace std;

class PriorityQueue
{
public:
	using Comp = function<bool(int, int)>;//����һ������ֵ����bool����������int�Ͳ����ĺ�������
	PriorityQueue(int cap = 20, Comp comp = greater<int>())
		: cap_(cap)
		, size_(0)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}
	~PriorityQueue();
	void push(int val);//���
	void pop();//����
	void top();//�鿴�Ѷ�Ԫ�ز�����
	bool empty();//�п�
	void Show();
private:
	int* que_ ;//��̬�����ָ��
	int cap_;
	int size_;
	Comp comp_;//�Ƚ�������
	void expand(int cap);//����
};


PriorityQueue::~PriorityQueue()
{
	delete[]que_;
	que_ = nullptr;
}
void PriorityQueue::push(int val)
{
	/*����ǿյ�ֱ�Ӳ��뵽0��λ��*/
	if (size_==0)
	{
		que_[0] = val;
		size_++;
		return;
	}
	if (size_ == cap_)
	{
		expand(2*cap_);
	}
	/*������ǿվ��ȷŵ�ĩβȻ���ϸ�����*/
	int i = size_;//Ҫ����Ľڵ�
	int f = (size_ - 1)/2;//ĩβԪ�صĸ��ڵ�
	while (i != 0)//���������ڵ�Ϊֹ
	{
		//if (que_[f] >= val)//����Ӧ���ñȽ���
		if(comp_(val,que_[f]))//������ڵ��ֵ�ȵ�ǰ�ڵ�С
		{
			que_[i] = que_[f];
			i = f;
			f = (i - 1) / 2;

		}
		else//val�����ڸ��ڵ� ֱ�Ӳ���
		{
			break;
		}
		
	}
	que_[i] = val;
	size_++;
}
void PriorityQueue::Show()
{
	for (int  i = 0; i < size_; i++)
	{
		cout << que_[i] << " ";
	}
	cout << endl;
}

void PriorityQueue::pop()
{

}
void PriorityQueue::top()
{

}
void PriorityQueue::expand(int cap)
{
	int* newque = new int[cap];
	for (int i = 0; i < size_; i++)
	{
		newque[i] = que_[i];
	}
	
	delete[]que_;
	que_ = newque;
	cap_ = cap;
	//delete[]newque;
	//newque = nullptr;
}
bool PriorityQueue::empty()
{
	return(size_ == 0);
}

void test01()
{
	PriorityQueue q1;
	cout << q1.empty() << endl;
	srand(time(NULL));
	for (int i = 0; i < 105;i++)
	{
		int val= rand() % 100;
		q1.push(val);
	}
	q1.Show();
}
int main()
{
	test01();
	system("pause");
	return 0;
	
}