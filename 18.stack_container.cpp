#include<iostream>
#include<stack>
using namespace std;
void test1()
{
	stack<int>s;
	s.push(12);
	s.push(13);
	s.push(14);
	s.push(15);
	cout << s.size() << endl;
	while (!s.empty()) {
		s.pop();
	}
	cout << s.size() << endl;
}
int main() {
	test1();
	system("pause");
	return 0;
}