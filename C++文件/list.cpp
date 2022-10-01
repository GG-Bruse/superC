/*
list�Ľ���:
1. list�ǿ����ڳ�����Χ��������λ�ý��в����ɾ��������ʽ���������Ҹ���������ǰ��˫�������

2. list�ĵײ���˫������ṹ��˫��������ÿ��Ԫ�ش洢�ڻ�����صĶ����ڵ��У��ڽڵ���ͨ��ָ��ָ����ǰһ��Ԫ�غͺ�һ��Ԫ�ء�

3. list��forward_list�ǳ����ƣ�����Ҫ�Ĳ�ͬ����forward_list�ǵ�����ֻ�ܳ�ǰ��������������򵥸�Ч��

4. ������������ʽ�������(array��vector��deque)��listͨ��������λ�ý��в��롢�Ƴ�Ԫ�ص�ִ��Ч�ʸ��á�

5. ����������ʽ������ȣ�list��forward_list����ȱ���ǲ�֧������λ�õ��������
����:Ҫ����list�ĵ�6��Ԫ�أ��������֪��λ��(����ͷ������β��)��������λ�ã������λ���ϵ�����Ҫ���Ե�ʱ�俪��
list����ҪһЩ����Ŀռ䣬�Ա���ÿ���ڵ���������Ϣ(���ڴ洢���ͽ�СԪ�صĴ�list��˵�������һ����Ҫ������)

*/
/*
list������ʧЧ:
������ʧЧ����������ָ��Ľڵ����Ч�����ýڵ㱻ɾ����
��Ϊlist�ĵײ�ṹΪ��ͷ����˫��ѭ�����������list�н��в���ʱ�ǲ��ᵼ��list�ĵ�����ʧЧ�ģ�
ֻ����ɾ��ʱ�Ż�ʧЧ������ʧЧ��ֻ��ָ��ɾ���ڵ�ĵ����������������������ܵ�Ӱ��
*/







//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cassert>
//#include"reverse_iterator.h"
//using std::bidirectional_iterator_tag;
//namespace bjy
//{
//	template<class T>
//	struct list_node{
//		list_node(const T& data = T()): _next(nullptr),_prev(nullptr),_data(data) {}
//		list_node<T>* _next;
//		list_node<T>* _prev;
//		T _data;
//	};
//
//	template<class T,class Ref,class Ptr>
//	struct __list_iterator {
//		typedef list_node<T> list_node;
//		typedef __list_iterator<T, Ref, Ptr> iterator;
//
//		typedef bidirectional_iterator_tag iterator_category;
//		typedef T value_type;
//		typedef Ptr pointer;
//		typedef Ref reference;
//		typedef ptrdiff_t difference_type;
//
//		__list_iterator(list_node* node):_node(node) {}
//		bool operator!=(const iterator& it)const { return _node != it._node; }
//		bool operator==(const iterator& it)const { return _node == it._node; }
//		Ref operator*() { return _node->_data; }
//		Ptr operator->() { return &(operator*()); }
//		iterator& operator++() { 
//			_node = _node->_next;
//			return *this;
//		}
//		iterator operator++(int) {
//			iterator temp(*this);
//			_node = _node->_next;
//			return temp;
//		}
//		iterator& operator--() {
//			_node = _node->_prev;
//			return *this;
//		}
//		iterator operator--(int) {
//			iterator temp(*this);
//			_node = _node->_prev;
//			return temp;
//		}
//		iterator operator+(int num) {
//			iterator temp(_node);
//			if (num < 0) temp = operator-(-num);
//			else for (int i = 0; i < num - 1; ++i) temp._node = temp._node->_next;
//			return temp;
//		}
//		iterator operator-(int num) {
//			iterator temp(_node);
//			if (num < 0) temp = operator+(-num);
//			else for (int i = 0; i < num; ++i) temp._node = temp._node->_prev;
//			return temp;
//		}
//		list_node* _node;
//	};
//
//	template<class T>
//	class list
//	{
//		typedef T value_type;
//		typedef list_node<value_type> list_node;
//		typedef value_type& reference;
//		typedef const value_type& const_reference;
//	public:
//		typedef __list_iterator<T,T&,T*> iterator;
//		typedef __list_iterator<T, const T&, const T*> const_iterator;
//		typedef __reverse_iterator<iterator, T&, T*> reverse_iterator;
//		typedef __reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
//
//		iterator begin() { return iterator(_head->_next); }
//		const_iterator begin()const { return const_iterator(_head->_next); }
//		iterator end() { return iterator(_head); }
//		const_iterator end()const { return const_iterator(_head); }
//
//		reverse_iterator rbegin() { return reverse_iterator(end()); }
//		const_reverse_iterator rbegin()const { return const_reverse_iterator(end()); }
//		reverse_iterator rend() { return reverse_iterator(begin()); }
//		const_reverse_iterator rend()const { return const_reverse_iterator(begin()); }
//
//		void empty_initialize() {
//			_head = new list_node;
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//		void swap(list<value_type>& lt) { std::swap(_head, lt._head); }
//		void clear() { for (list<int>::iterator it = begin(); it != end(); ) it = erase(it); }
//		list() { empty_initialize(); }
//		template<class InputIterator>
//		list(InputIterator first, InputIterator last) {
//			empty_initialize();
//			for (; first != last; ++first) {
//				push_back(*first);
//			}
//		}
//		list(const list<value_type>& lt) {
//			empty_initialize();
//			list<value_type> temp(lt.begin(), lt.end());
//			swap(temp);
//		}
//		~list(){
//			clear();
//			delete _head;
//			_head = nullptr;
//		}
//		list<value_type>& operator=(list<value_type> lt) {
//			swap(lt);
//			return *this;
//		}
//
//		iterator insert(iterator pos, const_reference data){
//			list_node* newnode = new list_node(data);
//			list_node* cur = pos._node;
//			list_node* prev = cur->_prev;
//
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//		void push_back(const_reference data) {
//#if 0
//			list_node* new_node = new list_node(data);
//			list_node* tail = _head->_prev;
//			tail->_next = new_node;
//			new_node->_prev = tail;
//			new_node->_next = _head;
//			_head->_prev = new_node;
//#else
//			insert(end(), data);
//#endif
//		}
//		void push_front(const_reference x) { insert(begin(), x); }
//
//		iterator erase(iterator pos){
//			assert(pos != end());
//			list_node* prev = (pos._node)->_prev;
//			list_node* next = (pos._node)->_next;
//			prev->_next = next;
//			next->_prev = prev;
//			delete (pos._node);
//			return iterator(next);
//		}
//		void pop_back() { erase(--end()); }
//		void pop_front() { erase(begin()); }
//
//	private:
//		list_node* _head;
//	};
//}
//
//#include<iostream>
//#include<algorithm>
//using namespace bjy;
//using std::cout;
//using std::endl;
//using std::find;
//struct Pos
//{
//	int _x;
//	int _y;
//};
//int main1()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(5);
//	
//	list<int>::iterator it = l1.begin();
//	for (; it != l1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	it = l1.begin();
//	for (; it != l1.end(); it++) {
//		(*it) *= 2;
//	}
//	it != l1.begin();
//	for (auto e : l1){
//		cout << e << " ";
//	}
//	cout << endl;
//
//	struct Pos pos1 {10,20};
//	struct Pos* p = &pos1;
//	cout << p->_x <<" " << p->_y << endl;//����Ϊp->->_x ������Ϊ�˿ɶ��Խ��������⴦��
//	return 0;
//}
//void func(const list<int>& l)
//{
//	list<int>::const_iterator it = l.begin();
//	list<int>::const_iterator its = l.end();
//	while (it != its)
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//int main2()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(5);
//	func(l1);
//	return 0;
//}
//int main3()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = lt.begin();
//	while (it != lt.end())
//	{
//		*it *= 2;
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	lt.push_front(10);
//	lt.push_front(20);
//	lt.push_front(30);
//	lt.push_front(40);
//
//	lt.pop_back();
//	lt.pop_back();
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	auto pos = find(lt.begin(), lt.end(), 4);
//	if (pos != lt.end())
//	{
//		// pos�Ƿ��ʧЧ������
//		lt.insert(pos, 40);
//		//lt.insert(pos, 30);
//		*pos *= 100;
//	}
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}
//int main4()
//{
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//
//	list<int> lt2 = lt1;
//
//	*(lt2.begin()) = 100;
//	for (list<int>::iterator it = lt1.begin(); it != lt1.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	for (list<int>::iterator it = lt2.begin(); it != lt2.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	list<int>lt3;
//	lt3 = lt1;
//	*(--lt3.end()) = 100;
//	for (list<int>::iterator it = lt3.begin(); it != lt3.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	list<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	return 0;
//}
