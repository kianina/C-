#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<time.h>
using namespace std;

/*
1.sort算法，rand_shuff算法，merge算法，reverse算法
2.unique
3.使用谓词
4.lambda表达式
*/
//sort算法
void myPrint(int val)
{
	cout << val << " ";
}
void myPrintString(string str)
{
    cout<<str<<" ";
}
void test1()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(60);
	v.push_back(5);
	v.push_back(30);
	v.push_back(2);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
}
//random_shuff算法,打乱元素顺序
void test3()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
}
//merge合并算法
void test4()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	//目标容器
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(),myPrint);
}
//reserve反转算法
void test5()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(60);
	v.push_back(5);
	v.push_back(30);
	v.push_back(2);
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

//unique消除重复单词(unique返回不重复值范围末尾的迭代器)
void test6()
{
    vector<string> str{"ahig","qgohri","gohair","aohg","ogh","ooahgia","gohair","qgohri"};
    sort(str.begin(),str.end());
    for_each(str.begin(),str.end(),myPrintString);
    cout<<endl;
    auto end_unique=unique(str.begin(),str.end());
    for_each(str.begin(),str.end(),myPrintString);
    cout<<endl;
    str.erase(end_unique,str.end());
    for_each(str.begin(),str.end(),myPrintString);
}
//采用谓词的方式对元素进行sort
//按字符串的长短进行排序
bool isSorter(const string &s1,const string &s2)
{
    return s1.size()<s2.size();
}
void test7()
{
    vector<string> str{"ahig","qgohri","gohair","aohg","ogh","ooahgia","gohair","qgohri"};
    sort(str.begin(),str.end(),isSorter);
    for_each(str.begin(),str.end(),myPrintString);
}

//practice10.3.1
//practice10.13
bool isPartition(const string &str)
{
    return str.size()<5;
}
void practice10_13()
{
    vector<string> str{"ahig","qgohri","gohair","aohg","ogh","ooahgia","gohair","qgohri"};
    partition(str.begin(),str.end(),isPartition);
    for_each(str.begin(),str.end(),myPrintString);
}

//lambda表达式进行排序
void test8()
{
    vector<string> str{"ahig","qgohri","gohair","aohg","ogh","ooahgia","gohair","qgohri"};
    sort(str.begin(),str.end(),[](const string &str1,const string &str2){return str1.size()>str2.size();});
    for_each(str.begin(),str.end(),myPrintString);
}
//practice10.3.2
//practice10.14
void practice10_14() //打印两数字之和
{
    int a,b;
    auto c=[](int a,int b)->int{return a+b;};  //尾置返回类型   
    cout<<c(1,3)<<endl;
}
//practice10.15
void practice10_15()  //lambda采用值捕获
{
    int data;
    cin>>data;
    auto f=[data](int b){return data+b;};
    auto j=f(10);
    cout<<j<<endl;
}
void practice10_15_2()  //lambda采用引用捕获
{
    int data;
    cin>>data;
    auto f=[&data](int b){return data+b;};
    auto j=f(188);
    cout<<j<<endl;
}
void practice10_15_3()  //采用隐式捕获
{
    int data;
    cin>>data;
    auto f=[&](int b){return data+b;};  //&表示引用捕获
    auto g=[=](int b){return data+b;};  //=表示值捕获
    auto j=f(18);
    cout<<j<<endl;
}
void test9()    //可变lambda(捕获的值可以改变)
{
    int data;
    cin>>data;
    auto f=[=](int b)mutable{return ++data+b;};
    auto j=f(1);
    cout<<j<<endl;
}
//practice10.21
void practice10_21()
{
    int d;
    cin>>d;
    auto f=[&]()->bool{while(d!=0)d--; return true;}; 
    cout<<f()<<endl;  
}
int main() {
	// srand((unsigned int)time(NULL));
    practice10_21();
	return 0;
}