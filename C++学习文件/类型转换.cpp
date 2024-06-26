#define _CRT_SECURE_NO_WARNINGS

//C++类型转换
/*
类型转换(cast)是将一种类型转换成另一种数据类型
C++的强制转换相对于C强制转换的优点:
能更清晰地表明类型转换的目的
*/




//静态转换(static_cast)
//语法:static_cast<目标类型>(原变量/原对象)
/*
1.用于类层次结构中基类(父类)和派生类(子类)之间指针或引用的转换
(1)进行上行转换(把派生类的指针或引用转换成基类表示——范围减小)是安全的
(2)进行下行转换(把基类指针或引用转换成派生类表示——范围扩大)时，由于没有动态类型检查，是不安全的
2.用与内置基本数据类型之间的转换
*/

//1.父子类中指针或引用转化
//#include<iostream>
//using namespace std;
//class Base {};
//class Son :public Base {};
//class Other {};
//int main()
//{
//    Base* base = NULL;
//    Son* son = NULL;
//    //向下类型转换不安全
//    Son* s = static_cast<Son*>(base);
//    //向上类型转换
//    Base* b = static_cast<Base*>(son);
//    return 0;
//}


//2.内置数据类型转换
//#include<iostream>
//using namespace std;
//void test()
//{
//    char ch = 'a';
//    double d = static_cast<double>(ch);
//    cout << d << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}











                                                    //动态类型转换(dynamic_cast)
//语法:dynamic_cast<目标类型>(原变量/原对象)
/*
dynamic_cast用于父子类层次间的指针或引用上行转换和下行转换(不允许内置类型转换)
在类层次间进行上行转换时，dynamic_cast和static_cast的效果相同
在进行下行转换时，dynamic_cast具有类型检查的功能，比static更安全
*/

//#include<iostream>
//using namespace std;
//class Base {};
//class Son :public Base {};
//class Other {};
//int main()
//{
//    Base* base = NULL;
//    Son* son = NULL;
//    //向下类型转换不安全
//    //Son* s = dynamic_cast<Son*>(base);//不允许使用。如果发生了多态，转换总是安全的，可以进行转换。
//    //向上类型转换
//    Base* b = dynamic_cast<Base*>(son);
//    return 0;
//}









                                                     //常量转换(const_cast)
//语法:const_cast<目标类型>(原变量/原对象)
/*
该操作符用于修改类型的const属性
(1)常量指针被转化成非常量指针，并且仍指向原来的对象(可反向)
(2)常量引用被转换成非常量引用，并且仍指向原来的对象(可反向)
注意:不能对非指针和非引用的变量直接使用const_cast操作符区直接移除它的const
*/

//#include<iostream>
//using namespace std;
//int main()
//{   
//    //指针
//    const int* p = NULL;
//    int* pp = const_cast<int*>(p);
//    const int* ppp = const_cast<const int*>(pp);
//    //引用
//    int num = 10;
//    int& numref = num;
//    const int& ff = const_cast<const int&>(numref);
//    int& fff = const_cast<int&>(ff);
//    return 0;
//}







                                                  //重新解释转换(reinterpret_cast)
/*
这是最不安全的一种转换机制，极有可能出现问题。
主要用于将一种数据类型转换为另一种数据类型。例如:将一个指针转换为一个整型，也可以将一个整型转换为一个指针
*/