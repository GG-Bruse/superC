#define _CRT_SECURE_NO_WARNINGS

//类和对象

//初识
/*
类的关键字:class
类中的函数被称为成员函数(或成员方法)
类中的变量被称为成员变量(或成员属性)
通过类创建一个变量(对象),被称为实例化对象
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    int a;//只有非静态成员变量属于类对象上
//
//    void fun1() {}//成员函数不属于类对象上
//
//    static int b;//静态成员变量不属于类对象上
//
//    static void fun2() {}//静态成员函数不属于类对象上
//
//    double d;//与struct相同也遵循内存对齐
//};
//int main()
//{
//    A a;
//    cout << sizeof(a) << endl;//16
//    return 0;
//}


//空类以及空对象的大小为1字节
//#include<iostream>
//using namespace std;
//class Person
//{};
//int main()
//{
//    Person p;
//    cout << sizeof(Person) << endl;//1
//    cout << sizeof(p) << endl;//1
//    return 0;
//}


//设计一个类，求圆的周长
//#include<iostream>
//using namespace std;
//const float pi = 3.14f;
//class Circle
//{
//public://公共权限
//	float R;
//	void SETR(float r)//设置半径
//	{
//		R = r;
//	}
//	float ZC()//返回周长
//	{
//		return 2 * R * pi;
//	}
//};
//int main()
//{
//	Circle c1;//通过类创建一个对象(实例化对象)
//	c1.SETR(10);//c1.R = 10;
//	cout << "圆的周长为 = " << c1.ZC() << endl;//62.8
//	return 0;
//}



//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，并且可以显示学生的姓名和学号
//#include<iostream>
//#include<string>
//using namespace std;
//class student
//{
//public:
//    struct S
//    {
//        string name;
//        int ID;
//    }s1;
//    void get()
//    {
//        S* p = &s1;
//        cout << "请输入学生的姓名:";
//        cin >> p->name;
//        cout << "请输入学生的学号:";
//        cin >> p->ID;
//    }
//    void put()
//    {
//        S* p = &s1;
//        cout << p->name << ":" << p->ID << endl;
//    }
//};
//int main()
//{
//    student s;
//    s.get();
//    s.put();
//    return 0;
//}










//类的封装
/*
C++封装理念:
将属性和行为作为一个整体，来表现事物。
将属性和行为加以权限控制
*/
/*
class的默认权限为私有权限
访问权限:
1.public公共权限——类内类外都可以访问成员
2.private私有权限——类内可以访问成员、类外不可访问成员
3.protectd保护权限——类内可以访问成员、类外不可访问成员(子类可以访问父类的protectd权限内容)
*/

/*
建议将成员属性设置为private私有权限
优势:
(1)可以通过在类中编写函数来控制读写
(2)可以在函数中对设置内容加以有效性验证
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Person
//{
//public:
//    //设置名字
//    int setname(string p)
//    {
//        if (p == "李四")
//        {
//            cout << "该名字已被使用" << endl;
//            return 0;
//        }
//        name = p;
//    }
//    //读取名字
//    string getname()
//    {
//        return name;
//    }
//    //读取年龄
//    int getage()
//    {
//        return age;
//    }
//    //设置
//    void setlover(string a)
//    {
//        lover = a;
//    }
//private:
//    string name = "王五";//可读、可写
//    int age = 18;//可读
//    string lover;//可写
//};
//void test()
//{
//    Person p;
//    //名字
//    p.setname("李四");
//    cout << p.getname() << endl;
//    //年龄
//    cout << p.getage() << endl;
//    //LOVER
//    p.setlover("abcdef");
//}
//int main()
//{
//    test();
//    return 0;
//}



//立方体类设计案例
//分别通过全局函数和成员函数判断两立方体是否相等
//#include<iostream>
//using namespace std;
//class Cube
//{
//public:
//    //设置长宽高
//    void setLWH(int a,int b,int c)
//    {
//        l = a;
//        w = b;
//        h = c;
//    }
//    //获取长宽高
//    int getL()
//    {
//        return l;
//    }
//    int getW()
//    {
//        return w;
//    }
//    int getH()
//    {
//        return h;
//    }
//    //求面积
//    int S()
//    {
//        return 2 * l * w + 2 * l * h + 2 * w * h;
//    }
//    //求体积
//    int V()
//    {
//        return l * w * h;
//    }
//    //判断
//    bool compare(Cube &c)
//    {
//        return ((l == c.getL()) && (w == c.getW()) && (h == c.getH()));  
//    }
//private:
//    int l;//长
//    int w;//宽
//    int h;//高
//};
//bool compareCube(Cube &c1,Cube &c2)
//{
//    return ((c1.getL() == c2.getL()) && (c1.getW() == c2.getW()) && (c1.getH() == c2.getH()));   
//}
//int main()
//{
//    Cube c1, c2;
//    c1.setLWH(10,10,10);
//    c2.setLWH(10, 10, 10);
//    cout << "面积为:" << c1.S() << endl;
//    cout << "体积为:" << c1.V() << endl;
//    bool ret = compareCube(c1, c2);
//    if (ret)
//    {
//        cout << "c1和c2相等" << endl;
//    }
//    else
//    {
//        cout << "c1和c2不相等" << endl;
//    }
//     ret = c1.compare(c2);
//    if (ret)
//    {
//        cout << "成员函数判断c1和c2相等" << endl;
//    }
//    else
//    {
//        cout << "成员函数判断c1和c2不相等" << endl;
//    }
//    return 0;
//}



//点和圆关系案例
//#include<iostream>
//using namespace std;
////点类
//class Point
//{
//public:
//    //设置x、y
//    void setxy(int a, int b)
//    {
//        x = a;
//        y = b;
//    }
//    //获取x、y
//    int getx()
//    {
//        return x;
//    }
//    int gety()
//    {
//        return y;
//    }
//private:
//    int x;
//    int y;
//};
////圆类
//class Circle
//{
//public:
//    void setr(int a)//设置半径
//    {
//        m_r = a;
//    }
//    int getr()//获取半径
//    {
//        return m_r;
//    }
//    void setcenter(Point p)//设置圆心
//    {
//        m_center = p;
//    }
//    Point getcenter()//获取圆心
//    {
//        return m_center;
//    }
//private:
//    int m_r;//半径
//    Point m_center;//圆心
//};
//void panduan(Circle c,Point p)
//{
//    int distanced = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx())
//        + (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());//点到圆心距离的平方
//    int Rdistanced = c.getr() * c.getr();//半径的平方
//    if (distanced == Rdistanced)
//    {
//        cout << "点在圆上" << endl;
//    }
//    else if (distanced > Rdistanced)
//    {
//        cout << "点在圆外" << endl;
//    }
//    else
//    {
//        cout << "点在圆内" << endl;
//    }
//}
//int main()
//{
//    Circle c;
//    Point ce;//圆心
//    Point p;
//    ce.setxy(0, 0);
//    c.setcenter(ce);
//    c.setr(10);
//    p.setxy(10, 10);
//    panduan(c, p);
//        return 0;
//}

















//对象的构造和析构

//构造函数进行初始化、析构函数进行清理
//构造和析构必须声明在全局作用域

/*
构造函数:
1.没有返回值，不用写void
2.函数名与类名相同
3.可以有参数，可以发生重载
4.构造函数由编译器自动调用一次(对象建立时调用)
*/
/*
析构函数:
1.没有返回值，不用写void
2.函数名为类名前加上~
3.不可以有参数，不可以发生重载
4.构造函数由编译器自动调用一次(对象释放时调用)
*/


//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person()
//    {
//        cout << "构造函数调用" << endl;
//    }
//    ~Person()
//    {
//        cout << "析构函数调用" << endl;
//    }
//};
//int main()
//{
//    Person p;
//    return 0;
//}




//构造函数的分类和调用
/*
按照参数分类:
1.无参构造(默认构造函数)
2.有参构造
按照类型分类:
1.普通构造函数
2.拷贝构造函数
*/

/*
调用:
1.括号法
 不要使用括号发调用无参构造函数。编译器将认为代码是函数的声明
2.显示法:
不要使用拷贝构造函数初始化匿名对象
3.隐式类型转换法:
可读性较低
*/

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int a)
//    {
//        cout << "构造函数调用" << endl;
//    }
//    Person(const Person& p)
//    {
//        cout << "拷贝构造函数调用" << endl;
//    }
//    ~Person()
//    {
//        cout << "析构函数调用" << endl;
//    }
//};
//int main()
//{
//    Person p(10);
//    Person p2(p);//括号法
//
//    Person p3 = Person(10);
//    Person p4 = Person(p3);//显示法 
//    //Person(10);//匿名对象——当前执行完成后，立即释放
//   
//    //隐式法
//    Person p5 = 10;//Person p5 = Person(10);
//    Person p6 = p5;//Peraon p6 = Person(p5);
//
//    cout << endl;
//    return 0;
//}







//拷贝构造函数的调用时机
/*
1.用已经创建好的对象来初始化新的对象
2.用值传递的方式给函数的参数传值(值传递的本质就是进行拷贝)
3.以值的方式返回局部对象
*/






//构造函数的调用规则
/*
1.编译器会给一个类默认添加四个函数(1)默认构造——空实现(2)析构函数——空实现(3)拷贝构造——值拷贝(4)operator=赋值运算符重载——值拷贝
2.若我们自己提供了有参构造函数，编译器就不会提供默认构造函数，但依然会提供拷贝构造函数
3.若我们提供了拷贝构造函数，编译器就不会提供其他构造函数
*/

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person()
//    {
//        cout << "默认构造函数调用" << endl;
//    }
//    Person(int age)
//    {
//        m_Age = age;
//        cout << "有参构造函数调用" << endl;
//    }
//    //Person(const Person& p)//编译器默认添加拷贝构造函数，函数内值拷贝
//    //{
//    //    m_Age = p.m_Age;
//    //    cout << "拷贝构造函数调用" << endl;
//    //}
//    ~Person()
//    {
//        cout << "析构函数调用" << endl;
//    }
//    int m_Age =10;
//};
//int main()
//{
//    Person p1;
//    p1.m_Age = 18;
//    Person p2(p1);
//    cout << p2.m_Age << endl;//18
//    return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    A() = default;//让编译器提供一个无参构造，效率比用户自行提供更高
//    //default只能修饰类默认添加的四个函数
//
//    A(int a)//提供了有参构造，不提供无参构造
//    {
//        cout << a << endl;
//    }
//
//    A(const A& a);//声明
//
//    A& operator=(const A& a) = delete;//用"=delete"修饰，此函数被禁用
//    //=delete可运用于各种成员函数
//};
//A::A(const A& a) = default;//可以放置到类的外部
//int main()
//{
//    A a;
//    A a2 = a;
//    a2 = a;//调用赋值运算重载函数,error
//    return 0;
//}









//深浅拷贝问题
//若有属性开辟在堆区，利用编译器提供的拷贝函数会调用浅拷贝带来的析构函数，产生重复释放堆区内存的问题
//利用深拷贝来解决浅拷贝问题(自己提供拷贝构造函数，实现深拷贝)
//#include<iostream>
//#include<cstdlib>
//using namespace std;
//class Person
//{
//public:
//    Person(const char* name, int age)
//    {
//        m_name = (char*)malloc(sizeof(name));
//        if (m_name == NULL)
//        {
//            return;
//        }
//        strcpy(m_name, name);
//        m_age = age;
//    }
//    Person(const Person& p)//自行提供深拷贝函数，否则容易因浅拷贝而二次释放空间
//    {
//        m_name = (char*)malloc(sizeof(p.m_name));
//        if (m_name == NULL)
//        {
//            return;
//        }
//        strcpy(m_name, p.m_name);
//        m_age = p.m_age;
//    }
//    char* m_name;
//    int m_age = 0;
//    ~Person()//结束时释放堆区空间
//    {
//        if (m_name != NULL)
//        {
//            free(m_name);
//            m_name = NULL;
//        }
//    }
//};
//int main()
//{
//    Person p("bjy", 18);
//    cout << "姓名:" << p.m_name << endl;
//    cout << "年龄:" << p.m_age << endl;
//    Person p2(p);//编译器提供了拷贝构造函数会造成二次释放空间
//    cout << "姓名:" << p.m_name << endl;
//    cout << "年龄:" << p.m_age << endl;
//    return 0;
//}










//初始化列表
//可以利用初始化列表，对类中属性进行初始化操作
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    //1.
//    //Person() :m_a(10), m_b(20), m_c(30) {}//初始化列表 用于赋初值
//    //2.
//    Person(int a, int b, int c) :m_a(a), m_b(b), m_c(c) {}
//    int m_a;
//    int m_b;
//    int m_c;
//};
//int main()
//{
//    //1.
//    //Person p;
//    //2.
//    Person p(10, 20, 30);
//    cout << "m_a = " << p.m_a << endl;
//    cout << "m_b = " << p.m_b << endl;
//    cout << "m_c = " << p.m_c << endl;
//    return 0;
//}







//类对象做类中成员
//当其他类对象作为本类成员，先构造其他类对象，再构造自身。析构的顺序则相反。
/*
如下代码结果:
Phone的构造函数调用
Game的构造函数调用
Person的构造函数调用
Person的析构函数调用
Game的析构函数调用
Phone的析构函数调用
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Phone
//{
//public:
//    Phone(string name)
//    {
//        cout << "Phone的构造函数调用" << endl;
//        phonename = name;
//    }
//    string phonename;
//    ~Phone()
//    {
//        cout << "Phone的析构函数调用" << endl;
//    }
//};
//class Game
//{
//public:
//    Game(string gname)
//    {
//        cout << "Game的构造函数调用" << endl;
//        gamename = gname;
//    }
//    string gamename;
//    ~Game()
//    {
//        cout << "Game的析构函数调用" << endl;
//    }
//};
//class Person
//{
//public:
//    Person(string a, string b, string c) :m_name(a), m_phone(b), m_game(c)
//    {
//        cout << "Person的构造函数调用" << endl;
//    }
//    ~Person()
//    {
//        cout << "Person的析构函数调用" << endl;
//    }
//    string m_name;
//    Phone m_phone;
//    Game m_game;
//};
//int main()
//{
//    Person p("张三", "鸭梨", "王者");
//    return 0;
//}





//explicit关键字
/*
注意:
1.explicit用于修饰构造函数(位于构造函数前)，防止隐式转化(强制提高代码的可读性)
2.是针对单个参数的构造函数(或者除了第一个参数以外其余函数都有默认值的多参构造函数)而言
*/





//new创建对象
//delete释放对象及其堆区空间
/*
malloc和new的区别:
1.malloc和free属于库函数;new和delete属于运算符。
2.malloc不会调用构造函数，new会调用构造函数
3.malloc返回void*，需要强转;new返回创建的对象的指针
*/
/*
注意事项:
不要使用void*接收new出来的对象，什么类型的对象使用什么类型的指针接收
*/
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person()
//    {
//        cout << "Person构造函数调用" << endl;
//    }
//    Person(int a)
//    {
//        cout << "Person有参构造函数调用" << endl;
//    }
//    ~Person()
//    {
//        cout << "Person析构函数调用" << endl;
//    }
//};
//int main()
//{
//    Person* p = new Person;//堆区开辟的内存需自己释放
//    delete p;
//
//    //利用new在堆区开辟数组，一定会调用默认构造函数
//    Person* pp = new Person[10];
//    delete[]pp;//加[]，告诉编译器寻找有几个对象
//
//    //在栈上开辟数组，可以没有默认构造函数
//    Person arr[2] = { Person(10) };
//    return 0;
//}























//静态成员

/*
在类定义中，它的成员(包括成员变量和成员函数)可以用关键子static声明为静态的，称为静态成员
不管这个类创建了多少个对象，静态成员只有一个拷贝，这个拷贝被所有属于这个类的对象共享
*/



//静态成员变量
/*
1.静态成员变量必须在类中声明，在类外定义
2.静态成员变量不属于某个对象，在为对象分配空间中不包括静态成员所占空间
3.静态成员变量可以通过类名或对象名来引用
4.所有对象都共享一份数据
5.静态成员变量也受访问权限限制
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    //静态成员变量:编译阶段就分配了内存
//    //类内声明
//    static int m_a;
//};
//int A::m_a = 10;//类外初始化
//int main()
//{
//    //1.通过对象进行访问
//    A a1;
//    cout << "m_a = " << a1.m_a << endl;
//    A a2;
//    a2.m_a = 20;
//    cout << "m_a = " << a1.m_a << endl;
//    //2.通过类名进行访问
//    cout << "m_a = " << A::m_a << endl;
//    return 0;
//}



//静态成员函数
/*
1.所有对象都共享同一个函数
2.静态成员函数可以通过类名或对象名来调用
3.静态成员函数可以访问静态成员变量，但不能访问普通成员变量
4.静态成员函数也受访问权限限制
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    static void fun()
//    {
//        cout << "静态成员函数调用" << endl;
//    }
//};
//int main()
//{
//    //通过对象调用
//    A a1;
//    a1.fun();
//    //通过类名
//    A::fun();
//
//    return 0;
//}













//单例模式

/*
单例模式是一种常见的软件设计模式。在它的核心结构中值包含一个被称为单例的特殊类。通过单例模式可以保证系统中一个类只有一个实例
而且该实例易于外界访问，从而方便对实例个数的控制并节约系统资源。
*/
/*
实现方法:
1.将构造函数私有化，实现不可创建多个对象
2.类内声明一个静态指针，类外进行初始化，该指针为唯一实例。并将其设置为私有权限，防止通过将指针置入NULL导致无法访问
3.在私有权限下提供空实现的拷贝构造函数，防止通过编译器提供的拷贝构造函数实现创建对象
4.公共权限下提供接口，实现访问该对象的功能
5.单例模式下通过new在堆区开辟的空间一般不进行释放(可能多人使用),在程序结束时由系统收回堆区内存
*/

//#include<iostream>
//using namespace std;
//class ChairMan//主席类
//{
//private:
//    //构造函数私有化，不可以创建多个对象
//    ChairMan()
//    {}
//    //防止通过编译器提供的拷贝构造函数实现创建对象
//    ChairMan(const ChairMan&)
//    {}
//    static ChairMan* singleman;//类内声明
//public:
//    //公共只读接口
//    static ChairMan* get()
//    {
//        return singleman;
//    }
//};
//ChairMan* ChairMan::singleman = new ChairMan;//类外初始化对象
//int main()
//{
//    ChairMan* c1 = ChairMan::get();
//    ChairMan* c2 = ChairMan::get();
//    if (c1 == c2)
//    {
//        cout << "c1 = c2" << endl;
//    }
//    else
//    {
//        cout << "c1 != c2" << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//class Printer
//{
//private:
//    Printer()
//    {
//        count = 0;
//    }
//    Printer(const Printer&)
//    {}
//    static Printer* p;
//    int count;//记录打印次数
//public:
//    static Printer* get()
//    {
//        return p;
//    }
//    //打印函数
//    void printtext(string str)
//    {
//        cout << str << endl;
//        count++;
//    }
//    //查看打印次数
//    void look()
//    {
//        cout << "共打印" << count << "次" << endl;
//    }
//};
//Printer* Printer::p = new Printer;
//int main()
//{
//    Printer* p = Printer::get();
//    p->printtext("bjy is the best handsome boy");
//    p->printtext("bjy is the best handsome boy");
//    p->look();
//    p->printtext("bjy is the best handsome boy");
//    p->look();
//    return 0;
//}














//this指针
//this指针的本质:类名* const this(不允许被修改)
/*
this指针指向被调用的成员函数所属的对象
this指针隐式的加在每个成员函数中
不要使用空指针访问(隐式)用到this指针的成员函数
*/
/*
用途:
1.解决名称冲突
2.实现链式编程
*/
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int age)
//    {
//        this->age = age;
//    }
//    Person& Addage(Person& p)
//    {
//        this->age += p.age;
//        return *this;//指向被调用的成员函数所属的对象的指针，解引用为本体对象
//    }
//    int age;
//};
//int main()
//{
//    Person p1(18);
//    Person p2(10);
//    cout << "p1的年龄为:" << p1.age << endl;
//    p1.Addage(p2);
//    cout << "p1的年龄为:" << p1.age << endl;
//    p1.Addage(p2).Addage(p2);//链式编程思想
//    cout << "p1的年龄为:" << p1.age << endl;
//    return 0;
//}





//常对象与常函数
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int age ,int high)
//    {
//        m_age = age;
//        m_high = high;
//    }
//
//    void showage() const//const修饰为常函数(中的this指针)，使得不可修改this指向的值
//    {
//        //m_age = 100;
//        m_high = 180;
//        cout << "年龄为:" << this->m_age << endl;
//        cout << "身高为:" << this->m_high << endl;
//    }
//
//    mutable int m_high;//加上mutable关键字，使得常函数可以修改该成员变量的值，当其作为常对象的属性时也可以被修改
//    int m_age;
//};
//int main()
//{
//    Person p1(18, 10);
//    p1.showage();
//    const Person p2(1, 1);//常对象——其属性不可被修改
//    //常对象最好只调用常函数，普通函数可能修改其属性导致报错
//    p2.showage();
//    return 0;
//}












//友元
/*
类的主要特点之一是数据隐藏，即类的私有成员无法在类的外部(作用域之外)访问。
友元是一种特权，C++允许其访问私有成员。
*/

//1.全局函数做友元函数
//#include<iostream>
//#include<string>
//using namespace std;
//class Building
//{
//    friend void goodfirend(Building* p);//利用firend关键字，声明友元函数
//public:
//    Building()
//    {
//        this->sittingroom = "客厅";
//        this->bedroom = "卧室";
//    }
//public:
//    string sittingroom;//客厅
//private:
//    string bedroom;//卧室
//
//};
////全局函数
//void goodfirend(Building* p)
//{
//    cout << "正在访问" << p->sittingroom << endl;
//    cout << "正在访问" << p->bedroom << endl;
//}
//int main()
//{
//    Building Person;
//    goodfirend(&Person);
//    return 0;
//}


//2.类做为友元类
//#include<iostream>
//#include<string>
//using namespace std;
////类:我的房子
//class Building
//{
//    friend class Goodfriend;
//public:
//    Building()
//    {
//        this->sittingroom = "客厅";
//        this->bedroom = "卧室";
//    }
//    string sittingroom;
//private:
//    string bedroom;
//};
////类:好朋友
//class Goodfriend
//{
//public:
//    Goodfriend()
//    {
//        this->p = new Building;
//    }
//    void visit()
//    {
//        cout << "好朋友正在访问" << p->sittingroom << endl;
//        cout << "好朋友正在访问" << p->bedroom << endl;
//    }
//    Building* p;
//};
//int main()
//{
//    Goodfriend a;
//    a.visit();
//    return 0;
//}


//3.另一个类中的成员函数作为本类友元函数
//将函数类外编写，避免编译器无法识别
//#include<iostream>
//#include<string>
//using namespace std;
//class Building;
////类:好朋友
//class Goodfriend
//{
//public:
//    Goodfriend();
//    void visit();
//
//    Building* p;
//};
////类:我的房子
//class Building
//{
//    friend void Goodfriend::visit();
//public:
//    Building()
//    {
//        this->bedroom = "卧室";
//    }
//private:
//    string bedroom;
//};
//Goodfriend::Goodfriend()
//{
//    this->p = new Building;
//}
//void Goodfriend::visit()
//{
//    cout << "好朋友正在访问" << p->bedroom << endl;
//}
//int main()
//{
//    Goodfriend a;
//    a.visit();
//    return 0;
//}









//数组类封装
//#include<iostream>
//using namespace std;
//class my_arr
//{
//public:
//    my_arr()
//    {
//        cout << "默认构造函数调用" << endl;
//        this->m_num = 100;
//        this->m_size = 0;
//        this->parr = new int[m_num];
//    }
//    my_arr(int num)
//    {
//        cout << "有参构造函数调用" << endl;
//        this->m_num = num;
//        this->m_size = 0;
//       this->parr = new int[m_num];
//    }
//    my_arr(const my_arr& arr)
//    {
//        cout << "拷贝构造函数调用" << endl;
//        this->m_num = arr.m_num;
//        this->m_size = arr.m_size;
//        this->parr = new int[m_num];
//        if (m_num>=m_size)
//        {
//            for (int i = 0; i < m_size; i++)
//            {
//                this->parr[i] = arr.parr[i];
//            }
//        }
//    }
//    //尾插法
//    void pushBack(int val)
//    {
//        this->parr[this->m_size] = val;
//        m_size++;
//    }
//    //根据位置设置数据
//    void setdata(int pos,int val)
//    {
//        this->parr[pos] = val;
//    }
//    //根据位置获取数据
//    int getdata(int pos)
//    {
//        return this->parr[pos];
//    }
//    //获取数组容量
//    int getnum()
//    {
//        return m_num;
//    }
//    //获取数组大小
//    int getsize()
//    {
//        return m_size;
//    }
//    //析构函数
//    ~my_arr()
//    {
//        cout << "析构函数调用" << endl;
//        if (this->parr != NULL)
//        {
//            delete[] parr;
//            this->parr = NULL;
//        }
//    }
//private:
//    int m_num;//数组的最大下标
//    int m_size;//数组当前的大小
//    int* parr;//指向开辟在堆区的空间
//};
//int main()
//{
//    int i;
//    my_arr arr;
//    for (i = 0; i < 10; i++)
//    {
//        arr.pushBack(i);
//    }
//    for (i = 0; i < arr.getsize(); i++)
//    {
//        cout << arr.getdata(i) << endl;
//    }
//
//    my_arr arr2(arr);
//    for (i = 0; i < arr2.getsize(); i++)
//    {
//        cout << arr2.getdata(i) << endl;
//    }
//
//    return 0;
//}




//字符串类封装
//#include<iostream>
//#include<cstring>
//using namespace std;
//class Mystring
//{
//    friend ostream& operator<<(ostream& cout, Mystring& p);
//    friend istream& operator>>(istream& cin, Mystring& p);
//public:
//    Mystring(const char* str)
//    {
//        this->pstring = new char[strlen(str)+1];
//        strcpy(this->pstring, str);
//        this->m_size = strlen(str);
//    }
//    Mystring(const Mystring& p)
//    {
//        this->pstring = new char[strlen(p.pstring)+1];
//        strcpy(this->pstring, p.pstring);
//        this->m_size = p.m_size;
//    }
//    //重载=(1)
//    Mystring& operator=(const char* p)
//    {
//        if (this->pstring != NULL)
//        {
//            delete[] this->pstring;
//        }
//        this->pstring = new char[strlen(p) + 1];
//        strcpy(this->pstring, p);
//        this->m_size = strlen(p);
//        return *this;
//    }
//    //重载=(2)
//    Mystring& operator=(const Mystring& p)
//    {
//        if (this->pstring != NULL)
//        {
//            delete[] this->pstring;
//        }
//        this->pstring = new char[strlen(p.pstring) + 1];
//        strcpy(this->pstring, p.pstring);
//        this->m_size = strlen(p.pstring);
//        return *this;
//    }
//    //重载[]
//    char& operator[](int index)
//    {
//        return this->pstring[index];
//    }
//    //重载+实现字符串拼接(1)
//    Mystring operator+(const char* str)
//    {
//        int newsize = this->m_size + strlen(str) + 1;
//        char* temp = new char[newsize];
//        memset(temp, 0, newsize);//清空
//        strcat(temp, this->pstring);
//        strcat(temp, str);
//        Mystring newstring(temp);
//        delete[]temp;
//        return newstring;
//    }
//    //+(2)
//    Mystring operator+(Mystring& p)
//    {
//        int newsize = this->m_size + strlen(p.pstring) + 1;
//        char* temp = new char[newsize];
//        memset(temp, 0, newsize);//清空
//        strcat(temp, this->pstring);
//        strcat(temp, p.pstring);
//        Mystring newstring(temp);
//        delete[]temp;
//        return newstring;
//    }
//    //重载==进行字符串的比较(1)
//    bool operator==(const Mystring& p)
//    {
//        int ret = strcmp(this->pstring, p.pstring);
//        if (ret == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//    //==(2)
//    bool operator==(const char* str)
//    {
//        int ret = strcmp(this->pstring, str);
//        if (ret == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//    ~Mystring()
//    {
//        if (this->pstring != NULL)
//        {
//            delete[] this->pstring;
//            this->pstring = NULL;
//        }
//    }
//private:
//    char* pstring;//维护在堆区开辟的字符数组
//    int m_size;//字符串的长度(不统计'\0')
//};
////重载<<用于输出
//ostream& operator<<(ostream& cout, Mystring& p)
//{
//    cout << p.pstring << endl;
//    return cout;
//}
////重载>>用于输入
//istream& operator>>(istream& cin, Mystring& p)
//{
//    char buff[1024];//开辟临时数组用作缓冲区
//    if (p.pstring != NULL)
//    {
//        delete[] p.pstring;
//        p.pstring = NULL;
//    }
//    cin >> buff;
//    p.pstring = new char[strlen(buff) + 1];
//    strcpy(p.pstring, buff);
//    p.m_size = strlen(buff);
//    return cin ;
//}







//委托构造
/*
委托构造函数可以使用当前类的其他构造函数来帮助当前构造函数初始化.
1.委托构造一定要通过初始化列表的方式
2.当被委托的构造函数的函数体中如果有代码，那么会先执行完函数体的代码，才会回到发出委托请求的构造函数
3.不要形成委托环。
 在构造函数较多时,我们可能拥有多个委托构造函数,而一些目标构造函数很可能也是委托构造函数,
 就很可能在委托构造函数中形成循环链状的委托构造关系
 4.若在委托构造函数中使用try，可以捕获目标构造函数中抛出的异常
*/

//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//    Test():Test(18,'b')
//    {
//        cout << "调用无参构造函数" << endl;
//    }
//    Test(int x):m_x(x){}
//    Test(char y):m_y(y){}
//    Test(int x, char y) :m_x(x), m_y(y) { cout << "调用有参构造函数" << endl; }
//
//    int m_x = 0;
//    char m_y = 0;
//};
//int main()
//{
//    Test t;
//    cout << t.m_x << endl;
//    cout << t.m_y << endl;
//    return 0;
//}
/*
输出:
调用有参构造函数
调用无参构造函数
18
b
*/



//委托环(错误)
//#include<iostream>
//using namespace std;
//class Foo
//{
//public:
//    Foo(int i) : Foo('c') { type = i; }
//    Foo(char c) : Foo(1) { name = c; }
//private:
//    int type;
//    char name;
//};



//error
//#include <iostream> 
//using namespace std;
//class Foo
//{
//public:
//    Foo(int i)try:Foo(i, 'c'){}
//    catch (...)
//    {
//        cout << "捕获int类型异常" << endl;
//    }
//private:
//    Foo(int i, char c)
//    {
//        this->type = i;
//        this->name = c;
//        cout << "抛出异常" << endl;
//        throw 0;
//    }
//    int type;
//    char name;
//};
//int main()
//{
//    Foo f(1);
//    return 0;
//}


