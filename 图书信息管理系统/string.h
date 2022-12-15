#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NEW 1
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
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
		iterator begin(){ return _str; }
		iterator end(){ return _str + _size; }
		const_iterator begin()const{ return _str; }
		const_iterator end()const{ return _str + _size; }

		string() :_str(new char[1]), _size(0), _capacity(0){ _str[0] = '\0'; }

#ifdef STRING_CONST_CHARPTR_STR
		string(const char* str) :_str(new char[strlen(str) + 1]), _size(strlen(str)), _capacity(_size)//初始化顺序依赖声明顺序
		{
			strcpy(_str, str);//内容拷贝
		}
#endif
#ifndef STRING_CONST_CHARPTR_STR
		string(const char* str){
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);//内容拷贝
		}
#endif

#ifdef OLD//深拷贝
		string(const string& str){
			_size = str._size;
			_capacity = str._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, str._str);
		}
#endif
#ifdef NEW
	//现代写法
	string(const string& str) :_str(nullptr), _size(0), _capacity(0)//使用初始化列表初始化，避免交换脏数据
	{
		string strTemp(str._str);//调用构造函数
		swap(strTemp);
	}
#endif

#ifdef OLD//传统写法
	string& operator=(const string& str){
		if (this != &str){
			char* pTemp = new char[strlen(str._str) + 1];
			strcpy(pTemp, str._str);
			delete[] _str;
			_str = pTemp;
			_size = str._size;
			_capacity = str._capacity;
		}
		return *this;
	}
#endif
#ifdef OLDANDNEW//现代写法1
	string& operator=(const string& str){
		if (this != &str){
			string strTemp(str._str);
			swap(strTemp);
		}
		return *this;
	}
#endif
#ifdef NEW//现代写法2:通过传值传参，使得str代替strTemp
		string& operator=(string str){
			swap(str);
			return *this;
		}
#endif
		char& operator[](size_t pos){
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const{
			assert(pos < _size);
			return _str[pos];
		}
		bool operator>(const string& str)const{ return strcmp(_str, str._str) > 0; }
		bool operator==(const string& str)const{ return strcmp(_str, str._str) == 0; }
		bool operator>=(const string& str)const{ return (*this > str || *this == str); }
		bool operator<=(const string& str)const{ return !(*this > str); }
		bool operator<(const string& str)const{ return !(*this >= str); }

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
		void append(const char* str){ insert(_size, str); }
		void append(const string& str){ append(str._str); }
		string& operator+=(char ch){
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str){
			append(str);
			return *this;
		}
		string& operator+=(const string& str){
			append(str._str);
			return *this;
		}

		const char* c_str()const{ return _str; }
		size_t size()const{ return _size;}

		void erase(size_t pos ,size_t lenth = npos){
			assert(pos < _size);
			if (lenth == npos || pos + lenth >= _size){//需要删完
				_str[pos] = '\0';
				_size = pos;
			}
			else{
				strcpy(_str + pos, _str + pos + lenth);
				_size -= lenth;
			}
		}
		void clear(){
			_str[0] = '\0';
			_size = 0;
		}
		void resize(size_t n, char ch = '\0'){
			if (n > _size){
				reserve(n);
				for (size_t i = _size; i < n; ++i){
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else{
				_str[n] = '\0';
				_size = n;
			}
		}
		size_t find(char ch, size_t pos = 0)const{
			for (size_t i = pos; i < _size; ++i){
				if (ch == _str[i]) return i;
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0){
			assert(sub);
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, sub);
			if (ptr == nullptr) return npos;
			return ptr - _str;
		}
		string substr(size_t pos = 0, size_t len = npos)const{
			assert(pos < _size);
			size_t realLenth = len;
			if (len == npos || len + len > _size) realLenth = _size - pos;
			string strTemp;
			for (size_t i = 0; i < realLenth; ++i) strTemp += _str[pos + i];
			return strTemp;
		}
		void reserve(size_t num){
			if (num > _capacity){
				char* temp = new char[num + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = num;
			}
		}

		~string(){
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
	private:
		void swap(string& strTemp){
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
	ostream& operator<<(ostream& out, const string& str){
		out << str.c_str();
		return out;
	}
	istream& operator>>(istream& in, string& str){
		str.clear();
		const size_t N = 32;
		char buff[N];
		size_t i = 0;
		for(char chTemp = in.get();chTemp != ' ' && chTemp != '\n'; chTemp = in.get()){
			buff[i++] = chTemp;
			if (i == N - 1){
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


