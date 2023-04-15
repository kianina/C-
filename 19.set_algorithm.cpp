#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
void myPrint(int val)
{
	cout << val << " ";
}
//set_intersection求交集
void test1()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	vTarget.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itend, myPrint);
}
//set_union求并集
void test2() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	vTarget.resize(v1.size()+v2.size());
	vector<int>::iterator it=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), it, myPrint);
}
//set_difference求差集
void test3() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i+5);
		v2.push_back(i);
	}
	vector<int>vTarget;
	vTarget.resize(max(v1.size(), v2.size()));
	vector<int>::iterator it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(),it, myPrint);
}
int main()
{
	test3();
	system("pause");
	return 0;
}