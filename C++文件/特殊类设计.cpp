//不能被拷贝的类
//拷贝只会发生在两个场景中：拷贝构造函数以及赋值运算符重载
//让该类不能调用拷贝构造函数以及赋值运算符重载即可
/*
1.将拷贝构造函数与赋值运算符重载只声明不定义，并且将其访问权限设置为私有即可
2.=delete
*/


//class Test
//{
//public:
//	Test() {}
//	//...
//private:
//	//C++98
//	Test(const Test&);
//	Test& operator=(const Test&);
//	//C++11
//	//Test(const Test&) = delete;
//	//Test& operator=(const Test&) = delete;
//};










//只能在堆上创建对象
//1.析构函数私有
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	void Delete() { delete this; }
//private:
//	~HeapOnly() {}
//private:
//	int _data;
//};
//int main()
//{
//	HeapOnly* p = new HeapOnly;
//	p->Delete();
//	return 0;
//}

//2.构造函数、拷贝构造私有
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	//提供公有的获取对象的静态方法
//	static HeapOnly* CreateObj(){
//		return new HeapOnly;
//	}
//private:
//	HeapOnly() :_data(0) {};
//	HeapOnly(const HeapOnly& tmp) = delete;
//private:
//	int _data;
//};
//int main()
//{
//	HeapOnly* obj = HeapOnly::CreateObj();
//	delete obj;
//	return 0;
//}














//只能在栈上创建对象
//构造函数私有
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	static StackOnly&& CreateObj() {
//		return StackOnly();
//	}
//
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	StackOnly():_data(0) {};
//private:
//	int _data;
//};
//int main()
//{
//	StackOnly so = StackOnly::CreateObj();
//
//	static StackOnly s1(so);//无法完全实现要求
//	return 0;
//}












//无法被继承的类
//1.C++98: 构造函数私有化，派生类中调不到基类的构造函数, 则无法继承
//2.final修饰类，表示该类不能被继承

//class Perent
//{
//public:
//	static Perent CreatePerentObj() {
//		return Perent();
//	}
//private:
//	Perent() {};
//};













//单例模式



//饿汉模式
//class SingleTon
//{
//public:
//	static SingleTon* GetInstance() {//全局访问点
//		return _inst;
//	}
//private:
//	SingleTon() {};//构造函数私有
//	//防拷贝
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//	static SingleTon* _inst;//指向单例对象的static指针
//};
//SingleTon* SingleTon::_inst = new SingleTon;//在程序入口前完成单例对象的初始化



//#include <thread>
//#include <mutex>
//using namespace std;
//class SingleTon
//{
//public:
//	static SingleTon* GetInstance() {//全局访问点
//		if (nullptr == _inst)
//		{
//			unique_lock<mutex>(_mtx);
//			if (nullptr == _inst) {
//				_inst = new SingleTon;
//			}
//		}
//	}
//private:
//	SingleTon() {};//构造函数私有
//	//防拷贝
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//	static SingleTon* _inst;//指向单例对象的static指针
//	static mutex _mtx;
//};
//SingleTon* SingleTon::_inst = nullptr;
//mutex SingleTon::_mtx;//定义，在程序入口前完成初始化



//class SignleTon
//{
//public:
//	static SignleTon* GetInstance() {
//		static SignleTon inst;
//		return &inst;
//	}
//private:
//	SignleTon() {}
//	SignleTon(const SignleTon&) = delete;
//	SignleTon& operator=(const SignleTon&) = delete;
//};