//����
/*
1.vector�Ǳ�ʾ�ɱ��С�������������

2.vector���õ������洢�ռ����洢Ԫ��
���Բ����±��vector��Ԫ�ؽ��з��ʣ�������һ����Ч��
�����ֲ������飬���Ĵ�С�ǿ��Զ�̬�ı�ģ��������Ĵ�С�ᱻ�����Զ�����

3.���ʽ���vectorʹ�ö�̬�����������洢����Ԫ�ء�����Ԫ�ز���ʱ�����������Ҫ�����·����СΪ�����Ӵ洢�ռ䡣
�������ǣ�����һ���µ����飬Ȼ��ȫ��Ԫ���Ƶ�������顣
��ʱ����ԣ�����һ����Դ��۸ߵ�������Ϊÿ��һ���µ�Ԫ�ؼ��뵽������ʱ��vector������ÿ�ζ����·����С��

4.vector����ռ����:
vector�����һЩ����Ŀռ�����Ӧ���ܵ���������Ϊ�洢�ռ��ʵ����Ҫ�Ĵ洢�ռ����
��ͬ�Ŀ���ò�ͬ�Ĳ���Ȩ��ռ��ʹ�ú����·��䡣����������Σ����·��䶼Ӧ���Ƕ��������ļ����С����������ĩβ����һ��Ԫ�ص�ʱ�����ڳ���ʱ��ĸ��Ӷ���ɵġ�

5.vectorռ���˸���Ĵ洢�ռ䣬Ϊ�˻�ù���洢�ռ��������������һ����Ч�ķ�ʽ��̬������

6.��������̬����������ȣ�deque, list and forward_list���� vector�ڷ���Ԫ�ص�ʱ����Ӹ�Ч����ĩβ��Ӻ�ɾ��Ԫ����Ը�Ч��
������������ĩβ��ɾ���Ͳ��������Ч�ʸ��͡�����list��forward_listͳһ�ĵ����������ø���
*/



//ע��:
/*
1.vs������capacity�ǰ�1.5�������ģ�g++�����ǰ�2��������
  vs��PJ�汾STL��g++��SGI�汾STL
2.vector<char>��string�Ĳ��:
(1)string���ݽ�β����'\0'
(2)�÷���ӿ��ṩ�ϲ�ͬ		+=��find���Ƚϴ�С��operator<<��operator>>
*/

































//vector������ʧЧ����(�������ݡ����ݡ�Խ�������ʧЧ)
/*
����������Ҫ���þ������㷨�ܹ����ù��ĵײ����ݽṹ����ײ�ʵ�ʾ���һ��ָ�룬�����Ƕ�ָ������˷�װ��
����:vector�ĵ���������ԭ��ָ̬��T* ����˵�����ʧЧ��ʵ�ʾ��ǵ������ײ��Ӧָ����ָ��Ŀռ䱻�����ˣ�
��ʹ��һ���Ѿ����ͷŵĿռ䣬��ɵĺ���ǳ������(���������ʹ���Ѿ�ʧЧ�ĵ�������������ܻ����)��
*/
/*
1.��������ײ�ռ�ı�Ĳ��������п����ǵ�����ʧЧ������:resize��reserve��insert��assign��push_back��

2.ָ��λ��Ԫ�ص�ɾ������erase:
eraseɾ��posλ��Ԫ�غ�posλ��֮���Ԫ�ػ���ǰ���ƣ�û�е��µײ�ռ�ĸı䣬�����Ͻ���������Ӧ�û�ʧЧ
����:���pos�պ������һ��Ԫ�أ�ɾ��֮��pos�պ���end��λ�ã���endλ����û��Ԫ�صģ���ô��pos��ʧЧ�ˣ����ɼ������ʡ�
���ɾ��vector������λ����Ԫ��ʱ(erase��ʵ�ֲ�ͬ���ڲ��п��ܽ�������)��vs����Ϊ��λ�õ�����ʧЧ

3.ע��:Linux�£�g++�������Ե�����ʧЧ�ļ�Ⲣ���Ƿǳ��ϸ񣬴���Ҳû��vs�¼���

4. ��vector���ƣ�string�ڲ���+���ݲ���+erase֮�󣬵�����Ҳ��ʧЧ

���:��ʹ��ǰ���Ե��������¸�ֵ����
*/
























/*
��ǳ����:

ǳ����:Ҳ��λ������������ֻ�ǽ������е�ֵ������������������й�����Դ�����ͻᵼ�¶��������ͬһ����Դ����һ����������ʱ�ͻὫ����Դ�ͷŵ���
����ʱ��һЩ����֪������Դ�Ѿ����ͷţ���Ϊ����Ч�����Ե���������Դ�������ʱ���ͻᷢ�������˷���Υ��

���:���һ�������漰����Դ�Ĺ����俽�����캯������ֵ����������Լ�������������Ҫ��ʽ������һ��������ǰ��������ʽ�ṩ

ע��:
1. memcpy���ڴ�Ķ����Ƹ�ʽ��������һ���ڴ�ռ�������ԭ�ⲻ���Ŀ���������һ���ڴ�ռ���

2. ������������Զ������͵�Ԫ�أ�memcpy�ȸ�Ч�ֲ��������������������Զ�������Ԫ�أ������Զ�������Ԫ�����漰����Դ����ʱ���ͻ������Ϊmemcpy�Ŀ���ʵ����ǳ������
����������漰����Դ����ʱ��ǧ����ʹ��memcpy���ж���֮��Ŀ�������Ϊmemcpy��ǳ������������ܻ������ڴ�й©�������������
*/















//#define _CRT_SECURE_NO_WARNINGS
//#define NEW 1
//#include<iostream>
//#include<algorithm>
//#include<cassert>
//#include"reverse_iterator.h"
//using std::swap;
//namespace bjy
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T value_type;
//		typedef value_type& reference;
//		typedef const value_type& const_reference;
//		typedef value_type* iterator;
//		typedef const value_type* const_iterator;
//		typedef __reverse_iterator<iterator, reference, T*> reverse_iterator;
//		typedef __reverse_iterator<const_iterator, const_reference, const value_type*> const_reverse_iterator;
//	public:
//		iterator begin() { return _start; }
//		iterator end() { return _finish; }
//		const_iterator begin()const { return _start; }
//		const_iterator end()const { return _finish; }
//
//		reverse_iterator rbegin() { return reverse_iterator(end()); }
//		reverse_iterator rend() { return reverse_iterator(begin()); }
//		const_reverse_iterator rbegin()const { return const_reverse_iterator(end()); }
//		const_reverse_iterator rend()const { return const_reverse_iterator(begin()); }
//
//		vector() :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
//#ifdef OLD1
//		vector(const vector<int>& temp) {
//			_start = new T[temp.capacity()];
//			//memcpy(_start, temp._start,sizeof(T)*temp.size());//�Զ������Ͳ���ʹ��memcpy
//			for (size_t i = 0; i < temp.size(); ++i) _start[i] = temp._start[i];
//			_finish = _start + temp.size();
//			_end_of_storage = _start + temp.capacity();
//		}
//#endif
//#ifdef OLD2
//		vector(const vector<int>& temp) :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
//			reserve(temp.capacity());
//			for (size_t i = 0; i < temp.size(); ++i)
//				push_back(temp[i]);
//		}
//#endif
//#ifdef NEW//�ִ�д��
//		template<class InputIterator>
//		vector(InputIterator first, InputIterator last) {
//			for (; first != last; ++first) push_back(*first);
//		}
//		vector(const vector<int>& temp) :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
//			vector<int>worker(temp.begin(), temp.end());
//			swap(worker);
//		}
//#endif
//		vector(int n, const_reference val = T()) {
//			reserve(n);
//			for (int i = 0; i < n; ++i) push_back(val);
//		}
//		vector(size_t n, const_reference val = T()) {
//			reserve(n);
//			for (size_t i = 0; i < n; ++i) push_back(val);
//		}
//		~vector() {
//			delete[] _start;
//			_start = _finish = _end_of_storage = nullptr;
//		}
//
//		size_t capacity()const { return _end_of_storage - _start; }
//		size_t size()const { return _finish - _start; }
//		bool empty()const { return (size() == 0); }
//		reference front() { return _start[0]; }
//		const_reference front()const { return _start[0]; }
//		reference back() { return _start[size() - 1]; }
//		const_reference back()const { return _start[size() - 1]; }
//
//		reference operator[](size_t pos) {
//			assert(pos < size());
//			return _start[pos];
//		}
//		const_reference operator[](size_t pos)const {
//			assert(pos < size());
//			return _start[pos];
//		}
//		vector<T>& operator=(vector<T> temp) {
//			swap(temp);
//			return *this;
//		}
//		void swap(vector<T>& temp) {
//			std::swap(_start, temp._start);
//			std::swap(_finish, temp._finish);
//			std::swap(_end_of_storage, temp._end_of_storage);
//		}
//
//		void reserve(size_t n) {
//			size_t previous_size = size();
//			if (n > capacity()) {
//				value_type* temp = new value_type[n];
//				if (_start) {
//					for (size_t i = 0; i < previous_size; ++i) temp[i] = _start[i];
//					delete[] _start;
//				}
//				_start = temp;
//				_finish = _start + previous_size;
//				_end_of_storage = _start + n;
//			}
//		}
//		void resize(size_t n, const_reference val = T()) {
//			if (n > capacity())reserve(n);
//			if (n > size())
//				while (_finish < _end_of_storage) *_finish++ = val;
//			else
//				_finish = _start + n;
//		}
//		iterator insert(iterator pos, const_reference data) {
//			assert((pos >= _start) && (pos <= _finish));
//			if (_finish >= _end_of_storage) {
//				size_t lenth = pos - _start;//��¼,���������ʧЧ
//				reserve(capacity() == 0 ? 6 : capacity() * 2);
//				pos = _start + lenth;//����
//			}
//			for (iterator cur = _finish - 1; cur >= pos; --cur)
//				*(cur + 1) = *cur;
//			*pos = data;
//			++_finish;
//			return pos;
//		}
//		iterator erase(iterator pos) {
//			assert((pos >= _start) && (pos < _finish));
//			for (iterator cur = pos + 1; cur < _finish; ++cur)
//				*(cur - 1) = *cur;
//			--_finish;
//			return pos;
//		}
//		void push_back(const_reference data) {
//			if (_finish >= _end_of_storage)
//				reserve(capacity() == 0 ? 6 : capacity() * 2);
//			*(_finish++) = data;
//		}
//		void pop_back() {
//			assert(_finish > _start);
//			--_finish;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _end_of_storage;
//	};
//}
//
//#include<algorithm>
//using namespace bjy;
//using std::cout;
//using std::endl;
//using std::find;
//int main1()
//{
//	vector<int>v;
//	for (size_t i = 0; i < 10; ++i)
//	{
//		v.push_back(i + 1);
//	}
//	
//	vector<int>::iterator it = find(v.begin(), v.end(), 5);
//	v.insert(it, 30);
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < 10; ++i)
//	{
//		v.push_back(i + 1);
//	}
//
//	it = find(v.begin(), v.end(), 5);
//	v.erase(it);
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (vector<int>::iterator it = v.begin(); it != v.end();) {
//		if (*it % 2 == 0) 
//		{
//			it = v.erase(it);
//		}
//		else{
//			++it;
//		}
//	}
//	for (auto e : v) 
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}
//int main2()
//{
//	vector<int>v;
//	for (size_t i = 0; i < 10; ++i)
//	{
//		v.push_back(i);
//	}
//	vector<int>v1(v);
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//
//	vector<int>v2;
//	v2 = v1;
//	v1[0] *= 10;
//	for (size_t i = 0; i < v2.size(); ++i)
//	{
//		cout << v2[i] << " ";
//	}
//
//	return 0;
//}
//int main3()
//{
//	vector<int>v(10,1);//����vector(size_t n, const_reference val = T())����
//	//C++�������������������ڹ��캯��
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << " ";
//	}
//	return 0;
//}
//int main4()
//{
//	vector<int>v;
//	v.resize(10);
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	for (size_t i = 1; i <= 100; ++i)
//		v.push_back(i);
//	v.resize(20);
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	return 0;
//}
//
//class Solution
//{
//public:
//	vector<vector<int>> generate(int numRows)
//	{
//		static vector<vector<int>> ret(numRows);
//		for (int i = 0; i < numRows; ++i)
//		{
//			ret[i].resize(i + 1);//ÿ�д�С����
//			ret[i][0] = ret[i][i] = 1;//ÿ�е�һ�������һ��Ԫ�ض�Ϊ1������Ԫ��Ҳ��ʱ��ֵΪ1
//			for (int j = 1; j < i; ++j)
//			{
//				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];//Ԫ�ص�ֵ���� ��һ�и�λ�õ�ֵ �� ��һ�ж�Ӧλ��ǰһ����ֵ
//			}
//		}
//		return ret;
//	}
//};
//int main5()
//{
//	vector<vector<int>>ret = Solution().generate(5);
//	for (size_t i = 0; i < ret.size(); ++i)
//	{
//		for (size_t j = 0; j < ret[i].size(); ++j)
//		{
//			cout << ret[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; ++i) { v.push_back(i + 1); }
//	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) {
//		cout << *rit << " ";
//	}
//	cout << endl;
//	return 0;
//}





