// 一个类的成员函数作为另一个类的友元
#include <string>
#include <iostream>
using namespace std;

class Girl; // 与函数类似，在调用类前也必须对其进行声明，但其定义可以放在后面写

class Boy
{
    string name;
    public:
        Boy(string nm)
        {
            name = nm;
            cout << "Boy's constructor is called." << endl;
        }
        void IntrouduceOneself()
        {
            cout << "I am " << name << endl;
        }
        void IntroduceFriend(Girl &x);
};

class Girl
{
    string name;
    public:
        Girl(string nm)
        {
            name = nm;
            cout << "Girl's constructor is called." << endl;
        }
        void IntroduceOneself()
        {
            cout << "I am " << name << endl;
        }
        friend void Boy :: IntroduceFriend(Girl &x); // 声明友元函数
};

void Boy :: IntroduceFriend(Girl &x) // 成员函数定义放在外部时不要忘记 classname :: classfun()
{
    cout << x.name << " is my girlfriedn. ^_^!" << endl;
}

int main()
{
    Boy boy1("Tom");
    Girl girl1("Marry");
    boy1.IntrouduceOneself();
    girl1.IntroduceOneself();
    boy1.IntroduceFriend(girl1);
    return 0;
}