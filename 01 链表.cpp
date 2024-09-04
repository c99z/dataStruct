#include <iostream>
using namespace std;
#include "Node.h"
#include "Clink.h"

//����
    void test01()
    {
        Clink<int> link;
        link.InsertFirst(10);
        link.InsertFirst(520);
        link.InsertFirst(120);
        link.InsertFirst(220);
        link.InsertFirst(230);
        link.Show();
        //link.Remove(120);//�Ƴ�120
        link.Show();


    }
    void test02()
    {
        Clink<string> link2;
        link2.InsertFirst("����");
        link2.InsertFirst("����");
        link2.InsertFirst("����");
        link2.InsertFirst("����");
        link2.Show();
        link2.Remove("����");
        link2.Show();

    }
    //��������
//template<class T>
void Reverse2(Clink<int> &link)//�������÷�ʽ����һ������,ʵ����ֻ��Ҫһ��ͷ�ڵ�
{
    Node<int>* p = link.head->next;
    Node<int>* q = nullptr;
    link.head->next= nullptr;//ת������׽ڵ���β�ڵ㣬�������ַ��Ҫ��Ϊ��

    while (p!=nullptr)
    {
        q = p->next;//������һ���ڵ�
        p->next = link.head->next;
        link.head->next = p;
        p = q;
        q = nullptr;
    }
}
//����ģ������
/*��һ����Ҫ��������������ʵ���ϴ���ͷ�ڵ����*/
template<class T>
void ReverseLink(Node<T>& head)
{
    Node<T>* p =head.next;
    Node<T>* q = nullptr;
    head.next = nullptr;//ת������׽ڵ���β�ڵ㣬�������ַ��Ҫ��Ϊ��

    while (p != nullptr)
    {
        q = p->next;//������һ���ڵ�
        p->next =head.next;
        head.next = p;
        p = q;
        q = nullptr;
    }
}
//����������k���ڵ�
/*z���ַ������������ܳ�������kҲ�ܴ󣬲���������*/
template <class T>
void ReverseCount(Node<T>& head)
{
    int k=0;
    int n = 0;//�ڵ����
    Node<T>* q = head.next;
    while (q!=nullptr)
    {
        n = n+1;
        q = q->next;
    }

    cout << "�ܸ���Ϊ��" << n << endl;
    cout << "��������Ҫ���ҵ����ڼ����ڵ㣺" << endl;
    cin >> k;
    Node<T>* p = head.next;
    for (int i = 1; i < n-k+1; i++)
    {
        p = p->next;
    }
    cout << p->data << endl;
}

//�ϲ���������ĵ�����
void MergeClink(Clink<int>& l1, Clink<int>& l2 )//�����ô��ݣ��޸��βξͰ�ʵ�θ���
{
    Node<int>* p = l1.head->next;
    Node<int>* h = l1.head;
    Node<int>* q = l2.head->next;
    while (p!=nullptr&&q!=nullptr)
    {
        if (p->data > q->data)//p����q����q���l1
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
    
}/*�������������*/

void MergeClink2(Clink<int>& l1, Clink<int>& l2)
{
    Node<int>* p = l1.head->next;
    Node<int>* q = l2.head->next;
    Node<int>* last = l1.head;//lastΪ���ս����ĩβ�ڵ�
    while (p != nullptr && q != nullptr)
    {
        if (p->data>q->data)//qС��p����q�嵽ĩβȥ
        {
            last->next = q;
            q = q->next;
            last = last->next;//ʼ��ָ��ĩβ�ڵ�
        }
        else//�����p���ȥ
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
    l2.head->next = nullptr;//2��Ϊ��
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
    link2.InsertFirst("����");
    link2.InsertFirst("����");
    link2.InsertFirst("����");
    link2.InsertFirst("����");
    link2.Show();
    ReverseLink(*link2.head);
    link2.Show();

}

void test05()
{
    Clink<string> link2;
    link2.InsertFirst("����");
    link2.InsertFirst("����");
    link2.InsertFirst("����");
    link2.InsertFirst("����");
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
        l1.InsertTail(v);//β�巨���ȥ
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
