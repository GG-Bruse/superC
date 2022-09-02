#pragma once
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
		typedef char* iterator;
		typedef const char* const_iterator;
		//const static size_t npos = -1;//特例:const static可以直接当成定义初始化
		static size_t npos;
		
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;

		string():_str(new char[1]), _size(0), _capacity(0)
		{
			_str[0] = '\0';
		}
		string(const char* str);

		////传统写法
		////string(const string& str)//深拷贝
		////{
		////	_size = str._size;
		////	_capacity = str._capacity;
		////	_str = new char[_capacity + 1];
		////	strcpy(_str, str._str);
		////}
		////现代写法
		string(const string& str) :_str(nullptr), _size(0), _capacity(0)//使用初始化列表初始化，避免交换脏数据
		{
			string strTemp(str._str);//调用构造函数
			swap(strTemp);
		}

		string& operator=(string str);
		char& operator[](size_t pos);
		const char& operator[](size_t pos)const;
		bool operator>(const string& str)const;
		bool operator==(const string& str)const;
		bool operator>=(const string& str)const;
		bool operator<=(const string& str)const;
		bool operator<(const string& str)const;

		string& insert(size_t pos, char ch);
		string& insert(size_t pos, const char* str);
		void push_back(char ch);
		void append(size_t num, char ch);
		void append(const char* str);
		void append(const string& str);
		string& operator+=(char ch);
		string& operator+=(const char* str);
		string& operator+=(const string& str);

		void reserve(size_t num);
		const char* c_str()const;
		size_t size()const;
		void erase(size_t pos, size_t lenth = npos);
		void clear();
		size_t find(char ch, size_t pos = 0)const;
		void resize(size_t n, char ch = '\0');
		size_t find(const char* sub, size_t pos);
		string substr(size_t pos = 0, size_t len = npos)const;
		
		~string();;
		
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
	ostream& operator<<(ostream& out, const string& str);
	istream& operator>>(istream& in, string& str);
}
