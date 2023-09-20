#ifndef __MYSTRING__
#define __MYSTRING__
#include<iostream>
#include<cstring>

/*
1.类中有指针，要进行动态分配，且要有拷贝构造和拷贝赋值
2.结束后要删除
*/



class String {
public: 
    String(const char* cstr = 0); 
    String(const String& str);   //拷贝构造，拷贝自己的类型
    String& operator=(const String& str);  //拷贝赋值
    ~String();
    char* get_c_str() const { return m_data; } 
private: 
    char* m_data; 
}; 

inline String::String(const char* cstr) {
    if(cstr){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else{
        m_data = new char[1];
        m_data[1] = '\0';
    }
}
inline String::~String(){
    delete [] m_data;
}

inline String::String(const String& str) {
    m_data = new char[strlen(str.m_data) + 1]; //创建空间，再拷贝内容（深拷贝）
    strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str) {
    if(this == &str){  //检测是否是自我赋值
        return *this;
    }
    delete [] m_data;  //拷贝赋值
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data, str.m_data);
    return *this;
}

using namespace std;
ostream& operator<<(ostream& os, const String& str) {
    os << str.get_c_str();
    return os;
}


#endif