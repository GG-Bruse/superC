//泛型编程
/*
1.重载的函数仅仅是类型不同，代码复用率比较低，只要有新类型出现时，就需要用户自己增加对应的函数
2.代码的可维护性比较低，一个出错可能所有的重载均出错

泛型编程：编写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础
*/
//#include<iostream>
//using std::cout;
//using std::endl;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int t1 = 1, t2 = 2;
//	double t3 = 3.3, t4 = 4.4;
//	char t5 = '5', t6 = '6';
//	Swap(t1, t2);
//	Swap(t3, t4);
//	Swap(t5, t6);
//	cout << t1 << " " << t2 << endl;
//	cout << t3 << " " << t4 << endl;
//	cout << t5 << " " << t6 << endl;
//	return 0;
//}































//函数模板

//概念:
/*
函数模板代表了一个函数家族，该函数模板与类型无关，在使用时被参数化，根据实参类型产生函数的特定类型版本
格式:
template<typename T1, typename T2,......,typename Tn>
返回值类型 函数名(参数列表){}
注意:
typename是用来定义模板参数关键字，也可以使用class(切记:不能使用struct代替class)
*/
//#include<iostream>
//using std::cout;
//using std::endl;
//template<typename T>//模板参数
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int t1 = 1, t2 = 2;
//	double t3 = 3.3, t4 = 4.4;
//	char t5 = '5', t6 = '6';
//	Swap(t1, t2);
//	Swap(t3, t4);
//	Swap(t5, t6);
//	cout << t1 << " " << t2 << endl;
//	cout << t3 << " " << t4 << endl;
//	cout << t5 << " " << t6 << endl;
//	return 0;
//}


//函数模板的原理:
/*
函数模板是一个蓝图，它本身并不是函数，是编译器用使用方式产生特定具体类型函数的模具。所以其实模板就是将本来应该我们做的重复的事情交给了编译器

在编译器编译阶段，对于模板函数的使用，编译器需要根据传入的实参类型来推演实例化生成对应类型的函数以供调用。
比如:当用double类型使用函数模板时，编译器通过对实参类型的推演，将T确定为double类型，然后产生一份专门处理double类型的代码，对于字符类型等也是如此
*/


//函数模板的实例化
/*
用不同类型的参数使用函数模板时，称为函数模板的实例化。模板参数实例化分为:隐式实例化和显式实例化

1.隐式实例化: 让编译器根据实参推演模板参数的实际类型
2.显式实例化: 在函数名后的<>中指定模板参数的实际类型
*/
//#include<iostream>
//template<typename T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	//Add(a1, d1);//err
//	/*
//	该语句不能通过编译
//	因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意:在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	*/
//
//	//处理方式: 1.用户自己来强制转化 2.使用显式实例化 3.设置多个模板参数
//	Add(a1, (int)d1);
//	Add<int>(a1, d1);//显式实例化
//	return 0;
//}


//模板参数的匹配原则
/*
1.一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函数

2.对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模板产生出一个实例。
如果模板可以产生一个具有更好匹配的函数， 那么将选择模板

3.模板函数不允许自动类型转换，但普通函数可以进行自动类型转换
*/

//int Add(int left, int right)//专门处理int的加法函数
//{
//	return left + right;
//}
//template<class T>//通用加法函数
//T Add(T left, T right)
//{
//	return left + right;
//}
//template<class T1, class T2>//通用加法函数
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2);//与非函数模板类型完全匹配，不需要函数模板实例化
//
//	//模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	Add(1.0, 2.0);//调用第二个
//	Add(1.0, 2);//调用第三个
//	return 0;
//}































//类模板

//类模板的定义格式:
/*
template<class T1, class T2, ..., class Tn>
class 类模板名
{
// 类内成员定义
};
*/
//#include<iostream>
//using namespace std;
//template<class T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 6):_capacity(capacity),_top(0),_data(new T[capacity]){}
//	~Stack();
//private:
//	size_t _capacity;
//	size_t _top;
//	T* _data;
//};
//template<class T>//类模板中函数放在类外进行定义时，需要加模板参数列表
//Stack<T>::~Stack()
//{
//	delete[] _data;
//	_top = 0;
//	_capacity = 0;
//}
//int main()
//{
//	//Stack是类名，Stack<int>、Stack<char>等才是类型
//	Stack<int>sk1;
//	Stack<char>sk2;
//	Stack<int>sk3(100);
//	return 0;
//}

//类模板的实例化:
/*
类模板实例化与函数模板实例化不同，类模板实例化需要在类模板名字后跟<>，然后将实例化的类型放在<>中即可，
类模板名字不是真正的类，而实例化的结果才是真正的类
*/


































//模板参数分为 类型形参与非类型形参
/*
类型形参即: 出现在模板参数列表中，跟在class或者typename之类的参数类型名称。
非类型形参: 就是用一个常量作为类(函数)模板的一个参数，在类(函数)模板中可将该参数当成常量来使用
*/

//template<class T, size_t N = 10>
//class array
//{
//public:
//	T& operator[](size_t index) { return _array[index]; }
//	const T& operator[](size_t index)const { return _array[index]; }
//	size_t size()const { return _size; }
//	bool empty()const { return 0 == _size; }
//private:
//	T _array[N];
//	size_t _size;
//};

/*
注意:
1. 浮点数、类对象以及字符串是不允许作为非类型模板参数的
2. 非类型的模板参数必须在编译期就能确认结果
*/



















//模板的特化
/*
概念:
通常情况下，使用模板可以实现一些与类型无关的代码，但对于一些特殊类型的可能会得到一些错误的结果，需要特殊处理
此时，就需要对模板进行特化。即:在原模板类的基础上，针对特殊类型所进行特殊化的实现方式。模板特化中分为函数模板特化与类模板特化
*/

//函数模板特化
/*
1. 必须要先有一个基础的函数模板
2. 关键字template后面接一对空的尖括号<>
3. 函数名后跟一对尖括号，尖括号中指定需要特化的类型
4. 函数形参表: 必须要和模板函数的基础参数类型完全相同
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//class Date
//{
//public:
//	Date() :_year(0), _month(0), _day(0) {}
//	Date(int year, int month, int day) :_year(year), _month(month), _day(day) {}
//	bool operator<(const Date& d)const {
//		if ((_year < d._year) || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day))
//			return true;
//			return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////该种实现简单明了，代码的可读性高，容易书写，因为对于一些参数类型复杂的函数模板，特化时特别给出，因此函数模板不建议特化
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
////对Less函数模板进行特化
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl;
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl;
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl;
//	return 0;
//}





//类模板特化
/*
全特化:
全特化即是将模板参数列表中所有的参数都确定化

偏特化:
任何针对模版参数进一步进行条件限制设计的特化版本
	偏特化有以下两种表现方式:
	(1)部分特化:将模板参数类表中的一部分参数特化
	(2)参数更进一步的限制:偏特化并不仅仅是指特化部分参数，而是针对模板参数更进一步的条件限制所设计出来的一个特化版本
*/


//#include<iostream>
//using std::cout;
//using std::endl;
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//};
//
//template<>//全特化
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//};
//
//template <class T1>//偏特化
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//};
//template<class T1, class T2>//偏特化
//class Data<T1*,T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//template<class T1, class T2>//偏特化
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//};
//
//int main()
//{
//	Data<int, int> d1;//Data<T1, int>
//	Data<int, char> d2;//Data<int, char>
//	Data<double, double>d3;//Data<T1, T2>
//
//	Data<int*, int*> d4;//Data<T1*, T2*>
//	Data<double*, char*>d5;//Data<T1*, T2*>
//
//	Data<double&, char&>d6;//Data<T1&, T2&>
//	return 0;
//}






























//模板的分离编译

//模板不支持分离编译
/*
解决方法:
1.将声明和定义放到一个文件 "xxx.hpp" 里面或者xxx.h其实也是可以的(推荐)
2.模板定义的位置显式实例化(不推荐:将类型写死)
*/
/*
原因:
main.cpp文件:
#include"add.h"
int main()
{
	Add(1,1);
	Add(2.1,2.2);
	return 0;
}

add.h文件:
template<class T>
T Add(const T& left,const T& right);

add.cpp文件
template<class T>
T Add(const T& left,const T& right) { return left + right; }

C/C++程序要运行，得经历: 预处理 -- 编译 -- 汇编 -- 链接
编译:
对程序进行词法、语法、语义分析，无误后生成汇编代码。
头文件不参与编译，编译器对各个.cpp文件分离编译
链接:
将多个.o文件合并，并处理没有解决的地址问题

分离编译导致add.cpp文件中的模板函数并未实例化，链接合并符号表后无法找到Add函数的地址，导致链接错误
*/










//模板总结
/*
优点:
1. 模板复用了代码，节省资源，更快的迭代开发，C++的标准模板库(STL)因此而产生
2. 增强了代码的灵活性
缺陷:
1. 模板会导致代码膨胀问题，也会导致编译时间变长
2. 出现模板编译错误时，错误信息非常凌乱，不易定位错误
*/













//可变参数模板
/*
C++11的新特性可变参数模板能够让您创建可以接受可变参数的函数模板和类模板。
*/

// Args是一个模板参数包，args是一个函数形参参数包
// 声明一个参数包Args... args，这个参数包中可以包含0到任意个模板参数
//template <class ...Args>
//void ShowList(Args... args) {}

/*
上面的参数args前面有省略号，所以它就是一个可变模版参数，我们把带省略号的参数称为“参数包”，它里面包含了0到N（N>=0）个模版参数。
我们无法直接获取参数包args中的每个参数的，只能通过展开参数包的方式来获取参数包中的每个参数。
*/



//递归函数方式展开参数包
//#include <iostream>
//#include <string>
//using namespace std;
////template <class T>
//void ShowList()// 递归终止函数
//{
//	cout << endl;
//}
//template <class T, class ...Args>
//void ShowList(const T& value, Args... args)
//{
//	cout << "ShowList("<<value<<", " << sizeof...(args) << "参数包)" << endl;
//	ShowList(args...);
//}
//int main()
//{
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}



//逗号表达式展开参数包
/*
这种展开参数包的方式，不需要通过递归终止函数，是直接在expand函数体中展开的。
printarg不是一个递归终止函数，只是一个处理参数包中每一个参数的函数。
这种就地展开参数包的方式实现的关键是逗号表达式。我们知道逗号表达式会按顺序执行逗号前面的表达式。

expand函数中的逗号表达式：(printarg(args), 0)，也是按照这个执行顺序，先执行printarg(args)，再得到逗号表达式的结果0。
同时还用到了C++11的另外一个特性——初始化列表，通过初始化列表来初始化一个变长数组,
{(printarg(args), 0)...}将会展开成((printarg(arg1),0),(printarg(arg2),0), (printarg(arg3),0), etc... )，
最终会创建一个元素值都为0的数组int arr[sizeof...(Args)]。

由于是逗号表达式，在创建数组的过程中会先执行逗号表达式前面的部分printarg(args)
打印出参数，也就是说在构造int数组的过程中就将参数包展开了，这个数组的目的纯粹是为了在数组构造的过程展开参数包
*/

//#include <iostream>
//#include <string>
//using namespace std;
//template<class T>
//int PrintArg(const T& x)//处理每个参数的函数
//{
//	cout << x << " ";
//	return 0;
//}
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int a[] = { PrintArg(args)... };
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}



//emplace_back(这里写博客时，查下资料)
//#include <iostream>
//#include <list>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;
//	}
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		cout << "Date& operator=(const Date& d))" << endl;
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//对于普通内置类型没有区别
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.emplace_back(2);
//
//	//对于自定义类型
//	list<Date> lt2;
//	lt2.push_back(Date(2022, 11, 16));//构造+拷贝构造(移动构造)
//	cout << "---------------------------------" << endl;
//	lt2.emplace_back(2022, 11, 16);//本质上是将参数包中参数逐个用于构造
//
//	return 0;
//}
/*
Date(int year = 1, int month = 1, int day = 1)
Date(const Date& d)
---------------------------------
Date(int year = 1, int month = 1, int day = 1)
*/



































//#include <iostream>
//using namespace std;
//
//void Swap(double& d1, double& d2) {
//	double temp = d1;
//	d1 = d2;
//	d2 = temp;
//}
//void Swap(int& i1, int& i2) {
//	int temp = i1;
//	i1 = i2;
//	i2 = temp;
//}
//void Swap(char& c1, char& c2) {
//	char temp = c1;
//	c1 = c2;
//	c2 = temp;
//}
//template <typename T>
//void Swap(T& t1, T& t2) {
//	T temp = t1;
//	t1 = t2;
//	t2 = temp;
//}
//int main()
//{
//	double d1 = 1.0;
//	double d2 = 2.0;
//	Swap(d1, d2);
//	int i1 = 1;
//	int i2 = 2;
//	Swap(i1, i2);
//	char c1 = '1';
//	char c2 = '2';
//	Swap(c1, c2);
//	return 0;
//}





//#include <iostream>
//using namespace std;
//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2);//与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0);//模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	return 0;
//}








//#include <iostream>
//using namespace std;
//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2);//与非模板函数匹配，编译器不需要实例化
//	Add<int>(1, 2);//调用编译器实例化的版本
//	return 0;
//}






//template<class T, size_t N = 10>
//class array
//{
//public:
//	//……
//private:
//	T _array[N];
//	size_t _size;
//};









//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date() :_year(0), _month(0), _day(0) {}
//	Date(int year, int month, int day) :_year(year), _month(month), _day(day) {}
//	bool operator<(const Date& d)const {
//		if ((_year < d._year) || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day))
//			return true;
//		return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//	//这里本意比较Date类型数据的大小，实际比较的却是指针地址的大小
//	return 0;
//}




