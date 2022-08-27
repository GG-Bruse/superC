#define _CRT_SECURE_NO_WARNINGS

//多态
/*
多态性改善了代码的可读性和组织性，同时也使得创建的程序具有了可扩展性
C++支持编译时多态(静态多态)和运行时多态(动态多态)，运算符重载和函数重载就是编译时多态，而派生类和虚函数实现运行时多态

静态多态和动态多态的区别就是函数地址是早绑定(静态联编)还是晚绑定(动态联编)。
若函数的调用，在编译时可以确定函数的调用地址，并产生代码，就是静态多态(编译时多态)，就是说地址时早绑定的。
若函数的调用地址不能在编译时确定，而需要在运行时才能确定，这就属于晚绑定(动态多态，运行时多态)
*/

/*
多态产生的条件:
1.存在继承关系
2.父类中有虚函数，子类中重写父类中的虚函数
3.父类的指针或引用指向子类的对象
*/
/*
重写(覆盖)
1.有继承
2.子类(派生类)重写父类(基类)的virtual函数
函数返回值、函数名字、函数参数，必须和基类中的虚函数一致
*/

//静态联编
//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//    void speak()
//    {
//        cout << "动物在说话" << endl;
//    }
//};
//class Cat : public Animal
//{
//public:
//    void speak()
//    {
//        cout << "小猫在说话" << endl;
//    }
//};
////有父子关系的两个类，它们的指针或者引用是可以直接转换的
//void dospeak(Animal& p)
//{
//    //地址早就绑定好了，地址早绑定，属于静态联编
//    p.speak();
//}
//int main()
//{
//    Cat c;
//    dospeak(c);//动物在说话
//    return 0;
//}



//动态联编
//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//    //加上virtual关键字后，该函数变为虚函数
//    virtual void speak()
//    {
//        cout << "动物在说话" << endl;
//    }
//};
//class Cat : public Animal
//{
//public:
//    void speak()
//    {
//        cout << "小猫在说话" << endl;
//    }
//};
//class Dog : public Animal
//{
//public:
//    void speak()
//    {
//        cout << "小狗在说话" << endl;
//    }
//};
//void dospeak(Animal& p)
//{
//    p.speak();
//}
//int main()
//{
//    //根据所传内容进行绑定，在运行阶段绑定函数地址，地址晚绑定，属于动态联编
//    Cat c;
//    dospeak(c);//小猫在说话
//    Dog d;
//    dospeak(d);//小狗在说话
//    return 0;
//}





//纯虚函数和抽象类
/*
纯虚函数的作用是在基类中为其派生类保留一个函数的名字，以便派生类根据需要对他进行定义.
注意:
1.如果一个类中包含纯虚函数，那么这个类就无法实例化对象，这个类通常被称为抽象类
3.抽象类的子类必须重写父类的纯虚函数，否则也属于抽象类
3.纯虚函数没有函数体;
4.最后面的"=0"并不表示函数返回值为0,只起形式上的作用,告诉编译器该函数为虚函数
*/

//#include<iostream>
//#include<string>
//using namespace std;
////抽象基类计算器
//class AbstractCalculator
//{
//public:
//    virtual int getresult() = 0;//纯虚函数
//    int m_a;
//    int m_b;
//};
////加法计算器
//class AddCalculator: public AbstractCalculator
//{
//public:
//    int getresult()
//    {
//        return m_a + m_b;
//    }
//};
////减法计算器
//class SubCalculator : public AbstractCalculator
//{
//public:
//    int getresult()
//    {
//        return m_a - m_b;
//    }
//};
////乘法
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




//虚析构和纯虚析构
/*
如果子类中有指向堆区的属性，那么要利用虚析构，在delete时调用子类的析构函数
纯虚析构要有声明也要有实现(类内声明，类外实现)
如果一个类中有了纯虚析构函数，那么这个类属于抽象类，无法实例化对象
*/

//#include<iostream>
//#include<cstring>
//using namespace std;
//class Animal
//{
//public:
//    Animal()
//    {
//        cout << "Animal构造函数调用" << endl;
//    }
//    virtual void speak()
//    {
//        cout << "动物在说话" << endl;
//    }
//    //1.
//    virtual~Animal() = 0;//纯虚析构
//    //2.
//    //virtual ~Animal()//虚析构
//    //{
//    //    cout << "Animal虚析构函数调用" << endl;
//    //}
//};
//Animal::~Animal()
//{
//    cout << "Animal纯虚析构函数调用" << endl;
//}
//class Cat: public Animal
//{
//public:
//    Cat(const char* name)
//    {
//        cout << "Cat构造函数调用" << endl;
//        this->m_name = new char[strlen(name) + 1];
//        strcpy(this->m_name, name);
//    }
//    void speak()
//    {
//        cout << "小猫在说话" << endl;
//    }
//    char* m_name;
//    ~Cat()
//    {
//        cout << "Cat析构函数调用" << endl;
//        if (this->m_name != NULL)
//        {
//            delete[] this->m_name;
//            this->m_name = NULL;
//        }
//    }
//};
//int main()
//{
//    Animal* p = new Cat("Tom");//在delete一个抽象类指针时候,必须要通过虚函数找到真正的析构函数
//    p->speak();
//    delete p;
//    return 0;
//}







//向上向下类型转换
/*
父类指针转成子类指针——向下类型转换(易出现寻址越界)
子类指针转成父类指针——向上类型转换
若发生了多态，那么转换永远都是安全的
*/





//多态案例(电脑组装)
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
////inter厂商
//class intercpu : public CPU
//{
//public:
//    void calculate()
//    {
//        cout << "interCPU开始计算" << endl;
//    }
//};
//class intervideocard: public Videocard
//{
//public:
//    void display()
//    {
//        cout << "inter显卡开始工作" << endl;
//    }
//};
//class intermemory: public Memory
//{
//public:
//    void storage()
//    {
//        cout << "inter内存开始工作" << endl;
//    }
//};
////联想厂商
//class Lenovocpu : public CPU
//{
//public:
//    void calculate()
//    {
//        cout << "联想CPU开始计算" << endl;
//    }
//};
//class Lenovovideocard : public Videocard
//{
//public:
//    void display()
//    {
//        cout << "联想显卡开始工作" << endl;
//    }
//};
//class Lenovomemory : public Memory
//{
//public:
//    void storage()
//    {
//        cout << "联想内存开始工作" << endl;
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