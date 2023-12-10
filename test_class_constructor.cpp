#include <iostream>
using namespace std;
//#include "Point.h"

class Point {
    private: //这里的private关键字可以省略
        int x,y; // 成员变量x,y是Point类私有的，
        // 若要访问类的私有成员，可以通过定义public成员函数来实现
    public:
        void set1(int a, int b);
        void printxy (); 
        Point(); // constructor构造函数
        Point(int a, int b); //不要忘记函数声明
        Point(int);
        //Point(int a = 9, int b =9); //利用构造函数给成员变量赋上默认值 
        virtual ~Point(); // destructor析构函数
};
//////////////////////////////////////////////////////////
void Point :: set1(int a, int b) {
    x = a;
    y = b;
}
void Point :: printxy() { // 当成员函数定义很长时，可将成员函数定义写在类外面
    cout << "点坐标为：(" << x << "," << y << ")" << endl;
}
//////////////////////////////////////////////////////////
Point :: Point() { //默认构造函数
    cout << "The default Constructor is called when an object is created." << endl;
}
Point :: Point(int a, int b) { //
    x = a;
    y = b;
    cout << " The Constructor with two parameters is called." << endl;
}
Point :: Point(int a) {
    x = a;
    y = 18;
    cout << "The Constructor with one paremeter is called." << endl;
}
/*
Point :: Point (int a = 9, int b = 9) { 
    x = a;
    y = b;
    cout << "Use the constructor to assign default values to member variables." << endl;
}*/
///////////////////////////////////////////////////////////////////////////
Point :: ~Point() { //默认的析构函数
    cout << "The destructor is called." << endl;
}
//////////////////////////////////////////////////////////////////////////

int main() {
    Point p1; // 定义一个类的对象
    //p1.x = 1; // erro 私有成员不可以这样访问
    //p1.y = 1;
    p1.set1(1,1); //通过公共成员函数访问
    p1.printxy();
    
    Point *point_1; // 定义一个类指针
    point_1 = &p1; //让其指向对象p1
    (*point_1).set1(11,11);
    p1.printxy();
    point_1 -> set1(12,12); //指向符
    (&p1)->printxy();
    //delete point_1; //似乎不需要再写delete语句释放内存，析构函数会被自动调用

    cout << "--------------------------" << endl;
    Point p[3];
    for (int i = 0; i < 3; ++i) {
        p[i].set1(i,i);
        p[i].printxy();
    }
    //delete p;

    cout << "---------------------------" << endl;
    Point cp1, cp2(1), cp3(2,3);
    cp2.printxy();
    cp3.printxy();
    //delete &cp1;
    return 0;
}