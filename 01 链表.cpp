template<class T>
class Node 
{
    T data;
    T* next;
public:
    Node<T> node();

}
`void InsertHead(int val) //val为数据
{
    Node* node = new node(val);//把val写到新节点的地址域
    node->next = head->next;//头节点的next赋给新节点的next
    head->next = node;


}