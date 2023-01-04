//#include <iostream>
//using namespace std;
//
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr) :_ptr(ptr) {}
//
//	~SmartPtr(){
//		cout << "delete:" << _ptr << endl;
//		delete _ptr;
//	}
//
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	T* _ptr;
//};
//
//
//int div(){
//	int a, b;
//	cin >> a >> b;
//	if (b == 0) throw invalid_argument("除0错误");
//	return a / b;
//}
//
//void Func()
//{
//	SmartPtr<int> sp1(new int);//是否抛异常都会释放
//	SmartPtr<int> sp2(new int);
//
//	*sp1 = 0;
//	*sp2 = 2;
//
//	cout << div() << endl;
//}
//
//int main()
//{
//	try{
//		Func();
//	}
//	catch (exception& e){
//		cout << e.what() << endl;
//	}
//	return 0;
//}
