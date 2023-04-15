#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
#include<vector>

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector容器构造
void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	printVector(v);
	//通过区间的方式进行构造
	vector<int>v1(v.begin(), v.end());
	printVector(v1);
	//n个elem方式构造
	vector<int>v3(10, 100);//10个100
	printVector(v3);
	//拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//赋值 operator= 
	vector<int>v2;
	v2 = v1;
	printVector(v2);
	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());//使用assign将v3中的元素替换成迭代器范围内的元素
	printVector(v3);
	//n个elem方式赋值
	vector<int>v4;
	v4.assign(10, 100);//10个100，替换成n个值是100的元素
	printVector(v4);
}

//对vector容器重新指定大小
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//判断是否是空
	if (v1.empty()) {
		cout << "kong" << endl;
	}
	else {
		cout << "bu kong" << endl;
	}
	cout << "the capacity of v1" << v1.capacity() << endl;
	cout << "the size of v1" << v1.size() << endl;
	//重新指定大小
	v1.resize(15, 100);//利用重载版本，可以指定默认填充值，第二个参数
	printVector(v1);//如果重新指定的比原来的长，默认用0填充
	v1.resize(5);
	printVector(v1);//如果重新指定的比原来短，超出的部分会删除掉	
}

//vector容器的增删改查
void test03()
{
	vector<int>v1;
	//尾插法
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	//遍历
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	//删除 参数也是迭代器
	v1.erase(v1.begin());
	printVector(v1);
	//清空
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}

//vector容器 数据存取
void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//利用[]访问数组中的元素
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//利用at方式访问元素
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//获取第一个元素
	cout << "the frist data" << v1.front() << endl;

	//获取最后一个元素
	cout << "the last data" << v1.back() << endl;
}
void test05()
{
	vector<int>v1;
	cout << "begin change" << endl;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int>v2;

	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	cout << "after change" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
//巧用swap可以收缩内存空间
void test06()
{
	vector<int>v;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}

	cout << "capacity" << v.capacity() << endl;
	cout << "size" << v.size() << endl;
	cout << endl;
	v.resize(3);//重新指定大小
	cout << "capacity" << v.capacity() << endl;
	cout << "size" << v.size() << endl;
	//巧用swap收缩内存
	vector<int>(v).swap(v);
	cout << endl;
	cout << "capacity" << v.capacity() << endl;
	cout << "size" << v.size() << endl;
}
//vector容器 预留空间
void test07()
{
	vector<int>v1;
	int num = 0;//统计开辟次数
	int* p = NULL;
	v1.reserve(100000);
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);

		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;
}

//使用swap函数
void test08()
{
    vector<int> str1;
    vector<int> str2;
    for(int i=0;i<10;i++)
    {
        str1.push_back(i+3);
    }
    for(int i=0;i<20;i++)
    {
        str2.push_back(i);
    }
    printVector(str1);
    printVector(str2);
    swap(str1,str2);  //使用swap函数直接交换

    printVector(str1);
    printVector(str2);
}
int main()
{
	test06();
	return 0;
}