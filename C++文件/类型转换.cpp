//#include <stdio.h>
//int main()
//{
//	// ��ʽ����ת��
//	int i = 1;
//	double d = i;
//	printf("%d, %.2f\n", i, d);//1, 1.00
//	
//	// ��ʾ��ǿ������ת��
//	int* p = &i;
//	int address = (int)p;
//	printf("%p %d\n", p, address);//008FF8EC 9435372
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;//12
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 12;
//
//	//�������ʹ��static_cast�ᱨ��
//	//int *p = static_cast<int*>(a);//����ת����Ч
//
//	int* p = reinterpret_cast<int*>(a);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	const int a = 2;
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << endl;//2
//	cout << *p << endl;//3
//	return 0;
//}










//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void f(){}
//public:
//	int _a = 0;
//};
//class B : public A
//{
//public:
//	int _b = 1;
//};
//
//void Func(A* pa)
//{
//	if (pa == nullptr) return;
//
//	//��pa��ָ�����࣬��ô����ת����ת�����ʽ������ȷ�ĵ�ַ
//	//��pa��ָ���࣬��ô����ת����ת�����ʽ����nullptr
//
//	B* pb = dynamic_cast<B*>(pa); // ��ȫ��
//	//B* pb = (B*)pa;             // ����ȫ
//
//	if (pb){
//		cout << "ת���ɹ�" << endl;
//		pb->_a++;
//		pb->_b++;
//		cout << pb->_a << ":" << pb->_b << endl;
//	}
//	else
//	{
//		cout << "ת��ʧ��" << endl;
//		pa->_a++;
//		cout << pa->_a << endl;
//	}
//}
//
//int main()
//{
//	//A aa;
//	//Func(&aa);
//	B bb;
//	Func(&bb);
//	return 0;
//}













//#include <iostream>
//using namespace std;
//class A1
//{
//public:
//	virtual void f(){}
//public:
//	int _a1 = 0;
//};
//
//class A2
//{
//public:
//	virtual void f(){}
//public:
//	int _a2 = 0;
//};
//
//class B : public A1, public A2
//{
//public:
//	int _b = 1;
//};
//
//int main()
//{
//	B bb;
//	A1* ptr1 = &bb;
//	A2* ptr2 = &bb;
//	cout << ptr1 << endl;
//	cout << ptr2 << endl << endl;
//
//	B* pb1 = (B*)ptr1;
//	B* pb2 = (B*)ptr2;
//	cout << pb1 << endl;
//	cout << pb2 << endl << endl;
//
//	B* pb3 = dynamic_cast<B*>(ptr1);
//	B* pb4 = dynamic_cast<B*>(ptr2);
//	cout << pb3 << endl;
//	cout << pb4 << endl << endl;
//
//	return 0;
//}















//�Զ�����������תΪ������������
//#include <iostream>
//using namespace std;
//class Test
//{
//public:
//	Test(const int data) :_data(data) { cout << "���ù��캯��" << endl; }
//	Test(const Test& tmp) {
//		_data = tmp._data;
//		cout << "���ÿ�������" << endl;
//	}
//	operator int(){
//		return _data;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	Test t = 1;
//	int a = t;
//	int b = t.operator int();
//	cout << a << " " << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Test
//{
//public:
//	Test(const int data) :_data(data) { cout << "���ù��캯��" << endl; }
//	Test(const Test& tmp) {
//		_data = tmp._data;
//		cout << "���ÿ�������" << endl;
//	}
//	explicit operator int(){//��ֹ��ʽ����ת��
//		return _data;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	Test t = 1;
//	//����ʹ��ǿ������ת��
//	int a = (int)t;
//	int b = static_cast<int> (t);
//	cout << a << " " << b << endl;
//	return 0;
//}