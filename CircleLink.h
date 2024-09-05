#pragma once
#include <iostream>
using namespace std;
#include "CircleNode.h"
template <class T>
class CircleLink
{
public:
	CircleLink()
	{
		head_ = new CircleNode<T>();//创建头节点，用一个指针接收
		tail_ = head_;//尾节点指向头，因为现在是空链表
		head_->next_ = tail_;
	}
	void InsertHead(T val)
	{
		//node = CircleNode<T>(val);//不行，得用new
		CircleNode<T>* node = new CircleNode<T>(val);//新建待插入节点
		//CircleNode<T>* p =head_next//保存头节点信息
		node->next_ = head_->next_;//链接
		head_->next_ = node;
		//tail_->next_ = head_;//重置尾节点指针
		/*s实际上尾节点指针在头插法中只移动一次就是第一次插入的时候*/
		if (node->next_ == head_)//第一次插入的时候，head->next是head本身，故node->next是head
		{
			tail_ = node;
		}
	}
	void InsertTail(T val)
	{
		CircleNode<T>* node = new CircleNode<T>(val);//新建待插入节点
		tail_->next_ = node;
		tail_ = tail_->next_;
		node->next_ = head_;
	}

	void Show() const//只读不写，可以写成const方法
	{
		CircleNode<T>* p = head_->next_;
		while (p!=head_)//单向循环链表的遍历操作
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}
public:
	CircleNode<T>* head_ = nullptr;//头节点指针
	CircleNode<T>* tail_ = nullptr;//尾节点指针
};

