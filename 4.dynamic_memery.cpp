#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<istream>
using namespace std;

/*
智能指针
1.shared_ptr类
2.项目：文本查询程序
*/

//shared_ptr的初始化
void test1()
{
    shared_ptr<int> p1;
    shared_ptr<vector<int>> p2;
    shared_ptr<int> p{new int[10]};     //使用new进行初始化
    p1 = make_shared<int>(10);      //使用make_shared进行初始化,推荐
    shared_ptr<int>p3=p;
    cout<<*p<<endl;
    *p3=34;
    cout<<*p<<endl;

}

//1.new
void test2()
{
    int *p=new int[10];  //申请一个数组指针
    delete [] p;
}

int main()
{
    test1();
    return 0;
}