#define _CRT_SECURE_NO_WARNINGS

//初识C++

//面向对象三大特性:
//封装、继承、多态

//#include<iostream>//包含标准输入输出流
//using namespace std;//命名空间 
////对头文件的又一次细分，优化编译，用不到就不包含
//int main()
//{
//	//c out(输出)、c in(输入)
//	cout << "bjy is the best handsome.\n" << "hello world!\n";
//	cout << 3.14 << 'A' << "abcd" << 10;//泛型:自动推理数据类型
//	return 0;
//}


////#include<stdlib.h>
//#include<cstdlib>//C++风格
//using namespace std;
//int main()
//{
//    //char str[20] = "tasklist &pause";
//    char str[20]{ "tasklist &pause" };//C++风格
//    system(str);
//    return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//    char ch;
//    double db;
//    int num;
//    cin >> num>>db >> ch;
//    cout << num << db << ch << endl;//endl结束并换行
//    //cin cout 都遵循泛型
//    return 0;
//}














                                                       //双冒号作用域运算符
//::代表作用域 
/*
若前面什么都不添加，则代表全局作用域
若前面有内容，则代表内容的作用域
*/
//#include<iostream>
//using namespace std;
//int atk = 1000;
//void test()
//{
//    int atk = 2000;
//    cout << "atk=" << atk << endl;//2000
//    cout << "全局atk=" << ::atk << endl;//1000
//}
//int main()
//{
//    test();
//    return 0;
//}















                                                       //namespace命名空间
//1.解决名称冲突
//#include<iostream>
//using namespace std;
//namespace kingglory
//{
//    void goatk();
//}
//namespace LOL
//{
//    void goatk();
//}
//void kingglory::goatk()
//{
//    cout << "王者荣耀攻击实现" << endl;
//}
//void LOL::goatk()
//{
//    cout << "LOL攻击实现" << endl;
//}
//int main()
//{
//    kingglory::goatk();//王者荣耀攻击实现
//    LOL::goatk();//LOL攻击实现
//    return 0;
//}



//2.命名空间可以存放变量、函数、结构体、类等内容
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int a;
//    void func();
//    struct S {};
//    class animal{};
//}
//int main()
//{
//    return 0;
//}



//3.命名空间必须声明在全局作用域下


//4.命名空间可以嵌套
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int a = 10;
//    namespace B
//    {
//        int a = 20;
//    }
//}
//int main()
//{
//    cout << "A空间下的a=" << A::a << endl;
//    cout << "B空间下的a=" << A::B::a << endl;
//    return 0;
//}



//5.命名空间是开放的，可以随时添加新成员
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int a = 100;
//}
//namespace A
//{
//    int b = 100;
//}
////两个命名空间进行合并
//int main()
//{
//    cout << "A空间下的a=" << A::a << endl;
//    cout << "A空间下的b=" << A::b << endl;
//    return 0;
//}



//6.命名空间可以是匿名的
//#include<iostream>
//using namespace std;
//namespace
////当命名空间为匿名的,其中变量默认为静态变量,相当于static int a =1;static int b=2;
//{
//    int a = 1;
//    int b = 2;
//}
//int main()
//{
//    cout << a << endl;
//    cout << ::b << endl;
//    return 0;
//}



//7.命名空间可以有多个名字
//#include<iostream>
//using namespace std;
//namespace verylong
//{
//    int a = 10;
//}
//int main()
//{
//    namespace veryshort = verylong;
//    cout << verylong::a << endl;
//    cout << veryshort::a << endl;
//    return 0;
//}
















                                                           //using

//using声明
//声明的命名空间不可有与局部变量相同名字的变量
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int suwukongID = 1;
//}
//int main()
//{
//    //using声明
//    using A::suwukongID;//声明需要使用空间A的suwukongID变量
//    cout << suwukongID << endl;
//    return 0;
//}



//using编译指令
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int suwukongID = 1;
//}
//void test()
//{
//    int suwukongID = 2;
//    using namespace A;//相当于打开命名空间A
//    cout << A::suwukongID << endl;//1
//    cout << suwukongID << endl;//2 若没有具体指定，局部变量优先于using指令
//}
//int main()
//{
//    test();
//    return 0;
//}



//起别名
//#include<iostream>
//#include<type_traits>
//using namespace std;
//using m_int = int;
//int main()
//{
//    //判断2个类型是否一致，若是返回真，否则为假
//    cout << is_same<int, m_int>::value << endl;//模板
//    return 0;
//}
















                                                     //C++对C语言的扩展与增强
//1.全局变量的检测增强


//2.函数的检测增强(函数类型、返回值、形参、实参等)


//3.类型转换检测增强


//4.struct增强
/*
C语言中的结构体不允许有函数，而C++中的结构体中可以有函数
C语言中创建结构体变量时，必须加关键字struct;而C++中可以简化关键字struct
*/


//5.bool类型的扩展
/*
C语言中不存在bool类型，而C++中存在
bool类型 true——真(1) false——假(0) 大小为1个字节
*/
//#include<iostream>
//using namespace std;
//int main()
//{
//    bool flag1 = true;
//    bool flag2 = 100;
//    cout << flag1 << endl;//1
//    cout << flag2 << endl;//将所有非0的数都转换为1
//    cout << sizeof(bool) << endl;
//    return 0;
//}


//6.三目运算符的增强
//C语言中的三目运算符返回的是值，而C++中返回的是变量
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 10;
//    int b = 20;
//    cout << (a > b ? a : b) << endl;//20
//    a > b ? a : b = 100;//C语言中不允许这种语句
//    cout << a << endl;//10
//    cout << b << endl;//100
//    return 0;
//}


//7.const增强
/*
const修饰的变量都不可直接修改
(1)C语言中，const修饰的全局变量不可以通过指针修改，其受到常量区的保护。
  const修饰的局部变量可以通过指针修改，其分配在栈上，为具有常属性的变量。
(2)C++中，const修饰的全局变量不可以通过指针修改，其受到常量区的保护。
   const修饰局部变量不可以通过指针修改，相当于常量，甚至可进行数组的初始化。
*/
/*
只要对变量本身进行了内存分配，就可以通过指针找到并修改
(1)对const修饰的变量取地址，会拷贝备份并为备份分配临时内存，所以用指针无法修改。
(2)使用普通变量对const修饰的变量进行初始化，可以使用指针进行修改。
(3)对于const修饰自定义数据类型变量，可以使用指针进行修改。
*/
/*
C语言中，const修饰的全局变量默认是外部链接属性，声明(extern)后可以使用。
C++中，const修饰的全局变量默认是内部链接属性，可以在变量前加上extern提高其作用域。
*/













//引用
//引用的本质在C++内部实现是一个指针

//引用的目的:起别名(a和b操作同一块内存)   
//引用必须初始化赋值且一旦初始化后就不能指向别的内存
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 10;
//    int& b = a;
//    b = 100;
//    cout << "a = " << b << endl;
//    return 0;
//}


//对数组建立引用
//#include<iostream>
//using namespace std;
//int main()
//{
//    int arr[10] = { 0 };
//    int(&brr)[10] = arr;
//    int i;
//    for (i = 0; i < 10; i++)
//    {
//        arr[i] = i;
//    }
//    for (i = 0; i < 10; i++)
//    {
//        cout << brr[i] << " ";
//    }
//    return 0;
//}

/*
引用的注意事项:
1.引用的必须是一块合法的内存空间。
2.不要返回局部、临时变量的引用(内存空间会被释放)
3.若函数返回的是引用，那么函数的调用可以作为左值
*/



//指针的引用
//若要使用高级指针，可以直接使用同级指针的引用进行代替，从而简化指针的用法
//#include<iostream>
//using namespace std;
//struct Person
//{
//    int age;
//};
//void test(Person* &pp)
//{
//    pp = (Person*)malloc(sizeof(Person));
//    if (pp != NULL)
//    {
//        pp->age = 18;
//    }
//}
//int main()
//{
//    Person* p = NULL;
//    test(p);
//    cout << p->age << endl;
//    free(p);
//    p = NULL;
//    return 0;
//}



//常量的引用
//#include<iostream>
//using namespace std;
//int main()
//{
//    //int& ref = 10;
//    //不允许,引用的必须是一块合法的内存空间
//    const int& ref = 10;
//    //加了const后，相当于int temp=10;const int& ref=temp;(可以通过指针修改)
//    return 0;
//}

//#include<iostream>
//using namespace std;
//void test(const int& as)//修饰形参，防止由于误操作导致变量的值被修改
//{
//    cout << as << endl;
//}
//int main()
//{
//    int a = 10;
//    test(a);
//    return 0;
//}












                                                       //参数的传递方式

//1.值传递(不改变原始值)
//#include<iostream>
//using namespace std;
//void Swap(int a,int b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    Swap(a, b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    return 0;
//}


//址传递
//#include<iostream>
//using namespace std;
//void Swap(int* pa, int* pb)
//{
//    int temp = *pa;
//    *pa = *pb;
//    *pb = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    Swap(&a, &b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    return 0;
//}


//引用传递
//#include<iostream>
//using namespace std;
//void Swap(int& a,int& b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    Swap(a, b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    return 0;
//}

















                                                         //内联函数(inline)
/*
内联函数本质上还是一个真正的函数，其具有普通函数的所有行为。

内联函数和普通函数的区别在于：
当编译器处理调用内联函数的语句时，不会将该语句编译成函数调用的指令，而是直接将整个函数体的代码插人调用语句处，
就像整个函数体在调用处被重写了一遍一样。
有了内联函数，就能像调用一个函数那样方便地重复使用一段代码，而不需要付出执行函数调用的额外开销。
使用内联函数会使最终可执行程序的体积增加。以时间换取空间，或增加空间消耗来节省时间

优点:解决了宏的缺陷，同时具有宏的优势，以空间换时间


注意:
1.函数体和声明必须结合在一起，否则编译器还会将其作为普通函数对待
2.为定义内联函数，通常必须加上一个inline关键字，但在类内部定义内联函数时不是必须的，任何在类内部定义的函数默认为内联函数
3.C++内联编译有一些限制，某些情况下编译器可能考虑不会将函数进行内联编译:
    (1)不能存在任何形式的循环语句
    (2)不能存在过多的条件判断语句
    (3)函数体不能过于庞大(没有明确标准)
    (4)不能对函数进行取址操作
4.内联仅仅是给编译器的一个建议，编译器不一定会接受。若你没有将函数声明为内联函数，编译器也可能将该函数看作内联函数
*/



//使用方法与普通函数基本相同
//#include<iostream>
//#include<string>
//using namespace std;
//inline int func(int,int);//声明
//inline int func(int a,int b)//定义
//{
//    return a + b;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    int ret = func(a, b);
//    cout << ret << endl;
//    return 0;
//}












                                                      //函数的默认参数和占位参数

//默认参数(在形参中赋值)
//函数的声明和定义中有且只有一个提供默认参数
//#include<iostream>
//using namespace std;
//int fun(int a = 10, int b = 10)
//{
//    return a + b;
//}
//int main()
//{
//    cout << fun() << endl;//20
//    cout << fun(20,10) << endl;//30(一旦传参，就不取用默认参数)
//    return 0;
//}



//占位参数(只写一个类型进行占位，调用时必须传入占位值)
//占位参数也可以有默认值
//#include<iostream>
//using namespace std;
//void fun(int a,int)
//{}
//int main()
//{
//    fun(10,20);
//    return 0;
//}

















                                                             //函数重载
/*
在传统C语言中，程序中不允许出现同名的函数。而在C++中可以出现同名函数，这种现象被称为函数重载。
函数重载的条件:
(1)同一作用域下并且名称相同(否则没必要重载)
(2)参数个数不同
(3)参数类型不同
(4)参数顺序不同
*/
/*
注意事项:
1.函数的返回值不能作为重载条件
2.加const和不加const的引用也可以作为重载条件
3.函数重载遇到默认参数时要避免二义性
*/

//#include<iostream>
//using namespace std;
//void A()
//{
//    cout << "函数A()调用" << endl;
//}
//void A(int a)
//{
//    cout << "函数A(int a)调用" << endl;
//}
//int main()
//{
//    A(1);//函数A(int a)调用
//    A();//函数A()调用
//    return 0;
//}

//#include<iostream>
//using namespace std;
//void A(int& a)
//{
//    cout << "函数A(int& a)调用" << endl;
//}
//void A(const int& a)
//{
//    cout << "函数A(const int& a)调用" << endl;
//}
//int main()
//{
//    int a = 10;
//    A(a);//函数A(int& a)调用
//    A(1);//函数A(const int& a)调用
//    return 0;
//}
















                                                        //extern "C"
/*
在C++中存在函数重载，会修饰函数名。若函数定义存在于C语言文件中，C++文件中的main函数无法调用，产生链接失败。

解决:
(1)在main文件中:
extern "C" void show();//告诉编译器对show函数使用C语言的方式链接

(2)在头文件中:
#ifdef __cplusplus
extern "C" {
#enddef
…………
…………
#ifdef __cplusplus
}
#endif
*/
















//auto C++11
/*
在C中，auto修饰局部变量，局部变量也称auto变量(自动变量)

在c++11中，auto根据用户初始化内容自动推导类型
*/

/*
注意:
1.定义变量时必须初始化,auto通过初始化的值进行类型推导
2.部分编译器不支持函数形参为auto变量(vs不支持，Qt支持)
3.auto变量不可作为自定义类型的成员变量,即使初始化也不行
4.不可创建auto类型的数组
5.模板实例化类型不可是auto类型
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//double test()
//{
//    return 1.1;
//}
//struct Person
//{
//    int age;
//};
//class Student
//{
//public:
//    Student(const char* name ,int age)
//    {
//        this->m_name = (char*)name;
//        this->m_age = age;
//    }
//    char* m_name;
//    int m_age;
//};
//void func(vector<int>& temp)
//{
//    for (auto i = temp.begin(); i != temp.end(); ++i);//变量i的类型为vector<int>::iterator迭代器
//}
//int main()
//{
//    auto a = 1;//变量a的类型为int
//
//    auto b = test();//变量b的类型为double
//
//    Person p1 = {0};
//    auto p2 = p1;//p2的类型为Person
//
//    Student s("bjy",18);
//    auto sb = s;//对象sb类型为Student
//
//    vector<int>v;
//    func(v);
//
//    return 0;
//}















                                                            //decltype
//获取变量的类型

/*
 auto并不适用于所有的自动类型推导场景,在某些特殊情况下auto用起来非常不方便,甚至压根无法使用,所以 decltype 关键字也被引入到 C++11 中。
 auto和decltype关键字都可以自动推导出变量的类型,但它们的用法是有区别的:auto varname = value;
 decltype(exp)varname = value; 其中，varname 表示变量名，value 表示赋给变量的值，exp 表示一个表达式.
*/

//#include<iostream>
//#include<typeinfo>
//using namespace std;
//int main()
//{
//    int i;
//    decltype(i)j = 0;//利用i的类型定义一个变量j
//    cout << typeid(j).name() << endl;
//
//    float a = 2;
//    double b = 1;
//    decltype(a + b)c = 1.2;//c为double类型
//    cout << c << endl;
//
//    enum {A,B,C}flag;//匿名的枚举变量
//    decltype(flag)flag2;//通过类型推导，可以定义与匿名变量相同类型的变量
//
//    return 0;
//}















                                                            //追踪返回类型
//返回类型后置:在函数名和参数列表后面指定返回类型

//#include<iostream>
//using namespace std;
//int func1(int a, double b)
//{
//    return a + b;
//}
//auto func2(int a, double b)->int//指定特定的返回类型
//{
//    return a + b;
//}
//auto func3(int a, double b)->decltype(a+b)//根据返回的数据自动识别返回类型
//{
//    return a + b;
//}
//
//template<class T1, class T2>
//auto mul(T1& t1, T2& t2)->decltype(t1*t2)
//{
//    return t1 * t2;
//}
//
//int main()
//{
//    auto a = func3(10, 11.1);
//    cout << a << endl;
//
//    auto i = 10;
//    auto j = 11.2;
//    auto ret = mul(i, j);
//    cout << ret << endl;
//
//    return 0;
//}



















                                                             //普通变量的列表初始化

//#include<iostream>
//using namespace std;
//int main()
//{
//    int a{ 1 };
//    cout << a << endl;
//
//    int arr[]{ 1,2,3,4,5,6 };
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//    {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}

//可通过使用列表初始化防止类型收窄造成精度丢失(部分编译器不可)
//错误案列:
//#include<iostream>
//using namespace std;
//int main()
//{
//    int c = 1024;
//    char d = {c};//编译不过   从“int”转换到“char”需要收缩转换
//    cout << "d = " << d << endl;
//    return 0;
//}




















                                                          //基于范围的for循环
//范围必须是可确定的
/*
例如:
形参若接收一个数组，实际上接收其地址，该形参实际为一个指针变量，无法通过该指针变量确定元素个数(即范围)
void func(int arr[])
{
    for (int tmp : arr)//此基于范围的“for”语句需要适合的 "begin" 函数，但未找到

    {
        cout << tmp << endl;
    }
}
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//    int arr[]{ 1,2,3,4,5,6,7,8,9,10 };
//
//    //传统写法
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//
//    //基于范围的写法
//    for (int temp : arr)
//    {
//        cout << temp << " ";
//    }
//    cout << endl;
//    //类似于:
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//    {
//        int temp = arr[i];
//        cout << temp << " ";
//    }
//    cout << endl;
//
//    return 0;
//}















                                                               //静态断言
/*
static_assert(常量表达式，提示字符串)
若第一个参数常量表达式的值为真(true或者非零值)，那么static_assert不做任何事情，就像它不存在一样，
否则会产生一条编译错误，错误位置就是该static_assert语句所在行，错误提示就是第二个参数提示字符串。


说明:
使用static_assert，我们可以在编译期间发现更多的错误，用编译器来强制保证一些契约，并帮助我们改善编译信息的可读性，尤其是用于模板的时候。
static_assert可以用在全局作用域中，命名空间中，类作用域中，函数作用域中，几乎可以不受限制的使用。

编译器在遇到一个static_assert语句时，通常立刻将其第一个参数作为常量表达式进行演算，
但如果该常量表达式依赖于某些模板参数，则延迟到模板实例化时再进行演算，这就让检查模板参数成为了可能。

性能方面，由于是static_assert编译期间断言，不生成目标代码，因此static_assert不会造成任何运行期性能损失。
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//    static_assert(sizeof(void*) != 4, "不支持32位系统");//无法运行,本机默认为x86为32位,sizeof(void*) = 4
//    return 0;
//}















                                                            //nullptr
/*
解决了C++中NULL的二义性的问题，#define NULL ((void*)0),#define NULL 0.
nullptr是nullptr_t 类型的右值常量,专用于初始化空类型指针.nullptr_t是C++11新增加的数据类型可称为“指针空值类型”
*/

//#include <iostream>
//using namespace std;
//
//void isnull(void* c) 
//{
//    cout << "void* c" << endl;
//}
//void isnull(int n) 
//{
//    cout << "int n" << endl;
//}
//int main() 
//{
//    isnull(NULL);//int n
//    isnull(nullptr);//void* c
//
//    //nullptr只能给指针赋值，不能给一个整型变量赋值
//    int* p1 = NULL;
//    int* p2 = nullptr;
//    if (p1 == p2)
//    {
//        cout << "equal" << endl;//执行
//    }
//
//    return 0;
//}
















                                                            //强类型枚举
/*
例:
enum class Status01{Ok,Error};
enum struct Status02{Ok,Error};
enum class Status03:char {Ok,Error};
*/
/*
特点:
(1)强作用域,强类型枚举成员的名称不会被输出到其父作用域,所以不同枚举类型定义同名枚举成员编译不会报重定义错误.
进而使用枚举类型的枚举成员时,必须指明作用域,比如Enum::VAL1,而单独的VAL1则不再具有意义:
(2)转换限制，强类型枚举成员的值不可以与整型发生隐式相互转换。
(3)可以指定成员变量的类型
(4)由于使用枚举成员必须选择作用域，强类型枚举无法匿名
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//    enum class Status01: long long {Ok,Error};
//    cout << sizeof(Status01::Ok) << endl;
//
//    enum struct Status02 : long long { Ok, Error };
//    cout << sizeof(Status02::Ok) << endl;
//    return 0;
//}
















                                                        //常量表达式constexpr
/*
允许一些计算只在编译时进行一次,而不是每次程序运行时,编译器可以进行尺度更大的优化；
*/



//constexpr修饰普通变量
/*
使用 constexpr 修改普通变量时，变量必须经过初始化且初始值必须是一个常量表达式
*/

//#include <iostream>
//using namespace std;
//int main()
//{
//    constexpr int num = 1 + 2 + 3;
//    int url[num] = { 1,2,3,4,5,6 };
//    cout << url[1] << endl;
//    return 0;
//}




//constexpr修饰函数
/*
限制:
1.常量表达式函数必须有返回值(不可以是void函数)
2.常量表达式函数体中只能有一条语句,且该语句必须是return语句。
但不产生实际代码的语句可以在常量表达式函数中使用,如static_assert,using,typedef等
3.return语句中,不能使用非常量表达式的变量、函数,且return的表达式也要是常量表达式
4.常量表达式函数在使用前，必须有定义.  (普通函数在被调用前只要有函数声明就够了，不一定有定义)
*/

//#include<iostream>
//using namespace std;
//int getNum01()
//{
//    return 1;
//}
//const int getNum02()
//{
//    return 2;
//}
//constexpr int getNum03()
//{
//    return 3;
//}
//int main()
//{
//    //枚举成员初始化必须是整型常量
//    
//    //error
//    /*enum {a1 = getNum01(),a2};
//    enum { b1 = getNum02(), b2 };*/
//
//    //ok
//    enum {c1 = getNum03(),c2 };
//
//    return 0;
//}




//constexpr修饰类的构造函数
/*
1.constexpr修饰类的构造函数时,要求该构造函数的函数体必须为空,且采用初始化列表的方式为各个成员赋值时,必须使用常量表达式
2.C++11 标准中,不支持用constexpr修饰带有virtual的成员方法
*/

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//    //构造函数体必须为空，可以使用初始化列表的方式进行初始化
//    constexpr Date(int year, int month, int day) :m_year(year), m_month(month), m_day(day) {}
//
//    constexpr int getYear()const
//    {
//        return m_year;
//    }
//    constexpr int getMonth()const
//    {
//        return m_month;
//    }
//    constexpr int getDay()const
//    {
//        return m_day;
//    }
//private:
//    int m_year;
//    int m_month;
//    int m_day;
//};
//int main()
//{
//    constexpr Date obj{ 2022, 3, 8 };//必须使用常量初始化
//    cout << obj.getYear() << endl;
//    return 0;
//}




//constexpr修饰模板函数
/*
constexpr可以修饰模板函数,但由于模板中类型的不确定性,因此模板函数实例化后的函数是否符合常量表达式函数的要求也是不确定的.
若constexpr修饰的模板函数实例化结果不满足常量表达式函数的要求,则constexpr会被自动忽略,即该函数就等同于一个普通函数.
*/

//#include <iostream>
//using namespace std;
//struct myType {
//    const char* name;
//    int age;
//};
//template<typename T>
//constexpr T dispaly(T t) {
//    return t;
//}
//
//int main()
//{
//    struct myType stu { "zhangsan", 10 };
//    //普通函数
//    struct myType ret = dispaly(stu);
//    cout << ret.name << " " << ret.age << endl;
//    //常量表达式函数
//    constexpr int ret1 = dispaly(10);
//    cout << ret1 << endl;
//    return 0;
//}


















                                                           //自定义字面参量说明

/*
C++11中引入了用户自定义字面量，也叫自定义后缀操作符，即通过实现一个后缀操作符，将申明了该后缀标识的字面量转化为需要的类型。
字面量的返回值并没有被严格限定，可以提供相容类型的返回值

以下参数列表才合法:
char const*
unsigned long long
long double
char const* , size_t
wchar_t const *, size_t
char16_t const *, size_t
char32_t const *, size_t
最后四个对于字符串相当有用，因为第二个参数会自动推断为字符串的长度
*/

//#include<iostream>
//using namespace std;
//unsigned long long operator"" _s(unsigned long long x)
//{
//    return x * 1000;
//}
//
//size_t operator"" _byte(char const* str, size_t len)//自动推断长度
//{
//    return len;
//}
//
//int main()
//{
//    unsigned long long time = 123_s;
//    cout << time << "_ms" << endl;//123000_ms
//
//    cout << "bjy"_byte << endl;//3
//    return 0;
//}











                                                         //原生字符串字面值
/*
原生字符串字面值(raw string literal)使用户书写的字符串“所见即所得”.
原生字符串的声明相当简单,只需在字符串前加入前缀,即字母R,并在引号中使用括号左右标识,就可以声明该字符串字面量为原生字符串了.
*/

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    cout << R"(hello\nworld)" << endl;//使得转义字符失效并被认为为普通字符
//
//    string str = R"(\n\t)";
//    cout << str << endl;
//    return 0;
//}


















                                                        //智能指针
/*
智能指针是一个可以像指针一样工作的对象,有unique_ptr(独占指针),shared_ptr与weak_ptr等智能指针,定义在<memory>中，可以对动态资源进行管理。
保证以构造的对象最终会销毁，即它的析构函数最终会被调用
*/
/*
注意:
1.为了避免内存泄漏,通过智能指针管理的对象应该没有其他的引用指向它们.
2.智能指针不支持指针的算术运算

3.不能使用其他unique_ptr对象的值来初始化一个unique_ptr。也不能将一个unique_ptr对象赋值给另外一个。
这样的操作将导致两个独占指针共享相同对象的所有权

4.unique_ptr代表的是专属所有权，如果想要把一个unique_ptr的内存交给另外一个unique_ptr对象管理。
只能使用std::move转移当前对象的所有权。转移之后，当前对象不再持有此内存，新的对象将获得专属所有权。

5.若unique_ptr指向的是一个对象数组的话,要确保调用delete[]来处理被解除分配的数组,则应该在对象类型后面包含一对空的方括号[]。

*/


//一、unique_ptr
//#include<iostream>
//#include<memory>
//using namespace std;
//int main() 
//{
//    unique_ptr<int> up1(new int(11));
//    cout << "up = " << *up1 << endl;
//
//    //将up1的独占权转移给up2，up1不能再操作堆区空间
//    unique_ptr<int> up2 = std::move(up1);
//    cout << "up2 = " << *up2 << endl;
//
//    //up2.reset();//若为无参作用是显示释放堆区内容
//    up2.reset(new int(22));//若为有参，先释放原来堆区内容,重新给up2绑定一个新的堆区内容
//    cout << "up2 = " << *up2 << endl;
//
//    //释放控制权，但不释放堆区内存
//    int* p = up2.release();
//    cout <<"p = "<< *p << endl;
//    delete p;
//    p = nullptr;
//    return 0;
//}

//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//    //指向数组的独占指针
//    unique_ptr<int[] > up(new int[5]);
//    for (int k = 0; k < 5; k++)
//    {
//        up[k] = k+1;
//    }
//    for (int k = 0; k < 5; k++)
//    {
//        cout << up[k] << " ";
//    }
//    cout << endl;
//    return 0;
//}





//二、shared_ptr
/*
多个shared_ptr智能指针可以共同使用同一块堆内存。由于该类型智能指针在实现上采用的是引用计数机制，
即便有一个shared_ptr指针放弃了堆内存的"使用权"(引用计数减1)也不会影响其他指向同一堆内存的shared_ptr指针(只有引用计数为0时,堆内存才会被自动释放）
*/

//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//    shared_ptr<int> sp1(new int(11));
//    shared_ptr<int>sp2(sp1);//拷贝构造
//
//    cout << "num = " << sp2.use_count() << endl;//打印计数器 2
//
//    sp1.reset();
//    cout << "num = " << sp2.use_count() << endl;//1
//    cout << *sp2 << endl;//11
//
//    sp1.reset();
//    cout << "num = " << sp1.use_count() << endl;//0
//    return 0;
//}




//三、weak_ptr
/*
该类型指针通常不单独使用(没有实际用处),只能和shared_ptr搭配使用。我们可以将weak_ptr视为shared_ptr指针的一种辅助工具,
借助weak_ptr类型指针,我们可以获取shared_ptr指针的一些状态信息,比如有多少指向相同的shared_ptr指针,shared_ptr指针指向的堆内存是否已经被释放等。

当weak_ptr类型指针的指向和某一shared_ptr指针相同时,weak_ptr并不会使所指堆内存的引用计数加1
当weak_ptr指针被释放时,之前所指堆内存的引用计数也不会因此而减1.也就是说,weak_ptr并不会影响所指堆内存空间的引用计数。

weak_ptr<T>模板类中没有重载*和->运算符 , weak_ptr 类型指针只能访问所指的堆内存，而无法修改它
*/

//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//    shared_ptr<int>sp1(new int(11));
//    shared_ptr<int>sp2(sp1);
//    weak_ptr<int>wp = sp1;
//    cout << wp.use_count() << endl;
//
//    shared_ptr<int>sp3 = wp.lock();
//    //lock() 若当前weak_ptr已经过期,则该函数会返回一个空的shared_ptr指针.反之,该函数返回一个和当前weak_ptr指向相同的shared_ptr。
//    cout << wp.use_count() << endl;
//
//    if (sp3 == nullptr)
//    {
//        cout << "堆区空间已经释放" << endl;
//    }
//    else
//    {
//        //cout << *wp << endl;//err
//        cout << *sp3 << endl;//间接访问
//    }
//    return 0;
//}






















