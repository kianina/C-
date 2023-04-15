#include<iostream>
#include<string>
#include<map>
using namespace std;


/*
1.map
2.mutimap:一个key可以对应多个值
*/
void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout <<(*it).first <<" " << it->second << endl;
	}
}
void test1() {
	map<int, int>m;
	m.insert(pair<int, int>(12, 45));	//对于数值键会自动排序
	m.insert(pair<int, int>(14, 25));
	m.insert(pair<int, int>(16, 85));
	m.insert(pair<int, int>(13, 95));
	m.insert(pair<int, int>(11, 35));
	printMap(m);
	cout<<endl;
	map<int, int>m2(m);
	printMap(m2);
	cout<<endl;
	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}
void test2()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);
	if (m1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "no empty" << endl;
		cout << "volumns is" << m1.size() << endl;
	}
	map<int, int>m2;
	m2.insert(pair<int, int>(10, 1));
	m2.insert(pair<int, int>(20, 2));
	m2.insert(pair<int, int>(30, 3));
	m2.insert(pair<int, int>(40, 4));
	cout << "begin change" << endl;
	printMap(m1);
	printMap(m2);
	cout << "after change" << endl;
	m1.swap(m2);
	printMap(m1);
	printMap(m2);

}
void test3()
{
	map<int, int>m1;
	//第一种
	m1.insert(pair<int, int>(1, 10));
	//第二种
	m1.insert(make_pair(2, 20));
	//第三种
	m1.insert(map<int, int>::value_type(3, 30));
	//第四种
	m1[4] = 40;//不建议这种，用途是利用key访问到value,不存在会自动创建，所以应该确定存在再访问
	cout << m1[4] << endl;
	printMap(m1);
	m1.erase(m1.begin());
	printMap(m1);
	m1.erase(3);//按照key删除
	printMap(m1);
	m1.erase(m1.begin(), m1.end());
	printMap(m1);
	m1.clear();
	printMap(m1);
}
void test4()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	map<int, int>::iterator pos = m1.find(3);//返回迭代器
	if (pos != m1.end())
	{
		cout << "find" << pos->first << " " << pos->second << endl;
	}
	else
	{
		cout << "no find" << endl;
	}
	//map不允许插入重复key,0 or 1
	//multimap可以大于1，可以重复
	m1.insert(pair<int,int>(3,50)); //不予许重复
	int num = m1.count(3);	//统计key是3的个数
	cout<<m1[3]<<endl;
	cout << num << endl;
}
/*排序*/
class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};
void PrintMap(map<int, int, MyCompare>& m)
{
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << " " << "value=" << it->second << endl;
	}
	cout << endl;
}
void test5()
{
	map<int, int, MyCompare>m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));
	m1.insert(make_pair(5, 50));
	PrintMap(m1);
}

//multimap
void test6()
{
	multimap<int,int> m1;
	m1.insert(make_pair(1,19));
	m1.insert(pair<int,int>(3,6));
	m1.insert(make_pair(1,78));
	int count=m1.count(1);
	auto it =m1.find(1);
	while(count)
	{
		cout<<it->first<<" "<<it->second<<endl;
		++it;
		--count;
	}
}

//采用lower_bound,upper_bound
void test7()
{
	multimap<int,int> m1;
	m1.insert(make_pair(1,66));
	m1.insert(make_pair(1,56));
	m1.insert(make_pair(1,46));
	m1.insert(make_pair(2,66));
	for(auto beg=m1.lower_bound(1),end=m1.upper_bound(1);beg!=end;++beg)
	{
		cout<<beg->second<<" ";
	}
	cout<<endl;
}
//使用equal_range(返回两个迭代器first和second在初始和结束位置)
void test8()
{
	multimap<int,int> m1;
	m1.insert(make_pair(1,66));
	m1.insert(make_pair(1,56));
	m1.insert(make_pair(1,46));
	m1.insert(make_pair(2,66));
	for(auto it=m1.equal_range(1);it.first!=it.second;++it.first)
	{
		cout<<it.first->second<<" ";
	}
}
int main() {
	test7();
	return 0;
}