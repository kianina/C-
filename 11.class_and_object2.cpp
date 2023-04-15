#include <iostream>

using namespace std;


/*
1.类的访问权限
2.友元
*/


//1.公有成员
class Line
{
public: 
    double length;
    void setLength(double len);
    double getLength(void);
};
// 成员函数定义
double Line::getLength(void)
{
    return length;
}

void Line::setLength(double len)
{
    length = len;
}


//2.私有成员
class Box
{
public:
    double length;
    void setWidth(double wid);
    double getWidth(void);

private:
    double width;
};

// 成员函数定义
double Box::getWidth(void)
{
    return width;
}

void Box::setWidth(double wid)
{
    width = wid;
}



//3.保护成员
class Box1
{
protected:
    double width;
};

class SmallBox1 :Box1 // SmallBox 是派生类
{
public:
    void setSmallWidth(double wid);
    double getSmallWidth(void);
};

// 子类的成员函数
double SmallBox1::getSmallWidth(void)
{
    return width;
}

void SmallBox1::setSmallWidth(double wid)
{
    width = wid;
}
//测试函数
void func()
{
    //1.公有成员
    Line line;
    // 设置长度
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;
    // 不使用成员函数设置长度
    line.length = 10.0; // OK: 因为 length 是公有的
    cout << "Length of line : " << line.length << endl;


    //2.私有成员
    Box box;
    // 不使用成员函数设置长度
    box.length = 10.0; // OK: 因为 length 是公有的
    cout << "Length of box : " << box.length << endl;
    // 不使用成员函数设置宽度
    // box.width = 10.0; // Error: 因为 width 是私有的
    box.setWidth(10.0);  // 使用成员函数设置宽度
    cout << "Width of box : " << box.getWidth() << endl;

    //3.保护成员
    SmallBox1 box1;
    // 使用成员函数设置宽度
    box1.setSmallWidth(5.0);
    cout << "Width of box1 : " << box1.getSmallWidth() << endl;

}

//2.友元
class number
{
friend void func1(); //1.全局函数作为友元
friend class number1;
public:
    int sum(int a,int b)
    {
        return a+b;
    }
    int sub(int a,int b)
    {
        return a-b;
    }
    int toub(int a,int b)
    {
        int c=this->multi(a,b);
        return c+b;
    }
private:
    int a;
    int b;
    int multi(int a,int b)
    {
        return a*b;
    }
};
//测试1，全局函数作为友元
void func1()
{
    number num;
    int a=10,b=100,data,data1;
    data=num.sum(a,b);
    cout<<data<<endl;
    data1=num.multi(a,b);  //使用友元访问类的私有成员函数
    cout<<data1<<endl;
}
//测试2，类作为友元
class number1
{
public:
    int a=10,b=100;
    void func_numx()
    {
    number num;
    a=num.sub(a,b);
    cout<<a<<endl;
    b=num.multi(a,b);
    cout<<b<<endl;
    }
};
void func2()
{
    number1 num;
    num.func_numx();
}

//测试3，成员函数作为友元
void func3()
{
    number num;
    int a=100,b=15;
    int c=num.toub(a,b);
    cout<<c<<endl;
}


// 程序的主函数
int main()
{
    func3();
    return 0;
}