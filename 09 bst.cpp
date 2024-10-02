#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// BST树代码实现
template<typename T, typename Comp = less<T>>
class BSTree
{
public:
	// 初始化根节点和函数对象+lambda表达式
	BSTree(Comp comp = Comp())
		:root_(nullptr)
		, comp_(comp)
	{}
	void n_insert(const T& val)
	{
		// 树为空，生成根节点
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}

		// 搜索合适的插入位置，记录父节点的位置
		Node* parent = nullptr;//待插入节点的父节点
		Node* cur = root_;//待插入节点
		while (cur != nullptr)//直到待插入节点为空为止
		{
			if (cur->data_ == val)
			{
				// 不插入元素相同的值
				return;
			}
			else if (comp_(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;//往右边走
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
		}

		// 把新节点插入到parent节点的孩子上
		if (comp_(val, parent->data_))//其实是判断空位置在哪
		{
			parent->left_ = new Node(val);
		}
		else
		{
			parent->right_ = new Node(val);
		}
	}

	// 非递归删除操作
	void n_remove(const T& val)
	{
		// 树空直接返回
		if (root_ == nullptr)
		{
			return;
		}
		// 搜索待删除节点
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				break; // 找到待删除节点
			}
			else if (comp_(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
		}

		// 没找到待删除节点
		if (cur == nullptr)
		{
			return;
		}

		// 情况3 =》 删除前驱节点（归结成情况1、2）
		if (cur->left_ != nullptr && cur->right_ != nullptr)//左右都不为空
		{
			parent = cur;
			Node* pre = cur->left_;//一直往右走找最大值
			while (pre->right_ != nullptr)
			{
				parent = pre;
				pre = pre->right_;
			}
			cur->data_ = pre->data_;
			cur = pre; // 让cur指向前驱节点，转化成情况1，2
		}

		// cur指向删除节点，parent指向其父节点，同一处理情况1或者2
		Node* child = cur->left_;
		if (child == nullptr)
		{
			child = cur->right_;
		}

		if (parent == nullptr) // 特殊情况 表示删除的是根节点
		{
			root_ = child;
		}
		else
		{
			// 把待删除节点的孩子(nullptr或者不空)写入其父节点相应地址域中
			if (parent->left_ == cur)
			{
				parent->left_ = child;
			}
			else
			{
				parent->right_ = child;
			}
		}

		delete cur; // 删除当前节点
	}
	// 递归中序遍历操作
	void inOrder()
	{
		cout << "[递归]中序遍历:";
		inOrder(root_);
		cout << endl;
	}
	// 非递归中序遍历操作
	void n_inOrder()
	{
		cout << "[非递归]中序遍历:";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s;
		Node* cur = root_;

		while (!s.empty() || cur != nullptr)//栈不等于空或者当前节点不为空
		{
			if (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left_;
			}
			else//左孩子为空了，开始出栈
			{
				Node* top = s.top();//记录栈顶元素
				s.pop();//出栈
				cout << s.top().data_ << " ";//打印出栈前的栈顶元素
				cur = top->right_;//操作右孩子
			}
		}

		cout << endl;
	}
public:
	struct Node
	{
		Node(T data = T())//零构造
			:data_(data)
			, left_(nullptr)
			, right_(nullptr)
		{}
		T data_; // 数据域
		Node* left_; // 左孩子域
		Node* right_; // 右孩子域
	};
	Node* root_; // 指向BST树的根节点
	Comp comp_; // 定义一个函数对象

};
void test01()
{
	int ar[] = {58,24,67,0,34,62,69,5,41,64,78};
	BSTree<int> bst;
	for (int v : ar)
	{
		//bst.n_insert(v);
		bst.n_insert(v);
	}
	bst.n_inOrder();
}

int main()
{
	test01();
	system("pause");
	return 0;
}