#include <iostream>
using namespace std;

/*
1.全局变量
2.局部变量
3.局部静态变量
*/

//1. 全局变量声明
int g = 10;

// 2.引用
// 引用其实是给对象起别名，就是将新名字和变量的值绑定在一块
void func()
{
    int val = 100;
    cout<<val<<endl;
    int &val_one = val;
    cout<<val_one<<endl;
    val_one = 10;
    cout<<val<<endl;
}

//3.局部变量
void func1()
{
    // 局部变量声明
   int a, b;
   // 实际初始化
   a = 10;
   b = 20;
   int g = 100;
   //访问块作用域
   cout<<g<<" "<<a<<endl;
   //显示访问全局变量
   cout<<::g<<endl;
}

// 3.局部静态对象
//practice6.1.1
//practice6.7
int func6_7()
{
    static int i=0; //局部静态变量，不会因为函数结束而销毁，但是局部变量会
    return i++;
}
void practice6_7()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cout<<func6_7()<<endl;
    }
}


int main()
{
    practice6_7();
   return 0;
}
