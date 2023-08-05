#define _CRT_SECURE_NO_WARNINGS
/************************************************* auto_ptr模拟实现 ******************************************************/

namespace bjy
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr):_ptr(ptr) {}
		~auto_ptr() {
			if (_ptr != nullptr) {
				delete _ptr;
				_ptr = nullptr;
			}
		}
		//因为涉及管理权转移，所以不可使用const类型
		auto_ptr(auto_ptr<T>& tmp) {
			_ptr = tmp._ptr;
			tmp._ptr = nullptr;
		}
		auto_ptr<T>& operator=(auto_ptr<T>& tmp) {
			if (this != tmp)
			{
				delete _ptr;
				_ptr = tmp._ptr;
				tmp._ptr = nullptr;
			}
			return *this;
		}

		T* operator->() { return _ptr; };
		T& operator*() { return *_ptr; }

	private:
		T* _ptr;
	};
}


/*************************************************** unique_ptr模拟实现 ***************************************************/

namespace bjy
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr) :_ptr(ptr) {};
		~unique_ptr() 
		{
			if (_ptr != nullptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T* operator->() { return _ptr; };
		T& operator*() { return *_ptr; }

		//防拷贝
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
		unique_ptr(const unique_ptr<T>&) = delete;
	private:
		T* _ptr;
	};
}






/*************************************************** shared_ptr模拟实现 ***************************************************/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
namespace bjy
{
	template<class T>
	struct Delete {
	public:
		void operator()(const T* ptr) {
			delete ptr;
		}
	};
	template<class T>
	struct DelArr {
		void operator()(const T* ptr) {
			cout << "delete[]: " << ptr << endl;
			delete[] ptr;
		}
	};

	template<class T, class D = Delete<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr, D del) :_ptr(ptr), _pCount(new size_t(1)), _del(del) {}
		~shared_ptr() { ReleaseRef(); }

		shared_ptr(const shared_ptr<T>& sp):_ptr(sp._ptr),_pCount(sp._pCount),_pMtx(sp._pMtx) {
			AddRef();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp) 
		{
			if (_ptr != sp._ptr)
			{
				ReleaseRef();
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				AddRef();
			}
			return *this;
		}

		size_t GetCount() { return *_pCount; };
		T* operator->() { return _ptr; };
		T& operator*() { return *_ptr; };

	private:
		inline void AddRef() {
			unique_lock<mutex>(*_pMtx);
			++(*_pCount);
		}
		void ReleaseRef()
		{
			bool flag = false;
			{
				unique_lock<mutex>(_pMtx);
				if (--(*_pCount) == 0)
				{
					if (_ptr != nullptr)
					{
						_del(_ptr);
						_ptr = nullptr;
					}
					delete _pCount;
					_pCount = nullptr;
					flag = true;
				}
			}
			if (flag) {
				delete _pMtx;
				_pMtx = nullptr;
			}
		}
		
	private:
		T* _ptr;
		size_t* _pCount;//引用计数
		mutex* _pMtx;
		D _del;
	};
}





/************************************************shared_ptr测试（不需重新编写）********************************************/

//#include <functional>
//using namespace bjy;
//struct ListNode
//{
//	ListNode* _prev;
//	ListNode* _next;
//	size_t _value;
//	~ListNode() { std::cout << "~ListNode()" << std::endl; }
//};
//int main()
//{
//	//仿函数示例
//	bjy::shared_ptr<ListNode, DelArr<ListNode>> sp1(new ListNode[10], DelArr<ListNode>());
//
//	//lambda示例1
//	bjy::shared_ptr<FILE, function<void(FILE*)>> sp2(fopen("test.cpp", "r"), [](FILE* ptr) {
//		cout << "fclose: " << ptr << endl;
//		fclose(ptr);
//	});
//
//	//lambda示例2
//	auto f = [](FILE* ptr) {
//		cout << "fclose: " << ptr << endl;
//		fclose(ptr);
//	};
//	bjy::shared_ptr<FILE, decltype(f)> sp3(fopen("test.cpp", "w"), f);
//
//	return 0;
//}






/************************************************ weak_ptr模拟实现 ********************************************************/
/*
weak_ptr<T>模板类中没有重载 * 和 -> 运算符，weak_ptr 类型指针只能访问所指的堆内存，而无法修改它
*/
namespace bjy
{
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr(const weak_ptr<T>& wp) :_ptr(ptr) {};
		weak_ptr(const shared_ptr<T>& sp) :_ptr(ptr) {};
		weak_ptr<T>& operator=(const shared_ptr<T>& sp) {
			_ptr = sp.get();
			return *this;
		}
	private:
		T* _ptr;
	};
}