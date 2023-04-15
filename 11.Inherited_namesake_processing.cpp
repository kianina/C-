#include<iostream>
using namespace std;

/*
1.继承中的重名问题
2.多继承
*/

class Page
{
public:
	  Page() {
		A = 10;
	}
	  void func() {
		  cout << "The function call of the parent class" << endl;
	  }
	  static void fun() {
		  cout << "The parent class static function calls" << endl;
	  }
	int A;
};
class Bage
{
public:
	Bage() {
		B = 110;
	}
	int B;
};
class Son :public Page
{
public:
	 Son() {
		A = 11;
	}
	 void func()
	 {
		 cout << "A member function call to a subclass" << endl;
	 }
	 static void fun() {
		 cout << "Subclass static function call" << endl;
	 }
	int A;

};
/*多继承*/
class Son2 :public Page, public Bage
{

};

void test() {
	Son son;
	cout << son.A << endl;
	//如果要通过子类对象访问到父类中的同名成员，需要加作用域
	cout << son.Page::A << endl;
}
//同名函数的处理方式
void test1() {
	Son son1;
	son1.func();
	son1.fun();
	//如果子类中出现和父类同名的成员函数
	//子类的同名成员会隐藏掉父类中所有同名成员函数
	//如果想要访问到父类中被隐藏的同名成员函数，需要加作用域
	son1.Page::func();
	son1.Page::fun();
}
//多继承
void test3()
{
	Son2 son3;
	cout << son3.Bage::B << endl;
	cout << son3.Page::A << endl;
}
int main() {
	test1();
	return 0;
}