#include <iostream>
using namespace std;
using std::cout;

// 第一个命名空间
namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}
// 第二个命名空间
namespace second_space {
    void func() {
        cout << "Inside second_space" << endl;
    }
}

//3.嵌套命名空间
// 第一个命名空间
namespace first_space1 {
    void func() {
        cout << "Inside first_space" << endl;
    }
    // 第二个命名空间
    namespace second_space1 {
        void func1() {
            cout << "Inside second_space" << endl;
        }
    }
}
using namespace first_space1::second_space1;
//2.使用using
using namespace first_space;
int main()
{
    // 调用第一个命名空间中的函数
    first_space::func();
    // 调用第二个命名空间中的函数
    second_space::func();

    cout << "std::endl is used with std!" << std::endl;
    func();
    func1();
  
    return 0;
}