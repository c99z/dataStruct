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

/*void InsertHead(int val) //valΪ����
{
    Node* node = new node(val);//��valд���½ڵ�ĵ�ַ��
    node->next = head->next;//ͷ�ڵ��next�����½ڵ��next
    head->next = node;


}*/

//����ʵ�ִ���
template<class T>
    class Clink
    {
    public:
        Clink() 
        {
           
            head = new Node<T>();//��ʼ��ͷ�ڵ�,������Ĭ�Ϲ��캯��
            
        }
        ~Clink()
        {
            //�ڵ���ͷ�
        };
    public:
        Node<T>* head;//����ͷ�ڵ�
        //�ӿ�
        //β�巨
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

    }
    void test02()
    {
        Clink<string> link2;
        link2.InsertFirst("����");
        link2.InsertFirst("����");
        link2.InsertFirst("����");
        link2.InsertFirst("����");

        link2.Show();
    }


int main()
{
    test01();
    test02();

    system("pause");
    return 0;
}
