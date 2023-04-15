#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//string的构造函数
void test01()
{
	string s1;//默认构造
	const char* str = "hellow world";
	string s2(str);
	cout << "s2：" << s2 << endl;

	string s3(s2);
	cout << "s3" << s3 << endl;
}
//字符串的拼接
void test02()
{
	string str1 = "you";
	str1 += "is paratroopers";
	cout << "str1=" << str1 << endl;

	str1 += '?';
	cout << "str1=" << str1 << endl;

	string str2 = "zbc";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	string str3 = "You";
	str3.append(" SB");
	cout << "str3=" << str3 << endl;

	str3.append("hahaha hahaha", 4);
	cout << "str3=" << str3 << endl;

	str3.append(str2);
	cout << "str3=" << str3 << endl;

	str3.append(str2, 0, 1);
	cout << "str3=" << str3 << endl;
}
//字符串的查找和替换
//查找
void test03()
{
	string str1 = "abcdefg";
	//找到返回下标，找不到返回-1
	int pos1 = str1.find("de");
	cout << "pos1=" << pos1 << endl;
	int pos2 = str1.find("z");
	cout << "pos2=" << pos2 << endl;

	pos1 = str1.rfind("ab");//从右往左
	cout << "pos1=" << pos1 << endl;;
}

void test04()
{
	string str2 = "abcdef";
	str2.replace(1, 3, "1111");//从1号位置起，3个字符替换为1111
	cout << "str2=" << str2 << endl;
}
// 字符串比较
void test05()
{
	string str1 = "zello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)
	{
		cout << "enquity" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 big" << endl;
	}
	else
	{
		cout << "str2 big" << endl;
	}
}
//string字符存取
void test06()
{
	string str1 = "hello";
	//通过[]访问单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;
	//通过at方式访问的单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	str1[0] = 'z';
	cout << str1 << endl;

	str1.at(0) = 'x';
	cout << str1 << endl;
}
//字符串 插入和删除
void test07()
{
	string str = "hello";
	//插入
	str.insert(1, "111");
	cout << "str = " << str << endl;

	//删除
	str.erase(1, 3);
	cout << "str = " << str << endl;
}
//string求字串,拷贝字符串
void test08()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << "subStr=" << subStr << endl;
}
//使用操作
void test09()
{
	string email = "zhangsan@qq.com";
	//从邮箱地址中获取用户名信息
	int pos = email.find("@");
	string usrName = email.substr(0, pos);
	cout << usrName << endl;
}
int main(void)
{
	test08();
	test09();
	system("pause");
	return 0;
}