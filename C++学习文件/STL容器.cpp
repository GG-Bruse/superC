#define _CRT_SECURE_NO_WARNINGS


//STL
/*
STL(标准模板库)
从广义上分为:容器(container)、算法(aigorithm)、迭代器(iterator)

1.容器:
根据数据在容器中的排列特性分为序列式容器和关联式容器:
(1)序列式容器强调值得排序，序列式容器中得每个元素均有固定位置，除非用删除或插入的操作改变这个位置
(2)关联式容器是非线性的树结构，更准确来说是二叉树结构。
各元素之间没有严格物理上的顺序关系，也就是说元素在容器中并没有保存元素置入时的逻辑顺序。
关联式容器特点:在值中选择一个值作为关键字key，这个关键字对值起索引的作用，方便查找。

2.算法:
算法分为:
(1)质变算法:是指运算过程中会更改区间内的元素的内容，例如:拷贝、替换、删除等
(2)非质变算法:是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻极值等

3.迭代器:
迭代器的种类:
输入迭代器               提供对数据的只读访问                  只读，支持++、==、!=

输出迭代器               提供对数据的只写访问                  只写，支持++

前向迭代器               提供读写操作，并且能向前推进迭代器    读写，支持++、==、!=

双向迭代器               提供读写操作，并能向前和向后操作      读写，支持++、--

随机访问迭代器           提供读写操作，并能以跳跃的方式访问    读写，支持++、--、[n]、
                         容器的任意数据，是功能最强的迭代器    <、<=、>、>=
*/



/*
STL提供了六大组件:
容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器
(1)容器:
各种数据结构，用来存放数据。从实现角度来看，STL容器是一种class templats(类模板)

(2)算法:
各种常用的算法。从实现角度来看，STL算法是一种function template(函数模板)

(3)迭代器:
扮演了容器与算法之间的胶合剂，共有五种类型。
从实现角度来看，迭代器是一种将operator*,operator->,operator++,operator--等指针相关操作予以重载的class template。
所有STL容器都附带自己专属的迭代器，只有容器的设计者才知道如何遍历自己的元素。原生指针也是一种迭代器。

(4)仿函数:
行为类似函数，可作为算法的某种策略。
从实现角度来看，仿函数是一种重载了operator()的class或class template

(5)适配器(配接器)
一种用来修饰容器或仿函数或迭代器接口的东西

(6)空间配置器:
负责空间的配置与管理。从实现角度来看，配置器是一个实现了动态空间配置、空间管理、空间释放的class template

STL六大组件的交互关系:
容器通过空间配置器取得数据存储空间，算法通过迭代器存储容器中的内容，仿函数可以协助算法完成不同策略的变化，适配器可以修饰仿函数。
*/














//初识
//#include<iostream>
//#include<vector>
//#include<algorithm>//标准算法头文件
//using namespace std;
//void myPrint(int val)
//{
//    cout << val << endl;
//}
//void test1()
//{
//    int arr[5] = { 1,2,3,4,5 };
//    int* p = arr;//原生指针也是迭代器
//    for (int i = 0; i < 5; i++)
//    {
//        cout << *(p++) << endl;
//    }
//}
//void test2()
//{
//    vector<int>a;//创建一个vector容器，容器中存放的元素类型是int类型
//    a.push_back(10);//插入元素
//    a.push_back(20);
//    a.push_back(30);
//    vector<int>::iterator it = a.begin();//a.begin起始迭代器 指向容器中的第一个数据
//    vector<int>::iterator itend = a.end();//a.end结束迭代器 指向容器的是容器中最后一个元素的下一个位置
//    //第一种遍历
//    /*while (it != itend)
//    {
//        cout << *it << endl;
//        it++;
//    }*/
//    //第二种遍历
//    /*for (; it != itend; it++)
//    {
//        cout << *it << endl;
//    }*/
//    //第三种遍历
//    for_each(a.begin(), a.end(), myPrint);//提供回调函数
//}
//int main()
//{
//    //test1();
//    test2();
//    return 0;
//}



//#include<iostream>
//#include<vector>
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
//int main()
//{
//    vector<Person> p;
//    Person p1("Tom", 99);
//    Person p2("Jerry", 1);
//    Person p3("GG_Bond", 18);
//    p.push_back(p1);
//    p.push_back(p2);
//    p.push_back(p3);
//
//    vector<Person*> a;
//    a.push_back(&p1);
//    a.push_back(&p2);
//    a.push_back(&p3);
//    //自定义类型
//    for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
//    {
//        cout << (*it).m_name << endl;
//        cout << it->m_age << endl;
//    }
//    //自定义类型指针
//    for (vector<Person*>::iterator it = a.begin(); it != a.end(); it++)
//    {
//        cout << (**it).m_name << endl;
//        cout << (*it)->m_age << endl;
//    }
//    return 0;
//}



//容器嵌套
//#include<iostream>
//#include<vector>
//using namespace std;
//void test()
//{
//    vector<vector<int>>v;
//    vector<int>v1;
//    vector<int>v2;
//    vector<int>v3;
//    //在小容器中放入数据
//    for (int i = 0; i < 10; i++)
//    {
//        v1.push_back(i + 1);
//        v2.push_back(i + 10);
//        v3.push_back(i + 100);
//    }
//    //将小容器放入大容器
//    v.push_back(v1);
//    v.push_back(v2);
//    v.push_back(v3);
//    //遍历大容器
//    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        //大容器解引用为小容器
//        for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); its++)
//        {
//            cout << *its << " ";
//        }
//        cout << endl;
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}


































                                                              //容器




                                                             //string容器
/*
1.string封装了char*,管理这个字符串，是一个char*型的容器

2.string封装了很多成员方法
查找find、拷贝copy、删除delete、替换replace、插入insert

3.不用考虑内存释放和越界
*/




//string构造函数
/*
string()://创建一个空的字符串
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s)://使用字符串初始化
string(int n,char c);//使用n个字符c初始化
*/



//string基本赋值操作
/*
string& operstor=(const char* s);//const char*类型字符串赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串

string& assign(const char* s);//把字符串s赋值给当前的字符串
string& assign(const char* s,int n);//把字符串s的前n个字符赋值给当前的字符串
string& assign(const string& s);//把字符串s赋值给当前字符串
string& assign(int n,char c);//用n个字符c赋值给当前的字符串
string& assign(const string& s,int start,int n);//将s从start位置开始n个字符赋值给字符串
*/



//string存取字符操作
/*
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符

[]和at的区别:
[]越界访问，程序直接崩溃;at越界访问，抛出out_of_range异常
注意:
为了修改string字符串的内容，下标操作符[]和at都会返回字符的引用。但当字符串的内存重新分配之后，可能发生错误。
*/



//string拼接操作
/*
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符

string& append(const char* s);//把字符串s连接到当前字符串结尾
string& append(const char* s,int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string& s);//把字符串s连接到当前字符串结尾
string& append(const string& s,int pos,int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n,char c);//在当前字符串结尾添加n个字符c
*/



//string查找和替换
/*
find从左向右找
int find(const string& str,pos = 0)const;//从pos开始查找str第一次出现的位置
int find(const char* s,pos = 0)const;//从pos开始查找s第一次出现的位置
int find(const char* s,pos,int n)const;//从pos位置查找s的前n个字符第一次出现的位置
int find(const char c,pos = 0)const;//查找字符c第一次出现的位置

rfind从右向左找
int rfind(const string& str,pos = npos)const;//从pos开始查找str最后一次出现的位置
int rfind(const char* s,pos = npos)const;//从pos开始查找s最后一次出现的位置
int rfind(const char* s,pos,int n);//从pos查找s的前n个字符最后一次出现的位置
int rfind(const char c,pos = 0)const;//查找字符c最后一次出现的位置

string& replace(int pos,int n,const string& str);//替换从pos开始的n个字符为字符串str
string& replace(int pos,int n,const char* s);//替换从pos开始的n个字符为字符串s
*/



//string比较操作
/*
compare函数在>时返回1，在<时返回-1，在==时返回0(区分大小写)
int compare(const string& s)const;
int compare(const char* s)const;
*/



//string子串
//string substr(int pos = 0,int n = npos)const;//返回由pos开始的n个字符组成的字符串



//string插入和删除操作
/*
string& insert(pos,const char* s);//在pos位置插入字符串s
string& insert(pos,const string& str);//在pos位置插入字符串str
string& insert(pos,int n,char c);//在指定pos位置插入n个字符c
string& erase(pos,int n = npos);//删除从pos开始的n个字符
*/



//string和c_style字符串转换
/*
const char* 可以隐式类型转换为string
string不可以隐式类型转换为const char*
*/
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    const char* str = "abcd";
//    //const char* 转为string
//    string s(str);
//    //string转为const char*
//    const char* str2 = s.c_str();
//    return 0;
//}








//案例1
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string email = "BJY811@outlook.com";
//    int pos = email.find("@");
//    string username = email.substr(0, pos);
//    cout << username << endl;
//    return 0;
//}



//案例2
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void test()
//{
//    string str = "www.itcast.com.cn";
//    vector<string> v;//将str分为www itcast com cn放入vector中
//    int start = 0;
//    int pos = -1;
//    while (true)
//    {
//        pos = str.find(".",start);
//        if (pos == -1)
//        {
//            string tempstr = str.substr(start, str.size() - start);
//            v.push_back(tempstr);
//            break;
//        }
//        string tempstr = str.substr(start, pos - start);
//        v.push_back(tempstr);
//        start = pos + 1;
//    }
//    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << *it << " ";
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}



//案例3
//#include<iostream>
//#include<string>
//#include<cctype>
//using namespace std;
//int main()
//{
//    string str = "abCDeFg";
//    //str.size() 在容器说明中被定义为unsigned int类型,而i是int 类型,进行强制类型转换避免警告 
//    for (int i = 0; i < (int)str.size(); i++)
//    {
//        //转成大写
//        str[i] = toupper(str[i]);
//        //转成小写
//        str[i] = tolower(str[i]);
//    }
//    cout << str << endl;
//    return 0;
//}



















                                                           //vector容器
/*
vector维护的是一个线性空间，所以不论元素的型别如何，普通指针都可以作为vector的迭代器。
vector提供的是随机访问迭代器。
*/



//vector的数据结构
/*
一个vector的容量永远大于或等于其大小，一旦容量等于大小便是满载，下次再有新增元素，整个vector就得另觅居所。
注意:
所谓动态增加大小，并不是在原空间之后续接新空间(因为无法保证原空间之后尚有可配置的空间)，而是找一块更大的内存空间，然后将原数据拷贝
到新空间，并释放原空间。因此，对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都无效了。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//        cout << v.capacity() << " ";//v.capacity()容器的容量
//    }
//    //1 2 3 4 6 6 9 9 9 13
//    return 0;
//}



//vector构造函数
/*
vector<T>v;//采用模板实现类实现，默认构造函数
vector(v.begin(),v.end());//将v[begin(),end())区间中的元素拷贝给自身
vector(int n,elem);//构造函数将n个elem拷贝给自身
vector (const vector& vec)//拷贝构造函数
*/



//vector常用赋值操作
/*
assign(v.begin(),v.end());//将v[begin(),end())区间中的元素拷贝赋值给自身
assign(int n,elem);//将n个elem拷贝赋值给自身
vector& operator=(const vector &vec);//重载等号操作符
swap(vector &vec);//将vec与本身元素互换——指针交换
*/



//vector大小操作
/*
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的大小为num。若容器边长，则以默认填充新位置。若容器变短，则末尾超出容器长度的元素被删除
resize(int num,elem);//重新指定容器的大小为num。若容器边长，则以elem值填充新位置。若容器变短，则末尾超出容器长度的元素被删除
capacity();//容器的容量
reserve(int len);//容器预留了len个元素长度，预留位置不初始化，元素不可访问
*/



//vector数据存取操作
/*
at(int index);//返回索引index所指的数据，若index越界，则抛出out_of_range异常
operator[];//返回索引index所指的数据，越界时，程序直接崩溃
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
*/



//vector插入和删除操作
/*
insert(const_iterator pos,int count,elem);//在迭代器指向位置pos插入count个元素elem
push_back(elem);//尾插
pop_back();//尾删
erase(const_iterator start,const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器所指向的那个元素
clear();//删除容器中的所有元素
*/



//案例1:巧用swap收缩内存
//#include<iostream>
//#include<vector>
//using namespace std;
//void test()
//{
//    vector<int>v;
//    for (int i = 0; i < 100000; i++)
//    {
//        v.push_back(i);
//    }
//    cout << v.capacity() << endl;//138255
//    cout << v.size() << endl;//100000
//    v.resize(3);
//    cout << v.capacity() << endl;//138255
//    //已开辟空间大小不变，造成空间浪费
//    cout << v.size() << endl;//3
//
//    vector<int>(v).swap(v);
//    //利用拷贝构造函数传参v创建匿名对象(匿名对象使用完后由系统收回空间)，匿名对象的容量由当时v的元素个数决定，再进行交换
//    cout << v.capacity() << endl;//3
//    cout << v.size() << endl;//3
//}
//int main()
//{
//    test();
//    return 0;
//}



//案例2:巧用reserve预留空间
//#include<iostream>
//#include<vector>
//using namespace std;
//void test()
//{
//    vector<int>v;
//    //v.reserve(100000);
//    int* p = NULL;
//    int num = 0;
//    for (int i = 0; i < 100000; i++)
//    {
//        v.push_back(i);
//        if (p != &v[0])
//        {
//            p = &v[0];
//            num++;//计算找了多少次内存空间  30次/1次
//        }
//    }
//    cout << num << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}



//案例3
//#include<iostream>
//#include<vector>
//using namespace std;
//void test()
//{
//    vector<int>v;
//    for (int i = 0; i < 5; i++)
//    {
//        v.push_back(i + 1);
//    }
//    //逆序遍历
//    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//    //vector迭代器是随机访问迭代器，支持跳跃访问 
//    vector<int>::iterator itbegin = v.begin();
//    itbegin += 3;
//    cout << *itbegin << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}

















                                                             //deque容器
/*
deque是一种双向开口的连续线性空间。
即可以在头尾两端分别做元素的插入和删除的操作。
注意:
deque没有容量的概念，因为它是动态的以分段连续空间组合而成，随时可以增加一段新的空间并连续起来。
*/


//deque构造函数
/*
deque<T>deqT;//默认构造形式
deque(begin,end);//将[begin,end)区间中的元素拷贝给自身
deque(int n,elem);//构造函数将n个elem拷贝给自身
deque(const deque& deq);//拷贝构造函数
*/



//deque赋值操作
/*
assign(begin,end);//将区间[begin,end)中的数据拷贝赋值给自身
assign(int n,elem);//将n个elem拷贝赋值给自身
deque operator=(const deque& deq);//重载等号运算符
swap(deq);//将deq的元素与自身元素互换
*/



//deque大小操作
/*
deque.size();//返回容器中的元素的个数
deque.empty();//判断容器是否为空
deque.resize(int num);//重新指定容器的长度为num。若容器变长，则以默认值填充新位置。若容器变短，末尾超出容器长度的元素被删除。
deque.resize(int num,elem);///重新指定容器的长度为num。若容器变长，则以elem值填充新位置。若容器变短，末尾超出容器长度的元素被删除。
*/



//deque双端插入和删除操作
/*
push_back(elem);//在容器的尾部插入元素elem
push_front(elem);//在容器的头部插入数据elem
pop.back();//删除容器的最后一个数据
pop_front();//删除容器的第一个数据
*/



//deque数据存取
/*
at(int index);//返回索引index所指的元素。若index越界，抛出out_of_range异常。
operator[];//返回索引index所指的元素，若index越界，程序直接崩溃。
front();//返回第一个数据
back();//返回最后一个数据
*/



//deque插入操作
/*
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,int n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,begin,end);//在pos位置插入[begin,end)区间的数据，无返回值
*/



//deque删除操作
/*
clear();//删除容器中的所有元素
erase(begin,end);//删除[begin,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置
*/





//案例
//#include<iostream>
//#include<vector>
//#include<deque>
//#include<string>
//#include<algorithm>
//#include<ctime>
//using namespace std;
//class Player
//{
//public:
//    Player(string name,int score)
//    {
//        this->m_name = name;
//        this->m_score = score;
//    }
//    string m_name;//姓名
//    int m_score;//平均分
//};
//void createPlayer(vector<Player>& v)
//{
//    string nameseed = "ABCDE";
//    for (int i = 0; i < 5; i++)
//    {
//        string name = "选手";
//        name += nameseed[i];
//        int score = 0;
//        Player player(name, score);
//        v.push_back(player);
//    }
//}
//void setscore(vector<Player>& v)
//{
//    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        deque<int>deq;//存放分数的容器
//        for (int i = 0; i < 10; i++)//十个评委打分
//        {
//            int score = rand() % 41 + 60;//分数范围60~100
//            deq.push_back(score);
//        }
//
//        //排序
//        sort(deq.begin(), deq.end());//默认从小到大排序
//
//        //去除最高和最低分
//        deq.pop_back();
//        deq.pop_front();
//
//        //计算平均分
//        int sum = 0;//总分
//        for (deque<int>::iterator dit = deq.begin(); dit != deq.end(); dit++)
//        {
//            sum += *dit;
//        }
//        int avg = sum / deq.size();
//        it->m_score = avg;
//    }
//}
//void showscore(vector<Player>& v)
//{
//    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << "姓名:" << it->m_name << endl;
//        cout << "平均分数:" << it->m_score << endl;
//        cout << endl;
//    }
//}
//int main()
//{
//    //设置随机数种子
//    srand((unsigned int)time(NULL));
//    //创建五名选手
//    vector<Player>v;
//    createPlayer(v);
//    //评委打分
//    setscore(v);
//    //显示平均分
//    showscore(v);
//    return 0;
//}



















                                                            //stack栈容器
/*
stack是一种先进后出的数据结构，它只有一个出口。
stack容器允许新增元素，移除元素，取得栈顶元素。但是除了最顶端外，没有任何其他地方可以存取stack的元素。
stack没有迭代器，不允许有遍历行为。
*/



//stack构造函数
/*
stack<T>sT;//stack采用类模板实现，stack对象的默认构造形式
stack(const stack& stk);//拷贝构造函数
*/



//stack赋值操作
/*
stack& operator=(const stack& stk);//重载等号操作符
*/



//stack数据存取操作
/*
push(elem);//向栈顶添加元素elem
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
*/



//stack大小操作
/*
empty();//判断stack是否为空
size();//返回stack的大小
*/



















//queue队列容器
/*
queue是一种先进先出的数据结构，其有两个出口。
queue容器允许从一端新增元素，从另一端移除元素。
只有queue队头队尾的元素才可以被外界访问，且其没有迭代器，不提供遍历功能。
*/



//queue构造函数
/*
queue<T>que;//queue采用类模板实现，queue对象的默认构造形式
queue(const queue& que);//拷贝构造函数
*/



//queue存取、插入和删除操作
/*
push(elem);//往队尾添加元素elem
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素
*/



//queue赋值操作
/*
queue operator=(const queue& que);//重载等号运算符
*/



//queue大小操作
/*
empty();//判断队列是否为空
size();//返回队列的大小
*/
















//list容器
/*
list容器是一个双向循环链表。
链表是一中物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑结构是通过链表中的指针链接次序实现的。链表由一系列结点
(链表中的每一个元素被称为结点)组成，结点可以在运行时动态生成。每个结点包括两个部分:一个是存储数据元素的数据域，另一个是
存储下一个结点地址的指针域。
list每次插入或者删除一个元素，就配置或释放一个元素的空间。list对空间的运用有绝对的精准。
而且，对于任何位置的元素插入或移除。list永远都为常数时间。
*/


//list特点:
/*
1.采用动态存储分配，不会造成内存浪费
2.链表执行插入和删除操作十分方便，不需要移动大量元素，修改指针即可。
3.链表灵活，但空间和时间的额外耗费较大。
4.与vector不同，插入和删除操作都不会造成原有list迭代器的失效。(不需全部重新分配空间)
*/





//list构造函数
/*
list<T>L;//list采用类模板实现，list对象的默认构造形式
list(begin,end);//构造函数将区间[begin,end)中的元素拷贝给其自身
list(int n,elem);//构造函数将n个elem拷贝给自身
list(const list& L);//拷贝构造函数
*/



//list数据元素的插入和删除操作
/*
push_back(elem);//尾插elem
pop_back();//尾删
push_front(elem);//头插elem
pop_front();//头删
insert(pos,elem);//在pos位置插入elem元素的拷贝，返回新数据的位置
insert(pos,int n,elem);//在pos位置插入n个elem数据，无返回值
insert(pos,begin,end);//在pos位置插入[begin,end)区间的数据，无返回值
clear();//移除容器中的所有数据
erase(begin,end);//删除[begin,end)区间的数据，返回下一个数据的位置
erase(pos);//删除pos位置的数据，返回下一个数据的位置
remove(elem);//删除容器中所有与elem值匹配的元素(若利用remove删除自定义数据类型，需要重载==)
*/



//list大小操作
/*
size();//返回容器中的元素个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num。若容器变长，则以默认值填充新位置。若容器变短，则末尾超出容器长度的元素被删除
resize(int num,elem);//重新指定容器的长度为num。若容器变长，则以elem值填充新位置。若容器变短，则末尾超出容器长度的元素被删除
*/



//list赋值操作
/*
assign(begin,end);//将[begin,end)区间中的数据拷贝赋值给本身
assign(int n,elem);//将n个elem拷贝赋值给自身
list& operator=(const list& L);//重载等号操作符
swap(L);//将L的元素与自身交换
*/



//list数据的存取
/*
front();//返回第一个元素
back();//返回最后一个元素
*/



//list反转排序
/*
reverse();//反转链表
sort();//链表排序，默认从小到大

注意:
1.对于自定义类型必须指定排序规则
2.只有容器的迭代器支持随机访问的情况下，才可以使用系统提标准算法
*/


















//set、multiset容器

//set容器
/*
set的所有元素会根据元素的键值自动排序(默认从小到大)。
set的元素既是键值又是实值。set不允许两个元素有相同的键值。
不可以通过迭代器修改set元素的值，set的iterator是一种const_iterator。
*/

//multiset容器
/*
multiset的用法与set基本一致，唯一差别在于multiset允许键值重复。
*/





//常用API

//set构造函数
/*
set<T>st;//set默认构造函数
multiset<T>mst;//multiset默认构造函数
set(const set& st);//拷贝构造函数
*/



//set赋值操作
/*
set& operator=(const set& st);//重载等号运算符
swap(st);//交换两个集合容器
*/



//set大小操作
/*
size();//返回容器中的元素个数
empty();//判断容器是否为空
*/



//set插入和删除操作
/*
insert(elem);//在容器中插入元素elem
clear();//清除容器中所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(begin,end);//删除区间[begin,end)的所有元素，返回下一个元素的迭代器
erase(elem);//删除容器中值为elem的元素
*/



//set查找操作
/*
find(key);//查找key是否存在。若存在，返回该键的元素的迭代器。若不存在，返回end();
count(key);//查找key的元素个数
lower_bound(keyelem);//返回第一个key>=keyelem元素的迭代器,若不存在，返回end();
upper_bound(keyelem);//返回第一个key>keyelem元素的迭代器,若不存在，返回end();
equal_range(keyelem);//返回容器中key与keyelem相等的上下限的两个迭代器(即返回lower_bound和upper_bound),若不存在，返回set.end();
*/





//案例1:
//#include<iostream>
//#include<set>
//using namespace std;
//void test1(set<int>& s)
//{
//    set<int>::iterator pos = s.find(30);
//    if (pos != s.end())
//    {
//        cout << "找到了元素:" << *pos << endl;
//    }
//    else
//    {
//        cout << "未找到该元素" << endl;
//    }
//}
//void test2(set<int>& s)
//{
//    //对于set而言，count的结果要么为0要么为1(不允许两个元素有相同的键值)
//    cout << "key为40的个数为:" << s.count(40) << endl;
//}
//void test3(set<int>& s)
//{
//    set<int>::iterator it = s.lower_bound(30);
//    if (it != s.end())
//    {
//        cout << *it << endl;//30(已经进行排序)
//    }
//
//    set<int>::iterator its = s.upper_bound(30);
//    if (its != s.end())
//    {
//        cout << *its << endl;//40
//    }
//
//    pair<set<int>::iterator,set<int>::iterator>ret = s.equal_range(30);//返回对组
//    if (ret.first != s.end())
//    {
//        cout << "lower_bound的值为:" << *ret.first << endl;
//    }
//    if (ret.second != s.end())
//    {
//        cout << "upper_bound的值为:" << *ret.second << endl;
//    }
//}
//int main()
//{
//    set<int>s;
//    s.insert(10);
//    s.insert(40);
//    s.insert(20);
//    s.insert(50);
//    s.insert(30);
//    //test1(s);
//    //test2(s);
//    test3(s);
//    return 0;
//}





//案例2:pair对组的创建
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    //1.
//    pair<string,int>p1("Tom", 18);
//    cout << "姓名:" << p1.first << endl;
//    cout << "年龄:" << p1.second << endl;
//    //2.
//    pair<string, int>p2 = make_pair("Jerry", 1);
//    cout << "姓名:" << p2.first << endl;
//    cout << "年龄:" << p2.second << endl;
//    return 0;
//}





//案例3:set排序从大到小
//#include<iostream>
//#include<set>
//using namespace std;
//class mycompareint//仿函数
//{
//public:
//    bool operator()(int a,int b)const//const一定要加
//    {
//        return a > b;
//    }
//};
//void test()
//{
//    set<int, mycompareint>s;
//    s.insert(10);
//    s.insert(50);
//    s.insert(30);
//    s.insert(40);
//    s.insert(20);
//    for (set<int, mycompareint>::iterator it = s.begin(); it != s.end(); it++)
//    {
//        cout << *it << " ";
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}





//案例4:对于自定义数据类型
//#include<iostream>
//#include<set>
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
//class mycompareperson
//{
//public:
//    bool operator()(const Person& p1, const Person& p2)const
//    {
//        //按照年龄从小到大
//        return p1.m_age < p2.m_age;
//    }
//};
//int main()
//{
//    set<Person,mycompareperson>s;
//    Person p1("aaa", 1);
//    Person p2("bbb", 2);
//    Person p3("ccc", 3);
//    Person p4("ddd", 4);
//    Person p5("eee", 5);
//    s.insert(p1);
//    s.insert(p2);
//    s.insert(p3);
//    s.insert(p4);
//    s.insert(p5);
//    for (set<Person, mycompareperson>::iterator it = s.begin(); it != s.end(); it++)
//    {
//        cout << "姓名:" << (*it).m_name << endl;
//        cout << "年龄:" << it->m_age << endl;
//    }
//    return 0;
//}




















                                                   //map、multimap容器(底层红黑树)
/*
map的所有元素根据元素的键值自动排序。
map的所有元素都是pair,同时拥有键值和实值。其pair的第一元素被视为键值。第二元素被视为实值。map不允许两个元素有相同的键值。
不可通过迭代器修改map的键值，但可以修改实值。
multimap和map的操作类似，但multimap键值可以重复。
*/





//常用API

//map构造函数
/*
map<T,T>m;//map默认构造函数
map(const map& m);//拷贝构造函数
*/



//map赋值操作
/*
msp& operator=(const map& m);//重载等号运算符
swap(m);//交换两个集合容器
*/



//map大小操作
/*
size();//返回容器中元素的个数
empty();//判断容器是否为空
*/



//map插入操作
/*
1.
map.insert(……)；//往容器中插入元素。返回pair<iterator,bool>

2.m.insert(pair<string,int>("Tom",18));//通过pair的方式插入

3.m.insert(make_pair("Jerry",1));通过pair的方式插入

4.m.insert(map<string,int>::value_type(GG_Bond",18));//通过value_type的方式插入

5.m[1]="haha";//通过数组的方式插入
*/



//map删除操作
/*
clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(begin,end);//删除[begin,end)区间的所有元素，返回下一个元素的迭代器
erase(keyelem);//删除容器中key为keyelem的对组
*/



//map查找操作
/*
find(key);//查找key是否存在，若存在，返回该键的元素的迭代器。若不存在，返回end();
count();//返回容器中key为keyelem的对组的个数。对于map来说，要么为0，要么为1
lower_bound(keyelem);//返回第一个key>=keyelem元素的迭代器,若不存在，返回end();
upper_bound(keyelem);//返回第一个key>keyelem元素的迭代器,若不存在，返回end();
equal_range(keyelem);//返回key与keyelem相等的上下限的两个迭代器,若不存在，返回end();
*/





//案例1:从大到小排序
//#include<iostream>
//#include<map>
//using namespace std;
//class mycompare
//{
//public:
//    bool operator()(int a, int b)const
//    {
//        return a > b;
//    }
//};
//void test()
//{
//    map<int, int, mycompare>m;
//    m.insert(pair<int, int>(1, 10));
//    m.insert(make_pair(2, 20));
//    m.insert(map<int, int>::value_type(3, 30));
//    m[4] = 40;
//    for (map<int, int, mycompare>::iterator it = m.begin(); it != m.end(); it++)
//    {
//        cout << it->first << endl;
//        cout << it->second << endl;
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}





//案例2:员工分组
//#include<iostream>
//#include<vector>
//#include<string>
//#include<map>
//#include<ctime>
//enum
//{
//    CAIWU,
//    RENSHI,
//    YANFA
//};
//using namespace std;
//class Worker
//{
//public:
//    string m_name;
//    int m_money = 0;
//};
//void createworker(vector<Worker>& v)
//{
//    string nameseed = "ABCDE";
//    for (int i = 0; i < 5; i++)
//    {
//        Worker w;
//        w.m_name = "员工";
//        w.m_name += nameseed[i];
//        w.m_money = rand() % 10000 + 10000;
//        v.push_back(w);
//    }
//
//}
//void setgroup(vector<Worker>& v,multimap<int ,Worker>& m)
//{
//    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        //随机产生部门编号
//        int ID = rand() % 3;
//        m.insert(make_pair(ID, *it));
//    }
//}
//void Print(multimap<int, Worker>& m, int bumen)
//{
//    multimap<int, Worker>::iterator pos = m.find(bumen);//找到该部门第一个元素的迭代器
//    int num = m.count(bumen);//部门人数
//    for (int i = 0; pos != m.end() && i < num; pos++, i++)
//    {
//        cout << "姓名为:" << pos->second.m_name << endl;
//        cout << "薪资为:" << pos->second.m_money << endl;
//    }
//}
//void showworker(multimap<int, Worker>& m)
//{
//    cout << "财务部门员工信息如下:" << endl;
//    Print(m, CAIWU);
//    cout << "人事部门员工信息如下:" << endl;
//    Print(m, RENSHI);
//    cout << "研发部门员工信息如下:" << endl;
//    Print(m, YANFA);
//}
//int main()
//{
//    //随机数种子
//    srand((unsigned int)time(NULL));
//    vector<Worker>v;
//    //创建五名员工
//    createworker(v);
//    //员工分组
//    multimap<int, Worker>m;
//    setgroup(v, m);
//    //分部门显示员工
//    showworker(m);
//    return 0;
//}




