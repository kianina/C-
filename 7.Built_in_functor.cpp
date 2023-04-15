#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
	negate<int>n;
	cout << n(50) << endl;
}
//加法仿函数
void test2()
{
	plus<int>p;
	cout << p(12, 3) << endl;
}
/*关系仿函数*/
void test3()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(2);
	v.push_back(5);
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
}
//逻辑仿函数
void test4()
{
	vector<bool>v;
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	vector<bool>v1;
	v1.resize(v.size());
	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
}
int main()
{
	test4();
	return 0;
}