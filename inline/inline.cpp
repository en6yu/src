#include<sstream>
#include<iostream>
#include<string>

using namespace std;
/**
* @brief inline use
* @author
* @param
* @return
* @note
*       1.inline 必须和函数定义在一起，只在声明中是不行的。
*       2.类成员函数有两种内联方式 隐式内联和显示内联
*       3.代码冗长和有循环时不宜用内联
*       4.虚函数和内联函数 只有知道特定调用才能用虚函数+内联 多态时就不能用内联+虚函数
*/

class CInline
{
    private:
        int m_value;
    public:
        CInline();
        ~CInline();
    public:
        void display()// 2.隐式内联
        {
            cout<<m_value<<endl;
        }
        void show();
    public:
        inline virtual void run();
};

class CSon :public CInline
{
    public:
        void run()
        {
            cout<<"Cson"<<endl;
        }
};
CInline::CInline()
{
    
}
CInline::~CInline()
{
    
}
void CInline::run()
{
    cout<<"CInline"<<endl;
}
inline void CInline::show()//2.显示内联
{
    cout<<m_value<<endl;
}


inline void print() //1. inline 必须和定义在一起
{
    cout<<"inline"<<endl;
}
int main()
{
   cout<<"CInline"<<endl;
   print();
   CSon son;
   son.run();//4.run 可以内联
   CInline * prun=new CSon();
   prun->run();//4.run 阻止内联 编译器决定的
   return 0;
}