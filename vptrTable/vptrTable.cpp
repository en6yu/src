#include<sstream>
#include<iostream>
#include<string>

using namespace std;
/**
* @brief use vptrTable
* @author
* @param
* @return
* @note
*       1.虚函数表 动态的后期调用函数、只要有虚函数就有虚函数表：类的每个对象虚函数指针指向虚函数表
*       2.继承时如果基类的虚函数没有实现，虚函数指针指向基类的
*       3.虚函数中的默认参数 看指针的默认参数
*       4.虚函数和多态 取决于指针指向类型也不是指针类型
*       5.静态函数不能声明为虚函数 不属于对象，没有this 指针调用vptr
*       6.构造函数也不能声明为虚函数，
*/
class CVirtual
{
    public:
        virtual void fun1();
        virtual void fun2();
        virtual void fun3(int a=3);
        //virtual static void fun4(); //5. 静态函数不能声明为虚函数
    public:
        CVirtual();
        //virtual CVirtual(); // 6.构造函数也不能声明为虚函数
        ~CVirtual();
};
CVirtual::CVirtual()
{
    
}
CVirtual::~CVirtual()
{
    
}
void CVirtual::fun1()
{
    cout<<"CVirtual fun1"<<endl;
}
void CVirtual::fun2()
{
    cout<<"CVirtual fun2"<<endl;    
}
void CVirtual::fun3(int a) //声明或者定义一个位置写缺省值即可
{
    cout<<"CVirtual fun3 a="<<a<<endl;   
}
class CSon :public CVirtual
{
    public:
        void fun1();
        void fun3(int a=5);  
};
void CSon::fun1()
{
    cout<<"Cson fun1"<<endl;
}
void CSon::fun3(int a)
{
    cout<<"Cson fun3 a="<<a<<endl;
}


int main()
{
   //cout<<"CVirtual"<<endl;

    CVirtual *p=new CSon();
    p->fun2();// 2.虚函数指向基类
    p->fun1();// 4.取决于指向类型而不是指针类型
    p->fun3();// 3.默认参数取决于指针类型而不是指向类型
   return 0;
}