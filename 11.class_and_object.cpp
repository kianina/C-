#include <iostream>

using namespace std;

/*
1.类的基本定义
2.类的成员的3种访问方式
*/

//1.定义并访问类的成员
class Box
{
public:
    //3.作用域解析符,用于类内成员的访问
    void Box::show()
    {
        cout<<Box::getVolume()<<endl;
    }
    double length;   // 长度
    double breadth;  // 宽度
    double height;   // 高度
    //2.类的成员函数
    // 成员函数声明
    double getVolume(void);
    void setLength(double len);
    void setBreadth(double bre);
    void setHeight(double hei);
};
//1.成员函数定义
double Box::getVolume(void)
{
    return length * breadth * height;
}
void Box::setLength(double len)
{
    length = len;
}
void Box::setBreadth(double bre)
{
    breadth = bre;
}
void Box::setHeight(double hei)
{
    height = hei;
}
//1.
void func()
{
    ////1.
    //Box Box1;        // 声明 Box1，类型为 Box
    //Box Box2;        // 声明 Box2，类型为 Box
    //double volume = 0.0;     // 用于存储体积
    //// box 1 详述
    //Box1.height = 5.0;
    //Box1.length = 6.0;
    //Box1.breadth = 7.0;
    //// box 2 详述
    //Box2.height = 10.0;
    //Box2.length = 12.0;
    //Box2.breadth = 13.0;
    //// box 1 的体积
    //volume = Box1.height * Box1.length * Box1.breadth;
    //cout << "Box1 的体积：" << volume << endl;
    //// box 2 的体积
    //volume = Box2.height * Box2.length * Box2.breadth;
    //cout << "Box2 的体积：" << volume << endl;

    //2.类的成员函数
    Box Box1;                // 声明 Box1，类型为 Box
    Box Box2;                // 声明 Box2，类型为 Box
    double volume = 0.0;     // 用于存储体积
    // box 1 详述
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);
    // box 2 详述
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);
    // box 1 的体积
    volume = Box1.getVolume();
    cout << "Box1 的体积：" << volume << endl;
    // box 2 的体积
    volume = Box2.getVolume();
    cout << "Box2 的体积：" << volume << endl;

}

//2.类成员的3种访问方式
//1.直接成员运算符
void func1()
{
    Box box;
    box.length=100,box.breadth=19,box.height=7;
    int volume;
    volume=box.getVolume();
    cout<<volume<<endl;
}
//2.间接成员运算符
void func2()
{
    Box *box = new Box; //创建一个类的指针
    box->breadth=19,box->height=18,box->length=8;
    cout<<box->getVolume()<<endl;
}


int main()
{
    
    return 0;
}