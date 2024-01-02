#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var is: " << var << endl;
 
   // 输出在指针变量中存储的地址
   cout << "Address stored in ip is: " << ip << endl;
 
   // 访问指针中地址的值
   cout << "Value of *ip is: " << *ip << endl;
 
   return 0;
}