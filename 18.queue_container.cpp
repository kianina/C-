#include<iostream>
#include<queue>
using namespace std;
class person
{
public:
	person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void test2()
{
	queue<person>q;
	person p1("1223", 121);
	person p2("1243", 151);
	person p3("1253", 111);
	person p4("1263", 161);
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << q.size() << endl;
	while (!q.empty()) {
		cout << q.front().name << " " << q.front().age << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

int main()
{
	test2();
	system("pause");
	return 0;
}