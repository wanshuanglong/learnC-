// 多线程
#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

//
void* say_hello(void* args) //void* 是 C++ 中的一种特殊类型，表示指向任意类型的指针
{ // 用于实现泛型编程、函数重载等高级功能。
    cout << "Hello Runoob!" << endl;
    return 0;
}

int main()
{
    //
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        //
        int ret = pthread_create(&tids[i],NULL,say_hello,NULL);
        if (ret != 0)
        {
            cout << "pthread_create ERROR: error_code = " << ret << endl;
        }
    }
    //
    pthread_exit(NULL);

}
// 编译需要使用 g++ test_multi_threads.cpp -o test_multi_threads -lpthread
// 关键是参数 -lpthread