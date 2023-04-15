#include <iostream>
using namespace std;


/*
1.指针
2.指针数组
3.引用
4.const
5.返回数组指针
*/

void func()
{
    //1.指针
    int  var = 20;   // 实际变量的声明
    int* ip;        // 指针变量的声明
    ip = &var;       // 在指针变量中存储 var 的地址
    cout << "Value of var variable: ";
    cout << var << endl;
    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;

    //2.NULL指针
    int* ptr1 = NULL; //地址为内存的初地址000000
    // cout <<"ptr1的值是：" << ptr1 << endl;
}

void func1()
{
     //3.指针数组
    int  var2[3] = { 10, 100, 200 };
    int* ptr2[3];
    for (int j = 0; j < 3; j++)
    {
        ptr2[j] = &var2[j]; // 赋值为整数的地址
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Value of var2[" << i << "] = ";
        cout << *ptr2[i] << endl;
    }

    //4.指向指针的指针
    int  var3;
    int* ptr3;
    int** pptr3;
    var3 = 3000;
    // 获取 var 的地址
    ptr3 = &var3;
    // 使用运算符 & 获取 ptr 的地址
    pptr3 = &ptr3;
    // 使用 pptr 获取值
    cout << "Value of var3 :" << var3 << endl;
    cout << "Value available at *ptr3 :" << *ptr3 << endl;
    cout << "Value available at **pptr3 :" << **pptr3 << endl;
}

void func2()
{    
    //5.引用
    //引用是变量的另一个标签
     // 声明简单的变量
    int    i;
    double d;
    // 声明引用变量
    int& r = i;
    double& s = d;
    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;
    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s << endl;
}

void func3()
{
    //指向指针的引用
    int *p;
    int data=100;
    p=&data;
    cout<<*p<<endl;

    int &val = *p;
    cout<<val<<endl;

    val = 1000;
    cout<<*p<<endl;

}

void func4()
{
    //const限定符
    const int val=100;
    cout<<val<<endl;
    //const的引用,引用必须也是const类型
    const int &val1=val;
    cout<<val1<<endl;

}

void func5()
{
    //初始化和const引用
    int i=100;
    int &r1 = i;
    const int &r2 = i;
    cout<<r1<<" "<<r2<<endl;
    r1 = 10;
    //无法修改r2的值，r2是被赋予了一个临时变量的值
}


//5.返回数组指针
// 返回数组指针
// 对两个数组按位置相加
/*注意函数在执行后其中的变量会被删除，所以数组必须是全局变量或者静态变量，因为返回值
是数组的第一个值的地址，后面的会全部被删除*/

// int (*array_point(int val1[10],int val2[10]))[10]
// {

// 	static int val3[10];
// 	for(int i=0;i<10;i++)
// 	{
// 		val3[i]=val2[i]+val1[i];
// 	}
// 	return &val3;
// }
// void array_func()
// {
//     int val1[10];
//     int val2[10];
// 	for(int i=0;i<10;i++)
// 	{
// 		val1[i]=(i+1)*2;
// 		val2[i]=(i+2)*3;
// 	} 
// 	int (*plt)[10]=array_point();
// 	for(int i=0;i<10;i++)
// 	{
// 		cout<<(**plt)++<<endl;
// 	}
// }

static int arry[10] = {1,2,3,4,5,6,7,8,9,10};
int (*fun())[10]
{       
    cout<<&arry<<endl;
    for(int i=0;i<10;i++)
    {
        arry[i]=arry[i]*3;
    }
    cout<<&arry<<endl;
	return &arry;
}
void func49()
{
    int (*p)[10] = fun();
	for(int i=0;i<10;i++)
	{
		cout<<*(*p++)<<" ";
	}
	    cout<<endl;
}


int main()
{
    func49();
    return 0;
}