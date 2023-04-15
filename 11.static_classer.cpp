#include<iostream>
using namespace std;
class person {
public:
	static void fun() {
		a = 10;//静态函数只能访问静态变量
		cout << "这是静态成员函数" << endl;
	}
	static int a;
};
void test() {
	person p;
	p.fun();
	person::fun();//通过类名访问
}
int main() {
	test();
	return 0;
}