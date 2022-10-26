
/*
多态是在不同继承关系的类对象，去调用同一函数，产生了不同的行为。
比如Student继承了Person。Person对象买票全价，Student对象买票半价
*/

/*
虚函数: 即被virtual修饰的类成员函数称为虚函数

虚函数的重写(覆盖): 派生类中有一个跟基类完全相同的虚函数(即派生类虚函数与基类虚函数的返回值类型、函数名字、参数列表完全相同)，
					称子类的虚函数重写了基类的虚函数



重写的特例:
1.子类虚函数不加virtual(父类加了)，依旧构成重写。实际使用中最好加上

2. 协变(基类与派生类虚函数返回值类型不同)
派生类重写基类虚函数时，与基类虚函数返回值类型不同。
即基类虚函数返回基类对象(不一定是本类，其他继承关系中的基类也行)的指针或者引用，
派生类虚函数返回派生类对象(不一定是本类，其他继承关系中的派生类也行)的指针或者引用时，称为协变

3.析构函数的重写(基类与派生类析构函数的名字不同) 建议将析构函数定义成虚函数
虽然函数名不相同，但这里编译器对析构函数的名称做了特殊处理，编译后析构函数的名称统一处理成destructor



在继承中要构成多态有两个条件:
1. 必须通过基类的指针或者引用调用虚函数
2. 被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写
*/


// C++11 override和final
/*
final:		修饰虚函数，表示该虚函数不能再被重写
override:	检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错
*/



//抽象类
/*
在虚函数的后面写上 = 0 ，则这个函数为纯虚函数。
包含纯虚函数的类叫做抽象类（也叫接口类），抽象类不能实例化出对象
派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象
纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承
*/

//#include<iostream>
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();//B->1
//	return 0;
//}
/*
普通函数继承是实现继承
虚函数重写是接口继承(即成员函数框架继承)、重写实现
*/







































//多态的原理

/*
除了_b成员，还多一个__vfptr放在对象的前面(注意有些平台可能会放到对象的最后面，这个跟平台有关)
对象中的这个指针我们叫做虚函数表指针(v代表virtual，f代表function)。
一个含有虚函数的类中都至少都有一个虚函数表指针，因为虚函数的地址要被放到虚函数表中，虚函数表也简称虚表。
虚函数表本质是一个存虚函数指针的指针数组，windows环境下这个数组最后面放了一个nullptr
*/
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//int main()
//{
//	cout << sizeof(Base) << endl;//8
//	return 0;
//}

/*
静态绑定又称为前期绑定(早绑定)，在程序编译期间确定了程序的行为，也称为静态多态，比如：函数重载
2. 动态绑定又称后期绑定(晚绑定)，是在程序运行期间，根据具体拿到的类型确定程序的具体行为，调用具体的函数，也称为动态多态
*/
































//单继承中的虚函数表
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};
//typedef void(*VFPTR)();
//void PrintVFTable(VFPTR table[]) {
//	for (int i = 0; table[i] != nullptr; ++i) {
//		cout << i << " " << (table + i) << " " << table[i] << " ";
//		table[i]();
//	}
//	cout << endl;
//}

//int main()
//{
//	Base b;//同一个类型的对象共用同一个虚函数表
//	Derive d;//vs下 无论是否完成重写，子类虚表和父类虚表都是不同的
//
//	PrintVFTable((VFPTR*)*(int*)&b);//取对象头部虚函数表指针
//	PrintVFTable((VFPTR*)*(int*)&d);
//	return 0;
//}






//多继承中的虚函数表
//#include<iostream>
//using namespace std;
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*VFPTR)();
//void PrintVFTable(VFPTR table[]) {
//	for (int i = 0; table[i] !=  nullptr; ++i) {
//		cout << i << " " << (table + i) << " " << table[i] << " ";
//		table[i]();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Derive d;
//	cout << sizeof(d) << endl;//20
//	PrintVFTable((VFPTR*)(*(int*)&d));
//	Base2* ptr = &d;
//	PrintVFTable((VFPTR*)(*(int*)(ptr)));
//	return 0;
//}
/*
多继承派生类的未重写的虚函数放在第一个继承基类部分的虚函数表中
*/






//#include<iostream>
//using namespace std;
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*VFPTR)();
//void PrintVFTable(VFPTR table[]) {
//	for (int i = 0; table[i] != nullptr; ++i) {
//		cout << i << " " << (table + i) << " " << table[i] << " ";
//		table[i]();
//	}
//	cout << endl;
//}
//int main()
//{
//	Derive d;
//	PrintVFTable((VFPTR*)(*(int*)&d));
//	Base2* ptr = &d;
//	PrintVFTable((VFPTR*)(*(int*)(ptr)));
//
//	printf("%p\n", &Derive::func1);//语法规定，成员函数必须加&才能取到其地址
//
//	d.func1();
//	Base1* ptr1 = &d;
//	ptr1->func1();
//	Base2* ptr2 = &d;
//	ptr2->func1();
//
//	return 0;
//}
/*
两个虚表中Derive::func1打印出函数的地址不一样
*/




























