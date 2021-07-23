#include<sstream>
#include<iostream>
#include<string>
//#include"other.cpp"

using namespace std;

/**
* @brief const use(study)
* @author
* @param
* @return
* @note 1.定义常量
*       2.const 和#define 定义常量的区别  const类型检查、#define 只是简单替换
*       3.防止修改 保护作用 增加程序健壮性
*       4.const 定义初始化 后续不能修改
*       5.const 默认文件内局部变量 不同文件访问需要显示调用extren
*       6.指针和常量
*       7.函数中使用 const 参数修饰为const 参数不能被修改 
*       8.类中成员函数后加const,里面数据不能被修改
*       9.static 和const 同时使用，不能被修改的静态变量 
*/
#define length 6

//extern const int c;//5 


class test
{
    private:
        int m_value;
        static const int m_t;
    public:
        test();
        ~test();
    public:
        void show()const;
};
test::test():m_value(1)
{

}
test::~test()
{
    
}
void test::show()const//8
{
   //m_value=m_value+1;
}

const int test::m_t=1;

void display(const int a)//7
{
    //a=a+10;
}

int main()
{
    const int a=4;//1

    cout<<a<<endl;

    cout<<length<<endl;//2

    //a=5; //3 error const not modfication

    //const int b; //4 error must init start 

    //cout<<c<<endl; //5

    //6 --begin--
    int aa=1;
    int bb=2;
     int * const p=&aa;
    //p=&bb; //指针是常量 、指针不能被修改
    *p=4;    //指向内容可修改
    int const * q=&aa;
    q=&bb;  //指针可修改
    //*q=6; //指向内容是常量
    //6 --end--

    display(7);
    test t1;
    t1.show();

    return 0;
}