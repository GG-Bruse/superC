//介绍
/*
1.vector是表示可变大小数组的序列容器

2.vector采用的连续存储空间来存储元素
可以采用下标对vector的元素进行访问，和数组一样高效。
但是又不像数组，它的大小是可以动态改变的，而且它的大小会被容器自动处理。

3.本质讲，vector使用动态分配数组来存储它的元素。当新元素插入时候，这个数组需要被重新分配大小为了增加存储空间。
其做法是，分配一个新的数组，然后将全部元素移到这个数组。
就时间而言，这是一个相对代价高的任务，因为每当一个新的元素加入到容器的时候，vector并不会每次都重新分配大小。

4.vector分配空间策略:
vector会分配一些额外的空间以适应可能的增长，因为存储空间比实际需要的存储空间更大。
不同的库采用不同的策略权衡空间的使用和重新分配。但是无论如何，重新分配都应该是对数增长的间隔大小，以至于在末尾插入一个元素的时候是在常数时间的复杂度完成的。

5.vector占用了更多的存储空间，为了获得管理存储空间的能力，并且以一种有效的方式动态增长。

6.与其它动态序列容器相比（deque, list and forward_list）， vector在访问元素的时候更加高效，在末尾添加和删除元素相对高效。
对于其它不在末尾的删除和插入操作，效率更低。比起list和forward_list统一的迭代器和引用更好
*/



//注意:
/*
1.vs下扩容capacity是按1.5倍增长的，g++扩容是按2倍增长的
  vs是PJ版本STL，g++是SGI版本STL
2.vector<char>与string的差别:
(1)string数据结尾存在'\0'
(2)用法与接口提供上不同		+=、find、比较大小、operator<<、operator>>
*/

































//vector迭代器失效问题(出现扩容、缩容、越界迭代器失效)
/*
迭代器的主要作用就是让算法能够不用关心底层数据结构，其底层实际就是一个指针，或者是对指针进行了封装，
比如:vector的迭代器就是原生态指针T* 。因此迭代器失效，实际就是迭代器底层对应指针所指向的空间被销毁了，
而使用一块已经被释放的空间，造成的后果是程序崩溃(即如果继续使用已经失效的迭代器，程序可能会崩溃)。
*/
/*
1.会引起其底层空间改变的操作，都有可能是迭代器失效，比如:resize、reserve、insert、assign、push_back等

2.指定位置元素的删除操作erase:
erase删除pos位置元素后，pos位置之后的元素会往前搬移，没有导致底层空间的改变，理论上讲迭代器不应该会失效
但是:如果pos刚好是最后一个元素，删完之后pos刚好是end的位置，而end位置是没有元素的，那么该pos就失效了，不可继续访问。
因此删除vector中任意位置上元素时(erase的实现不同，内部有可能进行缩容)，vs就认为该位置迭代器失效

3.注意:Linux下，g++编译器对迭代器失效的检测并不是非常严格，处理也没有vs下极端

4. 与vector类似，string在插入+扩容操作+erase之后，迭代器也会失效

解决:在使用前，对迭代器重新赋值即可
*/














































#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
namespace bjy
{
	template<class T>
	class vector
	{
	public:
		typedef T value_type;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef value_type& reference;
		typedef const value_type& const_reference;
	public:
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator begin()const { return _start; }
		const_iterator end()const { return _finish; }

		vector():_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
		~vector() {
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t capacity()const { return _end_of_storage - _start; }
		size_t size()const { return _finish - _start; }

		reference operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const_reference& operator[](size_t pos)const {
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n) {
			size_t previous_size = size();
			if (n > capacity()) {
				value_type* temp = new value_type[n];
				if (_start){
					memcpy(temp, _start,sizeof(value_type)*size());
					delete[] _start;
				}
				_start = temp;
				_finish = _start + previous_size;
				_end_of_storage = _start + n;
			}
		}
		void insert(iterator pos, const_reference data) {
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
		}
		iterator erase(iterator pos) {
			assert((pos >= _start) && (pos < _finish));
			for (iterator cur = pos + 1; cur < _finish; ++cur)
				*(cur - 1) = *cur;
			--_finish;
			return pos;
		}
		void push_back(const_reference data){
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

#include<algorithm>
using namespace bjy;
using std::cout;
using std::endl;
using std::find;
int main()
{
	vector<int>v;
	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(i + 1);
	}
	
	/*vector<int>::iterator it = find(v.begin(), v.end(), 5);
	v.insert(it, 30);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(i + 1);
	}

	it = find(v.begin(), v.end(), 5);
	v.erase(it);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/

	for (vector<int>::iterator it = v.begin(); it != v.end();) {
		if (*it % 2 == 0) 
		{
			it = v.erase(it);
		}
		else{
			++it;
		}
	}
	for (auto e : v) 
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}



















































