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


































//ģ�������Ϊ �����β���������β�
/*
�����βμ�: ������ģ������б��У�����class����typename֮��Ĳ����������ơ�
�������β�: ������һ��������Ϊ��(����)ģ���һ������������(����)ģ���пɽ��ò������ɳ�����ʹ��
*/

//template<class T, size_t N = 10>
//class array
//{
//public:
//	T& operator[](size_t index) { return _array[index]; }
//	const T& operator[](size_t index)const { return _array[index]; }
//	size_t size()const { return _size; }
//	bool empty()const { return 0 == _size; }
//private:
//	T _array[N];
//	size_t _size;
//};

/*
ע��:
1. ��������������Լ��ַ����ǲ�������Ϊ������ģ�������
2. �����͵�ģ����������ڱ����ھ���ȷ�Ͻ��
*/



















//ģ����ػ�
/*
����:
ͨ������£�ʹ��ģ�����ʵ��һЩ�������޹صĴ��룬������һЩ�������͵Ŀ��ܻ�õ�һЩ����Ľ������Ҫ���⴦��
��ʱ������Ҫ��ģ������ػ�����:��ԭģ����Ļ����ϣ���������������������⻯��ʵ�ַ�ʽ��ģ���ػ��з�Ϊ����ģ���ػ�����ģ���ػ�
*/

//����ģ���ػ�
/*
1. ����Ҫ����һ�������ĺ���ģ��
2. �ؼ���template�����һ�Կյļ�����<>
3. ���������һ�Լ����ţ���������ָ����Ҫ�ػ�������
4. �����βα�: ����Ҫ��ģ�庯���Ļ�������������ȫ��ͬ
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//class Date
//{
//public:
//	Date() :_year(0), _month(0), _day(0) {}
//	Date(int year, int month, int day) :_year(year), _month(month), _day(day) {}
//	bool operator<(const Date& d)const {
//		if ((_year < d._year) || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day))
//			return true;
//			return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////����ʵ�ּ����ˣ�����Ŀɶ��Ըߣ�������д����Ϊ����һЩ�������͸��ӵĺ���ģ�壬�ػ�ʱ�ر��������˺���ģ�岻�����ػ�
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
////��Less����ģ������ػ�
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl;
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl;
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl;
//	return 0;
//}





//��ģ���ػ�
/*
ȫ�ػ�:
ȫ�ػ����ǽ�ģ������б������еĲ�����ȷ����

ƫ�ػ�:
�κ����ģ�������һ����������������Ƶ��ػ��汾
	ƫ�ػ����������ֱ��ַ�ʽ:
	(1)�����ػ�:��ģ���������е�һ���ֲ����ػ�
	(2)��������һ��������:ƫ�ػ�����������ָ�ػ����ֲ������������ģ���������һ����������������Ƴ�����һ���ػ��汾
*/


//#include<iostream>
//using std::cout;
//using std::endl;
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//};
//
//template<>//ȫ�ػ�
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//};
//
//template <class T1>//ƫ�ػ�
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//};
//template<class T1, class T2>//ƫ�ػ�
//class Data<T1*,T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//template<class T1, class T2>//ƫ�ػ�
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//};
//
//int main()
//{
//	Data<int, int> d1;//Data<T1, int>
//	Data<int, char> d2;//Data<int, char>
//	Data<double, double>d3;//Data<T1, T2>
//
//	Data<int*, int*> d4;//Data<T1*, T2*>
//	Data<double*, char*>d5;//Data<T1*, T2*>
//
//	Data<double&, char&>d6;//Data<T1&, T2&>
//	return 0;
//}






























//ģ��ķ������

//ģ�岻֧�ַ������
/*
�������:
1.�������Ͷ���ŵ�һ���ļ� "xxx.hpp" �������xxx.h��ʵҲ�ǿ��Ե�(�Ƽ�)
2.ģ�嶨���λ����ʽʵ����(���Ƽ�:������д��)
*/
/*
ԭ��:
main.cpp�ļ�:
#include"add.h"
int main()
{
	Add(1,1);
	Add(2.1,2.2);
	return 0;
}

add.h�ļ�:
template<class T>
T Add(const T& left,const T& right);

add.cpp�ļ�
template<class T>
T Add(const T& left,const T& right) { return left + right; }

C/C++����Ҫ���У��þ���: Ԥ���� -- ���� -- ��� -- ����
����:
�Գ�����дʷ����﷨�������������������ɻ����롣
ͷ�ļ���������룬�������Ը���.cpp�ļ��������
����:
�����.o�ļ��ϲ���������û�н���ĵ�ַ����

������뵼��add.cpp�ļ��е�ģ�庯����δʵ���������Ӻϲ����ű���޷��ҵ�Add�����ĵ�ַ���������Ӵ���
*/















//ģ���ܽ�
/*
�ŵ�:
1. ģ�帴���˴��룬��ʡ��Դ������ĵ���������C++�ı�׼ģ���(STL)��˶�����
2. ��ǿ�˴���������
ȱ��:
1. ģ��ᵼ�´����������⣬Ҳ�ᵼ�±���ʱ��䳤
2. ����ģ��������ʱ��������Ϣ�ǳ����ң����׶�λ����
*/