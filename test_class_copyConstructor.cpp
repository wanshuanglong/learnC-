#include <iostream>
using namespace std;
//#include "Point.h"

class Point {
    int x,y;
    public:
    Point (int a, int b) { // constructor with two parameters
        x = a;
        y = b;
        cout << "Constructor ......." << endl;
    }
    Point (const Point &p) { //copyconstructor
        x = p.x;
        y = p.y;
        cout << "CopyConstructor ......." << endl;

    }
    ~Point () { // destructor
        cout << "Destructor ......." << endl;
    }
    void show()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
Point fun(Point temp) {
    Point p(temp);
    return p;
}

int main() 
{
    Point p1(1,1);
    p1.show();
    Point p2(2,2);
    p2.show();
    Point p3(p1);
    p3.show();
    Point p4 = p2;
    p4.show();
    p4 = p1;
    p4.show();
    p4 = fun(p2);
    p4.show();
    return 0;
}