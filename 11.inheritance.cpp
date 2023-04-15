#include<iostream>
#include<string>
using namespace std;

//公共页面
class BasePage
{
public:
	void header()
	{
		cout << "Home page, login registration" << endl;
	}
	void footer()
	{
		cout << "Help center, exchange and cooperation" << endl;
	}
	void left()
	{
		cout << "java,python,c++" << endl;

	}
};
//普通实现页面

//java页面
class Java : public BasePage
{
public:
	void contenet()
	{
		cout << "java Discipline Video" << endl;
	}
};
class Python : public BasePage
{
public:
	void contenet()
	{
		cout << "python Subject Videos" << endl;
	}
};
class Cpp : public BasePage
{
public:

	void contenet()
	{
		cout << "c++ discipline Video" << endl;
	}
};
void test()
{
	cout << "java" << endl;
	Java java;
	java.header();
	java.footer();
	java.left();
	java.contenet();

	cout << endl;

	cout << "python" << endl;
	Python python;
	python.header();
	python.footer();
	python.left();
	python.contenet();

	cout << endl;

	cout << "cpp" << endl;
	Cpp cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.contenet();
}
int main(void)
{
	test();
	return 0;
}

