/*

编写一个程序，实现二分查找算法。要求如下：

    定义一个整型数组，包含n个元素；
    定义一个指向整型的指针变量，指向数组的第一个元素；
    定义一个整型变量表示查找的目标值；
    使用循环遍历数组，比较指针变量所指向的元素与目标值的大小关系，
    如果相等则返回指针变量所指向的元素的下标，
    否则根据大小关系调整指针变量和目标值的范围；
    如果指针变量所指向的元素下标小于0或大于等于数组长度，则说明查找失败，返回-1；
    输出查找结果。

二分查找是一种高效的查找算法，适用于有序数组。
其基本思想是每次比较中间元素与目标值的大小关系，
根据比较结果缩小查找范围，直到找到目标值或查找范围为空为止。

*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int binarySearch(int arr[], int left, int right, int target);
const int NSIZE = 200; // 定义数组大小

int main() {
    // 首先生成一个含有N个元素的整形数组
    //srand(time(0));
    int arr[NSIZE]; 
    for (int i=0; i < NSIZE; ++i) {
        arr[i] = i; // 初始化数组，放入1～100之间的随机数
        //cout << arr[i] << endl;
    }
    int *p = arr; // 定义一个指向整型的指针变量，指向数组的第一个元素；
    int SEARCH_NUM = 91; // 定义一个整型变量表示查找的目标值；
    // 二分查找
    int left = p[0]; int right = p[NSIZE-1];
    int index_n = binarySearch (p,left,right, SEARCH_NUM); 
    //用指针来为函数传递数组参数，可以减少拷贝，从而节约资源
    
    if (index_n == -1) { 
        cout << " 数组中没有 " << SEARCH_NUM << endl;
    } else {
        cout << "arr[" << index_n << "] = " << SEARCH_NUM<< endl;
    }
    
    /*
    int flag = 0; // 标示符
    while (left <= right ) {
        int n = left + (right -left)/2; //取arr中间值
        if (p[n] == SEARCH_NUM) {
            cout << "arr[" << n << "] = " << SEARCH_NUM<< endl;
            ++flag;
            break;
        } else if ( p[n] < SEARCH_NUM) { // 目标值在右边
            left = p[n] + 1; 
        } else if ( p[n] > SEARCH_NUM) { // 目标值在左边 
            right = p[n] - 1;
        }
    }
    if (flag == 0) { //如果查找失败，输出-1
        cout << -1 << endl;
    }*/
    return 0;
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // 取中间位置
        if (arr[mid] == target) { // 找到目标值
            return mid;
        } else if (arr[mid] < target) { // 目标值在右半部分
            left = mid + 1;
        } else { // 目标值在左半部分
            right = mid - 1;
        }
    }
    return -1; // 没有找到目标值
}