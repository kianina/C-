//1.auto 定义RAM中的局部变量
//2.register 定义寄存器中的局部变量
//3.mutable 适用于类的对象
//4.static static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁
//5.extern extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的
//extern 是用来在另一个文件中声明一个全局变量或函数。
#include <iostream>

// 函数声明 
void func(void);

static int count = 10; /* 全局变量 */

int main()
{
    while (count--)
    {
        func();
    }
    return 0;
}
// 函数定义
void func(void)
{
    static int i = 5; // 局部静态变量
    i++;
    std::cout << "变量 i 为 " << i;
    std::cout << " , 变量 count 为 " << count << std::endl;
}