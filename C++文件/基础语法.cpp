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



//C++支持函数重载的原理--名字修饰

































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
//	int& ra = a;
//	int& rra = a;
//	std::cout << &a << " " << &ra << " " << &rra << std::endl;
//	return 0;
//}



//引用的使用场景

//1.作参数
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


//2.做返回值
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
//	Add(2, 3);
//	cout << "Add(1, 2) is :" << ret << endl;//3
//	return 0;
//}






































