#include<iostream>
#include<string>
using namespace std;
class building
{
	/*友元访问私有变量*/
	friend void fun(building* build);
public:
	building()
	{
		m_room = "客厅";
		m_bedroom = "卧室";
	}
	void building1();
public:
	string m_room;
	string room;
private:
	string m_bedroom;
	string bedroom;
};

void fun(building* build)
{
	cout << build->m_room << endl;
	cout << build->m_bedroom << endl;
}
void test() {
	building build;
	fun(&build);
}

/*类做友元*/
class goodGay
{
public:
	building* build;

};

/*类外写类内函数*/
void building::building1() {
	room = "客厅1";
	bedroom = "卧室1";
}


int main()
{
	test();
	return 0;
}