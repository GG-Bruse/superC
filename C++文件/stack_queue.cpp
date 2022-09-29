//stack的介绍
/*
1. stack是一种容器适配器，专门用在具有后进先出操作的上下文环境中，其删除只能从容器的一端进行元素的插入与提取操作。

2. stack是作为容器适配器被实现的，容器适配器即是对特定类封装作为其底层的容器，
并提供一组特定的成员函数来访问其元素，将特定类作为其底层的，元素特定容器的尾部(即栈顶)被压入和弹出。

3. stack的底层容器可以是任何标准的容器类模板或者一些其他特定的容器类，这些容器类应该支持以下操作:
empty：判空操作
back：获取尾部元素操作
push_back：尾部插入元素操作
pop_back：尾部删除元素操作

4. 标准容器vector、deque、list均符合这些需求，默认情况下，如果没有为stack指定特定的底层容器，默认情况下使用deque(双端队列容器)。
*/



//queue的介绍
/*
1. 队列是一种容器适配器，专门用于在FIFO上下文(先进先出)中操作，其中从容器一端插入元素，另一端提取元素

2. 队列作为容器适配器实现，容器适配器即将特定容器类封装作为其底层容器类，queue提供一组特定的成员函数来访问其元素。元素从队尾入队列，从队头出队列

3. 底层容器可以是标准容器类模板之一，也可以是其他专门设计的容器类。该底层容器应至少支持以下操作:
empty：检测队列是否为空
size：返回队列中有效元素的个数
front：返回队头元素的引用
back：返回队尾元素的引用
push_back：在队列尾部入队列
pop_front：在队列头部出队列

4. 标准容器类deque和list满足了这些要求。默认情况下，如果没有为queue实例化指定容器类，则使用标准容器deque
*/



//priority_queue的介绍
/*
1. 优先队列是一种容器适配器，根据严格的弱排序标准，它的第一个元素总是它所包含的元素中最大的

2. 此上下文类似于堆，在堆中可以随时插入元素，并且只能检索最大堆元素(优先队列中位于顶部的元素)

3. 优先队列被实现为容器适配器，容器适配器即将特定容器类封装作为其底层容器类，queue提供一组特
定的成员函数来访问其元素。元素从特定容器的“尾部”弹出，其称为优先队列的顶部。

4. 底层容器可以是任何标准容器类模板，也可以是其他特定设计的容器类。容器应该可以通过随机访问迭代器访问，并支持以下操作:
empty()：检测容器是否为空
size()：返回容器中有效元素个数
front()：返回容器中第一个元素的引用
push_back()：在容器尾部插入元素
pop_back()：删除容器尾部元素

5. 标准容器类vector和deque满足这些需求。默认情况下，如果没有为特定的priority_queue类实例化指定容器类，则使用vector

6. 需要支持随机访问迭代器，以便始终在内部保持堆结构。容器适配器通过在需要时自动调用算法函数make_heap、push_heap和pop_heap来自动完成此操作
*/







/*
容器适配器:

1.什么是适配器:
适配器是一种设计模式(设计模式是一套被反复使用的、多数人知晓的、经过分类编目的、代码设计经验的总结)，
该种模式是将一个类的接口转换成客户希望的另外一个接口。

2.STL标准库中stack和queue的底层结构:
虽然stack和queue中也可以存放元素，但在STL中并没有将其划分在容器的行列，而是将其称为容器适配器，
这是因为stack和队列只是对其他容器的接口进行了包装，STL中stack和queue默认使用deque

*/





//deque分析
/*
deque(双端队列):
是一种双开口的"连续"空间的数据结构

双开口的含义是:可以在头尾两端进行插入和删除操作，且时间复杂度为O(1)，与vector比较，头插效率高，不需要搬移元素;与list比较，空间利用率比较高。

deque并不是真正连续的空间，而是由一段段连续的小空间拼接而成的，实际deque类似于一个动态的二维数组

双端队列底层是一段假象的连续空间，实际是分段连续的，为了维护其“整体连续”以及随机访问的假象，落在了deque的迭代器身上，因此deque的迭代器设计就比较复杂
*/

/*
deque的缺陷:

1.与vector比较，deque的优势是:头部插入和删除时，不需要搬移元素，效率特别高，而且在扩容时，也不需要搬移大量的元素，因此其效率是必vector高的。

2.与list比较，其底层是连续空间，空间利用率比较高，不需要存储额外字段。

3.deque致命缺陷:
1.不适合遍历，因为在遍历时，deque的迭代器要频繁的去检测其是否移动到某段小空间的边界，导致效率低下，而序列式场景中，可能需要经常遍历，
2.中间位置的插入删除效率较低
3.迭代器设计复杂
因此在实际中，需要线性结构时大多数情况下优先考虑vector和list，deque的应用并不多。而目前能看到的一个应用就是，STL用其作为stack和queue的底层数据结构
*/

/*
选择deque作为stack和queue的底层默认容器的原因:
stack是一种后进先出的特殊线性数据结构，因此只要具有push_back()和pop_back()操作的线性结构，都可以作为stack的底层容器，比如vector和list都可以
queue是先进先出的特殊线性数据结构，只要具有push_back和pop_front操作的线性结构，都可以作为queue的底层容器，比如list。

但是STL中对stack和queue默认选择deque作为其底层容器，主要是因为:
1. stack和queue不需要遍历(因此stack和queue没有迭代器)，只需要在固定的一端或者两端进行操作。
2. 在stack中元素增长时，deque比vector的效率高(扩容时不需要搬移大量数据)；
queue中的元素增长时，deque不仅效率高，而且内存使用率高。结合了deque的优点，而完美的避开了其缺陷
*/


















//模拟实现stack
//#include<vector>
//#include<deque>
//using std::vector;
//using std::deque;
//namespace bjy
//{
//	template<class T, class Sequence = deque<T>>
//	class stack
//	{
//	public:
//		void push(const T& data) { _container.push_back(data); }
//		void pop() { _container.pop_back(); }
//		T& top() { return _container.back(); }
//		const T& top()const { return _container.back(); }
//		bool empty()const { return _container.empty(); }
//		size_t size()const { return _container.size(); }
//	private:
//		Sequence<T> _container;
//	};
//}





//queue的模拟实现
//#include<deque>
//using std::deque;
//namespace bjy
//{
//	template<class T,class Sequence = deque<T>>
//	class queue
//	{
//	public:
//		void push() { _container.push_back(); }
//		void pop() { _container.pop_front(); }
//		T& front() { return _container.front(); }
//		const T& front()const { return _container.front(); }
//		T& back() { return _container.back(); }
//		const T& back()const { return _container.back(); }
//		bool empty()const { return _container.empty(); }
//		size_t size()const { return _container.size(); }
//	private:
//		Sequence<T> _container;
//	};
//}




//priority_queue模拟实现
//#include<algorithm>
//#include<vector>
//using std::vector;
//namespace bjy
//{
//	template<class T = void>
//	struct less { 
//		bool operator() (const T& left, const T& right) { return left < right; }
//	};
//	template<class T = void>
//	struct greater {
//		bool operator() (const T& left, const T& right) { return left > right; }
//	};
//
//	template<class T, class Sequence = vector<T>, class Compare = less<T>>
//	class priority_queue
//	{
//	public:
//		priority_queue() {}
//		template <class InputIterator>
//		priority_queue(InputIterator first, InputIterator last) {
//			for (; first != last; ++first) {
//				_container.push_back(*first);
//			}
//			for (int i = (_container.size() - 1 - 1) / 2; i >= 0 ; --i) {
//				adjust_down(i);
//			}
//		}
//		void adjust_up(size_t child){
//			Compare com;
//			size_t parent = (child - 1) / 2;
//			while (child > 0) {
//				if (com(_container[parent], _container[child])) {
//					std::swap(_container[child], _container[parent]);
//					child = parent;
//					parent = (child - 1) / 2;
//				}
//				else{ break;}
//			}
//		}
//		void adjust_down(size_t parent) {
//			Compare com;
//			size_t child = parent * 2 + 1;
//			while (child < _container.size()) {
//				//选出左右孩子中大的一个
//				if (child + 1 < _container.size() && com(_container[child],_container[child + 1])) {
//					++child;
//				}
//				if (com(_container[parent], _container[child])) {
//					std::swap(_container[child], _container[parent]);
//					parent = child;
//					child = parent * 2 + 1;
//				}
//				else { break;}
//			}
//		}
//		void push(const T& data) {
//			_container.push_back(data);
//			adjust_up(_container.size() - 1);
//		}
//		void pop() {
//			std::swap(_container.front(), _container.back());
//			_container.pop_back();
//			adjust_down(0);
//		}
//		const T& top() { return _container[0]; }
//		size_t size()const { _container.size(); }
//		bool empty()const { return _container.empty(); }
//	private:
//		Sequence _container;
//	};
//}
//
//#include<iostream>
//using namespace bjy;
//using std::cout;
//using std::endl;
//int main()
//{
//	priority_queue<int> heap;
//	heap.push(5);
//	heap.push(3);
//	heap.push(2);
//	heap.push(0);
//	heap.push(4);
//	heap.push(1);
//	while (!heap.empty()) {
//		cout << heap.top() << " ";
//		heap.pop();
//	}
//	cout << endl;
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	priority_queue<int,vector<int>,greater<int>> heap2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	while (!heap2.empty()) {
//		cout << heap2.top() << " ";
//		heap2.pop();
//	}
//	cout << endl;
//
//	return 0;
//}






