// 命名空间
#include <iostream>
using namespace std;

namespace first_space {
    void func()
    {
        cout << "Inside the first namespace." << endl;
    }
}
namespace second_space{
    void func()
    {
        cout << "Inside the second namespace." << endl;
    }
}
using namespace first_space; // 使用using指令，指定接下来使用的命名空间
int main()
{
    //first_space::func();
    func();
    second_space::func();

    return 0;
}