#include<iostream>
using namespace std;
class Myclass
{
public:
        Myclass()
        {
                cout << 1;
        }
};
int main()
{
        Myclass a, b[2], * p[2];
        return 0;
}






#include<iostream>
using namespace std;
class test
{
private:
        int a;
public:
        test()
        {
                cout << "constructor" << endl;
        }
        test(int a) { cout << a << endl; }
        test(const test& _test)
        {
                a = _test.a;
                cout << "copy constructor" << endl;
        }
        ~test() { cout << "destructor" << endl; }
};
int main()
{
        test A(3);
        return 0;
}








#include<iostream>
using namespace std;
class Base
{
public:
        Base(int x = 0)
        {
                cout << x;
        }
};
class Derived:public Base
{
public:
        Derived(int x = 0)
        {
                cout << x;
        }
private:
        Base val;
};
int main()
{
        Derived d(1);
        return 0;
}








#include<iostream>
using namespace std;
class B
{
        void fun1() {}
protected:
        double var;
public:
        void fun2() {}
};
class D :public B
{
protected:
        void func3() {}
};
int main()
{
        D obj;
        obj.fun2();
}






#include<iostream>
using namespace std;
class Part
{
public:
        Part(int x = 0):val(x)
        {
                cout << val;
        }
        ~Part()
        {
                cout << val;
        }
private:
        int val;
};
class Whole
{
public:
        Whole(int x, int y, int z = 0) :p2(x), p1(y), val(z)
        {
                cout << val;
        }
        ~Whole()
        {
                cout << val;
        }
private:
        Part p1, p2;
        int val;
};
int main()
{
        Whole obj(1, 2, 3);
        return 0;
}






#include<iostream>
using namespace std;
class Test
{
public:
        Test() {}
        Test(const Test& t)
        {
                cout << 1;
        }
};
Test fun(Test& u)
{
        Test t = u;
        return t;
}
int main()
{
        Test x, y;
        x = fun(y);
        return 0;
}







#include<iostream>
#include<iomanip>
using namespace std;
class Myclass
{
public:
        Myclass()
        {
                cout << 'A';
        }
        Myclass(char c)
        {
                cout << c;
        }
        ~Myclass()
        {
                cout << 'B';
        }
};
int main()
{
        Myclass p1, * p2;
        p2 = new Myclass('X');
        delete p2;
        return 0;
}







#include<iostream>
using namespace std;
int i = 0;
class Fun
{
public:
        static int i;
        int value()
        {
                return i - 1;
        }
        int value()const
        {
                return i + 1;
        }
};
int Fun::i = 2;
int main()
{
        int i = 3;
        Fun fun1;
        const Fun fun2;
        cout << fun1.value() << Fun::i << fun2.value();
        return 0;
}








#include<iostream>
using namespace std;
class Obj
{
        static int i;
public:
        Obj()
        {
                i++;
        }
        ~Obj()
        {
                i--;
        }
        static int getVal()
        {
                return i;
        }
};
int Obj::i = 0;
void f()
{
        Obj ob2;
        cout << ob2.getVal();
}
int main()
{
        Obj ob1;
        f();
        Obj* ob3 = new Obj;
        cout << ob3->getVal();
        delete ob3;
        cout << Obj::getVal();
        return 0;
}

