#define _CRT_SECURE_NO_WARNINGS


//ģ��

//����
/*
C++�ṩ����ģ�����:����ģ�����ģ��
���������Ͳ��������ֳƲ���ģ��
�ܽ�:
1.ģ��Ѻ�������Ҫ������������Ͳ�����������Ϊ���͵Ķ�̬�ԣ���Ϊ����
2.ģ�����ڱ���߼��ṹ��ͬ������������Ԫ�����Ͳ�ͬ�����ݶ����ͨ����Ϊ
*/




//����ģ��

//�����﷨
/*
����ģ��ʵ�����ǽ���һ��ͨ�ú������亯�����ͺ��β����Ͳ�����д������һ�����������������
*/

//#include<iostream>
//using namespace std;
//template<typename T>//T����һ��ͨ�õ��������ͣ��ں�������ŵĺ��������г���T���������ᱨ��
//void mySwap(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    mySwap(a, b);//1.�Զ������Ƶ�(�����Ƶ���һ�µ��������Ͳſ�������ʹ��ģ��)
//    cout << a << endl;//20
//    cout << b << endl;//10
//    double c = 3.14;
//    double d = 0.01;
//    mySwap<double>(c, d);//2.��ʽָ������
//    cout << c << endl;//0.01
//    cout << d << endl;//3.14
//    return 0;
//}




//����ģ��ʵ�ֶ�char��int���͵���������
//#include<iostream>
//using namespace std;
//template<class T>//typename��class��ͬ
//void myswap(T& a,T&b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//template<class T>
//void mySort(T arr[],int len)
//{
//    int i, j, max;
//    for (i = 0; i < len; i++)
//    {
//        max = i;
//        for (j = i + 1; j < len; j++)
//        {
//            if (arr[max] < arr[j])
//            {
//                max = j;
//            }
//        }
//        if (i != max)
//        {
//            myswap(arr[i],arr[max]);
//        }
//    }
//}
//template<class T>
//void Printarr(T arr,int len)
//{
//    int i;
//    for (i = 0; i < len; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}
//int main()
//{
//    char charr[] = "helloworld";
//    mySort(charr,strlen(charr));
//    Printarr(charr, strlen(charr));
//    int arr[] = { 1,2,3,6,5,4,9,8,7 };
//    mySort(arr, sizeof(arr)/sizeof(int));
//    Printarr(arr, sizeof(arr)/sizeof(int));//9 8 7 6 5 4 3 2 1
//    return 0;
//}





//����ģ������ͨ�������𼰵��ù���
/*
����:
�ں���ģ���У����ʹ���Զ������Ƶ����ǲ����Է�����ʽ����ת����(����int��char֮���໥ת��)��
����ͨ�������Է�����ʽ����ת����
*/
/*
����:
1.�ں���ģ�����ͨ���������Ե��õ�����£����ȵ�����ͨ����
2.����ǿ�Ƶ��ú���ģ�壬����ʹ�ÿ�ģ���б�
3.����ģ��Ҳ���Է�����������
4.������ģ����Բ������õ�ƥ�䣬����ʹ�ú���ģ��
*/

//#include<iostream>
//using namespace std;
//template<class T>
//void A(T a,T b)
//{
//    cout << "����ģ�����" << endl;
//}
//template<class T>
//void A(T a, T b,T c)
//{
//    cout << "����ģ��(2)����" << endl;
//}
//void A(int a,int b)
//{
//    cout << "��ͨ��������" << endl;
//}
//int main()
//{
//    int a = 10, b = 1;
//    char c = 'c', d = 'd';
//    A(a,b);
//    A<>(a,b);//��ģ���б�
//    A(a, b, 10);
//    A(c, d);//��������ͨ�����������ʽ����ת������ʱ�뺯��ģ���ƥ��ȸ���
//    return 0;
//}








//ģ����ƺ�ģ�������
/*
����ģ����ƽ���:
1.�����������ǰѺ���ģ�崦����ܹ������κ����͵ĺ���
2.����ģ��ͨ���������Ͳ�����ͬ�ĺ���(ͨ������ģ������ĺ�������Ϊģ�庯��)
3.��������Ժ���ģ��������α��룬�������ĵط���ģ����뱾ʡ���б��룬�ڵ��õĵط��Բ����滻��Ĵ�����б���
*/
/*
ģ��ľ�����:
ģ�岢����������ͨ�ã������Զ�����������ͣ�����ʹ�þ��廯(Ҳ֧�ֲ��־��廯)��ʵ�ֶ��Զ������������ṩ����ģ��
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Person
//{
//public:
//    Person(string name,int age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    string m_name;
//    int m_age;
//};
//template<class T>
//bool mycompare(T& a, T& b)
//{
//    if (a == b)
//    {
//        return true;
//    }
//    return false;
//}
////���þ��廯
//template<>
//bool mycompare(Person& a, Person& b)
//{
//    if (a.m_age == b.m_age && a.m_name == b.m_name)
//    {
//        return true;
//    }
//    return false;
//}
//int main()
//{
//    Person p1("Tom", 18);
//    Person p2("Tom", 18);
//    bool ret = mycompare(p1, p2);
//    if (ret)
//    {
//        cout << "a = b" << endl;
//    }
//    else
//    {
//        cout << "a!=b" << endl;
//    }
//    return 0;
//}







                                                           //��ģ��

//�����﷨
/*
����ģ�����ģ������:
1.��ģ�岻����ʹ���Զ������Ƶ�,ֻ��ʹ����ʽָ������
2.��ģ���п�����Ĭ�ϲ���
*/
//#include<iostream>
//#include<string>
//using namespace std;
//template<class NAMETYPE,class AGETYPE = int>//Ĭ�ϲ���
//class Person
//{
//public:
//    Person(NAMETYPE name,AGETYPE age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    void show()
//    {
//        cout << "����:" << this->m_name << endl;
//        cout << "����:" << this->m_age << endl;
//    }
//    NAMETYPE m_name;
//    AGETYPE m_age;
//};
//int main()
//{
//    Person <string >p1("Tom", 18);
//    p1.show();
//    return 0;
//}





//��ģ���еĵĳ�Ա��������ʱ��
/*
��ģ���еĳ�Ա������������һ��ʼ�����ģ����������н׶�ȷ�������������Ͳ�ȥ������
*/
//#include<iostream>
//using namespace std;
//class Person1
//{
//public:
//    void showPerson1()
//    {
//        cout << "Person1 show ����" << endl;
//    }
//};
//class Person2
//{
//public:
//    void showPerson2()
//    {
//        cout << "Person2 show ����" << endl;
//    }
//};
//template<class T>
//class Myclass
//{
//public:
//    void func1()
//    {
//        obj.showPerson1();
//    }
//    void func2()
//    {
//        obj.showPerson2();
//    }
//    T obj;
//};
//int main()
//{
//    Myclass<Person1>p1;
//    p1.func1();
//    Myclass<Person2>p2;
//    p2.func2();
//    return 0;
//}





//��ģ������������
/*
1.ָ����������
2.����ģ�廯
3.������ģ�廯
*/
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name,T2 age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    void show()
//    {
//        cout << "����:" << this->m_name << endl;
//        cout << "����:" << this->m_age << endl;
//    }
//    T1 m_name;
//    T2 m_age;
//};
//void dowork1(Person<string, int>& p)//ָ����������
//{
//    p.show();
//}
//template<class T1, class T2>
//void dowork2(Person<T1, T2>& p)//����ģ�廯
//{
//    p.show();
//}
//template<class T>
//void dowork3(T& p)//������ģ�廯
//{
//    p.show();
//}
//
//int main()
//{
//    Person<string, int>p1("Tom",999);
//    Person<string, int>p2("Jerry", 1);
//    Person<string, int>p3("GG_Bond", 18);
//    dowork1(p1);
//    dowork2(p2);
//    dowork3(p3);
//    return 0;
//}









//��ģ����̳е����⼰����
/*
����Ҫָ�����������е�T,���ܸ���������ڴ�
1.�Լ�ָ������
2.�û�ָ������
*/

//#include<iostream>
//using namespace std;
//template<class T>
//class Base
//{
//public:
//    T m_a;
//};
////�Լ�(д����)
//class Son1 : public Base<int>{};
////�û�
//template<class T1 ,class T2>
//class Son2 :public Base<T1>
//{
//public:
//    T2 m_b;
//};






//��ģ���еĳ�Ա��������ʵ��
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name, T2 age);
//    void showPerson();
//    T1 m_name;
//    T2 m_age;
//};
//template<class T1, class T2>
//Person<T1,T2>::Person(T1 name, T2 age)
//{
//    this->m_name = name;
//    this->m_age = age;
//}
//template<class T1, class T2>
//void Person<T1,T2>::showPerson()
//{
//    cout << "����:" << this->m_name << endl;
//    cout << "����:" << this->m_age << endl;
//}
//int main()
//{
//    Person<string, int>p("Tom", 99);
//    p.showPerson();
//    return 0;
//}






//��ģ��ķ��ļ���д����
/*
��ʹ����ͨ��������ģ���еĳ�Ա����������һ��ʼ��������˵��·��ļ���д���Ӳ�������ʵ�֣������޷��������ⲿ�������
���:
1.ֱ�Ӱ�������ʵ�ֵ�.cppԴ�ļ�(���Ƽ�)
2.�����������ʵ��д��ͬһ�ļ��У����ļ��ĺ�׺����Ϊ.hpp
*/








//��ģ������Ԫ�����⼰����
//#include<iostream>
//#include<string>
//using namespace std;
//
////2.��ǰ����
//template<class T1, class T2>
//class Person;
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p);
//
////3. ����
//template<class T1, class T2>
//void printPerson3(Person<T1, T2>& p)
//{
//    cout << "����ʵ������:" << p.m_name << endl;
//    cout << "����ʵ������:" << p.m_age << endl;
//}
//
//template<class T1, class T2>
//class Person
//{
//public:
//    //1.��Ԫ��������ʵ��
//    friend void printPerson1(Person<T1, T2>& p)
//    {
//        cout << "����:" << p.m_name << endl;
//        cout << "����:" << p.m_age << endl;
//    }
//
//    //2.��Ԫ��������ʵ��(1)
//    friend void printPerson2<>(Person<T1, T2>& p);
//
//    //3..��Ԫ��������ʵ��(2)
//    friend void printPerson3<>(Person<T1, T2>& p);
//
//    Person(T1 name,T2 age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//private:
//    T1 m_name;
//    T2 m_age;
//};
//
////2.ʵ��
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p)
//{
//    cout << "����ʵ������:" << p.m_name << endl;
//    cout << "����ʵ������:" << p.m_age << endl;
//}
//
//int main()
//{
//    Person<string, int>p1("Tom", 99);
//    Person<string, int>p2("Jerry", 1);
//    printPerson1(p1);
//    printPerson2(p2);
//    printPerson3(p1);
//    return 0;
//}









//��ģ�尸��:��������
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T>
//class myArray
//{
//public:
//    myArray(int num)
//    {
//        this->m_num = num;
//        this->m_size = 0;
//        this->pAddress = new T[m_num];
//    }
//    myArray(const myArray& arr)
//    {
//        this->m_num = arr.m_num;
//        this->m_size = arr.m_size;
//        this->pAddress = new T[this->m_num];
//        for (int i = 0; i < arr.m_size; i++)
//        {
//            this->pAddress[i] = arr.pAddress[i];
//        }
//    }
//    //����=
//    myArray& operator=(const myArray& p)
//    {
//        if (this->pAddress != NULL)
//        {
//            delete[] this->pAddress;
//            this->pAddress = NULL;
//        }
//        this->m_num = p.m_num;
//        this->m_size = p.m_size;
//        this->pAddress = new T[this->m_num];
//        for (int i = 0; i < p.m_size; i++)
//        {
//            this->pAddress[i] = p.pAddress[i];
//        }
//        return *this;
//    }
//    //����[]
//    T& operator[](int index)
//    {
//        return this->pAddress[index];
//    }
//    //β��
//    void pushback(const T& val)
//    {
//        if (this->m_size >= this->m_num)
//        {
//            return;
//        }
//        this->pAddress[this->m_size] = val;
//        this->m_size++;
//    }
//    //��ȡ���鵱ǰ��С
//    int getsize()
//    {
//        return this->m_size;
//    }
//private:
//    T* pAddress;
//    int m_num;//������
//    int m_size;//��������
//};
//class Person
//{
//public:
//    Person(){}
//    Person(string name,int age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//    string m_name;
//    int m_age = 0;
//
//};
//void printPerson(myArray<Person>& p)
//{
//    for (int i = 0; i <p.getsize(); i++)
//    {
//        cout << "����:" << p[i].m_name << endl;
//        cout << "����:" << p[i].m_age << endl;
//    }
//
//}
//int main()
//{
//    myArray<Person> myarr(100);
//    Person p1("Tom", 99);
//    Person p2("Jerry", 1);
//    Person p3("GG_Bond", 18);
//    myarr.pushback(p1);
//    myarr.pushback(p2);
//    myarr.pushback(p3);
//    printPerson(myarr);
//    return 0;
//}



