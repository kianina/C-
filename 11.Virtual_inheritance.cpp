#include<iostream>
using namespace std;


class animal
{
public:
	int age=49;
};
//利用虚继承可以解决菱形继承问题
//在继承之前加上关键字virtual变为虚继承
// Animal类称为虚基类
class sheep:virtual public animal
{

};
class tuo:virtual public animal
{

};
class sheepTuo :public sheep, public tuo
{

};
void test()
{
	sheepTuo St;
	//St.sheep::age = 10;
	St.tuo::age = 11;
	cout << St.sheep::age << endl;
	cout << St.tuo::age << endl;
	cout << St.age << endl;
}

int main() 
{
	test();
	return 0;
}