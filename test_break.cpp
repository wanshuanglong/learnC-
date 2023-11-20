#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 5) {
                cout << "循环被break中止时，i = " << i << "; " << "循环被break中止时，j = " << j << endl;
                break; // 内层循环被中断，外层循环继续
            }
        }
    }
}
/*在这个例子中，原本内层循环的执行次数为10次，
而外层循环的执行次数是5次。
但是当内层循环的变量j等于5时，break语句被执行，内层循环被中断，但外层循环会继续
*/
