#include<iostream>
#include "string.h"
using namespace std;


int main(){
    String s1("hello");
    String s2("world");
    String s3(s1);
    cout << s3 << endl; 
    s3 = s2;
    cout << s3 << endl;
}