#include<iostream>
using namespace std;
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
using std::setw;



double getAverage(int arr[], int size);
int* getRandom();

//1.数组
void fun()
{
//1.数学运算
	// 数字定义
	short  s = 10;
	int    i = -1000;
	long   l = 100000;
	float  f = 230.47;
	double d = 200.374;
	// 数学运算
	cout << "sin(d) :" << sin(d) << endl;
	cout << "abs(i)  :" << abs(i) << endl;
	cout << "floor(d) :" << floor(d) << endl;
	cout << "sqrt(f) :" << sqrt(f) << endl;
	cout << "pow( d, 2) :" << pow(d, 2) << endl;

	//2.随机数
	int i1, j1;
	//设置种子
	srand((unsigned)time(NULL));
	//生成10个随机数
	for (i = 0; i < 10; i++) {
		j1 = rand();
		cout << "随机数：" << j1 << endl;
	}


	//3.数组
	int n[10]; // n 是一个包含 10 个整数的数组
    // 初始化数组元素          
	for (int i = 0; i < 10; i++) {
		n[i] = i + 100; // 设置元素 i 为 i + 100
	}
	cout << "Element" << setw(13) << "Value" << endl;
	// 输出数组中每个元素的值                     
	for (int j = 0; j < 10; j++) {
		cout << setw(7) << j << setw(13) << n[j] << endl;
	}

	//4.多维数组
	// 一个带有 5 行 2 列的数组
	int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8} };
	// 输出数组中每个元素的值                      
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cout << a[i][j] << endl;
		}

	//5.指向数组的指针
	// 带有 5 个元素的整型数组
	double balance[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
	double* p;
	p = balance;
	// 输出数组中每个元素的值
	//输出banlance[0]的地址
	cout << &p << endl;
	cout << "使用指针的数组值 " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}
	cout << "使用 balance 作为地址的数组值 " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(balance + " << i << ") : ";
		cout << *(balance + i) << endl;
	}

	//6.传递数组给函数
	int bal[5] = { 1000, 2, 3, 17, 50 };
	double avg;
	// 传递一个指向数组的指针作为参数
	avg = getAverage(bal, 5);
	// 输出返回值
	cout << "平均值是：" << avg << endl;

	//7.从函数返回数组
	// 一个指向整数的指针
	int* plt;
	plt = getRandom();
	for (int i = 0; i < 10; i++)
	{
		cout << "*(plt + " << i << ") : ";
		cout << *(plt + i) << endl;
	}

	//8.初始化字符串
	char greeting[] = "hello";
	char greeting1[6]= { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << "Greeting message: ";
	cout << greeting << endl;
	cout << greeting1 << endl;

	//9.处理字符串函数
	char str1[11] = "Hello";
	char str2[11] = "World";
	char str3[11];
	int  len;
	// 复制 str1 到 str3
	strcpy_s(str3, str1);
	cout << "strcpy_s( str3, str1) : " << str3 << endl;
	// 连接 str1 和 str2
	strcat_s(str1, str2);
	cout << "strcat_s( str1, str2): " << str1 << endl;
	// 连接后，str1 的总长度
	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;

	//10.c++中的string类
	string str11 = "Hello";
	string str21 = "World";
	string str31;
	int  len1;
	// 复制 str1 到 str3
	str31 = str11;
	cout << "str3 : " << str31 << endl;
	// 连接 str11 和 str21
	str31 = str11 + str2;
	cout << "str11 + str21 : " << str31 << endl;
	// 连接后，str31 的总长度
	len1 = str31.size();
	cout << "str31.size() :  " << len1 << endl;
}

//2.字符串
void string_str()
{
	//初始化字符串
	string str1 = "hello";
	string str2("world");
	// string str3(10,"bu");
	cout<<str1<<" "<<str2<<" "<<endl; 
}
int main()
{
	
	return 0;
}

double getAverage(int arr[], int size)
{
	int    i, sum = 0;
	double avg;
	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}
	avg = double(sum) / size;
	return avg;
}
// 要生成和返回随机数的函数
int* getRandom( )
{
	static int  r[10];

	// 设置种子
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}

	return r;
}