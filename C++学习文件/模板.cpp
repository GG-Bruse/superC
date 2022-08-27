#define _CRT_SECURE_NO_WARNINGS


//模板

//概论
/*
C++提供两种模板机制:函数模板和类模板
类属—类型参数化，又称参数模板
总结:
1.模板把函数或类要处理的数据类型参数化，表现为类型的多态性，称为类属
2.模板用于表达逻辑结构相同，但具体数据元素类型不同的数据对象的通用行为
*/




//函数模板

//基础语法
/*
函数模板实际上是建立一个通用函数，其函数类型和形参类型不具体写定，用一个虚拟的类型来代表
*/

//#include<iostream>
//using namespace std;
//template<typename T>//T代表一个通用的数据类型，在后面紧跟着的函数或类中出现T编译器不会报错
//void mySwap(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    mySwap(a, b);//1.自动类型推导(必须推导出一致的数据类型才可以正常使用模板)
//    cout << a << endl;//20
//    cout << b << endl;//10
//    double c = 3.14;
//    double d = 0.01;
//    mySwap<double>(c, d);//2.显式指定类型
//    cout << c << endl;//0.01
//    cout << d << endl;//3.14
//    return 0;
//}




//利用模板实现对char和int类型的数组排序
//#include<iostream>
//using namespace std;
//template<class T>//typename和class相同
//void myswap(T& a,T&b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//template<class T>
//void mySort(T arr[],int len)
//{
//    int i, j, max;
//    for (i = 0; i < len; i++)
//    {
//        max = i;
//        for (j = i + 1; j < len; j++)
//        {
//            if (arr[max] < arr[j])
//            {
//                max = j;
//            }
//        }
//        if (i != max)
//        {
//            myswap(arr[i],arr[max]);
//        }
//    }
//}
//template<class T>
//void Printarr(T arr,int len)
//{
//    int i;
//    for (i = 0; i < len; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}
//int main()
//{
//    char charr[] = "helloworld";
//    mySort(charr,strlen(charr));
//    Printarr(charr, strlen(charr));
//    int arr[] = { 1,2,3,6,5,4,9,8,7 };
//    mySort(arr, sizeof(arr)/sizeof(int));
//    Printarr(arr, sizeof(arr)/sizeof(int));//9 8 7 6 5 4 3 2 1
//    return 0;
//}





//函数模板与普通函数区别及调用规则
/*
区别:
在函数模板中，如果使用自动类型推导，是不可以发生隐式类型转换的(例如int和char之间相互转换)；
而普通函数可以发生隐式类型转换。
*/
/*
规则:
1.在函数模板和普通函数都可以调用的情况下，优先调用普通函数
2.若想强制调用函数模板，可以使用空模板列表
3.函数模板也可以发生函数重载
4.若函数模板可以产生更好的匹配，优先使用函数模板
*/

//#include<iostream>
//using namespace std;
//template<class T>
//void A(T a,T b)
//{
//    cout << "函数模板调用" << endl;
//}
//template<class T>
//void A(T a, T b,T c)
//{
//    cout << "函数模板(2)调用" << endl;
//}
//void A(int a,int b)
//{
//    cout << "普通函数调用" << endl;
//}
//int main()
//{
//    int a = 10, b = 1;
//    char c = 'c', d = 'd';
//    A(a,b);
//    A<>(a,b);//空模板列表
//    A(a, b, 10);
//    A(c, d);//若调用普通函数需进行隐式类型转换，此时与函数模板的匹配度更高
//    return 0;
//}








//模板机制和模板局限性
/*
函数模板机制结论:
1.编译器并不是把函数模板处理成能够处理任何类型的函数
2.函数模板通过具体类型产生不同的函数(通过函数模板产生的函数被称为模板函数)
3.编译器会对函数模板进行两次编译，在声明的地方对模板代码本省进行编译，在调用的地方对参数替换后的代码进行编译
*/
/*
模板的局限性:
模板并不是真正的通用，对于自定义的数据类型，可以使用具体化(也支持部分具体化)，实现对自定义数据类型提供特殊模板
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Person
//{
//public:
//    Person(string name,int age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    string m_name;
//    int m_age;
//};
//template<class T>
//bool mycompare(T& a, T& b)
//{
//    if (a == b)
//    {
//        return true;
//    }
//    return false;
//}
////利用具体化
//template<>
//bool mycompare(Person& a, Person& b)
//{
//    if (a.m_age == b.m_age && a.m_name == b.m_name)
//    {
//        return true;
//    }
//    return false;
//}
//int main()
//{
//    Person p1("Tom", 18);
//    Person p2("Tom", 18);
//    bool ret = mycompare(p1, p2);
//    if (ret)
//    {
//        cout << "a = b" << endl;
//    }
//    else
//    {
//        cout << "a!=b" << endl;
//    }
//    return 0;
//}







                                                           //类模板

//基础语法
/*
函数模板和类模板区别:
1.类模板不可以使用自动类型推导,只能使用显式指定类型
2.类模板中可以有默认参数
*/
//#include<iostream>
//#include<string>
//using namespace std;
//template<class NAMETYPE,class AGETYPE = int>//默认参数
//class Person
//{
//public:
//    Person(NAMETYPE name,AGETYPE age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    void show()
//    {
//        cout << "姓名:" << this->m_name << endl;
//        cout << "年龄:" << this->m_age << endl;
//    }
//    NAMETYPE m_name;
//    AGETYPE m_age;
//};
//int main()
//{
//    Person <string >p1("Tom", 18);
//    p1.show();
//    return 0;
//}





//类模板中的的成员函数创建时机
/*
类模板中的成员函数，并不是一开始创建的，而是在运行阶段确定出其数据类型才去创建的
*/
//#include<iostream>
//using namespace std;
//class Person1
//{
//public:
//    void showPerson1()
//    {
//        cout << "Person1 show 调用" << endl;
//    }
//};
//class Person2
//{
//public:
//    void showPerson2()
//    {
//        cout << "Person2 show 调用" << endl;
//    }
//};
//template<class T>
//class Myclass
//{
//public:
//    void func1()
//    {
//        obj.showPerson1();
//    }
//    void func2()
//    {
//        obj.showPerson2();
//    }
//    T obj;
//};
//int main()
//{
//    Myclass<Person1>p1;
//    p1.func1();
//    Myclass<Person2>p2;
//    p2.func2();
//    return 0;
//}





//类模板做函数参数
/*
1.指定传入类型
2.参数模板化
3.整个类模板化
*/
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name,T2 age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    void show()
//    {
//        cout << "姓名:" << this->m_name << endl;
//        cout << "年龄:" << this->m_age << endl;
//    }
//    T1 m_name;
//    T2 m_age;
//};
//void dowork1(Person<string, int>& p)//指定传入类型
//{
//    p.show();
//}
//template<class T1, class T2>
//void dowork2(Person<T1, T2>& p)//参数模板化
//{
//    p.show();
//}
//template<class T>
//void dowork3(T& p)//整个类模板化
//{
//    p.show();
//}
//
//int main()
//{
//    Person<string, int>p1("Tom",999);
//    Person<string, int>p2("Jerry", 1);
//    Person<string, int>p3("GG_Bond", 18);
//    dowork1(p1);
//    dowork2(p2);
//    dowork3(p3);
//    return 0;
//}









//类模板与继承的问题及其解决
/*
必须要指定出来父类中的T,才能给子类分配内存
1.自己指定类型
2.用户指定类型
*/

//#include<iostream>
//using namespace std;
//template<class T>
//class Base
//{
//public:
//    T m_a;
//};
////自己(写死了)
//class Son1 : public Base<int>{};
////用户
//template<class T1 ,class T2>
//class Son2 :public Base<T1>
//{
//public:
//    T2 m_b;
//};






//类模板中的成员函数类外实现
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name, T2 age);
//    void showPerson();
//    T1 m_name;
//    T2 m_age;
//};
//template<class T1, class T2>
//Person<T1,T2>::Person(T1 name, T2 age)
//{
//    this->m_name = name;
//    this->m_age = age;
//}
//template<class T1, class T2>
//void Person<T1,T2>::showPerson()
//{
//    cout << "姓名:" << this->m_name << endl;
//    cout << "年龄:" << this->m_age << endl;
//}
//int main()
//{
//    Person<string, int>p("Tom", 99);
//    p.showPerson();
//    return 0;
//}






//类模板的分文件编写问题
/*
若使用普通方法，类模板中的成员函数，不会一开始创建，因此导致分文件编写链接不到函数实现，出现无法解析的外部命令错误
解决:
1.直接包含有类实现的.cpp源文件(不推荐)
2.将类的声明和实现写到同一文件中，将文件的后缀名改为.hpp
*/








//类模板与友元的问题及其解决
//#include<iostream>
//#include<string>
//using namespace std;
//
////2.提前声明
//template<class T1, class T2>
//class Person;
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p);
//
////3. 定义
//template<class T1, class T2>
//void printPerson3(Person<T1, T2>& p)
//{
//    cout << "类外实现姓名:" << p.m_name << endl;
//    cout << "类外实现年龄:" << p.m_age << endl;
//}
//
//template<class T1, class T2>
//class Person
//{
//public:
//    //1.友元函数类内实现
//    friend void printPerson1(Person<T1, T2>& p)
//    {
//        cout << "姓名:" << p.m_name << endl;
//        cout << "年龄:" << p.m_age << endl;
//    }
//
//    //2.友元函数类外实现(1)
//    friend void printPerson2<>(Person<T1, T2>& p);
//
//    //3..友元函数类外实现(2)
//    friend void printPerson3<>(Person<T1, T2>& p);
//
//    Person(T1 name,T2 age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//private:
//    T1 m_name;
//    T2 m_age;
//};
//
////2.实现
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p)
//{
//    cout << "类外实现姓名:" << p.m_name << endl;
//    cout << "类外实现年龄:" << p.m_age << endl;
//}
//
//int main()
//{
//    Person<string, int>p1("Tom", 99);
//    Person<string, int>p2("Jerry", 1);
//    printPerson1(p1);
//    printPerson2(p2);
//    printPerson3(p1);
//    return 0;
//}









//类模板案例:任意数组
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T>
//class myArray
//{
//public:
//    myArray(int num)
//    {
//        this->m_num = num;
//        this->m_size = 0;
//        this->pAddress = new T[m_num];
//    }
//    myArray(const myArray& arr)
//    {
//        this->m_num = arr.m_num;
//        this->m_size = arr.m_size;
//        this->pAddress = new T[this->m_num];
//        for (int i = 0; i < arr.m_size; i++)
//        {
//            this->pAddress[i] = arr.pAddress[i];
//        }
//    }
//    //重载=
//    myArray& operator=(const myArray& p)
//    {
//        if (this->pAddress != NULL)
//        {
//            delete[] this->pAddress;
//            this->pAddress = NULL;
//        }
//        this->m_num = p.m_num;
//        this->m_size = p.m_size;
//        this->pAddress = new T[this->m_num];
//        for (int i = 0; i < p.m_size; i++)
//        {
//            this->pAddress[i] = p.pAddress[i];
//        }
//        return *this;
//    }
//    //重载[]
//    T& operator[](int index)
//    {
//        return this->pAddress[index];
//    }
//    //尾插
//    void pushback(const T& val)
//    {
//        if (this->m_size >= this->m_num)
//        {
//            return;
//        }
//        this->pAddress[this->m_size] = val;
//        this->m_size++;
//    }
//    //获取数组当前大小
//    int getsize()
//    {
//        return this->m_size;
//    }
//private:
//    T* pAddress;
//    int m_num;//总容量
//    int m_size;//总数据量
//};
//class Person
//{
//public:
//    Person(){}
//    Person(string name,int age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    string m_name;
//    int m_age = 0;
//
//};
//void printPerson(myArray<Person>& p)
//{
//    for (int i = 0; i <p.getsize(); i++)
//    {
//        cout << "姓名:" << p[i].m_name << endl;
//        cout << "年龄:" << p[i].m_age << endl;
//    }
//
//}
//int main()
//{
//    myArray<Person> myarr(100);
//    Person p1("Tom", 99);
//    Person p2("Jerry", 1);
//    Person p3("GG_Bond", 18);
//    myarr.pushback(p1);
//    myarr.pushback(p2);
//    myarr.pushback(p3);
//    printPerson(myarr);
//    return 0;
//}



