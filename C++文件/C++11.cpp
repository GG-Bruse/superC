//�б��ʼ��
/*
��C++98�У���׼����ʹ�û�����{}��������߽ṹ��Ԫ�ؽ���ͳһ���б��ʼֵ�趨��
C++11�������ô�����������б�(��ʼ���б�)��ʹ�÷�Χ��ʹ����������е��������ͺ��û��Զ�������͡�ʹ�ó�ʼ���б�ʱ������ӵȺ�(=)Ҳ�ɲ���ӡ�
��������ʱҲ����ʹ���б��ʼ����ʽ���ù��캯����ʼ��
*/

//#include <iostream>
//using namespace std;
//struct Point{
//	int _x;
//	int _y;
//};
//class Date
//{
//public:
//	Date(int year, int month, int day):_year(year), _month(month), _day(day){
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	int x1 = 1;
//	int x2{ 2 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//	
//	int* pa = new int[4]{ 0 };// C++11���б��ʼ��Ҳ����������new���ʽ��
//
//	Date d1(2022, 1, 1);
//	Date d2{ 2022, 1, 2 };//���ù��캯����ʼ��
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}



//initializer_list

//#include <iostream>
//using namespace std;
//int main()
//{
//	auto il = { 10,20,30 };//{}�����ͼ�Ϊclass std::initializer_list<int>
//	cout << typeid(il).name() << endl;//class std::initializer_list<int>
//	return 0;
//}



//��������ʹ���б��ʼ�������������β�Ϊinitializer_list�Ĺ��캯��
//#include <iostream>
//#include <map>
//using namespace std;
//int main()
//{
//	// ����{"sort", "����"}���ȳ�ʼ������һ��pair����
//	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
//	return 0;
//}

//C++11��һ�ж���֧��ʹ���б��ʼ������������ͨ������Ȼ������ǰ�ķ�ʽ���г�ʼ�����������������ʹ���б��ʼ����
















//auto
/*
��C++98��auto��һ���洢���͵�˵���������������Ǿֲ��Զ��洢���ͣ����Ǿֲ����ж���ֲ��ı���Ĭ�Ͼ����Զ��洢���ͣ�����auto��ûʲô��ֵ�ˡ�
C++11�з���autoԭ�����÷�����������ʵ���Զ������ȶϡ�����Ҫ����������ʾ��ʼ�����ñ�����������������������Ϊ��ʼ��ֵ�����͡�
*/
//decltype
/*
�ؼ���decltype����������������Ϊ���ʽָ��������
*/
//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret��������double
//	decltype(&x) p; // p��������int const *
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}








//STL�еı仯
/*
1.C++11������unordered_map��unordered_set����

2.������array(��̬˳���)
C����Խ���鱡����Խ���������鲻������Խ��д���
��ʵ������Ǻ�����ʹ��array��ϰ��ʹ��C���飬����ʹ��vector + resize

3.������forward_list(������)

4.�����ڲ��ı仯
	��֧����initializer_list,����֧���б��ʼ����
	�Ƚϼ��ߵĽӿڣ���:cbegin��cend��
	�ƶ�������ƶ���ֵ
	��ֵ���ò����Ĳ���
*/




































