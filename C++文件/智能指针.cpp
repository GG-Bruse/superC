#define _CRT_SECURE_NO_WARNINGS

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












//auto_ptr的实现原理：管理权转移的思想
//存在问题，不要使用


//unique_ptr的实现原理：简单粗暴的防拷贝


//shared_ptr引用计数
//shared存在循环引用的问题

//weak_ptr的设计初衷便是为了解决shared_ptr的循环引用问题








//#include <iostream>
//using namespace std;
//int main()
//{
//	std::auto_ptr<int> ap1(new int(1));
//	std::auto_ptr<int> ap2(ap1);
//	*ap2 = 10;
//	//*ap1 = 20; //error
//
//	std::auto_ptr<int> ap3(new int(1));
//	std::auto_ptr<int> ap4(new int(2));
//	ap3 = ap4;
//	cout << *ap3 << endl;//2
//	//cout << *ap4 << endl;//error
//	return 0;
//}



//namespace bjy
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr = nullptr):_ptr(ptr) {}
//		~auto_ptr() {
//			if (_ptr != nullptr) {
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//		auto_ptr(auto_ptr<T>& ap) {
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//		auto_ptr& operator=(auto_ptr<T>& ap) {
//			if (this != &ap) {
//				delete _ptr;
//				_ptr = ap._ptr;
//				ap._ptr = nullptr;
//			}
//			return *this;
//		}
//		T& operator*() { return *_ptr; }
//		T* operator->() { return _ptr; }
//	private:
//		T* _ptr;//指向所管理的资源
//	};
//}
//#include <iostream>
//int main()
//{
//	bjy::auto_ptr<int> ap1(new int(1));
//	bjy::auto_ptr<int> ap2(ap1);
//	*ap2 = 10;
//	//*ap1 = 20; //error
//
//	bjy::auto_ptr<int> ap3(new int(1));
//	bjy::auto_ptr<int> ap4(new int(2));
//	ap3 = ap4;
//	std::cout << *ap3 << std::endl;//2
//	//cout << *ap4 << endl;//error
//	return 0;
//}




//namespace bjy
//{
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr) :_ptr(ptr) {}
//		~unique_ptr() {
//			if (_ptr != nullptr) {
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//		T& operator*() { return *_ptr; }
//		T* operator->() { return _ptr; }
//		//防拷贝
//		unique_ptr(unique_ptr<T>& ap) = delete;
//		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
//	private:
//		T* _ptr;//指向所管理的资源
//	};
//}
//#include <iostream>
//int main()
//{
//	bjy::unique_ptr<int> up1(new int(10));
//	//bjy::unique_ptr<int> up2(up1); //error
//	std::cout << *up1 << std::endl;
//	return 0;
//}


//#include <iostream>
//int main()
//{
//	std::shared_ptr<int> sp1(new int(1));
//	std::shared_ptr<int> sp2(sp1);
//	*sp1 = 10;
//	*sp2 = 20;
//	std::cout << sp1.use_count() << std::endl; //2
//
//	std::shared_ptr<int> sp3(new int(1));
//	std::shared_ptr<int> sp4(new int(2));
//	sp3 = sp4;
//	std::cout << *sp3 << std::endl;//2
//	std::cout << sp3.use_count() << std::endl; //2
//	return 0;
//}




//namespace bjy
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr = nullptr):_ptr(ptr),_pCount(new size_t(1)) {}
//		~shared_ptr() 
//		{
//			if (--(*_pCount) == 0) 
//			{
//				if (_ptr != nullptr) {
//					delete _ptr;
//					_ptr = nullptr;
//				}
//				delete _pCount;
//				_pCount = nullptr;
//			}
//		}
//		shared_ptr(shared_ptr<T>& sp):_ptr(sp._ptr),_pCount(sp._pCount) {
//			++(*_pCount);
//		}
//		shared_ptr<T>& operator=(shared_ptr<T>& sp) {
//			if (_ptr != sp._ptr)
//			{
//				if (--(*_pCount) == 0) {//若引用计数为0,则释放该对象
//					delete _ptr;
//					delete _pCount;
//				}
//				_ptr = sp._ptr;
//				_pCount = sp._pCount;
//				++(*_pCount);
//			}
//			return *this;
//		}
//
//		size_t GetCount() { return *_pCount; }
//		T& operator*() { return *_ptr; }
//		T* operator->() { return _ptr; };
//	private:
//		T* _ptr;
//		size_t* _pCount;
//	};
//}
//#include <iostream>
//int main()
//{
//	bjy::shared_ptr<int> sp1(new int(1));
//	bjy::shared_ptr<int> sp2(sp1);
//	*sp1 = 10;
//	*sp2 = 20;
//	std::cout << sp1.GetCount() << std::endl; //2
//
//	bjy::shared_ptr<int> sp3(new int(1));
//	bjy::shared_ptr<int> sp4(new int(2));
//	sp3 = sp4;
//	std::cout << *sp3 << std::endl;//2
//	std::cout << sp3.GetCount() << std::endl; //2
//	return 0;
//}


//#include <iostream>
//#include <thread>
//void Function(bjy::shared_ptr<size_t>& sp, const size_t n) 
//{
//	for (size_t i = 0; i < n; ++i) {
//		bjy::shared_ptr<size_t> copy(sp);
//	}
//}
//int main()
//{
//	bjy::shared_ptr<size_t> sp(new size_t(0));
//
//	const size_t n = 10000;
//	std::thread t1(Function, std::ref(sp), n);
//	std::thread t2(Function, std::ref(sp), n);
//
//	t1.join();
//	t2.join();
//
//	std::cout << sp.GetCount() << std::endl; //预期：1
//	return 0;
//}



//#include <mutex>
//using std::mutex;
//using std::unique_lock;
//namespace bjy
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr = nullptr) :_ptr(ptr), _pCount(new size_t(1)), _pMtx(new mutex) {}
//		~shared_ptr() { ReleaseRef(); }
//		shared_ptr(shared_ptr<T>& sp) :_ptr(sp._ptr), _pCount(sp._pCount), _pMtx(sp._pMtx) {
//			AddRef();
//		}
//		shared_ptr<T>& operator=(shared_ptr<T>& sp) {
//			if (_ptr != sp._ptr) {//管理同一块空间的对象之间不需进行赋值操作
//				ReleaseRef();
//				_ptr = sp._ptr;
//				_pCount = sp._pCount;
//				_pMtx = sp._pMtx;
//				AddRef();
//			}
//			return *this;
//		}
//
//		size_t GetCount() { return *_pCount; }
//		T& operator*() { return *_ptr; }
//		T* operator->() { return _ptr; };
//
//	private:
//		void AddRef() {
//			unique_lock<mutex> lock(*_pMtx);
//			++(*_pCount);
//		}
//		void ReleaseRef()//flag为true表示引用计数已为0,需要删除锁
//		{
//			bool flag = false;
//			{
//				unique_lock<mutex> lock(*_pMtx);
//				if (--(*_pCount) == 0) //引用计数完成--
//				{
//					if (nullptr != _ptr) {
//						delete _ptr;
//						_ptr = nullptr;
//					}
//					delete _pCount;
//					_pCount = nullptr;
//					flag = true;
//				}
//			}
//			if (flag == true) delete _pMtx;
//		}
//	private:
//		T* _ptr;
//		size_t* _pCount;
//		mutex* _pMtx;
//	};
//}
//#include <iostream>
//#include <thread>
//void Function(bjy::shared_ptr<size_t>& sp, const size_t n) 
//{
//	for (size_t i = 0; i < n; ++i) {
//		bjy::shared_ptr<size_t> copy(sp);
//	}
//}
//int main()
//{
//	bjy::shared_ptr<size_t> sp(new size_t(0));
//
//	const size_t n = 10000;
//	std::thread t1(Function, std::ref(sp), n);
//	std::thread t2(Function, std::ref(sp), n);
//
//	t1.join();
//	t2.join();
//
//	std::cout << sp.GetCount() << std::endl; //预期：1
//	return 0;
//}



//#include <iostream>
//struct ListNode 
//{
//	ListNode* _prev;
//	ListNode* _next;
//	size_t _value;
//	~ListNode() { std::cout << "~ListNode()" << std::endl; }
//};
//template<class T>
//struct DelArrary
//{
//	void operator()(const T* ptr) {
//		std::cout << "delete[]: " << ptr << std::endl;
//		delete[] ptr;
//	}
//};
//int main()
//{
//	std::shared_ptr<ListNode> sp1(new ListNode[10], DelArrary<ListNode>());
//	std::shared_ptr<FILE> sp2(fopen("test.cpp", "r"), [](FILE* ptr) {
//		std::cout << "fclose: " << ptr << std::endl;
//		fclose(ptr);
//	});
//
//	return 0;
//}




//#include <iostream>
//using namespace std;
//struct ListNode
//{
//	std::weak_ptr<ListNode> _next;
//	std::weak_ptr<ListNode> _prev;
//	size_t _val = 10;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	std::shared_ptr<ListNode> node1(new ListNode);
//	std::shared_ptr<ListNode> node2(new ListNode);
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	//...
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}




//namespace bjy
//{
//	template<class T>
//	class weak_ptr
//	{
//	public:
//		weak_ptr(const weak_ptr<T>& wp)noexcept :_ptr(ptr) {}
//		weak_ptr(const shared_ptr<T>& sp)noexcept :_ptr(sp.get()) {}
//		weak_ptr& operator=(const shared_ptr<T>& sp) {
//			_ptr = sp.get();
//			return *this;
//		}
//		T& operator*() { return *_ptr; };
//		T* operator->() { return _ptr; };
//	private:
//		T* _ptr;
//	};
//}