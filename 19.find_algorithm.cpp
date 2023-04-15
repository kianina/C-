#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
#include<string>
#include<numeric>
#include<time.h>
using namespace std;

/*
只读算法(不能修改元素值)
1.find,find_if
2.count,count_if
3.accumulate,equal
*/
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	//重载==，该函数表示两个对象中的元素是否相等
	bool operator ==(const Person& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};



//内置find查找算法
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5); 
	if (it == v.end())
	{
		cout << "no find" << endl;
	}
	else
	{
		cout<<distance(v.begin(),it)<<" ";
		cout << "find:" << *it << endl;
		
	}
}
//自定义数据类型
void test02()
{
	vector<Person>V;
	Person p1("1", 11);
	Person p2("2", 22);
	Person p3("3", 33);
	Person p4("4", 44);

	V.push_back(p1);
	V.push_back(p2);
	V.push_back(p3);
	V.push_back(p4);

	vector<Person>::iterator it = find(V.begin(), V.end(), p4);
	if (it == V.end())
	{
		cout << "no find" << endl;
	}
	else
	{
		cout << "find:" << it->m_Name<<endl;
        cout<<it->m_Age<<endl;
	}
}

//find_if查找,可以为其查找值指定规则
//内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
}; 
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "no find" << endl;
	}
	else
	{
		cout << "find" << *it << endl;
	}
}
//自定义的数据类型
class Person1
{
public:
	Person1(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};
class Greater20
{
public:
	bool operator()(Person1& p) {
		return p.m_Age;
	}
};
void test04()
{
	vector<Person1>V;
	Person1 p1("1", 11);
	Person1 p2("2", 22);
	Person1 p3("3", 33);
	Person1 p4("4", 44);

	V.push_back(p1);
	V.push_back(p2);
	V.push_back(p3);
	V.push_back(p4);

	vector<Person1>::iterator it = find_if(V.begin(), V.end(), Greater20());
	if (it == V.end())
	{
		cout << "no find" << endl;
	}
	else
	{
		cout << "find:" << it->m_Name<<endl;
        cout<<it->m_Age<<endl;
	}
}

//adjecent_find查找两个连续相等的元素
void test05()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(3);
	v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "no find" << endl;
	}
	else
	{
		cout << "find the neighbor data" << *it << endl;
	}
}

//binary_search查找算法
void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//这个容器必须是有序的序列，如果是无序的序列，结果未知
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "find" << endl;
	}
	else
	{
		cout << "no find" << endl;
	}
}

//count 统计元素个数
void test07()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);

	int num = count(v.begin(), v.end(), 10);
	cout << num << endl;
}

class Person2
{
public:
	Person2(string m_name,int m_age) {
		this->age = m_age;
		this->name = m_name;
	}
	bool operator==(const Person2& p) {
		if (p.age == this->age) {
			return true;
		}
		else {
			return false;
		}
	}
	int age;
	string name;
};
void test08()
{
	vector<Person2>v;
	Person2 p1("s1", 11);
	Person2 p2("s2", 12);
	Person2 p3("s3", 13);
	Person2 p4("s5", 14.1);
	Person2 p5("s5", 14.1);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = count(v.begin(), v.end(), p5); //对数值值进行比较，而不是字符串
	cout << num << endl;
}

//count_if统计算法
class greater20
{
public:
	bool operator()(int val) {
		return val > 20;
	}        
};
void test09()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	int num = count_if(v.begin(), v.end(), greater20());
	cout << num << endl;
}
class AgeGreater20
{
public:
	bool operator()(const Person2& p) {
		return p.age > 20;
	}
};
void test10()
{
	vector<Person2>v;
	Person2 p1("s1", 11);
	Person2 p2("s2", 22);
	Person2 p3("s3", 33);
	Person2 p4("s4", 44);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	int num = count_if(v.begin(), v.end(), AgeGreater20());
	cout << num << endl;
}

//practice10.1
//practice10.1
void practice10_1()
{
    vector<int> v1;
    for(int i=0;i<36;i++)
    {
        v1.push_back(i%7);
    }
    int num =count(v1.begin(),v1.end(),4);
    cout<<"data count is :"<<num<<endl;
}
//practice10.2
void practice10_2()
{
    list<string> ls;
    for(int i=0;i<18;i++)
    {
        ls.push_back("i");
    }
    int num=count(ls.begin(),ls.end(),"i"); 
    cout<<num<<endl;
}


//accumulate算法，统计序列间元素和
//practice10.2.1
//practice10.3
void practice10_3()
{
    vector<int> v1;
    for(int i=0;i<18;i++)
    {
        v1.push_back(i+3);
    }
    int num = accumulate(v1.begin(),v1.end(),0); //从零开始相加
    cout<<num<<endl;
}
void practice10_5()
{
    double seed=time(0);
    srand(seed);
    vector<double> d1;
    for(int i=0;i<19;i++)
    {
        d1.push_back(rand()%18/(double(18)));
        cout<<d1[i]<<endl;
    }
    double num=accumulate(d1.cbegin(),d1.cend(),0.0);
    cout<<num<<endl;
    string str("hgaihaoihgrha");
    string str1("hgaihaoihgrha");
    bool bo = equal(str.cbegin(),str.cend(),str1.cbegin());
    cout<<bo<<endl;
}
int main()
{   
    practice10_5();
	return 0;
}