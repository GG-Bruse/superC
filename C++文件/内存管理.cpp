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


































































