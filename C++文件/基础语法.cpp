//命名空间
/*
在C/C++中，变量、函数和类都是大量存在的，这些变量、函数和类的名称将都存在于全局作用域中，
可能会导致很多冲突。使用命名空间的目的是对标识符的名称进行本地化，以避免命名冲突或名字污染，
namespace关键字的出现就是针对这种问题的
*/
//注意:
//1.一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中
//2.在项目中。尽量不要使用using namespace std; , 可以指定命名空间或者展开常用的(例:using std::cout;)
//3.命名空间中可以定义变量/函数/类型
//4.命名空间可以嵌套
//5.同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中




//#include<iostream>
//namespace handsomeBoy
//{
//	int rand = 0;
//}
//using namespace handsomeBoy;
//int main()
//{
//	//cout << rand << endl;//error 与rand函数冲突
//	std::cout << handsomeBoy::rand << std::endl;
//	return 0;
//}































//C++输入输出
/*
1. 使用cout标准输出对象(控制台)和cin标准输入对象(键盘)时，必须包含 <iostream> 头文件以及按命名空间使用方法使用std。

2. cout和cin是全局的流对象，endl是特殊的C++符号，表示换行输出，他们都包含在包含 <iostream> 文件中。

3. <<是流插入运算符，>>是流提取运算符。

4. 使用C++输入输出更方便，不需要像printf/scanf输入输出时那样，需要手动控制格式。C++的输入输出可以自动识别变量类型。

5. 实际上cout和cin分别是ostream和istream类型的对象。

注意：早期标准库将所有功能在全局域中实现，声明在.h后缀的头文件中，使用时只需包含对应头文件即可,
后来将其实现在std命名空间下，为了和C头文件区分，也为了正确使用命名空间，规定C++头文件不带.h;
旧编译器(vc 6.0)中还支持<iostream.h>格式，后续编译器已不支持，因此推荐使用<iostream>+std的方式。
*/


//#include<iostream>
//int main()
//{
//	double d = 0.0;
//	int x = 0;
//	std::cin >> d >> x;//自动识别数据类型
//	std::cout << d << " " << x << std::endl;
//	return 0;
//}






























//缺省参数
/*
缺省参数是声明或定义函数时为函数的参数指定一个缺省值。在调用该函数时，如果没有指定实参则采用该形参的缺省值，否则使用指定的实参。

缺省参数分类:全缺省参数、半缺省参数

注意：
1. 半缺省参数必须 从右往左 依次来给出，不能间隔着给
2. 缺省参数不能在函数声明和定义中同时出现。若同时出现时，应在声明时设置 
3. 缺省值必须是常量或者全局变量
4. C语言不支持（编译器不支持）
*/


//#include<iostream>
//using std::cout;
//using std::endl;
//void Func_1(int a = 10, int b = 20, int c = 30)//全缺省
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//void Func_2(int a, int b = 10, int c = 20)//半缺省
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Func_1();//10 20 30 
//	cout << endl;
//	Func_2(1);//1 10 20
//	//实参从左往右传递
//
//	return 0;
//}
































//函数重载
/*
函数重载是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，这些同名函数
的形参列表(参数个数 或 类型 或 类型顺序)不同，常用来处理实现功能类似数据类型不同的问题
*/

//#include<iostream>
//int Add(int a, int b)
//{
//	return a + b;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret1 = Add(1, 2);
//	std::cout << ret1 << std::endl;
//
//	double ret2 = Add(1.1, 2.2);
//	std::cout << ret2 << std::endl;
//	return 0;
//}



//C++支持函数重载的原理--函数名字修饰规则
/*
每个.o文件都有其符号表
gcc的函数修饰后名字不变。而g++的函数修饰后变成 [_Z+函数长度+函数名+类型首字母]
windows下vs编译器对函数名字修饰规则不同
*/






//extern "C"
/*
由于C和C++编译器对函数名字修饰规则的不同，在有些场景下可能就会出问题，比如:

1. C++中调用C语言实现的静态库或者动态库，反之亦然
2. 多人协同开发时，有些人使用C语言，有些人使用用C++

在这种混合模式下开发，由于C和C++编译器对函数名字修饰规则不同，可能就会导致链接失败，在该种场景
下，就需要使用extern "C"。在函数前加extern "C"，意思是告诉编译器，将该函数按照C语言规则来编译

1.C++程序调用C库: 
在C++程序引用头文件时extern "C"

2.C程序调用C++库(不可完全兼容):
在C++库的头文件中extern "C"
#ifdef __cplusplus
extern "C"
{
#endif
…………
…………
#ifdef __cplusplus
}
#endif
*/































//引用
/*
引用不是新定义一个变量，而是给已存在变量取了一个别名，编译器不会为引用变量开辟内存空间，它和它引用的变量共用同一块内存空间
引用类型必须和引用实体是同种类型的。

特性:
1. 引用在定义时必须初始化
2. 一个变量可以有多个引用
3. 引用一旦引用一个实体，再不能引用其他实体

*/

//#include<iostream>
//int main()
//{
//	int a = 10;
//	// int& ra; // 该条语句编译时会出错
//	int& xa = a;
//	int& xxa = a;
//	std::cout << &a << " " << &xa << " " << &xxa << std::endl;
//	return 0;
//}






//常引用

//#include<iostream>
//int main()
//{
//	int a = 1;
//	int& b = a;//权限平移 ok
//
//	const int c = 2;
//	const int& d = c;//不可写成int& d = c; 会造成权限放大 err
//
//	int e = 3;
//	const int& f = e;//权限缩小 ok
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int data = 1;
//	double d = data;
//	//double& xd = data;    err
//	const double& xd = data;
//	/*
//	隐式类型转换/强制类型转换都会产生临时变量
//	临时变量具有常性
//	若data赋给xd,则权限放大，因此错误
//	*/
//	cout << xd << endl;
//	return 0;
//}






//引用的使用场景:
/*
1.作参数
	a.输出参数 b.大对象传参时,可提高效率
2.做返回值
*/

//#include<iostream>
//using namespace std;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	Swap(a, b);
//	cout << "a = " << a << endl;//20
//	cout << "b = " << b << endl;//10
//	return 0;
//}

//err代码
/*
若函数返回时，出了函数作用域，如果返回对象还在(还没还给系统)，则可以使用引用返回，
如果已经还给系统了，则必须使用传值返回
*/
//#include<iostream>
//using namespace std;
//int& Add(int a, int b)
//{
//	int c = a + b;
//	cout << c << endl;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add(1, 2) is :" << ret << endl;//3
//	cout << "Add(1, 2) is :" << ret << endl;//随机值,此时原本变量c所在空间被系统清理
//	return 0;
//}






//传值、传引用效率比较
/*
以值作为参数或者返回值类型，在传参和返回期间，函数不会直接传递实参或者将变量本身直接返回，而是传递实参或者返回变量的一份临时的拷贝，
因此用值作为参数或者返回值类型，效率是非常低下的，尤其是当参数或者返回值类型非常大时，效率就更低
*/

//值和引用的作为参数类型的性能比较
//#include <iostream>
//#include <time.h>
//using namespace std;
//struct A { int a[10000]; };
//void TestFunc1(A data) {}
//void TestFunc2(A& data) {}
//void TestRefAndValue()
//{
//	A a = { {0} };
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;//13
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//1
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}


//值和引用的作为返回值类型的性能比较
//#include<iostream>
//#include <time.h>
//using namespace std;
//struct A
//{ 
//	int a[10000]; 
//}a;
//A TestFunc1()
//{
//	return a; 
//}
//A& TestFunc2()
//{ 
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;//157
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;//2
//}
//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}






//引用和指针的区别
/*
在语法概念上引用就是一个别名，没有独立空间，和其引用实体共用同一块空间
在底层实现上实际是有空间的，因为引用是按照指针方式来实现的。
*/

/*
引用和指针的不同点:
1. 引用概念上定义一个变量的别名，指针存储一个变量地址。

2. 引用在定义时必须初始化，指针没有要求

3. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型实体

4. 没有NULL引用，但有NULL指针

5. 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占4个字节)

6. 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小

7. 有多级指针，但是没有多级引用

8. 访问实体方式不同，指针需要显式解引用，引用编译器自己处理

9. 引用比指针使用起来相对更安全
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//
//	int* pa = &a;
//	*pa = 20;
//
//	int& xa = a;
//	xa = 10;
//
//	return 0;
//}
/*
反汇编
	int* pa = &a;
00B82036  lea         eax,[a]
00B82039  mov         dword ptr [pa],eax
	*pa = 20;
00B8203C  mov         eax,dword ptr [pa]
00B8203F  mov         dword ptr [eax],14h

	int& xa = a;
00B82045  lea         eax,[a]
00B82048  mov         dword ptr [xa],eax
	xa = 10;
00B8204B  mov         eax,dword ptr [xa]
00B8204E  mov         dword ptr [eax],0Ah
*/

































//内联函数
/*
概念:
以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数调用建立栈帧的开销，内联函数提升程序运行的效率

特性:
1.inline是一种以空间换时间的做法，如果编译器将函数当成内联函数处理，在编译阶段，会用函数体替换函数调用。
缺陷:可能会使目标文件变大，优势：少了调用开销，提高程序运行效率。

2.inline对于编译器而言只是一个建议，不同编译器关于inline实现机制可能不同。
一般建议:将函数规模较小(编译出来的指令较少)(即函数不是很长，具体没有准确的说法，取决于编译器内部实现)、不是递归、频繁调用的函数采用inline修饰，
		 否则编译器会忽略inline特性

3.inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了(不放入符号表)，链接就会找不到。
*/
































//auto关键字(C++11)
/*
在早期C/C++中auto的含义是:使用auto修饰的变量，是具有自动存储器的局部变量。

C++11中:
auto不再是一个存储类型指示符，而是作为一个类型指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导而得
*/

/*
注意:
1.使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类型。
因此auto并非是一种"类型"的声明，而是一个类型声明时的"占位符"，编译器在编译期会将auto替换为变量实际的类型

2.用auto声明指针类型时，用auto和auto*没有任何区别(加*没用)，但用auto声明引用类型时则必须加&

3.当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错.
因为编译器实际只对第一个类型进行推导，然后用推导出来的类型定义其他变量。

4.为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法
*/

/*
auto不能推导的场景:
1.auto不能作为函数的参数(形参)

2.auto不能直接用来声明数组
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//double AutoTest()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = AutoTest();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;
//}

//#include<iostream>
//using std::cout;
//using std::endl;
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;//加*没用
//	auto& c = x;
//	cout << typeid(a).name() << endl;//int*
//	cout << typeid(b).name() << endl;//int*
//	cout << typeid(c).name() << endl;//int
//	*a = 20;
//	*b = 30;
//	c = 40;
//	cout << x << endl;//40
//	return 0;
//}






























//基于范围的for循环(C++11)
/*
C++11中引入了基于范围的for循环。for循环后的括号由冒号" : "分为两部分
第一部分是范围内用于迭代的变量，第二部分则表示被迭代的范围

范围for的使用条件:
1.for循环迭代的范围必须是确定的
对于数组而言，就是数组中第一个元素和最后一个元素的范围;
对于类而言，应该提供begin和end的方法，begin和end就是for循环迭代的范围。
(出现指针降级的情况不可使用)

2.迭代的对象要可以实现++和==的操作(可以自行进行运算符重载)
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	for (auto i : arr)
//	{
//		cout << i << " ";
//	}
//	return 0;
//}


































//指针空值nullptr(C++11)
/*
NULL实际是一个宏，在传统的C头文件(stddef.h)中:
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif
NULL可能被定义为字面常量0，或者被定义为无类型指针(void*)的常量
*/

/*
NULL的问题:
本意是想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，因此与程序的初衷相悖(存在二义性)
#include<iostream>
using std::cout;
using std::endl;
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);//f(int)
	f(NULL);//f(int)
	f((int*)NULL);//f(int*)
	return 0;
}
*/

/*
nullptr注意:
1. 在使用nullptr表示指针空值时，不需要包含头文件，因为nullptr是C++11作为新关键字引入的。
2. 在C++11中，sizeof(nullptr) 与 sizeof((void*)0)所占的字节数相同。
3. 为了提高代码的健壮性，在表示指针空值时建议最好使用nullptr
*/







