#include <iostream>
using namespace std;

/*
1.类的构造函数
2.类的析构函数
*/


//1.类的构造函数
//类的构造函数会为某些变量设置初始值
class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line();  // 这是构造函数

private:
    double length;
};
// 成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "Object is being created" << endl;
}
void Line::setLength(double len)
{
    length = len;
}
double Line::getLength(void)
{
    return length;
}

//2.带参数的构造函数
class Line1
{
public:
    void setLength(double len);
    double getLength(void);
    Line1(double len);  // 这是构造函数

private:
    double length;
};
// 成员函数定义，包括构造函数
Line1::Line1(double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}
void Line1::setLength(double len)
{
    length = len;
}
double Line1::getLength(void)
{
    return length;
}


//3.类的析构函数
//作用，跳出程序，释放资源
class Line2
{
public:
    void setLength(double len);
    double getLength(void);
    Line2();   // 这是构造函数声明
    ~Line2();  // 这是析构函数声明

private:
    double length;
};

// 成员函数定义，包括构造函数
Line2::Line2(void)
{
    cout << "Object is being created" << endl;
}
Line2::~Line2(void)
{
    cout << "Object is being deleted" << endl;
}
void Line2::setLength(double len)
{
    length = len;
}
double Line2::getLength(void)
{
    return length;
}



// 程序的主函数
int main()
{
    //1.类的构造函数
    Line line;
    // 设置长度
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;


    //2.带参数的构造函数
    Line1 line1(10.0);
    // 获取默认设置的长度
    cout << "Length of line1 : " << line1.getLength() << endl;
    // 再次设置长度
    line1.setLength(6.0);
    cout << "Length of line1 : " << line1.getLength() << endl;

    //3.析构函数
    Line2 line2;
    // 设置长度
    line2.setLength(6.0);
    cout << "Length of line : " << line2.getLength() << endl;
    return 0;
}