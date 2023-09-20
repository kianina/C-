#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

// 1.返回多个值的操作
typedef struct lenghtij{
    int lengthi;
    int lengthj;
} lenghtij;

// pair可以返回两个返回值
class getTwo {
public:
    lenghtij getTwos();
};

lenghtij getTwo::getTwos(){
    lenghtij len;
    len.lengthi = 10;
    len.lengthj = 12;
    return len;
}

void test0(){
    getTwo *gets = new getTwo();
    lenghtij lg =  gets->getTwos();
    cout<<lg.lengthi<<" "<<lg.lengthj<<endl;
}

// 将容器作为返回值
vector<int>* getVector(){
    vector<int> v{1, 3, 5};
    vector<int> *k = &v;
    cout<<k<<endl;
    cout<<k->at(1)<<endl;
    return k;
}

// tuple返回多个返回值
tuple<vector<int>*, int, int> getName(){
    tuple<vector<int>*, int, int> result;
    vector<int> v{1,3,4};
    vector<int> *k = &v;
    int a = 10;
    int b = 12;
    result = std::make_tuple(k, a, b);
    return result;
} 
void test1(){
    tuple<vector<int>*, int, int> result;
    result = getName();
    cout<<get<0>(result)<<endl;
    cout<<get<1>(result)<<endl;
    cout<<get<2>(result)<<endl;
    // vector<int> *c = get<0>(result);
}



// 2.字符串指针操作
// void sumStwo(string *s1, string s2){
//     for(int i = 0; i<s1.size(); i++){

//     }
// }
string sums(string s1){
    return s1;
}
void test2(){
    string s1 = "gahigia";
    cout<<sums(s1)<<endl;
}


int main(){
    test2();
    return 0;
}