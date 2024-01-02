/*

编写一个程序，实现冒泡排序算法。要求如下：

    定义一个整型数组，包含n个元素；
    定义一个指向整型的指针变量，指向数组的第一个元素；
    使用循环遍历数组，比较相邻的两个元素的大小，如果前一个元素大于后一个元素，则交换它们的位置，并使用指针变量进行操作；
    重复上述步骤，直到整个数组有序；
    输出排序后的数组。

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
using std::setw;

//void convertSequence( int p1, int p2); //交换两个变量的位置
const int NSIZE = 100; // 定义数组大小

int main() {
    // 首先生成一个含有N个元素的整形数组
    srand(time(0));
    int arr[NSIZE]; // 原数组
    int sorted_arr[NSIZE]; //排序后数组  
    for (int i=0; i < NSIZE; ++i) {
        arr[i] = rand() % 100 ; // 初始化数组，放入0～99之间的随机数
        //cout << arr[i] << endl;
        sorted_arr[i] = arr[i]; //初始化排序后数组
    }
    //sorted_arr = arr; //在C++里是不行的
    int *p1 = sorted_arr; int *p2 = sorted_arr;
    for (int i=0; i < NSIZE; ++i) {
        //p1 = sorted_arr + i; // 令p1 指向 sorted_arr[i]
        for (int j=i+1; j < NSIZE; ++j) {
            p2 = sorted_arr + j; // 令p2 指向 sorted_arr[j]
            //p2++;
            // 方法一
            if (*p1 > *p2) {
                int temp = *p1; // p1指向的变量的值赋值给temp
                *p1 = *p2;      // p2指向的变量的值赋给p1指向的变量
                *p2 = temp;
            }
            // 方法二
            /*if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }*/
            // 方法三
            /*if (*(p1+i) > *(p2+j)) {
                //*p1 = arr[i]; //令p1指向arr[i]
                //*p2 = arr[j]; //令p2指向arr[j]
                int temp = *(p1+i);
                *(p1+i) = *(p2+j);
                *(p2+j) = temp;
                //convertSequence(*(p1+i), *(p2+j)); //交换位置s
            }*/
        }
        p1++; // 与p1 = sorted_arr + i;语句效果相同
    }
    cout << "排序前" << setw( 13 ) << "排序后" << endl;
    for (int i=0; i < NSIZE; ++i) {
        cout << setw( 3 )<< arr[i] << setw( 7 ) << sorted_arr[i] << endl;
        //cout << "排序后" << arr[i] << endl;
    }
}
/*
// 交换数列中两个元素的位置
void convertSequence( int p1, int p2) {
    int temp = p1; // p1指向的变量的值赋值给temp
    p1 = p2; // p2指向的变量的值赋给p1指向的变量
    p2 = temp;
}*/