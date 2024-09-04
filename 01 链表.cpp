#include <iostream>
using namespace std;
#include "Node.h"
#include "Clink.h"

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

//合并两个有序的单链表
void MergeClink(Clink<int>& l1, Clink<int>& l2 )//按引用传递，修改形参就把实参改了
{
    Node<int>* p = l1.head->next;
    Node<int>* h = l1.head;
    Node<int>* q = l2.head->next;
    while (p!=nullptr&&q!=nullptr)
    {
        if (p->data > q->data)//p大于q，把q插进l1
        {
            l2.head->next = q->next;
            q->next = p;
            h->next = q;
            q = l2.head->next;
            h = h->next;
        }
        else
        {
            p = p->next;
            h = h->next;
            //l1.head->next = h;
        }
    }
    if (p==nullptr)
    {
        h->next = q;
    }
    
}/*这个代码更好理解*/

void MergeClink2(Clink<int>& l1, Clink<int>& l2)
{
    Node<int>* p = l1.head->next;
    Node<int>* q = l2.head->next;
    Node<int>* last = l1.head;//last为最终结果的末尾节点
    while (p != nullptr && q != nullptr)
    {
        if (p->data>q->data)//q小于p，把q插到末尾去
        {
            last->next = q;
            q = q->next;
            last = last->next;//始终指向末尾节点
        }
        else//否则把p插进去
        {
            last->next = p;
            p = p->next;
            last = last->next;
        }

    }
    if (q == nullptr)
    {
        last->next = p;
    }
    if (p==nullptr)
    {
        last->next = q;
    }
    l2.head->next = nullptr;//2置为空
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
void test06()
{
    int arr[] = {10, 15, 23, 35, 46, 77, 89, 90,91,92,93,94,95,96,97};
    int brr[] = {8,9,14,22,48,56,100,152,153,156,200};
    Clink<int> l1;
    Clink<int> l2;
    for (int v : arr)
    {
        l1.InsertTail(v);//尾插法插进去
    }
    for (int v:brr)
    {
        l2.InsertTail(v);
    }
    l1.Show();
    l2.Show();
    MergeClink2(l1, l2);
    l1.Show();
    //l2.Show();
    //cout << l1.head->next->data << endl;

}
int main()
{
    
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    system("pause");
    return 0;
}
