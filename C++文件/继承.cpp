/*
继承的概念
继承(inheritance)机制是面向对象程序设计使代码可以复用的最重要的手段，它允许程序员在保持原有类特性的基础上进行扩展，增加功能，这样产生新的类，称派生类。
继承呈现了面向对象程序设计的层次结构，体现了由简单到复杂的认知过程。继承是类设计层次的复用
*/
/*
总结:
1. 基类private成员在派生类中无论以什么方式继承都是不可见的。
这里的不可见是指基类的私有成员还是被继承到了派生类对象中，但是语法上限制派生类对象不管在类里面还是类外面都不能去访问它。

2. 基类private成员在派生类中是不能被访问，如果基类成员不想在类外直接被访问，但需要在派生类中能访问，就定义为protected。
可以看出保护成员限定符是因继承才出现的

3. 基类的私有成员在子类都是不可见。基类的其他成员在子类的访问方式 = Min(成员在基类的访问限定符，继承方式)，public > protected> private

4. 使用关键字class时默认的继承方式是private，使用struct时默认的继承方式是public，不过最好显示的写出继承方式

5. 在实际运用中一般使用都是public继承，几乎很少使用protetced/private继承，也不提倡使用protetced/private继承，
因为protetced/private继承下来的成员都只能在派生类的类里面使用，实际中扩展维护性不强
*/

//#include<iostream>
//#include<string>
//using std::cout;
//using std::endl;
//using std::string;
//class Person
//{
//protected:
//	string _name = "bjy";
//	int _age = 18;
//};
//class Student : public Person
//{
//protected:
//	int _stuid = 04;
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid = 05;
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	return 0;
//}









//继承中的作用域
/*
1. 在继承体系中基类和派生类都有独立的作用域

2. 子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问,这种情况叫隐藏,也叫重定义（在子类成员函数中，可以使用 基类::基类成员 显示访问）

3. 需要注意的是如果是成员函数的隐藏，只需要函数名相同就构成隐藏

4. 注意在实际中在继承体系里面最好不要定义同名的成员
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)// B中的fun和A中的fun不是构成重载，因为不是在同一作用域	B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.fun(10);//func(int i)->10
//	b.A::fun();//func()
//	return 0;
//}