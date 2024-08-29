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

/*void InsertHead(int val) //val为数据
{
    Node* node = new node(val);//把val写到新节点的地址域
    node->next = head->next;//头节点的next赋给新节点的next
    head->next = node;


}*/

//单链实现代码
template<class T>
    class Clink
    {
    public:
        Clink() 
        {
           
            head = new Node<T>();//初始化头节点,并调用默认构造函数
            
        }
        ~Clink()
        {
            //节点的释放
        };
    public:
        Node<T>* head;//创建头节点
        //接口
        //尾插法
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

    }
    void test02()
    {
        Clink<string> link2;
        link2.InsertFirst("张三");
        link2.InsertFirst("萨三");
        link2.InsertFirst("黎三");
        link2.InsertFirst("五三");

        link2.Show();
    }


int main()
{
    test01();
    test02();

    system("pause");
    return 0;
}
