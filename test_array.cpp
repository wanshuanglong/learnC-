#include <iostream>
using namespace std;

#define NUM 100 //定义一个符号常量，以便修改
int a[NUM];  //数组一般定义在main()外，尤其是大数组
int main(){
    for (int i = 0; i < NUM; ++i){
        //cin >> a[i];
        a[i] = i;
    }
    for (int i = NUM-1; i >= 0; --i){
        cout << a[i] << ",";
    }
    return 0;
}