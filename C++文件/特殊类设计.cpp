//���ܱ���������
//����ֻ�ᷢ�������������У��������캯���Լ���ֵ���������
//�ø��಻�ܵ��ÿ������캯���Լ���ֵ��������ؼ���
/*
1.���������캯���븳ֵ���������ֻ���������壬���ҽ������Ȩ������Ϊ˽�м���
2.=delete
*/


//class Test
//{
//public:
//	Test() {}
//	//...
//private:
//	//C++98
//	Test(const Test&);
//	Test& operator=(const Test&);
//	//C++11
//	//Test(const Test&) = delete;
//	//Test& operator=(const Test&) = delete;
//};










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
//	static StackOnly&& CreateObj() {
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

//class Perent
//{
//public:
//	static Perent CreatePerentObj() {
//		return Perent();
//	}
//private:
//	Perent() {};
//};













//����ģʽ



//����ģʽ
//class SingleTon
//{
//public:
//	static SingleTon* GetInstance() {//ȫ�ַ��ʵ�
//		return _inst;
//	}
//private:
//	SingleTon() {};//���캯��˽��
//	//������
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//	static SingleTon* _inst;//ָ���������staticָ��
//};
//SingleTon* SingleTon::_inst = new SingleTon;//�ڳ������ǰ��ɵ�������ĳ�ʼ��



//#include <thread>
//#include <mutex>
//using namespace std;
//class SingleTon
//{
//public:
//	static SingleTon* GetInstance() {//ȫ�ַ��ʵ�
//		if (nullptr == _inst)
//		{
//			unique_lock<mutex>(_mtx);
//			if (nullptr == _inst) {
//				_inst = new SingleTon;
//			}
//		}
//	}
//private:
//	SingleTon() {};//���캯��˽��
//	//������
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//	static SingleTon* _inst;//ָ���������staticָ��
//	static mutex _mtx;
//};
//SingleTon* SingleTon::_inst = nullptr;
//mutex SingleTon::_mtx;//���壬�ڳ������ǰ��ɳ�ʼ��



//class SignleTon
//{
//public:
//	static SignleTon* GetInstance() {
//		static SignleTon inst;
//		return &inst;
//	}
//private:
//	SignleTon() {}
//	SignleTon(const SignleTon&) = delete;
//	SignleTon& operator=(const SignleTon&) = delete;
//};