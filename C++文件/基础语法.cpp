//�����ռ�
/*
��C/C++�У��������������඼�Ǵ������ڵģ���Щ������������������ƽ���������ȫ���������У�
���ܻᵼ�ºܶ��ͻ��ʹ�������ռ��Ŀ���ǶԱ�ʶ�������ƽ��б��ػ����Ա���������ͻ��������Ⱦ��
namespace�ؼ��ֵĳ��־���������������
*/
//ע��:
//1.һ�������ռ�Ͷ�����һ���µ������������ռ��е��������ݶ������ڸ������ռ���
//2.����Ŀ�С�������Ҫʹ��using namespace std; , ����ָ�������ռ����չ�����õ�(��:using std::cout;)
//3.�����ռ��п��Զ������/����/����
//4.�����ռ����Ƕ��
//5.ͬһ��������������ڶ����ͬ���Ƶ������ռ�,����������ϳ�ͬһ�������ռ���




//#include<iostream>
//namespace handsomeBoy
//{
//	int rand = 0;
//}
//using namespace handsomeBoy;
//int main()
//{
//	//cout << rand << endl;//error ��rand������ͻ
//	std::cout << handsomeBoy::rand << std::endl;
//	return 0;
//}































//C++�������
/*
1. ʹ��cout��׼�������(����̨)��cin��׼�������(����)ʱ��������� <iostream> ͷ�ļ��Լ��������ռ�ʹ�÷���ʹ��std��

2. cout��cin��ȫ�ֵ�������endl�������C++���ţ���ʾ������������Ƕ������ڰ��� <iostream> �ļ��С�

3. <<���������������>>������ȡ�������

4. ʹ��C++������������㣬����Ҫ��printf/scanf�������ʱ��������Ҫ�ֶ����Ƹ�ʽ��C++��������������Զ�ʶ��������͡�

5. ʵ����cout��cin�ֱ���ostream��istream���͵Ķ���

ע�⣺���ڱ�׼�⽫���й�����ȫ������ʵ�֣�������.h��׺��ͷ�ļ��У�ʹ��ʱֻ�������Ӧͷ�ļ�����,
��������ʵ����std�����ռ��£�Ϊ�˺�Cͷ�ļ����֣�ҲΪ����ȷʹ�������ռ䣬�涨C++ͷ�ļ�����.h;
�ɱ�����(vc 6.0)�л�֧��<iostream.h>��ʽ�������������Ѳ�֧�֣�����Ƽ�ʹ��<iostream>+std�ķ�ʽ��
*/


//#include<iostream>
//int main()
//{
//	double d = 0.0;
//	int x = 0;
//	std::cin >> d >> x;//�Զ�ʶ����������
//	std::cout << d << " " << x << std::endl;
//	return 0;
//}






























//ȱʡ����
/*
ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��ȱʡֵ���ڵ��øú���ʱ�����û��ָ��ʵ������ø��βε�ȱʡֵ������ʹ��ָ����ʵ�Ρ�

ȱʡ��������:ȫȱʡ��������ȱʡ����

ע�⣺
1. ��ȱʡ�������� �������� ���������������ܼ���Ÿ�
2. ȱʡ���������ں��������Ͷ�����ͬʱ���֡���ͬʱ����ʱ��Ӧ������ʱ���� 
3. ȱʡֵ�����ǳ�������ȫ�ֱ���
4. C���Բ�֧�֣���������֧�֣�
*/


//#include<iostream>
//using std::cout;
//using std::endl;
//void Func_1(int a = 10, int b = 20, int c = 30)//ȫȱʡ
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//void Func_2(int a, int b = 10, int c = 20)//��ȱʡ
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Func_1();//10 20 30 
//	cout << endl;
//	Func_2(1);//1 10 20
//	//ʵ�δ������Ҵ���
//
//	return 0;
//}
































//��������
/*
���������Ǻ�����һ�����������C++������ͬһ�����������������������Ƶ�ͬ����������Щͬ������
���β��б�(�������� �� ���� �� ����˳��)��ͬ������������ʵ�ֹ��������������Ͳ�ͬ������
*/

//#include<iostream>
//int Add(int a, int b)
//{
//	return a + b;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret1 = Add(1, 2);
//	std::cout << ret1 << std::endl;
//
//	double ret2 = Add(1.1, 2.2);
//	std::cout << ret2 << std::endl;
//	return 0;
//}



//C++֧�ֺ������ص�ԭ��--�����������ι���
/*
ÿ��.o�ļ���������ű�
gcc�ĺ������κ����ֲ��䡣��g++�ĺ������κ��� [_Z+��������+������+��������ĸ]
windows��vs�������Ժ����������ι���ͬ
*/






//extern "C"
/*
����C��C++�������Ժ����������ι���Ĳ�ͬ������Щ�����¿��ܾͻ�����⣬����:

1. C++�е���C����ʵ�ֵľ�̬����߶�̬�⣬��֮��Ȼ
2. ����Эͬ����ʱ����Щ��ʹ��C���ԣ���Щ��ʹ����C++

�����ֻ��ģʽ�¿���������C��C++�������Ժ����������ι���ͬ�����ܾͻᵼ������ʧ�ܣ��ڸ��ֳ���
�£�����Ҫʹ��extern "C"���ں���ǰ��extern "C"����˼�Ǹ��߱����������ú�������C���Թ���������

1.C++�������C��: 
��C++��������ͷ�ļ�ʱextern "C"

2.C�������C++��(������ȫ����):
��C++���ͷ�ļ���extern "C"
#ifdef __cplusplus
extern "C"
{
#endif
��������
��������
#ifdef __cplusplus
}
#endif
*/



























//����
/*
���ò����¶���һ�����������Ǹ��Ѵ��ڱ���ȡ��һ������������������Ϊ���ñ��������ڴ�ռ䣬���������õı�������ͬһ���ڴ�ռ�
�������ͱ��������ʵ����ͬ�����͵ġ�

����:
1. �����ڶ���ʱ�����ʼ��
2. һ�����������ж������
3. ����һ������һ��ʵ�壬�ٲ�����������ʵ��

*/

//#include<iostream>
//int main()
//{
//	int a = 10;
//	// int& ra; // ����������ʱ�����
//	int& xa = a;
//	int& xxa = a;
//	std::cout << &a << " " << &xa << " " << &xxa << std::endl;
//	return 0;
//}






//������

//#include<iostream>
//int main()
//{
//	int a = 1;
//	int& b = a;//Ȩ��ƽ�� ok
//
//	const int c = 2;
//	const int& d = c;//����д��int& d = c; �����Ȩ�޷Ŵ� err
//
//	int e = 3;
//	const int& f = e;//Ȩ����С ok
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int data = 1;
//	double d = data;
//	//double& xd = data;    err
//	const double& xd = data;
//	/*
//	��ʽ����ת��/ǿ������ת�����������ʱ����
//	��ʱ�������г���
//	��data����xd,��Ȩ�޷Ŵ���˴���
//	*/
//	cout << xd << endl;
//	return 0;
//}






//���õ�ʹ�ó���:
/*
1.������
	a.������� b.����󴫲�ʱ,�����Ч��
2.������ֵ
*/

//#include<iostream>
//using namespace std;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	Swap(a, b);
//	cout << "a = " << a << endl;//20
//	cout << "b = " << b << endl;//10
//	return 0;
//}

//err����
/*
����������ʱ�����˺���������������ض�����(��û����ϵͳ)�������ʹ�����÷��أ�
����Ѿ�����ϵͳ�ˣ������ʹ�ô�ֵ����
*/
//#include<iostream>
//using namespace std;
//int& Add(int a, int b)
//{
//	int c = a + b;
//	cout << c << endl;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add(1, 2) is :" << ret << endl;//3
//	cout << "Add(1, 2) is :" << ret << endl;//���ֵ,��ʱԭ������c���ڿռ䱻ϵͳ����
//	return 0;
//}






//��ֵ��������Ч�ʱȽ�
/*
��ֵ��Ϊ�������߷���ֵ���ͣ��ڴ��κͷ����ڼ䣬��������ֱ�Ӵ���ʵ�λ��߽���������ֱ�ӷ��أ����Ǵ���ʵ�λ��߷��ر�����һ����ʱ�Ŀ�����
�����ֵ��Ϊ�������߷���ֵ���ͣ�Ч���Ƿǳ����µģ������ǵ��������߷���ֵ���ͷǳ���ʱ��Ч�ʾ͸���
*/

//ֵ�����õ���Ϊ�������͵����ܱȽ�
//#include <iostream>
//#include <time.h>
//using namespace std;
//struct A { int a[10000]; };
//void TestFunc1(A data) {}
//void TestFunc2(A& data) {}
//void TestRefAndValue()
//{
//	A a = { {0} };
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;//13
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//1
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}


//ֵ�����õ���Ϊ����ֵ���͵����ܱȽ�
//#include<iostream>
//#include <time.h>
//using namespace std;
//struct A
//{ 
//	int a[10000]; 
//}a;
//A TestFunc1()
//{
//	return a; 
//}
//A& TestFunc2()
//{ 
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;//157
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;//2
//}
//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}






//���ú�ָ�������
/*
���﷨���������þ���һ��������û�ж����ռ䣬��������ʵ�干��ͬһ��ռ�
�ڵײ�ʵ����ʵ�����пռ�ģ���Ϊ�����ǰ���ָ�뷽ʽ��ʵ�ֵġ�
*/

/*
���ú�ָ��Ĳ�ͬ��:
1. ���ø����϶���һ�������ı�����ָ��洢һ��������ַ��

2. �����ڶ���ʱ�����ʼ����ָ��û��Ҫ��

3. �����ڳ�ʼ��ʱ����һ��ʵ��󣬾Ͳ�������������ʵ�壬��ָ��������κ�ʱ��ָ���κ�һ��ͬ����ʵ��

4. û��NULL���ã�����NULLָ��

5. ��sizeof�к��岻ͬ�����ý��Ϊ�������͵Ĵ�С����ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ���(32λƽ̨��ռ4���ֽ�)

6. �����ԼӼ����õ�ʵ������1��ָ���ԼӼ�ָ�����ƫ��һ�����͵Ĵ�С

7. �ж༶ָ�룬����û�ж༶����

8. ����ʵ�巽ʽ��ͬ��ָ����Ҫ��ʽ�����ã����ñ������Լ�����

9. ���ñ�ָ��ʹ��������Ը���ȫ
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//
//	int* pa = &a;
//	*pa = 20;
//
//	int& xa = a;
//	xa = 10;
//
//	return 0;
//}
/*
�����
	int* pa = &a;
00B82036  lea         eax,[a]
00B82039  mov         dword ptr [pa],eax
	*pa = 20;
00B8203C  mov         eax,dword ptr [pa]
00B8203F  mov         dword ptr [eax],14h

	int& xa = a;
00B82045  lea         eax,[a]
00B82048  mov         dword ptr [xa],eax
	xa = 10;
00B8204B  mov         eax,dword ptr [xa]
00B8204E  mov         dword ptr [eax],0Ah
*/
