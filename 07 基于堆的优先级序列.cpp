#include <iostream>
#include <stdlib.h>
#include <functional>
#include <time.h>
#include <algorithm>
using namespace std;

class PriorityQueue
{
public:
	using Comp = function<bool(int, int)>;//定义一个返回值类型bool，接受两个int型参数的函数对象
	PriorityQueue(int cap = 20, Comp comp = greater<int>())
		: cap_(cap)
		, size_(0)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}
	~PriorityQueue();
	void push(int val);//入堆
	void pop();//出堆
	void top();//查看堆顶元素并出堆
	bool empty();//判空
	void Show();
private:
	int* que_ ;//动态数组的指针
	int cap_;
	int size_;
	Comp comp_;//比较器对象
	void expand(int cap);//扩容
};


PriorityQueue::~PriorityQueue()
{
	delete[]que_;
	que_ = nullptr;
}
void PriorityQueue::push(int val)
{
	/*如果是空的直接插入到0号位置*/
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
	/*如果不是空就先放到末尾然后上浮操作*/
	int i = size_;//要插入的节点
	int f = (size_ - 1)/2;//末尾元素的父节点
	while (i != 0)//遍历到根节点为止
	{
		//if (que_[f] >= val)//这里应该用比较器
		if(comp_(val,que_[f]))//如果父节点的值比当前节点小
		{
			que_[i] = que_[f];
			i = f;
			f = (i - 1) / 2;

		}
		else//val不大于父节点 直接插入
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