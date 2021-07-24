#include<sstream>
#include<iostream>
#include<string>

using namespace std;
/**
* @brief use sizeof
* @author
* @param
* @return
* @note
*       1. 空类sizeof 是1
*       2. 类中成员函数(静态和非静态)、虚函数、静态成员都是不占类对象存储空间
*       3. 继承 是派生类和基类大小之和 会继承基类虚函数表 (还需要考虑数据对齐)
*/
class CSizeof
{
    private:
    
    public:
        CSizeof();
        ~CSizeof();
};
CSizeof::CSizeof()
{
    
}
CSizeof::~CSizeof()
{
    
}
class CSizeof1
{
    public:
        static int m_value;   
    public:
        CSizeof1();
        ~CSizeof1();
    public:
        void display()
        {
            cout<<"CSizeof1"<<endl;
        }
        static int getValue()
        {
            return m_value;
        }
        virtual void run();
};
int CSizeof1::m_value=1;
CSizeof1::CSizeof1()
{
    
}
CSizeof1::~CSizeof1()
{
    
}
void CSizeof1::run()
{
    cout<<"CSizeof2"<<endl;
}


class CSizeof2
{
    public:
        char m_a;
        int m_b;
        char m_c;
        char m_d;
    public:
        CSizeof2();
        ~CSizeof2();
    public:
        virtual void run();
};
CSizeof2::CSizeof2()
{
    
}
CSizeof2::~CSizeof2()
{
    
}
void CSizeof2::run()
{
    cout<<"test"<<endl;
}

class CSon:public CSizeof2
{
    public:
        char m_f;
        int m_e;
};

int main()
{
   //cout<<"CSizeof"<<endl;
   cout<<sizeof(CSizeof)<<endl; //1. 空类大小为1
   
   cout<<sizeof(CSizeof1)<<endl; //2. 值为8 是虚函数表的长度（32 位是4 、64位是8） 不管多少个虚函数大小都是8

   cout<<sizeof(CSon)<<endl;//3. 值24 4(m_a)+4+4（m_c+m_d+m_f）+4+8 考虑对齐
   return 0;
}