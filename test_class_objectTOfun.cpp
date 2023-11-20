// 1. 使用对象作为函数参数
// 2. 对象指针作为函数的参数
// 3. 对象引用作为函数的参数
#include <iostream>
using namespace std;

class Point 
{
    int x,y;
    public:
        Point (int a, int b)
        {
            x = a;
            y = b;
            cout << "The Constructor with args is called." << endl;
        }
        Point(const Point &p)
        {
            x = p.x;
            y = p.y;
            cout << "The default copy constructor is called." << endl;
        }
        void set(int a, int b)
        {
            x = a;
            y = b;
        }
        void show()
        {
            cout << "(" << x << "," << y << ")" << endl;
        }
        ~Point()
        {
            cout << "The Destructor is called." << endl;
        }
};
void fun (Point point) // Point point = p;对象作为函数参数,此时该函数并不能改变p的值
{
    point.set(10,10);
    cout << "The point's x and y are: " ;
    point.show();
}

void fun2 (Point *point) // Point *point = &p; 对象指针作为函数的参数，此时该函数可以改变p的值
{
    point -> set(10,10);
    cout << "The *point's x and y are: ";
    point -> show();
}

void fun3(Point &point) // Point &point = p; 对象引用作为函数参数，此时该函数可以改变p的值
{ //引用相当于给变量起了个别名
    point.set(11,11);
    cout << "The point's x and y are: ";
    point.show();
}

int main() 
{
    Point p(1,1);
    fun(p);
    cout << "Althought the fun() is called, p is unchanged in main: ";
    p.show();
    fun2(&p);
    cout << "The fun2() is called and p is changed. Now p = " ;
    p.show();
    fun3(p);
    cout << "The fun3() is called and p is changed. Now p = " ;
    p.show();
    return 0;
}