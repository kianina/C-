#include<iostream>
using namespace std;

class Base
{
    public:
        virtual void v_func(){
            cout<<"this is Base virtual function"<<endl;
        }
        void func(){
            cout<<"this is Base func"<<endl;
        }
};
class A:public Base
{
    public:
        virtual void v_func(){
            cout<<"this is A virtual function"<<endl;
        }
        void funcA(){
            cout<<"this is A func"<<endl;
        }   
};
class B:public Base
{
    public:
        virtual void v_func(){
            cout<<"this is B virtual function"<<endl;
        }
        void funcB(){
            cout<<"this is B func"<<endl;
        }   
};

int main()
{
    Base *base = new(Base);
    A *a = new(A);
    B *b = new(B);
    base->func(),a->func(),b->func();
    base->v_func(),a->v_func(),b->v_func();
}