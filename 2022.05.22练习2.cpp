
#include<iostream>
using namespace std;
class Solution
{
public:
        int Get_Max(int a, int b, int c)
        {
                int max = a;
                if (max < b)
                        max = b;
                if (max < c)
                        max = c;
                return max;
        }
};
int main()
{
        int a, b, c;
        cin >> a >> b >> c;
        Solution s;
        int max = s.Get_Max(a,b,c);
        cout << "最大值为" << max << endl;
        return 0;
}





#include<iostream>
#include<string>
using namespace std;
class Base
{
public:
        void setx(int n)
        {
                x = n;
        }
        void showx()
        {
                cout << x << endl;
        }
private:
        int x;
};
class Derived :private Base
{
public:
        void setxy(int n, int m)
        {
                setx(n);
                y = m;
        }
        void showxy()
        {
                this->showx();
                cout << y << endl;
        }
private:
        int y;
};
int main()
{
        Derived obj;
        obj.setxy(20, 30);
        obj.showxy();
        return 0;
}






#include<iostream>
#include<string>
using namespace std;
class Base
{
public:
        void seta(int sa)
        {
                a = sa;
        }
        void showa()
        {
                cout << "a = " << a << endl;
        }
protected:
        int a;
};
class Derived1 :private Base
{
public:

        void setab(int sa, int sd)
        {
                a = sa;
                b = sd;
        }
        void showab()
        {
                this->showa();
                cout << "b = " << b << endl;
        }
protected:
        int b;
};
class Derived2 :private Derived1
{
public:
        void setabc(int sa, int sd, int sc)
        {
                setab(sa, sd);
                c = sc;
        }
        void showabc()
        {
                this->showab();
                cout << "c = " << c << endl;
        }
private:
        int c;
};
int main()
{
        Base op1;
        op1.seta(1);
        op1.showa();
        Derived1 op2;
        op2.setab(2, 3);
        op2.showab();
        Derived2 op3;
        op3.setabc(4, 5, 6);
        op3.showabc();
        return 0;
}

#include<iostream>
using namespace std;
class Base
{
public:
        Base()
        {
                cout << "Constructing base class\n";
        }~Base()
        {
                cout << "Destructing base class\n";
        }
};
class Derived :public Base
{
public:
        Derived()
        {
                cout << "Constructing derived class" << endl;
        }~Derived()
        {
                cout << "Destructing derived class" << endl;
        }
};
int main()
{
        Derived obj;
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
                cout << "number:" << number << endl;
                cout << "name:" << name << endl;
                cout << "score:" << score << endl;
        }
protected:
        int number;
        string name;
        float score;
};
class UStudent :public Student
{
public:
        UStudent(int number1, string name1, float score1, string
                major1) :Student(number1, name1, score1)
        {
                major = major1;
        }
        void printl()
        {
                print();
                cout << "major:" << major << endl;
        }
private:
        string major;
};
int main()
{
        UStudent stu(22116, "张志", 95, "面向对象程序设计实验");
        stu.printl();
        return 0;
}
