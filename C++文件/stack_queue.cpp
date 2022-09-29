//stack�Ľ���
/*
1. stack��һ��������������ר�����ھ��к���ȳ������������Ļ����У���ɾ��ֻ�ܴ�������һ�˽���Ԫ�صĲ�������ȡ������

2. stack����Ϊ������������ʵ�ֵģ��������������Ƕ��ض����װ��Ϊ��ײ��������
���ṩһ���ض��ĳ�Ա������������Ԫ�أ����ض�����Ϊ��ײ�ģ�Ԫ���ض�������β��(��ջ��)��ѹ��͵�����

3. stack�ĵײ������������κα�׼��������ģ�����һЩ�����ض��������࣬��Щ������Ӧ��֧�����²���:
empty���пղ���
back����ȡβ��Ԫ�ز���
push_back��β������Ԫ�ز���
pop_back��β��ɾ��Ԫ�ز���

4. ��׼����vector��deque��list��������Щ����Ĭ������£����û��Ϊstackָ���ض��ĵײ�������Ĭ�������ʹ��deque(˫�˶�������)��
*/



//queue�Ľ���
/*
1. ������һ��������������ר��������FIFO������(�Ƚ��ȳ�)�в��������д�����һ�˲���Ԫ�أ���һ����ȡԪ��

2. ������Ϊ����������ʵ�֣����������������ض��������װ��Ϊ��ײ������࣬queue�ṩһ���ض��ĳ�Ա������������Ԫ�ء�Ԫ�شӶ�β����У��Ӷ�ͷ������

3. �ײ����������Ǳ�׼������ģ��֮һ��Ҳ����������ר����Ƶ������ࡣ�õײ�����Ӧ����֧�����²���:
empty���������Ƿ�Ϊ��
size�����ض�������ЧԪ�صĸ���
front�����ض�ͷԪ�ص�����
back�����ض�βԪ�ص�����
push_back���ڶ���β�������
pop_front���ڶ���ͷ��������

4. ��׼������deque��list��������ЩҪ��Ĭ������£����û��Ϊqueueʵ����ָ�������࣬��ʹ�ñ�׼����deque
*/



//priority_queue�Ľ���
/*
1. ���ȶ�����һ�������������������ϸ���������׼�����ĵ�һ��Ԫ����������������Ԫ��������

2. �������������ڶѣ��ڶ��п�����ʱ����Ԫ�أ�����ֻ�ܼ�������Ԫ��(���ȶ�����λ�ڶ�����Ԫ��)

3. ���ȶ��б�ʵ��Ϊ���������������������������ض��������װ��Ϊ��ײ������࣬queue�ṩһ����
���ĳ�Ա������������Ԫ�ء�Ԫ�ش��ض������ġ�β�������������Ϊ���ȶ��еĶ�����

4. �ײ������������κα�׼������ģ�壬Ҳ�����������ض���Ƶ������ࡣ����Ӧ�ÿ���ͨ��������ʵ��������ʣ���֧�����²���:
empty()����������Ƿ�Ϊ��
size()��������������ЧԪ�ظ���
front()�����������е�һ��Ԫ�ص�����
push_back()��������β������Ԫ��
pop_back()��ɾ������β��Ԫ��

5. ��׼������vector��deque������Щ����Ĭ������£����û��Ϊ�ض���priority_queue��ʵ����ָ�������࣬��ʹ��vector

6. ��Ҫ֧��������ʵ��������Ա�ʼ�����ڲ����ֶѽṹ������������ͨ������Ҫʱ�Զ������㷨����make_heap��push_heap��pop_heap���Զ���ɴ˲���
*/







/*
����������:

1.ʲô��������:
��������һ�����ģʽ(���ģʽ��һ�ױ�����ʹ�õġ�������֪���ġ����������Ŀ�ġ�������ƾ�����ܽ�)��
����ģʽ�ǽ�һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�

2.STL��׼����stack��queue�ĵײ�ṹ:
��Ȼstack��queue��Ҳ���Դ��Ԫ�أ�����STL�в�û�н��仮�������������У����ǽ����Ϊ������������
������Ϊstack�Ͷ���ֻ�Ƕ����������Ľӿڽ����˰�װ��STL��stack��queueĬ��ʹ��deque

*/





//deque����
/*
deque(˫�˶���):
��һ��˫���ڵ�"����"�ռ�����ݽṹ

˫���ڵĺ�����:������ͷβ���˽��в����ɾ����������ʱ�临�Ӷ�ΪO(1)����vector�Ƚϣ�ͷ��Ч�ʸߣ�����Ҫ����Ԫ��;��list�Ƚϣ��ռ������ʱȽϸߡ�

deque���������������Ŀռ䣬������һ�ζ�������С�ռ�ƴ�Ӷ��ɵģ�ʵ��deque������һ����̬�Ķ�ά����

˫�˶��еײ���һ�μ���������ռ䣬ʵ���Ƿֶ������ģ�Ϊ��ά���䡰�����������Լ�������ʵļ���������deque�ĵ��������ϣ����deque�ĵ�������ƾͱȽϸ���
*/

/*
deque��ȱ��:

1.��vector�Ƚϣ�deque��������:ͷ�������ɾ��ʱ������Ҫ����Ԫ�أ�Ч���ر�ߣ�����������ʱ��Ҳ����Ҫ���ƴ�����Ԫ�أ������Ч���Ǳ�vector�ߵġ�

2.��list�Ƚϣ���ײ��������ռ䣬�ռ������ʱȽϸߣ�����Ҫ�洢�����ֶΡ�

3.deque����ȱ��:
1.���ʺϱ�������Ϊ�ڱ���ʱ��deque�ĵ�����ҪƵ����ȥ������Ƿ��ƶ���ĳ��С�ռ�ı߽磬����Ч�ʵ��£�������ʽ�����У�������Ҫ����������
2.�м�λ�õĲ���ɾ��Ч�ʽϵ�
3.��������Ƹ���
�����ʵ���У���Ҫ���Խṹʱ�������������ȿ���vector��list��deque��Ӧ�ò����ࡣ��Ŀǰ�ܿ�����һ��Ӧ�þ��ǣ�STL������Ϊstack��queue�ĵײ����ݽṹ
*/

/*
ѡ��deque��Ϊstack��queue�ĵײ�Ĭ��������ԭ��:
stack��һ�ֺ���ȳ��������������ݽṹ�����ֻҪ����push_back()��pop_back()���������Խṹ����������Ϊstack�ĵײ�����������vector��list������
queue���Ƚ��ȳ��������������ݽṹ��ֻҪ����push_back��pop_front���������Խṹ����������Ϊqueue�ĵײ�����������list��

����STL�ж�stack��queueĬ��ѡ��deque��Ϊ��ײ���������Ҫ����Ϊ:
1. stack��queue����Ҫ����(���stack��queueû�е�����)��ֻ��Ҫ�ڹ̶���һ�˻������˽��в�����
2. ��stack��Ԫ������ʱ��deque��vector��Ч�ʸ�(����ʱ����Ҫ���ƴ�������)��
queue�е�Ԫ������ʱ��deque����Ч�ʸߣ������ڴ�ʹ���ʸߡ������deque���ŵ㣬�������ıܿ�����ȱ��
*/


















//ģ��ʵ��stack
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





//queue��ģ��ʵ��
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




//priority_queueģ��ʵ��
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
//				//ѡ�����Һ����д��һ��
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






