#include <iostream>
using namespace std;

//�ڵ����
template<class T>
class Node
{
public:
    T data;
    Node<T>* next;//ָ����һ���ڵ����͵�ָ�������д�����˼���Ǵ���һ��Node���͵�ָ�롣
public:
    Node<T>() //Ĭ�Ϲ��캯�����������½ڵ�ָ����ָ���
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


//����ʵ�ִ���
template<class T>
    class Clink
    {
    public:
        Clink() 
        {
           
            head = new Node<T>();//��ʼ��ͷ�ڵ�,������Ĭ�Ϲ��캯��
            
        }
        ~Clink()//�����ñ���ÿһ���ڵ�
        {
            Node<T>* q = head;
            Node<T>* p = head->next;//�鷳�ˣ�head�ò����ˣ�����ֱ����head����
            while (p!=nullptr)
            {
                delete q;
                q = p;
                p = p->next;
                
            }
            //�ڵ���ͷ�
        };
    public:
        
        //�ӿ�
        //β�巨
        // 
        //ͷ�巨
        void InsertFirst(T val)
        {
            Node<T>* node1 = new Node<T>(val);//����һ���½ڵ㲢��ʼ��
            //���ҵ�ͷ�ڵ�ָ�����һ���ڵ㣬����һ��
            node1->next = head->next;//����Ҫ�ж��Ƿ�Ϊ��
            head->next = node1;
        }
        //�����ӡ
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

        //ɾ��ֵΪval�Ľڵ�
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
                    return;//void�ͷ���ֵ
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
        Node<T>* head;//����ͷ�ڵ�
        
    };

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
