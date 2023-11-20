// 深拷贝
#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char *sbuf; //用来存放字符串的指针
    int length; // 表示字符串的长度
    public:
        String() // 不带参数的构造函数，创建一个空串
        {
            length = 0;
            sbuf = new char; //开辟空间
            sbuf[0] = '\0'; //字符串的结束符？为什么要放这个 
            cout << "The Constructor with no args is called." << endl;
        }
        String(const char *s) //带参数的构造函数
        {
            length = strlen(s); 
            sbuf = new char[length + 1]; //+1是为了存放字符串结束符'\0'
            strcpy(sbuf,s);
            cout << "The Constructor with args is called." << endl;
        }
        /*
        String(const String &s) // default copy Constructor
        {
            sbuf = s.sbuf;
            length = s.length;
            cout << "The default copy constructor is called." << endl;
        }
        */
        
        String(const String &s) // deep copy Constructor
        {
            length = s.length;
            sbuf = new char[length + 1];
            strcpy(sbuf, s.sbuf);
            cout << "The deep copy constructor is called." << endl;
        }
        
        ~String() //析构函数
        {
            delete[] sbuf; //为什么这么写
            cout << "The Destructor is called." << endl;
        }
        void show()
        {
            cout << sbuf << endl;
        }
};

int main() 
{
    String s1("Hello World!"); //定义一个对象，调用构造函数
    /* "Hello World!" is a  string constant and 
    the ISO C++ forbids converting a string constant to ‘char*’,
    so the Constructor String(char *s) should be ajust to String(const char *s).
    */ 
    s1.show();
    String s2 = s1; //此时如何调用默认拷贝构造函数，将会出现二次释放同一内存空间的错误
    // 因此需要定义深拷贝构造函数
    s2.show();
    return 0;
}