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















//基类和派生类对象赋值转换(非隐式类型转换)
/*
1.派生类对象可以赋值给基类的对象、基类的指针、基类的引用。这里有个形象的说法叫切片或者切割。意思是把派生类中父类那部分切来赋值过去。

2.基类对象不能赋值给派生类对象

3.基类的指针或者引用可以通过强制类型转换赋值给派生类的指针或者引用。但是必须是基类的指针是指向派生类对象时才是安全的
这里基类如果是多态类型，可以使用RTTI(RunTime Type Information)的dynamic_cast来进行识别后进行安全转换
*/
















//派生类的 默认 成员函数
/*
1. 派生类的构造函数 必须 调用基类的构造函数初始化基类的那一部分成员。如果基类没有默认的构造函数，则必须在派生类构造函数的初始化列表阶段 显示调用 基类的构造函数

2. 派生类的拷贝构造函数 必须 调用基类的拷贝构造完成基类的拷贝初始化

3. 派生类的operator= 必须 要调用基类的operator=完成基类的复制

4. 派生类的析构函数会在被调用完成后 自动调用 基类的析构函数清理基类成员。因为这样才能保证派生类对象先清理派生类成员再清理基类成员的顺序。

5. 派生类对象初始化先调用基类构造再调派生类构造

6. 派生类对象析构清理先调用派生类析构再调基类的析构

7. 因为后续一些场景析构函数需要构成重写，重写的条件之一是函数名相同，那么编译器会对析构函数名进行特殊处理，统一处理成destrutor()
所以父类析构函数不加virtual的情况下，子类析构函数和父类析构函数构成隐藏关系
*/










//继承与静态成员
/*
基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少个子类，都只有一个static成员实例
*/











//复杂的菱形继承及菱形虚拟继承
/*
单继承: 一个子类只有一个直接父类时称这个继承关系为单继承
多继承: 一个子类有两个或以上直接父类时称这个继承关系为多继承
菱形继承: 菱形继承是多继承的一种特殊情况,菱形继承存在数据冗余和二义性的问题
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Person
//{
//public:
//	string _name;
//};
//class Student :public Person
//{
//protected:
//	int _num;
//};
//class Teacher :public Person
//{
//protected:
//	int _id;
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//int main()
//{
//	Assistant a;
//	//显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "bruse";
//	a.Teacher::_name = "peter";
//	return 0;
//}

/*
虚拟继承可以解决菱形继承的二义性和数据冗余的问题
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class A{
//public:
//	int _a;
//};
//class B :virtual public A{
//public:
//	int _b;
//};
//class C :virtual public A{
//public:
//	int _c;
//};
//class D : public B, public C{
//public:
//	int _d;
//};
//void func(B& data) {
//	cout << data._b << endl;
//}
//int main()
//{
//	D d;
//	d.B::_a = 2;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	B bb;
//	bb._a = 1;
//	bb._b = 2;
//	func(d);
//	func(bb);
//	return 0;
//}

/*
1.C++语法复杂，其实多继承就是一个体现。有了多继承，就存在菱形继承，有了菱形继承就有菱形虚拟继承，底层实现就很复杂。所以一般不建议设计出多继承，
一定不要设计出菱形继承。否则在复杂度及性能上都有问题

2. 多继承可以认为是C++的缺陷之一，很多后来的OO语言都没有多继承，如Java。
*/












//继承和组合
/*
1.public继承是一种is-a的关系。也就是说每个派生类对象都是一个基类对象。

2.组合是一种has-a的关系。假设B组合了A，每个B对象中都有一个A对象

3.继承允许你根据基类的实现来定义派生类的实现。这种通过生成派生类的复用通常被称为白箱复用(white-box reuse)
术语“白箱”是相对可视性而言：在继承方式中，基类的内部细节对子类可见 。继承一定程度破坏了基类的封装，基类的改变，对派生类有很大的影响。
派生类和基类间的依赖关系很强，耦合度高。

4.对象组合是类继承之外的另一种复用选择。新的更复杂的功能可以通过组装或组合对象来获得。
对象组合要求被组合的对象具有良好定义的接口。这种复用风格被称为黑箱复用(black-box reuse)，
因为对象的内部细节是不可见的。对象只以“黑箱”的形式出现。组合类之间没有很强的依赖关系，耦合度低。
优先使用对象组合有助于你保持每个类被封装。

5.实际尽量多去用组合。组合的耦合度低，代码维护性好。不过继承也有用武之地的，有
些关系就适合继承那就用继承，另外要实现多态，也必须要继承。类之间的关系可以用继承也可以用组合时，优先使用组合
*/











//如何实现一个无法被继承的类
/*
1.将其构造函数私有，让子类不可见 (当子类对象实例化时，无法调用父类构造函数)

2.C++11 final关键字 (推荐)
class A final{};
class B:public A{};
*/


