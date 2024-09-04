
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
    Node<T>(const T& data, Node<T>* next)
    {
        this->data = data;
        this->next = next;
    };
};