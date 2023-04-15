#include<iostream>
#include<list>
#include<forward_list>
using namespace std;

/*
list容器，本质上是一个双向链表
forward_list容器，本质上是一个单向链表
*/
void printList(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it <<" ";
	}
	cout << endl;
}
//初始list容器
void test1() {
	list<int>l;
	l.push_back(12);
	l.push_back(15);
	l.push_back(1);
	l.push_back(62);
	l.push_back(22);
	printList(l);
	list<int>l1(l.begin(), l.end());
	printList(l1);
}
//list容器赋值和交换
void test2() {
	list<int>l;
	l.push_back(12);
	l.push_back(15);
	l.push_back(1);
	l.push_back(62);
	l.push_back(22);
	printList(l);
	list < int>l1;
	l1.push_back(14);
	l1.push_back(15);
	l1.push_back(98);
	l1.push_back(95);
	l1.push_back(19);
	printList(l1);
	l1.swap(l);
	printList(l);
	printList(l1);
}
//查看list容器的大小
void test3()
{
	list<int>l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	printList(l1);
	if (l1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "no empty" << endl;
		cout << "the number of data" << l1.size() << endl;
	}
	//重新指定大小
	l1.resize(10, 1000);  
	printList(l1);
}

//list容器的增删改查
void test4()
{
	list<int>l1;
	//尾
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	//头
	l1.push_front(10);
	l1.push_front(20);
	printList(l1);
	//删
	l1.pop_back();
	printList(l1);
	l1.pop_front();
	printList(l1);
	//插入
	list<int>::iterator it = l1.begin();
	it++;
	l1.insert(it, 1000);
	printList(l1);
	//删除
	//用的时候指定it
	it = l1.begin();
	l1.erase(++it);
	printList(l1);
	//移除
	l1.push_back(1000);
	l1.push_back(1000);
	l1.push_back(1000);
	printList(l1);
	l1.remove(1000);//删除所有匹配的元素
	printList(l1);
	//清空
	l1.clear();
	printList(l1);
}
void test5()
{
	list<int>l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	//list中不可以用[]访问容器中的元素
	//at()也不行
	//因为List本质是链表，不是用连续的线性空间存储数据，迭代器也是不支持随机访问的
	cout << "the frist data" << l1.front() << endl;
	cout << "the last data" << l1.back() << endl;
	//验证迭代器是不支持随机访问的
	list<int>::iterator it = l1.begin();
	it++;//支持++ --  双向
	it--;
	//it = it+1;不行——不支持随机访问
}

//反转容器内的元素
void test6()
{
	list<int>l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	cout << "begin of reverse" << endl;
	printList(l1);
	//反转
	cout << "after of reverse" << endl;
	l1.reverse();
	printList(l1);
}

bool myCompare(int v1, int v2)
{
	//降序 第一个数>第二个数
	return v1 > v2;
}
//排序
void test7()
{
	list<int>l2;
	l2.push_back(20);
	l2.push_back(10);
	l2.push_back(50);
	l2.push_back(30);
	l2.push_back(40);
	cout << "begin of queue" << endl;
	printList(l2);
	//所有不支持随机访问迭代器的容器不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应的一些算法
	cout << "after of queue" << endl;
	l2.sort();
	printList(l2);
	l2.sort(myCompare);//降序
	printList(l2);
}

//forward容器,对其中的元素进行增删改查
void test8()
{
    forward_list<int> list={0,1,2,3,4,5,6,7,8,9};
    for(forward_list<int>::iterator it=list.begin();it!=list.end();it++)
    {
        cout<<*it<<" ";
    }
    //1.删除奇数元素
    auto prev = list.before_begin(); //表示list的首前元素(链表中的头结点)
    auto curr = list.begin();  //表示list的第一个元素
    while(curr!=list.end())
    {
        if(*curr%2){
            curr=list.erase_after(prev); //erase_after:删除prev之后的一个元素
                                        //返回一个被删除元素之后的一个节点位置的指针
        }
        else{
            prev=curr;
            ++curr;
        }
    }
    cout<<endl;
    for(forward_list<int>::iterator it=list.begin();it!=list.end();it++)
    {
        cout<<*it<<" ";
    }
}
int main() {
    test8();
	return 0;
}