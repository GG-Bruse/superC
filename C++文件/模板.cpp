//���ͱ��
/*
1.���صĺ������������Ͳ�ͬ�����븴���ʱȽϵͣ�ֻҪ�������ͳ���ʱ������Ҫ�û��Լ����Ӷ�Ӧ�ĺ���
2.����Ŀ�ά���ԱȽϵͣ�һ������������е����ؾ�����

���ͱ�̣���д�������޹ص�ͨ�ô��룬�Ǵ��븴�õ�һ���ֶΡ�ģ���Ƿ��ͱ�̵Ļ���
*/
//#include<iostream>
//using std::cout;
//using std::endl;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int t1 = 1, t2 = 2;
//	double t3 = 3.3, t4 = 4.4;
//	char t5 = '5', t6 = '6';
//	Swap(t1, t2);
//	Swap(t3, t4);
//	Swap(t5, t6);
//	cout << t1 << " " << t2 << endl;
//	cout << t3 << " " << t4 << endl;
//	cout << t5 << " " << t6 << endl;
//	return 0;
//}































//����ģ��

//����:
/*
����ģ�������һ���������壬�ú���ģ���������޹أ���ʹ��ʱ��������������ʵ�����Ͳ����������ض����Ͱ汾
��ʽ:
template<typename T1, typename T2,......,typename Tn>
����ֵ���� ������(�����б�){}
ע��:
typename����������ģ������ؼ��֣�Ҳ����ʹ��class(�м�:����ʹ��struct����class)
*/
//#include<iostream>
//using std::cout;
//using std::endl;
//template<typename T>//ģ�����
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int t1 = 1, t2 = 2;
//	double t3 = 3.3, t4 = 4.4;
//	char t5 = '5', t6 = '6';
//	Swap(t1, t2);
//	Swap(t3, t4);
//	Swap(t5, t6);
//	cout << t1 << " " << t2 << endl;
//	cout << t3 << " " << t4 << endl;
//	cout << t5 << " " << t6 << endl;
//	return 0;
//}


//����ģ���ԭ��:
/*
����ģ����һ����ͼ�����������Ǻ������Ǳ�������ʹ�÷�ʽ�����ض��������ͺ�����ģ�ߡ�������ʵģ����ǽ�����Ӧ�����������ظ������齻���˱�����

�ڱ���������׶Σ�����ģ�庯����ʹ�ã���������Ҫ���ݴ����ʵ������������ʵ�������ɶ�Ӧ���͵ĺ����Թ����á�
����:����double����ʹ�ú���ģ��ʱ��������ͨ����ʵ�����͵����ݣ���Tȷ��Ϊdouble���ͣ�Ȼ�����һ��ר�Ŵ���double���͵Ĵ��룬�����ַ����͵�Ҳ�����
*/


//����ģ���ʵ����
/*
�ò�ͬ���͵Ĳ���ʹ�ú���ģ��ʱ����Ϊ����ģ���ʵ������ģ�����ʵ������Ϊ:��ʽʵ��������ʽʵ����

1.��ʽʵ����: �ñ���������ʵ������ģ�������ʵ������
2.��ʽʵ����: �ں��������<>��ָ��ģ�������ʵ������
*/
//#include<iostream>
//template<typename T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	//Add(a1, d1);//err
//	/*
//	����䲻��ͨ������
//	��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T���������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע��:��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	*/
//
//	//����ʽ: 1.�û��Լ���ǿ��ת�� 2.ʹ����ʽʵ���� 3.���ö��ģ�����
//	Add(a1, (int)d1);
//	Add<int>(a1, d1);//��ʽʵ����
//	return 0;
//}


//ģ�������ƥ��ԭ��
/*
1.һ����ģ�庯�����Ժ�һ��ͬ���ĺ���ģ��ͬʱ���ڣ����Ҹú���ģ�廹���Ա�ʵ����Ϊ�����ģ�庯��

2.���ڷ�ģ�庯����ͬ������ģ�壬���������������ͬ���ڵ���ʱ�����ȵ��÷�ģ�庯��������Ӹ�ģ�������һ��ʵ����
���ģ����Բ���һ�����и���ƥ��ĺ����� ��ô��ѡ��ģ��

3.ģ�庯���������Զ�����ת��������ͨ�������Խ����Զ�����ת��
*/

//int Add(int left, int right)//ר�Ŵ���int�ļӷ�����
//{
//	return left + right;
//}
//template<class T>//ͨ�üӷ�����
//T Add(T left, T right)
//{
//	return left + right;
//}
//template<class T1, class T2>//ͨ�üӷ�����
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2);//��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//
//	//ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//	Add(1.0, 2.0);//���õڶ���
//	Add(1.0, 2);//���õ�����
//	return 0;
//}































//��ģ��

//��ģ��Ķ����ʽ:
/*
template<class T1, class T2, ..., class Tn>
class ��ģ����
{
// ���ڳ�Ա����
};
*/
//#include<iostream>
//using namespace std;
//template<class T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 6):_capacity(capacity),_top(0),_data(new T[capacity]){}
//	~Stack();
//private:
//	size_t _capacity;
//	size_t _top;
//	T* _data;
//};
//template<class T>//��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
//Stack<T>::~Stack()
//{
//	delete[] _data;
//	_top = 0;
//	_capacity = 0;
//}
//int main()
//{
//	//Stack��������Stack<int>��Stack<char>�Ȳ�������
//	Stack<int>sk1;
//	Stack<char>sk2;
//	Stack<int>sk3(100);
//	return 0;
//}

//��ģ���ʵ����:
/*
��ģ��ʵ�����뺯��ģ��ʵ������ͬ����ģ��ʵ������Ҫ����ģ�����ֺ��<>��Ȼ��ʵ���������ͷ���<>�м��ɣ�
��ģ�����ֲ����������࣬��ʵ�����Ľ��������������
*/




//ģ�岻֧�ַ�����룬һ�����ͬһ�ļ��У�ȡ��.hpp





































