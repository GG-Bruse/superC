#pragma once
#include<algorithm>
#include"vector.hpp"
#include<deque>
using std::swap;
using bjy::vector;
using std::deque;
namespace bjy
{
	template<class T, class Sequence = deque<T>>
	class queue
	{
	public:
		void push(const T& data) { _container.push_back(data); }
		void pop() { _container.pop_front(); }
		T& front() { return _container.front(); }
		const T& front()const { return _container.front(); }
		T& back() { return _container.back(); }
		const T& back()const { return _container.back(); }
		bool empty()const { return _container.empty(); }
		size_t size()const { return _container.size(); }
	private:
		Sequence _container;
	};
}


namespace bjy
{
	template<class T = void>
	struct less {
		bool operator() (const T& left, const T& right) { return left < right; }
	};
	template<class T = void>
	struct greater {
		bool operator() (const T& left, const T& right) { return left > right; }
	};

	template<class T, class Sequence = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue() {}
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {
			for (; first != last; ++first) {
				_container.push_back(*first);
			}
			for (int i = (_container.size() - 1 - 1) / 2; i >= 0; --i) {
				adjust_down(i);
			}
		}
		void adjust_up(size_t child) {
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0) {
				if (com(_container[parent], _container[child])) {
					std::swap(_container[child], _container[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else { break; }
			}
		}
		void adjust_down(size_t parent) {
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _container.size()) {
				//选出左右孩子中大的一个
				if (child + 1 < _container.size() && com(_container[child], _container[child + 1])) {
					++child;
				}
				if (com(_container[parent], _container[child])) {
					std::swap(_container[child], _container[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else { break; }
			}
		}
		void push(const T& data) {
			_container.push_back(data);
			adjust_up(_container.size() - 1);
		}
		void pop() {
			std::swap(_container.front(), _container.back());
			_container.pop_back();
			adjust_down(0);
		}
		const T& top() { return _container[0]; }
		size_t size()const { _container.size(); }
		bool empty()const { return _container.empty(); }
	private:
		Sequence _container;
	};
}


