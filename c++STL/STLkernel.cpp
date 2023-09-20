/***算法****/

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;



/*1.unordered_multiset测试*/
//访问multiset的多个元素
void test1(){
    vector<int> arr = {3, 6, 3, 6, 3};
    unordered_multiset<int> mulset;
    for(auto a : arr){
        mulset.insert(a);
    }
    auto iter = mulset.find(3);
    cout<<mulset.count(*iter)<<endl;
    cout<<(*(++iter))<<endl;
    cout<<(*(++iter))<<endl;
    int count = 0;
}





int main() {
    test1();
    return 0;
}