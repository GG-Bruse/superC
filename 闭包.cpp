
                                                                    //闭包
/*
有很多种定义，其中一种说法是，闭包是带有上下文的函数。即有状态的函数。

闭包有属于自己的变量, 这些个变量的值是创建闭包的时候设置的, 并在调用闭包的时候, 可以访问这些变量.

函数是代码, 状态是一组变量，将代码和一组变量捆绑(bind)，就形成了闭包，内部包含static变量的函数不是闭包, 
因为这个static变量不能捆绑。你不能捆绑不同的 static 变量。这个在编译的时候已经确定了.

闭包的状态捆绑, 必须发生在运行时。
*/

/*
闭包实现的三种方式：
1.重载operator()(仿函数实现)
2.lambda表达式
3.bind和function
*/



                                                                 //仿函数
/*
因为闭包是一个函数+一个状态, 这个状态通过隐含的this指针传入.所以闭包必然是一个函数对象.因为成员变量就是极好的用于保存状态的工具,
因此实现operator()运算符重载, 该类的对象就能作为闭包使用.默认传入的this指针提供了访问成员变量的途径
*/

//#include<iostream>
//using namespace std;
//class MyFunc
//{
//public:
//    MyFunc(int temp) :m_r(temp) {}
//    int operator()(int num)
//    {
//        return num + m_r;
//    }
//
//private:
//    int m_r;
//};
//int main()
//{
//    MyFunc obj(10);
//    cout << obj(1) << endl;//调用仿函数 11
//    return 0;
//}








                                                         //lambda表达式
/*
lambda表达式是一个匿名对象，用于创建匿名的函数对象，以简化编程工作

lambda表达式的类型在C++11中被称为"闭包类型",每一个lambda表达式会产生一个临时对象(右值)，因此严格来讲,lambda表达式返回值并非函数指针

C++11却允许lambda表达式向函数指针转换，前提是lambda函数并没有捕获任何变量,且函数指针所示的函数原型必须跟lambda有着相同的调用方式
*/

/*
lambda 表达式还可以通过捕获列表捕获一定范围内的变量：
[]不捕获任何变量。

[&]捕获外部作用域中所有变量,并作为引用在函数体中使用(按引用捕获)。

[=]捕获外部作用域中所有变量,并作为副本在函数体中使用(按值捕获)。

[=,&foo]按值捕获外部作用域中所有变量,并按引用捕获foo变量。

[bar]按值捕获bar变量,同时不捕获其他变量。

[this]捕获当前类中的this指针,让lambda表达式拥有和当前类成员函数同样的访问权限。如果已经使用了&或者=,
就默认添加此选项。捕获this的目的是可以在lambda中使用当前类的成员函数和成员变量。
*/

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    int i_ = 0;
//    void func(int x, int y)
//    {
//        auto x1 = []() { return i_; };                    // error，没有捕获外部变量
//        auto x2 = [=] (){ return i_ + x + y; };           // OK，捕获所有外部变量
//        auto x3 = [&]() { return i_ + x + y; };           // OK，捕获所有外部变量
//        auto x4 = [this]() { return i_; };                // OK，捕获this指针
//        auto x5 = [this]() { return i_ + x + y; };        // error，没有捕获x、y
//        auto x6 = [this, x, y]() { return i_ + x + y; };  // OK，捕获this指针、x、y
//        auto x7 = [this]() { return i_++; };              // OK，捕获this指针，并修改成员的值
//    }
//};
//int main()
//{
//    A a;
//    a.func(10, 1);
//    return 0;
//}


/*
默认情况下，lambda函数以从const修饰函数，值传递无法修改。
若希望去修改按值捕获的外部变量时,需要显式指明lambda表达式为mutable:
*/
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 0;
//    //auto f1 = [=] { return a++; };             // error，修改按值捕获的外部变量
//    auto f2 = [=]() mutable
//    { 
//        ++a;
//        cout <<"a = "<< a << endl;//值传递
//    };// OK，mutable
//    f2();//1
//    cout << "a = " << a << endl;//0
//    return 0;
//}


//lambda返回值与函数指针的转换
//#include<iostream>
//#include<functional>
//using namespace std;
//
//int main()
//{
//    int temp = 1;
//    function<int(int)>f1 = [=](int a) { return a + temp;};
//    cout << f1(100) << endl;//101
//
//
//    function<void(int)>f2 = bind(
//        [](int a) { cout << a << endl; },
//        std::placeholders::_1
//    );
//    f2(10);//11
//
//
//
//    auto f3 = [](int x, int y)->int {return x + y; };
//    cout << f3(1, 1) << endl;//2
//
//    decltype(f3) f4 = f3;
//    cout << f4(2, 2) << endl;//4
//
//    //定义一个函数指针
//    typedef int(*PFUC)(int, int);
//    PFUC p1 = f3;
//    cout << p1(10, 10) << endl;//20
//
//
//    return 0;
//}


//for_each与lambda表达式结合
//#include<algorithm>
//#include<vector>
//#include<iostream>
//#define TEMP 5
//using namespace std;
//int main()
//{
//    vector<int>v;
//    vector<int>LargeNum;
//    for (int i = 0; i < 10; ++i)
//    {
//        v.push_back(i + 1);
//    }
//    for_each(v.begin(), v.end(),
//        [&](int&n){
//            if (n > TEMP)
//            {
//                LargeNum.push_back(n);
//            }
//        }
//    );
//    for_each(LargeNum.begin(), LargeNum.end(),
//        [&](int& n) {
//            cout << n << " ";
//        }
//    );
//    return 0;
//}






                                                           //std::function类模板(绑定器)
/*
在C++中,可调用实体主要包括:函数、函数指针、函数引用、可以隐式转化为函数指定的对象，或者重载了operator()的对象
*/

/*
C++11中新增了std::function类模板,它是对C++中现有的可调用的一种类型安全的包裹,通过指定它的模板参数,
它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟执行它们
*/

/*
注意:
1.function的最大的作用是实现函数回调
2.不能被检查相互相等或不相等
3.可以与NULL或nullptr进行比较
*/

//#include<iostream>
//#include<functional>
//using namespace std;
//void func()//普通函数
//{
//    cout << __func__ << endl;
//}
//class Test//类中静态函数
//{
//public:
//    static int test_func(int a)
//    {
//        cout << __func__ <<"("<<a<<")"<< endl;
//        return a;
//    }
//};
//class MyFunctor//类中仿函数
//{
//public:
//    int operator()(int a)
//    {
//        cout << __func__ << "(" << a << ")" << endl;
//        return a;
//    }
//};
//int main()
//{
//    function<void()>f1 = func;
//    f1();//等价于func();
//
//    function<int(int)>f2 = Test::test_func;
//    f2(10);//等价于Test::tets_func(10);
//
//    //绑定类中的仿函数，绑定对象
//    MyFunctor obj;
//    function<int(int)> f3 = obj;
//    f3(20);
//
//    return 0;
//}








                                                                  //std::bind
/*
std::bind可以预先把指定可调用实体的某些参数绑定到己有的变量，产生一个新的可调用的实体。

std::bind,其绑定的参数个数不受限制，绑定的具体哪些参数也不受限制，其为真正意义上的绑定。
*/

//#include<iostream>
//#include<functional>
//using namespace std;
//void func(int x, int y)
//{
//    cout << x << " " << y <<endl;
//}
//int main()
//{
//    bind(func, 11, 22)();
//
//    //占位符
//    //std::placeholders::_1 函数调用时，被第一个参数替换
//    //std::placeholders::_2 函数调用时，被第二个参数替换
//
//    bind(func, placeholders::_1, placeholders::_2)(11,22);
//
//    return 0;
//}






                                                           //bind和function结合
//#include<iostream>
//#include<functional>
//using namespace std;
//class Test
//{
//public:
//    void func(int x ,int y)
//    {
//        cout << x << " " << y << endl;
//    }
//    int m_a;
//};
//int main()
//{
//    Test obj;
//
//    //绑定成员函数
//    function<void(int, int)>f1 = bind(&Test::func, &obj, std::placeholders::_1, std::placeholders::_2);
//    f1(10, 20);
//
//    //绑定成员变量
//    function<int& ()>f2 = bind(&Test::m_a, &obj);
//    f2() = 111;
//    cout << obj.m_a << endl;
//
//    return 0;
//}