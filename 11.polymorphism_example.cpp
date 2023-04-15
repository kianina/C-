#include<iostream>
using namespace std;


/*抽象的计算器基类*/
class calcultor
{
public:
	virtual int getresult()
	{
		return 0;
	}
	int A;
	int B;
};
/*加法计算器*/
class Addcalcultor:public calcultor
{
public:
	virtual int getresult()     //重写了父类的虚函数
	{
		return A+B;
	}
};
/*-*/
class Subcalcultor :public calcultor
{
public:
	virtual int getresult()
	{
		return A - B;
	}
};
/***/
class Mulcalcultor :public calcultor
{
public:
	virtual int getresult()
	{
		return A * B;
	}
};
void test()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	//加法
	calcultor* abc = new Addcalcultor;//父类指针指向子类对象
	abc->A = 10;
	abc->B = 107;
	cout << abc->getresult() << endl;
	delete abc;
}
int main()
{
	test();
	return 0;
}