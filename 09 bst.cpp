#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// BST������ʵ��
template<typename T, typename Comp = less<T>>
class BSTree
{
public:
	// ��ʼ�����ڵ�ͺ�������+lambda���ʽ
	BSTree(Comp comp = Comp())
		:root_(nullptr)
		, comp_(comp)
	{}
	void n_insert(const T& val)
	{
		// ��Ϊ�գ����ɸ��ڵ�
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}

		// �������ʵĲ���λ�ã���¼���ڵ��λ��
		Node* parent = nullptr;//������ڵ�ĸ��ڵ�
		Node* cur = root_;//������ڵ�
		while (cur != nullptr)//ֱ��������ڵ�Ϊ��Ϊֹ
		{
			if (cur->data_ == val)
			{
				// ������Ԫ����ͬ��ֵ
				return;
			}
			else if (comp_(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;//���ұ���
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
		}

		// ���½ڵ���뵽parent�ڵ�ĺ�����
		if (comp_(val, parent->data_))//��ʵ���жϿ�λ������
		{
			parent->left_ = new Node(val);
		}
		else
		{
			parent->right_ = new Node(val);
		}
	}

	// �ǵݹ�ɾ������
	void n_remove(const T& val)
	{
		// ����ֱ�ӷ���
		if (root_ == nullptr)
		{
			return;
		}
		// ������ɾ���ڵ�
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				break; // �ҵ���ɾ���ڵ�
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

		// û�ҵ���ɾ���ڵ�
		if (cur == nullptr)
		{
			return;
		}

		// ���3 =�� ɾ��ǰ���ڵ㣨�������1��2��
		if (cur->left_ != nullptr && cur->right_ != nullptr)//���Ҷ���Ϊ��
		{
			parent = cur;
			Node* pre = cur->left_;//һֱ�����������ֵ
			while (pre->right_ != nullptr)
			{
				parent = pre;
				pre = pre->right_;
			}
			cur->data_ = pre->data_;
			cur = pre; // ��curָ��ǰ���ڵ㣬ת�������1��2
		}

		// curָ��ɾ���ڵ㣬parentָ���丸�ڵ㣬ͬһ�������1����2
		Node* child = cur->left_;
		if (child == nullptr)
		{
			child = cur->right_;
		}

		if (parent == nullptr) // ������� ��ʾɾ�����Ǹ��ڵ�
		{
			root_ = child;
		}
		else
		{
			// �Ѵ�ɾ���ڵ�ĺ���(nullptr���߲���)д���丸�ڵ���Ӧ��ַ����
			if (parent->left_ == cur)
			{
				parent->left_ = child;
			}
			else
			{
				parent->right_ = child;
			}
		}

		delete cur; // ɾ����ǰ�ڵ�
	}
	// �ݹ������������
	void inOrder()
	{
		cout << "[�ݹ�]�������:";
		inOrder(root_);
		cout << endl;
	}
	// �ǵݹ������������
	void n_inOrder()
	{
		cout << "[�ǵݹ�]�������:";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s;
		Node* cur = root_;

		while (!s.empty() || cur != nullptr)//ջ�����ڿջ��ߵ�ǰ�ڵ㲻Ϊ��
		{
			if (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left_;
			}
			else//����Ϊ���ˣ���ʼ��ջ
			{
				Node* top = s.top();//��¼ջ��Ԫ��
				s.pop();//��ջ
				cout << s.top().data_ << " ";//��ӡ��ջǰ��ջ��Ԫ��
				cur = top->right_;//�����Һ���
			}
		}

		cout << endl;
	}
public:
	struct Node
	{
		Node(T data = T())//�㹹��
			:data_(data)
			, left_(nullptr)
			, right_(nullptr)
		{}
		T data_; // ������
		Node* left_; // ������
		Node* right_; // �Һ�����
	};
	Node* root_; // ָ��BST���ĸ��ڵ�
	Comp comp_; // ����һ����������

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