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
		return mq[(rear - 1+msize)&msize];//rear在0号位置时会引发bug 不能直接减1
	}
	//出队 要判空
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
	/*麻烦*/
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
	//判满
	bool empty() const
	{
		return first == rear;
	}
	//判满
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

	//析构
	~queue()
	{
		delete[]mq;
		mq = nullptr;
	}

private:
	/*这里的初始化可以放在构造函数里*/
	int first = 0;//队头
	int rear = 0;//队尾
	int msize = 10;//默认数组大小10
	int* mq = new int[msize];//数组
	int size_ = 0;

	//扩容 要写成私有的，不能给用户调用
	void expand()
	{
		int Newmsize = 2 * msize;
		int* newArr = new int[Newmsize];
		//for (int i = 0; i < msize; i++)//这种扩容方法有问题，会导致内存浪费
		//{
		//	newArr[i] = mq[i];
		//}
		int n = 0;
		for (int i =first; i != rear; i=(i+1)%msize)
		{
			newArr[n] = mq[i];
			n++;
		}
		delete[]mq;//释放原来的内存,要全部释放，而不只是指向数组的指针
		mq = nullptr;
		mq = newArr;
		msize = Newmsize;
		first = 0;
		rear = n + 1;
	}
};

void test01()
{
	queue q1;
	q1.push(10);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.pop();
	q1.pop();
	q1.pop();
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);

	q1.push(20);
	q1.pop();
	q1.pop();
	q1.pop();

	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
	q1.push(20);
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