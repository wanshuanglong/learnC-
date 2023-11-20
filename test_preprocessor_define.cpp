// #define 预处理
#include <iostream>
using namespace std;

#define PI 3.1415926
#define MIN(a,b) (a<b? a:b) //带参数的宏

int main()
{
    cout << "pi = " << PI << endl;
    int i = 3;
    int j = 4;
    cout << "min(i,j) = " << MIN(i,j) << endl;

    return 0;
}