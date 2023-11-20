// 静态成员
// 学生类

#include <iostream>
using namespace std;

class Student
{
    public:
        static int count; //静态成员变量
        static double total;
        Student(double score) //构造函数，利用构造函数实现递增功能,因为每次创建对象都会自动调用构造函数
        {
            this -> score = score;
            count ++;
            total += score;
            cout << "The Constructor with args is called." << endl;
        }
        static double getAverage() //静态成员函数
        {
            // cout << score << endl; //error 静态成员函数不能访问非静态成员
            return total/count;
        }
        static double getTotal() //静态成员函数
        {
            return total;
        }
        ~Student()
        {
            cout << "The destructor is called." << endl;
        }
    private:
        double score; //普通的成员变量

};

int Student :: count = 0; //静态成员变量初始化，必须放在类外部
double Student :: total = 0;

int main()
{
    /*
    cout << Student::count << endl;
    cout << Student::total << endl;
    Student s1(70);
    cout << Student::count << endl;
    cout << Student::total << endl;
    //cout << s1.count << endl;
    //cout << s1.total << endl;
    */
    Student s1(70), s2(80);
    Student s[3] ={Student(74), Student(83.5), Student(91.5)};
    //cout << s1.getAverage() << endl;
    //cout << s << endl; // s是个指针
    cout << Student :: getTotal() << endl; //访问静态成员，可以用类名直接访问，而不需要通过对象
    cout << Student :: getAverage() << endl;
    return 0;
}