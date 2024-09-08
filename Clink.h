#pragma once
template<class T>
class Clink
{
public:
    Clink()
    {

        head = new Node<T>();//初始化头节点,并调用默认构造函数

    }
    ~Clink()//析构得遍历每一个节点
    {
        Node<T>* q = head;
        Node<T>* p = head->next;//麻烦了，head用不着了，可以直接用head操作
        while (p != nullptr)
        {
            delete q;
            q = p;
            p = p->next;

        }
        //节点的释放
    };
public:

    //接口
    //尾插法
     void InsertTail(T val)
    {
        Node<T>* node1 = new Node<T>(val); //new的返回值用一个指针接收
        Node<T>* p = head;
        while (p->next!=nullptr)//先找到尾节点
        {
            p = p->next;
        }
        p->next =node1;
        //node1->next = nullptr;
    }
    //头插法
    void InsertFirst(T val)
    {
        Node<T>* node1 = new Node<T>(val);//创建一个新节点并初始化，new的返回值用一个指针接收
        //先找到头节点指向的下一个节点，链接一下
        node1->next = head->next;//不需要判断是否为空
        head->next = node1;
    }
    //链表打印
    void Show()
    {
        Node<T>* p = head->next;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    //删除值为val的节点
    void Remove(T val)
    {
        Node<T>* q = head;
        Node<T>* p = head->next;
        while (p->next != nullptr)
        {
            if (p->data == val)
            {
                q->next = p->next;
                delete p;//删除不仅要取消链接，还要delete
                return;//void型返回值
            }
            else
            {
                q = p;
                p = p->next;
            }
        }


    }
    friend void Reverse2(const Clink<T>& link);
    //frined void ReverseLink(const Node<T>& head;
public:
    Node<T>* head;//创建头节点指针
    
};
