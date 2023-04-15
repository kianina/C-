#include <iostream>
using namespace std;

//1.数据抽象
/*
数据封装是一种把数据和操作数据的函数捆绑在一起的机制，
数据抽象是一种仅向用户暴露接口而把具体的实现细节隐藏起来的机制。
*/
class Adder {
public:
    // 构造函数
    Adder(int i = 0)
    {
        total = i;
    }
    // 对外的接口
    void addNum(int number)
    {
        total += number;
    }
    // 对外的接口
    int getTotal()
    {
        return total;
    };
private:
    // 对外隐藏的数据
    int total;
};

//2.接口
//C++ 接口是使用抽象类来实现的，抽象类与数据抽象互不混淆，数据抽象是一个把实现细节与相关的数据分离开的概念
//如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。纯虚函数是通过在声明中使用 "= 0" 来指定的
//设计抽象类（通常称为 ABC）的目的，是为了给其他类提供一个可以继承的适当的基类。抽象类不能被用于实例化对象，它只能作为接口使用。如果试图实例化一个抽象类的对象，会导致编译错误。
// 基类
class Shape
{
public:
    // 提供接口框架的纯虚函数
    virtual int getArea() = 0;
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
protected:
    int width;
    int height;
};

// 派生类
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};
class Triangle : public Shape
{
public:
    int getArea()
    {
        return (width * height) / 2;
    }
};
int main()
{
    //1.
    Adder a;
    a.addNum(10);
    a.addNum(20);
    a.addNum(30);
    cout << "Total " << a.getTotal() << endl;

    //2.
    Rectangle Rect;
    Triangle  Tri;
    Rect.setWidth(5);
    Rect.setHeight(7);
    // 输出对象的面积
    cout << "Total Rectangle area: " << Rect.getArea() << endl;
    Tri.setWidth(5);
    Tri.setHeight(7);
    // 输出对象的面积
    cout << "Total Triangle area: " << Tri.getArea() << endl;
    return 0;
}