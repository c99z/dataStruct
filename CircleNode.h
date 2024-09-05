#pragma once
template <class T>
class CircleNode
{
public://这个写成私有，链那边就访问不到了
	T data_;
	CircleNode<T>* next_;//y一个指向节点的指针
public:
	CircleNode<T>()//默认构造
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