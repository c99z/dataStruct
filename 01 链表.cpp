template<class T>
class Node 
{
    T data;
    T* next;
public:
    Node<T> node();

}
`void InsertHead(int val) //valΪ����
{
    Node* node = new node(val);//��valд���½ڵ�ĵ�ַ��
    node->next = head->next;//ͷ�ڵ��next�����½ڵ��next
    head->next = node;


}