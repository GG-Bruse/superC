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
































#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
namespace bjy
{
	template<class T>
	class vector
	{
	public:
		typedef T value_type;
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		vector():_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
		~vector() {
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		void push_back(value_type& data){

		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}




















































