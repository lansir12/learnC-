#include <iostream>
#include <thread>
#include "windows.h"

void thread_function()
{
    auto sleepTime = std::chrono::milliseconds(1000);
    for (int i = 0;i<5 ;++i)
    {
        std::this_thread::sleep_for(sleepTime);
        std::cout << "function point thread:" <<i<< std::endl;
    }
}

class A
{
public:
    A() { std::cout << "default construct function" << std::endl; }
    A(int a) { std::cout << "A class one parameter" << std::endl; }
    ~A(){}
    void operator()(){
        for (int i = 0; i<5;++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "class () function point thread:" << i << std::endl;
        }
    }

    void ordinaryFunc() {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "class ordinary function point thread:" << i << std::endl;
        }
    }

    void prit() {
        std::cout << "hello" << std::endl;
    }

    
};


int main() {
//     A a = A();//创建一个a对象
//     a.ordinaryFunc();

//     A a;//创建一个a对象
//     a.ordinaryFunc();
   // A a();//声明 一个返回A类型的a函数；不是创建a对象！！！

    A()();
    /*
    std::thread firstThread(thread_function);
    firstThread.detach();

    std::thread secondThread([]()->void{
        for (int k = 0; k<5; ++k)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "lambada func thread:" << k << std::endl;
        }
    });
    secondThread.detach();

    std::thread thirdThread((A()));
    thirdThread.detach();

    A objA;
//     std::thread thirdThread(objA);
//     thirdThread.detach();

    std::thread fourthThread(&A::ordinaryFunc,&objA);
    fourthThread.detach();


    for(int j = 0; j<3; ++j)
    {   
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "main function:" <<j<< std::endl;
    }
    
    int num;
    std::cin >> num;

    */
    return 0;
}
