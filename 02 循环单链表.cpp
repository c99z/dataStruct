#include <iostream>
using namespace std;
#include "CircleLink.h"
#include "CircleNode.h"
#include <cstdlib>
#include <ctime>
//头插
void test07()
{
	CircleLink<int> l1;
	l1.InsertHead(10);
	l1.InsertHead(19);
	l1.InsertHead(23);
	l1.InsertHead(30);
	l1.InsertHead(20);
	l1.Show();
	cout << l1.tail_->data_ << endl;//尾节点
	cout << l1.tail_->next_->next_->data_ << endl;//首个节点
}


void test08()
{
	CircleLink<int> l1;
	l1.InsertTail(10);
	l1.InsertTail(40);
	l1.InsertTail(20);
	l1.InsertTail(30);
	l1.Show();
	cout << l1.tail_->data_ << endl;//尾节点
	cout << l1.tail_->next_->next_->data_<< endl;//首个节点
}
//约瑟夫环问题，假设k=2，m=3
void test09()
{
	CircleLink<int> l1;
	for (int i = 0; i < 20; i++) 
	{
		
		l1.InsertTail(rand()%100 + 1);
	}
	l1.Show();
	CircleNode<int>* k = l1.head_->next_;
	l1.tail_->next_ = k;//删除头节点
	l1.head_ = k;
	l1.tail_->next_ = l1.head_;
	CircleNode<int>* q = l1.tail_;
	for (int i = 1; i < 2; i++)
	{
		k = k->next_;
		q = q->next_;
	}
	cout<< "第k个元素为："<<k->data_ << endl;//测试
	CircleNode<int>* p = k;//待删除节点
	while (p!=q)
	{
		for (int i = 1; i < 3; i++)//找到从k起第m个元素
		{
 			p = p->next_;//待删除节点
			q = q->next_;//待删除节点的前驱节点
		}
		cout<< p->data_ << " ";//输出
		q->next_ = p->next_;
		delete p;//delete就没问题了，不delete原来的没有删掉！
		p=q->next_;


	//头节点没有数据，得跳过头节点输出
	}
	cout << p->data_;
}
int main()
{
	//test07();
	//test08();
	test09();
	system("pause");
	return 0;
}