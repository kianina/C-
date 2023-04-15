#include <iostream>
#include<cstring>
using namespace std;


/*
1.拷贝构造函数
2.内联函数
3.友元函数
4.深拷贝和浅拷贝
*/

//1.拷贝构造函数
class Line
{
public:
    int getLength(void);
    Line(int len);             // 简单的构造函数
    Line(const Line& obj);    // 拷贝构造函数
    ~Line();                  // 析构函数

private:
    int* ptr;
};
// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
Line::Line(const Line& obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;  //为类指针变量分配内存空间，采用深拷贝
    *ptr = *obj.ptr; // copy the value
}
Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}
int Line::getLength(void)
{
    return *ptr;
}
void display(Line obj)
{
    cout << "Length of line : " << obj.getLength() << endl;
}

//测试函数1.
void func1()
{
    //1.
    Line line(10);
    display(line);
}
//测试函数4
void func4()
{
    Line line(666); //执行时会调用一次构造函数
    display(line); //执行时会进行一个深拷贝，对line对象的指针进行里一次拷贝所以要进行两次内存释放
}

//2.友元函数
class Box
{
    double width;
public:
    friend void printWidth(Box box); //友元函数，不是类里面的函数
    void setWidth(double wid);
};
// 成员函数定义
void Box::setWidth(double wid)
{
    width = wid;
}
// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width << endl;
}

//测试函数2.
void func2()
{
   //2.
    Box box;
    // 使用成员函数设置宽度
    box.setWidth(10.0);
    // 使用友元函数输出宽度
    printWidth(box);
}

//3.内联函数
//内联函数以空间换时间
//如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。
inline int Max(int x, int y)
{
    return (x > y) ? x : y;
}

//测试函数3.
void func3()
{
    //3.
    cout << "Max (20,10): " << Max(20, 10) << endl;
    cout << "Max (0,200): " << Max(0, 200) << endl;
    cout << "Max (100,1010): " << Max(100, 1010) << endl;
}



// 程序的主函数
int main()
{
    func4();
    return 0;
}