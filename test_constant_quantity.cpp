#include <iostream>
using namespace std;
 
int main()
{
   const int  LENGTH = 10; //利用const关键字声明常量
   const int  WIDTH  = 5;    //另外，在C++中用大写字母定义常量名，是个很好的编程实践
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}