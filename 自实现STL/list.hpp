#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
#include"reverse_iterator.h"
using std::bidirectional_iterator_tag;
namespace bjy
{
	template<class T>
	struct list_node {
		list_node(const T& data = T()) : _next(nullptr), _prev(nullptr), _data(data) {}
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator {
		typedef list_node<T> list_node;
		typedef __list_iterator<T, Ref, Ptr> iterator;

		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef ptrdiff_t difference_type;

		__list_iterator(list_node* node) :_node(node) {}
		bool operator!=(const iterator& it)const { return _node != it._node; }
		bool operator==(const iterator& it)const { return _node == it._node; }
		Ref operator*() { return _node->_data; }
		Ptr operator->() { return &(operator*()); }
		iterator& operator++() {
			_node = _node->_next;
			return *this;
		}
		iterator operator++(int) {
			iterator temp(*this);
			_node = _node->_next;
			return temp;
		}
		iterator& operator--() {
			_node = _node->_prev;
			return *this;
		}
		iterator operator--(int) {
			iterator temp(*this);
			_node = _node->_prev;
			return temp;
		}
		iterator operator+(int num) {
			iterator temp(_node);
			if (num < 0) temp = operator-(-num);
			else for (int i = 0; i < num - 1; ++i) temp._node = temp._node->_next;
			return temp;
		}
		iterator operator-(int num) {
			iterator temp(_node);
			if (num < 0) temp = operator+(-num);
			else for (int i = 0; i < num; ++i) temp._node = temp._node->_prev;
			return temp;
		}
		list_node* _node;
	};

	template<class T>
	class list
	{
		typedef T value_type;
		typedef list_node<value_type> list_node;
		typedef value_type& reference;
		typedef const value_type& const_reference;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef __reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef __reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		iterator begin() { return iterator(_head->_next); }
		const_iterator begin()const { return const_iterator(_head->_next); }
		iterator end() { return iterator(_head); }
		const_iterator end()const { return const_iterator(_head); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin()const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend()const { return const_reverse_iterator(begin()); }

		void empty_initialize() {
			_head = new list_node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void swap(list<value_type>& lt) { std::swap(_head, lt._head); }
		void clear() { for (list<int>::iterator it = begin(); it != end(); ) it = erase(it); }
		list() { empty_initialize(); }
		template<class InputIterator>
		list(InputIterator first, InputIterator last) {
			empty_initialize();
			for (; first != last; ++first) {
				push_back(*first);
			}
		}
		list(const list<value_type>& lt) {
			empty_initialize();
			list<value_type> temp(lt.begin(), lt.end());
			swap(temp);
		}
		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}
		list<value_type>& operator=(list<value_type> lt) {
			swap(lt);
			return *this;
		}

		iterator insert(iterator pos, const_reference data) {
			list_node* newnode = new list_node(data);
			list_node* cur = pos._node;
			list_node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		void push_back(const_reference data) {
#if 0
			list_node* new_node = new list_node(data);
			list_node* tail = _head->_prev;
			tail->_next = new_node;
			new_node->_prev = tail;
			new_node->_next = _head;
			_head->_prev = new_node;
#else
			insert(end(), data);
#endif
		}
		void push_front(const_reference x) { insert(begin(), x); }

		iterator erase(iterator pos) {
			assert(pos != end());
			list_node* prev = (pos._node)->_prev;
			list_node* next = (pos._node)->_next;
			prev->_next = next;
			next->_prev = prev;
			delete (pos._node);
			return iterator(next);
		}
		void pop_back() { erase(--end()); }
		void pop_front() { erase(begin()); }

	private:
		list_node* _head;
	};
}