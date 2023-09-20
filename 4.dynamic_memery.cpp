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
1.shared_ptr类（共享指针）
1.1-shared_ptr的初始化
2.unique_ptr类（独一指针）
*/

//shared_ptr的初始化
void test1()
{
    shared_ptr<int> p1;
    shared_ptr<vector<int>> p2;
    shared_ptr<int> p{new int[10]};     // 使用new进行初始化
    p1 = make_shared<int>(10);      // 使用 make_shared进行初始化,推荐

    // 初始化指针保存一个空指针
    if(p2 && p2->empty()){
        *p2 = vector<int> {3, 4, 6};
        cout<<"vecotr智能指针p2的值:"<<p2<<endl;
    }

    // 智能指针
    shared_ptr<int> p3 = p;
    cout<<*p<<endl;
    *p3=34;
    cout<<*p<<endl;

}

// shared_ptr的引用个数
class Test
{
public:
    Test()
    {
        std::cout << "Test()" << std::endl;
    }
    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }
};
void test2()
{
    std::shared_ptr<Test> p1 = std::make_shared<Test>();
    std::cout << "1 ref:" << p1.use_count() << std::endl;
    // 作用域表记符
    {
        std::shared_ptr<Test> p2 = p1;
        std::cout << "2 ref:" << p1.use_count() << std::endl;
    }
    std::cout << "3 ref:" << p1.use_count() << std::endl;
}


int main()
{
    test2();
    return 0;
}