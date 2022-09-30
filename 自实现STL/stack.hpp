#pragma once
#include<deque>
using std::deque;
namespace bjy
{
	template<class T, class Sequence = deque<T>>
	class stack
	{
	public:
		void push(const T& data) { _container.push_back(data); }
		void pop() { _container.pop_back(); }
		T& top() { return _container.back(); }
		const T& top()const { return _container.back(); }
		bool empty()const { return _container.empty(); }
		size_t size()const { return _container.size(); }
	private:
		Sequence _container;
	};
}