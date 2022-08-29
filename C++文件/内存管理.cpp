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
//	Test(int data = 0): _data(data)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//int main()
//{
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	Test* p2 = new Test(1);
//	free(p1);
//	delete p2;
//
//	cout << endl;
//
//	Test* p5 = (Test*)malloc(sizeof(Test) * 10);
//	Test* p6 = new Test[10];
//	free(p5);
//	delete[] p6;
//
//	cout << endl;
//	return 0;
//}


































































