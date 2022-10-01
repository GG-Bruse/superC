#pragma once
namespace bjy
{
	template<class Iterator,class Ref,class Ptr>
	struct __reverse_iterator//µü´úÆ÷ÊÊÅäÆ÷
	{
		typedef __reverse_iterator<Iterator,Ref,Ptr> reverse_iterator;
		__reverse_iterator(Iterator it):_current(it) {}

		reverse_iterator operator++() {
			--_current;
			return *this;
		}
		reverse_iterator operator--() {
			++_current;
			return *this;
		}
		Ref operator*() { 
			Iterator temp = _current;
			return *--temp;
		}
		Ref operator->() { return &(operator*()); }
		bool operator!=(const reverse_iterator& it) { return _current != it._current; }

		Iterator _current;
	};
}