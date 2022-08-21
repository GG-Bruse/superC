//面向对象的三大特性:封装、继承、多态
//C语言是面向过程的，关注的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题
//C++是基于面向对象的(非纯面向对象)，关注的是对象，将一件事情拆分成不同的对象，靠对象之间的交互完成

//C语言结构体struct中只能定义变量。在C++中，结构体内不仅可以定义变量，也可以定义函数。
//在C++中更喜欢用class来代替struct












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
注意空类的大小，空类比较特殊，编译器给了空类一个字节来唯一标识这个类的对象
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
在编译链接期间，就已经根据函数名去公共代码区找到了函数的地址，call函数地址。p->确定该函数位于class A域中

	A* p = nullptr;
	p->func();//void A::func
000A1000  mov         ecx,dword ptr [__imp_std::cout (0A3058h)]
000A1006  push        offset std::endl<char,std::char_traits<char> > (0A1240h)
000A100B  call        std::operator<<<std::char_traits<char> > (0A1020h)
000A1010  mov         ecx,eax
000A1012  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A3034h)]
*/





























































































































