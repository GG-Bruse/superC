//内存分布
/*
1.内核空间(用户代码不可读写)

2.栈又叫堆栈--非静态局部变量/函数参数/返回值等等，栈是向下增长的

3.内存映射段是高效的I/O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口创建共享内存，做进程间通信

4.堆用于程序运行时动态内存分配，堆是可以上增长的

5.数据段(静态区)--存储全局数据和静态数据

6.代码段(常量区)--可执行的代码(二进制指令代码)/只读常量
*/











 




















//new、delete操作内置类型
/*
申请和释放单个元素的空间，使用new和delete操作符，申请和释放连续的空间，使用new[]和delete[]
针对内置类型，new、delete跟malloc、free没有本质的区别，只有用法上的区别，用法简化
*/
//#include<iostream>
//void Test()
//{
//	int* ptr1 = new int;//动态申请一个int类型的空间
//	
//	int* ptr2 = new int(10);//动态申请一个int类型的空间并初始化为10
//	
//	int* ptr3 = new int[10];// 动态申请10个int类型的空间
//
//	//C++98不支持对数组初始化，C++11支持利用花括号初始化
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



//new和delete操作自定义类型
/*
在申请自定义类型的空间时，new会调用构造函数初始化，delete会调用析构函数清理，而malloc与free不会
因此使用new必须有默认构造函数
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
































//operator new与operator delete函数
/*
new、delete底层分别调用operator new与operator delete函数，operator new与operator delete函数并不是对new、delete的操作符重载

new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是系统提供的全局函数，
new在底层调用operator new全局函数来申请空间 + 构造函数，delete在底层通过operator delete全局函数来释放空间 + 析构函数

operator new实际也是通过malloc来申请空间，如果malloc申请空间成功就直接返回，否则执行用户提供的空间不足应对措施，
如果用户提供该措施就继续申请，否则就抛异常。operator delete最终是通过free来释放空间的
*/






//重载operator new与operator delete
/*
一般情况下不需要对 operator new 和 operator delete进行重载，除非在申请和释放空间时候有某些特殊的需求。
比如：在使用new和delete申请和释放空间时，打印一些日志信息，可以简单帮助用户来检测是否存在内存泄漏。
*/

// 重载operator delete，在申请空间时：打印在哪个文件、哪个函数、第多少行，申请了多少个字节
//#include<iostream>
//using std::cout;
//using std::endl;
//void* operator new(size_t size, const char* fileName, const char* funcName, size_t lineNo)
//{
//	void* p = ::operator new(size);
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-"<< size << endl;
//	return p;
//}
////重载operator delete
//void operator delete(void* p)
//{
//	cout <<"delete->" << p << endl;
//	free(p);
//}
//#ifdef _DEBUG//只有在Debug方式下，才调用用户重载的 operator new
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#endif
//int main()
//{
//	int* p = new int;
//	delete p;
//	return 0;
//}

//重载类的专属operator new与operator delete
//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//	Test() { cout << "Test()" << endl; }
//	void* operator new(size_t size)
//	{
//		cout << "void* operator new(size_t size)->STL内存池" << endl;
//		void* obj = _alloc.allocate(1);
//		return obj;
//	}
//	void operator delete(void* ptr)
//	{
//		cout << "void operator delete(void* ptr)->STL内存池" << endl;
//		_alloc.deallocate((Test*)ptr,1);
//	}
//private:
//	static allocator<Test> _alloc;//STL内存池
//	int _data;
//};
//allocator<Test> Test::_alloc;
//int main()
//{
//	//提高效率:申请时不会调用malloc,而是走定制的内存池
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
































//new和delete的实现原理
/*
1.内置类型
若申请的是内置类型的空间，new和malloc，delete和free基本类似，
不同的地方是:
new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申请空间失败时会抛异常，malloc则会返回NULL。

2.自定义类型
new的原理
1.调用operator new函数申请空间
2.在申请的空间上执行构造函数，完成对象的构造

delete的原理
1. 在空间上执行析构函数，完成对象中资源的清理工作
2. 调用operator delete函数释放对象的空间

new T[N]的原理
1. 调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对象空间的申请
2. 在申请的空间上执行N次构造函数

delete[]的原理
1. 在释放的对象空间上执行N次析构函数，完成N个对象中资源的清理
2. 调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间

*/


































//定位new表达式(placement-new)
/*
定位new表达式是在已分配的原始内存空间中调用构造函数初始化一个对象。

使用格式：
new (place_address) type或者new (place_address) type(initializer-list)
place_address必须是一个指针，initializer-list是类型的初始化列表

使用场景:
定位new表达式在实际中一般是配合内存池使用。因为内存池分配出的内存没有初始化，
所以如果是自定义类型的对象，需要使用new的定义表达式进行显示调构造函数进行初始化
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
//	//p1现在指向的是与Test对象相同大小的一段空间，但构造函数没有执行
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	new(p1)Test; // 注意:如果A类的构造函数有参数时，此处需要传参
//	p1->~Test();
//	free(p1);
//
//	Test* p2 = (Test*)operator new(sizeof(Test));
//	new(p2)Test(10);
//	p2->~Test();
//	operator delete(p2);
//	return 0;
//}

































//malloc、free和new、delete的区别
/*
malloc/free和new/delete的共同点是:
都是从堆上申请空间，并且需要用户手动释放。

不同的地方是:
1. malloc和free是函数，new和delete是操作符
2. malloc申请的空间不会初始化，new可以初始化
3. malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可，如果是多个对象，[]中指定对象个数即可
4. malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型
5. malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要捕获异常
6. 申请自定义类型对象时，malloc/free只会开辟空间，不会调用构造函数与析构函数，
而new在申请空间后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数完成空间中资源的清理
*/


































//内存泄漏概述
/*
什么是内存泄漏:
内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，
而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。
内存泄漏的危害:
长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死
*/

//内存泄漏分类
/*
C/C++程序中一般我们关心两种方面的内存泄漏:

堆内存泄漏(Heap leak):
堆内存指的是程序执行中依据须要分配通过malloc/calloc/realloc/ new等从堆中分配的一块内存，
用完后必须通过调用相应的 free或者delete 删掉。
假设程序的设计错误导致这部分内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak。

系统资源泄漏:
指程序使用系统分配的资源，比如套接字、文件描述符、管道等没有使用对应的函数释放，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定。
*/





















//#include <iostream>
//using namespace std;
//int main()
//{
//	//动态开辟一个int类型大小的空间
//	int* ptr1 = new int;
//	delete ptr1;
//
//	//动态开辟一个int类型大小的空间并初始化为10
//	int* ptr2 = new int(10);
//	cout << *ptr2 << endl;
//	delete ptr2;
//
//	//动态开辟10个int类型大小的空格键
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
//			//若申请内存失败了，这里会抛出bad_alloc 类型异常
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