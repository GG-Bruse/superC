#define _CRT_SECURE_NO_WARNINGS

//��������
/*
���غ������ò��������࣬����󳣱���Ϊ�������󣬼���������Ϊ���ƺ����Ķ���Ҳ����Ϊ�º�����
��ʵ��������()��������ʹ��������������һ�����á�
*/

/*
���������ŵ�:
1.��������ͨ�������幹�캯�������������������ڹ��������ʱ���ᷢ���κ����⡣
2.�������󳬳���ͨ�����ĸ����������������Լ���״̬��
3.����������Խ����������룬���ܺã��ú���ָ�뼸��������ʵ�֡�
4.ģ�庯������ʹ�ú����������ͨ���ԡ�
*/

//����1
//#include<iostream>
//using namespace std;
//class MyPrint
//{
//public:
//    void operator()(int num)
//    {
//        cout << num << endl;
//        m_count++;
//    }
//    int m_count = 0;
//};
//int main()
//{
//    MyPrint print;
//    print(100);
//    print(100);
//    print(100);
//    print(100);
//    //�����������ӵ���Լ���״̬����Ϊ�䱾��Ϊһ�������
//    cout << "���ô���Ϊ:" << print.m_count << endl;
//    return 0;
//}




//����2:����������Ϊ��������
//#include<iostream>
//using namespace std;
//class MyPrint
//{
//public:
//    void operator()(int num)
//    {
//        cout << num << endl;
//    }
//};
//void doprint(MyPrint print,int num)
//{
//    print(num);
//}
//void test()
//{
//    doprint(MyPrint(), 1000);
//}
//int main()
//{
//    test();
//    return 0;
//}




















                                                                //ν��
/*
ν����ָ��ͨ�������߷���ֵ��bool���͵ĺ�������(�º���)��
��operator()����һ������������һԪν�ʣ�����������Ϊ��Ԫν�ʡ�ν�ʿ���Ϊ�ж�ʽ��
*/



//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
////һԪν��
//class upperthan20
//{
//public:
//    bool operator()(int a)
//    {
//        return a>20;
//    }
//};
//void test1()
//{
//    vector<int>v;
//    v.push_back(10);
//    v.push_back(20);
//    v.push_back(30);
//    v.push_back(40);
//    v.push_back(50);
//    vector<int>::iterator it = find_if(v.begin(), v.end(), upperthan20());//ͨ���㷨��ʽ������������
//    cout << *it << endl;
//}
////��Ԫν��
//class mycompare
//{
//public:
//    bool operator()(int v1,int v2)
//    {
//        return v1 > v2;
//    }
//};
//void myprintint(int val)
//{
//    cout << val << " ";
//}
//void test2()
//{
//    vector<int>v;
//    v.push_back(10);
//    v.push_back(50);
//    v.push_back(20);
//    v.push_back(40);
//    v.push_back(30);
//    sort(v.begin(), v.end(), mycompare());//�ṩ�º�����ʵ�ִӴ�С������
//    for_each(v.begin(), v.end(), myprintint);//�������ṩ�ص�����
//    cout << endl;
//    //lambda���ʽ(��������)  []����lambda���ʽ��־
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//}
//int main()
//{
//    //test1();
//    test2();
//    return 0;
//}


















                                                           //�ڽ���������
/*
ʹ���ڽ��������������ͷ�ļ�#include<functional>
STL�ڽ���һЩ��������
��Ϊ:�����ຯ�����󡢹�ϵ�����ຯ�������߼������ຯ������
*/



//�����ຯ������
//����negate������Ϊ��Ԫ����
/*
tempslate<class T>plus<T>//�ӷ��º���
template<class T>minus<T>//�����º���
template<class T>multiplies<T>//�˷��º���
template<class T>divdies<T>//�����º���
template<class T>modulus<T>//��ģ�º���
template<class T>negate<T>//ȡ���º���
*/



//��ϵ�����ຯ������:��Ϊ��Ԫ����
/*
tempslate<class T>bool equal_to<T>//����
template<class T>bool not_equal_to<T>//������
template<class T>bool greater<T>//����
template<class T>bool greater_equal<T>//���ڵ���
template<class T>bool less<T>//С��
template<class T>bool less_equal<T>//С�ڵ���
*/



//�߼������ຯ������:notΪһԪ����,����Ϊ��Ԫ����
/*
template<class T>bool logical_or<T>//�߼���
template<class T>bool logical_and<T>//�߼���
template<class T>bool logical_not<T>//�߼���
*/





//����
//#include<iostream>
//#include<functional>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void test1()
//{
//    negate<int>n;
//    cout << n(10) << endl;
//}
//void test2()
//{
//    vector<int>v;
//    v.push_back(40);
//    v.push_back(20);
//    v.push_back(50);
//    v.push_back(10);
//    v.push_back(30);
//    sort(v.begin(), v.end(), greater<int>());
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//}
//int main()
//{
//    //test1();
//    test2();
//    return 0;
//}

















                                                             //������

//��������������
/*
1.����bind2nd��
2.�̳�public binary_function<��������,��������,�º�������ֵ>
3.��const
*/

//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<functional>
//using namespace std;
//class Myprint:public binary_function<int,int,void>
//{
//public:
//    void operator()(int val,int start)const
//    {
//        cout << val+start << " ";
//    }
//};
//void test()
//{
//    int num;
//    cout << "��������ʼֵ:";
//    cin >> num;
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//    }
//    for_each(v.begin(), v.end(), bind2nd(Myprint(),num));//bind2nd��,�ڽ���������
//}
//int main()
//{
//    test();
//    return 0;
//}





//ȡ��������
/*
1.����not1/not 2����ȡ��
2.�̳�public unary_function<��������,�º�������ֵ>
3.��const
*/
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<functional>
//using namespace std;
//class greaterthanfive: public unary_function<int,bool>
//{
//public:
//    bool operator()(int val)const
//    {
//        return val > 5;
//    }
//};
//void test()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//    }
//    vector<int>::iterator it = find_if(v.begin(), v.end(), not1(greaterthanfive()));//һԪȡ��
//    if (it != v.end())
//    {
//        cout << *it << endl;
//    }
//
//    sort(v.begin(), v.end(), not2(less<int>()));//��Ԫȡ��
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//
//}
//int main()
//{
//    test();
//    return 0;
//}





//����������
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<functional>
//using namespace std;
//void myprint(int val ,int start)
//{
//    cout << val+start << " ";
//}
//void test()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//         v.push_back(i);
//    }
//    //����ptr_fun������ָ������ɺ�������
//    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myprint),1000));
//}
//int main()
//{
//    test();
//    return 0;
//}





//��Ա����������
/*
���������ŵ��Ƕ���ָ�룬ʹ��mem_fun
��������ŵ��Ƕ���ʵ�壬ʹ��mem_fun_ref
*/
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<functional>
//using namespace std;
//class Person
//{
//public:
//    Person(string name, int age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    void showPerson()
//    {
//        cout << "����Ϊ:" << this->m_name << endl;
//        cout << "����Ϊ:" << this->m_age << endl;
//    }
//    void addage()
//    {
//        this->m_age += 100;
//    }
//    string m_name;
//    int m_age;
//};
//int main()
//{
//    vector<Person>v;
//    Person p1("Tom", 18);
//    Person p2("Jerry", 1);
//    Person p3("aaa", 3);
//    Person p4("GG_Bond", 18);
//    v.push_back(p1);
//    v.push_back(p2);
//    v.push_back(p3);
//    v.push_back(p4);
//    //����mem_fun_ref��������
//    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
//    for_each(v.begin(), v.end(), mem_fun_ref(&Person::addage));
//    cout << endl;
//    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
//    return 0;
//}































                                                                    //�հ�
/*
�кܶ��ֶ��壬����һ��˵���ǣ��հ��Ǵ��������ĵĺ���������״̬�ĺ�����

�հ��������Լ��ı���, ��Щ��������ֵ�Ǵ����հ���ʱ�����õ�, ���ڵ��ñհ���ʱ��, ���Է�����Щ����.

�����Ǵ���, ״̬��һ��������������һ���������(bind)�����γ��˱հ����ڲ�����static�����ĺ������Ǳհ�,
��Ϊ���static�������������㲻������ͬ�� static ����������ڱ����ʱ���Ѿ�ȷ����.

�հ���״̬����, ���뷢��������ʱ��
*/

/*
�հ�ʵ�ֵ����ַ�ʽ��
1.����operator()(�º���ʵ��)
2.lambda���ʽ
3.bind��function
*/



//�º���
/*
��Ϊ�հ���һ������+һ��״̬, ���״̬ͨ��������thisָ�봫��.���Ահ���Ȼ��һ����������.��Ϊ��Ա�������Ǽ��õ����ڱ���״̬�Ĺ���,
���ʵ��operator()���������, ����Ķ��������Ϊ�հ�ʹ��.Ĭ�ϴ����thisָ���ṩ�˷��ʳ�Ա������;��
*/

//#include<iostream>
//using namespace std;
//class MyFunc
//{
//public:
//    MyFunc(int temp) :m_r(temp) {}
//    int operator()(int num)
//    {
//        return num + m_r;
//    }
//
//private:
//    int m_r;
//};
//int main()
//{
//    MyFunc obj(10);
//    cout << obj(1) << endl;//���÷º��� 11
//    return 0;
//}








                                                         //lambda���ʽ
/*
lambda���ʽ��һ�������������ڴ��������ĺ��������Լ򻯱�̹���

lambda���ʽ��������C++11�б���Ϊ"�հ�����",ÿһ��lambda���ʽ�����һ����ʱ����(��ֵ)������ϸ�����,lambda���ʽ����ֵ���Ǻ���ָ��

C++11ȴ����lambda���ʽ����ָ��ת����ǰ����lambda������û�в����κα���,�Һ���ָ����ʾ�ĺ���ԭ�ͱ����lambda������ͬ�ĵ��÷�ʽ
*/

/*
lambda ���ʽ������ͨ�������б���һ����Χ�ڵı�����
[]�������κα�����

[&]�����ⲿ�����������б���,����Ϊ�����ں�������ʹ��(�����ò���)��

[=]�����ⲿ�����������б���,����Ϊ�����ں�������ʹ��(��ֵ����)��

[=,&foo]��ֵ�����ⲿ�����������б���,�������ò���foo������

[bar]��ֵ����bar����,ͬʱ����������������

[this]����ǰ���е�thisָ��,��lambda���ʽӵ�к͵�ǰ���Ա����ͬ���ķ���Ȩ�ޡ�����Ѿ�ʹ����&����=,
��Ĭ����Ӵ�ѡ�����this��Ŀ���ǿ�����lambda��ʹ�õ�ǰ��ĳ�Ա�����ͳ�Ա������
*/

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    int i_ = 0;
//    void func(int x, int y)
//    {
//        auto x1 = []() { return i_; };                    // error��û�в����ⲿ����
//        auto x2 = [=] (){ return i_ + x + y; };           // OK�����������ⲿ����
//        auto x3 = [&]() { return i_ + x + y; };           // OK�����������ⲿ����
//        auto x4 = [this]() { return i_; };                // OK������thisָ��
//        auto x5 = [this]() { return i_ + x + y; };        // error��û�в���x��y
//        auto x6 = [this, x, y]() { return i_ + x + y; };  // OK������thisָ�롢x��y
//        auto x7 = [this]() { return i_++; };              // OK������thisָ�룬���޸ĳ�Ա��ֵ
//    }
//};
//int main()
//{
//    A a;
//    a.func(10, 1);
//    return 0;
//}


/*
Ĭ������£�lambda�����Դ�const���κ�����ֵ�����޷��޸ġ�
��ϣ��ȥ�޸İ�ֵ������ⲿ����ʱ,��Ҫ��ʽָ��lambda���ʽΪmutable:
*/
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 0;
//    //auto f1 = [=] { return a++; };             // error���޸İ�ֵ������ⲿ����
//    auto f2 = [=]() mutable
//    { 
//        ++a;
//        cout <<"a = "<< a << endl;//ֵ����
//    };// OK��mutable
//    f2();//1
//    cout << "a = " << a << endl;//0
//    return 0;
//}


//lambda����ֵ�뺯��ָ���ת��
//#include<iostream>
//#include<functional>
//using namespace std;
//
//int main()
//{
//    int temp = 1;
//    function<int(int)>f1 = [=](int a) { return a + temp;};
//    cout << f1(100) << endl;//101
//
//
//    function<void(int)>f2 = bind(
//        [](int a) { cout << a << endl; },
//        std::placeholders::_1
//    );
//    f2(10);//11
//
//
//
//    auto f3 = [](int x, int y)->int {return x + y; };
//    cout << f3(1, 1) << endl;//2
//
//    decltype(f3) f4 = f3;
//    cout << f4(2, 2) << endl;//4
//
//    //����һ������ָ��
//    typedef int(*PFUC)(int, int);
//    PFUC p1 = f3;
//    cout << p1(10, 10) << endl;//20
//
//
//    return 0;
//}


//for_each��lambda���ʽ���
//#include<algorithm>
//#include<vector>
//#include<iostream>
//#define TEMP 5
//using namespace std;
//int main()
//{
//    vector<int>v;
//    vector<int>LargeNum;
//    for (int i = 0; i < 10; ++i)
//    {
//        v.push_back(i + 1);
//    }
//    for_each(v.begin(), v.end(),
//        [&](int&n){
//            if (n > TEMP)
//            {
//                LargeNum.push_back(n);
//            }
//        }
//    );
//    for_each(LargeNum.begin(), LargeNum.end(),
//        [&](int& n) {
//            cout << n << " ";
//        }
//    );
//    return 0;
//}






                                                           //std::function��ģ��(����)
/*
��C++��,�ɵ���ʵ����Ҫ����:����������ָ�롢�������á�������ʽת��Ϊ����ָ���Ķ��󣬻���������operator()�Ķ���
*/

/*
C++11��������std::function��ģ��,���Ƕ�C++�����еĿɵ��õ�һ�����Ͱ�ȫ�İ���,ͨ��ָ������ģ�����,
��������ͳһ�ķ�ʽ���������������󡢺���ָ�룬����������ӳ�ִ������
*/

/*
ע��:
1.function������������ʵ�ֺ����ص�
2.���ܱ�����໥��Ȼ����
3.������NULL��nullptr���бȽ�
*/

//#include<iostream>
//#include<functional>
//using namespace std;
//void func()//��ͨ����
//{
//    cout << __func__ << endl;
//}
//class Test//���о�̬����
//{
//public:
//    static int test_func(int a)
//    {
//        cout << __func__ <<"("<<a<<")"<< endl;
//        return a;
//    }
//};
//class MyFunctor//���зº���
//{
//public:
//    int operator()(int a)
//    {
//        cout << __func__ << "(" << a << ")" << endl;
//        return a;
//    }
//};
//int main()
//{
//    function<void()>f1 = func;
//    f1();//�ȼ���func();
//
//    function<int(int)>f2 = Test::test_func;
//    f2(10);//�ȼ���Test::tets_func(10);
//
//    //�����еķº������󶨶���
//    MyFunctor obj;
//    function<int(int)> f3 = obj;
//    f3(20);
//
//    return 0;
//}











                                                                  //std::bind
/*
std::bind����Ԥ�Ȱ�ָ���ɵ���ʵ���ĳЩ�����󶨵����еı���������һ���µĿɵ��õ�ʵ�塣

std::bind,��󶨵Ĳ��������������ƣ��󶨵ľ�����Щ����Ҳ�������ƣ���Ϊ���������ϵİ󶨡�
*/

//#include<iostream>
//#include<functional>
//using namespace std;
//void func(int x, int y)
//{
//    cout << x << " " << y <<endl;
//}
//int main()
//{
//    bind(func, 11, 22)();
//
//    //ռλ��
//    //std::placeholders::_1 ��������ʱ������һ�������滻
//    //std::placeholders::_2 ��������ʱ�����ڶ��������滻
//
//    bind(func, placeholders::_1, placeholders::_2)(11,22);
//
//    return 0;
//}






                                                           //bind��function���
//#include<iostream>
//#include<functional>
//using namespace std;
//class Test
//{
//public:
//    void func(int x ,int y)
//    {
//        cout << x << " " << y << endl;
//    }
//    int m_a;
//};
//int main()
//{
//    Test obj;
//
//    //�󶨳�Ա����
//    function<void(int, int)>f1 = bind(&Test::func, &obj, std::placeholders::_1, std::placeholders::_2);
//    f1(10, 20);
//
//    //�󶨳�Ա����
//    function<int& ()>f2 = bind(&Test::m_a, &obj);
//    f2() = 111;
//    cout << obj.m_a << endl;
//
//    return 0;
//}





















