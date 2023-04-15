#include <iostream>
using namespace std;

/*
1.运算符的重载
*/
//1.重载print()函数
class printData
{
public:
    void print(int i) {
        cout << "Printing int: " << i << endl;
    }

    void print(double  f) {
        cout << "Printing float: " << f << endl;
    }

    void print(string c) {
        cout << "Printing character: " << c << endl;
    }
};

//2.运算符的重载
/*
重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后
要重载的运算符符号构成的。与其他函数一样，重载运算符有一个返回类型
和一个参数列表。
*/
class Box
{
public:
    double getVolume(void)
    {
        return length * breadth * height;
    }
    void setLength(double len)
    {
        length = len;
    }
    void setBreadth(double bre)
    {
        breadth = bre;
    }
    void setHeight(double hei)
    {
        height = hei;
    }
    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box& b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
private:
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度
};

//1.重载print
void test1()
{
    //1.
    printData pd;
    // Call print to print integer
    pd.print(5);
    // Call print to print float
    pd.print(500.263);
    // Call print to print character
    pd.print("Hello C++");
}


//2.运算符重载
void test2()
{
//2.
    Box Box1;                // 声明 Box1，类型为 Box
    Box Box2;                // 声明 Box2，类型为 Box
    Box Box3;                // 声明 Box3，类型为 Box
    double volume = 0.0;     // 把体积存储在该变量中
    // Box1 详述
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);
    // Box2 详述
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);
    // Box1 的体积
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;
    // Box2 的体积
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;
    // 把两个对象相加，得到 Box3
    Box3 = Box1 + Box2;
    // Box3 的体积
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume << endl;
}
int main(void)
{
    test2();
    return 0;
}