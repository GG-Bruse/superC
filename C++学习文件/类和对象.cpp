#define _CRT_SECURE_NO_WARNINGS

//��Ͷ���

//��ʶ
/*
��Ĺؼ���:class
���еĺ�������Ϊ��Ա����(���Ա����)
���еı�������Ϊ��Ա����(���Ա����)
ͨ���ഴ��һ������(����),����Ϊʵ��������
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    int a;//ֻ�зǾ�̬��Ա���������������
//
//    void fun1() {}//��Ա�����������������
//
//    static int b;//��̬��Ա�����������������
//
//    static void fun2() {}//��̬��Ա�����������������
//
//    double d;//��struct��ͬҲ��ѭ�ڴ����
//};
//int main()
//{
//    A a;
//    cout << sizeof(a) << endl;//16
//    return 0;
//}


//�����Լ��ն���Ĵ�СΪ1�ֽ�
//#include<iostream>
//using namespace std;
//class Person
//{};
//int main()
//{
//    Person p;
//    cout << sizeof(Person) << endl;//1
//    cout << sizeof(p) << endl;//1
//    return 0;
//}


//���һ���࣬��Բ���ܳ�
//#include<iostream>
//using namespace std;
//const float pi = 3.14f;
//class Circle
//{
//public://����Ȩ��
//	float R;
//	void SETR(float r)//���ð뾶
//	{
//		R = r;
//	}
//	float ZC()//�����ܳ�
//	{
//		return 2 * R * pi;
//	}
//};
//int main()
//{
//	Circle c1;//ͨ���ഴ��һ������(ʵ��������)
//	c1.SETR(10);//c1.R = 10;
//	cout << "Բ���ܳ�Ϊ = " << c1.ZC() << endl;//62.8
//	return 0;
//}



//���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ�����ҿ�����ʾѧ����������ѧ��
//#include<iostream>
//#include<string>
//using namespace std;
//class student
//{
//public:
//    struct S
//    {
//        string name;
//        int ID;
//    }s1;
//    void get()
//    {
//        S* p = &s1;
//        cout << "������ѧ��������:";
//        cin >> p->name;
//        cout << "������ѧ����ѧ��:";
//        cin >> p->ID;
//    }
//    void put()
//    {
//        S* p = &s1;
//        cout << p->name << ":" << p->ID << endl;
//    }
//};
//int main()
//{
//    student s;
//    s.get();
//    s.put();
//    return 0;
//}










//��ķ�װ
/*
C++��װ����:
�����Ժ���Ϊ��Ϊһ�����壬���������
�����Ժ���Ϊ����Ȩ�޿���
*/
/*
class��Ĭ��Ȩ��Ϊ˽��Ȩ��
����Ȩ��:
1.public����Ȩ�ޡ����������ⶼ���Է��ʳ�Ա
2.private˽��Ȩ�ޡ������ڿ��Է��ʳ�Ա�����ⲻ�ɷ��ʳ�Ա
3.protectd����Ȩ�ޡ������ڿ��Է��ʳ�Ա�����ⲻ�ɷ��ʳ�Ա(������Է��ʸ����protectdȨ������)
*/

/*
���齫��Ա��������Ϊprivate˽��Ȩ��
����:
(1)����ͨ�������б�д���������ƶ�д
(2)�����ں����ж��������ݼ�����Ч����֤
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Person
//{
//public:
//    //��������
//    int setname(string p)
//    {
//        if (p == "����")
//        {
//            cout << "�������ѱ�ʹ��" << endl;
//            return 0;
//        }
//        name = p;
//    }
//    //��ȡ����
//    string getname()
//    {
//        return name;
//    }
//    //��ȡ����
//    int getage()
//    {
//        return age;
//    }
//    //����
//    void setlover(string a)
//    {
//        lover = a;
//    }
//private:
//    string name = "����";//�ɶ�����д
//    int age = 18;//�ɶ�
//    string lover;//��д
//};
//void test()
//{
//    Person p;
//    //����
//    p.setname("����");
//    cout << p.getname() << endl;
//    //����
//    cout << p.getage() << endl;
//    //LOVER
//    p.setlover("abcdef");
//}
//int main()
//{
//    test();
//    return 0;
//}



//����������ư���
//�ֱ�ͨ��ȫ�ֺ����ͳ�Ա�����ж����������Ƿ����
//#include<iostream>
//using namespace std;
//class Cube
//{
//public:
//    //���ó����
//    void setLWH(int a,int b,int c)
//    {
//        l = a;
//        w = b;
//        h = c;
//    }
//    //��ȡ�����
//    int getL()
//    {
//        return l;
//    }
//    int getW()
//    {
//        return w;
//    }
//    int getH()
//    {
//        return h;
//    }
//    //�����
//    int S()
//    {
//        return 2 * l * w + 2 * l * h + 2 * w * h;
//    }
//    //�����
//    int V()
//    {
//        return l * w * h;
//    }
//    //�ж�
//    bool compare(Cube &c)
//    {
//        return ((l == c.getL()) && (w == c.getW()) && (h == c.getH()));  
//    }
//private:
//    int l;//��
//    int w;//��
//    int h;//��
//};
//bool compareCube(Cube &c1,Cube &c2)
//{
//    return ((c1.getL() == c2.getL()) && (c1.getW() == c2.getW()) && (c1.getH() == c2.getH()));   
//}
//int main()
//{
//    Cube c1, c2;
//    c1.setLWH(10,10,10);
//    c2.setLWH(10, 10, 10);
//    cout << "���Ϊ:" << c1.S() << endl;
//    cout << "���Ϊ:" << c1.V() << endl;
//    bool ret = compareCube(c1, c2);
//    if (ret)
//    {
//        cout << "c1��c2���" << endl;
//    }
//    else
//    {
//        cout << "c1��c2�����" << endl;
//    }
//     ret = c1.compare(c2);
//    if (ret)
//    {
//        cout << "��Ա�����ж�c1��c2���" << endl;
//    }
//    else
//    {
//        cout << "��Ա�����ж�c1��c2�����" << endl;
//    }
//    return 0;
//}



//���Բ��ϵ����
//#include<iostream>
//using namespace std;
////����
//class Point
//{
//public:
//    //����x��y
//    void setxy(int a, int b)
//    {
//        x = a;
//        y = b;
//    }
//    //��ȡx��y
//    int getx()
//    {
//        return x;
//    }
//    int gety()
//    {
//        return y;
//    }
//private:
//    int x;
//    int y;
//};
////Բ��
//class Circle
//{
//public:
//    void setr(int a)//���ð뾶
//    {
//        m_r = a;
//    }
//    int getr()//��ȡ�뾶
//    {
//        return m_r;
//    }
//    void setcenter(Point p)//����Բ��
//    {
//        m_center = p;
//    }
//    Point getcenter()//��ȡԲ��
//    {
//        return m_center;
//    }
//private:
//    int m_r;//�뾶
//    Point m_center;//Բ��
//};
//void panduan(Circle c,Point p)
//{
//    int distanced = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx())
//        + (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());//�㵽Բ�ľ����ƽ��
//    int Rdistanced = c.getr() * c.getr();//�뾶��ƽ��
//    if (distanced == Rdistanced)
//    {
//        cout << "����Բ��" << endl;
//    }
//    else if (distanced > Rdistanced)
//    {
//        cout << "����Բ��" << endl;
//    }
//    else
//    {
//        cout << "����Բ��" << endl;
//    }
//}
//int main()
//{
//    Circle c;
//    Point ce;//Բ��
//    Point p;
//    ce.setxy(0, 0);
//    c.setcenter(ce);
//    c.setr(10);
//    p.setxy(10, 10);
//    panduan(c, p);
//        return 0;
//}

















//����Ĺ��������

//���캯�����г�ʼ��������������������
//�������������������ȫ��������

/*
���캯��:
1.û�з���ֵ������дvoid
2.��������������ͬ
3.�����в��������Է�������
4.���캯���ɱ������Զ�����һ��(������ʱ����)
*/
/*
��������:
1.û�з���ֵ������дvoid
2.������Ϊ����ǰ����~
3.�������в����������Է�������
4.���캯���ɱ������Զ�����һ��(�����ͷ�ʱ����)
*/


//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person()
//    {
//        cout << "���캯������" << endl;
//    }
//    ~Person()
//    {
//        cout << "������������" << endl;
//    }
//};
//int main()
//{
//    Person p;
//    return 0;
//}




//���캯���ķ���͵���
/*
���ղ�������:
1.�޲ι���(Ĭ�Ϲ��캯��)
2.�вι���
�������ͷ���:
1.��ͨ���캯��
2.�������캯��
*/

/*
����:
1.���ŷ�
 ��Ҫʹ�����ŷ������޲ι��캯��������������Ϊ�����Ǻ���������
2.��ʾ��:
��Ҫʹ�ÿ������캯����ʼ����������
3.��ʽ����ת����:
�ɶ��Խϵ�
*/

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int a)
//    {
//        cout << "���캯������" << endl;
//    }
//    Person(const Person& p)
//    {
//        cout << "�������캯������" << endl;
//    }
//    ~Person()
//    {
//        cout << "������������" << endl;
//    }
//};
//int main()
//{
//    Person p(10);
//    Person p2(p);//���ŷ�
//
//    Person p3 = Person(10);
//    Person p4 = Person(p3);//��ʾ�� 
//    //Person(10);//�������󡪡���ǰִ����ɺ������ͷ�
//   
//    //��ʽ��
//    Person p5 = 10;//Person p5 = Person(10);
//    Person p6 = p5;//Peraon p6 = Person(p5);
//
//    cout << endl;
//    return 0;
//}







//�������캯���ĵ���ʱ��
/*
1.���Ѿ������õĶ�������ʼ���µĶ���
2.��ֵ���ݵķ�ʽ�������Ĳ�����ֵ(ֵ���ݵı��ʾ��ǽ��п���)
3.��ֵ�ķ�ʽ���ؾֲ�����
*/






//���캯���ĵ��ù���
/*
1.���������һ����Ĭ������ĸ�����(1)Ĭ�Ϲ��졪����ʵ��(2)��������������ʵ��(3)�������졪��ֵ����(4)operator=��ֵ��������ء���ֵ����
2.�������Լ��ṩ���вι��캯�����������Ͳ����ṩĬ�Ϲ��캯��������Ȼ���ṩ�������캯��
3.�������ṩ�˿������캯�����������Ͳ����ṩ�������캯��
*/

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person()
//    {
//        cout << "Ĭ�Ϲ��캯������" << endl;
//    }
//    Person(int age)
//    {
//        m_Age = age;
//        cout << "�вι��캯������" << endl;
//    }
//    //Person(const Person& p)//������Ĭ����ӿ������캯����������ֵ����
//    //{
//    //    m_Age = p.m_Age;
//    //    cout << "�������캯������" << endl;
//    //}
//    ~Person()
//    {
//        cout << "������������" << endl;
//    }
//    int m_Age =10;
//};
//int main()
//{
//    Person p1;
//    p1.m_Age = 18;
//    Person p2(p1);
//    cout << p2.m_Age << endl;//18
//    return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    A() = default;//�ñ������ṩһ���޲ι��죬Ч�ʱ��û������ṩ����
//    //defaultֻ��������Ĭ����ӵ��ĸ�����
//
//    A(int a)//�ṩ���вι��죬���ṩ�޲ι���
//    {
//        cout << a << endl;
//    }
//
//    A(const A& a);//����
//
//    A& operator=(const A& a) = delete;//��"=delete"���Σ��˺���������
//    //=delete�������ڸ��ֳ�Ա����
//};
//A::A(const A& a) = default;//���Է��õ�����ⲿ
//int main()
//{
//    A a;
//    A a2 = a;
//    a2 = a;//���ø�ֵ�������غ���,error
//    return 0;
//}









//��ǳ��������
//�������Կ����ڶ��������ñ������ṩ�Ŀ������������ǳ�������������������������ظ��ͷŶ����ڴ������
//������������ǳ��������(�Լ��ṩ�������캯����ʵ�����)
//#include<iostream>
//#include<cstdlib>
//using namespace std;
//class Person
//{
//public:
//    Person(const char* name, int age)
//    {
//        m_name = (char*)malloc(sizeof(name));
//        if (m_name == NULL)
//        {
//            return;
//        }
//        strcpy(m_name, name);
//        m_age = age;
//    }
//    Person(const Person& p)//�����ṩ�������������������ǳ�����������ͷſռ�
//    {
//        m_name = (char*)malloc(sizeof(p.m_name));
//        if (m_name == NULL)
//        {
//            return;
//        }
//        strcpy(m_name, p.m_name);
//        m_age = p.m_age;
//    }
//    char* m_name;
//    int m_age = 0;
//    ~Person()//����ʱ�ͷŶ����ռ�
//    {
//        if (m_name != NULL)
//        {
//            free(m_name);
//            m_name = NULL;
//        }
//    }
//};
//int main()
//{
//    Person p("bjy", 18);
//    cout << "����:" << p.m_name << endl;
//    cout << "����:" << p.m_age << endl;
//    Person p2(p);//�������ṩ�˿������캯������ɶ����ͷſռ�
//    cout << "����:" << p.m_name << endl;
//    cout << "����:" << p.m_age << endl;
//    return 0;
//}










//��ʼ���б�
//�������ó�ʼ���б����������Խ��г�ʼ������
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    //1.
//    //Person() :m_a(10), m_b(20), m_c(30) {}//��ʼ���б� ���ڸ���ֵ
//    //2.
//    Person(int a, int b, int c) :m_a(a), m_b(b), m_c(c) {}
//    int m_a;
//    int m_b;
//    int m_c;
//};
//int main()
//{
//    //1.
//    //Person p;
//    //2.
//    Person p(10, 20, 30);
//    cout << "m_a = " << p.m_a << endl;
//    cout << "m_b = " << p.m_b << endl;
//    cout << "m_c = " << p.m_c << endl;
//    return 0;
//}







//����������г�Ա
//�������������Ϊ�����Ա���ȹ�������������ٹ�������������˳�����෴��
/*
���´�����:
Phone�Ĺ��캯������
Game�Ĺ��캯������
Person�Ĺ��캯������
Person��������������
Game��������������
Phone��������������
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Phone
//{
//public:
//    Phone(string name)
//    {
//        cout << "Phone�Ĺ��캯������" << endl;
//        phonename = name;
//    }
//    string phonename;
//    ~Phone()
//    {
//        cout << "Phone��������������" << endl;
//    }
//};
//class Game
//{
//public:
//    Game(string gname)
//    {
//        cout << "Game�Ĺ��캯������" << endl;
//        gamename = gname;
//    }
//    string gamename;
//    ~Game()
//    {
//        cout << "Game��������������" << endl;
//    }
//};
//class Person
//{
//public:
//    Person(string a, string b, string c) :m_name(a), m_phone(b), m_game(c)
//    {
//        cout << "Person�Ĺ��캯������" << endl;
//    }
//    ~Person()
//    {
//        cout << "Person��������������" << endl;
//    }
//    string m_name;
//    Phone m_phone;
//    Game m_game;
//};
//int main()
//{
//    Person p("����", "Ѽ��", "����");
//    return 0;
//}





//explicit�ؼ���
/*
ע��:
1.explicit�������ι��캯��(λ�ڹ��캯��ǰ)����ֹ��ʽת��(ǿ����ߴ���Ŀɶ���)
2.����Ե��������Ĺ��캯��(���߳��˵�һ�������������ຯ������Ĭ��ֵ�Ķ�ι��캯��)����
*/





//new��������
//delete�ͷŶ���������ռ�
/*
malloc��new������:
1.malloc��free���ڿ⺯��;new��delete�����������
2.malloc������ù��캯����new����ù��캯��
3.malloc����void*����Ҫǿת;new���ش����Ķ����ָ��
*/
/*
ע������:
��Ҫʹ��void*����new�����Ķ���ʲô���͵Ķ���ʹ��ʲô���͵�ָ�����
*/
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person()
//    {
//        cout << "Person���캯������" << endl;
//    }
//    Person(int a)
//    {
//        cout << "Person�вι��캯������" << endl;
//    }
//    ~Person()
//    {
//        cout << "Person������������" << endl;
//    }
//};
//int main()
//{
//    Person* p = new Person;//�������ٵ��ڴ����Լ��ͷ�
//    delete p;
//
//    //����new�ڶ����������飬һ�������Ĭ�Ϲ��캯��
//    Person* pp = new Person[10];
//    delete[]pp;//��[]�����߱�����Ѱ���м�������
//
//    //��ջ�Ͽ������飬����û��Ĭ�Ϲ��캯��
//    Person arr[2] = { Person(10) };
//    return 0;
//}























//��̬��Ա

/*
���ඨ���У����ĳ�Ա(������Ա�����ͳ�Ա����)�����ùؼ���static����Ϊ��̬�ģ���Ϊ��̬��Ա
��������ഴ���˶��ٸ����󣬾�̬��Աֻ��һ������������������������������Ķ�����
*/



//��̬��Ա����
/*
1.��̬��Ա�������������������������ⶨ��
2.��̬��Ա����������ĳ��������Ϊ�������ռ��в�������̬��Ա��ռ�ռ�
3.��̬��Ա��������ͨ�������������������
4.���ж��󶼹���һ������
5.��̬��Ա����Ҳ�ܷ���Ȩ������
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    //��̬��Ա����:����׶ξͷ������ڴ�
//    //��������
//    static int m_a;
//};
//int A::m_a = 10;//�����ʼ��
//int main()
//{
//    //1.ͨ��������з���
//    A a1;
//    cout << "m_a = " << a1.m_a << endl;
//    A a2;
//    a2.m_a = 20;
//    cout << "m_a = " << a1.m_a << endl;
//    //2.ͨ���������з���
//    cout << "m_a = " << A::m_a << endl;
//    return 0;
//}



//��̬��Ա����
/*
1.���ж��󶼹���ͬһ������
2.��̬��Ա��������ͨ�������������������
3.��̬��Ա�������Է��ʾ�̬��Ա�����������ܷ�����ͨ��Ա����
4.��̬��Ա����Ҳ�ܷ���Ȩ������
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    static void fun()
//    {
//        cout << "��̬��Ա��������" << endl;
//    }
//};
//int main()
//{
//    //ͨ���������
//    A a1;
//    a1.fun();
//    //ͨ������
//    A::fun();
//
//    return 0;
//}













//����ģʽ

/*
����ģʽ��һ�ֳ�����������ģʽ�������ĺ��Ľṹ��ֵ����һ������Ϊ�����������ࡣͨ������ģʽ���Ա�֤ϵͳ��һ����ֻ��һ��ʵ��
���Ҹ�ʵ�����������ʣ��Ӷ������ʵ�������Ŀ��Ʋ���Լϵͳ��Դ��
*/
/*
ʵ�ַ���:
1.�����캯��˽�л���ʵ�ֲ��ɴ����������
2.��������һ����ָ̬�룬������г�ʼ������ָ��ΪΨһʵ��������������Ϊ˽��Ȩ�ޣ���ֹͨ����ָ������NULL�����޷�����
3.��˽��Ȩ�����ṩ��ʵ�ֵĿ������캯������ֹͨ���������ṩ�Ŀ������캯��ʵ�ִ�������
4.����Ȩ�����ṩ�ӿڣ�ʵ�ַ��ʸö���Ĺ���
5.����ģʽ��ͨ��new�ڶ������ٵĿռ�һ�㲻�����ͷ�(���ܶ���ʹ��),�ڳ������ʱ��ϵͳ�ջض����ڴ�
*/

//#include<iostream>
//using namespace std;
//class ChairMan//��ϯ��
//{
//private:
//    //���캯��˽�л��������Դ����������
//    ChairMan()
//    {}
//    //��ֹͨ���������ṩ�Ŀ������캯��ʵ�ִ�������
//    ChairMan(const ChairMan&)
//    {}
//    static ChairMan* singleman;//��������
//public:
//    //����ֻ���ӿ�
//    static ChairMan* get()
//    {
//        return singleman;
//    }
//};
//ChairMan* ChairMan::singleman = new ChairMan;//�����ʼ������
//int main()
//{
//    ChairMan* c1 = ChairMan::get();
//    ChairMan* c2 = ChairMan::get();
//    if (c1 == c2)
//    {
//        cout << "c1 = c2" << endl;
//    }
//    else
//    {
//        cout << "c1 != c2" << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//class Printer
//{
//private:
//    Printer()
//    {
//        count = 0;
//    }
//    Printer(const Printer&)
//    {}
//    static Printer* p;
//    int count;//��¼��ӡ����
//public:
//    static Printer* get()
//    {
//        return p;
//    }
//    //��ӡ����
//    void printtext(string str)
//    {
//        cout << str << endl;
//        count++;
//    }
//    //�鿴��ӡ����
//    void look()
//    {
//        cout << "����ӡ" << count << "��" << endl;
//    }
//};
//Printer* Printer::p = new Printer;
//int main()
//{
//    Printer* p = Printer::get();
//    p->printtext("bjy is the best handsome boy");
//    p->printtext("bjy is the best handsome boy");
//    p->look();
//    p->printtext("bjy is the best handsome boy");
//    p->look();
//    return 0;
//}














//thisָ��
//thisָ��ı���:����* const this(�������޸�)
/*
thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
thisָ����ʽ�ļ���ÿ����Ա������
��Ҫʹ�ÿ�ָ�����(��ʽ)�õ�thisָ��ĳ�Ա����
*/
/*
��;:
1.������Ƴ�ͻ
2.ʵ����ʽ���
*/
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int age)
//    {
//        this->age = age;
//    }
//    Person& Addage(Person& p)
//    {
//        this->age += p.age;
//        return *this;//ָ�򱻵��õĳ�Ա���������Ķ����ָ�룬������Ϊ�������
//    }
//    int age;
//};
//int main()
//{
//    Person p1(18);
//    Person p2(10);
//    cout << "p1������Ϊ:" << p1.age << endl;
//    p1.Addage(p2);
//    cout << "p1������Ϊ:" << p1.age << endl;
//    p1.Addage(p2).Addage(p2);//��ʽ���˼��
//    cout << "p1������Ϊ:" << p1.age << endl;
//    return 0;
//}





//�������볣����
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//    Person(int age ,int high)
//    {
//        m_age = age;
//        m_high = high;
//    }
//
//    void showage() const//const����Ϊ������(�е�thisָ��)��ʹ�ò����޸�thisָ���ֵ
//    {
//        //m_age = 100;
//        m_high = 180;
//        cout << "����Ϊ:" << this->m_age << endl;
//        cout << "���Ϊ:" << this->m_high << endl;
//    }
//
//    mutable int m_high;//����mutable�ؼ��֣�ʹ�ó����������޸ĸó�Ա������ֵ��������Ϊ�����������ʱҲ���Ա��޸�
//    int m_age;
//};
//int main()
//{
//    Person p1(18, 10);
//    p1.showage();
//    const Person p2(1, 1);//�����󡪡������Բ��ɱ��޸�
//    //���������ֻ���ó���������ͨ���������޸������Ե��±���
//    p2.showage();
//    return 0;
//}












//��Ԫ
/*
�����Ҫ�ص�֮һ���������أ������˽�г�Ա�޷�������ⲿ(������֮��)���ʡ�
��Ԫ��һ����Ȩ��C++���������˽�г�Ա��
*/

//1.ȫ�ֺ�������Ԫ����
//#include<iostream>
//#include<string>
//using namespace std;
//class Building
//{
//    friend void goodfirend(Building* p);//����firend�ؼ��֣�������Ԫ����
//public:
//    Building()
//    {
//        this->sittingroom = "����";
//        this->bedroom = "����";
//    }
//public:
//    string sittingroom;//����
//private:
//    string bedroom;//����
//
//};
////ȫ�ֺ���
//void goodfirend(Building* p)
//{
//    cout << "���ڷ���" << p->sittingroom << endl;
//    cout << "���ڷ���" << p->bedroom << endl;
//}
//int main()
//{
//    Building Person;
//    goodfirend(&Person);
//    return 0;
//}


//2.����Ϊ��Ԫ��
//#include<iostream>
//#include<string>
//using namespace std;
////��:�ҵķ���
//class Building
//{
//    friend class Goodfriend;
//public:
//    Building()
//    {
//        this->sittingroom = "����";
//        this->bedroom = "����";
//    }
//    string sittingroom;
//private:
//    string bedroom;
//};
////��:������
//class Goodfriend
//{
//public:
//    Goodfriend()
//    {
//        this->p = new Building;
//    }
//    void visit()
//    {
//        cout << "���������ڷ���" << p->sittingroom << endl;
//        cout << "���������ڷ���" << p->bedroom << endl;
//    }
//    Building* p;
//};
//int main()
//{
//    Goodfriend a;
//    a.visit();
//    return 0;
//}


//3.��һ�����еĳ�Ա������Ϊ������Ԫ����
//�����������д������������޷�ʶ��
//#include<iostream>
//#include<string>
//using namespace std;
//class Building;
////��:������
//class Goodfriend
//{
//public:
//    Goodfriend();
//    void visit();
//
//    Building* p;
//};
////��:�ҵķ���
//class Building
//{
//    friend void Goodfriend::visit();
//public:
//    Building()
//    {
//        this->bedroom = "����";
//    }
//private:
//    string bedroom;
//};
//Goodfriend::Goodfriend()
//{
//    this->p = new Building;
//}
//void Goodfriend::visit()
//{
//    cout << "���������ڷ���" << p->bedroom << endl;
//}
//int main()
//{
//    Goodfriend a;
//    a.visit();
//    return 0;
//}









//�������װ
//#include<iostream>
//using namespace std;
//class my_arr
//{
//public:
//    my_arr()
//    {
//        cout << "Ĭ�Ϲ��캯������" << endl;
//        this->m_num = 100;
//        this->m_size = 0;
//        this->parr = new int[m_num];
//    }
//    my_arr(int num)
//    {
//        cout << "�вι��캯������" << endl;
//        this->m_num = num;
//        this->m_size = 0;
//       this->parr = new int[m_num];
//    }
//    my_arr(const my_arr& arr)
//    {
//        cout << "�������캯������" << endl;
//        this->m_num = arr.m_num;
//        this->m_size = arr.m_size;
//        this->parr = new int[m_num];
//        if (m_num>=m_size)
//        {
//            for (int i = 0; i < m_size; i++)
//            {
//                this->parr[i] = arr.parr[i];
//            }
//        }
//    }
//    //β�巨
//    void pushBack(int val)
//    {
//        this->parr[this->m_size] = val;
//        m_size++;
//    }
//    //����λ����������
//    void setdata(int pos,int val)
//    {
//        this->parr[pos] = val;
//    }
//    //����λ�û�ȡ����
//    int getdata(int pos)
//    {
//        return this->parr[pos];
//    }
//    //��ȡ��������
//    int getnum()
//    {
//        return m_num;
//    }
//    //��ȡ�����С
//    int getsize()
//    {
//        return m_size;
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
//    int m_size;//���鵱ǰ�Ĵ�С
//    int* parr;//ָ�򿪱��ڶ����Ŀռ�
//};
//int main()
//{
//    int i;
//    my_arr arr;
//    for (i = 0; i < 10; i++)
//    {
//        arr.pushBack(i);
//    }
//    for (i = 0; i < arr.getsize(); i++)
//    {
//        cout << arr.getdata(i) << endl;
//    }
//
//    my_arr arr2(arr);
//    for (i = 0; i < arr2.getsize(); i++)
//    {
//        cout << arr2.getdata(i) << endl;
//    }
//
//    return 0;
//}




//�ַ������װ
//#include<iostream>
//#include<cstring>
//using namespace std;
//class Mystring
//{
//    friend ostream& operator<<(ostream& cout, Mystring& p);
//    friend istream& operator>>(istream& cin, Mystring& p);
//public:
//    Mystring(const char* str)
//    {
//        this->pstring = new char[strlen(str)+1];
//        strcpy(this->pstring, str);
//        this->m_size = strlen(str);
//    }
//    Mystring(const Mystring& p)
//    {
//        this->pstring = new char[strlen(p.pstring)+1];
//        strcpy(this->pstring, p.pstring);
//        this->m_size = p.m_size;
//    }
//    //����=(1)
//    Mystring& operator=(const char* p)
//    {
//        if (this->pstring != NULL)
//        {
//            delete[] this->pstring;
//        }
//        this->pstring = new char[strlen(p) + 1];
//        strcpy(this->pstring, p);
//        this->m_size = strlen(p);
//        return *this;
//    }
//    //����=(2)
//    Mystring& operator=(const Mystring& p)
//    {
//        if (this->pstring != NULL)
//        {
//            delete[] this->pstring;
//        }
//        this->pstring = new char[strlen(p.pstring) + 1];
//        strcpy(this->pstring, p.pstring);
//        this->m_size = strlen(p.pstring);
//        return *this;
//    }
//    //����[]
//    char& operator[](int index)
//    {
//        return this->pstring[index];
//    }
//    //����+ʵ���ַ���ƴ��(1)
//    Mystring operator+(const char* str)
//    {
//        int newsize = this->m_size + strlen(str) + 1;
//        char* temp = new char[newsize];
//        memset(temp, 0, newsize);//���
//        strcat(temp, this->pstring);
//        strcat(temp, str);
//        Mystring newstring(temp);
//        delete[]temp;
//        return newstring;
//    }
//    //+(2)
//    Mystring operator+(Mystring& p)
//    {
//        int newsize = this->m_size + strlen(p.pstring) + 1;
//        char* temp = new char[newsize];
//        memset(temp, 0, newsize);//���
//        strcat(temp, this->pstring);
//        strcat(temp, p.pstring);
//        Mystring newstring(temp);
//        delete[]temp;
//        return newstring;
//    }
//    //����==�����ַ����ıȽ�(1)
//    bool operator==(const Mystring& p)
//    {
//        int ret = strcmp(this->pstring, p.pstring);
//        if (ret == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//    //==(2)
//    bool operator==(const char* str)
//    {
//        int ret = strcmp(this->pstring, str);
//        if (ret == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//    ~Mystring()
//    {
//        if (this->pstring != NULL)
//        {
//            delete[] this->pstring;
//            this->pstring = NULL;
//        }
//    }
//private:
//    char* pstring;//ά���ڶ������ٵ��ַ�����
//    int m_size;//�ַ����ĳ���(��ͳ��'\0')
//};
////����<<�������
//ostream& operator<<(ostream& cout, Mystring& p)
//{
//    cout << p.pstring << endl;
//    return cout;
//}
////����>>��������
//istream& operator>>(istream& cin, Mystring& p)
//{
//    char buff[1024];//������ʱ��������������
//    if (p.pstring != NULL)
//    {
//        delete[] p.pstring;
//        p.pstring = NULL;
//    }
//    cin >> buff;
//    p.pstring = new char[strlen(buff) + 1];
//    strcpy(p.pstring, buff);
//    p.m_size = strlen(buff);
//    return cin ;
//}







//ί�й���
/*
ί�й��캯������ʹ�õ�ǰ����������캯����������ǰ���캯����ʼ��.
1.ί�й���һ��Ҫͨ����ʼ���б�ķ�ʽ
2.����ί�еĹ��캯���ĺ�����������д��룬��ô����ִ���꺯����Ĵ��룬�Ż�ص�����ί������Ĺ��캯��
3.��Ҫ�γ�ί�л���
 �ڹ��캯���϶�ʱ,���ǿ���ӵ�ж��ί�й��캯��,��һЩĿ�깹�캯���ܿ���Ҳ��ί�й��캯��,
 �ͺܿ�����ί�й��캯�����γ�ѭ����״��ί�й����ϵ
 4.����ί�й��캯����ʹ��try�����Բ���Ŀ�깹�캯�����׳����쳣
*/

//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//    Test():Test(18,'b')
//    {
//        cout << "�����޲ι��캯��" << endl;
//    }
//    Test(int x):m_x(x){}
//    Test(char y):m_y(y){}
//    Test(int x, char y) :m_x(x), m_y(y) { cout << "�����вι��캯��" << endl; }
//
//    int m_x = 0;
//    char m_y = 0;
//};
//int main()
//{
//    Test t;
//    cout << t.m_x << endl;
//    cout << t.m_y << endl;
//    return 0;
//}
/*
���:
�����вι��캯��
�����޲ι��캯��
18
b
*/



//ί�л�(����)
//#include<iostream>
//using namespace std;
//class Foo
//{
//public:
//    Foo(int i) : Foo('c') { type = i; }
//    Foo(char c) : Foo(1) { name = c; }
//private:
//    int type;
//    char name;
//};



//error
//#include <iostream> 
//using namespace std;
//class Foo
//{
//public:
//    Foo(int i)try:Foo(i, 'c'){}
//    catch (...)
//    {
//        cout << "����int�����쳣" << endl;
//    }
//private:
//    Foo(int i, char c)
//    {
//        this->type = i;
//        this->name = c;
//        cout << "�׳��쳣" << endl;
//        throw 0;
//    }
//    int type;
//    char name;
//};
//int main()
//{
//    Foo f(1);
//    return 0;
//}


