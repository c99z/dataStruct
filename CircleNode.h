#pragma once
template <class T>
class CircleNode
{
public://���д��˽�У����Ǳ߾ͷ��ʲ�����
	T data_;
	CircleNode<T>* next_;//yһ��ָ��ڵ��ָ��
public:
	CircleNode<T>()//Ĭ�Ϲ���
	{
		this->data_ = 0;
		this->next_ = nullptr;
	}
	CircleNode<T>(T data)
	{
		this->data_ = data;
		this->next_ = nullptr;
	}
	CircleNode<T>( T data, CircleNode<T> *next )
	{
		this->data_ = data;
		this->next_ = next;
	}

};