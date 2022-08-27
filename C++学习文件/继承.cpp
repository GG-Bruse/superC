#define _CRT_SECURE_NO_WARNINGS



//继承

/*
C++通过继承机制可以利用已有的数据类型来定义新的数据类型，新的类不仅拥有旧类的成员，还拥有新定义的成员
1.继承语法:
class 子类名(派生类): 继承方式 父类名(基类名)
2.继承的优点:
减少重复的代码，提高代码复用性
3.派生类中的成员，包含两大部分:
(1)一类是从基类继承过来的，一类是自己增加的成员
(2)从基类继承过来的表现其共性，而新增的成员体现其个性
*/
/*
继承方式:
公有继承、保护继承、私有继承
派生类只可以访问基类的共有权限和保护权限下的特征，不可访问私有权限下的特征
基类中的默认构造、析构、拷贝构造、operator=不会被派生类继承
1.共有继承:保持基类的权限将其继承
2.保护继承:将从基类的继承来的特征在本类中都修改为保护权限
3.私有继承:将从基类的继承来的特征在本类中都修改为私有权限

从继承源上分:
1.单继承:
指每个派生类只直接继承一个基类的特征
2.多继承:
指多个基类派生出一个派生类的继承关系，多继承的派生类直接继承了不止一个基类的特征
*/

//#include<iostream>
//using namespace std;
//class Basepage
//{
//public:
//    void header()
//    {
//        cout << "公共的头部" << endl;
//    }
//    void footer()
//    {
//        cout << "公共的底部" << endl;
//    }
//    void leftlist()
//    {
//        cout << "公共的左侧列表" << endl;
//    }
//};
//class News: public Basepage
//{
//public:
//    void content()
//    {
//        cout << "新闻播报……" << endl;
//    }
//};
//class Sport : public Basepage
//{
//public:
//    void content()
//    {
//        cout << "世界杯赛况……" << endl;
//    }
//};
//int main()
//{
//    News n;
//    Sport sp;
//    n.header();
//    n.footer();
//    sp.leftlist();
//    sp.content();
//    return 0;
//}





//继承中的对象模型
/*
在开发人员命令提示符查看对象模型
1.跳转盘符D:
2.跳转文件路径:cd 文件路径
3.cl /d1 reportSingleClassLayout类名 文件名
*/

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    int m_a;
//protected:
//    int m_b;
//private:
//    int m_c;//基类中的私有属性，派生类访问不到(被编译器隐藏)，但会被继承
//};
//class Son : public Base
//{
//public:
//    int m_d;
//};
//int main()
//{
//    cout << "sizeof Son:" << sizeof(Son) << endl;//16
//    return 0;
//}






//继承中的构造和析构顺序
/*
1.先调用父类构造在调用子类构造，析构与构造相反
2.若本类中有其他类对象作为成员，先调用父类构造，再调用其他类构造，最后调用自身构造。析构与构造顺序相反。
3.若父类中没有默认构造函数:
(1)在父类中添加空实现的默认构造函数
(2)使用初始化列表的方式调用父类中的其他构造函数
*/

//1.
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    Base() { cout << "Base构造函数调用" << endl; }
//    ~Base() { cout << "Base析构函数调用" << endl; }
//};
//class Son : public Base
//{
//public:
//    Son() { cout << "Son构造函数调用" << endl; }
//    ~Son() { cout << "Son析构函数调用" << endl; }
//};
//int main()
//{
//    Son s1;
//    return 0;
//}



//2.
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    Base(){cout << "Base构造函数调用" << endl;}
//    ~Base(){cout << "Base析构函数调用" << endl;}
//};
//class Other
//{
//public:
//    Other() { cout << "Other构造函数调用" << endl; }
//    ~Other() { cout << "Other析构函数调用" << endl; }
//};
//class Son: public Base
//{
//public:
//    Son(){cout << "Son构造函数调用" << endl;}
//    ~Son(){ cout << "Son析构函数调用" << endl;}
//    Other o;
//};
//int main()
//{
//    Son s1;
//    return 0;
//}


//3.
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    Base(int a) { cout << "Base有参构造函数调用" << endl; }
//};
//class Son : public Base
//{
//public:
//    Son(int a) :Base(a)//在父类没有默认构造函数的情况下可以使用初始化列表的方式调用父类中的有参构造函数
//    { 
//        cout << "Son构造函数调用" << endl; 
//    }
//};
//int main()
//{
//    Son s1(100);
//    return 0;
//}








//继承中的同名成员处理
/*
1.可以利用作用域访问父类中的同名成员
2.当子类与父类出现同名函数(即子类重定义父类中的函数)，子类成员函数会隐藏掉父类中的所有重载版本的同名成员，只可以利用作用域进行显式调用
*/
/*
重定义(隐藏)
1.有继承
2.子类(派生类)重新定义父类(基类)的同名成员(非virtual函数)
*/
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    int m_a;
//    Base()
//    {
//        this->m_a = 10;
//    }
//    void func(int a)
//    {
//        cout << "Base中有参函数调用" << endl;
//    }
//    void func()
//    {
//        cout << "Base中函数调用" << endl;
//    }
//};
//class Son: public Base
//{
//public:
//    int m_a;
//    Son()
//    {
//        this->m_a = 20;
//    }
//    void func()
//    {
//        cout << "Son中函数调用" << endl;
//    }
//};
//int main()
//{
//    Son s1;
//    //本类中的成员优先
//    cout << s1.m_a << endl;//20 
//    //通过添加作用域访问父类中的同名成员
//    cout << s1.Base::m_a << endl;//10
//    s1.func();
//    s1.Base::func(10);//必须加上作用域
//    s1.Base::func();
//    return 0;
//}


//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    static void func()
//    {
//        cout << "Base中函数调用" << endl;
//    }
//    static int m_a;
//};
//int Base::m_a = 10;
//class Son : public Base
//{
//public:
//    static void func()
//    {
//        cout << "Son中函数调用" << endl;
//    }
//    static int m_a;
//};
//int Son::m_a = 20;
//int main()
//{
//    cout << Son::m_a << endl;
//    cout << Son::Base::m_a << endl; //通过类名的方式访问父类作用域下的m_a静态成员变量
//    Son::func();
//    Son::Base::func();//通过类名的方式访问父类作用域下的func静态成员函数
//    return 0;
//}









//多继承(不建议使用)
//#include<iostream>
//using namespace std;
//class Base1
//{
//public:
//    Base1()
//    {
//        this->m_a = 10;
//    }
//    int m_a;
//};
//class Base2
//{
//public:
//    Base2()
//    {
//        this->m_a = 20;
//    }
//    int m_a;
//};
//class Son: public Base1,public Base2
//{
//public:
//    int m_c;
//};
//int main()
//{
//    Son s;
//    cout << "sizeof Son " << sizeof(Son) << endl;//12
//    //当多继承的两个父类中有同名成员，需加作用域进行区分
//    cout << s.Base1::m_a << endl;
//    cout << s.Base2::m_a << endl;
//    return 0;
//}






//菱形继承问题
/*
两个派生类继承于同一个基类而又有某个类同时继承于这两个派生类，这种继承被称为菱形继承(钻石型继承)
问题:(利用虚继承解决，关键字virtual)
1.数据的二义性
2.数据重复
*/
/*
当发生虚继承后，两个派生类继承了一个vbptr指针(虚基类指针)，指向的是一个虚基类表(vbtable)
虚基类表中记录了偏移量，通过偏移量可以找到唯一的数据
*/
//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//    int m_age = 10;
//};
////羊类
//class Sheep :virtual public Animal {};
////驼类
//class Tuo :virtual public Animal {};
////羊驼类
//class SheepTuo : public Sheep, public Tuo {};
//int main()
//{
//    SheepTuo s;
//    cout << "sizeof SheepTuo " << sizeof(SheepTuo) << endl;//12
//    cout << s.m_age << endl;//10
//    return 0;
//}









//继承构造
/*
注意:
1.继承构造函数的功能是初始化基类中的成员变量,无法初始化派生类数据成员。
2.若基类的构造函数被声明为私有，或者派生类是从基类中虚继承，那么不能使用继承构造函数
3.一旦使用继承构造，编译器不会再为派生类提供默认构造函数
4.若构造函数拥有默认值，则会产生多个构造函数版本，且继承构造函数无法继承基类构造函数的默认参数
5.多继承的情况下，继承构造函数会出现“冲突”的情况，因为多个基类中的部分构造函数可能导致派生类中的继承构造函数的函数名、参数相同
*/
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//    Date(int x)
//    {
//        this->m_x = x;
//        this->m_y = 100;
//    }
//    Date(int x, int y)
//    {
//        this->m_x = x;
//        this->m_y = y;
//    }
//protected:
//    int m_x;
//    int m_y;
//};
//class Print :public Date
//{
//public:
//    //提供多个有参构造函数初始化继承于Date基类的属性
//    /*Print(int x,int y):Date(x,y){}
//    Print(int x) :Date(x) {}*/
//
//    //使用继承构造
//    using Date::Date;
//    void print()
//    {
//        cout << "x = " << this->m_x << endl;
//        cout << "y = " << this->m_y << endl;
//    }
//    //无新增成员变量
//};
//int main()
//{
//    Print obj{ 10};
//    obj.print();
//    return 0;
//}



//#include<iostream>
//using namespace std;
//class A {
//public:
//    A(int i) { cout << "A(int)调用" << endl; }
//};
//class B
//{
//public:
//    B(int i) { cout << "B(int)调用" << endl; }
//};
//class C : public A, public B {
//public:
//    using A::A;   //两个继承构造函数都会定义一个C(int)
//    using B::B;  //编译出错，重复定义C(int)
//
//   //显示定义继承构造函数C(int)
//    C(int i) :A(i), B(i)
//    { 
//        cout << "C(int)调用" << endl; 
//    }
//};
//int main()
//{
//    C c(10);
//    return 0;
//}
/*
A(int)调用
B(int)调用
C(int)调用
*/







//继承控制 final和override
/*
禁用一个类的进一步衍生
1.final阻止类的进一步派生和虚函数的进一步重写
2.override确保在派生类中声明的函数跟基类中的虚函数有相同的签名(包括函数名、参数类型、参数个数、顺序、返回值)
*/

//1.
//#include<iostream>
//using namespace std;
//class A final//该类无法被继承
//{
//    int a;
//};
//class B1
//{
//public:
//    virtual void func() final{}//该虚函数无法被重写
//};

//2.
//#include<iostream>
//using namespace std;
//class A1
//{
//public:
//    virtual void func(int a)
//    {
//        cout << a << endl;
//    }
//};
//class A2 :public A1
//{
//public:
//    void func(int a)override{}//要求重写的与虚函数签名一致
//};