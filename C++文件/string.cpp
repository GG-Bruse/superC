//编码
/*
1. ASCII编码
规定使用一个字节表示字母与二进制之间的对应关系(只能表示英文)

2. GB2312:
GB2312对汉字采用双字节编码

3. GBK:
1995年12月发布的汉字编码国家标准，是对GB2312编码的扩展，对汉字采用双字节编码

4. GBK18030:
是对GBK编码的扩展，采用单字节、双字节和四字节三种方式对字符编码。兼容GBK和GB2312字符集。

5. Unicode编码(万国码):
Unicode用一些基本的保留字符编制了三套编码方式。它们分别是UTF-8，UTF-16和UTF-32
	(1)UTF-8编码:
	UTF-8是Unicode的实现方式之一。UTF-8最大的一个特点，就是它是一种变长的编码方式。它可以使用1~4个字节表示一个符号，根据不同的符号而变化字节长度
	(2)UTF-16:
	介于UTF-8和UTF-32之间，使用2个或者4个字节存储，长度即固定又可变。
	(3)UTF-32:
	一种固定长度的编码方案，不管自负编号大小，始终使用4个字节来存储。
*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	const char test1[] = "包佳毅";
//	char test2[] = { -80,-4,-68,-47,-46,-29,0 };
//	cout << test1 << endl;
//	cout << test2 << endl;//包佳毅
//	return 0;
//}
































//C语言中的字符串
/*
C语言中，字符串是以'\0'结尾的一些字符的集合，为了操作方便，C标准库中提供了一些str系列的库函数，
但是这些库函数与字符串是分离开的，不太符合OOP的思想，而且底层空间需要用户自己管理，稍不留神可能还会越界访问
*/



//string类
/*
1.字符串是表示字符序列的类

2.标准的字符串类提供了对此类对象的支持，其接口类似于标准字符容器的接口，但添加了专门用于操作单字节字符字符串的设计特性

3.string类是使用char作为它的字符类型，使用它的默认char_traits和分配器类型

4.string类是basic_string模板类的一个实例，它使用char来实例化basic_string模板类，并用char_traits和allocator作为basic_string的默认参数

5.这个类独立于所使用的编码来处理字节:
若用来处理多字节或变长字符(如UTF-8)的序列，这个类的所有成员(如长度或大小)以及它的迭代器，将仍然按照字节(而不是实际编码的字符)来操作。


总结:
1.string是表示字符串的字符串类
2.该类的接口与常规容器的接口基本相同，再添加了一些专门用来操作string的常规操作。
3.string在底层实际是:
basic_string模板类的别名，typedef basic_string<char, char_traits, allocator>string;
4.不能操作多字节或者变长字符的序列。
5.在使用string类时，必须包含#include头文件以及using namespace std;
*/































//string类的常用接口说明(不全,查文档)

//string类对象的常见构造
/*
string()						构造空的string类对象，即空字符串
string(const char* s)			用C-string来构造string类对象
string(size_t n, char c)		string类对象中包含n个字符c
string(const string&s)			拷贝构造函数
*/



//string类对象的容量操作
/*
size		返回字符串有效字符长度
length		返回字符串有效字符长度
capacity	返回空间总大小
empty		检测字符串是否为空串，是返回true，否则返回false
clear		清空有效字符
reserve		为字符串预留空间(开空间)
resize		将有效字符的个数改成n个，多出的空间用字符c填充(开空间+初始化)

注意:
1. size()与length()方法底层实现原理完全相同，引入size()的原因是为了与其他容器的接口保持一致，一般情况下基本都是用size()。

2. clear()只是将string中有效字符清空，不改变底层空间大小。

3. resize(size_t n) 与 resize(size_t n, char c)都是将字符串中有效字符个数改变到n个，
不同的是当字符个数增多时:
resize(n)用0来填充多出的元素空间，resize(size_t n, char c)用字符c来填充多出的元素空间。
resize在改变元素个数时，如果是将元素个数增多，可能会改变底层容量的大小，如果是将元素个数减少，底层空间总大小不变。

4. reserve(size_t res_arg = 0):
为string预留空间，不改变有效元素个数，当reserve的参数小于string的底层空间总大小时，reserve不会改变容量大小
*/



//string类对象的访问及遍历操作
/*
operator[]			返回pos位置的字符，const string类对象调用
at					返回pos位置的字符，越界抛异常
begin + end			begin获取第一个字符的迭代器 + end获取最后一个字符下一个位置的迭代器 iterator
rbegin + rend		rbegin获取最后一个字符的迭代器 +rend获取第一个字符前一个位置的迭代器 reverse_iterator
cbegin + cend		const_iterator
crbegin + crend		const_reverse_iterator
范围for				C++11支持更简洁的范围for的新遍历方式
*/



//string类对象的修改操作
/*
push_back		在字符串后尾插字符c
append			在字符串后追加一个字符串
operator+=		在字符串后追加字符串str
c_str			返回C格式字符串
find + npos		从字符串pos位置开始往后找字符c，返回该字符在字符串中的位置
rfind			从字符串pos位置开始往前找字符c，返回该字符在字符串中的位置
substr			在str中从pos位置开始，截取n个字符，然后将其返回
erase			从字符串中删除字符

注意:
1. 在string尾部追加字符时，s.push_back(c) / s.append(1, c) / s += 'c'三种的实现方式差不多，
一般情况下string类的+=操作用的比较多，+=操作不仅可以连接单个字符，还可以连接字符串。

2. 对string操作时，若能够大概预估到放多少字符，可以先通过reserve把空间预留好
*/
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string filename("strig.cpp");
//	filename += '\0';
//	filename += "STL.cpp";
//	cout << filename << endl;//strig.cppSTL.cpp		以对象的size为准
//	cout << filename.c_str() << endl;//strig.cpp	遇到'\0'终止
//	return 0;
//}



//string类非成员函数
/*
operator+				尽量少用，因为传值返回，导致深拷贝效率低
operator>>				输入运算符重载
operator<<				输出运算符重载
getline					获取一行字符串
relational operators	大小比较

转换:
stoi			Convert string to integer (function template )
stol			Convert string to long int (function template )
stoul			Convert string to unsigned integer (function template )
stoll			Convert string to long long (function template )
stoull			Convert string to unsigned long long (function template )
stof			Convert string to float (function template )
stod			Convert string to double (function template )
stold			Convert string to long double (function template )
to_string		Convert numerical value to string (function )
*/


































//vs和g++下string结构的说明
/*
注意:下述结构是在32位平台下进行验证，32位平台下指针占4个字节。

1.vs下string的结构:
string总共占28个字节，内部结构稍微复杂一点，先是有一个联合体，联合体用来定义string中字符串的存储空间:
(1)当字符串长度小于16时，使用内部固定的字符数组来存放
(2)当字符串长度大于等于16时，从堆上开辟空间
原因:
大多数情况下字符串的长度都小于16，那string对象创建好之后，内部已经有了16个字符数组的固定空间，不需要通过堆创建，效率高

2.g++下string的结构:
g++下，string是通过写时拷贝实现的，string对象总共占4个字节，内部只包含了一个指针，该指针将来指向一块堆空间，内部包含了如下字段:
(1)空间总大小
(2)字符串有效长度
(3)引用计数
(4)指向堆空间的指针，用来存储字符串
*/
/*
写时拷贝:(谁写谁拷贝)
延迟拷贝,是在浅拷贝的基础之上增加了引用计数的方式来实现的。
引用计数:
用来记录资源使用者的个数。在构造时，将资源的计数给成1，每增加一个对象使用该资源，就给计数增加1，
当某个对象被销毁时，先给该计数减1，然后再检查是否需要释放资源，
如果计数为1，说明该对象时资源的最后一个使用者，将该资源释放；否则就不能释放，因为还有其他对象在使用该资源。
*/























//模拟实现string
/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::ostream;
using std::istream;
namespace bjy
{
	class string
	{
	public:
		//const static size_t npos = -1;//特例:const static可以直接当成定义初始化
		static size_t npos;
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}



		string() :_str(new char[1]), _size(0), _capacity(0)
		{
			_str[0] = '\0';
		}
		//string(const char* str) :_str(new char[strlen(str) + 1]), _size(strlen(str)), _capacity(_size)//初始化顺序依赖声明顺序
		//{
		//	strcpy(_str, str);//内容拷贝
		//}
		string(const char* str)
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);//内容拷贝
		}
		


		//传统写法
		//string(const string& str)//深拷贝
		//{
		//	_size = str._size;
		//	_capacity = str._capacity;
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, str._str);
		//}
		//现代写法
		string(const string& str):_str(nullptr),_size(0),_capacity(0)//使用初始化列表初始化，避免交换脏数据
		{
			string strTemp(str._str);//调用构造函数
			swap(strTemp);
		}



		//string& operator=(const string& str)//传统写法
		//{
		//	if (this != &str)
		//	{
		//		char* pTemp = new char[strlen(str._str) + 1];
		//		strcpy(pTemp, str._str);
		//		delete[] _str;
		//		_str = pTemp;
		//		_size = str._size;
		//		_capacity = str._capacity;
		//	}
		//	return *this;
		//}
		//string& operator=(const string& str)//现代写法1
		//{
		//	if (this != &str)
		//	{
		//		string strTemp(str._str);
		//		swap(strTemp);
		//	}
		//	return *this;
		//}
		string& operator=(string str)//现代写法2:通过传值传参，使得str代替strTemp
		{
			swap(str);
			return *this;
		}


		
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		bool operator>(const string& str)const
		{
			return strcmp(_str, str._str) > 0;
		}
		bool operator==(const string& str)const
		{
			return strcmp(_str, str._str) == 0;
		}
		bool operator>=(const string& str)const
		{
			return (*this > str || *this == str);
		}
		bool operator<=(const string& str)const
		{
			return !(*this > str);
		}
		bool operator<(const string& str)const
		{
			return !(*this >= str);
		}

		

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size >= _capacity)
				reserve(_capacity == 0 ? 3 : _capacity * 2);
			for (size_t end = _size + 1; end > pos; --end)
			{
				_str[end] = _str[end - 1];
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t lenth = strlen(str);
			if (_size + lenth >= _capacity)
				reserve(_capacity + lenth);
			for (size_t end = _size + lenth; end >= pos + lenth; --end)
			{
				_str[end] = _str[end - lenth];
			}
			strncpy(_str + pos, str, lenth);
			_size += lenth;
			return *this;
		}
		void push_back(char ch)
		{
			insert(_size,ch);
		}
		void append(size_t num, char ch)
		{
			reserve(_size + num);//避免多次扩容
			for (size_t i = 0; i < num; ++i)
			{
				push_back(ch);
			}
		}
		void append(const char* str)
		{
			insert(_size, str);
		}
		void append(const string& str)
		{
			append(str._str);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(const string& str)
		{
			append(str._str);
			return *this;
		}



		void reserve(size_t num)
		{
			if (num > _capacity)
			{
				char* temp = new char[num + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = num;
			}
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		void erase(size_t pos ,size_t lenth = npos)
		{
			assert(pos < _size);
			if (lenth == npos || pos + lenth >= _size)//需要删完
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + lenth);
				_size -= lenth;
			}
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}
		size_t find(char ch, size_t pos = 0)const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (ch == _str[i])
				{ 
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0)
		{
			assert(sub);
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, sub);
			if (ptr == nullptr)
				return npos;
			return ptr - _str;
		}
		string substr(size_t pos = 0, size_t len = npos)const
		{
			assert(pos < _size);
			size_t realLenth = len;
			if (len == npos || len + len > _size)
			{
				realLenth = _size - pos;
			}
			string strTemp;
			for (size_t i = 0; i < realLenth; ++i)
			{
				strTemp += _str[pos + i];
			}
			return strTemp;
		}
		
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
	private:
		void swap(string& strTemp)
		{
			::swap(_str, strTemp._str);
			::swap(_size, strTemp._size);
			::swap(_capacity, strTemp._capacity);
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	size_t string::npos = -1;
	ostream& operator<<(ostream& out, const string& str)
	{
		out << str.c_str();
		return out;
	}
	istream& operator>>(istream& in, string& str)
	{
		str.clear();
		const size_t N = 32;
		char buff[N];
		size_t i = 0;
		for(char chTemp = in.get();chTemp != ' ' && chTemp != '\n'; chTemp = in.get())
		{
			buff[i++] = chTemp;
			if (i == N - 1)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
		}
		buff[i] = '\0';
		str += buff;
		return in;
	}
}



using namespace bjy;
int main()
{
	string str1("hahaha");
	cout << str1.c_str() << endl;
	string str2;
	cout << str2.c_str() << endl;

	for (size_t i = 0; i < str1.size(); ++i)
	{
		str1[i] = 'b';
	}
	for (size_t i = 0; i < str1.size(); ++i)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	for (string::iterator it = str1.begin(); it != str1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto ch : str1)
	{
		cout << ch << " ";
	}
	cout << endl;

	string str3("1111111111111");
	string str4(str3);
	str3[0] = 'b';
	cout << str3.c_str() << endl;
	cout << str4.c_str() << endl;

	str3 = str4;
	str4[0] = 'j';
	cout << str3.c_str() << endl;
	cout << str4.c_str() << endl;

	str3.push_back('y');
	cout << str3.c_str() << endl;

	str3 += 'y';
	cout << str3.c_str() << endl;

	str3.append("yyy");
	cout << str3.c_str() << endl;

	str3 += "yyy";
	cout << str3.c_str() << endl;

	str3 += str4;
	cout << str3.c_str() << endl;

	str3.insert(3, 'b');
	cout << str3.c_str() << endl;

	str3.insert(4, "jy");
	cout << str3.c_str() << endl;

	str3.erase(6);
	cout << str3.c_str() << endl;

	string str5("bjyhahaha");
	cout << str5 << endl;

	string str8("hello world");
	cout << str8[str8.find('l')] << endl;
	str8 = str8.substr(2);
	cout << str8 << endl;
	str8.resize(100);
	cout << str8.size() << endl;;

	string str6("hello");
	string str7;
	cin >> str6>>str7;
	cout << str6 <<str7<< endl;

	return 0;
}
*/




























































