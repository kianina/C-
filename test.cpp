// 1.锁复习 
#include<iostream>
#include<string.h>
using namespace std;

void func1(){
    char* text = "GET /heyue_99/article/details/74689057 HTTP/2";
    char* m_url = strpbrk(text, " \t");
    cout<<*m_url<<endl;
    // *m_url  = '\0';
    char    po = *m_url;
    po = '\0';
    cout<<po<<endl;
    cout<<*m_url<<endl;
}

int main(){
    func1();
}