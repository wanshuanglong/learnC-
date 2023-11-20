// this 指针
#include <iostream>
using namespace std;

class Date
{
    int year, month, day;
    public:
        //Date(int y = 2023, int m = 9, int d = 11) //设置默认值的构造函数
        Date(int year = 2023, int month = 9, int day = 11)
        { //使用this指针就可以区分成员变量与函数参数了
            this -> year = year;
            (*this).month = month;
            this -> day = day;
            cout << "The Constructor with args is called." << endl;
        }
        void show()
        {
            cout << year << "." << month << "." << day << endl;
        }
        Date &fun() //类的方法需要返回当前对象的引用的时候，需要用到this 指针
        {
            return *this;
        }
        ~Date()
        {
            cout << "The Destructor is called." << endl;
        }
};

int main()
{
    Date d1(2020,12,1),d2;
    d1.show();
    d2.show();
    (d1.fun()).show();
    return 0;
}