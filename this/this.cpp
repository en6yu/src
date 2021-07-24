#include<sstream>
#include<iostream>
#include<string>

using namespace std;

/**
* @brief class this use
* @author
* @param
* @return
* @note
*       1.this 不是对象的一部分，不会影响sizeof的返回值
*       2.this 在类内部，非静态函数访问静态成员 编译器自动加this
*       3.return *this 返回本对象
*/
class CThis
{
    private:
        int m_value;
    public:
        CThis();
        ~CThis();
    public:
        void display();
        CThis &getCthis();
};
CThis::CThis():m_value(1)
{
    
}
CThis::~CThis()
{
    
}
void CThis::display()
{
    cout<<this->m_value<<endl;//2. 自动加this 指针
}
CThis &CThis::getCthis()
{
    return *this;
}


int main()
{
   cout<<"CThis"<<endl;
   cout<<sizeof(CThis)<<endl; //1. 大小是4 是int 的大小不包括this 的大小
   CThis cthis;
   cthis.display();
   cthis.getCthis().display();//3 返回这个对象
   return 0;
}