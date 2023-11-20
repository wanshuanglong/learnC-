#include<iostream> 
using namespace std;

//变量声明
extern int a, b;
extern int c;
extern float f;

int main()
{
    //变量定义
    int a, b;
    int c;
    float f;
    char k;

    //变量初始化
    a = 98;
    b = 20;
    c = a+b;
    cout << c << endl;
    
    k = a;
    cout << "k = " << k << endl;

   f = 70.0/3.0;
   cout << f << endl;

   return 0;


}