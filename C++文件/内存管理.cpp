//�ڴ�ֲ�
/*
1.�ں˿ռ�(�û����벻�ɶ�д)

2.ջ�ֽж�ջ--�Ǿ�̬�ֲ�����/��������/����ֵ�ȵȣ�ջ������������

3.�ڴ�ӳ����Ǹ�Ч��I/Oӳ�䷽ʽ������װ��һ������Ķ�̬�ڴ�⡣�û���ʹ��ϵͳ�ӿڴ��������ڴ棬�����̼�ͨ��

4.�����ڳ�������ʱ��̬�ڴ���䣬���ǿ�����������

5.���ݶ�(��̬��)--�洢ȫ�����ݺ;�̬����

6.�����(������)--��ִ�еĴ���(������ָ�����)/ֻ������
*/











 




















//new��delete������������
/*
������ͷŵ���Ԫ�صĿռ䣬ʹ��new��delete��������������ͷ������Ŀռ䣬ʹ��new[]��delete[]
����������ͣ�new��delete��malloc��freeû�б��ʵ�����ֻ���÷��ϵ������÷���
*/
//#include<iostream>
//void Test()
//{
//	int* ptr1 = new int;//��̬����һ��int���͵Ŀռ�
//	
//	int* ptr2 = new int(10);//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	
//	int* ptr3 = new int[10];// ��̬����10��int���͵Ŀռ�
//
//	//C++98��֧�ֶ������ʼ����C++11֧�����û����ų�ʼ��
//	int* ptr4 = new int[5]{ 1,2,3 };
//
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;
//	delete[] ptr4;
//}
//int main()
//{
//	Test();
//	return 0;
//}



//new��delete�����Զ�������
/*
�������Զ������͵Ŀռ�ʱ��new����ù��캯����ʼ����delete�������������������malloc��free����
���ʹ��new������Ĭ�Ϲ��캯��
*/
//#include<iostream>
//#include<cstdlib>
//using namespace std;
//class Test
//{
//public:
//	Test(int data = 0): _data(data) { cout << "Test():" << this << endl; }
//	~Test() { cout << "~Test():" << this << endl; }
//private:
//	int _data;
//};
//int main()
//{
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//	cout << endl;
//
//	Test* p2 = new Test(1);
//	delete p2;
//	cout << endl;
//
//	Test* p5 = (Test*)malloc(sizeof(Test) * 10);
//	free(p5);
//	cout << endl;
//
//	Test* p6 = new Test[10];
//	delete[] p6;
//
//	return 0;
//}
































//operator new��operator delete����
/*
new��delete�ײ�ֱ����operator new��operator delete������operator new��operator delete���������Ƕ�new��delete�Ĳ���������

new��delete���û����ж�̬�ڴ�������ͷŵĲ�������operator new ��operator delete��ϵͳ�ṩ��ȫ�ֺ�����
new�ڵײ����operator newȫ�ֺ���������ռ� + ���캯����delete�ڵײ�ͨ��operator deleteȫ�ֺ������ͷſռ� + ��������

operator newʵ��Ҳ��ͨ��malloc������ռ䣬���malloc����ռ�ɹ���ֱ�ӷ��أ�����ִ���û��ṩ�Ŀռ䲻��Ӧ�Դ�ʩ��
����û��ṩ�ô�ʩ�ͼ������룬��������쳣��operator delete������ͨ��free���ͷſռ��
*/






//����operator new��operator delete
/*
һ������²���Ҫ�� operator new �� operator delete�������أ�������������ͷſռ�ʱ����ĳЩ���������
���磺��ʹ��new��delete������ͷſռ�ʱ����ӡһЩ��־��Ϣ�����Լ򵥰����û�������Ƿ�����ڴ�й©��
*/

// ����operator delete��������ռ�ʱ����ӡ���ĸ��ļ����ĸ��������ڶ����У������˶��ٸ��ֽ�
//#include<iostream>
//using std::cout;
//using std::endl;
//void* operator new(size_t size, const char* fileName, const char* funcName, size_t lineNo)
//{
//	void* p = ::operator new(size);
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-"<< size << endl;
//	return p;
//}
////����operator delete
//void operator delete(void* p)
//{
//	cout <<"delete->" << p << endl;
//	free(p);
//}
//#ifdef _DEBUG//ֻ����Debug��ʽ�£��ŵ����û����ص� operator new
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#endif
//int main()
//{
//	int* p = new int;
//	delete p;
//	return 0;
//}

//�������ר��operator new��operator delete
//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//	Test() { cout << "Test()" << endl; }
//	void* operator new(size_t size)
//	{
//		cout << "void* operator new(size_t size)->STL�ڴ��" << endl;
//		void* obj = _alloc.allocate(1);
//		return obj;
//	}
//	void operator delete(void* ptr)
//	{
//		cout << "void operator delete(void* ptr)->STL�ڴ��" << endl;
//		_alloc.deallocate((Test*)ptr,1);
//	}
//private:
//	static allocator<Test> _alloc;//STL�ڴ��
//	int _data;
//};
//allocator<Test> Test::_alloc;
//int main()
//{
//	//���Ч��:����ʱ�������malloc,�����߶��Ƶ��ڴ��
//	Test* t1 = new Test;
//	Test* t2 = new Test;
//	Test* t3 = new Test;
//	Test* t4 = new Test;
//	delete t1;
//	delete t2;
//	delete t3;
//	delete t4;
//	return 0;
//}
































//new��delete��ʵ��ԭ��
/*
1.��������
����������������͵Ŀռ䣬new��malloc��delete��free�������ƣ�
��ͬ�ĵط���:
new/delete������ͷŵ��ǵ���Ԫ�صĿռ䣬new[]��delete[]������������ռ䣬����new������ռ�ʧ��ʱ�����쳣��malloc��᷵��NULL��

2.�Զ�������
new��ԭ��
1.����operator new��������ռ�
2.������Ŀռ���ִ�й��캯������ɶ���Ĺ���

delete��ԭ��
1. �ڿռ���ִ��������������ɶ�������Դ��������
2. ����operator delete�����ͷŶ���Ŀռ�

new T[N]��ԭ��
1. ����operator new[]��������operator new[]��ʵ�ʵ���operator new�������N������ռ������
2. ������Ŀռ���ִ��N�ι��캯��

delete[]��ԭ��
1. ���ͷŵĶ���ռ���ִ��N���������������N����������Դ������
2. ����operator delete[]�ͷſռ䣬ʵ����operator delete[]�е���operator delete���ͷſռ�

*/


































//��λnew���ʽ(placement-new)
/*
��λnew���ʽ�����ѷ����ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������

ʹ�ø�ʽ��
new (place_address) type����new (place_address) type(initializer-list)
place_address������һ��ָ�룬initializer-list�����͵ĳ�ʼ���б�

ʹ�ó���:
��λnew���ʽ��ʵ����һ��������ڴ��ʹ�á���Ϊ�ڴ�ط�������ڴ�û�г�ʼ����
����������Զ������͵Ķ�����Ҫʹ��new�Ķ�����ʽ������ʾ�����캯�����г�ʼ��
*/
//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//	Test(int a = 0): _data(a) { cout << "Test():" << this << endl; }
//	~Test() { cout << "~Test():" << this << endl; }
//private:
//	int _data;
//};
//int main()
//{
//	//p1����ָ�������Test������ͬ��С��һ�οռ䣬�����캯��û��ִ��
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	new(p1)Test; // ע��:���A��Ĺ��캯���в���ʱ���˴���Ҫ����
//	p1->~Test();
//	free(p1);
//
//	Test* p2 = (Test*)operator new(sizeof(Test));
//	new(p2)Test(10);
//	p2->~Test();
//	operator delete(p2);
//	return 0;
//}

































//malloc��free��new��delete������
/*
malloc/free��new/delete�Ĺ�ͬ����:
���ǴӶ�������ռ䣬������Ҫ�û��ֶ��ͷš�

��ͬ�ĵط���:
1. malloc��free�Ǻ�����new��delete�ǲ�����
2. malloc����Ŀռ䲻���ʼ����new���Գ�ʼ��
3. malloc����ռ�ʱ����Ҫ�ֶ�����ռ��С�����ݣ�newֻ���������Ͽռ�����ͼ��ɣ�����Ƕ������[]��ָ�������������
4. malloc�ķ���ֵΪvoid*, ��ʹ��ʱ����ǿת��new����Ҫ����Ϊnew������ǿռ������
5. malloc����ռ�ʧ��ʱ�����ص���NULL�����ʹ��ʱ�����пգ�new����Ҫ������new��Ҫ�����쳣
6. �����Զ������Ͷ���ʱ��malloc/freeֻ�Ὺ�ٿռ䣬������ù��캯��������������
��new������ռ�����ù��캯����ɶ���ĳ�ʼ����delete���ͷſռ�ǰ���������������ɿռ�����Դ������
*/


































//�ڴ�й©����
/*
ʲô���ڴ�й©:
�ڴ�й©ָ��Ϊ����������ɳ���δ���ͷ��Ѿ�����ʹ�õ��ڴ��������ڴ�й©������ָ�ڴ��������ϵ���ʧ��
����Ӧ�ó������ĳ���ڴ����Ϊ��ƴ���ʧȥ�˶Ըö��ڴ�Ŀ��ƣ����������ڴ���˷ѡ�
�ڴ�й©��Σ��:
�������еĳ�������ڴ�й©��Ӱ��ܴ������ϵͳ����̨����ȵȣ������ڴ�й©�ᵼ����ӦԽ��Խ�������տ���
*/

//�ڴ�й©����
/*
C/C++������һ�����ǹ������ַ�����ڴ�й©:

���ڴ�й©(Heap leak):
���ڴ�ָ���ǳ���ִ����������Ҫ����ͨ��malloc/calloc/realloc/ new�ȴӶ��з����һ���ڴ棬
��������ͨ��������Ӧ�� free����delete ɾ����
����������ƴ������ⲿ���ڴ�û�б��ͷţ���ô�Ժ��ⲿ�ֿռ佫�޷��ٱ�ʹ�ã��ͻ����Heap Leak��

ϵͳ��Դй©:
ָ����ʹ��ϵͳ�������Դ�������׽��֡��ļ����������ܵ���û��ʹ�ö�Ӧ�ĺ����ͷţ�����ϵͳ��Դ���˷ѣ����ؿɵ���ϵͳЧ�ܼ��٣�ϵͳִ�в��ȶ���
*/





















//#include <iostream>
//using namespace std;
//int main()
//{
//	//��̬����һ��int���ʹ�С�Ŀռ�
//	int* ptr1 = new int;
//	delete ptr1;
//
//	//��̬����һ��int���ʹ�С�Ŀռ䲢��ʼ��Ϊ10
//	int* ptr2 = new int(10);
//	cout << *ptr2 << endl;
//	delete ptr2;
//
//	//��̬����10��int���ʹ�С�Ŀո��
//	int* array = new int[10];
//	delete[] array;
//
//	return 0;
//}












//#include<iostream>
//#include<cstdlib>
//using namespace std;
//class Test
//{
//public:
//	Test(int data = 0): _data(data) { cout << "Test():" << this << endl; }
//	~Test() { cout << "~Test():" << this << endl; }
//private:
//	int _data;
//};
//int main()
//{
//	Test* ptr = new Test;
//	delete ptr;
//	return 0;
//}






//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			//report no memory
//			//�������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}






//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)