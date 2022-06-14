#include<iostream>
using namespace std;
class A
{
public:
        virtual void func1()
        {
                cout << "A1";
        }
        void func2()
        {
                cout << "A2";
        }
};
class B :public A
{
public:
        void func1()
        {
                cout << "B1";
        }
        void func2()
        {
                cout << "B2";
        }
};
int main()
{
        A* p = new B;
        p->func1();
        p->func2();
        return 0;
}







#include<iostream>
using namespace std;
class Base
{
protected:
        Base()
        {
                cout << 'A';
        }
        Base(char c)
        {
                cout << c;
        }
};
class Derived :public Base
{
public:
        Derived(char c)
        {
                cout << c;
        }
};
int main()
{
        Derived d1('B');
        return 0;
}






#include<iostream>
using namespace std;
class Base
{
public:
        void print() { cout << 'B'; }
};
class Derived :public Base
{
public:
        void print() { cout << 'D'; }
};
int main()
{
        Derived* pd = new Derived();
        Base* pb = pd;
        pb->print();
        pd->print();
        delete pd;
        return 0;
}






#include<iostream>
using namespace std;
class Base
{
public:
        Base(int x = 0) :valB(x)
        {
                cout << valB;
        }
        ~Base()
        {
                cout << valB;
        }
private:
        int valB;
};
class Derived :public Base
{
public:
        Derived(int x = 0, int y = 0) :Base(x), valD(y)
        {
                cout << valD;
        }
        ~Derived()
        {
                cout << valD;
        }
private:
        int valD;
};
int main()
{
        Derived obj(2, 3);
        return 0;
}






#include<iostream>
using namespace std;
class B
{
public:
        B(int xx) :x(xx)
        {
                ++count;
                x += 10;
        }
        virtual void show()const
        {
                cout << count << '_' << x << endl;
        }
protected:
        static int count;
private:
        int x;
};
class D :public B
{
public:
        D(int xx, int yy) :B(xx), y(yy)
        {
                ++count;
                y += 100;
        }
        virtual void show()const
        {
                cout << count << '_' << y << endl;
        }
private:
        int y;
};
int B::count = 0;
int main()
{
        B* ptr = new D(10, 20);
        ptr->show();
        delete ptr;
        return 0;
}







#include<iostream>
using namespace std;
class Base
{
        int a, b;
public:
        Base(int x, int y)
        {
                a = x;
                b = y;
        }
        void show()
        {
                cout << a << ',' << b << endl;
        }
};
class Derived :public Base
{
        int c, d;
public:
        Derived(int x, int y, int z, int m) :Base(x, y)
        {
                c = z;
                d = m;
        }
        void show()
        {
                cout << c << ',' << d << endl;
        }
};
int main()
{
        Base B1(50, 50), * pb;
        Derived D1(10, 20, 30, 40);
        pb = &D1;
        pb->show();
        return 0;
}






#include<iostream>
using namespace std;
class A
{
public:
        A(int i) { x = i; }
        void dispa() { cout << x << ','; }
private:
        int x;
};
class B :public A
{
public:
        B(int i) :A(i + 10) { x = i; }
        void dispb() { dispa(); cout << x << endl; }
private:
        int x;
};
int main()
{
        B b(2);
        b.dispb();
        return 0;
}


