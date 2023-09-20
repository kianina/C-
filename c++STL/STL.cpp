/*STL的体系结构和内核分析*/

#include<iostream>
#include<functional>
#include<vector>
#include<list>
#include<array>
#include<forward_list>
#include<ctime>
#include<deque>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
1.遍历容器
2.容器的六大部件
3.array容器
4.vector容器
5.list容器
6.forward_list容器
7.deque容器
8.multiset容器
9.multimap容器
10.unordered_multiset
11.unordered_multimap
12.set
13.map
14.unordered_set
15.unordered_map

*/


//输出vector容器中的值
template<typename T>
void print(vector<T> v) {
	int i = 0;
	for(auto cur : v) {
		cout<<cur<<" ";
		if(i++ % 10 == 0) cout<<endl;
	}
}
//1.遍历容器
void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(7);
	v.push_back(50);
	v.push_back(0);
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	while (itBegin != itEnd)
	{
		cout << *itBegin <<" ";
		itBegin++;
	}
	cout<<endl;
	for (auto it : v) {
		cout << it <<" ";
	}
	cout<<endl;
	for_each(v.begin(), v.end(),[](int i) {cout<<i<<" ";});
}

/**2.六大部件**/
void test2_1() {
	int ia[6] = {1,3,65,16,7,41};
	vector<int, allocator<int>> a(ia, ia+6);
	cout<<count_if(a.begin(), a.end(), not1(bind2nd(less<int>(), 40)))<<endl;
}

//辅助测试函数
long get_a_target_long() {
	long target = 0;
	cout<<"target (0~"<<RAND_MAX<<"):";
	cin>>target;
	return target;
}
string get_a_target_string() {
	long target = 0;
	char buf[10];
	cout<<"target (0~"<<RAND_MAX<<"):";
	cin>>target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}
int compareLongs(const void* a, const void* b) {
	return (*(long*)a - *(long*)b);
}
int compareStrings(const void* a, const void* b) {
	if(*(string*)a > *(string*)b) return 1;
	else if(*(string*)a < *(string*)b) return -1;
	else return 0;
}

/***3.array测试**/
#define ASIZE 500000
void test3_1() {
	array<int, ASIZE> arr;
	clock_t timestart = clock();
	for(long i = 0; i < ASIZE; i++){
		arr[i] = rand();
	}
	cout<<"milli-second = "<<clock() - timestart<<endl;
	cout<<"array size = "<<arr.size()<<endl;
	cout<<"array front = "<<arr.front()<<endl;
	cout<<"array back = "<<arr.back()<<endl;
	cout<<"array data = "<<arr.data()<<endl;

	long target = get_a_target_long();
	timestart = clock();
	qsort(arr.data(), ASIZE, sizeof(long), compareLongs);
	long *item = (long*)bsearch(&target, arr.data(), ASIZE, sizeof(long), compareLongs);
	cout<<"qsort + search = "<<clock() - timestart<<endl;
	if(item != NULL) cout<<"found = "<<*item<<endl;
	else cout<<"not found"<<endl;
}

/***4.vector容器测试*****/
void test4_1() {
	long value = 100000;
	vector<string> str;
	char buf[10];

	clock_t timeStart = 0;
	for(long i = 0; i < value; i++) {
		try{
			snprintf(buf, 10, "%d", rand());
			str.push_back(string(buf));
		}
		catch(exception &p){
			cout<<"i="<<i<<""<<p.what()<<endl;
			abort();
		}
	}
	cout<<"milli-seconds = "<<clock() - timeStart<<endl;
	cout<<"vector size = "<<str.size()<<endl;
	cout<<"vector front = "<<str.front()<<endl;
	cout<<"vector back = "<<str.back()<<endl;
	cout<<"vector data = "<<str.data()<<endl;
	cout<<"vector capacity = "<<str.capacity()<<endl;

	//测试查找时间
	string target = get_a_target_string();

	timeStart = clock();
	auto item = find(str.begin(), str.end(), target);  //顺序查找
	cout<<"find milli-second = "<<clock() - timeStart<<endl;
	if(item != str.end()) cout<<"found = "<<*item<<endl;
	else cout<<"not found"<<endl;

	//测试排序+二分查找时间
	timeStart = clock();
	sort(str.begin(), str.end());
	string *pitem = (string*)bsearch(&target, str.data(), str.size(), sizeof(string), compareStrings);
	cout<<"sort+bsearch = "<<clock()-timeStart<<endl;
	if(pitem != NULL) cout<<"found = "<<*pitem<<endl;
	else cout<<"not found"<<endl;	
}

/***5.list容器测试（双向循环链表）****/
void test5_1() {
	cout << "\ntest_list().......... \n";
    long value = 100000;
	list<string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();							
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));    	
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "list.size()= " << c.size() << endl;
	cout << "list.max_size()= " << c.max_size() << endl;    
	cout << "list.front()= " << c.front() << endl;	
	cout << "list.back()= " << c.back() << endl;		
		
	//查找时间测试
	string target = get_a_target_string();		
    timeStart = clock();		
	auto pItem = find(c.begin(), c.end(), target);						
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    
	//排序时间测试
    timeStart = clock();		
	c.sort();						
	cout << "c.sort(), milli-seconds : " << (clock()-timeStart) << endl;		    	
	c.clear();								
}

/******6.forward_list（单向链表）******/

void test6_1() {
     long value = 100000;
	forward_list<string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_front(string(buf));  			   		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "forward_list.max_size()= " << c.max_size() << endl;  //536870911
	cout << "forward_list.front()= " << c.front() << endl;	

	//查找时间测试
	string target = get_a_target_string();	
    timeStart = clock();			
	auto pItem = find(c.begin(), c.end(), target);	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    
	//排序时间测试
    timeStart = clock();		
	c.sort();						
	cout << "c.sort(), milli-seconds : " << (clock()-timeStart) << endl;		
	c.clear();	 
}

/***7.队容器deque***/
/*
按照缓存增加空间，空间不够时，头或者尾指针指向一片新的缓存空间
*/
void test7_1(){
	cout << "\ntest_deque().......... \n";
    long value = 100000;
	deque<string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "deque.size()= " << c.size() << endl;
	cout << "deque.front()= " << c.front() << endl;	
	cout << "deque.back()= " << c.back() << endl;	
	cout << "deque.max_size()= " << c.max_size() << endl;	//1073741821	
	
	string target = get_a_target_string();	
    timeStart = clock();			
	auto pItem = find(c.begin(), c.end(), target);	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;	
	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	sort(c.begin(), c.end());						
	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl;		
	
	c.clear(); 						
}					

/***8.multiset***/
/*
底层：红黑树，可以添加重复的元素
*/
void test8_1() {
	cout << "\ntest_multiset().......... \n";
	long value = 100000;
	multiset<string> c;  	
	char buf[10];		
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));     				
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "multiset.size()= " << c.size() << endl;	
	cout << "multiset.max_size()= " << c.max_size() << endl;	//214748364
	
	string target = get_a_target_string();	
	{
    timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 	
 	{
    timeStart = clock();		
	auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}	
	 
	c.clear(); 						
}	

/****9.multimap***/
/*
存在键值对，通过键来寻找值
而set的值就是键
*/
void test9_1()
{
	cout << "\ntest_multimap().......... \n";
    long value = 1000000;
	multimap<long, string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
    		//multimap 不可使用 [] 做 insertion 
        	c.insert(pair<long,string>(i,buf));   						
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "multimap.size()= " << c.size() << endl;
	cout << "multimap.max_size()= " << c.max_size() << endl;	//178956970	
	
	long target = get_a_target_long();		
    timeStart = clock();		
	auto pItem = c.find(target);								
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;	 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;	  	
	c.clear();		  					
}				

/***10.unordered_multiset****/
/*

*/
void test10_1()
{
	cout << "\ntest_unordered_multiset().......... \n";
    long value = 100000;
	unordered_multiset<string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));   			  		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_multiset.size()= " << c.size() << endl;
	cout << "unordered_multiset.max_size()= " << c.max_size() << endl;	//357913941
	cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << endl;	
	cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;	
	cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;	
	cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << endl;				
  	for (unsigned i=0; i< 20; ++i) {
    	cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
  	}					
				
	string target = get_a_target_string();	
	{
    timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 
 	{
    timeStart = clock();		
	auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;	 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}		
    c.clear();		 	 							
}							

/***11.unordered_multimap**/
void test11_1()
{
	cout << "\ntest_unordered_multimap().......... \n";
    long value = 100000;
	unordered_multimap<long, string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
			//multimap 不可使用 [] 進行 insertion 
			c.insert(pair<long,string>(i,buf));
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_multimap.size()= " << c.size() << endl;	
	cout << "unordered_multimap.max_size()= " << c.max_size() << endl;	//357913941	
	
	long target = get_a_target_long();		
    timeStart = clock();		
	auto pItem = c.find(target);								
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;		
}	

/***12.set***/
void test12_1()
{
	cout << "\ntest_set().......... \n";
    long value = 100000;
	set<string> c;  	
	char buf[10];

	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));     					
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "set.size()= " << c.size() << endl;
	cout << "set.max_size()= " << c.max_size() << endl;	   //214748364
		
	string target = get_a_target_string();	
	{
    timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 	
 	{
    timeStart = clock();		
	auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}							
}				

/***13.map**/
void test13_1()
{
	cout << "\ntest_map().......... \n";
    long value = 100000;
	map<long, string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
			c[i] = string(buf);  					
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "map.size()= " << c.size() << endl;	
	cout << "map.max_size()= " << c.max_size() << endl;		//178956970
	
	long target = get_a_target_long();		
    timeStart = clock();		
	auto pItem = c.find(target);								
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;				
    c.clear();					
}							

/***14.unordered_set**/
void test14_1()
{
	cout << "\ntest_unordered_set().......... \n";
    long value = 100000;
	unordered_set<string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_set.size()= " << c.size() << endl;	
	cout << "unordered_set.max_size()= " << c.max_size() << endl;  //357913941
	cout << "unordered_set.bucket_count()= " << c.bucket_count() << endl;	
	cout << "unordered_set.load_factor()= " << c.load_factor() << endl;	
	cout << "unordered_set.max_load_factor()= " << c.max_load_factor() << endl;	
	cout << "unordered_set.max_bucket_count()= " << c.max_bucket_count() << endl;			
  	for (unsigned i=0; i< 20; ++i) {
    	cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
  	}			
	
	string target = get_a_target_string();	
	{
    timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 
 	{
    timeStart = clock();		
	auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}	
}	

/***15.unordered_map***/
void test15_1()
{
	cout << "\ntest_unordered_map().......... \n";
	long value = 10000;
	unordered_map<long, string> c;  	
	char buf[10];
			
	clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
			c[i] = string(buf);  		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_map.size()= " << c.size() << endl;	//357913941
	cout << "unordered_map.max_size()= " << c.max_size() << endl;	
	
	long target = get_a_target_long();		
    timeStart = clock();	
	//! auto pItem = find(c.begin(), c.end(), target);	//map 不適用 std::find() 			
	auto pItem = c.find(target);
						
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;		
}		




int main()
{
	test15_1();
	return 0;
}