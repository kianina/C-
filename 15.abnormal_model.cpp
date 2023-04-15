#include <iostream>
using namespace std;

//1.捕获异常
double division(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("Division by zero condition!");
    }
    return (a / b);
}

//2.定义新的异常
struct MyException : public exception
{
    const char* what() const throw ()
    {
        return "C++ Exception";
    }
};

//3.异常测试
void abnormal_code()
{
    //  //1.
    // int x = 50;
    // int y;
    // double z = 0;
    // cin>>y;
    // try {
    //     z = division(x, y);
    //     cout << z << endl;
    // }
    // catch (const char* msg) {
    //     cerr << msg << endl;
    // }

    //2.
    try
    {
        throw MyException();
    }
    catch (MyException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        //其他的错误
    }
}
int main()
{
    abnormal_code();
    return 0;
}