// 动态内存 - 多维数组
#include <iostream>
#include <ctime>
using namespace std;

int main ()
{
    srand(time(0));
    // 一维数组///////////////////////////////////
    int m = 8; // 行数
    int *arr1 = new int [m]; // new data-type; //使用 new 运算符来为任意的数据类型动态分配内存的通用语法
    for (int i = 0; i < m; ++i)
    {
        arr1[i] = rand() % 100 + 1; // 为arr1各元素赋0～100间的随机数
        cout << arr1[i] << endl;
    }
    delete [] arr1; // 释放内存
    //////////////////////////////////////////////
    // 二维数组
    int n = 4; // 列数
    int **arr2;
    arr2 = new int *[m]; // 先分配行内存
    for (int i = 0; i < m; ++i)
    {
        arr2[i] = new int[n]; // 再分配列内存
    }
    // 为矩阵元素赋值
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            arr2[i][j] = rand() % 100 + 1;
            if (j == 0) cout << endl; //保证矩阵输出形状
            cout << arr2[i][j] << "\t"; // "\t" 为制表符
        }
    }
    // 释放内存
    for (int i = 0; i < m; ++i)
    {
        delete [] arr2[i];
    }
    delete [] arr2;
    return 0;
}