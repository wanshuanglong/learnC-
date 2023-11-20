#include <iostream>
using namespace std;
// 如何访问int a 前面的那一个字节 
int main(){
    int a = 10;
    char *p = (char *) &a; // &a 是 int * 类型，如果直接将其赋值给指针p, --p 将指向a 前面的第4个字节
    --p;
    printf("%c", *p); //可能导致运行错误
    *p = 'A'; //可能导致运行错误
    return 0;
}
