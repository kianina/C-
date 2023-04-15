#include<iostream>
using namespace std;

/*
1.模板语法
*/

void intchange(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void doublechange(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
/*函数模板*/
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test()
{
	int a, b;
	double c, d;
	a = 11;
	b = 43;
	c = 13.55;
	d = 13.77;
	//intchange(a, b);
	//doublechange(c, d);
	mySwap(a, b);
	mySwap<double>(c, d);
	cout <<  a <<"\n" << b<<"\n" << c<<"\n" << d <<"\n" << endl;

}


int main()
{
	test();
	return 0;
}