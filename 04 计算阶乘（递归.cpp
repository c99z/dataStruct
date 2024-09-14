#include <iostream>
using namespace std;
//求输入的数的阶乘
int func1(int n) {//定义一个函数就是求n的阶乘
    if (n == 0 || n == 1) {
        return 1;//结束递归
    }
    else {
        return n * func1(n - 1);//n的阶乘等于n乘以n-1的阶乘，n-1的阶乘可以用这个函数计算
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