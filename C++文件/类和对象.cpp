//����������������:��װ���̳С���̬
//C������������̵ģ���ע���ǹ��̣��������������Ĳ��裬ͨ�����������𲽽������
//C++�ǻ�����������(�Ǵ��������)����ע���Ƕ��󣬽�һ�������ֳɲ�ͬ�Ķ��󣬿�����֮��Ľ������

//C���Խṹ��struct��ֻ�ܶ����������C++�У��ṹ���ڲ������Զ��������Ҳ���Զ��庯����
//��C++�и�ϲ����class������struct
/*
���Ƕ�ĳһ��ʵ��(����)�����������ģ������ö��������Щ���ԣ�
��Щ������������ɺ���γ���һ���µ��Զ������ͣ����ø��Զ������;Ϳ���ʵ��������Ķ���
*/











//��Ķ���
/*
class className
{
	//����
}; 
classΪ������Ĺؼ��֣�ClassNameΪ������֣�{}��Ϊ������壬ע���ඨ�����ʱ����ֺŲ���ʡ�ԡ�

���������ݳ�Ϊ��ĳ�Ա:
���еı�����Ϊ������Ի��Ա����
���еĺ�����Ϊ��ķ������߳�Ա����
*/

/*
������ֶ��巽ʽ:(һ������£����������õڶ��ַ�ʽ)

1.�����Ͷ���ȫ������������
��ע��:��Ա���������ж���ʱ������Ա�����������������������������ͻὫ�䵱��������������

2.����������.h�ļ���,��Ա�����������.cpp�ļ���
ע��:��Ա������ǰ��Ҫ������::

*/

































//��ķ����޶�������װ

//�����޶���
/*
��Ϊ public(����)��protected(����)��private(˽��) ����

ע��:
1. public���εĳ�Ա���������ֱ�ӱ�����

2. protected��private���εĳ�Ա�����ⲻ��ֱ�ӱ�����(�˴�protected��private�����Ƶ�)

3. ����Ȩ��������Ӹ÷����޶������ֵ�λ�ÿ�ʼֱ����һ�������޶�������ʱΪֹ��������û�з����޶�����������͵� } ���������

4. class��Ĭ�Ϸ���Ȩ��Ϊprivate��structΪpublic(��ΪstructҪ����C)

5.�����޶���ֻ�ڱ���ʱ���ã�������ӳ�䵽�ڴ��û���κη����޶����ϵ�����

*/

//��װ
/*
C++ʵ�ַ�װ�ķ�ʽ:
���ཫ����������뷽�������һ�飬�ö���������ƣ�ͨ������Ȩ��ѡ���ԵĽ���ӿ��ṩ���ⲿ���û�ʹ��
*/

/*
1.C++��struct��class��������ʲô��
���:
C++��Ҫ����C���ԣ�����C++��struct���Ե��ɽṹ��ʹ�á�C++��structҲ�������������ࡣ��class��������һ���ģ�
������struct�������Ĭ�Ϸ���Ȩ����public��class�������Ĭ�Ϸ���Ȩ����private��
ע��:�ڼ̳к�ģ������б�λ�ã�struct��classҲ������

2.����Ͷ���׶Σ���Ҫ���о���ķ�װ���ԣ���ʲô�Ƿ�װ�أ�
��װ:
�����ݺͲ������ݵķ��������л���ϣ�ͨ������Ȩ�������ض�������Ժ�ʵ��ϸ�ڡ������⹫���ӿ����Ͷ�����н�������װ��������һ�ֹ������û�������ʹ���ࡣ
*/


































//���������
/*
�ඨ����һ���µ�������������г�Ա��������������С�
�������ⶨ���Աʱ����Ҫʹ�� :: �����������ָ����Ա�����ĸ�����
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//class Person
//{
//public:
//	Person(const char* name,const char* gender,int age);
//	void PrintPersonInfo();
//private:
//	char* _name;
//	char* _gender;
//	int _age;
//};
//Person::Person(const char* name, const char* gender, int age)
//{
//	this->_name = (char*)name;
//	this->_gender = (char*)gender;
//	this->_age = age;
//}
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}
//int main()
//{
//	Person p("bjy", "man", 18);
//	p.PrintPersonInfo();
//	return 0;
//}

































//�����
/*
���ʵ����:
��������ʹ�������Ĺ��̣���Ϊ���ʵ������

1.���ǶԶ�����������ģ�������ģ�ͣ��޶���������Щ��Ա���������һ���ಢû�з���ʵ�ʵ��ڴ�ռ����洢��

2.һ�������ʵ�������������ʵ�������Ķ���ռ��ʵ�ʵ�����ռ䣬�洢���Ա��
*/

/*
�����ģ��:
ֻ�����Ա��������Ա��������ڹ����Ĵ����:
һ����Ĵ�С��ʵ�ʾ��Ǹ����� "��Ա����" ֮�ͣ�ע���ڴ����
û�г�Ա�����������(��������)��1�ֽ�ռλ�����洢ʵ�����ݣ����ڱ�ʶ�������
*/


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void func()
//	{
//		cout << "void A::func" << endl;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	A* p = nullptr;
//	p->func();//void A::func
//	return 0;
//}
/*
�ô����������С�
������в��洢��Ա��������Ա��������ڹ����Ĵ���Ρ�
�ڱ��������ڼ䣬���Ѿ����ݺ�����ȥ�����������ҵ��˺����ĵ�ַ��call������ַ��
Ϊʲô����call����ʽ�����˵��ö���ĵ�ַ(��thisָ��)

	A* p = nullptr;
	p->func();//void A::func
000A1000  mov         ecx,dword ptr [__imp_std::cout (0A3058h)]
000A1006  push        offset std::endl<char,std::char_traits<char> > (0A1240h)
000A100B  call        std::operator<<<std::char_traits<char> > (0A1020h)
000A1010  mov         ecx,eax
000A1012  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A3034h)]
*/


//#include<iostream>
//using namespace std;
//class A//�޳�Ա��������
//{
//	void func() {}
//};
//class B//����
//{};
//int main()
//{
//	cout << sizeof(A) << endl;//1
//	cout << sizeof(B) << endl;//1
//	A a;
//	B b;
//	cout << sizeof(a) << endl;//1
//	cout << sizeof(b) << endl;//1
//	return 0;
//}


































//thisָ��
/*
C++��������ÿ��"�Ǿ�̬�ĳ�Ա����"������һ�����ص�ָ�������
�ø�ָ��ָ��ǰ����(��������ʱ���øú����Ķ���)���ں����������С���Ա����"�Ĳ���������ͨ����ָ��ȥ���ʡ�
ֻ�������еĲ������û���͸���ģ����û�����Ҫ�����ݣ��������Զ����
*/
/*
1. thisָ�������: �������* const������Ա�����в��ܸ�thisָ�븳ֵ��

2. ֻ����"��Ա����"���ڲ�ʹ��

3. thisָ�뱾������"��Ա����"���βΣ���������ó�Ա����ʱ���������ַ��Ϊʵ�δ��ݸ�this�βΣ����Զ����в��洢thisָ�롣

4. thisָ����"��Ա����"��һ��������ָ���βΣ�һ������ɱ�����ͨ��ecx�Ĵ����Զ�����(������Ϊ�βδ洢��ջ��)������Ҫ�û�����

*/

































//���6��Ĭ�ϳ�Ա����
/*
�κ�����ʲô����дʱ�����������Զ�����6��Ĭ�ϳ�Ա������
Ĭ�ϳ�Ա����:�û�û����ʽʵ�֣������������ɵĳ�Ա������ΪĬ�ϳ�Ա����

1.���캯��(��Ҫ��ɳ�ʼ������)

2.��������(��Ҫ���������)

3.�������캯��(��ʹ��ͬ�������г�ʼ����������)

4.��ֵ����������(��һ������ֵ����һ������)

5.��ͨ����ȡ��ַ����������

6.const����ȡ��ַ����������
*/






/*
���캯��:
��һ������ĳ�Ա������������������ͬ,���������Ͷ���ʱ�ɱ������Զ����ã��Ա�֤ÿ�����ݳ�Ա����һ�����ʵĳ�ʼֵ�������ڶ�����������������ֻ����һ��

����:
1.��������������ͬ

2.�޷���ֵ(����void)

3.����ʵ����ʱ�������Զ����ö�Ӧ�Ĺ��캯��

4.���캯����������

5.������û����ʽ���幹�캯��(�����������캯��)����C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯�����û���ʽ�������������������

6.�������ͳ�Ա��������������ʱ���Ը�Ĭ��ֵ

7.�޲ι��캯����ȫȱʡ�Ĺ��캯���ͱ�����Ĭ�����ɵĹ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ��
  (�������������ɵ��õĹ��캯��ΪĬ�Ϲ��캯��)
*/

/*
��������˱��������ɵ�Ĭ�Ϲ��캯�������Ƕ���ĳ�Ա�������������ֵ��
Ҳ��˵��������������ɵ�Ĭ�Ϲ��캯����û��ʲô�ã�

���:
C++�����ͷֳ���������(��������)���Զ�������
a.����������Ĭ�ϵĹ��캯�����������ͳ�Ա��������
b.����������Ĭ�ϵĹ��캯���� ���� �Զ������ͳ�Ա��Ĭ�Ϲ��캯��
ע��:�κ�ָ�붼������������(�����Զ�������*)

(�������C++������Ƶ�һ��ȱ�ݣ�������������һ������
����:C++11ʱ�����������ͳ�Ա��������������ʱ���Ը�Ĭ��ֵ(ȱʡֵ)������ʼ���б�)
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;//���
//		_data = 0;
//	}
//private:
//	int _data;
//};
//class B
//{
//private:
//	// ��������(��������)
//	int _year;
//	int _month;
//	int _day;
//	A* _test;
//	// �Զ�������
//	A _t;
//};
//int main()
//{
//	B b;
//	return 0;
//}

//#include<iostream>
//class Date
//{
//public:
//	Date(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
/*
�������캯������֮�󣬶������Ѿ�����һ����ʼֵ�����ǲ��ܽ����Ϊ�Զ����г�Ա�����ĳ�ʼ����
���캯�����е����ֻ�ܽ����Ϊ����ֵ�������ܳ�����ʼ������Ϊ��ʼ��ֻ�ܳ�ʼ��һ�Σ������캯�����ڿ��Զ�θ�ֵ
*/

//��ʼ���б�(����ʹ��)
/*
��һ��ð�ſ�ʼ��������һ���Զ��ŷָ������ݳ�Ա�б�ÿ��"��Ա����"�����һ�����������еĳ�ʼֵ����ʽ

ע��:
1.ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)

2.���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ��:
a.���ó�Ա����(���ñ����ڶ����ʱ���ʼ��)
b.const��Ա����(const���������ڶ���ĵط���ʼ����ֻ��һ�λ���)
c.�Զ������ͳ�Ա(�Ҹ���û��Ĭ�Ϲ��캯��ʱ)

3.����ʹ�ó�ʼ���б��ʼ������Ϊ�������Ƿ�ʹ�ó�ʼ���б��������г�Ա������һ������ʹ�ó�ʼ���б��ʼ��

4.��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�

5.��ʼ���б������Ϊ�ǳ�Ա��������ĵط�����ʹ��д����Ȼ��ʽ�ṩ
*/

//errʾ������
//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour, int minute):_hour(hour), _minute(minute){}
//	int GetHour()const
//	{
//		return _hour;
//	}
//	int GetMinute()const
//	{
//		return _minute;
//	}
//private:
//	int _hour;
//	int _minute;
//};
//class Date
//{
//public:
//	Date(int year,int month,int day,int hour,int minute):_year(year),_month(month),_day(day)/*,_time(hour,minute)*/,N(10)
//	{
//		Time temp(0, 0);
//		_time = temp;//���ʻ����߳�ʼ���б�����Ĭ�Ϲ��캯������������Time��Ĭ�Ϲ��캯��
//	}
//	void Print()const
//	{
//		cout << _year << " " << _month << " " << _day << " " << _time.GetHour() << " " << _time.GetMinute() << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _time;
//	const int N;
//};
//int main()
//{
//	Date d(2003, 10, 23, 0, 0);
//	d.Print();
//	return 0;
//}

//explicit�ؼ���
/*
���캯���������Թ������ʼ�����󣬶��ڵ����������߳���һ��������Ĭ��ֵ�������Ĭ��ֵ�Ĺ��캯��������������ת��������
explicit���ι��캯������ֹ����ת��
*/
//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//	/*explicit*/ Test(int year):_data(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//	Test(const Test& temp)
//	{
//		_data = temp._data;
//		cout << "Date(const Date& temp)" << endl;
//	}
//private:
//	int _data;
//};
//void func1(Test temp){}
//Test func2()
//{
//	Test temp(2022);
//	return temp;
//}
//int main()
//{
//	Test(2022);//��������ֱ�ӵ��ù��캯������������ֻ����һ��
//	/*err*/Test d2 = 2022;//��ʽ����ת��:����(��ʱ����) + �������� + �Ż� -> ֱ�ӵ��ù���
//	const Test& d4 = 2022;
//
//	func1(Test(2022));//����+��������+�Ż� -> ֱ�ӹ���
//
//	Test t1 = func2();//һ�ι���+���ο�������+�Ż�(����ͬһ���ʽ�Ļ��޷��Ż�) -> һ�ι���+һ�ο�������
// 
//  //����:������һ�����ʽ�����У��������춼���Ż�(�϶�Ϊһ)
//	return 0;
//}






/*
��������:
��������������ɶԶ���������٣��ֲ��������ٹ������ɱ�������ɵġ�������������ʱ���Զ�����������������ɶ�������Դ��������

����:
1. ������������������ǰ�����ַ�~

2. �޲����޷���ֵ����

3. һ����ֻ����һ��������������δ��ʽ���壬ϵͳ���Զ�����Ĭ�ϵ�����������ע��:����������������

4. �����������ڽ���ʱ��C++����ϵͳϵͳ�Զ�������������

5.���������ɵ�Ĭ���������������Զ����ͳ�Ա����������������

6.������û��������Դʱ�������������Բ�д��ֱ��ʹ�ñ��������ɵ�Ĭ����������
  ����Դ����ʱ��һ��Ҫд������������Դй©

7.a.����������Ĭ�ϵ������������������ͳ�Ա��������(������ӣ��޷�����)
  b.����������Ĭ�ϵ����������� ���� �Զ������ͳ�Ա����������
  ע��:�κ�ָ�붼������������(�����Զ�������*)
*/






/*
�������캯��:
ֻ�е����βΣ����β��ǶԱ������Ͷ��������(һ�㳣��const����)�������Ѵ��ڵ�����󴴽��¶���ʱ�ɱ������Զ�����

����:
1.�������캯���ǹ��캯����һ��������ʽ��

2.�������캯���Ĳ���ֻ��һ���ұ��������������á�ʹ�ô�ֵ��ʽ������ֱ�ӱ�����Ϊ����������ݹ����

3.��δ��ʽ���壬������������Ĭ�ϵĿ������캯���� Ĭ�ϵĿ������캯�������ڴ�洢���ֽ�����ɿ��������ֿ�������ǳ����(ֵ����)

4.�ڱ��������ɵ�Ĭ�Ͽ������캯���У����������ǰ����ֽڷ�ʽֱ�ӿ����ģ����Զ��������ǵ����俽�����캯����ɿ�����

5.�������û���漰��Դ����ʱ���������캯���Ƿ�д�����ԣ�һ���漰����Դ����ʱ���򿽱����캯����һ��Ҫд�ģ��������ǳ����


�������캯�����͵��ó���:
a.ʹ���Ѵ��ڶ��󴴽��¶���
b.������ʽ��������Ϊ�����
c.��������ֵ����Ϊ�����
*/
/*
ǳ����:
Ҳ��λ������������ֻ�ǽ������е�ֵ������������������й�����Դ�����ͻᵼ�¶��������ͬһ����Դ��
1.��һ����������ʱ�ͻὫ����Դ�ͷŵ�������ʱ��һЩ����֪������Դ�Ѿ����ͷţ���Ϊ����Ч�����Ե���������Դ���в���ʱ���ͻᷢ�������˷���Υ��
2.���޸�һ������ʱ��Ӱ������Ķ���
���:
���Բ���������ǳ�������⣬����ÿ��������һ�ݶ�������Դ����Ҫ������������
���:
��һ�������漰����Դ�Ĺ����俽�����캯������ֵ����������Լ�������������Ҫ��ʽ������һ��������ǰ��������ʽ�ṩ
*/





//const��Ա
/*
��const���ε�"��Ա����"��֮Ϊconst��Ա������const�������Ա������ʵ�����θó�Ա����������thisָ�룬
�����ڸó�Ա�����в��ܶ�����κγ�Ա�����޸ģ�ͬʱ��֤const����ͷ�const���󶼿ɵ��øú���
ע��:
���졢�������ǳ�Ա��������ʹ��const�����޶�������
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//class Date
//{
//public:
//	Date(int year = 2003, int month = 10, int day = 23)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print1()//�ú���thisָ������ΪDate* const this,thisָ�뱾���ɸı�(������ָ����������)
//	{
//		cout << _year << "_" << _month << "_" << _day << endl;
//	}
//	void Print2()const//�ú���thisָ������Ϊconst Date* const this
//	{
//		cout << _year << "_" << _month << "_" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2000, 10, 10);//&d1����ΪDate*	���εĹ����൱��Ϊ�βγ�ʼ��(Ȩ������)
//	const Date d2(2000, 10, 11);//&d2����Ϊconst Date*,ָ��ָ������ݲ��ɸı䣬Ȩ�޲�����
//
//	d1.Print1();
//	//d2.Print();//err
//
//	d1.Print2();
//	d2.Print2();
//	return 0;
//}

//ȡ��ַ��constȡ��ַ����������
/*
�����������һ�㲻��Ҫ���أ�ʹ�ñ��������ɵ�Ĭ��ȡ��ַ�����ؼ��ɣ�ֻ�������������Ҫ���أ��������ñ��˻�ȡ��ָ��������
*/
//#include<iostream>
//class A
//{
//public:
//	A(int data)
//	{
//		_data = data;
//	}
//	A* operator&()
//	{
//		return this;
//	}
//	const A* operator&()const
//	{
//		return this;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	A a1(1);
//	const A a2(2);
//	&a1;
//	&a2;
//	return 0;
//}





































//���������
/*
�������Ϳ���ֱ��ʹ����������㣬������֪��������㡣�������Զ������ͣ���������֪��������㣬������Ҫ�������������

����������Ǿ������⺯�����ĺ�����Ҳ���з���ֵ���͡����������Լ������б��䷵��ֵ����������б�����ͨ�ĺ�������

��������Ϊ:�ؼ���operator�������Ҫ���ص����������

����ԭ��:����ֵ���� operator������(�����б�)
*/
/*
ע�⣺
1.����ͨ���������������������µĲ�����������:operator@

2.���ز�����������һ�����������Ϊ����(������thisָ��)

3.�����������͵���������京�岻�ܸı䣬����:���õ�����+�����ܸı��京��

4.��Ϊ���Ա��������ʱ�����βο������Ȳ�������Ŀ��1����Ϊ��Ա�����ĵ�һ������Ϊ���ص�this

5. .* ��:: ��sizeof ��?: ��. ע������5���������������(.*�����ʹ�ü���)
*/

//��ֵ���������
/*
1. ��ֵ��������ظ�ʽ:
	a.�������ͣ�const T&���������ÿ�����ߴ���Ч�ʣ�const�������޸�

	b.����ֵ���� : T&���������ÿ�����߷��ص�Ч�ʣ��з���ֵĿ����Ϊ��֧��������ֵ

	c.����Ƿ�Ϊ�Լ����Լ���ֵ

	d.����*this : Ҫ����������ֵ�ĺ���

2.��ֵ�����ֻ�����س���ĳ�Ա�����������س�ȫ�ֺ���
ԭ��:
��ֵ������������ʽʵ�֣�������������һ��Ĭ�ϵ�(��ֵ�ķ�ʽ���ֽڿ���)��
��ʱ�û����������Լ�ʵ��һ��ȫ�ֵĸ�ֵ��������أ��ͺͱ��������������ɵ�Ĭ�ϸ�ֵ��������س�ͻ�ˣ��ʸ�ֵ���������ֻ������ĳ�Ա����

3.������δ�漰����Դ������ֵ������Ƿ�ʵ�ֶ����ԣ�һ���漰����Դ���������Ҫʵ��
*/

//ǰ��++�ͺ���++����
/*
ǰ��++�ͺ���++����һԪ�������Ϊ����ǰ��++�����++�γ�����ȷ����
C++�涨 : ����++����ʱ������һ��int���͵Ĳ����������ú���ʱ�ò������ô��ݣ��������Զ�����

ע��:
ǰ��++ֱ�ӷ���+1֮��Ľ��
����++����ʹ�ú�+1�������Ҫ����+1֮ǰ�ľ�ֵ��������ʵ��ʱ��Ҫ�Ƚ�this���棬��Ϊ��ʱ�������ֻ����ֵ�ķ�ʽ���أ����ܷ�������

*/
































//static��Ա
/*
����Ϊstatic�����Ա��Ϊ��ľ�̬��Ա����static���εĳ�Ա��������֮Ϊ��̬��Ա��������static���εĳ�Ա��������֮Ϊ��̬��Ա������
��̬��Ա����һ��Ҫ��������г�ʼ��
ע��:
1.��̬��ԱΪ������������������������࣬������ĳ������Ķ��󣬴���ھ�̬��
2.��̬��Ա�������������ⶨ�壬����ʱ�����static�ؼ��֣�����ֻ������
3.�ྲ̬��Ա������ ����::��̬��Ա ���� ����.��̬��Ա ������
4.��̬��Ա����û�����ص�thisָ�룬���ܷ����κηǾ�̬��Ա
5.��̬��ԱҲ����ĳ�Ա����public��protected��private �����޶���������
*/

//������:ʵ��һ���࣬��������д������˶��ٸ������
//#include<iostream>
//using std::cout;
//using std::endl;
//class Test
//{
//public:
//	Test() { ++_objectCount; }
//	Test(const Test&) { ++_objectCount; }
//	~Test() { --_objectCount; }
//	static int GetObjectCount() { return _objectCount; }//��̬��Ա����
//private:
//	static int _objectCount;//��̬��Ա����
//};
//int Test::_objectCount = 0;
//int main()
//{
//	Test t1;
//	Test t2(t1);
//	cout << t2.GetObjectCount() << endl;//2
//	Test t3;
//	cout << Test::GetObjectCount() << endl;//3
//	return 0;
//}

//���һ��ֻ����ջ�϶���������
//#include<iostream>
//class OnlyStack
//{
//public:
//	static OnlyStack CreatObject()
//	{
//		OnlyStack obj;
//		return obj;
//	}
//private:
//	OnlyStack(int dataX = 0, int dataY = 0) :_dataX(dataX), _dataY(dataY) {}
//	int _dataX;
//	int _dataY;
//};
//int main()
//{
//	OnlyStack obj1 = OnlyStack::CreatObject();
//	return 0;
//}

































//��Ԫ
/*
��Ԫ�ṩ��һ��ͻ�Ʒ�װ�ķ�ʽ����ʱ�ṩ�˱�����������Ԫ��������϶ȣ��ƻ��˷�װ��������Ԫ���˶��á�
��Ԫ��Ϊ����Ԫ��������Ԫ��
*/
/*
��Ԫ����:
��Ԫ��������ֱ�ӷ������˽�г�Ա�����Ƕ��������ⲿ����ͨ�������������κ��࣬����Ҫ������ڲ�����������ʱ��Ҫ��friend�ؼ���
ע��:
1.��Ԫ�����ɷ������˽�кͱ�����Ա����������ĳ�Ա����
2.��Ԫ����������const����
3.��Ԫ�����������ඨ����κεط�����������������޶�������
4.һ�����������Ƕ�������Ԫ�����������ϵ���ɱ��̳�
5.��Ԫ�����ĵ�������ͨ�����ĵ���ԭ����ͬ

��Ԫ��:
1.��Ԫ������г�Ա��������������һ�������Ԫ�����������Է�����һ�����еķǹ��г�Ա��
2.��Ԫ��ϵ�ǵ���ģ������н����ԡ�
3.��Ԫ��ϵ���ܴ���
4.��Ԫ��ϵ���ܼ̳�
*/

































//�ڲ���
/*
��һ���ඨ������һ������ڲ�������ڲ���ͽ����ڲ��ࡣ�ڲ�����һ���������࣬���������ⲿ�࣬������ͨ���ⲿ��Ķ���ȥ�����ڲ���ĳ�Ա��
�ⲿ����ڲ���û���κ���Խ�ķ���Ȩ�ޡ�
ע��:
1.�ڲ������ⲿ�����Ԫ�࣬�ڲ������ͨ���ⲿ��Ķ�������������ⲿ���е����г�Ա�������ⲿ�಻���ڲ������Ԫ��
2.�ڲ�����Զ������ⲿ���public��protected��private���ǿ��Ե�,���������ơ�
3.ע���ڲ������ֱ�ӷ����ⲿ���е�static��Ա������Ҫ�ⲿ��Ķ���/������
4.sizeof(�ⲿ��)=�ⲿ�࣬���ڲ���û���κι�ϵ
5.�ڲ������ⲿ�����������
*/
//#include<iostream>
//using std::cout;
//using std::endl;
//class A
//{
//public:
//	class B // B��������A����Ԫ
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _x << endl;//����static
//			cout << a._y << endl;//��Ԫ
//		}
//	private:
//		int _data;
//	};
//private:
//	static int _x;
//	int _y;
//};
//int A::_x = 1;
//int main()
//{
//	A::B b;//B����A�����������
//	b.foo(A());
//	cout << sizeof(A) << endl;//4	
//	return 0;
//}































//������
//#include <iostream>
//#include <cassert>
//using std::cout;
//using std::cin;
//using std::endl;
//using std::ostream;
//using std::istream;
//class Date
//{
//	friend inline ostream& operator<<(ostream& out, const Date& d);
//	friend inline istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year, int month, int day);
//
//	int GetMonthDay(int year, int month)const//�ú����������г�Ϊ��������
//	{
//		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//���������Ϊ��̬�����δ���
//		int day = days[month];
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			day += 1;
//		}
//		return day;
//	}
//	bool CheckDate()const
//	{
//		return (_year >= 1 && _month > 0 && _month < 13 && _day > 0 && _day <= GetMonthDay(_year, _month));
//	}
//
//	Date& operator=(const Date& temp);
//
//	bool operator==(const Date& temp)const;
//	bool operator!=(const Date& temp)const;
//	bool operator>(const Date& temp)const;
//	bool operator>=(const Date& temp)const;
//	bool operator<(const Date& temp)const;
//	bool operator<=(const Date& temp)const;
//
//	Date operator+(int day)const;
//	Date& operator+=(int day);
//	Date operator-(int day)const;
//	Date& operator-=(int day);
//
//	Date& operator++();
//	Date operator++(int);
//	Date& operator--();
//	Date operator--(int);
//
//	int operator-(const Date& temp)const;
//
//	void Print()const;
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date::Date(int year = 2003, int month = 10, int day = 23)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//	if (!CheckDate())
//	{
//		cout << "�Ƿ�����:";
//		Print();
//	}
//}
//
//Date& Date::operator=(const Date& temp)//�������ʵ����û��Ҫ��ʾ�ṩ
//{
//	if (this != &temp)//���������������ֵ�����
//	{
//		this->_year = temp._year;
//		this->_month = temp._month;
//		this->_day = temp._day;
//	}
//	return *this;//ʵ��=���������ʽ��ֵ
//}
//
//bool Date::operator==(const Date& temp)const
//{
//	return _year == temp._year && _month == temp._month && _day == temp._day;
//}
//bool Date::operator!=(const Date& temp)const
//{
//	return !(*this == temp);
//}
//bool Date::operator>(const Date& temp)const
//{
//	if (_year > temp._year)
//		return true;
//	else if (_year == temp._year && _month > temp._month)
//		return true;
//	else if (_year == temp._year && _month == temp._month && _day > temp._day)
//		return true;
//	else
//		return false;
//}
//bool Date::operator>=(const Date& temp)const
//{
//	return (*this > temp) || (*this == temp);
//}
//bool Date::operator<(const Date& temp)const
//{
//	return !(*this >= temp);
//}
//bool Date::operator<=(const Date& temp)const
//{
//	return !(*this > temp);
//}
//
//Date Date::operator+(int day)const
//{
//	Date temp(*this);
//	temp += day;
//	return temp;
//}
//Date& Date::operator+=(int day)
//{
//	if (day < 0)
//	{
//		return *this -= -day;
//	}
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		++_month;
//		if (_month == 13)
//		{
//			_month = 1;
//			++_year;
//		}
//	}
//	return *this;
//}
//Date Date::operator-(int day)const
//{
//	Date temp(*this);
//	temp -= day;
//	return temp;
//}
//Date& Date::operator-=(int day)
//{
//	if (day < 0)
//	{
//		return *this+=-day;
//	}
//	_day -= day;
//	while (_day <= 0)
//	{
//		--_month;
//		if (_month == 0)
//		{
//			--_year;
//			_month = 12;
//		}
//		_day += GetMonthDay(_year, _month);
//	}
//	return *this;
//}
//
//
//Date& Date::operator++()//ǰ��++
//{
//	*this += 1;
//	return *this;
//}
//Date Date::operator++(int)//����++
//{
//	Date temp(*this);
//	*this += 1;
//	return temp;//���ؾֲ���������������������٣�����ʹ�����÷���
//}
//Date& Date::operator--()//ǰ��--
//{
//	return *this -= 1;
//}
//Date Date::operator--(int)//����--
//{
//	Date temp(*this);
//	*this -= 1;
//	return temp;//���ؾֲ���������������������٣�����ʹ�����÷���
//}
//
//int Date::operator-(const Date& temp)const
//{
//	int flag = 1;
//	Date max = *this;
//	Date min = temp;
//	if (max < min)
//	{
//		max = temp;
//		min = *this;
//		flag = -1;
//	}
//	int count = 0;
//	while (max != min)//!=���߼���>����
//	{
//		++min;
//		++count;
//	}
//	return count*flag;
//}
//
//void Date::Print()const
//{
//	cout << _year << "_" << _month << "_" << _day << endl;
//}
//
////������Ϊȫ�ֺ���,ע���βα�˳��
//inline ostream& operator<<(ostream& out,const Date& d)
//{
//	out << d._year << "_" << d._month << "_" << d._day;
//	return out;
//}
//inline istream& operator>>(istream& in,Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	assert(d.CheckDate());
//	return in;
//}
//int main()
//{
//	Date day1(2022, 8, 23);//���ù��캯��
//
//	Date day2(day1);//���ñ�����Ĭ���ṩ�Ŀ������캯��
//
//	Date day3;//����ȫȱʡ���캯��
//	Date day4;
//
//	day4 = day3 = day1;//���ø�ֵ��������غ���
//
//	cout << day1 << endl;
//	cout << day2 << endl;
//	cout << day3 << endl;
//	cout << day4 << endl;
//
//	cout << (day1 == day2) << endl;//1
//	cout << (day1 != day2) << endl;//0
//	cout << (day1 > day2) << endl;//0
//	cout << (day1 < day2) << endl;//0
//	cout << (day1 >= day2) << endl;//1
//	cout << (day1 <= day2) << endl;//1
//
//	cout << (day1++) << endl;//2022_8_23
//	cout << (++day1) << endl;;//2022_8_25
//	cout << (day1--) << endl;//2022_8_25
//	cout << (--day1) << endl;//2022_8_23
//
//	day1 += 5;
//	cout << day1 << endl;//2022_8_28
//	day1 = day1 + 4;
//	cout << day1 << endl;//2022_9_1
//
//
//	day1 = day1 - 4;
//	cout << day1 << endl;//2022_8_28
//	day1 -= 5;
//	cout << day1 << endl;//2022_8_23
//
//	day1 += 100;
//	int num = day1 - day4;
//	cout << num << endl;//100
//	
//	Date day5(1000, 13, 55);//�Ƿ�����:1000_13_55
//
//	cin >> day5;
//	cout << day5;
//	return 0;
//}















