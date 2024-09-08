#pragma once 
#include <iostream>
using namespace std;

class queue
{
public:
	queue()
	{
		int* mq = new int[10];
	}//Ĭ�Ϲ���
	queue(int size)
	{
		this->msize = size;
	}
	void push(int val)
	{
		if (full())//������˾�����
		{
			expand();
		}
		else
		{
			mq[rear] = val;
			rear = (rear + 1) % msize;
			size_++;
		}

	}
	//��ͷ
	int front()
	{
		return mq[first];
	}
	//��β
	int back()
	{
		return mq[rear - 1];
	}
	//ɾ����ͷԪ��
	void pop()
	{
		first = (first + 1) % msize;
		size_--;
	}
	//��ӡ���
	void Show()
	{
		int i = first;
		while (i != rear)
		{
			cout << mq[i] << " ";//ֱ����first�����͸ı���first
			i = (i + 1) % msize;

		}
		cout << endl;
	}
	//�п�
	bool empty()
	{
		if (first == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//����
	bool full()
	{
		if (first==(rear+1)%msize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int size()
	{
		return size_;
	}
	//����
	void expand()
	{
		int Newmsize = 2 * msize;
		int* newArr = new int[Newmsize];
		for (int i = 0; i < msize; i++)
		{
			newArr[i] = mq[i];
		}
		mq = newArr;
		msize = Newmsize;
	}
	//����
	~queue()
	{
		delete mq;
	}

private:
	int first = 0;//��ͷ
	int rear = 0;//��β
	int msize = 10;//Ĭ�������С10
	int* mq = new int[msize];//����
	int size_ = 0;
};

void test01()
{
	queue q1;
	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.push(50);
	q1.Show();
	cout << "size:" << q1.size() << endl;//
	cout << "front:" << q1.front() << endl;
	q1.pop();
	cout << "front:" << q1.front() << endl;
	cout << "size:" << q1.size() << endl;//

}
int main()
{
	test01();
	system("pause");
	return 0;
}