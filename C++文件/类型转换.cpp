//#include <stdio.h>
//int main()
//{
//	// 隐式类型转换
//	int i = 1;
//	double d = i;
//	printf("%d, %.2f\n", i, d);//1, 1.00
//	
//	// 显示的强制类型转换
//	int* p = &i;
//	int address = (int)p;
//	printf("%p %d\n", p, address);//008FF8EC 9435372
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;//12
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 12;
//
//	//这种情况使用static_cast会报错
//	//int *p = static_cast<int*>(a);//类型转换无效
//
//	int* p = reinterpret_cast<int*>(a);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	const int a = 2;
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << endl;//2
//	cout << *p << endl;//3
//	return 0;
//}










//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void f(){}
//public:
//	int _a = 0;
//};
//class B : public A
//{
//public:
//	int _b = 1;
//};
//
//void Func(A* pa)
//{
//	if (pa == nullptr) return;
//
//	//若pa是指向子类，那么可以转换，转换表达式返回正确的地址
//	//若pa是指向父类，那么不能转换，转换表达式返回nullptr
//
//	B* pb = dynamic_cast<B*>(pa); // 安全的
//	//B* pb = (B*)pa;             // 不安全
//
//	if (pb){
//		cout << "转换成功" << endl;
//		pb->_a++;
//		pb->_b++;
//		cout << pb->_a << ":" << pb->_b << endl;
//	}
//	else
//	{
//		cout << "转换失败" << endl;
//		pa->_a++;
//		cout << pa->_a << endl;
//	}
//}
//
//int main()
//{
//	//A aa;
//	//Func(&aa);
//	B bb;
//	Func(&bb);
//	return 0;
//}













//#include <iostream>
//using namespace std;
//class A1
//{
//public:
//	virtual void f(){}
//public:
//	int _a1 = 0;
//};
//
//class A2
//{
//public:
//	virtual void f(){}
//public:
//	int _a2 = 0;
//};
//
//class B : public A1, public A2
//{
//public:
//	int _b = 1;
//};
//
//int main()
//{
//	B bb;
//	A1* ptr1 = &bb;
//	A2* ptr2 = &bb;
//	cout << ptr1 << endl;
//	cout << ptr2 << endl << endl;
//
//	B* pb1 = (B*)ptr1;
//	B* pb2 = (B*)ptr2;
//	cout << pb1 << endl;
//	cout << pb2 << endl << endl;
//
//	B* pb3 = dynamic_cast<B*>(ptr1);
//	B* pb4 = dynamic_cast<B*>(ptr2);
//	cout << pb3 << endl;
//	cout << pb4 << endl << endl;
//
//	return 0;
//}















//自定义类型数据转为内置类型数据
//#include <iostream>
//using namespace std;
//class Test
//{
//public:
//	Test(const int data) :_data(data) { cout << "调用构造函数" << endl; }
//	Test(const Test& tmp) {
//		_data = tmp._data;
//		cout << "调用拷贝构造" << endl;
//	}
//	operator int(){
//		return _data;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	Test t = 1;
//	int a = t;
//	int b = t.operator int();
//	cout << a << " " << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Test
//{
//public:
//	Test(const int data) :_data(data) { cout << "调用构造函数" << endl; }
//	Test(const Test& tmp) {
//		_data = tmp._data;
//		cout << "调用拷贝构造" << endl;
//	}
//	explicit operator int(){//禁止隐式类型转换
//		return _data;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	Test t = 1;
//	//可以使用强制类型转换
//	int a = (int)t;
//	int b = static_cast<int> (t);
//	cout << a << " " << b << endl;
//	return 0;
//}