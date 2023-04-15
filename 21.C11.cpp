/*
c++新特性
*/

#include<iostream>
using namespace std;


/***1.数量不定的模板参数***/
/*
...就是pack包
1.用于模板参数时，就是模板参数包
2.用于函数参数类型时，就是函数参数类型包
3.用于函数参数时，就是函数参数包
4.查看参数个数,sizeof...(args)
*/
void print(){}  //重载print

template<typename T, typename... Types>
void print(const T &firstArg, const Types &... args){
    cout<<firstArg<<endl;
    sizeof...(args);
    print(args...);
}

void test1(){
    print(3,5,"hello",43);
}


/****2.nullptr测试***/
void f(int key){
    cout<<key<<endl;
}
void f(void* key){
    cout<<key<<endl;
}
void test2(){
    f(0);
    f(NULL);  //歧义，NULL本来就是0
    f(nullptr);
}
//NULL的值就是0
void test3(){
    int *ptr = NULL;
    cout<<ptr<<endl;
}





int main(){
    test2();
    return 0;
}