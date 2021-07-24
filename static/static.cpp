#include<sstream>
#include<iostream>
#include<string>

using namespace std;

/**
* @brief static use(study)
* @author
* @param
* @return
* @note 1.静态变量 程序周期内分配 、只分配一次、存储先前数据状态
*       2.类中静态变量 被对象共享、能直接用类直接调用
*       3.静态类对象 对象存在到程序生命周期结束
*       4.类的静态函数 和成员变量一样 共享和直接调用 只能访问静态成员和静态函数
*/
static string a="d";//最好初始化 、不初始化也会被初始化为默认值 int 默认0 string 默认空

class Cstatic
{
    public:
        static int t;
        int m_value;
    public:
        Cstatic();
        ~Cstatic();
    public:
        static void show();
};
Cstatic::Cstatic()
{
    cout<<"Cstatic"<<endl;
}
Cstatic::~Cstatic()
{
    cout<<"~Cstatic"<<endl;
}
int Cstatic::t=1;
void Cstatic::show()
{
    //cout<<m_value<<endl; //4 静态函数只能处理静态
    cout<<t<<endl;
}

void display()
{
    static int b=1;//1 只分配一次 存储先前状态
    cout<<b<<endl;
    b++;

}

int main()
{
    cout<<a<<endl;
    for (int i=0;i<5;i++)
    {
        display();
    }
    //cout<<b<<endl;//虽然是静态变量、但是有作用域

    cout<<Cstatic::t<<endl;//2 不需要实例化直接调用

    {
        Cstatic cst;
        cst.t=8;
        cout<<Cstatic::t<<endl;//2 实例化之间共享数据值
    }//3.析构函数在此之前调用
    {
        static Cstatic sstic;;
    }//3.析构函数在程序结束后调用

    Cstatic::show();

    cout<<"end main"<<endl;
    
    return 0;
}