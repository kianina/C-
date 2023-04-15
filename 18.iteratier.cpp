#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<list>
#include<time.h>
using namespace std;

/*
1.for_each查看元素
2.插入迭代器
3.反向迭代器
*/
void print(int val)
{
	cout << val << " ";
}

class print1
{
public:
	 void operator()(int val)
	{
		cout << val << " ";
	}
};
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print);
	cout << endl;
	for_each(v.begin(), v.end(), print1());
	cout << endl;
}

class TransForm
{
public:
	int operator()(int val)
	{
		return val + 100;
	}
};
class myprint
{
public:
	void operator()(int val) {
		cout << val << " ";
	}

};


void test2()
{
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>vM;
	vM.resize(v.size());
	transform(v.begin(), v.end(), vM.begin(), TransForm()); //对vector中的元素做变换
	for_each(vM.begin(), vM.end(), myprint());
	cout << endl;
}

//插入迭代器
void test3()
{
	list<int> li={1,5,6,3,1};
	list<int> li1,li2;
	copy(li.cbegin(),li.cend(),front_inserter(li1));	//插入最前面或最后面
	copy(li.cbegin(),li.cend(),inserter(li2,li2.begin()));	//按位置插入	
	for_each(li.cbegin(),li.cend(),myprint());
	cout<<endl;
	for_each(li1.cbegin(),li1.cend(),myprint());
	cout<<endl;
	for_each(li2.cbegin(),li2.cend(),myprint());
	cout<<endl;
}

//practice10.4.1
//practice10.27
void practice10_27()
{
	vector<int> v1;
	for(int i=0;i<19;i++){
		v1.push_back(i%8);
	}
	list<int> li;
	sort(v1.begin(),v1.end());   //需要先对元素进行排序
	unique_copy(v1.cbegin(),v1.cend(),back_inserter(li));  //第三个参数接收一个插入迭代器
	for_each(li.cbegin(),li.cend(),myprint());
}


//3.反向迭代器
//构建反向迭代器，逆序打印容器中的值
void test4()
{
	int seed=time(0);
	srand(seed);
	vector<int> v1;
	for(int i=0;i<17;i++)
	{
		v1.push_back(rand()/(i+1));
	}
	for_each(v1.cbegin(),v1.cend(),myprint());
	cout<<endl;
	for_each(v1.crbegin(),v1.crend(),myprint());
}

//practece10.4.3
//practice10.34
void practice10_34()
{
	int seed=time(0);
	srand(seed);
	vector<int> v1;
	for(int i=0;i<17;i++)
	{
		v1.push_back(rand()/(i+1));
	}
	for_each(v1.cbegin(),v1.cend(),myprint());
	cout<<endl;
	reverse_iterator<vector<int>::iterator>my_iter(v1.end()); //创建一个指向最后一个元素的反向迭代器
	for(int i=0;i<17;i++)
	{
		cout<<*my_iter<<" ";
		my_iter++;
	}
}
//practice10.36
void practice10_36()
{
	list<int> li={1,61,0,16,0,61,4,0,61};
	reverse_iterator<list<int>::iterator>my_iter_end(li.rbegin());
	reverse_iterator<list<int>::iterator>my_iter_begin(li.rend());
	auto f=find(my_iter_end,my_iter_begin,0);
	cout<<distance(f,my_iter_begin)<<" ";  //使用distance返回元素所在的位置
	cout<<*f<<endl;
}
//practice10.37
// void practice10_37()
// {
// 	vector<int> v1;
// 	list<int> ls;
// 	for(int i=0;i<18;i++)
// 	{
// 		v1.push_back(i);
// 	}
// 	reverse_iterator<list<int>::iterator>my_iter_end(v1.cbegin());
// 	reverse_iterator<list<int>::iterator>my_iter_begin(v1.cbegin()+3);
// 	copy(my_iter_end,my_iter_begin,back_inserter(ls));
// 	for_each(ls.cbegin(),ls.cend(),myprint());
// }


int main()
{
	// practice10_37();
	return 0;
}