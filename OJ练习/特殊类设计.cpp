/*****************************************************不能被拷贝的类********************************************************/

//class Test1
//{
//public:
//	Test1() {};
//private:
//	Test1(const Test1&);
//	Test1 operator=(const Test1&);
//};

//class Test2
//{
//public:
//	Test2() {};
//	Test2(const Test2&) = delete;
//	Test2 operator=(const Test2&) = delete;
//};
















/*************************************************只能在堆区上创建对象的类***************************************************/
//class HeapOnly
//{
//public:
//	static HeapOnly* CreatObj() {
//		return new HeapOnly;
//	}
//private:
//	HeapOnly() {};
//	//防拷贝
//	HeapOnly(const HeapOnly&) = delete;/*防止类似这种情况 HeapOnly obj2(*obj); */
//};
//int main()
//{
//	HeapOnly* obj = HeapOnly::CreatObj();
//	return 0;
//}
















/**************************************************只能在栈上创建空间*********************************************************/
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	static StackOnly CreateObj() {
//		return StackOnly();
//	}
//private:
//	StackOnly():_data(10) {};
//	void* operator new(size_t) = delete;
//	void operator delete(void*) = delete;
//
//	StackOnly& operator=(const StackOnly&) = delete;
//	/*避免出现
//	StackOnly* obj = (StackOnly*)malloc(sizeof(StackOnly));
//	if(obj != nullptr) *obj = s1;
//	*/
//private:
//	int _data;
//};
//int main()
//{
//	StackOnly s1 = StackOnly::CreateObj();
//
//	static StackOnly s2(s1);
//	/*
//	无法避免，CreateObj返回局部变量必定调用拷贝构造，所以不能屏蔽拷贝构造
//	构造函数私有，避免直接调用构造函数在静态区创建对象
//	*/
//	return 0;
//}














/****************************************************不能被继承的类********************************************************/
//class Test1
//{
//public:
//	Test1 CreateObj() {//子类对象构造必定调用父类构造函数，将父类构造函数私有
//		return Test1();
//	}
//private:
//	Test1() {};
//};
//
//class Test2 final
//{
//	//...
//};















/*****************************************************饿汉模式*************************************************************/
//class SingleTon
//{
//public:
//	static SingleTon* GetInstance() {
//		return _inst;
//	}
//private:
//	SingleTon() {};
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//private:
//	static SingleTon* _inst;
//};
//SingleTon* SingleTon::_inst = new SingleTon;



/******************************************************懒汉模式************************************************************/

//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//class SingleTon
//{
//public:
//	SingleTon* GetInstance() {
//		if (_inst == nullptr) //避免后续多次加锁解锁
//		{
//			unique_lock<mutex>(_mtx);//使用RAII风格的锁，避免new抛出异常导致锁未释放
//			if (_inst == nullptr)//避免多次new 
//			{
//				_inst = new SingleTon();
//			}
//		}
//		return _inst;
//	}
//	static void DelInstance() {//确保释放时线程安全，避免多次释放
//		unique_lock<mutex>(_mtx);
//		if (_inst != nullptr) {
//			delete _inst;
//		}
//	}
//private:
//	SingleTon() {};
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//private:
//	static SingleTon* _inst;
//	static mutex _mtx;
//};
//SingleTon* SingleTon::_inst = nullptr;
//mutex SingleTon::_mtx;


//class SingleTon
//{
//public:
//	SingleTon* GetInstance() {
//		static SingleTon inst;//原子操作
//		return &inst;
//	}
//private:
//	SingleTon() {};
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//};