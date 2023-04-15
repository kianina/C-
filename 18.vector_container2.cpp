#include<iostream>
using namespace std;
#include<vector>
#include<string>



class person
{
public:
	person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	int age;
	string name;
};
void test() {
	vector<person>p;
	person p1("aa", 1321);
	person p21("aab", 121);
	person p331("aad", 113);
	person p441("aadd", 131);

	p.push_back(p1);
	p.push_back(p21);
	p.push_back(p331);
	p.push_back(p441);
	for (vector<person>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << (*it).name << (*it).age << endl;	
		cout << it->name << it->age << endl;
	}
}


//??????????????vector?
void test1()
{
	vector<person*>p;
	person p1("aa", 1321);
	person p21("aab", 121);
	person p331("aad", 113);
	person p441("aadd", 131);

	p.push_back(&p1);
	p.push_back(&p21);
	p.push_back(&p331);
	p.push_back(&p441);
	for (vector<person*>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << (* *it).name << (**it).age << endl;
		cout << (*it)->name << (*it)->age << endl;
	}
}
int main()
{
	test1();
	system("pause");
	return 0;
}