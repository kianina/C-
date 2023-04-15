#include<iostream>
#include<string>
#include<set>
using namespace std;

/*
1.set:集合中数据自动按从大到小排列
2.multiset:可以插入重复元素（集合）
3.pair:组
4.set容器的操作
*/
void  PrintSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void PrintMultiSet(multiset<int>& ms)
{
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	set<int>s;
	s.insert(10);
	s.insert(14);
	s.insert(16);
	s.insert(11);
	PrintSet(s);
}
void test2()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	PrintSet(s1);
	if (s1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "no empty" << endl;
		cout << "volumns:" << s1.size() << endl;
	}
}
void test4()
{
	set<int>s2;
	set<int>s3;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s3.insert(1);
	s3.insert(2);
	s3.insert(3);
	cout << "begin change:" << endl;
	PrintSet(s2);
	PrintSet(s3);
	s2.swap(s3);
	cout << "after change:" << endl;
	PrintSet(s2);
	PrintSet(s3);
}
void test3()
{
	set<int>s1;
	s1.insert(2);
	s1.insert(1);
	s1.insert(3);
	s1.insert(4);
	PrintSet(s1);
	s1.erase(s1.begin());
	PrintSet(s1);
	s1.erase(3);
	PrintSet(s1);
	s1.erase(s1.begin(), s1.end());
	PrintSet(s1);
	s1.clear();
	PrintSet(s1);
}
void test5()
{
	set<int>s1;
	s1.insert(1);
	s1.insert(3);
	s1.insert(3);
	s1.insert(4);
	set<int>::iterator pos = s1.find(3);
	if (pos != s1.end())
	{
		cout << "find" << *pos << endl;
	}
	else
	{
		cout << "no find" << endl;
	}
	PrintSet(s1);
	int num = s1.count(3);
	//对于set而言 统计结果 0 或 1，因为无重复
	cout << num << "a" << endl;
}
void test6()
{
	set<int>s1;
	pair<set<int>::iterator, bool>ret = s1.insert(10);
	if (ret.second)
	{
		cout << "successful insert" << endl;
	}
	else
	{
		cout << "fail insert" << endl;
	}
	//第二次
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "successful insert" << endl;
	}
	else
	{
		cout << "fail insert" << endl;
	}
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	PrintMultiSet(ms);
}

/*对组的创建*/
void test7() {
	pair<string, int>p("tom", 12);
	cout << p.first << p.second << endl;
	pair<string, int>p1 = make_pair("jerry", 12);
	cout << p1.first << p1.second << endl;
}
/*set容器的指定排序*/
class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};
void test8() {
	set<int>s1;
	s1.insert(12);
	s1.insert(55);
	s1.insert(7);
	s1.insert(78);
	PrintSet(s1);
	set<int,MyCompare>s2;
	s2.insert(12);
	s2.insert(55);
	s2.insert(7);
	s2.insert(78);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};
class Mycompare
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_Age > p2.m_Age;
	}
};
void test9()
{
	set<Person, Mycompare>s1;
	Person p1("s1", 11);
	Person p2("s2", 22);
	Person p3("s3", 33);
	Person p4("s4", 44);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	for (set<Person, Mycompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << it->m_Name << " " << it->m_Age << endl;
	}
}
int main() 
{
	test9();
	return 0;
}