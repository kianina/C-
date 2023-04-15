#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void myPrint(int val)
{
	cout << val << endl;
}
void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(7);
	v.push_back(50);
	v.push_back(0);
	vector<int>::iterator itBegin = v.begin();//起始迭代器，指向第一个元素
	vector<int>::iterator itEnd = v.end();//指向最后一个元素最后一个
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	for_each(v.begin(), v.end(),myPrint);
}
int main()
{
	test();
	return 0;
}