
/*
��̬���ڲ�ͬ�̳й�ϵ�������ȥ����ͬһ�����������˲�ͬ����Ϊ��
����Student�̳���Person��Person������Ʊȫ�ۣ�Student������Ʊ���
*/

/*
�麯��: ����virtual���ε����Ա������Ϊ�麯��

�麯������д(����): ����������һ����������ȫ��ͬ���麯��(���������麯��������麯���ķ���ֵ���͡��������֡������б���ȫ��ͬ)��
					��������麯����д�˻�����麯��



��д������:
1.�����麯������virtual(�������)�����ɹ�����д��ʵ��ʹ������ü���

2. Э��(�������������麯������ֵ���Ͳ�ͬ)
��������д�����麯��ʱ��������麯������ֵ���Ͳ�ͬ��
�������麯�����ػ������(��һ���Ǳ��࣬�����̳й�ϵ�еĻ���Ҳ��)��ָ��������ã�
�������麯���������������(��һ���Ǳ��࣬�����̳й�ϵ�е�������Ҳ��)��ָ���������ʱ����ΪЭ��

3.������������д(�������������������������ֲ�ͬ) ���齫��������������麯��
��Ȼ����������ͬ������������������������������������⴦���������������������ͳһ�����destructor



�ڼ̳���Ҫ���ɶ�̬����������:
1. ����ͨ�������ָ��������õ����麯��
2. �����õĺ����������麯���������������Ի�����麯��������д
*/


// C++11 override��final
/*
final:		�����麯������ʾ���麯�������ٱ���д
override:	����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��
*/



//������
/*
���麯���ĺ���д�� = 0 �����������Ϊ���麯����
�������麯��������������ࣨҲ�нӿ��ࣩ�������಻��ʵ����������
������̳к�Ҳ����ʵ����������ֻ����д���麯�������������ʵ����������
���麯���淶�������������д�����ⴿ�麯�������ֳ��˽ӿڼ̳�
*/

//#include<iostream>
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();//B->1
//	return 0;
//}
/*
��ͨ�����̳���ʵ�ּ̳�
�麯����д�ǽӿڼ̳�(����Ա������ܼ̳�)����дʵ��
*/







































//��̬��ԭ��

/*
����_b��Ա������һ��__vfptr���ڶ����ǰ��(ע����Щƽ̨���ܻ�ŵ����������棬�����ƽ̨�й�)
�����е����ָ�����ǽ����麯����ָ��(v����virtual��f����function)��
һ�������麯�������ж����ٶ���һ���麯����ָ�룬��Ϊ�麯���ĵ�ַҪ���ŵ��麯�����У��麯����Ҳ������
�麯��������һ�����麯��ָ���ָ�����飬windows���������������������һ��nullptr
*/
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//int main()
//{
//	cout << sizeof(Base) << endl;//8
//	return 0;
//}

/*
��̬���ֳ�Ϊǰ�ڰ�(���)���ڳ�������ڼ�ȷ���˳������Ϊ��Ҳ��Ϊ��̬��̬�����磺��������
2. ��̬���ֳƺ��ڰ�(���)�����ڳ��������ڼ䣬���ݾ����õ�������ȷ������ľ�����Ϊ�����þ���ĺ�����Ҳ��Ϊ��̬��̬
*/
































//���̳��е��麯����
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};
//typedef void(*VFPTR)();
//void PrintVFTable(VFPTR table[]) {
//	for (int i = 0; table[i] != nullptr; ++i) {
//		cout << i << " " << (table + i) << " " << table[i] << " ";
//		table[i]();
//	}
//	cout << endl;
//}

//int main()
//{
//	Base b;//ͬһ�����͵Ķ�����ͬһ���麯����
//	Derive d;//vs�� �����Ƿ������д���������͸�������ǲ�ͬ��
//
//	PrintVFTable((VFPTR*)*(int*)&b);//ȡ����ͷ���麯����ָ��
//	PrintVFTable((VFPTR*)*(int*)&d);
//	return 0;
//}






//��̳��е��麯����
//#include<iostream>
//using namespace std;
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*VFPTR)();
//void PrintVFTable(VFPTR table[]) {
//	for (int i = 0; table[i] !=  nullptr; ++i) {
//		cout << i << " " << (table + i) << " " << table[i] << " ";
//		table[i]();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Derive d;
//	cout << sizeof(d) << endl;//20
//	PrintVFTable((VFPTR*)(*(int*)&d));
//	Base2* ptr = &d;
//	PrintVFTable((VFPTR*)(*(int*)(ptr)));
//	return 0;
//}
/*
��̳��������δ��д���麯�����ڵ�һ���̳л��ಿ�ֵ��麯������
*/






//#include<iostream>
//using namespace std;
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*VFPTR)();
//void PrintVFTable(VFPTR table[]) {
//	for (int i = 0; table[i] != nullptr; ++i) {
//		cout << i << " " << (table + i) << " " << table[i] << " ";
//		table[i]();
//	}
//	cout << endl;
//}
//int main()
//{
//	Derive d;
//	PrintVFTable((VFPTR*)(*(int*)&d));
//	Base2* ptr = &d;
//	PrintVFTable((VFPTR*)(*(int*)(ptr)));
//
//	printf("%p\n", &Derive::func1);//�﷨�涨����Ա���������&����ȡ�����ַ
//
//	d.func1();
//	Base1* ptr1 = &d;
//	ptr1->func1();
//	Base2* ptr2 = &d;
//	ptr2->func1();
//
//	return 0;
//}
/*
���������Derive::func1��ӡ�������ĵ�ַ��һ��
*/




























