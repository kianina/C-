#include <iostream>

using namespace std;
//1.this指针
//，每一个对象都能通过 this 指针来访问自己的地址。this 指针是所有成员函数的隐含参数。
//,因此，在成员函数内部，它可以用来指向调用对象,友元函数没有this指针
class Box
{
public:
    // 构造函数定义
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
    }
    double Volume()
    {
        return length * breadth * height;
    }
    int compare(Box box)
    {
        return this->Volume() > box.Volume();
    }
private:
    double length;     // Length of a box
    double breadth;    // Breadth of a box
    double height;     // Height of a box
};


//2.静态成员
//当我们声明类的成员为静态时，
//这意味着无论创建多少个类的对象，静态成员都只有一个副本
/*
不能把静态成员放置在类的定义中，
但是可以在类的外部通过使用范围解析运算符 :: 
来重新声明静态变量从而对它进行初始化
*/
class Boxu
{
public:
    static int objectCount;
    // 构造函数定义
    Boxu(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        // 每次创建对象时增加 1
        objectCount++;
    }
    double Volume()
    {
        return length * breadth * height;
    }
private:
    double length;     // 长度
    double breadth;    // 宽度
    double height;     // 高度
};
// 初始化类 Box 的静态成员
int Boxu::objectCount = 0;


//4.静态成员函数
class Boxx
{
public:
    static int objectCount;
    // 构造函数定义
    Boxx(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        // 每次创建对象时增加 1
        objectCount++;
    }
    double Volume()
    {
        return length * breadth * height;
    }
    static int getCount()
    {
        return objectCount;
    }
private:
    double length;     // 长度
    double breadth;    // 宽度
    double height;     // 高度
};
// 初始化类 Box 的静态成员
int Boxx::objectCount = 0;

int main(void)
{
    //1.
    Box Box1(3.3, 1.2, 1.5);    // Declare box1
    Box Box2(8.5, 6.0, 2.0);    // Declare box2

    if (Box1.compare(Box2))
    {
        cout << "Box2 is smaller than Box1" << endl;
    }
    else
    {
        cout << "Box2 is equal to or larger than Box1" << endl;
    }

    //2.指向类的指针
    Box* ptrBox;                // Declare pointer to a class.
    // 保存第一个对象的地址
    ptrBox = &Box1;
    // 现在尝试使用成员访问运算符来访问成员
    cout << "Volume of Box1: " << ptrBox->Volume() << endl;
    // 保存第二个对象的地址
    ptrBox = &Box2;
    // 现在尝试使用成员访问运算符来访问成员
    cout << "Volume of Box2: " << ptrBox->Volume() << endl;

    //3.静态成员
    Boxu Box11(3.3, 1.2, 1.5);   // 声明 box1
    Boxu Box21(8.5, 6.0, 2.0);    // 声明 box2
    // 输出对象的总数
    cout << "Total objects: " << Boxu::objectCount << endl;


    //4.静态成员函数
    // 在创建对象之前输出对象的总数
    cout << "Inital Stage Count: " << Boxx::getCount() << endl;
    Boxx Box12(3.3, 1.2, 1.5);    // 声明 box1
    Boxx Box22(8.5, 6.0, 2.0);    // 声明 box2
    // 在创建对象之后输出对象的总数
    cout << "Final Stage Count: " << Boxx::getCount() << endl;
    return 0;
}