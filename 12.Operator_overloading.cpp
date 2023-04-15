#include<iostream>
using namespace std;

/*
1.运算符重载
2.输入输出运算符要在重载前面加上引用
*/
class build
{
public:
	/*成员重载函数+*/
	build operator+(build& b) {
		build temp;
		temp.A = this->A + b.A;
		temp.B = this->B + b.B;
		return temp;
	}
	int A;
	int B;
};

/*全局函数重载+*/
// build operator+(build& a, build& b)
// {
// 	build temp;
// 	temp.A = a.A + b.A;
// 	temp.B = b.B + a.B;
// 	return temp;
// }

/*全局函数左移运算符*/
ostream &operator<<(ostream &cout,build &b) {
	cout << "A is " << b.A << "B is " << b.B;
	return cout;
}

void test() {
	build building;
	building.A = 10;
	building.B = 12;
	build building1;
	building1.A = 11;
	building1.B = 13;
	build building3 = building + building1;
	cout << building3.A << " " << building3.B << endl;
}

void test1() {
	build bb;
	bb.A = 12;
	bb.B = 34;
	cout << bb.A << endl;;
	cout << "\n";
	cout << bb.B;
}


int main()
{
    test1();
	return 0;
}