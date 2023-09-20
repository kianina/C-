#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
    priority_queue<Type, Container, Functional>
    使用基本数据类型时，只需要传入数据类型，默认是大顶堆
    priority_queue<int, vector<int>, greater<int>> upq;
    priority_queue<int, vector<int>, less<int>> downq;
*/
void test1(){
    
    //对于基础类型 默认是大顶堆
    priority_queue<int> a; 
    //等同于 priority_queue<int, vector<int>, less<int> > a;
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;

    for (int i = 0; i < 5; i++) 
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty()) 
    {
        cout << a.top() << ' ';
        a.pop();
    } 
    cout << endl;

    while (!c.empty()) 
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty()) 
    {
        cout << b.top() << ' ';
        b.pop();
    } 
    cout << endl;
}


int main(){
    test1();
    return 0;
}