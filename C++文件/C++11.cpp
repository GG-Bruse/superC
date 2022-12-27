//列表初始化
/*
在C++98中，标准允许使用花括号{}对数组或者结构体元素进行统一的列表初始值设定。
C++11扩大了用大括号括起的列表(初始化列表)的使用范围，使其可用于所有的内置类型和用户自定义的类型。使用初始化列表时，可添加等号(=)也可不添加。
创建对象时也可以使用列表初始化方式调用构造函数初始化
*/

//#include <iostream>
//using namespace std;
//struct Point{
//	int _x;
//	int _y;
//};
//class Date
//{
//public:
//	Date(int year, int month, int day):_year(year), _month(month), _day(day){
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	int x1 = 1;
//	int x2{ 2 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//	
//	int* pa = new int[4]{ 0 };// C++11中列表初始化也可以适用于new表达式中
//
//	Date d1(2022, 1, 1);
//	Date d2{ 2022, 1, 2 };//调用构造函数初始化
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}



//initializer_list

//#include <iostream>
//using namespace std;
//int main()
//{
//	auto il = { 10,20,30 };//{}的类型即为class std::initializer_list<int>
//	cout << typeid(il).name() << endl;//class std::initializer_list<int>
//	return 0;
//}



//容器可以使用列表初始化，是重载了形参为initializer_list的构造函数
//#include <iostream>
//#include <map>
//using namespace std;
//int main()
//{
//	// 这里{"sort", "排序"}会先初始化构造一个pair对象
//	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//	return 0;
//}

//C++11后一切对象都支持使用列表初始化。但建议普通对象依然采用以前的方式进行初始化，容器有需求则可使用列表初始化。
















//auto
/*
在C++98中auto是一个存储类型的说明符，表明变量是局部自动存储类型，但是局部域中定义局部的变量默认就是自动存储类型，所以auto就没什么价值了。
C++11中废弃auto原来的用法，将其用于实现自动类型腿断。这样要求必须进行显示初始化，让编译器将定义对象的类型设置为初始化值的类型。
*/
//decltype
/*
关键字decltype将变量的类型声明为表达式指定的类型
*/
//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret的类型是double
//	decltype(&x) p; // p的类型是int const *
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}








//STL中的变化
/*
1.C++11增加了unordered_map和unordered_set容器

2.增加了array(静态顺序表)
C数组越界检查薄弱，越界读基本检查不出来，越界写抽查
但实际情况是很少是使用array，习惯使用C数组，或者使用vector + resize

3.增加了forward_list(单链表)

4.容器内部的变化
	都支持了initializer_list,用来支持列表初始化、
	比较鸡肋的接口，如:cbegin、cend等
	移动构造和移动赋值
	右值引用参数的插入
*/


































#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <array>
#include <assert.h>
using namespace std;
namespace bjy
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造(深拷贝)" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 资源转移" << endl;
			swap(s);
		}

		// 拷贝赋值
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 拷贝赋值(深拷贝)" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string s) -- 移动赋值(资源移动)" << endl;
			swap(s);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

bjy::string to_string(int value)
{
	bjy::string str;

	//……

	return str;
}
int main()
{
	bjy::string ret = to_string(-3456);

	return 0;
}