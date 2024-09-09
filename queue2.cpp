#pragma once 
#include <iostream>
using namespace std;

class queue
{
public:
	queue()
		:msize(10)
		,size_(0)
		,first(0)
		,rear(0)
	{
		mq = new int[msize];
	}//Ĭ�Ϲ���
	queue(int num)
		:msize(num)
		, size_(0)
		, first(0)
		, rear(0)
	{
		mq = new int[msize];

	}
	void push(int val)
	{
		if (full())//������˾�����
		{
			expand();
		}
		/*���ﲻҪelse,����֮����Ҫ����*/
			mq[rear] = val;
			rear = (rear + 1) % msize;
			size_++;
	

	}
	//��ͷ
	int front()
	{
		return mq[first];
	}
	//��β
	int back()
	{
		return mq[(rear - 1+msize)&msize];//rear��0��λ��ʱ������bug ����ֱ�Ӽ�1
	}
	//���� Ҫ�п�
	void pop()
	{
		if (empty())
		{
			throw"queue is empty";
		}
		else
		{
			first = (first + 1) % msize;
			size_--;
		}

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
	/*�鷳*/
	//bool empty() 
	//{
	//	if (first == rear)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	//����
	bool empty() const
	{
		return first == rear;
	}
	//����
	bool full() const
	{
		return first == (rear + 1) % msize;
	}
	/*bool full()
	{
		if (first==(rear+1)%msize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/
	int size()
	{
		return size_;
	}

	//����
	~queue()
	{
		delete[]mq;
		mq = nullptr;
	}

private:
	/*����ĳ�ʼ�����Է��ڹ��캯����,���ﲻҪд*/
	int first ;//��ͷ
	int rear ;//��β
	int msize ;//Ĭ�������С10
	int* mq ;//����
	int size_;

	//���� Ҫд��˽�еģ����ܸ��û�����
	void expand()
	{
		int Newmsize = 2 * msize;
		int* newArr = new int[Newmsize];
		//for (int i = 0; i < msize; i++)//�������ݷ��������⣬�ᵼ���ڴ��˷�
		//{
		//	newArr[i] = mq[i];
		//}
		int i = 0;
		int j = first;
		for (; j != rear;i++, j=(j+1)%msize)
		{
			newArr[i] = mq[j];
			
		}
		delete[]mq;//�ͷ�ԭ�����ڴ�,Ҫȫ���ͷţ�����ֻ��ָ�������ָ��
		//mq = nullptr;
		mq = newArr;
		msize = Newmsize;
		first = 0;
		rear = i;
	}
};

void test01()
{
	queue q1; 
	q1.push(10);
	q1.push(30);
	q1.push(40);
	q1.push(20);
	q1.push(50);
	q1.push(60);
	q1.push(40);
	q1.push(30);
	q1.push(10);
	q1.push(30);
	q1.push(20);
	q1.push(40);
	q1.Show();

	//cout << "size:" << q1.size() << endl;//
	//cout << "front:" << q1.front() << endl;
	//q1.pop();
	//cout << "front:" << q1.front() << endl;
	//cout << "size:" << q1.size() << endl;//

}
int main()
{
	test01();
	system("pause");
	return 0;
}