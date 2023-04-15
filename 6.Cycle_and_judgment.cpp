#include <iostream>
using namespace std;

/*
1.循环语句
*/
int main()
{
    //1.break
    // 局部变量声明
    int a = 10;

    // do 循环执行
    do
    {
        cout << "a value:" << a << endl;
        a = a + 1;
        if (a > 15)
        {
            // 终止循环
            break;
        }
    } while (a < 20);
    //2.continue
      // 局部变量声明
    int a1 = 10;

    // do 循环执行
    do
    {
        if (a1 == 15)
        {
            // 跳过迭代
            a1 = a1 + 1;
            continue;
        }
        cout << "a1 value" << a1 << endl;
        a1 = a1 + 1;
    } while (a1< 20);
    //3.goto
    // 局部变量声明
    int a2 = 10;
    // do 循环执行
    LOOP:do
    {
        if (a2 == 15)
        {
            // 跳过迭代
            a2 = a2 + 1;
            goto LOOP;
        }
        cout << "a2 value" << a2 << endl;
        a2 = a2 + 1;
    } while (a2 < 17);

    //3.switch
    // 局部变量声明
    char grade = 'D';
    switch (grade)
    {
    case 'A':
        cout << "good" << endl;
        break;
    case 'B':
    case 'C':
        cout << "do well" << endl;
        break;
    case 'D':
        cout << "you passed" << endl;
        break;
    case 'F':
        cout << "try it" << endl;
        break;
    default:
        cout << "no grade" << endl;
    }
    cout << "you grade is " << grade << endl;
    return 0;
}