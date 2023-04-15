#include <iostream> 
using namespace std;
/*
C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数
*/
class Shape {
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    //虚函数，告诉编译器不要链接到该函数
    virtual int area() //没有virtual时，函数调用在程序执行前就准备好了。有时候这也被称为早绑定
    {
        cout << "Parent class area :" << endl;
        return 0;
    }
};
class Rectangle : public Shape {
public:
    Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
    int area()
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};
class Triangle : public Shape {
public:
    Triangle(int a = 0, int b = 0) :Shape(a, b) { }
    int area()
    {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

void test()
{
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle  tri(10, 5);
    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();
    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();
}

// 程序的主函数
int main()
{
    test();
    return 0;
}