#include<iostream>
#include<time.h>
using namespace std;


/*
1.数组
2.多维数组
3.常用运算符
*/

//常用运算符
void func()
{
	//1.sizeof ;返回变量的大小
	int a = 10;
	int X = 1;
	int Y = 2;
	cout << sizeof(a) << endl;
	
	//2.Condition ? X:Y 条件运算符
	cout << (a > 5) ? X : Y;
	cout << "\n" << endl;

	//3.逗号运算符
	int b = (a++, a + 100, a + 99);
	cout << b << endl;

	//4.Cast 强制转换运算符
	double c = 20.144;
	cout << int(c) << endl;

	//5.指针运算符
	// & 运算符读作"取地址运算符"
	cout << &c << endl;
	//* 是一元运算符，返回操作数所指定地址的变量的值。
	int* p;
	int data = 100;
	p = &data;
	cout << *p << endl;
	cout << p << endl;
}

//1.数组
//1.1复杂数组的声明
void func1()
{
	int arr[5]={1,2,3,5,6};
	int *plt[5];
	int (*plt1)[5]=&arr; //指向一个含有5个元素的数组
	int (&arrRef)[5]=arr; //为每个元素进行引用
	for(int i=0;i<5;i++)
	{
		// cout<<plt[i]<<endl;
		cout<<(*plt1)[i]<<endl;
		// cout<<arrRef[i]<<endl;
	}
	cout<<*plt1<<endl; //输出指针的地址
}
//practice3.5.3
//practice3.35
void practice3_35()
{
	int num=10;
	int arr[num];
	int (&arrRe)[num]=arr;
	for(int i=0;i<num;i++)
	{
		arrRe[i]=i*3;
	}
	cout<<arrRe[3]<<endl;
	int (*plt)[num] = &arrRe;
	for(int i=0;i<num;i++)
	{
		(*plt)[i] = 0;
	}
	cout<<arrRe[3]<<endl;
	int *plt1=&arrRe[0];
	for(;plt1!=&arrRe[num];plt1++)
	{
		(*plt1)=1;
	}
	cout<<arrRe[3]<<endl;
}

//1.2多维数组和指针
void func2()
{
	unsigned seed;
	seed=time(0);
	srand(seed);
	int num1=4,num2=5;
	int arr[num1][num2];
	for(int i=0;i<num1;i++)
	{
		for(int j=0;j<num2;j++)
		{
			arr[i][j]=(i+1)*(j+1);
		}
	}

	int (*plt)[num2]=arr; //指向该数组的num1的第一个元素，该元素有一个长度是num2的数组
	cout<<(*plt)[1]<<endl; //输出num1的第二个元素
	cout<<(*(plt+1))[1]<<endl; //输出num2的第二个元素
}
int main()
{
	func2();
	return 0;
}