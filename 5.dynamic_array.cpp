#include <iostream>
#include<memory>
using namespace std;


/*
1.new和数组
*/
//1.为对象分配内存
class Box
{
public:
	Box() {
		cout << "have gouzao functino" << endl;
	}
	~Box() {
		cout << "have xigou function" << endl;
	}
};
void test1()
{
	//1.为变量分配内存
	double* pvalue = NULL; // 初始化为 null 的指针
	pvalue = new double;   // 为变量请求内存
	*pvalue = 29494.99;     // 在分配的地址存储值
	cout << "Value of pvalue : " << *pvalue << endl;
	delete pvalue;         // 释放内存
	//2.
	Box* myBoxArray = new Box[4];
	delete[] myBoxArray; // Delete array
}

//1.初始化动态分配的数组对象
void test2()
{
	int *pia=new int[10];
	int *pia2=new int[10]();	//初始化为0
	int *pia3=new int[3]{1,2,3};
	typedef int arrT[10];
	int *p=new arrT;
	cout<<pia3[1]<<endl;
	delete [] pia3;	//释放动态数组
	delete [] pia2;
	delete [] pia;
	delete [] p;
}
//2.智能指针和动态数组
void test3()
{
	unique_ptr<int[]> up(new int[10]);
	for(int i=0;i!=10;i++)
	{
		up[i]=i;
	}
	cout<<up[9]<<endl;
	up.release();	//自动调用delete销	毁指针
}
int main()
{
	test3();
	return 0;
}