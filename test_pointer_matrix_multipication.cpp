/*

编写一个程序，实现两个矩阵的相乘。要求如下：

    定义两个3x3的整型矩阵；
    定义两个指向整型的指针变量，分别指向两个矩阵的第一行；
    使用循环遍历矩阵，将两个矩阵对应位置的元素相乘，并将结果存储在另一个3x3的矩阵中；
    输出相乘后的矩阵。


*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    //int n = RandomPositiveNum();
    srand(time(0));
    int arr1 [3][3];
    int arr2 [3][3];
    int arr3 [3][3];
    int *p1 = arr1[0]; //定义两个指向整型的指针变量，分别指向两个矩阵的第一行；
    int *p2 = arr2[0];
    for (int i=0; i<3; ++i){ //定义两个3x3的整型矩阵；
        p1 = arr1[i]; //指针指向二维数组第i行
        p2 = arr2[i];
        for (int j=0; j<3; ++j){
            arr1[i][j] = rand() % 100 + 1;
            arr2[i][j] = rand() % 100 + 1;
            arr3[i][j] = p1[j] * p2[j]; // 利用指针访问各列元素
            cout << "arr1[" << i << "][" << j << "] = " << arr1[i][j] << endl;
            cout << "arr2[" << i << "][" << j << "] = " << arr2[i][j] << endl;
            cout << "arr3[" << i << "][" << j << "] = " << arr3[i][j] << endl;
        }
    }
}
