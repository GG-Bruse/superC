#define _CRT_SECURE_NO_WARNINGS



//�̳�

/*
C++ͨ���̳л��ƿ����������е����������������µ��������ͣ��µ��಻��ӵ�о���ĳ�Ա����ӵ���¶���ĳ�Ա
1.�̳��﷨:
class ������(������): �̳з�ʽ ������(������)
2.�̳е��ŵ�:
�����ظ��Ĵ��룬��ߴ��븴����
3.�������еĳ�Ա���������󲿷�:
(1)һ���Ǵӻ���̳й����ģ�һ�����Լ����ӵĳ�Ա
(2)�ӻ���̳й����ı����乲�ԣ��������ĳ�Ա���������
*/
/*
�̳з�ʽ:
���м̳С������̳С�˽�м̳�
������ֻ���Է��ʻ���Ĺ���Ȩ�޺ͱ���Ȩ���µ����������ɷ���˽��Ȩ���µ�����
�����е�Ĭ�Ϲ��졢�������������졢operator=���ᱻ������̳�
1.���м̳�:���ֻ����Ȩ�޽���̳�
2.�����̳�:���ӻ���ļ̳����������ڱ����ж��޸�Ϊ����Ȩ��
3.˽�м̳�:���ӻ���ļ̳����������ڱ����ж��޸�Ϊ˽��Ȩ��

�Ӽ̳�Դ�Ϸ�:
1.���̳�:
ָÿ��������ֱֻ�Ӽ̳�һ�����������
2.��̳�:
ָ�������������һ��������ļ̳й�ϵ����̳е�������ֱ�Ӽ̳��˲�ֹһ�����������
*/

//#include<iostream>
//using namespace std;
//class Basepage
//{
//public:
//    void header()
//    {
//        cout << "������ͷ��" << endl;
//    }
//    void footer()
//    {
//        cout << "�����ĵײ�" << endl;
//    }
//    void leftlist()
//    {
//        cout << "����������б�" << endl;
//    }
//};
//class News: public Basepage
//{
//public:
//    void content()
//    {
//        cout << "���Ų�������" << endl;
//    }
//};
//class Sport : public Basepage
//{
//public:
//    void content()
//    {
//        cout << "���籭��������" << endl;
//    }
//};
//int main()
//{
//    News n;
//    Sport sp;
//    n.header();
//    n.footer();
//    sp.leftlist();
//    sp.content();
//    return 0;
//}





//�̳��еĶ���ģ��
/*
�ڿ�����Ա������ʾ���鿴����ģ��
1.��ת�̷�D:
2.��ת�ļ�·��:cd �ļ�·��
3.cl /d1 reportSingleClassLayout���� �ļ���
*/

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    int m_a;
//protected:
//    int m_b;
//private:
//    int m_c;//�����е�˽�����ԣ���������ʲ���(������������)�����ᱻ�̳�
//};
//class Son : public Base
//{
//public:
//    int m_d;
//};
//int main()
//{
//    cout << "sizeof Son:" << sizeof(Son) << endl;//16
//    return 0;
//}






//�̳��еĹ��������˳��
/*
1.�ȵ��ø��๹���ڵ������๹�죬�����빹���෴
2.���������������������Ϊ��Ա���ȵ��ø��๹�죬�ٵ��������๹�죬�����������졣�����빹��˳���෴��
3.��������û��Ĭ�Ϲ��캯��:
(1)�ڸ�������ӿ�ʵ�ֵ�Ĭ�Ϲ��캯��
(2)ʹ�ó�ʼ���б�ķ�ʽ���ø����е��������캯��
*/

//1.
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    Base() { cout << "Base���캯������" << endl; }
//    ~Base() { cout << "Base������������" << endl; }
//};
//class Son : public Base
//{
//public:
//    Son() { cout << "Son���캯������" << endl; }
//    ~Son() { cout << "Son������������" << endl; }
//};
//int main()
//{
//    Son s1;
//    return 0;
//}



//2.
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    Base(){cout << "Base���캯������" << endl;}
//    ~Base(){cout << "Base������������" << endl;}
//};
//class Other
//{
//public:
//    Other() { cout << "Other���캯������" << endl; }
//    ~Other() { cout << "Other������������" << endl; }
//};
//class Son: public Base
//{
//public:
//    Son(){cout << "Son���캯������" << endl;}
//    ~Son(){ cout << "Son������������" << endl;}
//    Other o;
//};
//int main()
//{
//    Son s1;
//    return 0;
//}


//3.
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    Base(int a) { cout << "Base�вι��캯������" << endl; }
//};
//class Son : public Base
//{
//public:
//    Son(int a) :Base(a)//�ڸ���û��Ĭ�Ϲ��캯��������¿���ʹ�ó�ʼ���б�ķ�ʽ���ø����е��вι��캯��
//    { 
//        cout << "Son���캯������" << endl; 
//    }
//};
//int main()
//{
//    Son s1(100);
//    return 0;
//}








//�̳��е�ͬ����Ա����
/*
1.����������������ʸ����е�ͬ����Ա
2.�������븸�����ͬ������(�������ض��常���еĺ���)�������Ա���������ص������е��������ذ汾��ͬ����Ա��ֻ�������������������ʽ����
*/
/*
�ض���(����)
1.�м̳�
2.����(������)���¶��常��(����)��ͬ����Ա(��virtual����)
*/
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    int m_a;
//    Base()
//    {
//        this->m_a = 10;
//    }
//    void func(int a)
//    {
//        cout << "Base���вκ�������" << endl;
//    }
//    void func()
//    {
//        cout << "Base�к�������" << endl;
//    }
//};
//class Son: public Base
//{
//public:
//    int m_a;
//    Son()
//    {
//        this->m_a = 20;
//    }
//    void func()
//    {
//        cout << "Son�к�������" << endl;
//    }
//};
//int main()
//{
//    Son s1;
//    //�����еĳ�Ա����
//    cout << s1.m_a << endl;//20 
//    //ͨ�������������ʸ����е�ͬ����Ա
//    cout << s1.Base::m_a << endl;//10
//    s1.func();
//    s1.Base::func(10);//�������������
//    s1.Base::func();
//    return 0;
//}


//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    static void func()
//    {
//        cout << "Base�к�������" << endl;
//    }
//    static int m_a;
//};
//int Base::m_a = 10;
//class Son : public Base
//{
//public:
//    static void func()
//    {
//        cout << "Son�к�������" << endl;
//    }
//    static int m_a;
//};
//int Son::m_a = 20;
//int main()
//{
//    cout << Son::m_a << endl;
//    cout << Son::Base::m_a << endl; //ͨ�������ķ�ʽ���ʸ����������µ�m_a��̬��Ա����
//    Son::func();
//    Son::Base::func();//ͨ�������ķ�ʽ���ʸ����������µ�func��̬��Ա����
//    return 0;
//}









//��̳�(������ʹ��)
//#include<iostream>
//using namespace std;
//class Base1
//{
//public:
//    Base1()
//    {
//        this->m_a = 10;
//    }
//    int m_a;
//};
//class Base2
//{
//public:
//    Base2()
//    {
//        this->m_a = 20;
//    }
//    int m_a;
//};
//class Son: public Base1,public Base2
//{
//public:
//    int m_c;
//};
//int main()
//{
//    Son s;
//    cout << "sizeof Son " << sizeof(Son) << endl;//12
//    //����̳е�������������ͬ����Ա������������������
//    cout << s.Base1::m_a << endl;
//    cout << s.Base2::m_a << endl;
//    return 0;
//}






//���μ̳�����
/*
����������̳���ͬһ�����������ĳ����ͬʱ�̳��������������࣬���ּ̳б���Ϊ���μ̳�(��ʯ�ͼ̳�)
����:(������̳н�����ؼ���virtual)
1.���ݵĶ�����
2.�����ظ�
*/
/*
��������̳к�����������̳���һ��vbptrָ��(�����ָ��)��ָ�����һ��������(vbtable)
�������м�¼��ƫ������ͨ��ƫ���������ҵ�Ψһ������
*/
//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//    int m_age = 10;
//};
////����
//class Sheep :virtual public Animal {};
////����
//class Tuo :virtual public Animal {};
////������
//class SheepTuo : public Sheep, public Tuo {};
//int main()
//{
//    SheepTuo s;
//    cout << "sizeof SheepTuo " << sizeof(SheepTuo) << endl;//12
//    cout << s.m_age << endl;//10
//    return 0;
//}









//�̳й���
/*
ע��:
1.�̳й��캯���Ĺ����ǳ�ʼ�������еĳ�Ա����,�޷���ʼ�����������ݳ�Ա��
2.������Ĺ��캯��������Ϊ˽�У������������Ǵӻ�������̳У���ô����ʹ�ü̳й��캯��
3.һ��ʹ�ü̳й��죬������������Ϊ�������ṩĬ�Ϲ��캯��
4.�����캯��ӵ��Ĭ��ֵ��������������캯���汾���Ҽ̳й��캯���޷��̳л��๹�캯����Ĭ�ϲ���
5.��̳е�����£��̳й��캯������֡���ͻ�����������Ϊ��������еĲ��ֹ��캯�����ܵ����������еļ̳й��캯���ĺ�������������ͬ
*/
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//    Date(int x)
//    {
//        this->m_x = x;
//        this->m_y = 100;
//    }
//    Date(int x, int y)
//    {
//        this->m_x = x;
//        this->m_y = y;
//    }
//protected:
//    int m_x;
//    int m_y;
//};
//class Print :public Date
//{
//public:
//    //�ṩ����вι��캯����ʼ���̳���Date���������
//    /*Print(int x,int y):Date(x,y){}
//    Print(int x) :Date(x) {}*/
//
//    //ʹ�ü̳й���
//    using Date::Date;
//    void print()
//    {
//        cout << "x = " << this->m_x << endl;
//        cout << "y = " << this->m_y << endl;
//    }
//    //��������Ա����
//};
//int main()
//{
//    Print obj{ 10};
//    obj.print();
//    return 0;
//}



//#include<iostream>
//using namespace std;
//class A {
//public:
//    A(int i) { cout << "A(int)����" << endl; }
//};
//class B
//{
//public:
//    B(int i) { cout << "B(int)����" << endl; }
//};
//class C : public A, public B {
//public:
//    using A::A;   //�����̳й��캯�����ᶨ��һ��C(int)
//    using B::B;  //��������ظ�����C(int)
//
//   //��ʾ����̳й��캯��C(int)
//    C(int i) :A(i), B(i)
//    { 
//        cout << "C(int)����" << endl; 
//    }
//};
//int main()
//{
//    C c(10);
//    return 0;
//}
/*
A(int)����
B(int)����
C(int)����
*/







//�̳п��� final��override
/*
����һ����Ľ�һ������
1.final��ֹ��Ľ�һ���������麯���Ľ�һ����д
2.overrideȷ�����������������ĺ����������е��麯������ͬ��ǩ��(�������������������͡�����������˳�򡢷���ֵ)
*/

//1.
//#include<iostream>
//using namespace std;
//class A final//�����޷����̳�
//{
//    int a;
//};
//class B1
//{
//public:
//    virtual void func() final{}//���麯���޷�����д
//};

//2.
//#include<iostream>
//using namespace std;
//class A1
//{
//public:
//    virtual void func(int a)
//    {
//        cout << a << endl;
//    }
//};
//class A2 :public A1
//{
//public:
//    void func(int a)override{}//Ҫ����д�����麯��ǩ��һ��
//};