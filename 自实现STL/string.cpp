#define _CRT_SECURE_NO_WARNINGS

#include"string.h"
using namespace bjy;

typedef char* iterator;
typedef const char* const_iterator;
size_t string::npos = -1;



iterator string::begin()
{
	return _str;
}
iterator bjy::string::end()
{
	return _str + _size;
}
const_iterator bjy::string::begin()const
{
	return _str;
}
const_iterator bjy::string::end()const
{
	return _str + _size;
}



//string(const char* str = "") :_str(new char[strlen(str) + 1]), _size(strlen(str)), _capacity(_size)//初始化顺序依赖声明顺序
//{
//	strcpy(_str, str);//内容拷贝
//}
bjy::string::string(const char* str)
{
	_size = strlen(str);
	_capacity = _size;
	_str = new char[_size + 1];
	strcpy(_str, str);//内容拷贝
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
string& bjy::string::operator=(string str)//现代写法2:通过传值传参，使得str代替strTemp
{
	swap(str);
	return *this;
}



char& bjy::string::operator[](size_t pos)
{
	assert(pos < _size);
	return _str[pos];
}
const char& bjy::string::operator[](size_t pos)const
{
	assert(pos < _size);
	return _str[pos];
}
bool bjy::string::operator>(const string& str)const
{
	return strcmp(_str, str._str) > 0;
}
bool bjy::string::operator==(const string& str)const
{
	return strcmp(_str, str._str) == 0;
}
bool bjy::string::operator>=(const string& str)const
{
	return (*this > str || *this == str);
}
bool bjy::string::operator<=(const string& str)const
{
	return !(*this > str);
}
bool bjy::string::operator<(const string& str)const
{
	return !(*this >= str);
}



string& bjy::string::insert(size_t pos, char ch)
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
string& bjy::string::insert(size_t pos, const char* str)
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
void bjy::string::push_back(char ch)
{
	insert(_size, ch);
}
void bjy::string::append(size_t num, char ch)
{
	reserve(_size + num);//避免多次扩容
	for (size_t i = 0; i < num; ++i)
	{
		push_back(ch);
	}
}
void bjy::string::append(const char* str)
{
	insert(_size, str);
}
void bjy::string::append(const string& str)
{
	append(str._str);
}
string& bjy::string::operator+=(char ch)
{
	push_back(ch);
	return *this;
}
string& bjy::string::operator+=(const char* str)
{
	append(str);
	return *this;
}
string& bjy::string::operator+=(const string& str)
{
	append(str._str);
	return *this;
}



void bjy::string::reserve(size_t num)
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
const char* bjy::string::c_str()const
{
	return _str;
}
size_t bjy::string::size()const
{
	return _size;
}
void bjy::string::erase(size_t pos, size_t lenth)
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
void bjy::string::clear()
{
	_str[0] = '\0';
	_size = 0;
}
size_t bjy::string::find(char ch, size_t pos)const
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
size_t bjy::string::find(const char* sub, size_t pos)
{
	assert(sub);
	assert(pos < _size);
	const char* ptr = strstr(_str + pos, sub);
	if (ptr == nullptr)
		return npos;
	return ptr - _str;
}
void bjy::string::resize(size_t n, char ch)
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
string bjy::string::substr(size_t pos, size_t len)const
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



bjy::string::~string()
{
	delete[] _str;
	_str = nullptr;
	_capacity = _size = 0;
}



ostream& bjy::operator<<(ostream& out, const string& str)
{
	out << str.c_str();
	return out;
}
istream& bjy::operator>>(istream& in, string& str)
{
	str.clear();
	const size_t N = 32;
	char buff[N];
	size_t i = 0;
	for (char chTemp = in.get(); chTemp != ' ' && chTemp != '\n'; chTemp = in.get())
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
