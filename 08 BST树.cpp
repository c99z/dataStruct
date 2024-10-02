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
		if (root_==nullptr)//没有根节点，生成一个
		{
			Node* cur = new Node(val);
			//cur->data_ = val;
			root_= cur;
			delete cur;
		}
		/*有跟节点 生成新的节点然后 比较大小*/
		Node* cul = new Node(val);
		Node* p = root_;
		while (p != nullptr)//遍历到叶子节点为止
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
	Node* root_;//指向根节点的指针 初始化的时候指向空
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