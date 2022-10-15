//面向对象的三大特性:封装、继承、多态
//C语言是面向过程的，关注的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题
//C++是基于面向对象的(非纯面向对象)，关注的是对象，将一件事情拆分成不同的对象，靠对象之间的交互完成

//C语言结构体struct中只能定义变量。在C++中，结构体内不仅可以定义变量，也可以定义函数。
//在C++中更喜欢用class来代替struct
/*
类是对某一类实体(对象)来进行描述的，描述该对象具有那些属性，
那些方法，描述完成后就形成了一种新的自定义类型，才用该自定义类型就可以实例化具体的对象
*/











//类的定义
/*
class className
{
	//类体
}; 
class为定义类的关键字，ClassName为类的名字，{}中为类的主体，注意类定义结束时后面分号不能省略。

类体中内容称为类的成员:
类中的变量称为类的属性或成员变量
类中的函数称为类的方法或者成员函数
*/

/*
类的两种定义方式:(一般情况下，更期望采用第二种方式)

1.声明和定义全部放在类体中
需注意:成员函数在类中定义时，若成员函数符合内联函数条件，编译器就会将其当成内联函数处理

2.类声明放在.h文件中,成员函数定义放在.cpp文件中
注意:成员函数名前需要加类名::

*/

































//类的访问限定符及封装

//访问限定符
/*
分为 public(公有)、protected(保护)、private(私有) 三种

注意:
1. public修饰的成员在类外可以直接被访问

2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)

3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止。若后面没有访问限定符，作用域就到 } 即类结束。

4. class的默认访问权限为private，struct为public(因为struct要兼容C)

5.访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别

*/

//封装
/*
C++实现封装的方式:
用类将对象的属性与方法结合在一块，让对象更加完善，通过访问权限选择性的将其接口提供给外部的用户使用
*/

/*
1.C++中struct和class的区别是什么？
解答:
C++需要兼容C语言，所以C++中struct可以当成结构体使用。C++中struct也可以用来定义类。和class定义类是一样的，
区别是struct定义的类默认访问权限是public，class定义的类默认访问权限是private。
注意:在继承和模板参数列表位置，struct和class也有区别

2.在类和对象阶段，主要是研究类的封装特性，那什么是封装呢？
封装:
将数据和操作数据的方法进行有机结合，通过访问权限来隐藏对象的属性和实现细节。仅对外公开接口来和对象进行交互。封装本质上是一种管理，让用户更方便使用类。
*/


































//类的作用域
/*
类定义了一个新的作用域，类的所有成员都在类的作用域中。
在类体外定义成员时，需要使用 :: 作用域操作符指明成员属于哪个类域
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//class Person
//{
//public:
//	Person(const char* name,const char* gender,int age);
//	void PrintPersonInfo();
//private:
//	char* _name;
//	char* _gender;
//	int _age;
//};
//Person::Person(const char* name, const char* gender, int age)
//{
//	this->_name = (char*)name;
//	this->_gender = (char*)gender;
//	this->_age = age;
//}
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}
//int main()
//{
//	Person p("bjy", "man", 18);
//	p.PrintPersonInfo();
//	return 0;
//}

































//类对象
/*
类的实例化:
用类的类型创建对象的过程，称为类的实例化。

1.类是对对象进行描述的，类似于模型，限定了类有哪些成员，但定义出一个类并没有分配实际的内存空间来存储它

2.一个类可以实例化出多个对象，实例化出的对象占用实际的物理空间，存储类成员。
*/

/*
类对象模型:
只保存成员变量，成员函数存放在公共的代码段:
一个类的大小，实际就是该类中 "成员变量" 之和，注意内存对齐
没有成员变量的类对象(包括空类)，1字节占位，不存储实际数据，用于标识对象存在
*/


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void func()
//	{
//		cout << "void A::func" << endl;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	A* p = nullptr;
//	p->func();//void A::func
//	return 0;
//}
/*
该代码正常运行。
类对象中不存储成员函数，成员函数存放在公共的代码段。
在编译链接期间，就已经根据函数名去公共代码区找到了函数的地址，call函数地址。
为什么不会call错？隐式传入了调用对象的地址(即this指针)

	A* p = nullptr;
	p->func();//void A::func
000A1000  mov         ecx,dword ptr [__imp_std::cout (0A3058h)]
000A1006  push        offset std::endl<char,std::char_traits<char> > (0A1240h)
000A100B  call        std::operator<<<std::char_traits<char> > (0A1020h)
000A1010  mov         ecx,eax
000A1012  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A3034h)]
*/


//#include<iostream>
//using namespace std;
//class A//无成员变量的类
//{
//	void func() {}
//};
//class B//空类
//{};
//int main()
//{
//	cout << sizeof(A) << endl;//1
//	cout << sizeof(B) << endl;//1
//	A a;
//	B b;
//	cout << sizeof(a) << endl;//1
//	cout << sizeof(b) << endl;//1
//	return 0;
//}


































//this指针
/*
C++编译器给每个"非静态的成员函数"增加了一个隐藏的指针参数，
让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有”成员变量"的操作，都是通过该指针去访问。
只不过所有的操作对用户是透明的，即用户不需要来传递，编译器自动完成
*/
/*
1. this指针的类型: 类的类型* const，即成员函数中不能给this指针赋值。

2. 只能在"成员函数"的内部使用

3. this指针本质上是"成员函数"的形参，当对象调用成员函数时，将对象地址作为实参传递给this形参，所以对象中不存储this指针。

4. this指针是"成员函数"第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递(或者作为形参存储在栈中)，不需要用户传递

*/

































//类的6个默认成员函数
/*
任何类在什么都不写时，编译器会自动生成6个默认成员函数。
默认成员函数:用户没有显式实现，编译器会生成的成员函数称为默认成员函数

1.构造函数(主要完成初始化工作)

2.析构函数(主要完成清理工作)

3.拷贝构造函数(可使用同类对象进行初始化创建对象)

4.赋值操作符重载(将一个对象赋值给另一个对象)

5.普通对象取地址操作符重载

6.const对象取地址操作符重载
*/






/*
构造函数:
是一个特殊的成员函数，名字与类名相同,创建类类型对象时由编译器自动调用，以保证每个数据成员都有一个合适的初始值，并且在对象整个生命周期内只调用一次

特性:
1.函数名与类名相同

2.无返回值(无需void)

3.对象实例化时编译器自动调用对应的构造函数

4.构造函数可以重载

5.若类中没有显式定义构造函数(包括拷贝构造函数)，则C++编译器会自动生成一个无参的默认构造函数，用户显式定义编译器将不再生成

6.内置类型成员变量在类中声明时可以给默认值

7.无参构造函数、全缺省的构造函数和编译器默认生成的构造函数都称为默认构造函数，并且默认构造函数只能有一个
  (即不传参数都可调用的构造函数为默认构造函数)
*/

/*
对象调用了编译器生成的默认构造函数，但是对象的成员变量依旧是随机值。
也就说在这里编译器生成的默认构造函数并没有什么用？

解答:
C++把类型分成内置类型(基本类型)和自定义类型
a.编译器生成默认的构造函数对内置类型成员不做处理
b.编译器生成默认的构造函数会 调用 自定义类型成员的默认构造函数
注意:任何指针都属于内置类型(包括自定义类型*)

(该设计是C++早期设计的一个缺陷，本该内置类型一并处理。
补丁:C++11时允许内置类型成员变量在类中声明时可以给默认值(缺省值)，给初始化列表)
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;//输出
//		_data = 0;
//	}
//private:
//	int _data;
//};
//class B
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	A* _test;
//	// 自定义类型
//	A _t;
//};
//int main()
//{
//	B b;
//	return 0;
//}

//#include<iostream>
//class Date
//{
//public:
//	Date(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
/*
上述构造函数调用之后，对象中已经有了一个初始值，但是不能将其称为对对象中成员变量的初始化，
构造函数体中的语句只能将其称为赋初值，而不能称作初始化。因为初始化只能初始化一次，而构造函数体内可以多次赋值
*/

//初始化列表(建议使用)
/*
以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个"成员变量"后面跟一个放在括号中的初始值或表达式

注意:
1.每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)

2.类中包含以下成员，必须放在初始化列表位置进行初始化:
a.引用成员变量(引用必须在定义的时候初始化)
b.const成员变量(const变量必须在定义的地方初始化，只有一次机会)
c.自定义类型成员(且该类没有默认构造函数时)

3.尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于所有成员变量，一定会先使用初始化列表初始化

4.成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关

5.初始化列表可以认为是成员变量定义的地方，即使不写它依然隐式提供
*/

//err示例代码
//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour, int minute):_hour(hour), _minute(minute){}
//	int GetHour()const
//	{
//		return _hour;
//	}
//	int GetMinute()const
//	{
//		return _minute;
//	}
//private:
//	int _hour;
//	int _minute;
//};
//class Date
//{
//public:
//	Date(int year,int month,int day,int hour,int minute):_year(year),_month(month),_day(day)/*,_time(hour,minute)*/,N(10)
//	{
//		Time temp(0, 0);
//		_time = temp;//本质还是走初始化列表，调用默认构造函数，但不存在Time类默认构造函数
//	}
//	void Print()const
//	{
//		cout << _year << " " << _month << " " << _day << " " << _time.GetHour() << " " << _time.GetMinute() << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _time;
//	const int N;
//};
//int main()
//{
//	Date d(2003, 10, 23, 0, 0);
//	d.Print();
//	return 0;
//}

//explicit关键字
/*
构造函数不仅可以构造与初始化对象，对于单个参数或者除第一个参数无默认值其余均有默认值的构造函数，还具有类型转换的作用
explicit修饰构造函数，禁止类型转换
*/
//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//	/*explicit*/ Test(int year):_data(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//	Test(const Test& temp)
//	{
//		_data = temp._data;
//		cout << "Date(const Date& temp)" << endl;
//	}
//private:
//	int _data;
//};
//void func1(Test temp){}
//Test func2()
//{
//	Test temp(2022);
//	return temp;
//}
//int main()
//{
//	Test(2022);//匿名对象直接调用构造函数，生命周期只在这一行
//	/*err*/Test d2 = 2022;//隐式类型转换:构造(临时变量) + 拷贝构造 + 优化 -> 直接调用构造
//	const Test& d4 = 2022;
//
//	func1(Test(2022));//构造+拷贝构造+优化 -> 直接构造
//
//	Test t1 = func2();//一次构造+两次拷贝构造+优化(不在同一表达式的话无法优化) -> 一次构造+一次拷贝构造
// 
//  //结论:连续的一个表达式步骤中，连续构造都会优化(合二为一)
//	return 0;
//}






/*
析构函数:
析构函数不是完成对对象本身的销毁，局部对象销毁工作是由编译器完成的。而对象在销毁时会自动调用析构函数，完成对象中资源的清理工作

特性:
1. 析构函数名是在类名前加上字符~

2. 无参数无返回值类型

3. 一个类只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。注意:析构函数不能重载

4. 对象生命周期结束时，C++编译系统系统自动调用析构函数

5.编译器生成的默认析构函数，对自定类型成员调用它的析构函数

6.若类中没有申请资源时，析构函数可以不写，直接使用编译器生成的默认析构函数
  有资源申请时，一定要写，否则会造成资源泄漏

7.a.编译器生成默认的析构函数对内置类型成员不做处理(情况复杂，无法处理)
  b.编译器生成默认的析构函数会 调用 自定义类型成员的析构函数
  注意:任何指针都属于内置类型(包括自定义类型*)
*/






/*
拷贝构造函数:
只有单个形参，该形参是对本类类型对象的引用(一般常用const修饰)，在用已存在的类对象创建新对象时由编译器自动调用

特性:
1.拷贝构造函数是构造函数的一个重载形式。

2.拷贝构造函数的参数只有一个且必须是类对象的引用。使用传值方式编译器直接报错，因为会引发无穷递归调用

3.若未显式定义，编译器会生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷贝，这种拷贝叫做浅拷贝(值拷贝)

4.在编译器生成的默认拷贝构造函数中，内置类型是按照字节方式直接拷贝的，而自定义类型是调用其拷贝构造函数完成拷贝的

5.类中如果没有涉及资源申请时，拷贝构造函数是否写都可以；一旦涉及到资源申请时，则拷贝构造函数是一定要写的，否则就是浅拷贝


拷贝构造函数典型调用场景:
a.使用已存在对象创建新对象
b.函数形式参数类型为类对象
c.函数返回值类型为类对象
*/
/*
浅拷贝:
也称位拷贝，编译器只是将对象中的值拷贝过来。如果对象中管理资源，最后就会导致多个对象共享同一份资源，
1.当一个对象销毁时就会将该资源释放掉，而此时另一些对象不知道该资源已经被释放，以为还有效，所以当继续对资源进行操作时，就会发生发生了访问违规
2.当修改一个对象时会影响另外的对象
解决:
可以采用深拷贝解决浅拷贝问题，即：每个对象都有一份独立的资源，不要和其他对象共享
深拷贝:
若一个类中涉及到资源的管理，其拷贝构造函数、赋值运算符重载以及析构函数必须要显式给出。一般情况都是按照深拷贝方式提供
*/





//const成员
/*
将const修饰的"成员函数"称之为const成员函数，const修饰类成员函数，实际修饰该成员函数隐含的this指针，
表明在该成员函数中不能对类的任何成员进行修改，同时保证const对象和非const对象都可调用该函数
注意:
构造、析构、非成员函数不可使用const类型限定符修饰
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//class Date
//{
//public:
//	Date(int year = 2003, int month = 10, int day = 23)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print1()//该函数this指针类型为Date* const this,this指针本身不可改变(即不可指向其他内容)
//	{
//		cout << _year << "_" << _month << "_" << _day << endl;
//	}
//	void Print2()const//该函数this指针类型为const Date* const this
//	{
//		cout << _year << "_" << _month << "_" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2000, 10, 10);//&d1类型为Date*	传参的过程相当于为形参初始化(权限收缩)
//	const Date d2(2000, 10, 11);//&d2类型为const Date*,指针指向的内容不可改变，权限不兼容
//
//	d1.Print1();
//	//d2.Print();//err
//
//	d1.Print2();
//	d2.Print2();
//	return 0;
//}

//取地址及const取地址操作符重载
/*
这两个运算符一般不需要重载，使用编译器生成的默认取地址的重载即可，只有特殊情况才需要重载，比如想让别人获取到指定的内容
*/
//#include<iostream>
//class A
//{
//public:
//	A(int data)
//	{
//		_data = data;
//	}
//	A* operator&()
//	{
//		return this;
//	}
//	const A* operator&()const
//	{
//		return this;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	A a1(1);
//	const A a2(2);
//	&a1;
//	&a2;
//	return 0;
//}





































//运算符重载
/*
内置类型可以直接使用运算符运算，编译器知道如何运算。但对于自定义类型，编译器不知道如何运算，所以需要进行运算符重载

运算符重载是具有特殊函数名的函数，也具有返回值类型、函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似

函数名字为:关键字operator后面接需要重载的运算符符号

函数原型:返回值类型 operator操作符(参数列表)
*/
/*
注意：
1.不能通过连接其他符号来创建新的操作符，比如:operator@

2.重载操作符必须有一个类的类型作为参数(可以是this指针)

3.用于内置类型的运算符，其含义不能改变，例如:内置的整型+，不能改变其含义

4.作为类成员函数重载时，其形参看起来比操作数数目少1，因为成员函数的第一个参数为隐藏的this

5. .* 、:: 、sizeof 、?: 、. 注意以上5个运算符不能重载(.*运算符使用极少)
*/

//赋值运算符重载
/*
1. 赋值运算符重载格式:
	a.参数类型：const T&，传递引用可以提高传参效率，const避免误修改

	b.返回值类型 : T&，返回引用可以提高返回的效率，有返回值目的是为了支持连续赋值

	c.检测是否为自己给自己赋值

	d.返回*this : 要复合连续赋值的含义

2.赋值运算符只能重载成类的成员函数不能重载成全局函数
原因:
赋值运算符如果不显式实现，编译器会生成一个默认的(以值的方式逐字节拷贝)。
此时用户再在类外自己实现一个全局的赋值运算符重载，就和编译器在类中生成的默认赋值运算符重载冲突了，故赋值运算符重载只能是类的成员函数

3.若类中未涉及到资源管理，赋值运算符是否实现都可以；一旦涉及到资源管理则必须要实现
*/

//前置++和后置++重载
/*
前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
C++规定 : 后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传递

注意:
前置++直接返回+1之后的结果
后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存，且为临时对象，因此只能以值的方式返回，不能返回引用

*/
































//static成员
/*
声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；用static修饰的成员函数，称之为静态成员函数。
静态成员变量一定要在类外进行初始化
注意:
1.静态成员为所有类对象所共享，属于整个类，不属于某个具体的对象，存放在静态区
2.静态成员变量必须在类外定义，定义时不添加static关键字，类中只是声明
3.类静态成员即可用 类名::静态成员 或者 对象.静态成员 来访问
4.静态成员函数没有隐藏的this指针，不能访问任何非静态成员
5.静态成员也是类的成员，受public、protected、private 访问限定符的限制
*/

//面试题:实现一个类，计算程序中创建出了多少个类对象
//#include<iostream>
//using std::cout;
//using std::endl;
//class Test
//{
//public:
//	Test() { ++_objectCount; }
//	Test(const Test&) { ++_objectCount; }
//	~Test() { --_objectCount; }
//	static int GetObjectCount() { return _objectCount; }//静态成员函数
//private:
//	static int _objectCount;//静态成员变量
//};
//int Test::_objectCount = 0;
//int main()
//{
//	Test t1;
//	Test t2(t1);
//	cout << t2.GetObjectCount() << endl;//2
//	Test t3;
//	cout << Test::GetObjectCount() << endl;//3
//	return 0;
//}

//设计一个只能在栈上定义对象的类
//#include<iostream>
//class OnlyStack
//{
//public:
//	static OnlyStack CreatObject()
//	{
//		OnlyStack obj;
//		return obj;
//	}
//private:
//	OnlyStack(int dataX = 0, int dataY = 0) :_dataX(dataX), _dataY(dataY) {}
//	int _dataX;
//	int _dataY;
//};
//int main()
//{
//	OnlyStack obj1 = OnlyStack::CreatObject();
//	return 0;
//}

































//友元
/*
友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多用。
友元分为：友元函数和友元类
*/
/*
友元函数:
友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声明，声明时需要加friend关键字
注意:
1.友元函数可访问类的私有和保护成员，但不是类的成员函数
2.友元函数不能用const修饰
3.友元函数可以在类定义的任何地方声明，不受类访问限定符限制
4.一个函数可以是多个类的友元函数，但其关系不可被继承
5.友元函数的调用与普通函数的调用原理相同

友元类:
1.友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。
2.友元关系是单向的，不具有交换性。
3.友元关系不能传递
4.友元关系不能继承
*/

































//内部类
/*
若一个类定义在另一个类的内部，这个内部类就叫做内部类。内部类是一个独立的类，它不属于外部类，更不能通过外部类的对象去访问内部类的成员。
外部类对内部类没有任何优越的访问权限。
注意:
1.内部类是外部类的友元类，内部类可以通过外部类的对象参数来访问外部类中的所有成员。但是外部类不是内部类的友元。
2.内部类可以定义在外部类的public、protected、private都是可以的,但受其限制。
3.注意内部类可以直接访问外部类中的static成员，不需要外部类的对象/类名。
4.sizeof(外部类)=外部类，和内部类没有任何关系
5.内部类受外部类的类域限制
*/
//#include<iostream>
//using std::cout;
//using std::endl;
//class A
//{
//public:
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _x << endl;//访问static
//			cout << a._y << endl;//友元
//		}
//	private:
//		int _data;
//	};
//private:
//	static int _x;
//	int _y;
//};
//int A::_x = 1;
//int main()
//{
//	A::B b;//B类受A类的类域限制
//	b.foo(A());
//	cout << sizeof(A) << endl;//4	
//	return 0;
//}































//日期类
//#include <iostream>
//#include <cassert>
//using std::cout;
//using std::cin;
//using std::endl;
//using std::ostream;
//using std::istream;
//class Date
//{
//	friend inline ostream& operator<<(ostream& out, const Date& d);
//	friend inline istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year, int month, int day);
//
//	int GetMonthDay(int year, int month)const//该函数放在类中成为内联函数
//	{
//		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//该数组设计为静态避免多次创建
//		int day = days[month];
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			day += 1;
//		}
//		return day;
//	}
//	bool CheckDate()const
//	{
//		return (_year >= 1 && _month > 0 && _month < 13 && _day > 0 && _day <= GetMonthDay(_year, _month));
//	}
//
//	Date& operator=(const Date& temp);
//
//	bool operator==(const Date& temp)const;
//	bool operator!=(const Date& temp)const;
//	bool operator>(const Date& temp)const;
//	bool operator>=(const Date& temp)const;
//	bool operator<(const Date& temp)const;
//	bool operator<=(const Date& temp)const;
//
//	Date operator+(int day)const;
//	Date& operator+=(int day);
//	Date operator-(int day)const;
//	Date& operator-=(int day);
//
//	Date& operator++();
//	Date operator++(int);
//	Date& operator--();
//	Date operator--(int);
//
//	int operator-(const Date& temp)const;
//
//	void Print()const;
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date::Date(int year = 2003, int month = 10, int day = 23)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//	if (!CheckDate())
//	{
//		cout << "非法日期:";
//		Print();
//	}
//}
//
//Date& Date::operator=(const Date& temp)//该情况下实际上没必要显示提供
//{
//	if (this != &temp)//若遇到自身给自身赋值的情况
//	{
//		this->_year = temp._year;
//		this->_month = temp._month;
//		this->_day = temp._day;
//	}
//	return *this;//实现=运算符的链式赋值
//}
//
//bool Date::operator==(const Date& temp)const
//{
//	return _year == temp._year && _month == temp._month && _day == temp._day;
//}
//bool Date::operator!=(const Date& temp)const
//{
//	return !(*this == temp);
//}
//bool Date::operator>(const Date& temp)const
//{
//	if (_year > temp._year)
//		return true;
//	else if (_year == temp._year && _month > temp._month)
//		return true;
//	else if (_year == temp._year && _month == temp._month && _day > temp._day)
//		return true;
//	else
//		return false;
//}
//bool Date::operator>=(const Date& temp)const
//{
//	return (*this > temp) || (*this == temp);
//}
//bool Date::operator<(const Date& temp)const
//{
//	return !(*this >= temp);
//}
//bool Date::operator<=(const Date& temp)const
//{
//	return !(*this > temp);
//}
//
//Date Date::operator+(int day)const
//{
//	Date temp(*this);
//	temp += day;
//	return temp;
//}
//Date& Date::operator+=(int day)
//{
//	if (day < 0)
//	{
//		return *this -= -day;
//	}
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		++_month;
//		if (_month == 13)
//		{
//			_month = 1;
//			++_year;
//		}
//	}
//	return *this;
//}
//Date Date::operator-(int day)const
//{
//	Date temp(*this);
//	temp -= day;
//	return temp;
//}
//Date& Date::operator-=(int day)
//{
//	if (day < 0)
//	{
//		return *this+=-day;
//	}
//	_day -= day;
//	while (_day <= 0)
//	{
//		--_month;
//		if (_month == 0)
//		{
//			--_year;
//			_month = 12;
//		}
//		_day += GetMonthDay(_year, _month);
//	}
//	return *this;
//}
//
//
//Date& Date::operator++()//前置++
//{
//	*this += 1;
//	return *this;
//}
//Date Date::operator++(int)//后置++
//{
//	Date temp(*this);
//	*this += 1;
//	return temp;//返回局部变量，出该作用域后销毁，不可使用引用返回
//}
//Date& Date::operator--()//前置--
//{
//	return *this -= 1;
//}
//Date Date::operator--(int)//后置--
//{
//	Date temp(*this);
//	*this -= 1;
//	return temp;//返回局部变量，出该作用域后销毁，不可使用引用返回
//}
//
//int Date::operator-(const Date& temp)const
//{
//	int flag = 1;
//	Date max = *this;
//	Date min = temp;
//	if (max < min)
//	{
//		max = temp;
//		min = *this;
//		flag = -1;
//	}
//	int count = 0;
//	while (max != min)//!=的逻辑较>更简单
//	{
//		++min;
//		++count;
//	}
//	return count*flag;
//}
//
//void Date::Print()const
//{
//	cout << _year << "_" << _month << "_" << _day << endl;
//}
//
////需重载为全局函数,注意形参表顺序
//inline ostream& operator<<(ostream& out,const Date& d)
//{
//	out << d._year << "_" << d._month << "_" << d._day;
//	return out;
//}
//inline istream& operator>>(istream& in,Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	assert(d.CheckDate());
//	return in;
//}
//int main()
//{
//	Date day1(2022, 8, 23);//调用构造函数
//
//	Date day2(day1);//调用编译器默认提供的拷贝构造函数
//
//	Date day3;//调用全缺省构造函数
//	Date day4;
//
//	day4 = day3 = day1;//调用赋值运算符重载函数
//
//	cout << day1 << endl;
//	cout << day2 << endl;
//	cout << day3 << endl;
//	cout << day4 << endl;
//
//	cout << (day1 == day2) << endl;//1
//	cout << (day1 != day2) << endl;//0
//	cout << (day1 > day2) << endl;//0
//	cout << (day1 < day2) << endl;//0
//	cout << (day1 >= day2) << endl;//1
//	cout << (day1 <= day2) << endl;//1
//
//	cout << (day1++) << endl;//2022_8_23
//	cout << (++day1) << endl;;//2022_8_25
//	cout << (day1--) << endl;//2022_8_25
//	cout << (--day1) << endl;//2022_8_23
//
//	day1 += 5;
//	cout << day1 << endl;//2022_8_28
//	day1 = day1 + 4;
//	cout << day1 << endl;//2022_9_1
//
//
//	day1 = day1 - 4;
//	cout << day1 << endl;//2022_8_28
//	day1 -= 5;
//	cout << day1 << endl;//2022_8_23
//
//	day1 += 100;
//	int num = day1 - day4;
//	cout << num << endl;//100
//	
//	Date day5(1000, 13, 55);//非法日期:1000_13_55
//
//	cin >> day5;
//	cout << day5;
//	return 0;
//}















