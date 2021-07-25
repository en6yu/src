#include<sstream>
#include<iostream>
#include<string>

using namespace std;
/**
* @brief use prureVirtual
* @author
* @param
* @return
* @note
*       1.没有函数体的虚函数、直接等于0
*       2.有纯虚函数的类是抽象类、不能实例化、只能作为基类
*       3.继承类必须实现虚函数、才能不是抽象类，不实现还是抽象类
*       4.构造函数不能是虚构函数（本身为了初始化实例）、析构函数有些场景必须是析构函数才能析构数据
*/

class CPureVirtual
{
    private:
    
    public:
        CPureVirtual();
        ~CPureVirtual();
        virtual void run()=0;//1. 纯虚函数不需要函数体
};
CPureVirtual::CPureVirtual()
{
    
}
CPureVirtual::~CPureVirtual()
{
    
}
class CSon :public CPureVirtual
{
    public:
        void run();
};
void CSon::run()
{
    cout<<"CSon"<<endl;
}
int main()
{
    //CPureVirtual pv;//2. error 含有纯虚函数的类不能实例化 
    CSon son;
    son.run();//3. 继承类实现基类虚函数
   return 0;
}