/*****************************************************���ܱ���������********************************************************/

//class Test1
//{
//public:
//	Test1() {};
//private:
//	Test1(const Test1&);
//	Test1 operator=(const Test1&);
//};

//class Test2
//{
//public:
//	Test2() {};
//	Test2(const Test2&) = delete;
//	Test2 operator=(const Test2&) = delete;
//};
















/*************************************************ֻ���ڶ����ϴ����������***************************************************/
//class HeapOnly
//{
//public:
//	static HeapOnly* CreatObj() {
//		return new HeapOnly;
//	}
//private:
//	HeapOnly() {};
//	//������
//	HeapOnly(const HeapOnly&) = delete;/*��ֹ����������� HeapOnly obj2(*obj); */
//};
//int main()
//{
//	HeapOnly* obj = HeapOnly::CreatObj();
//	return 0;
//}
















/**************************************************ֻ����ջ�ϴ����ռ�*********************************************************/
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	static StackOnly CreateObj() {
//		return StackOnly();
//	}
//private:
//	StackOnly():_data(10) {};
//	void* operator new(size_t) = delete;
//	void operator delete(void*) = delete;
//
//	StackOnly& operator=(const StackOnly&) = delete;
//	/*�������
//	StackOnly* obj = (StackOnly*)malloc(sizeof(StackOnly));
//	if(obj != nullptr) *obj = s1;
//	*/
//private:
//	int _data;
//};
//int main()
//{
//	StackOnly s1 = StackOnly::CreateObj();
//
//	static StackOnly s2(s1);
//	/*
//	�޷����⣬CreateObj���ؾֲ������ض����ÿ������죬���Բ������ο�������
//	���캯��˽�У�����ֱ�ӵ��ù��캯���ھ�̬����������
//	*/
//	return 0;
//}














/****************************************************���ܱ��̳е���********************************************************/
//class Test1
//{
//public:
//	Test1 CreateObj() {//���������ض����ø��๹�캯���������๹�캯��˽��
//		return Test1();
//	}
//private:
//	Test1() {};
//};
//
//class Test2 final
//{
//	//...
//};















/*****************************************************����ģʽ*************************************************************/
//class SingleTon
//{
//public:
//	static SingleTon* GetInstance() {
//		return _inst;
//	}
//private:
//	SingleTon() {};
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//private:
//	static SingleTon* _inst;
//};
//SingleTon* SingleTon::_inst = new SingleTon;



/******************************************************����ģʽ************************************************************/

//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//class SingleTon
//{
//public:
//	SingleTon* GetInstance() {
//		if (_inst == nullptr) //���������μ�������
//		{
//			unique_lock<mutex>(_mtx);//ʹ��RAII������������new�׳��쳣������δ�ͷ�
//			if (_inst == nullptr)//������new 
//			{
//				_inst = new SingleTon();
//			}
//		}
//		return _inst;
//	}
//	static void DelInstance() {//ȷ���ͷ�ʱ�̰߳�ȫ���������ͷ�
//		unique_lock<mutex>(_mtx);
//		if (_inst != nullptr) {
//			delete _inst;
//		}
//	}
//private:
//	SingleTon() {};
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//private:
//	static SingleTon* _inst;
//	static mutex _mtx;
//};
//SingleTon* SingleTon::_inst = nullptr;
//mutex SingleTon::_mtx;


//class SingleTon
//{
//public:
//	SingleTon* GetInstance() {
//		static SingleTon inst;//ԭ�Ӳ���
//		return &inst;
//	}
//private:
//	SingleTon() {};
//	SingleTon(const SingleTon&) = delete;
//	SingleTon& operator=(const SingleTon&) = delete;
//};