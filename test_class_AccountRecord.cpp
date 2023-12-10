/*
家庭财务系统收入记录类( AccountRecord )，该类包括：
(1）数据成员：财务发生的时间（ accountDay )、金额（ accountMoney ）和项目内容( accountContent );
    静态数据成员：收入总计 accountSum ;
(2）成员函数有：构造函数，用于初始化数据用；输出收入总计的函数 accountSum ();
    显示一条财务记录信息函数 showAccountRecord ()。
在 main (）函数中，可以通过输入或传实参设置每一笔账目，测试能输出每一条财务记录和财务余额。
*/
#include <iostream>
#include <cstring>
using namespace std;

class AccountRecord
{
    private:
        int accountDay[3]; //accountDay[0] = year; accountDay[1] = month; accountDay[2] = day;
        double accountMoney;
        char *accountContent;
        int length;
    public:
        static double incomeSum;
        AccountRecord(int year,int month, int day, double b, const char *c)
        {
            accountDay[0] = year;
            accountDay[1] = month;
            accountDay[2] = day;
            accountMoney = b;
            //////////////////////////////////////////
            // 往函数里传递字符串还是有些难度的，需要再进一步学习
            length = strlen(c);
            accountContent = new char[length + 1];
            strcpy(accountContent,c);
            /////////////////////////////////////////
            incomeSum += b;
            cout << "The Constructor with args is called." << endl;
        }
        static double accountSum() //静态成员函数，返回帐户余额
        {
            return incomeSum;
        }
        void showAccountRecord()
        {
            cout << accountDay[0] << "." << accountDay[1] << "." \
            << accountDay[2] << " " << accountContent << " " \
            << accountMoney << "CNY  " << "Account balance: " << \
            incomeSum << "CNY"<< endl; 
        }
        ~AccountRecord()
        {
            cout << "The destructor is called." << endl;
        }
};
double AccountRecord :: incomeSum = 0; 
//在AccountRecord类中定义了一个名为incomeSum的double类型成员变量，并将其初始值设置为0。

int main()
{
    AccountRecord income1(2023, 9, 14, 4800, "salary");
    //AccountRecord income2(2023, 8, 14, 4800, "salary");
    income1.showAccountRecord();
    //income2.showAccountRecord();
    return 0;
}