#include <iostream>
using namespace std;

//节点代码
template<class T>
class Node
{
public:
    T data;
    Node<T>* next;//指向下一个节点类型的指针域，这行代码意思就是创建一个Node类型的指针。
public:
    Node<T>() //默认构造函数，创建的新节点指针域指向空
    {
        this->next = nullptr;

    };
    Node<T>(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node<T>(const T& data, Node<T> *next)
    {
        this->data = data;
        this->next = next;
    };
};


//单链实现代码
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
            while (p!=nullptr)
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
        // 
        //头插法
        void InsertFirst(T val)
        {
            Node<T>* node1 = new Node<T>(val);//创建一个新节点并初始化
            //先找到头节点指向的下一个节点，链接一下
            node1->next = head->next;//不需要判断是否为空
            head->next = node1;
        }
        //链表打印
        void Show()
        {
            Node<T> *p = head->next;
            while (p!=nullptr)
            {
                cout<< p->data << " ";
                p = p->next;
            }
            cout << endl;
        }

        //删除值为val的节点
        void Remove(T val)
        {
            Node<T>* q = head;
            Node<T>* p = head->next;
            while (p->next!=nullptr)
            {
                if (p->data == val)
                {
                    q->next = p->next;
                    delete p;
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
        Node<T>* head;//创建头节点
        
    };

//测试
    void test01()
    {
        Clink<int> link;
        link.InsertFirst(10);
        link.InsertFirst(520);
        link.InsertFirst(120);
        link.InsertFirst(220);
        link.InsertFirst(230);
        link.Show();
        //link.Remove(120);//移除120
        link.Show();


    }
    void test02()
    {
        Clink<string> link2;
        link2.InsertFirst("张三");
        link2.InsertFirst("萨三");
        link2.InsertFirst("黎三");
        link2.InsertFirst("五三");
        link2.Show();
        link2.Remove("五三");
        link2.Show();

    }
    //链表逆序
//template<class T>
void Reverse2(Clink<int> &link)//常量引用方式传入一个链表,实际上只需要一个头节点
{
    Node<int>* p = link.head->next;
    Node<int>* q = nullptr;
    link.head->next= nullptr;//转换后的首节点变成尾节点，所以其地址域要设为空

    while (p!=nullptr)
    {
        q = p->next;//保存下一个节点
        p->next = link.head->next;
        link.head->next = p;
        p = q;
        q = nullptr;
    }
}
//函数模板逆序
/*不一定非要传入整个单链，实际上传入头节点就行*/
template<class T>
void ReverseLink(Node<T>& head)
{
    Node<T>* p =head.next;
    Node<T>* q = nullptr;
    head.next = nullptr;//转换后的首节点变成尾节点，所以其地址域要设为空

    while (p != nullptr)
    {
        q = p->next;//保存下一个节点
        p->next =head.next;
        head.next = p;
        p = q;
        q = nullptr;
    }
}
//求单链表倒数第k个节点
/*z这种方法，如果链表很长，但是k也很大，不如正数快*/
template <class T>
void ReverseCount(Node<T>& head)
{
    int k=0;
    int n = 0;//节点个数
    Node<T>* q = head.next;
    while (q!=nullptr)
    {
        n = n+1;
        q = q->next;
    }

    cout << "总个数为：" << n << endl;
    cout << "请输入你要查找倒数第几个节点：" << endl;
    cin >> k;
    Node<T>* p = head.next;
    for (int i = 1; i < n-k+1; i++)
    {
        p = p->next;
    }
    cout << p->data << endl;
}

void test03()
{   

    Clink<int> link;
    link.InsertFirst(10);
    link.InsertFirst(520);
    link.InsertFirst(120);
    link.InsertFirst(220);
    link.InsertFirst(230);
    link.Show();
    Reverse2(link);
    link.Show();
    ReverseLink(*link.head);
    link.Show();

}
 
void test04()
{
    Clink<string> link2;
    link2.InsertFirst("张三");
    link2.InsertFirst("萨三");
    link2.InsertFirst("黎三");
    link2.InsertFirst("五三");
    link2.Show();
    ReverseLink(*link2.head);
    link2.Show();

}

void test05()
{
    Clink<string> link2;
    link2.InsertFirst("张三");
    link2.InsertFirst("萨三");
    link2.InsertFirst("黎三");
    link2.InsertFirst("五三");
    link2.Show();
    ReverseCount(*link2.head);


}
int main()
{
    
    //test01();
    //test02();
    test03();
    //test04();
    //test05();
    system("pause");
    return 0;
}
