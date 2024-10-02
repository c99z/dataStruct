#include <iostream>
using namespace std;
#include <algorithm>

template <typename T,typename Compare=less<T>>
class BSTree
{
public:
	BSTree()
	{
		Node* root_ = nullptr;
	}
	~BSTree()
	{
		delete* root;
	}

	void Insert(const T &val)
	{
		if (root_==nullptr)//û�и��ڵ㣬����һ��
		{
			Node* cur = new Node(val);
			//cur->data_ = val;
			root_= cur;
			delete cur;
		}
		/*�и��ڵ� �����µĽڵ�Ȼ�� �Ƚϴ�С*/
		Node* cul = new Node(val);
		Node* p = root_;
		while (p != nullptr)//������Ҷ�ӽڵ�Ϊֹ
		{
			if (val >= p->data_)
			{
				p = p->right_;
			}
			else
			{
				p = p->left_;  
				if (val >= p->right_)
				{
					break;
				}
			}
		}
	}
	bool empty()
	{
		return root_;
	}
	struct Node
	{
		Node(T data = T())
		:left_(nullptr)
		,right_(nullptr)
		,data_=data
	{}
		T data_;
		Node* left_;
		Node* right_;
	};
private:
	Node* root_;//ָ����ڵ��ָ�� ��ʼ����ʱ��ָ���
};

void test01()
{
	BSTree<int> s1;


}

int main()
{
	test01();
	system("pause");
	return 0;
}