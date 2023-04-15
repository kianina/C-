#include<iostream>
using namespace std;


//类模板和继承
template <class T> class base
{
public:
	T m;
};
class son:public base<int>
{
};
void test()
{
	son s;
}
template <class T1,class T2>
class son1 :public base<T2>
{
public:
	son1()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 ob;
};
void test1()
{
	son1<int, char>s2;
}

//类模板成员函数类外实现
template<class T1, class T2 >
class Person
{
public:
	Person(T1 name, T2 age);

	void showPerson() {
		cout << this->m_Name << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
void test2()
{
	Person<string, int>p("henfa", 1506);
	p.showPerson();
}
int main()
{
	test2();
	return 0;
}