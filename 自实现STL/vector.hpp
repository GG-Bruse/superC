#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NEW 1
#include<iostream>
#include<algorithm>
#include<cassert>
#include"reverse_iterator.h"
using std::swap;
namespace bjy
{
	template<class T>
	class vector
	{
	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef __reverse_iterator<iterator, reference, T*> reverse_iterator;
		typedef __reverse_iterator<const_iterator, const_reference, const value_type*> const_reverse_iterator;
	public:
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator begin()const { return _start; }
		const_iterator end()const { return _finish; }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rbegin()const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend()const { return const_reverse_iterator(begin()); }

		vector() :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
#ifdef OLD1
		vector(const vector<int>& temp) {
			_start = new T[temp.capacity()];
			//memcpy(_start, temp._start,sizeof(T)*temp.size());//自定义类型不可使用memcpy
			for (size_t i = 0; i < temp.size(); ++i) _start[i] = temp._start[i];
			_finish = _start + temp.size();
			_end_of_storage = _start + temp.capacity();
		}
#endif
#ifdef OLD2
		vector(const vector<int>& temp) :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
			reserve(temp.capacity());
			for (size_t i = 0; i < temp.size(); ++i)
				push_back(temp[i]);
		}
#endif
#ifdef NEW//现代写法
		template<class InputIterator>
		vector(InputIterator first, InputIterator last) {
			for (; first != last; ++first) push_back(*first);
		}
		vector(const vector<int>& temp) :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
			vector<int>worker(temp.begin(), temp.end());
			swap(worker);
		}
#endif
		vector(int n, const_reference val = T()) {
			reserve(n);
			for (int i = 0; i < n; ++i) push_back(val);
		}
		vector(size_t n, const_reference val = T()) {
			reserve(n);
			for (size_t i = 0; i < n; ++i) push_back(val);
		}
		~vector() {
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t capacity()const { return _end_of_storage - _start; }
		size_t size()const { return _finish - _start; }
		bool empty()const { return (size() == 0); }
		reference front() { return _start[0]; }
		const_reference front()const { return _start[0]; }
		reference back() { return _start[size() - 1]; }
		const_reference back()const { return _start[size() - 1]; }

		reference operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const_reference operator[](size_t pos)const {
			assert(pos < size());
			return _start[pos];
		}
		vector<T>& operator=(vector<T> temp) {
			swap(temp);
			return *this;
		}
		void swap(vector<T>& temp) {
			std::swap(_start, temp._start);
			std::swap(_finish, temp._finish);
			std::swap(_end_of_storage, temp._end_of_storage);
		}

		void reserve(size_t n) {
			size_t previous_size = size();
			if (n > capacity()) {
				value_type* temp = new value_type[n];
				if (_start) {
					for (size_t i = 0; i < previous_size; ++i) temp[i] = _start[i];
					delete[] _start;
				}
				_start = temp;
				_finish = _start + previous_size;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const_reference val = T()) {
			if (n > capacity())reserve(n);
			if (n > size())
				while (_finish < _end_of_storage) *_finish++ = val;
			else
				_finish = _start + n;
		}
		iterator insert(iterator pos, const_reference data) {
			assert((pos >= _start) && (pos <= _finish));
			if (_finish >= _end_of_storage) {
				size_t lenth = pos - _start;//记录,避免迭代器失效
				reserve(capacity() == 0 ? 6 : capacity() * 2);
				pos = _start + lenth;//更新
			}
			for (iterator cur = _finish - 1; cur >= pos; --cur)
				*(cur + 1) = *cur;
			*pos = data;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos) {
			assert((pos >= _start) && (pos < _finish));
			for (iterator cur = pos + 1; cur < _finish; ++cur)
				*(cur - 1) = *cur;
			--_finish;
			return pos;
		}
		void push_back(const_reference data) {
			if (_finish >= _end_of_storage)
				reserve(capacity() == 0 ? 6 : capacity() * 2);
			*(_finish++) = data;
		}
		void pop_back() {
			assert(_finish > _start);
			--_finish;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}