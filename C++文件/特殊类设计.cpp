//���ܱ���������
//����ֻ�ᷢ�������������У��������캯���Լ���ֵ���������
//�ø��಻�ܵ��ÿ������캯���Լ���ֵ��������ؼ���
/*
1.���������캯���븳ֵ���������ֻ���������壬���ҽ������Ȩ������Ϊ˽�м���
2.=delete
*/













//ֻ���ڶ��ϴ�������
//1.��������˽��
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	void Delete() { delete this; }
//private:
//	~HeapOnly() {}
//private:
//	int _data;
//};
//int main()
//{
//	HeapOnly* p = new HeapOnly;
//	p->Delete();
//	return 0;
//}

//2.���캯������������˽��
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	//�ṩ���еĻ�ȡ����ľ�̬����
//	static HeapOnly* CreateObj(){
//		return new HeapOnly;
//	}
//private:
//	HeapOnly() :_data(0) {};
//	HeapOnly(const HeapOnly& tmp) = delete;
//private:
//	int _data;
//};
//int main()
//{
//	HeapOnly* obj = HeapOnly::CreateObj();
//	delete obj;
//	return 0;
//}














//ֻ����ջ�ϴ�������
//���캯��˽��
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	static StackOnly CreateObj() {
//		return StackOnly();
//	}
//
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	StackOnly():_data(0) {};
//private:
//	int _data;
//};
//int main()
//{
//	StackOnly so = StackOnly::CreateObj();
//
//	static StackOnly s1(so);//�޷���ȫʵ��Ҫ��
//	return 0;
//}












//�޷����̳е���
//1.C++98: ���캯��˽�л����������е���������Ĺ��캯��, ���޷��̳�
//2.final�����࣬��ʾ���಻�ܱ��̳�















//����ģʽ
//������
