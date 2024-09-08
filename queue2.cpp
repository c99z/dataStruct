#pragma once 
#include <iostream>
using namespace std;

class queue
{
public:
	queue()
	{
		int* mq = new int[10];
	}//默认构造
	queue(int size)
	{
		this->msize = size;
	}
	void push(int val)
	{
		if (full())//如果满了就扩容
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
	//队头
	int front()
	{
		return mq[first];
	}
	//队尾
	int back()
	{
		return mq[rear - 1];
	}
	//删除队头元素
	void pop()
	{
		first = (first + 1) % msize;
		size_--;
	}
	//打印输出
	void Show()
	{
		int i = first;
		while (i != rear)
		{
			cout << mq[i] << " ";//直接用first遍历就改变了first
			i = (i + 1) % msize;

		}
		cout << endl;
	}
	//判空
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
	//判满
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
	//扩容
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
	//析构
	~queue()
	{
		delete mq;
	}

private:
	int first = 0;//队头
	int rear = 0;//队尾
	int msize = 10;//默认数组大小10
	int* mq = new int[msize];//数组
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