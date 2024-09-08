#pragma once
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
        while (p != nullptr)
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
     void InsertTail(T val)
    {
        Node<T>* node1 = new Node<T>(val); //new�ķ���ֵ��һ��ָ�����
        Node<T>* p = head;
        while (p->next!=nullptr)//���ҵ�β�ڵ�
        {
            p = p->next;
        }
        p->next =node1;
        //node1->next = nullptr;
    }
    //ͷ�巨
    void InsertFirst(T val)
    {
        Node<T>* node1 = new Node<T>(val);//����һ���½ڵ㲢��ʼ����new�ķ���ֵ��һ��ָ�����
        //���ҵ�ͷ�ڵ�ָ�����һ���ڵ㣬����һ��
        node1->next = head->next;//����Ҫ�ж��Ƿ�Ϊ��
        head->next = node1;
    }
    //�����ӡ
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

    //ɾ��ֵΪval�Ľڵ�
    void Remove(T val)
    {
        Node<T>* q = head;
        Node<T>* p = head->next;
        while (p->next != nullptr)
        {
            if (p->data == val)
            {
                q->next = p->next;
                delete p;//ɾ������Ҫȡ�����ӣ���Ҫdelete
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
    Node<T>* head;//����ͷ�ڵ�ָ��
    
};
