#define _CRT_SECURE_NO_WARNINGS

//异常
/*
传统的错误处理机制：
1. 终止程序，如assert，缺陷：用户难以接受。如发生内存错误，除0错误时就会终止程序。
2. 返回错误码，缺陷：需要程序员自己去查找对应的错误。如系统的很多库的接口函数都是通过把错误码放到errno中，表示错误
实际中C语言基本都是使用返回错误码的方式处理错误，部分情况下使用终止程序处理非常严重的错误

C++中的异常必须有函数进行处理，如果没有任何处理，程序自动中断
*/




//异常的基本语法
/*
1.若有异常则通过throw操作创建一个异常对象并抛出

2.将可能抛出异常的程序放入try块中

3.若在try段执行期间没有引起异常，那么跟在try后的catch字句就不会执行

4.catch语句会根据顺序出现的先后被检查，匹配的catch语句捕获并处理异常(或继续抛出)

5.若匹配的处理未找到，则运行函数terminate将自动被调用，其缺省功能调用abort终止程序

6.处理不了的异常可以在catch的最后一个分支，使用throw向上抛

C++异常处理使得异常的引发和异常的处理不必在一个函数中，这样底层的函数可以着重解决具体问题，而不必过多的考虑异常的处理，
上层调用者可以在适当的位置设计对不同类型异常的处理
*/

//#include<iostream>
//using namespace std;
//int Divsion(int a, int b)
//{
//    if (b == 0)
//    {
//        throw - 1;//抛出一个int类型的异常
//    }
//    return a / b;
//}
//void test()
//{
//    int a = 10;
//    int b = 0;
//    try
//    {
//        Divsion(a, b);
//    }
//    catch (int)
//    {
//        throw;//不处理异常，继续向上抛出异常
//    }
//    catch (...)
//    {
//        cout << "其他类型异常捕获" << endl;
//    }
//}
//int main()
//{
//    try
//    {
//        test();
//    }
//    catch (int)
//    {
//        cout << "main函数中int类型异常捕获" << endl;
//    }
//    return 0;
//}




//栈解旋
/*
从try代码块开始，到throw抛出异常之前，所有栈上的数据都会被释放掉，释放的顺序与创建的顺序相反，这个过程我们称为栈解旋
*/





//异常接口声明
/*
1.为了加强程序的可读性，可以在函数声明中列出可能抛出异常的所有数据类型。
例如:void func throw(A,B,C);该函数能够且只能抛出类型A，B，C及其子类型的异常。
2.若函数声明中没有包含异常接口声明，则此函数可以抛出任何类型的异常
3.一个不抛出任何类型异常的函数可声明为:void func()throw()
4.如果一个函数抛出了它异常接口声明所不允许抛出的异常，unexcepted函数会被调用，该函数默认行为使用terminate函数中断程序
*/

//#include<iostream>
//using namespace std;
//void func()throw(int)
//{
//    throw  1;
//}
//int main()
//{
//    try
//    {
//        func();
//    }
//    catch (int)
//    {
//        cout << "int类型异常捕获" << endl;
//    }
//}










//异常的多态使用
/*
1.提供基类异常类，基类中包含纯虚函数或虚函数
2.派生异常类继承基类，并重写其虚函数或纯虚函数
3.抛出子类对象异常，用父类引用进行捕获
*/
//#include<iostream>
//using namespace std;
//class BaseException
//{
//public:
//    virtual void printError() = 0;
//};
////空指针异常
//class NULLPointException :public BaseException
//{
//public:
//    void printError()
//    {
//        cout << "空指针异常" << endl;
//    }
//};
////越界异常
//class OutofRangeException :public BaseException
//{
//public:
//    void printError()
//    {
//        cout << "越界异常" << endl;
//    }
//};
//void dowork()
//{
//    throw OutofRangeException();
//}
//int main()
//{
//    try
//    {
//        dowork();
//    }
//    catch (BaseException& p)
//    {
//        p.printError();
//    }
//    return 0;
//}







//C++标准异常库<stdexcept>
/*
1.标准库中的异常是有限的
2.在自己的异常类中，可以添加自己的信息
3.建议自己编写的异常类要继承标准异常类
4.当继承标准异常类时，应该重写父类的what函数和虚析构函数
*/

//编写自己的异常类
//#include<iostream>
//#include<stdexcept>
//#include<string>
//using namespace std;
//class MyoutofrangeException: public exception
//{
//public:
//    MyoutofrangeException(const char* str)
//    {
//        //const char*可以隐式类型转换为string,反之不可以
//        this->m_error = str;
//    }
//    MyoutofrangeException(string str)
//    {
//        this->m_error = str;
//    }
//    const char* what() const
//    {
//        //将string转换为const char*
//        return this->m_error.c_str();
//    }
//    string m_error;
//};
//class Person
//{
//public:
//    Person(int age)
//    {
//        if (age < 0 || age>180)
//        {
//            throw MyoutofrangeException("年龄必须在0—180之间");
//        }
//        else
//        {
//            this->m_age = age;
//        }
//    }
//    int m_age;
//};
//int main()
//{
//    try
//    {
//        Person p(181);
//    }
//    catch (exception& a)//catch (MyoutofrangeException& a)
//    {
//        cout << a.what() << endl;
//    }
//    return 0;
//}








//noexcept修饰符
/*
void func() noexcept(常量表达式);

常量表达式的结果会被转换成一个 bool 类型的值,该值为 true,表示函数不能抛出异常,反之则可能抛出异常.
而不带常量表达式的noexcept相当于声明了 noexcept(true)，即不能抛出异常。
*/

//#include<iostream>
//using namespace std;
//void func1()
//{
//    throw 1;
//}
//
//void func2()throw()//限定这个函数不可抛出异常，无法运行
//{
//    throw 2;
//}
//
//void func3()noexcept//限定这个函数不可抛出异常，无法运行
//{
//    throw 3;
//}
//int mian()
//{
//    func1();
//    func2();
//    func3();
//    return 0;
//}

