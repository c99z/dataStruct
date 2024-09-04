
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
    Node<T>(const T& data, Node<T>* next)
    {
        this->data = data;
        this->next = next;
    };
};