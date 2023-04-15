#include<iostream>
using namespace std;


class person
{
public:
	person(int a, int b, int c) :A(a), B(b), C(c)
	{

	}
	int A, B, C;
};
void test() {
	person p(12, 15, 66);
	cout << p.A<< p.B<< p.C << endl;
}
int main() {
	test();
	return 0;
}