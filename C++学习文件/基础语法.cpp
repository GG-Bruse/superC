#define _CRT_SECURE_NO_WARNINGS

//��ʶC++

//���������������:
//��װ���̳С���̬

//#include<iostream>//������׼���������
//using namespace std;//�����ռ� 
////��ͷ�ļ�����һ��ϸ�֣��Ż����룬�ò����Ͳ�����
//int main()
//{
//	//c out(���)��c in(����)
//	cout << "bjy is the best handsome.\n" << "hello world!\n";
//	cout << 3.14 << 'A' << "abcd" << 10;//����:�Զ�������������
//	return 0;
//}


////#include<stdlib.h>
//#include<cstdlib>//C++���
//using namespace std;
//int main()
//{
//    //char str[20] = "tasklist &pause";
//    char str[20]{ "tasklist &pause" };//C++���
//    system(str);
//    return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//    char ch;
//    double db;
//    int num;
//    cin >> num>>db >> ch;
//    cout << num << db << ch << endl;//endl����������
//    //cin cout ����ѭ����
//    return 0;
//}














                                                       //˫ð�������������
//::���������� 
/*
��ǰ��ʲô������ӣ������ȫ��������
��ǰ�������ݣ���������ݵ�������
*/
//#include<iostream>
//using namespace std;
//int atk = 1000;
//void test()
//{
//    int atk = 2000;
//    cout << "atk=" << atk << endl;//2000
//    cout << "ȫ��atk=" << ::atk << endl;//1000
//}
//int main()
//{
//    test();
//    return 0;
//}















                                                       //namespace�����ռ�
//1.������Ƴ�ͻ
//#include<iostream>
//using namespace std;
//namespace kingglory
//{
//    void goatk();
//}
//namespace LOL
//{
//    void goatk();
//}
//void kingglory::goatk()
//{
//    cout << "������ҫ����ʵ��" << endl;
//}
//void LOL::goatk()
//{
//    cout << "LOL����ʵ��" << endl;
//}
//int main()
//{
//    kingglory::goatk();//������ҫ����ʵ��
//    LOL::goatk();//LOL����ʵ��
//    return 0;
//}



//2.�����ռ���Դ�ű������������ṹ�塢�������
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int a;
//    void func();
//    struct S {};
//    class animal{};
//}
//int main()
//{
//    return 0;
//}



//3.�����ռ����������ȫ����������


//4.�����ռ����Ƕ��
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int a = 10;
//    namespace B
//    {
//        int a = 20;
//    }
//}
//int main()
//{
//    cout << "A�ռ��µ�a=" << A::a << endl;
//    cout << "B�ռ��µ�a=" << A::B::a << endl;
//    return 0;
//}



//5.�����ռ��ǿ��ŵģ�������ʱ����³�Ա
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int a = 100;
//}
//namespace A
//{
//    int b = 100;
//}
////���������ռ���кϲ�
//int main()
//{
//    cout << "A�ռ��µ�a=" << A::a << endl;
//    cout << "A�ռ��µ�b=" << A::b << endl;
//    return 0;
//}



//6.�����ռ������������
//#include<iostream>
//using namespace std;
//namespace
////�������ռ�Ϊ������,���б���Ĭ��Ϊ��̬����,�൱��static int a =1;static int b=2;
//{
//    int a = 1;
//    int b = 2;
//}
//int main()
//{
//    cout << a << endl;
//    cout << ::b << endl;
//    return 0;
//}



//7.�����ռ�����ж������
//#include<iostream>
//using namespace std;
//namespace verylong
//{
//    int a = 10;
//}
//int main()
//{
//    namespace veryshort = verylong;
//    cout << verylong::a << endl;
//    cout << veryshort::a << endl;
//    return 0;
//}
















                                                           //using

//using����
//�����������ռ䲻������ֲ�������ͬ���ֵı���
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int suwukongID = 1;
//}
//int main()
//{
//    //using����
//    using A::suwukongID;//������Ҫʹ�ÿռ�A��suwukongID����
//    cout << suwukongID << endl;
//    return 0;
//}



//using����ָ��
//#include<iostream>
//using namespace std;
//namespace A
//{
//    int suwukongID = 1;
//}
//void test()
//{
//    int suwukongID = 2;
//    using namespace A;//�൱�ڴ������ռ�A
//    cout << A::suwukongID << endl;//1
//    cout << suwukongID << endl;//2 ��û�о���ָ�����ֲ�����������usingָ��
//}
//int main()
//{
//    test();
//    return 0;
//}



//�����
//#include<iostream>
//#include<type_traits>
//using namespace std;
//using m_int = int;
//int main()
//{
//    //�ж�2�������Ƿ�һ�£����Ƿ����棬����Ϊ��
//    cout << is_same<int, m_int>::value << endl;//ģ��
//    return 0;
//}
















                                                     //C++��C���Ե���չ����ǿ
//1.ȫ�ֱ����ļ����ǿ


//2.�����ļ����ǿ(�������͡�����ֵ���βΡ�ʵ�ε�)


//3.����ת�������ǿ


//4.struct��ǿ
/*
C�����еĽṹ�岻�����к�������C++�еĽṹ���п����к���
C�����д����ṹ�����ʱ������ӹؼ���struct;��C++�п��Լ򻯹ؼ���struct
*/


//5.bool���͵���չ
/*
C�����в�����bool���ͣ���C++�д���
bool���� true������(1) false������(0) ��СΪ1���ֽ�
*/
//#include<iostream>
//using namespace std;
//int main()
//{
//    bool flag1 = true;
//    bool flag2 = 100;
//    cout << flag1 << endl;//1
//    cout << flag2 << endl;//�����з�0������ת��Ϊ1
//    cout << sizeof(bool) << endl;
//    return 0;
//}


//6.��Ŀ���������ǿ
//C�����е���Ŀ��������ص���ֵ����C++�з��ص��Ǳ���
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 10;
//    int b = 20;
//    cout << (a > b ? a : b) << endl;//20
//    a > b ? a : b = 100;//C�����в������������
//    cout << a << endl;//10
//    cout << b << endl;//100
//    return 0;
//}


//7.const��ǿ
/*
const���εı���������ֱ���޸�
(1)C�����У�const���ε�ȫ�ֱ���������ͨ��ָ���޸ģ����ܵ��������ı�����
  const���εľֲ���������ͨ��ָ���޸ģ��������ջ�ϣ�Ϊ���г����Եı�����
(2)C++�У�const���ε�ȫ�ֱ���������ͨ��ָ���޸ģ����ܵ��������ı�����
   const���ξֲ�����������ͨ��ָ���޸ģ��൱�ڳ����������ɽ�������ĳ�ʼ����
*/
/*
ֻҪ�Ա�������������ڴ���䣬�Ϳ���ͨ��ָ���ҵ����޸�
(1)��const���εı���ȡ��ַ���´�����ݲ�Ϊ���ݷ�����ʱ�ڴ棬������ָ���޷��޸ġ�
(2)ʹ����ͨ������const���εı������г�ʼ��������ʹ��ָ������޸ġ�
(3)����const�����Զ����������ͱ���������ʹ��ָ������޸ġ�
*/
/*
C�����У�const���ε�ȫ�ֱ���Ĭ�����ⲿ�������ԣ�����(extern)�����ʹ�á�
C++�У�const���ε�ȫ�ֱ���Ĭ�����ڲ��������ԣ������ڱ���ǰ����extern�����������
*/













//����
//���õı�����C++�ڲ�ʵ����һ��ָ��

//���õ�Ŀ��:�����(a��b����ͬһ���ڴ�)   
//���ñ����ʼ����ֵ��һ����ʼ����Ͳ���ָ�����ڴ�
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 10;
//    int& b = a;
//    b = 100;
//    cout << "a = " << b << endl;
//    return 0;
//}


//�����齨������
//#include<iostream>
//using namespace std;
//int main()
//{
//    int arr[10] = { 0 };
//    int(&brr)[10] = arr;
//    int i;
//    for (i = 0; i < 10; i++)
//    {
//        arr[i] = i;
//    }
//    for (i = 0; i < 10; i++)
//    {
//        cout << brr[i] << " ";
//    }
//    return 0;
//}

/*
���õ�ע������:
1.���õı�����һ��Ϸ����ڴ�ռ䡣
2.��Ҫ���ؾֲ�����ʱ����������(�ڴ�ռ�ᱻ�ͷ�)
3.���������ص������ã���ô�����ĵ��ÿ�����Ϊ��ֵ
*/



//ָ�������
//��Ҫʹ�ø߼�ָ�룬����ֱ��ʹ��ͬ��ָ������ý��д��棬�Ӷ���ָ����÷�
//#include<iostream>
//using namespace std;
//struct Person
//{
//    int age;
//};
//void test(Person* &pp)
//{
//    pp = (Person*)malloc(sizeof(Person));
//    if (pp != NULL)
//    {
//        pp->age = 18;
//    }
//}
//int main()
//{
//    Person* p = NULL;
//    test(p);
//    cout << p->age << endl;
//    free(p);
//    p = NULL;
//    return 0;
//}



//����������
//#include<iostream>
//using namespace std;
//int main()
//{
//    //int& ref = 10;
//    //������,���õı�����һ��Ϸ����ڴ�ռ�
//    const int& ref = 10;
//    //����const���൱��int temp=10;const int& ref=temp;(����ͨ��ָ���޸�)
//    return 0;
//}

//#include<iostream>
//using namespace std;
//void test(const int& as)//�����βΣ���ֹ������������±�����ֵ���޸�
//{
//    cout << as << endl;
//}
//int main()
//{
//    int a = 10;
//    test(a);
//    return 0;
//}












                                                       //�����Ĵ��ݷ�ʽ

//1.ֵ����(���ı�ԭʼֵ)
//#include<iostream>
//using namespace std;
//void Swap(int a,int b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    Swap(a, b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    return 0;
//}


//ַ����
//#include<iostream>
//using namespace std;
//void Swap(int* pa, int* pb)
//{
//    int temp = *pa;
//    *pa = *pb;
//    *pb = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    Swap(&a, &b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    return 0;
//}


//���ô���
//#include<iostream>
//using namespace std;
//void Swap(int& a,int& b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    Swap(a, b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    return 0;
//}

















                                                         //��������(inline)
/*
�������������ϻ���һ�������ĺ������������ͨ������������Ϊ��

������������ͨ�������������ڣ�
����������������������������ʱ�����Ὣ��������ɺ������õ�ָ�����ֱ�ӽ�����������Ĵ�����˵�����䴦��
���������������ڵ��ô�����д��һ��һ����
�����������������������һ����������������ظ�ʹ��һ�δ��룬������Ҫ����ִ�к������õĶ��⿪����
ʹ������������ʹ���տ�ִ�г����������ӡ���ʱ�任ȡ�ռ䣬�����ӿռ���������ʡʱ��

�ŵ�:����˺��ȱ�ݣ�ͬʱ���к�����ƣ��Կռ任ʱ��


ע��:
1.�������������������һ�𣬷�����������Ὣ����Ϊ��ͨ�����Դ�
2.Ϊ��������������ͨ���������һ��inline�ؼ��֣��������ڲ�������������ʱ���Ǳ���ģ��κ������ڲ�����ĺ���Ĭ��Ϊ��������
3.C++����������һЩ���ƣ�ĳЩ����±��������ܿ��ǲ��Ὣ����������������:
    (1)���ܴ����κ���ʽ��ѭ�����
    (2)���ܴ��ڹ���������ж����
    (3)�����岻�ܹ����Ӵ�(û����ȷ��׼)
    (4)���ܶԺ�������ȡַ����
4.���������Ǹ���������һ�����飬��������һ������ܡ�����û�н���������Ϊ����������������Ҳ���ܽ��ú���������������
*/



//ʹ�÷�������ͨ����������ͬ
//#include<iostream>
//#include<string>
//using namespace std;
//inline int func(int,int);//����
//inline int func(int a,int b)//����
//{
//    return a + b;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    int ret = func(a, b);
//    cout << ret << endl;
//    return 0;
//}












                                                      //������Ĭ�ϲ�����ռλ����

//Ĭ�ϲ���(���β��и�ֵ)
//�����������Ͷ���������ֻ��һ���ṩĬ�ϲ���
//#include<iostream>
//using namespace std;
//int fun(int a = 10, int b = 10)
//{
//    return a + b;
//}
//int main()
//{
//    cout << fun() << endl;//20
//    cout << fun(20,10) << endl;//30(һ�����Σ��Ͳ�ȡ��Ĭ�ϲ���)
//    return 0;
//}



//ռλ����(ֻдһ�����ͽ���ռλ������ʱ���봫��ռλֵ)
//ռλ����Ҳ������Ĭ��ֵ
//#include<iostream>
//using namespace std;
//void fun(int a,int)
//{}
//int main()
//{
//    fun(10,20);
//    return 0;
//}

















                                                             //��������
/*
�ڴ�ͳC�����У������в��������ͬ���ĺ���������C++�п��Գ���ͬ���������������󱻳�Ϊ�������ء�
�������ص�����:
(1)ͬһ�������²���������ͬ(����û��Ҫ����)
(2)����������ͬ
(3)�������Ͳ�ͬ
(4)����˳��ͬ
*/
/*
ע������:
1.�����ķ���ֵ������Ϊ��������
2.��const�Ͳ���const������Ҳ������Ϊ��������
3.������������Ĭ�ϲ���ʱҪ���������
*/

//#include<iostream>
//using namespace std;
//void A()
//{
//    cout << "����A()����" << endl;
//}
//void A(int a)
//{
//    cout << "����A(int a)����" << endl;
//}
//int main()
//{
//    A(1);//����A(int a)����
//    A();//����A()����
//    return 0;
//}

//#include<iostream>
//using namespace std;
//void A(int& a)
//{
//    cout << "����A(int& a)����" << endl;
//}
//void A(const int& a)
//{
//    cout << "����A(const int& a)����" << endl;
//}
//int main()
//{
//    int a = 10;
//    A(a);//����A(int& a)����
//    A(1);//����A(const int& a)����
//    return 0;
//}
















                                                        //extern "C"
/*
��C++�д��ں������أ������κ����������������������C�����ļ��У�C++�ļ��е�main�����޷����ã���������ʧ�ܡ�

���:
(1)��main�ļ���:
extern "C" void show();//���߱�������show����ʹ��C���Եķ�ʽ����

(2)��ͷ�ļ���:
#ifdef __cplusplus
extern "C" {
#enddef
��������
��������
#ifdef __cplusplus
}
#endif
*/
















//auto C++11
/*
��C�У�auto���ξֲ��������ֲ�����Ҳ��auto����(�Զ�����)

��c++11�У�auto�����û���ʼ�������Զ��Ƶ�����
*/

/*
ע��:
1.�������ʱ�����ʼ��,autoͨ����ʼ����ֵ���������Ƶ�
2.���ֱ�������֧�ֺ����β�Ϊauto����(vs��֧�֣�Qt֧��)
3.auto����������Ϊ�Զ������͵ĳ�Ա����,��ʹ��ʼ��Ҳ����
4.���ɴ���auto���͵�����
5.ģ��ʵ�������Ͳ�����auto����
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//double test()
//{
//    return 1.1;
//}
//struct Person
//{
//    int age;
//};
//class Student
//{
//public:
//    Student(const char* name ,int age)
//    {
//        this->m_name = (char*)name;
//        this->m_age = age;
//    }
//    char* m_name;
//    int m_age;
//};
//void func(vector<int>& temp)
//{
//    for (auto i = temp.begin(); i != temp.end(); ++i);//����i������Ϊvector<int>::iterator������
//}
//int main()
//{
//    auto a = 1;//����a������Ϊint
//
//    auto b = test();//����b������Ϊdouble
//
//    Person p1 = {0};
//    auto p2 = p1;//p2������ΪPerson
//
//    Student s("bjy",18);
//    auto sb = s;//����sb����ΪStudent
//
//    vector<int>v;
//    func(v);
//
//    return 0;
//}















                                                            //decltype
//��ȡ����������

/*
 auto�������������е��Զ������Ƶ�����,��ĳЩ���������auto�������ǳ�������,����ѹ���޷�ʹ��,���� decltype �ؼ���Ҳ�����뵽 C++11 �С�
 auto��decltype�ؼ��ֶ������Զ��Ƶ�������������,�����ǵ��÷����������:auto varname = value;
 decltype(exp)varname = value; ���У�varname ��ʾ��������value ��ʾ����������ֵ��exp ��ʾһ�����ʽ.
*/

//#include<iostream>
//#include<typeinfo>
//using namespace std;
//int main()
//{
//    int i;
//    decltype(i)j = 0;//����i�����Ͷ���һ������j
//    cout << typeid(j).name() << endl;
//
//    float a = 2;
//    double b = 1;
//    decltype(a + b)c = 1.2;//cΪdouble����
//    cout << c << endl;
//
//    enum {A,B,C}flag;//������ö�ٱ���
//    decltype(flag)flag2;//ͨ�������Ƶ������Զ���������������ͬ���͵ı���
//
//    return 0;
//}















                                                            //׷�ٷ�������
//�������ͺ���:�ں������Ͳ����б����ָ����������

//#include<iostream>
//using namespace std;
//int func1(int a, double b)
//{
//    return a + b;
//}
//auto func2(int a, double b)->int//ָ���ض��ķ�������
//{
//    return a + b;
//}
//auto func3(int a, double b)->decltype(a+b)//���ݷ��ص������Զ�ʶ�𷵻�����
//{
//    return a + b;
//}
//
//template<class T1, class T2>
//auto mul(T1& t1, T2& t2)->decltype(t1*t2)
//{
//    return t1 * t2;
//}
//
//int main()
//{
//    auto a = func3(10, 11.1);
//    cout << a << endl;
//
//    auto i = 10;
//    auto j = 11.2;
//    auto ret = mul(i, j);
//    cout << ret << endl;
//
//    return 0;
//}



















                                                             //��ͨ�������б��ʼ��

//#include<iostream>
//using namespace std;
//int main()
//{
//    int a{ 1 };
//    cout << a << endl;
//
//    int arr[]{ 1,2,3,4,5,6 };
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//    {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}

//��ͨ��ʹ���б��ʼ����ֹ������խ��ɾ��ȶ�ʧ(���ֱ���������)
//������:
//#include<iostream>
//using namespace std;
//int main()
//{
//    int c = 1024;
//    char d = {c};//���벻��   �ӡ�int��ת������char����Ҫ����ת��
//    cout << "d = " << d << endl;
//    return 0;
//}




















                                                          //���ڷ�Χ��forѭ��
//��Χ�����ǿ�ȷ����
/*
����:
�β�������һ�����飬ʵ���Ͻ������ַ�����β�ʵ��Ϊһ��ָ��������޷�ͨ����ָ�����ȷ��Ԫ�ظ���(����Χ)
void func(int arr[])
{
    for (int tmp : arr)//�˻��ڷ�Χ�ġ�for�������Ҫ�ʺϵ� "begin" ��������δ�ҵ�

    {
        cout << tmp << endl;
    }
}
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//    int arr[]{ 1,2,3,4,5,6,7,8,9,10 };
//
//    //��ͳд��
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//
//    //���ڷ�Χ��д��
//    for (int temp : arr)
//    {
//        cout << temp << " ";
//    }
//    cout << endl;
//    //������:
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//    {
//        int temp = arr[i];
//        cout << temp << " ";
//    }
//    cout << endl;
//
//    return 0;
//}















                                                               //��̬����
/*
static_assert(�������ʽ����ʾ�ַ���)
����һ�������������ʽ��ֵΪ��(true���߷���ֵ)����ôstatic_assert�����κ����飬������������һ����
��������һ��������󣬴���λ�þ��Ǹ�static_assert��������У�������ʾ���ǵڶ���������ʾ�ַ�����


˵��:
ʹ��static_assert�����ǿ����ڱ����ڼ䷢�ָ���Ĵ����ñ�������ǿ�Ʊ�֤һЩ��Լ�����������Ǹ��Ʊ�����Ϣ�Ŀɶ��ԣ�����������ģ���ʱ��
static_assert��������ȫ���������У������ռ��У����������У������������У��������Բ������Ƶ�ʹ�á�

������������һ��static_assert���ʱ��ͨ�����̽����һ��������Ϊ�������ʽ�������㣬
������ó������ʽ������ĳЩģ����������ӳٵ�ģ��ʵ����ʱ�ٽ������㣬����ü��ģ�������Ϊ�˿��ܡ�

���ܷ��棬������static_assert�����ڼ���ԣ�������Ŀ����룬���static_assert��������κ�������������ʧ��
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//    static_assert(sizeof(void*) != 4, "��֧��32λϵͳ");//�޷�����,����Ĭ��Ϊx86Ϊ32λ,sizeof(void*) = 4
//    return 0;
//}















                                                            //nullptr
/*
�����C++��NULL�Ķ����Ե����⣬#define NULL ((void*)0),#define NULL 0.
nullptr��nullptr_t ���͵���ֵ����,ר���ڳ�ʼ��������ָ��.nullptr_t��C++11�����ӵ��������Ϳɳ�Ϊ��ָ���ֵ���͡�
*/

//#include <iostream>
//using namespace std;
//
//void isnull(void* c) 
//{
//    cout << "void* c" << endl;
//}
//void isnull(int n) 
//{
//    cout << "int n" << endl;
//}
//int main() 
//{
//    isnull(NULL);//int n
//    isnull(nullptr);//void* c
//
//    //nullptrֻ�ܸ�ָ�븳ֵ�����ܸ�һ�����ͱ�����ֵ
//    int* p1 = NULL;
//    int* p2 = nullptr;
//    if (p1 == p2)
//    {
//        cout << "equal" << endl;//ִ��
//    }
//
//    return 0;
//}
















                                                            //ǿ����ö��
/*
��:
enum class Status01{Ok,Error};
enum struct Status02{Ok,Error};
enum class Status03:char {Ok,Error};
*/
/*
�ص�:
(1)ǿ������,ǿ����ö�ٳ�Ա�����Ʋ��ᱻ������丸������,���Բ�ͬö�����Ͷ���ͬ��ö�ٳ�Ա���벻�ᱨ�ض������.
����ʹ��ö�����͵�ö�ٳ�Աʱ,����ָ��������,����Enum::VAL1,��������VAL1���پ�������:
(2)ת�����ƣ�ǿ����ö�ٳ�Ա��ֵ�����������ͷ�����ʽ�໥ת����
(3)����ָ����Ա����������
(4)����ʹ��ö�ٳ�Ա����ѡ��������ǿ����ö���޷�����
*/

//#include<iostream>
//using namespace std;
//int main()
//{
//    enum class Status01: long long {Ok,Error};
//    cout << sizeof(Status01::Ok) << endl;
//
//    enum struct Status02 : long long { Ok, Error };
//    cout << sizeof(Status02::Ok) << endl;
//    return 0;
//}
















                                                        //�������ʽconstexpr
/*
����һЩ����ֻ�ڱ���ʱ����һ��,������ÿ�γ�������ʱ,���������Խ��г߶ȸ�����Ż���
*/



//constexpr������ͨ����
/*
ʹ�� constexpr �޸���ͨ����ʱ���������뾭����ʼ���ҳ�ʼֵ������һ���������ʽ
*/

//#include <iostream>
//using namespace std;
//int main()
//{
//    constexpr int num = 1 + 2 + 3;
//    int url[num] = { 1,2,3,4,5,6 };
//    cout << url[1] << endl;
//    return 0;
//}




//constexpr���κ���
/*
����:
1.�������ʽ���������з���ֵ(��������void����)
2.�������ʽ��������ֻ����һ�����,�Ҹ���������return��䡣
��������ʵ�ʴ�����������ڳ������ʽ������ʹ��,��static_assert,using,typedef��
3.return�����,����ʹ�÷ǳ������ʽ�ı���������,��return�ı��ʽҲҪ�ǳ������ʽ
4.�������ʽ������ʹ��ǰ�������ж���.  (��ͨ�����ڱ�����ǰֻҪ�к��������͹��ˣ���һ���ж���)
*/

//#include<iostream>
//using namespace std;
//int getNum01()
//{
//    return 1;
//}
//const int getNum02()
//{
//    return 2;
//}
//constexpr int getNum03()
//{
//    return 3;
//}
//int main()
//{
//    //ö�ٳ�Ա��ʼ�����������ͳ���
//    
//    //error
//    /*enum {a1 = getNum01(),a2};
//    enum { b1 = getNum02(), b2 };*/
//
//    //ok
//    enum {c1 = getNum03(),c2 };
//
//    return 0;
//}




//constexpr������Ĺ��캯��
/*
1.constexpr������Ĺ��캯��ʱ,Ҫ��ù��캯���ĺ��������Ϊ��,�Ҳ��ó�ʼ���б�ķ�ʽΪ������Ա��ֵʱ,����ʹ�ó������ʽ
2.C++11 ��׼��,��֧����constexpr���δ���virtual�ĳ�Ա����
*/

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//    //���캯�������Ϊ�գ�����ʹ�ó�ʼ���б�ķ�ʽ���г�ʼ��
//    constexpr Date(int year, int month, int day) :m_year(year), m_month(month), m_day(day) {}
//
//    constexpr int getYear()const
//    {
//        return m_year;
//    }
//    constexpr int getMonth()const
//    {
//        return m_month;
//    }
//    constexpr int getDay()const
//    {
//        return m_day;
//    }
//private:
//    int m_year;
//    int m_month;
//    int m_day;
//};
//int main()
//{
//    constexpr Date obj{ 2022, 3, 8 };//����ʹ�ó�����ʼ��
//    cout << obj.getYear() << endl;
//    return 0;
//}




//constexpr����ģ�庯��
/*
constexpr��������ģ�庯��,������ģ�������͵Ĳ�ȷ����,���ģ�庯��ʵ������ĺ����Ƿ���ϳ������ʽ������Ҫ��Ҳ�ǲ�ȷ����.
��constexpr���ε�ģ�庯��ʵ������������㳣�����ʽ������Ҫ��,��constexpr�ᱻ�Զ�����,���ú����͵�ͬ��һ����ͨ����.
*/

//#include <iostream>
//using namespace std;
//struct myType {
//    const char* name;
//    int age;
//};
//template<typename T>
//constexpr T dispaly(T t) {
//    return t;
//}
//
//int main()
//{
//    struct myType stu { "zhangsan", 10 };
//    //��ͨ����
//    struct myType ret = dispaly(stu);
//    cout << ret.name << " " << ret.age << endl;
//    //�������ʽ����
//    constexpr int ret1 = dispaly(10);
//    cout << ret1 << endl;
//    return 0;
//}


















                                                           //�Զ����������˵��

/*
C++11���������û��Զ�����������Ҳ���Զ����׺����������ͨ��ʵ��һ����׺���������������˸ú�׺��ʶ��������ת��Ϊ��Ҫ�����͡�
�������ķ���ֵ��û�б��ϸ��޶��������ṩ�������͵ķ���ֵ

���²����б�źϷ�:
char const*
unsigned long long
long double
char const* , size_t
wchar_t const *, size_t
char16_t const *, size_t
char32_t const *, size_t
����ĸ������ַ����൱���ã���Ϊ�ڶ����������Զ��ƶ�Ϊ�ַ����ĳ���
*/

//#include<iostream>
//using namespace std;
//unsigned long long operator"" _s(unsigned long long x)
//{
//    return x * 1000;
//}
//
//size_t operator"" _byte(char const* str, size_t len)//�Զ��ƶϳ���
//{
//    return len;
//}
//
//int main()
//{
//    unsigned long long time = 123_s;
//    cout << time << "_ms" << endl;//123000_ms
//
//    cout << "bjy"_byte << endl;//3
//    return 0;
//}











                                                         //ԭ���ַ�������ֵ
/*
ԭ���ַ�������ֵ(raw string literal)ʹ�û���д���ַ��������������á�.
ԭ���ַ����������൱��,ֻ�����ַ���ǰ����ǰ׺,����ĸR,����������ʹ���������ұ�ʶ,�Ϳ����������ַ���������Ϊԭ���ַ�����.
*/

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    cout << R"(hello\nworld)" << endl;//ʹ��ת���ַ�ʧЧ������ΪΪ��ͨ�ַ�
//
//    string str = R"(\n\t)";
//    cout << str << endl;
//    return 0;
//}


















                                                        //����ָ��
/*
����ָ����һ��������ָ��һ�������Ķ���,��unique_ptr(��ռָ��),shared_ptr��weak_ptr������ָ��,������<memory>�У����ԶԶ�̬��Դ���й���
��֤�Թ���Ķ������ջ����٣������������������ջᱻ����
*/
/*
ע��:
1.Ϊ�˱����ڴ�й©,ͨ������ָ�����Ķ���Ӧ��û������������ָ������.
2.����ָ�벻֧��ָ�����������

3.����ʹ������unique_ptr�����ֵ����ʼ��һ��unique_ptr��Ҳ���ܽ�һ��unique_ptr����ֵ������һ����
�����Ĳ���������������ռָ�빲����ͬ���������Ȩ

4.unique_ptr�������ר������Ȩ�������Ҫ��һ��unique_ptr���ڴ潻������һ��unique_ptr�������
ֻ��ʹ��std::moveת�Ƶ�ǰ���������Ȩ��ת��֮�󣬵�ǰ�����ٳ��д��ڴ棬�µĶ��󽫻��ר������Ȩ��

5.��unique_ptrָ�����һ����������Ļ�,Ҫȷ������delete[]������������������,��Ӧ���ڶ������ͺ������һ�Կյķ�����[]��

*/


//һ��unique_ptr
//#include<iostream>
//#include<memory>
//using namespace std;
//int main() 
//{
//    unique_ptr<int> up1(new int(11));
//    cout << "up = " << *up1 << endl;
//
//    //��up1�Ķ�ռȨת�Ƹ�up2��up1�����ٲ��������ռ�
//    unique_ptr<int> up2 = std::move(up1);
//    cout << "up2 = " << *up2 << endl;
//
//    //up2.reset();//��Ϊ�޲���������ʾ�ͷŶ�������
//    up2.reset(new int(22));//��Ϊ�вΣ����ͷ�ԭ����������,���¸�up2��һ���µĶ�������
//    cout << "up2 = " << *up2 << endl;
//
//    //�ͷſ���Ȩ�������ͷŶ����ڴ�
//    int* p = up2.release();
//    cout <<"p = "<< *p << endl;
//    delete p;
//    p = nullptr;
//    return 0;
//}

//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//    //ָ������Ķ�ռָ��
//    unique_ptr<int[] > up(new int[5]);
//    for (int k = 0; k < 5; k++)
//    {
//        up[k] = k+1;
//    }
//    for (int k = 0; k < 5; k++)
//    {
//        cout << up[k] << " ";
//    }
//    cout << endl;
//    return 0;
//}





//����shared_ptr
/*
���shared_ptr����ָ����Թ�ͬʹ��ͬһ����ڴ档���ڸ���������ָ����ʵ���ϲ��õ������ü������ƣ�
������һ��shared_ptrָ������˶��ڴ��"ʹ��Ȩ"(���ü�����1)Ҳ����Ӱ������ָ��ͬһ���ڴ��shared_ptrָ��(ֻ�����ü���Ϊ0ʱ,���ڴ�Żᱻ�Զ��ͷţ�
*/

//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//    shared_ptr<int> sp1(new int(11));
//    shared_ptr<int>sp2(sp1);//��������
//
//    cout << "num = " << sp2.use_count() << endl;//��ӡ������ 2
//
//    sp1.reset();
//    cout << "num = " << sp2.use_count() << endl;//1
//    cout << *sp2 << endl;//11
//
//    sp1.reset();
//    cout << "num = " << sp1.use_count() << endl;//0
//    return 0;
//}




//����weak_ptr
/*
������ָ��ͨ��������ʹ��(û��ʵ���ô�),ֻ�ܺ�shared_ptr����ʹ�á����ǿ��Խ�weak_ptr��Ϊshared_ptrָ���һ�ָ�������,
����weak_ptr����ָ��,���ǿ��Ի�ȡshared_ptrָ���һЩ״̬��Ϣ,�����ж���ָ����ͬ��shared_ptrָ��,shared_ptrָ��ָ��Ķ��ڴ��Ƿ��Ѿ����ͷŵȡ�

��weak_ptr����ָ���ָ���ĳһshared_ptrָ����ͬʱ,weak_ptr������ʹ��ָ���ڴ�����ü�����1
��weak_ptrָ�뱻�ͷ�ʱ,֮ǰ��ָ���ڴ�����ü���Ҳ������˶���1.Ҳ����˵,weak_ptr������Ӱ����ָ���ڴ�ռ�����ü�����

weak_ptr<T>ģ������û������*��->����� , weak_ptr ����ָ��ֻ�ܷ�����ָ�Ķ��ڴ棬���޷��޸���
*/

//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//    shared_ptr<int>sp1(new int(11));
//    shared_ptr<int>sp2(sp1);
//    weak_ptr<int>wp = sp1;
//    cout << wp.use_count() << endl;
//
//    shared_ptr<int>sp3 = wp.lock();
//    //lock() ����ǰweak_ptr�Ѿ�����,��ú����᷵��һ���յ�shared_ptrָ��.��֮,�ú�������һ���͵�ǰweak_ptrָ����ͬ��shared_ptr��
//    cout << wp.use_count() << endl;
//
//    if (sp3 == nullptr)
//    {
//        cout << "�����ռ��Ѿ��ͷ�" << endl;
//    }
//    else
//    {
//        //cout << *wp << endl;//err
//        cout << *sp3 << endl;//��ӷ���
//    }
//    return 0;
//}






















