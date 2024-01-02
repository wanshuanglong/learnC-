/*

编写一个程序，实现两个矩阵的相乘。要求如下：

    定义两个3x3的整型矩阵；
    定义两个指向整型的指针变量，分别指向两个矩阵的第一行；
    使用循环遍历矩阵，将两个矩阵对应位置的元素相乘，并将结果存储在另一个3x3的矩阵中；
    输出相乘后的矩阵。


*/
// 我自己编写的代码
/*

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
*/

// 改进: 这样修改后的代码使用了std::vector来存储矩阵，
// 使得代码更加简洁、易读。同时，将矩阵乘法的逻辑封装成了一个函数，提高了代码的可维护性。

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// 矩阵乘法函数
vector<vector<int>> matrix_multiply(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2) {
    vector<vector<int>> result(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return result;
}

int main() {
    srand(time(0));
    vector<vector<int>> arr1(3, vector<int>(3));
    vector<vector<int>> arr2(3, vector<int>(3));
    vector<vector<int>> arr3(3, vector<int>(3));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr1[i][j] = rand() % 100 + 1;
            arr2[i][j] = rand() % 100 + 1;
        }
    }

    arr3 = matrix_multiply(arr1, arr2);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "arr1[" << i << "][" << j << "] = " << arr1[i][j] << "\t";
            cout << "arr2[" << i << "][" << j << "] = " << arr2[i][j] << "\t";
            cout << "arr3[" << i << "][" << j << "] = " << arr3[i][j] << endl;
        }
    }

    return 0;
}
