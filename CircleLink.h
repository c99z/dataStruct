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
		head_ = new CircleNode<T>();//����ͷ�ڵ㣬��һ��ָ�����
		tail_ = head_;//β�ڵ�ָ��ͷ����Ϊ�����ǿ�����
		head_->next_ = tail_;
	}
	void InsertHead(T val)
	{
		//node = CircleNode<T>(val);//���У�����new
		CircleNode<T>* node = new CircleNode<T>(val);//�½�������ڵ�
		//CircleNode<T>* p =head_next//����ͷ�ڵ���Ϣ
		node->next_ = head_->next_;//����
		head_->next_ = node;
		//tail_->next_ = head_;//����β�ڵ�ָ��
		/*sʵ����β�ڵ�ָ����ͷ�巨��ֻ�ƶ�һ�ξ��ǵ�һ�β����ʱ��*/
		if (node->next_ == head_)//��һ�β����ʱ��head->next��head������node->next��head
		{
			tail_ = node;
		}
	}
	void InsertTail(T val)
	{
		CircleNode<T>* node = new CircleNode<T>(val);//�½�������ڵ�
		tail_->next_ = node;
		tail_ = tail_->next_;
		node->next_ = head_;
	}

	void Show() const//ֻ����д������д��const����
	{
		CircleNode<T>* p = head_->next_;
		while (p!=head_)//����ѭ������ı�������
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}
public:
	CircleNode<T>* head_ = nullptr;//ͷ�ڵ�ָ��
	CircleNode<T>* tail_ = nullptr;//β�ڵ�ָ��
};

