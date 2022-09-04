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
				size_t lenth = pos - _start;//��¼,���������ʧЧ
				reserve(capacity() == 0 ? 6 : capacity() * 2);
				pos = _start + lenth;//����
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



















































