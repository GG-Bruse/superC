#define _CRT_SECURE_NO_WARNINGS

//���������

/*
��������ؾ��Ƕ����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
�������õ��������͵ı��ʽ��������ǲ����Ըı��
�ؼ���:operator
�﷨:
�����Ĳ�������ȡ������������
1.�������һԪ(һ������)���Ƕ�Ԫ��(��������)
2.�����������Ϊȫ�ֺ���(����һԪ��һ�����������ڶ�Ԫ����������)���ǳ�Ա����(����һԪû�в��������ڶ�Ԫ��һ����������ʱ����Ķ��������������)
*/


//�Ӻ����������
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    A() {}//�ṩĬ�Ϲ��캯����
//    A(int a, int b):m_a(a),m_b(b){}//ͨ���б���г�ʼ��
//    int m_a;
//    int m_b;
//    //1.���ó�Ա����ʵ�ּӺ����������
//    /*A operator+(A& a)
//    {
//        A temp;
//        temp.m_a = this->m_a + a.m_a;
//        temp.m_b = this->m_b + a.m_b;
//        return temp;
//    }*/
//};
////2.����ȫ�ֺ���ʵ�ּӺ����������
//A operator+(A& a1, A& a2)
//{
//    A temp;
//    temp.m_a = a1.m_a + a2.m_a;
//    temp.m_b = a1.m_b + a2.m_b;
//    return temp;
//}
//int main()
//{
//    A a1(10, 10);
//    A a2(1, 2);
//    //�򻯵��÷���:
//    A a3 = a1 + a2;
//    //���ʵ��÷���
//    //1.
//    //A a3 = a1.operator+(a2);
//    //2.
//    //A a3 = operator+(a1, a2);
//    cout << a3.m_a << endl << a3.m_b << endl;
//    return 0;
//}





//�������������
//#include<iostream>
//using namespace std;
//class Person
//{
//    friend ostream& operator<<(ostream& out, Person& p);
//public:
//    Person(int a,int b)
//    {
//        this->m_a = a;
//        this->m_b = b;
//    }
//private:
//    int m_a;
//    int m_b;
//};
//ostream& operator<<(ostream &out,Person& p)//��ʽ
//{
//    out << "m_a = " << p.m_a << endl << "m_b = " << p.m_b << endl;
//    return out;
//}
//int main()
//{
//    Person p(1, 2);
//    cout << p << endl;
//    return 0;
//}








//ǰ�ú�������(�Լ�)���������
//#include<iostream>
//using namespace std;
//class Myint
//{
//    friend ostream& operator<<(ostream& cont, Myint& a);
//public:
//    Myint()
//    {
//        m_num = 0;
//    }
//    //ǰ��++����
//    Myint& operator++()
//    {
//        this->m_num++;
//        return *this;
//    }
//    //����++����
//    Myint& operator++(int)//ʹ��ռλ��������ǰ����++��ʹ֮���Է�����������
//    {
//        static Myint temp = *this;
//        this->m_num++;
//        return temp;
//    }
//private:
//    int m_num;
//};
//ostream& operator<<(ostream& cont, Myint& a)
//{
//    cout << a.m_num;
//    return cout; 
//}
//int main()
//{
//    Myint int1;
//    ++int1;
//    cout << ++int1 << endl;
//
//    cout << int1++ << endl;//���ò���ʵ����ʽ
//    cout << int1 << endl;
//    return 0;
//}





//ָ�����������
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int age)
//    {
//        cout << "�вι��캯������" << endl;
//        m_age = age;
//    }
//    void showage()
//    {
//        cout << "����Ϊ:" << this->m_age << endl;
//    }
//    ~Person()
//    {}
//    int m_age;
//};
////��������ָ�����new�������ڴ���ͷ�
//class Smartpoint
//{
//public:
//    Smartpoint(Person* p)
//    {
//        this->m_person = p;
//    }
//    //����->�����
//    Person* operator->()
//    {
//        return this->m_person;
//    }
//    //����*�����
//    Person& operator*()
//    {
//        return *m_person;
//    }
//    ~Smartpoint()
//    {
//        if (this->m_person != NULL)
//        {
//            //cout << "������������" << endl;
//            delete this->m_person;
//        }
//    }
//private:
//    Person* m_person;
//};
//int main()
//{
//    Smartpoint sp(new Person(18));
//    sp->showage();
//    (*sp).showage();
//    return 0;
//}







//��ֵ���������(������ǳ�������³������)
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(const char* name,int age)
//    {
//        this->m_name = new char[strlen(name)+1];
//        strcpy(this->m_name ,name);
//        this->m_age = age;
//    }
//    //����=
//    Person& operator=(const Person &p)
//    {
//        if (this->m_name!= NULL)
//        {
//            //delete []this->m_name;
//        }
//        this->m_name = new char[strlen(p.m_name)+1];
//        strcpy(this->m_name, p.m_name);
//        this->m_age = p.m_age;
//        return *this;
//    }
//    ~Person()
//    {
//        if (this->m_name != NULL)
//        {
//            delete[]this->m_name;
//            this->m_name = NULL;
//        }
//    }
//    char* m_name;
//    int m_age;
//};
//int main()
//{
//    Person p1("Tom", 18);
//    Person p2("Jerry", 10);
//    Person p3("", 0);
//    p3 = p2 = p1;
//    cout << "����:" << p1.m_name << " " << "����:" << p1.m_age << endl;
//    cout << "����:" << p2.m_name << " " << "����:" << p2.m_age << endl;
//    cout << "����:" << p3.m_name << " " << "����:" << p3.m_age << endl;
//    return 0;
//}





//[]���������
//#include<iostream>
//using namespace std;
//class my_arr
//{
//public:
//    my_arr()
//    {
//        cout << "Ĭ�Ϲ��캯������" << endl;
//        this->m_num = 100;
//        this->parr = new int[m_num];
//    }
//    //����
//    int& operator[](int index)
//    {
//        return this->parr[index];
//    }
//    //��������
//    ~my_arr()
//    {
//        cout << "������������" << endl;
//        if (this->parr != NULL)
//        {
//            delete[] parr;
//            this->parr = NULL;
//        }
//    }
//private:
//    int m_num;//���������±�
//    int* parr;//ָ�򿪱��ڶ����Ŀռ�
//};
//int main()
//{
//    int i;
//    my_arr arr;
//    for (i = 0; i < 10; i++)
//    {
//        arr[i]=i;
//    }
//    for (i = 0; i < 10; i++)
//    {
//        cout << arr[i]<< endl;
//    }
//    return 0;
//}





//��ϵ���������
//#include<iostream>
//#include<cstring>
//using namespace std;
//class Person
//{
//public:
//    Person(string name,int age)
//    {
//        m_name = name;
//        m_age = age;
//    }
//    //==����
//    bool operator==(Person& p)
//    {
//        return (this->m_name == p.m_name && this->m_age == p.m_age);
//    }
//    //!=����
//    bool operator !=(Person& p)
//    {
//        return !(this->m_name == p.m_name && this->m_age == p.m_age);
//    }
//    string m_name;
//    int m_age;
//};
//int main()
//{
//    Person p1("Tom", 18);
//    Person p2("Jerry", 10);
//    if (p1 == p2)
//    {
//        cout << "p1 == p2" << endl;
//    }
//    else
//    {
//        cout << "p1 != p2" << endl;
//    }
//    if (p1 != p2)
//    {
//        cout << "p1 != p2" << endl;
//    }
//    else
//    {
//        cout << "p1 == p2" << endl;
//    }
//    return 0;
//}








//�����������������
//#include<iostream>
//#include<string>
//using namespace std;
//class Myprint
//{
//public:
//    void operator()(string str)
//    {
//        cout << str << endl;
//    }
//};
//int main()
//{
//    Myprint print;
//    //ԭʼ���÷���:print.operator()("bjy");
//    print("bjy");//�º��� ������һ������(��������)
//    return 0;
//}






//�����ܽ�:
/*
1.��Ҫ�����߼���(&&)���߼���(||)
ԭ��:�޷��������������ʵ�����ò���������������(�߼���·)
2.= [] -> ������ֻ��ͨ����Ա������������
3.<<��>>ֻ��ͨ��ȫ�ֺ��������Ԫ������������
4.һԪ���������ʹ�ó�Ա��������
*/
