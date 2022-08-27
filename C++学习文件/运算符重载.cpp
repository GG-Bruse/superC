#define _CRT_SECURE_NO_WARNINGS

//运算符重载

/*
运算符重载就是对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
对于内置的数据类型的表达式的运算符是不可以改变的
关键字:operator
语法:
函数的参数个数取决于两个因素
1.运算符是一元(一个参数)还是二元的(两个参数)
2.运算符被定义为全局函数(对于一元是一个参数，对于二元是两个参数)还是成员函数(对于一元没有参数，对于二元是一个参数，此时该类的对象用作左耳参数)
*/


//加号运算符重载
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    A() {}//提供默认构造函数被
//    A(int a, int b):m_a(a),m_b(b){}//通过列表进行初始化
//    int m_a;
//    int m_b;
//    //1.利用成员函数实现加号运算符重载
//    /*A operator+(A& a)
//    {
//        A temp;
//        temp.m_a = this->m_a + a.m_a;
//        temp.m_b = this->m_b + a.m_b;
//        return temp;
//    }*/
//};
////2.利用全局函数实现加号运算符重载
//A operator+(A& a1, A& a2)
//{
//    A temp;
//    temp.m_a = a1.m_a + a2.m_a;
//    temp.m_b = a1.m_b + a2.m_b;
//    return temp;
//}
//int main()
//{
//    A a1(10, 10);
//    A a2(1, 2);
//    //简化调用方法:
//    A a3 = a1 + a2;
//    //本质调用方法
//    //1.
//    //A a3 = a1.operator+(a2);
//    //2.
//    //A a3 = operator+(a1, a2);
//    cout << a3.m_a << endl << a3.m_b << endl;
//    return 0;
//}





//左移运算符重载
//#include<iostream>
//using namespace std;
//class Person
//{
//    friend ostream& operator<<(ostream& out, Person& p);
//public:
//    Person(int a,int b)
//    {
//        this->m_a = a;
//        this->m_b = b;
//    }
//private:
//    int m_a;
//    int m_b;
//};
//ostream& operator<<(ostream &out,Person& p)//链式
//{
//    out << "m_a = " << p.m_a << endl << "m_b = " << p.m_b << endl;
//    return out;
//}
//int main()
//{
//    Person p(1, 2);
//    cout << p << endl;
//    return 0;
//}








//前置后置自增(自减)运算符重载
//#include<iostream>
//using namespace std;
//class Myint
//{
//    friend ostream& operator<<(ostream& cont, Myint& a);
//public:
//    Myint()
//    {
//        m_num = 0;
//    }
//    //前置++重载
//    Myint& operator++()
//    {
//        this->m_num++;
//        return *this;
//    }
//    //后置++重载
//    Myint& operator++(int)//使用占位参数区别前后置++，使之可以发生函数重载
//    {
//        static Myint temp = *this;
//        this->m_num++;
//        return temp;
//    }
//private:
//    int m_num;
//};
//ostream& operator<<(ostream& cont, Myint& a)
//{
//    cout << a.m_num;
//    return cout; 
//}
//int main()
//{
//    Myint int1;
//    ++int1;
//    cout << ++int1 << endl;
//
//    cout << int1++ << endl;//后置不可实现链式
//    cout << int1 << endl;
//    return 0;
//}





//指针运算符重载
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int age)
//    {
//        cout << "有参构造函数调用" << endl;
//        m_age = age;
//    }
//    void showage()
//    {
//        cout << "年龄为:" << this->m_age << endl;
//    }
//    ~Person()
//    {}
//    int m_age;
//};
////利用智能指针管理new出来的内存的释放
//class Smartpoint
//{
//public:
//    Smartpoint(Person* p)
//    {
//        this->m_person = p;
//    }
//    //重载->运算符
//    Person* operator->()
//    {
//        return this->m_person;
//    }
//    //重载*运算符
//    Person& operator*()
//    {
//        return *m_person;
//    }
//    ~Smartpoint()
//    {
//        if (this->m_person != NULL)
//        {
//            //cout << "析构函数调用" << endl;
//            delete this->m_person;
//        }
//    }
//private:
//    Person* m_person;
//};
//int main()
//{
//    Smartpoint sp(new Person(18));
//    sp->showage();
//    (*sp).showage();
//    return 0;
//}







//赋值运算符重载(避免因浅拷贝导致程序崩溃)
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(const char* name,int age)
//    {
//        this->m_name = new char[strlen(name)+1];
//        strcpy(this->m_name ,name);
//        this->m_age = age;
//    }
//    //重载=
//    Person& operator=(const Person &p)
//    {
//        if (this->m_name!= NULL)
//        {
//            //delete []this->m_name;
//        }
//        this->m_name = new char[strlen(p.m_name)+1];
//        strcpy(this->m_name, p.m_name);
//        this->m_age = p.m_age;
//        return *this;
//    }
//    ~Person()
//    {
//        if (this->m_name != NULL)
//        {
//            delete[]this->m_name;
//            this->m_name = NULL;
//        }
//    }
//    char* m_name;
//    int m_age;
//};
//int main()
//{
//    Person p1("Tom", 18);
//    Person p2("Jerry", 10);
//    Person p3("", 0);
//    p3 = p2 = p1;
//    cout << "姓名:" << p1.m_name << " " << "年龄:" << p1.m_age << endl;
//    cout << "姓名:" << p2.m_name << " " << "年龄:" << p2.m_age << endl;
//    cout << "姓名:" << p3.m_name << " " << "年龄:" << p3.m_age << endl;
//    return 0;
//}





//[]运算符重载
//#include<iostream>
//using namespace std;
//class my_arr
//{
//public:
//    my_arr()
//    {
//        cout << "默认构造函数调用" << endl;
//        this->m_num = 100;
//        this->parr = new int[m_num];
//    }
//    //重载
//    int& operator[](int index)
//    {
//        return this->parr[index];
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
//    int* parr;//指向开辟在堆区的空间
//};
//int main()
//{
//    int i;
//    my_arr arr;
//    for (i = 0; i < 10; i++)
//    {
//        arr[i]=i;
//    }
//    for (i = 0; i < 10; i++)
//    {
//        cout << arr[i]<< endl;
//    }
//    return 0;
//}





//关系运算符重载
//#include<iostream>
//#include<cstring>
//using namespace std;
//class Person
//{
//public:
//    Person(string name,int age)
//    {
//        m_name = name;
//        m_age = age;
//    }
//    //==重载
//    bool operator==(Person& p)
//    {
//        return (this->m_name == p.m_name && this->m_age == p.m_age);
//    }
//    //!=重载
//    bool operator !=(Person& p)
//    {
//        return !(this->m_name == p.m_name && this->m_age == p.m_age);
//    }
//    string m_name;
//    int m_age;
//};
//int main()
//{
//    Person p1("Tom", 18);
//    Person p2("Jerry", 10);
//    if (p1 == p2)
//    {
//        cout << "p1 == p2" << endl;
//    }
//    else
//    {
//        cout << "p1 != p2" << endl;
//    }
//    if (p1 != p2)
//    {
//        cout << "p1 != p2" << endl;
//    }
//    else
//    {
//        cout << "p1 == p2" << endl;
//    }
//    return 0;
//}








//函数调用运算符重载
//#include<iostream>
//#include<string>
//using namespace std;
//class Myprint
//{
//public:
//    void operator()(string str)
//    {
//        cout << str << endl;
//    }
//};
//int main()
//{
//    Myprint print;
//    //原始调用方法:print.operator()("bjy");
//    print("bjy");//仿函数 本质是一个对象(函数对象)
//    return 0;
//}






//重载总结:
/*
1.不要重载逻辑与(&&)和逻辑或(||)
原因:无法在这两种情况下实现内置操作符的完整语义(逻辑短路)
2.= [] -> 操作符只能通过成员函数进行重载
3.<<和>>只能通过全局函数配合友元函数进行重载
4.一元运算符建议使用成员函数重载
*/
