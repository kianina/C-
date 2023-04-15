#include<iostream>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<vector>
using namespace std;

void test1()
{
    int m[]={1,2,3,4,5,6,7,8,9,0};
    int(*p)[4]=(int(*)[4])m;
    cout<<p[1][2]<<endl;
}

void test2()
{
    int f1(float a);
    int f2(char a);
    int f3(float a);
    int f4(float a);
    int (*pf)(float a);
    if(pf==f3)
    {   
        cout<<"true"<<endl;      
    }  //正确，函数名称相当于函数的首地址

}

//3.字符串函数
//把信息输出到字符串，保证字符串足够大 
void test3()
{
    char a[20]; 
    memset(a,0,sizeof(a)); 
    sprintf(a,"%d%d%d%d",4,5,6,7); 
    for(int i=0;i<sizeof(a);i++)
    {
        printf("%d ",a[i]);
    }
}



//单例模式
class SingleExample {
public:
    static SingleExample& create() {
        return example;
    }
private:
    SingleExample() {
        std::cout << "正在构造..." << std::endl;
    }
    ~SingleExample() {
        std::cout << "正在析构..." << std::endl;
    }
    SingleExample(const SingleExample&) = delete;
    const SingleExample& operator=(const SingleExample&) = delete;
    static SingleExample example;
};

SingleExample SingleExample::example;


//开闭原则
enum class COLOR { RED, GREEN, BLUE };
enum class SIZE { SMALL, MEDIUM, LARGE };
struct Product {
    string  m_name;
    COLOR   m_color;
    SIZE    m_size;
};
using Items = vector<Product*>;
template <typename T>
struct Specification {
    virtual ~Specification() = default;
    virtual bool is_satisfied(T *item) const = 0;
};
struct ColorSpecification : Specification<Product> {
    COLOR e_color;
    ColorSpecification(COLOR e_color) : e_color(e_color) {}
    bool is_satisfied(Product *item) const { return item->m_color == e_color; }
};

struct SizeSpecification : Specification<Product> {
    SIZE e_size;
    SizeSpecification(SIZE e_size) : e_size(e_size) {}
    bool is_satisfied(Product *item) const { return item->m_size == e_size; }
};


template <typename T>
struct Filter {
    virtual vector<T *> filter(vector<T *> items, const Specification<T> &spec) = 0;
};
struct BetterFilter : Filter<Product> {
    vector<Product *> filter(vector<Product *> items, const Specification<Product> &spec) {
        vector<Product *> result;
        for (auto &p : items)
            if (spec.is_satisfied(p))
                result.push_back(p);
        return result;
    }
};

int main() {
    BetterFilter bf;
    const Items all{
        new Product{"Apple", COLOR::GREEN, SIZE::SMALL},
        new Product{"Tree", COLOR::GREEN, SIZE::LARGE},
        new Product{"House", COLOR::BLUE, SIZE::LARGE},
    };
    for (auto &x : bf.filter(all, ColorSpecification(COLOR::GREEN)))
    cout << x->m_name << " is green\n";
}
