#define _CRT_SECURE_NO_WARNINGS

//C++����ת��
/*
����ת��(cast)�ǽ�һ������ת������һ����������
C++��ǿ��ת�������Cǿ��ת�����ŵ�:
�ܸ������ر�������ת����Ŀ��
*/




//��̬ת��(static_cast)
//�﷨:static_cast<Ŀ������>(ԭ����/ԭ����)
/*
1.�������νṹ�л���(����)��������(����)֮��ָ������õ�ת��
(1)��������ת��(���������ָ�������ת���ɻ����ʾ������Χ��С)�ǰ�ȫ��
(2)��������ת��(�ѻ���ָ�������ת�����������ʾ������Χ����)ʱ������û�ж�̬���ͼ�飬�ǲ���ȫ��
2.�������û�����������֮���ת��
*/

//1.��������ָ�������ת��
//#include<iostream>
//using namespace std;
//class Base {};
//class Son :public Base {};
//class Other {};
//int main()
//{
//    Base* base = NULL;
//    Son* son = NULL;
//    //��������ת������ȫ
//    Son* s = static_cast<Son*>(base);
//    //��������ת��
//    Base* b = static_cast<Base*>(son);
//    return 0;
//}


//2.������������ת��
//#include<iostream>
//using namespace std;
//void test()
//{
//    char ch = 'a';
//    double d = static_cast<double>(ch);
//    cout << d << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}











                                                    //��̬����ת��(dynamic_cast)
//�﷨:dynamic_cast<Ŀ������>(ԭ����/ԭ����)
/*
dynamic_cast���ڸ������μ��ָ�����������ת��������ת��(��������������ת��)
�����μ��������ת��ʱ��dynamic_cast��static_cast��Ч����ͬ
�ڽ�������ת��ʱ��dynamic_cast�������ͼ��Ĺ��ܣ���static����ȫ
*/

//#include<iostream>
//using namespace std;
//class Base {};
//class Son :public Base {};
//class Other {};
//int main()
//{
//    Base* base = NULL;
//    Son* son = NULL;
//    //��������ת������ȫ
//    //Son* s = dynamic_cast<Son*>(base);//������ʹ�á���������˶�̬��ת�����ǰ�ȫ�ģ����Խ���ת����
//    //��������ת��
//    Base* b = dynamic_cast<Base*>(son);
//    return 0;
//}









                                                     //����ת��(const_cast)
//�﷨:const_cast<Ŀ������>(ԭ����/ԭ����)
/*
�ò����������޸����͵�const����
(1)����ָ�뱻ת���ɷǳ���ָ�룬������ָ��ԭ���Ķ���(�ɷ���)
(2)�������ñ�ת���ɷǳ������ã�������ָ��ԭ���Ķ���(�ɷ���)
ע��:���ܶԷ�ָ��ͷ����õı���ֱ��ʹ��const_cast��������ֱ���Ƴ�����const
*/

//#include<iostream>
//using namespace std;
//int main()
//{   
//    //ָ��
//    const int* p = NULL;
//    int* pp = const_cast<int*>(p);
//    const int* ppp = const_cast<const int*>(pp);
//    //����
//    int num = 10;
//    int& numref = num;
//    const int& ff = const_cast<const int&>(numref);
//    int& fff = const_cast<int&>(ff);
//    return 0;
//}







                                                  //���½���ת��(reinterpret_cast)
/*
�������ȫ��һ��ת�����ƣ����п��ܳ������⡣
��Ҫ���ڽ�һ����������ת��Ϊ��һ���������͡�����:��һ��ָ��ת��Ϊһ�����ͣ�Ҳ���Խ�һ������ת��Ϊһ��ָ��
*/