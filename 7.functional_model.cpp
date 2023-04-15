#include<iostream>
#include<time.h>
#include<string.h>
using namespace std;


/*
1.函数
2.函数的参数传递
3.数组形参
4.函数指针
*/

//函数声明
int max(int num1, int num2);
//int sum(int a, int e = 100);
void swap(int x, int y);
void swap_index(int* x, int* y);
void swap_ying(int& x, int& y);


//1.函数
void func()
{
		//1.函数定义
	int c;
	c = max(3, 6);
	cout << c << endl;

	//2.函数默认参数
	//int number = 100;
	//int d = sum(number);
	//cout << d << endl;

	//3.传值参数
	// 局部变量声明
	int a = 100;
	int b = 200;
	cout <<"begin swap,a's value:" << a << endl;
	cout <<"begin swap,b's value" << b << endl;
	// 调用函数来交换值
	swap(a, b);
	cout <<"after swap,a's value" << a << endl;
	cout <<"after swap,b's value:" << b << endl;

	//4.指针传参数
	cout <<"begin swap,a's value:" << a << endl;
	cout <<"begin swap,b's value:" << b << endl;
	/* 调用函数来交换值
	 * &a 表示指向 a 的指针，即变量 a 的地址
	 * &b 表示指向 b 的指针，即变量 b 的地址
	 */
	swap_index(&a, &b);
	cout << "after swap,a's value:" << a << endl;
	cout << "after swap,b's value:" << b << endl;

	//5.引用传参
	cout << "begin swap,a's value" << a << endl;
	cout << "begin swap,b's value" << b << endl;
	/* 调用函数来交换值 */
	swap_ying(a, b);
	cout << "after swap,a's value" << a << endl;
	cout << "after swap,b's value" << b << endl;
}

//2.传引用参数
/*引用传参，其形参和实参会被绑定在一块，修改形参则会修改实参*/
void func1(int &a,int &b)
{
	cout<<a+b<<endl;
	a=a+109;
	cout<<a<<endl;
}
void reference_code()
{
	int i=10,j=100;
	func1(i,j);
	cout<<i<<endl;
}

//使用引用形参返回额外的信息
string::size_type find_char(const string &chr,char c,string::size_type &occurs)
{
	auto ret=chr.size();
	occurs=0;
	for(decltype(ret) i=0;i!=chr.size();++i)
	{
		if(chr[i]==c)
		{
			if(ret==chr.size()) 
				ret=i;
			++occurs;
		}
	}
	return ret;
}
void func4()
{
	string strm("hiaehgaheghaheaihaiufhaubeyauigafhauegiahfei");
	cout<<strm.size()<<endl;
	char ch;
	string::size_type cls;
	cin>>ch;
	cout<<find_char(strm,ch,cls)<<endl;;
}

//practice6.2.3
//practice6_17
//判断字符串中是否含有大写字母
void func6_17(string str)
{
	for(auto strl:str)
	{
		if(isupper(strl))
		{
			cout<<"have a Capital letters"<<endl;
			break;
		}
	}
}
//将字符串中存在的大写字母改成小写
void fun6_17(string str)
{
	for(auto &strl:str)
	{
		if(isupper(strl))
		{
			strl=tolower(strl);
		}
	}
	cout<<str<<endl;
}
void practice6_17()
{
	string str("hfaEEAGhaoShieJweuaifHae");
	fun6_17(str);
}


//3.传递数组形参
void array_parameter(int arr[],int n) //传递的是数组的首地址，数组不可以被拷贝
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	cout<<sum<<endl;
}
void array_ex()
{
	int seed=time(0);
	srand(seed);
	int num;
	cin>>num;
	int arr[num];
	for(int i=0;i<num;i++)
	{
		arr[i]=i*rand()%99;
	}
	array_parameter(arr,num);
}

//传递多维数组
void func_array(int arr[][10],int num) //传递一个元素是一维数组（长度是10）的数组的首地址
{
	int sum=0;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<10;j++)
		{
			sum+=arr[i][j];
		}
	}
	cout<<sum<<endl;
}
void array_point(int (*arr)[10],int num) //传递二维数组的首地址
{
	int sum=0;
	for(int j=0;j<num;arr++,j++)
	{
		for(int i=0;i<10;i++)
		{
	    	sum+=(*arr)[i];
		}
	}
	cout<<sum<<endl;
}
void multi_array()
{
	int seed = time(0);
	srand(seed);
	int num1;
	int num2=10;
	cin>>num1;
	int arr[num1][10];  //当将10换成num2是error，此时就相当于将num2拷贝给arr[][10]
	for(int i=0;i<num1;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[i][j]=j+rand()%79;
		}
	}
	array_point(arr,num1);
}





//4.函数指针
//4.1使用函数指针
int sum_two(int a,int b)
{
	return a+b;
}
/*获取函数指针，就是函数名*/
void func4_1()
{
	int (*plt)(int a,int b); //创建一个和函数相同类型的指针
	plt=sum_two;
	cout<<(*plt)(10,11)<<endl; //使用指针去调用函数
}

//4.2将函数作为参数，采用函数指针的方式
int sum_three(int (*plt1)(int a,int b),int (*plt2)(int c,int d))
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	return (*plt1)(a,b)+(*plt2)(c,d);
}
void func4_2()
{
	int (*plt)(int a,int b);
	plt=sum_two;
	cout<<sum_three(sum_two,sum_two)<<endl;
}

// 4_3将多个类型相同的函数放在一个数组内，然后用一个指针表示，可以通过该指针来调用该函数，然后再用typedef来简化书写


// 5.指针函数
int *sum1(int a,int b){
	int c=a+b;
	int *p=&c;
	return p;
}
void test5(){
	int *p=NULL;
	p=sum1(1,3);
	cout<<p<<endl;
}


int main()
{
	test5();
	return 0;
}







//1.函数定义
int max(int num1, int num2)
{
	int result;
	if (num1 > num2)
		result = num1;
	else
		result = num2;
	return result;
}
//2.默认参数
int sum(int a, int e = 100)
{
	int result;
	result = a + e;
	return (result);
}
//3.传值参数
void swap(int x, int y)
{
	int temp;
	temp = x; /* 保存 x 的值 */
	x = y;    /* 把 y 赋值给 x */
	y = temp; /* 把 x 赋值给 y */
	return;
}

//4.指针调用
void swap_index(int* x, int* y)
{
	int temp;
	temp = *x;	/* 保存地址 x 的值 */
	*x = *y;		/* 把 y 赋值给 x */
	*y = temp;	/* 把 x 赋值给 y */

	return;
}

//5.引用调用
/*
向函数传递参数的引用调用方法，把参数的地址复制给形式参数。
在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修
改形式参数会影响实际参数。
*/
void swap_ying(int& x, int& y)
{
	int temp;
	temp = x; /* 保存地址 x 的值 */
	x = y;    /* 把 y 赋值给 x */
	y = temp; /* 把 x 赋值给 y  */

	return;
}