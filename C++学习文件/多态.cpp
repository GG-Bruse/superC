#define _CRT_SECURE_NO_WARNINGS

//��̬
/*
��̬�Ը����˴���Ŀɶ��Ժ���֯�ԣ�ͬʱҲʹ�ô����ĳ�������˿���չ��
C++֧�ֱ���ʱ��̬(��̬��̬)������ʱ��̬(��̬��̬)����������غͺ������ؾ��Ǳ���ʱ��̬������������麯��ʵ������ʱ��̬

��̬��̬�Ͷ�̬��̬��������Ǻ�����ַ�����(��̬����)�������(��̬����)��
�������ĵ��ã��ڱ���ʱ����ȷ�������ĵ��õ�ַ�����������룬���Ǿ�̬��̬(����ʱ��̬)������˵��ַʱ��󶨵ġ�
�������ĵ��õ�ַ�����ڱ���ʱȷ��������Ҫ������ʱ����ȷ��������������(��̬��̬������ʱ��̬)
*/

/*
��̬����������:
1.���ڼ̳й�ϵ
2.���������麯������������д�����е��麯��
3.�����ָ�������ָ������Ķ���
*/
/*
��д(����)
1.�м̳�
2.����(������)��д����(����)��virtual����
��������ֵ���������֡���������������ͻ����е��麯��һ��
*/

//��̬����
//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//    void speak()
//    {
//        cout << "������˵��" << endl;
//    }
//};
//class Cat : public Animal
//{
//public:
//    void speak()
//    {
//        cout << "Сè��˵��" << endl;
//    }
//};
////�и��ӹ�ϵ�������࣬���ǵ�ָ����������ǿ���ֱ��ת����
//void dospeak(Animal& p)
//{
//    //��ַ��Ͱ󶨺��ˣ���ַ��󶨣����ھ�̬����
//    p.speak();
//}
//int main()
//{
//    Cat c;
//    dospeak(c);//������˵��
//    return 0;
//}



//��̬����
//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//    //����virtual�ؼ��ֺ󣬸ú�����Ϊ�麯��
//    virtual void speak()
//    {
//        cout << "������˵��" << endl;
//    }
//};
//class Cat : public Animal
//{
//public:
//    void speak()
//    {
//        cout << "Сè��˵��" << endl;
//    }
//};
//class Dog : public Animal
//{
//public:
//    void speak()
//    {
//        cout << "С����˵��" << endl;
//    }
//};
//void dospeak(Animal& p)
//{
//    p.speak();
//}
//int main()
//{
//    //�����������ݽ��а󶨣������н׶ΰ󶨺�����ַ����ַ��󶨣����ڶ�̬����
//    Cat c;
//    dospeak(c);//Сè��˵��
//    Dog d;
//    dospeak(d);//С����˵��
//    return 0;
//}





//���麯���ͳ�����
/*
���麯�����������ڻ�����Ϊ�������ౣ��һ�����������֣��Ա������������Ҫ�������ж���.
ע��:
1.���һ�����а������麯������ô�������޷�ʵ�������������ͨ������Ϊ������
3.����������������д����Ĵ��麯��������Ҳ���ڳ�����
3.���麯��û�к�����;
4.������"=0"������ʾ��������ֵΪ0,ֻ����ʽ�ϵ�����,���߱������ú���Ϊ�麯��
*/

//#include<iostream>
//#include<string>
//using namespace std;
////������������
//class AbstractCalculator
//{
//public:
//    virtual int getresult() = 0;//���麯��
//    int m_a;
//    int m_b;
//};
////�ӷ�������
//class AddCalculator: public AbstractCalculator
//{
//public:
//    int getresult()
//    {
//        return m_a + m_b;
//    }
//};
////����������
//class SubCalculator : public AbstractCalculator
//{
//public:
//    int getresult()
//    {
//        return m_a - m_b;
//    }
//};
////�˷�
//class Mulculator : public AbstractCalculator
//{
//public:
//    int getresult()
//    {
//        return m_a * m_b;
//    }
//};
//int main()
//{
//    AbstractCalculator* p = new AddCalculator;
//    p->m_a = 10;
//    p->m_b = 20;
//    cout << p->getresult() << endl;
//    delete p;
//    p = new SubCalculator;
//    p->m_a = 10;
//    p->m_b = 20;
//    cout<<p->getresult();
//    delete p;
//    p = nullptr;
//    return 0;
//}




//�������ʹ�������
/*
�����������ָ����������ԣ���ôҪ��������������deleteʱ�����������������
��������Ҫ������ҲҪ��ʵ��(��������������ʵ��)
���һ���������˴���������������ô��������ڳ����࣬�޷�ʵ��������
*/

//#include<iostream>
//#include<cstring>
//using namespace std;
//class Animal
//{
//public:
//    Animal()
//    {
//        cout << "Animal���캯������" << endl;
//    }
//    virtual void speak()
//    {
//        cout << "������˵��" << endl;
//    }
//    //1.
//    virtual~Animal() = 0;//��������
//    //2.
//    //virtual ~Animal()//������
//    //{
//    //    cout << "Animal��������������" << endl;
//    //}
//};
//Animal::~Animal()
//{
//    cout << "Animal����������������" << endl;
//}
//class Cat: public Animal
//{
//public:
//    Cat(const char* name)
//    {
//        cout << "Cat���캯������" << endl;
//        this->m_name = new char[strlen(name) + 1];
//        strcpy(this->m_name, name);
//    }
//    void speak()
//    {
//        cout << "Сè��˵��" << endl;
//    }
//    char* m_name;
//    ~Cat()
//    {
//        cout << "Cat������������" << endl;
//        if (this->m_name != NULL)
//        {
//            delete[] this->m_name;
//            this->m_name = NULL;
//        }
//    }
//};
//int main()
//{
//    Animal* p = new Cat("Tom");//��deleteһ��������ָ��ʱ��,����Ҫͨ���麯���ҵ���������������
//    p->speak();
//    delete p;
//    return 0;
//}







//������������ת��
/*
����ָ��ת������ָ�롪����������ת��(�׳���ѰַԽ��)
����ָ��ת�ɸ���ָ�롪����������ת��
�������˶�̬����ôת����Զ���ǰ�ȫ��
*/





//��̬����(������װ)
//#include<iostream>
//using namespace std;
//class CPU
//{
//public:
//    virtual void calculate() = 0;
//};
//class Videocard
//{
//public:
//    virtual void display() = 0;
//};
//class Memory
//{
//public:
//    virtual void storage() = 0;
//};
//class computer
//{
//public:
//    computer(CPU* cpu, Videocard* vc, Memory* mem)
//    {
//        this->m_cpu = cpu;
//        this->m_vc = vc;
//        this->m_mem = mem;
//    }
//    void dowork()
//    {
//        this->m_cpu->calculate();
//        this->m_vc->display();
//        this->m_mem->storage();
//    }
//    ~computer()
//    {
//        if (this->m_cpu != NULL)
//        {
//            delete this->m_cpu;
//            this->m_cpu = NULL;
//        }
//        if (this->m_vc != NULL)
//        {
//            delete this->m_vc;
//            this->m_vc = NULL;
//        }
//        if (this->m_mem != NULL)
//        {
//            delete this->m_mem;
//            this->m_mem = NULL;
//        }
//    }
//    CPU* m_cpu;
//    Videocard* m_vc;
//    Memory* m_mem;
//};
////inter����
//class intercpu : public CPU
//{
//public:
//    void calculate()
//    {
//        cout << "interCPU��ʼ����" << endl;
//    }
//};
//class intervideocard: public Videocard
//{
//public:
//    void display()
//    {
//        cout << "inter�Կ���ʼ����" << endl;
//    }
//};
//class intermemory: public Memory
//{
//public:
//    void storage()
//    {
//        cout << "inter�ڴ濪ʼ����" << endl;
//    }
//};
////���볧��
//class Lenovocpu : public CPU
//{
//public:
//    void calculate()
//    {
//        cout << "����CPU��ʼ����" << endl;
//    }
//};
//class Lenovovideocard : public Videocard
//{
//public:
//    void display()
//    {
//        cout << "�����Կ���ʼ����" << endl;
//    }
//};
//class Lenovomemory : public Memory
//{
//public:
//    void storage()
//    {
//        cout << "�����ڴ濪ʼ����" << endl;
//    }
//};
//int main()
//{
//    CPU* c = new intercpu;
//    Videocard* v = new Lenovovideocard;
//    Memory* m = new Lenovomemory;
//    computer com(c, v, m);
//    com.dowork();
//    return 0;
//}