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













//�ɱ����ģ��
/*
C++11�������Կɱ����ģ���ܹ������������Խ��ܿɱ�����ĺ���ģ�����ģ�塣
*/

// Args��һ��ģ���������args��һ�������ββ�����
// ����һ��������Args... args������������п��԰���0�������ģ�����
//template <class ...Args>
//void ShowList(Args... args) {}

/*
����Ĳ���argsǰ����ʡ�Ժţ�����������һ���ɱ�ģ����������ǰѴ�ʡ�ԺŵĲ�����Ϊ�����������������������0��N��N>=0����ģ�������
�����޷�ֱ�ӻ�ȡ������args�е�ÿ�������ģ�ֻ��ͨ��չ���������ķ�ʽ����ȡ�������е�ÿ��������
*/



//�ݹ麯����ʽչ��������
//#include <iostream>
//#include <string>
//using namespace std;
////template <class T>
//void ShowList()// �ݹ���ֹ����
//{
//	cout << endl;
//}
//template <class T, class ...Args>
//void ShowList(const T& value, Args... args)
//{
//	cout << "ShowList("<<value<<", " << sizeof...(args) << "������)" << endl;
//	ShowList(args...);
//}
//int main()
//{
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}



//���ű��ʽչ��������
/*
����չ���������ķ�ʽ������Ҫͨ���ݹ���ֹ��������ֱ����expand��������չ���ġ�
printarg����һ���ݹ���ֹ������ֻ��һ�������������ÿһ�������ĺ�����
���־͵�չ���������ķ�ʽʵ�ֵĹؼ��Ƕ��ű��ʽ������֪�����ű��ʽ�ᰴ˳��ִ�ж���ǰ��ı��ʽ��

expand�����еĶ��ű��ʽ��(printarg(args), 0)��Ҳ�ǰ������ִ��˳����ִ��printarg(args)���ٵõ����ű��ʽ�Ľ��0��
ͬʱ���õ���C++11������һ�����ԡ�����ʼ���б�ͨ����ʼ���б�����ʼ��һ���䳤����,
{(printarg(args), 0)...}����չ����((printarg(arg1),0),(printarg(arg2),0), (printarg(arg3),0), etc... )��
���ջᴴ��һ��Ԫ��ֵ��Ϊ0������int arr[sizeof...(Args)]��

�����Ƕ��ű��ʽ���ڴ�������Ĺ����л���ִ�ж��ű��ʽǰ��Ĳ���printarg(args)
��ӡ��������Ҳ����˵�ڹ���int����Ĺ����оͽ�������չ���ˣ���������Ŀ�Ĵ�����Ϊ�������鹹��Ĺ���չ��������
*/

//#include <iostream>
//#include <string>
//using namespace std;
//template<class T>
//int PrintArg(const T& x)//����ÿ�������ĺ���
//{
//	cout << x << " ";
//	return 0;
//}
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int a[] = { PrintArg(args)... };
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}



//emplace_back(����д����ʱ����������)
//#include <iostream>
//#include <list>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;
//	}
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		cout << "Date& operator=(const Date& d))" << endl;
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//������ͨ��������û������
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.emplace_back(2);
//
//	//�����Զ�������
//	list<Date> lt2;
//	lt2.push_back(Date(2022, 11, 16));//����+��������(�ƶ�����)
//	cout << "---------------------------------" << endl;
//	lt2.emplace_back(2022, 11, 16);//�������ǽ��������в���������ڹ���
//
//	return 0;
//}
/*
Date(int year = 1, int month = 1, int day = 1)
Date(const Date& d)
---------------------------------
Date(int year = 1, int month = 1, int day = 1)
*/



































//#include <iostream>
//using namespace std;
//
//void Swap(double& d1, double& d2) {
//	double temp = d1;
//	d1 = d2;
//	d2 = temp;
//}
//void Swap(int& i1, int& i2) {
//	int temp = i1;
//	i1 = i2;
//	i2 = temp;
//}
//void Swap(char& c1, char& c2) {
//	char temp = c1;
//	c1 = c2;
//	c2 = temp;
//}
//template <typename T>
//void Swap(T& t1, T& t2) {
//	T temp = t1;
//	t1 = t2;
//	t2 = temp;
//}
//int main()
//{
//	double d1 = 1.0;
//	double d2 = 2.0;
//	Swap(d1, d2);
//	int i1 = 1;
//	int i2 = 2;
//	Swap(i1, i2);
//	char c1 = '1';
//	char c2 = '2';
//	Swap(c1, c2);
//	return 0;
//}





//#include <iostream>
//using namespace std;
//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2);//��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0);//ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//	return 0;
//}








//#include <iostream>
//using namespace std;
//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2);//���ģ�庯��ƥ�䣬����������Ҫʵ����
//	Add<int>(1, 2);//���ñ�����ʵ�����İ汾
//	return 0;
//}






//template<class T, size_t N = 10>
//class array
//{
//public:
//	//����
//private:
//	T _array[N];
//	size_t _size;
//};









//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date() :_year(0), _month(0), _day(0) {}
//	Date(int year, int month, int day) :_year(year), _month(month), _day(day) {}
//	bool operator<(const Date& d)const {
//		if ((_year < d._year) || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day))
//			return true;
//		return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // ���ԱȽϣ��������
//	//���ﱾ��Ƚ�Date�������ݵĴ�С��ʵ�ʱȽϵ�ȴ��ָ���ַ�Ĵ�С
//	return 0;
//}




