#include <iostream>
using namespace std;
#include "CircleLink.h"
#include "CircleNode.h"
#include <cstdlib>
#include <ctime>
//ͷ��
void test07()
{
	CircleLink<int> l1;
	l1.InsertHead(10);
	l1.InsertHead(19);
	l1.InsertHead(23);
	l1.InsertHead(30);
	l1.InsertHead(20);
	l1.Show();
	cout << l1.tail_->data_ << endl;//β�ڵ�
	cout << l1.tail_->next_->next_->data_ << endl;//�׸��ڵ�
}


void test08()
{
	CircleLink<int> l1;
	l1.InsertTail(10);
	l1.InsertTail(40);
	l1.InsertTail(20);
	l1.InsertTail(30);
	l1.Show();
	cout << l1.tail_->data_ << endl;//β�ڵ�
	cout << l1.tail_->next_->next_->data_<< endl;//�׸��ڵ�
}
//Լɪ�����⣬����k=2��m=3
void test09()
{
	CircleLink<int> l1;
	for (int i = 0; i < 20; i++) 
	{
		
		l1.InsertTail(rand()%100 + 1);
	}
	l1.Show();
	CircleNode<int>* k = l1.head_->next_;
	l1.tail_->next_ = k;//ɾ��ͷ�ڵ�
	l1.head_ = k;
	l1.tail_->next_ = l1.head_;
	CircleNode<int>* q = l1.tail_;
	for (int i = 1; i < 2; i++)
	{
		k = k->next_;
		q = q->next_;
	}
	cout<< "��k��Ԫ��Ϊ��"<<k->data_ << endl;//����
	CircleNode<int>* p = k;//��ɾ���ڵ�
	while (p!=q)
	{
		for (int i = 1; i < 3; i++)//�ҵ���k���m��Ԫ��
		{
 			p = p->next_;//��ɾ���ڵ�
			q = q->next_;//��ɾ���ڵ��ǰ���ڵ�
		}
		cout<< p->data_ << " ";//���
		q->next_ = p->next_;
		delete p;//delete��û�����ˣ���deleteԭ����û��ɾ����
		p=q->next_;


	//ͷ�ڵ�û�����ݣ�������ͷ�ڵ����
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