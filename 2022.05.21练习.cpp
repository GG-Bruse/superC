

#include<iostream>
using namespace std;
int main()
{
        char ret;
        while (1)
        {
                cout << "现在正在下雨吗?(请输入'Y'或'N'):";
                cin >> ret;
                if (ret == 'Y')
                {
                        cout << "现在正在下雨";
                        break;
                }
                else if(ret == 'N')
                {
                        cout << "现在没有下雨";
                        break;
                }
        }
        return 0;
}





#include<iostream>
using namespace std;
int main()
{
        int ret;
        cout << "你考试考了多少分?(0-100)" << endl;
        cin >> ret;
        if (ret >= 90 && ret <= 100)
        {
                cout << "优" << endl;
        }
        else if (ret >= 80 && ret < 90)
        {
                cout << "良" << endl;
        }
        else if(ret >= 60 && ret < 80)
        {
                cout << "中" << endl;
        }
        else if (ret >= 0 && ret < 60)
        {
                cout << "差" << endl;
        }
        else
        {
                cout << "输入错误,请输入0到100之间的数字" << endl;
        }
        return 0;
}




#include<iostream>
using namespace std;
int main()
{
        int intOne;
        int& rSomeRef = intOne;
        intOne = 5;
        cout << "intOne:\t" << intOne << endl;
        cout << "rSomeRef:\t" << rSomeRef << endl;

        int intTwo = 8;
        rSomeRef = intTwo;
        cout << "\nintOne:\t" << intOne << endl;
        cout << "intTwo:\t" << intTwo << endl;
        cout << "rSomeRef:\t" << rSomeRef << endl;
        system("pause");//阻塞
        return 0;
}

//intOne:	5
//rSomeRef:	5
//
//intOne:	8
//intTwo:	8
//rSomeRef:	8








#include<iostream>
#include<string>
using namespace std;
void test(int a)
{
        cout << a << endl;
}
void test(double b)
{
        cout << b << endl;
}
void test(string b)
{
        cout << b << endl;
}
int main() {
        test(6);
        test(6.01);
        test("六点零");
        system("pause");
        return 0;
}

//6
//6.01
//六点零



/*
编写函数把华氏温度转化为相应的摄氏温度，公式为 C = 5(F-32)/9，在主程序中提示
用户输入一个华氏温度，转化后输出相应的摄氏温度，保留两位小数
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
        double fahrenheit;
        cin >> fahrenheit;
        double C_temperature = 5 * (fahrenheit - 32) / 9;
        cout << setiosflags(ios::fixed) << setprecision(2) << C_temperature<< endl;
        return 0;
}
