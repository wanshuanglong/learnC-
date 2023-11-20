#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using std::setw;
using namespace std;

int RandomPositiveNum (); // 随机数函数声明
bool JPrimeNumber(int nparameters); // 判断一个整数是否为素数的函数
void printArray(int arr[],int size); //输出一维数组各元素的函数

int main() {
    int n = RandomPositiveNum (); //将随机产生的一个正整数赋值给n
    cout << "随机生成的正整数为：" << n << endl;
    bool an = JPrimeNumber(n); // 将判断素数语句包装成一个函数，方便调用 
    if (an == 1){
        printf("%d 为素数", n);
    }
    // 筛选出2到100中的素数
    int narray[99];
    for (int i = 2; i < 101; ++i){
        int j = i-2;
        narray[j] = i;
    }
    //int size = sizeof(narray) / sizeof(narray[0]);
    //printArray(narray, size); 
    //cout << "size = " << size << endl;
    //cout << "sizeof(narray[0]) = " << sizeof(narray[0]) << endl;

    bool TorF[99]; 
    for (int i = 0; i < 99; ++i){
        TorF[i] = JPrimeNumber(narray[i]);
        //cout << TorF[i] <<" ";
    }
    cout << "整数" << setw( 13 ) << "TrueOrFalse" << endl;
    for ( int i = 0; i < 99; ++i)
    {
      cout << setw( 3 )<< narray[i] << setw( 7 ) << TorF[i] << endl;
    }
    //printArray((int *)TorF);
    return 0;
}

// 将判断一个整数是否为素数的程序包成函数
bool JPrimeNumber(int nparameters){
    int flag = 0; //计数器
    for (int i = 2; i <= sqrt(nparameters); ++i){
        /*从2开始，到这个数的平方根结束，看这个数能否被其中的任一整数整除，如果不能，则这个数是素数。*/
        if (nparameters%i == 0){
            ++flag; //计数
        }
    }
    bool JP = 0; //布尔变量，记录是素数与否 
    if (flag == 0 ){
        JP = 1;
    }
    return JP;

}
// 随机生成一个正整数的函数
int RandomPositiveNum (){
    int positiveNum;
    do {
        //int positiveNum;
        // 设置随机数种子
        srand(time(0)); // time(0)函数获取当前时间作为随机数种子

        // 生成一个[0, RAND_MAX]范围内的随机数
        int randomNum = rand();

        // 将随机数转换为正整数
        positiveNum = randomNum > 0 ? randomNum : -randomNum;
    } while (positiveNum == 1); //若随机生成的正整数为1,则重新生成

    //cout << "随机生成的正整数为：" << positiveNum << endl;
    return positiveNum;
}
// 输出一维数组各元素
void printArray(int arr[], int size) {
    //int size = sizeof(arr) / sizeof(arr[0]); 
    /*获取数组长度,sizeof(myArray)将返回整个数组的字节数，
    而sizeof(myArray[0])将返回数组中第一个元素的字节数。
    通过将两者相除，就可以得到数组的长度。*/
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}