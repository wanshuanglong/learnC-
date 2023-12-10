/*

定义一个“圆”类，圆有半径，还要求出圆面积

*/
#include <iostream>
//#include <cmath>
using namespace std;
#define MYPI 3.14;

class Circle{
    private:
        float r;
    public:
        void set_r(float a) {
            r = a;
        }
        void circle_area( ) {
            float area = r * r * MYPI;
            cout << "半径为 " << r << " 的圆面积为： " << area << endl;
        }
};

int main() {
    Circle c1;
    c1.set_r(3.14);
    c1.circle_area();
    return 0;
}