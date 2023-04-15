#include<iostream>
using namespace std;
/*对象的初始化和清除*/
class person {
	//1.构造函数
public:
	person() {
		cout << "This is the call to the default constructor" << endl;
	}
	person(int a,int m_heigth) {
		age = a;
		height=new int(m_heigth);
		cout << "This is the call to the constructor with arguments 2" << endl;
	}
	/*拷贝构造函数*/
	//person(const person& p) {
	//	age = p.age;
	//	height = p.height;//编译器默认
	//	cout << "拷贝构造函数的调用" << endl;
	//}
	/*解决浅拷贝问题*/
	person(const person& p) {
		cout << "Deep copy function call" << endl;
		age = p.age;
		//深拷贝操作
		height = new int(*p.height);
		
	}
	~person() {
		//释放堆区的内容
		if (height != NULL) {
			delete height;
			height = NULL;
		}
		cout << "This is the default destructor call" << endl;
	}
	int age;
	int* height;
};

/*调用*/
//void test1() {
//	/*默认调用*/
//	person p1;
//	person p2(10);
//	person p21 = person(10);
//	person p22 = 10;
//	person p3(p2);
//	person p31 = person(p2);
//	person p32 = p1;
//	cout << "p2的年龄：" <<p2.age<<endl;
//	person(10);//匿名对象的调用，会被立即释放
//	cout << "aaa" << endl;
//}

/*拷贝构造函数的调用*/
//值传递的方式个函数传参数
void dowork(person p) {

}
void test2() {
	person p;
	dowork(p);
}
//值方式返回局部对象
person dowork1() {
	person p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test3() {
	person p2 = dowork1();
	cout << (int*)&p2 << endl;
}


/*深拷贝与浅拷贝*/
void test4() {
	person p1(18,160);
	cout << "p1 year" << p1.age << "p2 height " << *p1.height << endl;
	cout << (int*)&p1.height << endl;
	person p2(p1);
	cout << "p2 year " << p2.age <<"p2 height "<< *p2.height<<endl;
	cout << (int*)&p2.height << endl;
}
int main() {
	test4();
	return 0;
}