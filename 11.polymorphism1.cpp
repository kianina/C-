#include<iostream>
using namespace std;
class animal
{
public:
	//加上virtual变成虚函数,实现地址晚绑定
	virtual void speak()
	{
		cout << "animal speaking" << endl;
	}
};
class cat :public animal
{
public:
	 void speak() {                 //重写基类的函数
		cout << "cat speaking" << endl;
	}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "dog speaking" << endl;
	}
};
void dospeak(animal& ani)
{
	ani.speak();
}
void test()
{
	cat catt;
	dog dogg;
	dospeak(catt);
	dospeak(dogg);
}
int main()
{
	test();
	return 0;
}