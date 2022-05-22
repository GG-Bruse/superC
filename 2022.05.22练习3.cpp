



/*
建立 cylinder，cylinder 的构造函数被传递了两个 double 值，分别表示圆柱体的半径和
高度。用 cylinder 计算圆柱体的体积，并存储在一个 double 变量中。在类 cylinder 中包含一
个成员函数 vol，用来显示每个 cylinder
*/
#include<iostream>
using namespace std;
const double pi = 3.14;
class cylinder
{
public:
        cylinder(double r, double h)
        {
                this->m_V = pi * r * r * h;
        }
        void vol()
        {
                cout << "体积为" << this->m_V << endl;
        }
private:
        double m_V;
};
int main()
{
        cylinder c(3.1, 4.1);
        c.vol();
        return 0;
}








/*
构建一个类 book，其中含有两个私有数据成员 qu 和 price，将 qu 初始化为 1~5，将 price
初始化为 qu 的 10 倍，建立一个有 5 个元素的数组对象。显示每个对象数组元素的 qu*price
值。
*/
#include<iostream>
using namespace std;
class Book
{
public:
        Book(int q)
        {
                this->qu = q;
                this->price = q * 10;
        }
        int get_qp()
        {
                return this->price * this->qu;
        }
private:
        int qu;
        int price;
};
int main()
{
        Book arr[5] = { Book(1),Book(2),Book(3),Book(4),Book(5) };
        for (int i = 0; i < 5; ++i)
        {
                cout << arr[i].get_qp() << endl;
        }
        return 0;
}






/*
通过对象指针访问对象数组，使程序以相反的顺序显示每个对象数组元素
的 qu*price 值
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Book
{
public:
        Book(int q)
        {
                this->qu = q;
                this->price = q * 10;
        }
        int get_qp()
        {
                return this->price * this->qu;
        }
private:
        int qu;
        int price;
};
int main()
{
        Book arr[5] = {Book(1),Book(2),Book(3),Book(4),Book(5)};
        for (Book* ptr = arr + 4; ptr != arr; --ptr)
        {
                cout << (*ptr).get_qp() << endl;
        }
        return 0;
}







#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
        Student(int number1, string name1, float score1)
        {
                number = number1;
                name = name1;
                score = score1;
        }
        void print()
        {
                cout << "学号：" << number << endl;
                cout << "姓名：" << name << endl;
                cout << "成绩：" << score << endl;
        }
protected:
        int number;
        string name;
        float score;
};
class UStudent :public Student
{
public:
        UStudent(int number1, string name1, float score1, int number2, string name2, float
                score2, int number3, string name3, float score3, string major1)
                :Student(number1, name1, score1), auditor2(number3, name3, score3), auditor1(number2, name2, score2)
        {
                major = major1;
        }
        void print()
        {
                cout << "正式生是：" << endl;
                Student::print();
                cout << "专业：" << major << endl;
        }
        void print_auditor1()
        {
                cout << "旁听生是：" << endl;
                auditor1.print();
        }
        void print_auditor2()
        {
                cout << "旁听生是：" << endl;
                auditor2.print();
        }
private:
        string major;
        Student auditor1;
        Student auditor2;
};
int main()
{
        UStudent stu(2001, "张志", 95, 3001, "王大宝", 66, 3002, "李倩倩", 50, "面向对象程序设计");
        stu.print();
        stu.print_auditor1();
        stu.print_auditor2();
        return 0;
}





#include<iostream>
using namespace std;
class B1
{
public:
        B1(int i)
        {
                b1 = i;
                cout << "Constructor B1." << endl;
        }
        void print()
        {
                cout << b1 << endl;
        }
private:
        int b1;
};
class B2
{
public:
        B2(int i)
        {
                b2 = i;
                cout << "Constructor B2." << endl;
        }
        void print()
        {
                cout << b2 << endl;
        }
private:
        int b2;
};
class A :public B2, public B1
{
public:
        A(int i, int j, int l);
        void print();
private:
        int a;
};
A::A(int i, int j, int l) :B1(i), B2(j)
{
        a = l;
        cout << "Constructor A1." << endl;
}
void A::print()
{
        B1::print();
        B2::print();
        cout << a << endl;
}
int main()
{
        A aa(50, 60, 70);
        aa.print();
        return 0;
}


