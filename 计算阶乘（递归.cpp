#include <iostream>
using namespace std;
//����������Ľ׳�
int func1(int n) {//����һ������������n�Ľ׳�
    if (n == 0 || n == 1) {
        return 1;//�����ݹ�
    }
    else {
        return n * func1(n - 1);//n�Ľ׳˵���n����n-1�Ľ׳ˣ�n-1�Ľ׳˿����������������
    }
}

void test01()
{
    cout << func1(4) << endl;
}


int main()
{
    //test07();
    //test08();
    test01();
    system("pause");
    return 0;
}