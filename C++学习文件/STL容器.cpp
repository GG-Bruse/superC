#define _CRT_SECURE_NO_WARNINGS


//STL
/*
STL(��׼ģ���)
�ӹ����Ϸ�Ϊ:����(container)���㷨(aigorithm)��������(iterator)

1.����:
���������������е��������Է�Ϊ����ʽ�����͹���ʽ����:
(1)����ʽ����ǿ��ֵ����������ʽ�����е�ÿ��Ԫ�ؾ��й̶�λ�ã�������ɾ�������Ĳ����ı����λ��
(2)����ʽ�����Ƿ����Ե����ṹ����׼ȷ��˵�Ƕ������ṹ��
��Ԫ��֮��û���ϸ������ϵ�˳���ϵ��Ҳ����˵Ԫ���������в�û�б���Ԫ������ʱ���߼�˳��
����ʽ�����ص�:��ֵ��ѡ��һ��ֵ��Ϊ�ؼ���key������ؼ��ֶ�ֵ�����������ã�������ҡ�

2.�㷨:
�㷨��Ϊ:
(1)�ʱ��㷨:��ָ��������л���������ڵ�Ԫ�ص����ݣ�����:�������滻��ɾ����
(2)���ʱ��㷨:��ָ��������в�����������ڵ�Ԫ�����ݣ�������ҡ�������������Ѱ��ֵ��

3.������:
������������:
���������               �ṩ�����ݵ�ֻ������                  ֻ����֧��++��==��!=

���������               �ṩ�����ݵ�ֻд����                  ֻд��֧��++

ǰ�������               �ṩ��д��������������ǰ�ƽ�������    ��д��֧��++��==��!=

˫�������               �ṩ��д������������ǰ��������      ��д��֧��++��--

������ʵ�����           �ṩ��д��������������Ծ�ķ�ʽ����    ��д��֧��++��--��[n]��
                         �������������ݣ��ǹ�����ǿ�ĵ�����    <��<=��>��>=
*/



/*
STL�ṩ���������:
�������㷨�����������º�����������(�����)���ռ�������
(1)����:
�������ݽṹ������������ݡ���ʵ�ֽǶ�������STL������һ��class templats(��ģ��)

(2)�㷨:
���ֳ��õ��㷨����ʵ�ֽǶ�������STL�㷨��һ��function template(����ģ��)

(3)������:
�������������㷨֮��Ľ��ϼ��������������͡�
��ʵ�ֽǶ���������������һ�ֽ�operator*,operator->,operator++,operator--��ָ����ز����������ص�class template��
����STL�����������Լ�ר���ĵ�������ֻ������������߲�֪����α����Լ���Ԫ�ء�ԭ��ָ��Ҳ��һ�ֵ�������

(4)�º���:
��Ϊ���ƺ���������Ϊ�㷨��ĳ�ֲ��ԡ�
��ʵ�ֽǶ��������º�����һ��������operator()��class��class template

(5)������(�����)
һ����������������º�����������ӿڵĶ���

(6)�ռ�������:
����ռ�������������ʵ�ֽǶ���������������һ��ʵ���˶�̬�ռ����á��ռ�����ռ��ͷŵ�class template

STL��������Ľ�����ϵ:
����ͨ���ռ�������ȡ�����ݴ洢�ռ䣬�㷨ͨ���������洢�����е����ݣ��º�������Э���㷨��ɲ�ͬ���Եı仯���������������ηº�����
*/














//��ʶ
//#include<iostream>
//#include<vector>
//#include<algorithm>//��׼�㷨ͷ�ļ�
//using namespace std;
//void myPrint(int val)
//{
//    cout << val << endl;
//}
//void test1()
//{
//    int arr[5] = { 1,2,3,4,5 };
//    int* p = arr;//ԭ��ָ��Ҳ�ǵ�����
//    for (int i = 0; i < 5; i++)
//    {
//        cout << *(p++) << endl;
//    }
//}
//void test2()
//{
//    vector<int>a;//����һ��vector�����������д�ŵ�Ԫ��������int����
//    a.push_back(10);//����Ԫ��
//    a.push_back(20);
//    a.push_back(30);
//    vector<int>::iterator it = a.begin();//a.begin��ʼ������ ָ�������еĵ�һ������
//    vector<int>::iterator itend = a.end();//a.end���������� ָ�������������������һ��Ԫ�ص���һ��λ��
//    //��һ�ֱ���
//    /*while (it != itend)
//    {
//        cout << *it << endl;
//        it++;
//    }*/
//    //�ڶ��ֱ���
//    /*for (; it != itend; it++)
//    {
//        cout << *it << endl;
//    }*/
//    //�����ֱ���
//    for_each(a.begin(), a.end(), myPrint);//�ṩ�ص�����
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
//    //�Զ�������
//    for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
//    {
//        cout << (*it).m_name << endl;
//        cout << it->m_age << endl;
//    }
//    //�Զ�������ָ��
//    for (vector<Person*>::iterator it = a.begin(); it != a.end(); it++)
//    {
//        cout << (**it).m_name << endl;
//        cout << (*it)->m_age << endl;
//    }
//    return 0;
//}



//����Ƕ��
//#include<iostream>
//#include<vector>
//using namespace std;
//void test()
//{
//    vector<vector<int>>v;
//    vector<int>v1;
//    vector<int>v2;
//    vector<int>v3;
//    //��С�����з�������
//    for (int i = 0; i < 10; i++)
//    {
//        v1.push_back(i + 1);
//        v2.push_back(i + 10);
//        v3.push_back(i + 100);
//    }
//    //��С�������������
//    v.push_back(v1);
//    v.push_back(v2);
//    v.push_back(v3);
//    //����������
//    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        //������������ΪС����
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


































                                                              //����




                                                             //string����
/*
1.string��װ��char*,��������ַ�������һ��char*�͵�����

2.string��װ�˺ܶ��Ա����
����find������copy��ɾ��delete���滻replace������insert

3.���ÿ����ڴ��ͷź�Խ��
*/




//string���캯��
/*
string()://����һ���յ��ַ���
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s)://ʹ���ַ�����ʼ��
string(int n,char c);//ʹ��n���ַ�c��ʼ��
*/



//string������ֵ����
/*
string& operstor=(const char* s);//const char*�����ַ�����ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���

string& assign(const char* s);//���ַ���s��ֵ����ǰ���ַ���
string& assign(const char* s,int n);//���ַ���s��ǰn���ַ���ֵ����ǰ���ַ���
string& assign(const string& s);//���ַ���s��ֵ����ǰ�ַ���
string& assign(int n,char c);//��n���ַ�c��ֵ����ǰ���ַ���
string& assign(const string& s,int start,int n);//��s��startλ�ÿ�ʼn���ַ���ֵ���ַ���
*/



//string��ȡ�ַ�����
/*
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�

[]��at������:
[]Խ����ʣ�����ֱ�ӱ���;atԽ����ʣ��׳�out_of_range�쳣
ע��:
Ϊ���޸�string�ַ��������ݣ��±������[]��at���᷵���ַ������á������ַ������ڴ����·���֮�󣬿��ܷ�������
*/



//stringƴ�Ӳ���
/*
string& operator+=(const string& str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������

string& append(const char* s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char* s,int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string& s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const string& s,int pos,int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n,char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
*/



//string���Һ��滻
/*
find����������
int find(const string& str,pos = 0)const;//��pos��ʼ����str��һ�γ��ֵ�λ��
int find(const char* s,pos = 0)const;//��pos��ʼ����s��һ�γ��ֵ�λ��
int find(const char* s,pos,int n)const;//��posλ�ò���s��ǰn���ַ���һ�γ��ֵ�λ��
int find(const char c,pos = 0)const;//�����ַ�c��һ�γ��ֵ�λ��

rfind����������
int rfind(const string& str,pos = npos)const;//��pos��ʼ����str���һ�γ��ֵ�λ��
int rfind(const char* s,pos = npos)const;//��pos��ʼ����s���һ�γ��ֵ�λ��
int rfind(const char* s,pos,int n);//��pos����s��ǰn���ַ����һ�γ��ֵ�λ��
int rfind(const char c,pos = 0)const;//�����ַ�c���һ�γ��ֵ�λ��

string& replace(int pos,int n,const string& str);//�滻��pos��ʼ��n���ַ�Ϊ�ַ���str
string& replace(int pos,int n,const char* s);//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/



//string�Ƚϲ���
/*
compare������>ʱ����1����<ʱ����-1����==ʱ����0(���ִ�Сд)
int compare(const string& s)const;
int compare(const char* s)const;
*/



//string�Ӵ�
//string substr(int pos = 0,int n = npos)const;//������pos��ʼ��n���ַ���ɵ��ַ���



//string�����ɾ������
/*
string& insert(pos,const char* s);//��posλ�ò����ַ���s
string& insert(pos,const string& str);//��posλ�ò����ַ���str
string& insert(pos,int n,char c);//��ָ��posλ�ò���n���ַ�c
string& erase(pos,int n = npos);//ɾ����pos��ʼ��n���ַ�
*/



//string��c_style�ַ���ת��
/*
const char* ������ʽ����ת��Ϊstring
string��������ʽ����ת��Ϊconst char*
*/
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    const char* str = "abcd";
//    //const char* תΪstring
//    string s(str);
//    //stringתΪconst char*
//    const char* str2 = s.c_str();
//    return 0;
//}








//����1
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



//����2
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void test()
//{
//    string str = "www.itcast.com.cn";
//    vector<string> v;//��str��Ϊwww itcast com cn����vector��
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



//����3
//#include<iostream>
//#include<string>
//#include<cctype>
//using namespace std;
//int main()
//{
//    string str = "abCDeFg";
//    //str.size() ������˵���б�����Ϊunsigned int����,��i��int ����,����ǿ������ת�����⾯�� 
//    for (int i = 0; i < (int)str.size(); i++)
//    {
//        //ת�ɴ�д
//        str[i] = toupper(str[i]);
//        //ת��Сд
//        str[i] = tolower(str[i]);
//    }
//    cout << str << endl;
//    return 0;
//}



















                                                           //vector����
/*
vectorά������һ�����Կռ䣬���Բ���Ԫ�ص��ͱ���Σ���ָͨ�붼������Ϊvector�ĵ�������
vector�ṩ����������ʵ�������
*/



//vector�����ݽṹ
/*
һ��vector��������Զ���ڻ�������С��һ���������ڴ�С�������أ��´���������Ԫ�أ�����vector�͵����پ�����
ע��:
��ν��̬���Ӵ�С����������ԭ�ռ�֮�������¿ռ�(��Ϊ�޷���֤ԭ�ռ�֮�����п����õĿռ�)��������һ�������ڴ�ռ䣬Ȼ��ԭ���ݿ���
���¿ռ䣬���ͷ�ԭ�ռ䡣��ˣ���vector���κβ�����һ������ռ���������ã�ָ��ԭvector�����е������Ͷ���Ч�ˡ�
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
//        cout << v.capacity() << " ";//v.capacity()����������
//    }
//    //1 2 3 4 6 6 9 9 9 13
//    return 0;
//}



//vector���캯��
/*
vector<T>v;//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(),v.end());//��v[begin(),end())�����е�Ԫ�ؿ���������
vector(int n,elem);//���캯����n��elem����������
vector (const vector& vec)//�������캯��
*/



//vector���ø�ֵ����
/*
assign(v.begin(),v.end());//��v[begin(),end())�����е�Ԫ�ؿ�����ֵ������
assign(int n,elem);//��n��elem������ֵ������
vector& operator=(const vector &vec);//���صȺŲ�����
swap(vector &vec);//��vec�뱾��Ԫ�ػ�������ָ�뽻��
*/



//vector��С����
/*
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������Ĵ�СΪnum���������߳�������Ĭ�������λ�á���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
resize(int num,elem);//����ָ�������Ĵ�СΪnum���������߳�������elemֵ�����λ�á���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
capacity();//����������
reserve(int len);//����Ԥ����len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
*/



//vector���ݴ�ȡ����
/*
at(int index);//��������index��ָ�����ݣ���indexԽ�磬���׳�out_of_range�쳣
operator[];//��������index��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
front();//���������е�һ������Ԫ��
back();//�������������һ������Ԫ��
*/



//vector�����ɾ������
/*
insert(const_iterator pos,int count,elem);//�ڵ�����ָ��λ��pos����count��Ԫ��elem
push_back(elem);//β��
pop_back();//βɾ
erase(const_iterator start,const_iterator end);//ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);//ɾ����������ָ����Ǹ�Ԫ��
clear();//ɾ�������е�����Ԫ��
*/



//����1:����swap�����ڴ�
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
//    //�ѿ��ٿռ��С���䣬��ɿռ��˷�
//    cout << v.size() << endl;//3
//
//    vector<int>(v).swap(v);
//    //���ÿ������캯������v������������(��������ʹ�������ϵͳ�ջؿռ�)����������������ɵ�ʱv��Ԫ�ظ����������ٽ��н���
//    cout << v.capacity() << endl;//3
//    cout << v.size() << endl;//3
//}
//int main()
//{
//    test();
//    return 0;
//}



//����2:����reserveԤ���ռ�
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
//            num++;//�������˶��ٴ��ڴ�ռ�  30��/1��
//        }
//    }
//    cout << num << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}



//����3
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
//    //�������
//    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//    //vector��������������ʵ�������֧����Ծ���� 
//    vector<int>::iterator itbegin = v.begin();
//    itbegin += 3;
//    cout << *itbegin << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}

















                                                             //deque����
/*
deque��һ��˫�򿪿ڵ��������Կռ䡣
��������ͷβ���˷ֱ���Ԫ�صĲ����ɾ���Ĳ�����
ע��:
dequeû�������ĸ����Ϊ���Ƕ�̬���Էֶ������ռ���϶��ɣ���ʱ��������һ���µĿռ䲢����������
*/


//deque���캯��
/*
deque<T>deqT;//Ĭ�Ϲ�����ʽ
deque(begin,end);//��[begin,end)�����е�Ԫ�ؿ���������
deque(int n,elem);//���캯����n��elem����������
deque(const deque& deq);//�������캯��
*/



//deque��ֵ����
/*
assign(begin,end);//������[begin,end)�е����ݿ�����ֵ������
assign(int n,elem);//��n��elem������ֵ������
deque operator=(const deque& deq);//���صȺ������
swap(deq);//��deq��Ԫ��������Ԫ�ػ���
*/



//deque��С����
/*
deque.size();//���������е�Ԫ�صĸ���
deque.empty();//�ж������Ƿ�Ϊ��
deque.resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á���������̣�ĩβ�����������ȵ�Ԫ�ر�ɾ����
deque.resize(int num,elem);///����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á���������̣�ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/



//deque˫�˲����ɾ������
/*
push_back(elem);//��������β������Ԫ��elem
push_front(elem);//��������ͷ����������elem
pop.back();//ɾ�����������һ������
pop_front();//ɾ�������ĵ�һ������
*/



//deque���ݴ�ȡ
/*
at(int index);//��������index��ָ��Ԫ�ء���indexԽ�磬�׳�out_of_range�쳣��
operator[];//��������index��ָ��Ԫ�أ���indexԽ�磬����ֱ�ӱ�����
front();//���ص�һ������
back();//�������һ������
*/



//deque�������
/*
insert(pos,elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,int n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,begin,end);//��posλ�ò���[begin,end)��������ݣ��޷���ֵ
*/



//dequeɾ������
/*
clear();//ɾ�������е�����Ԫ��
erase(begin,end);//ɾ��[begin,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
*/





//����
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
//    string m_name;//����
//    int m_score;//ƽ����
//};
//void createPlayer(vector<Player>& v)
//{
//    string nameseed = "ABCDE";
//    for (int i = 0; i < 5; i++)
//    {
//        string name = "ѡ��";
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
//        deque<int>deq;//��ŷ���������
//        for (int i = 0; i < 10; i++)//ʮ����ί���
//        {
//            int score = rand() % 41 + 60;//������Χ60~100
//            deq.push_back(score);
//        }
//
//        //����
//        sort(deq.begin(), deq.end());//Ĭ�ϴ�С��������
//
//        //ȥ����ߺ���ͷ�
//        deq.pop_back();
//        deq.pop_front();
//
//        //����ƽ����
//        int sum = 0;//�ܷ�
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
//        cout << "����:" << it->m_name << endl;
//        cout << "ƽ������:" << it->m_score << endl;
//        cout << endl;
//    }
//}
//int main()
//{
//    //�������������
//    srand((unsigned int)time(NULL));
//    //��������ѡ��
//    vector<Player>v;
//    createPlayer(v);
//    //��ί���
//    setscore(v);
//    //��ʾƽ����
//    showscore(v);
//    return 0;
//}



















                                                            //stackջ����
/*
stack��һ���Ƚ���������ݽṹ����ֻ��һ�����ڡ�
stack������������Ԫ�أ��Ƴ�Ԫ�أ�ȡ��ջ��Ԫ�ء����ǳ�������⣬û���κ������ط����Դ�ȡstack��Ԫ�ء�
stackû�е��������������б�����Ϊ��
*/



//stack���캯��
/*
stack<T>sT;//stack������ģ��ʵ�֣�stack�����Ĭ�Ϲ�����ʽ
stack(const stack& stk);//�������캯��
*/



//stack��ֵ����
/*
stack& operator=(const stack& stk);//���صȺŲ�����
*/



//stack���ݴ�ȡ����
/*
push(elem);//��ջ�����Ԫ��elem
pop();//��ջ���Ƴ���һ��Ԫ��
top();//����ջ��Ԫ��
*/



//stack��С����
/*
empty();//�ж�stack�Ƿ�Ϊ��
size();//����stack�Ĵ�С
*/



















//queue��������
/*
queue��һ���Ƚ��ȳ������ݽṹ�������������ڡ�
queue���������һ������Ԫ�أ�����һ���Ƴ�Ԫ�ء�
ֻ��queue��ͷ��β��Ԫ�زſ��Ա������ʣ�����û�е����������ṩ�������ܡ�
*/



//queue���캯��
/*
queue<T>que;//queue������ģ��ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
queue(const queue& que);//�������캯��
*/



//queue��ȡ�������ɾ������
/*
push(elem);//����β���Ԫ��elem
pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
back();//�������һ��Ԫ��
front();//���ص�һ��Ԫ��
*/



//queue��ֵ����
/*
queue operator=(const queue& que);//���صȺ������
*/



//queue��С����
/*
empty();//�ж϶����Ƿ�Ϊ��
size();//���ض��еĴ�С
*/
















//list����
/*
list������һ��˫��ѭ������
������һ������洢��Ԫ�Ϸ���������˳��Ĵ洢�ṹ������Ԫ�ص��߼��ṹ��ͨ�������е�ָ�����Ӵ���ʵ�ֵġ�������һϵ�н��
(�����е�ÿһ��Ԫ�ر���Ϊ���)��ɣ�������������ʱ��̬���ɡ�ÿ����������������:һ���Ǵ洢����Ԫ�ص���������һ����
�洢��һ������ַ��ָ����
listÿ�β������ɾ��һ��Ԫ�أ������û��ͷ�һ��Ԫ�صĿռ䡣list�Կռ�������о��Եľ�׼��
���ң������κ�λ�õ�Ԫ�ز�����Ƴ���list��Զ��Ϊ����ʱ�䡣
*/


//list�ص�:
/*
1.���ö�̬�洢���䣬��������ڴ��˷�
2.����ִ�в����ɾ������ʮ�ַ��㣬����Ҫ�ƶ�����Ԫ�أ��޸�ָ�뼴�ɡ�
3.���������ռ��ʱ��Ķ���ķѽϴ�
4.��vector��ͬ�������ɾ���������������ԭ��list��������ʧЧ��(����ȫ�����·���ռ�)
*/





//list���캯��
/*
list<T>L;//list������ģ��ʵ�֣�list�����Ĭ�Ϲ�����ʽ
list(begin,end);//���캯��������[begin,end)�е�Ԫ�ؿ�����������
list(int n,elem);//���캯����n��elem����������
list(const list& L);//�������캯��
*/



//list����Ԫ�صĲ����ɾ������
/*
push_back(elem);//β��elem
pop_back();//βɾ
push_front(elem);//ͷ��elem
pop_front();//ͷɾ
insert(pos,elem);//��posλ�ò���elemԪ�صĿ��������������ݵ�λ��
insert(pos,int n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ
insert(pos,begin,end);//��posλ�ò���[begin,end)��������ݣ��޷���ֵ
clear();//�Ƴ������е���������
erase(begin,end);//ɾ��[begin,end)��������ݣ�������һ�����ݵ�λ��
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
remove(elem);//ɾ��������������elemֵƥ���Ԫ��(������removeɾ���Զ����������ͣ���Ҫ����==)
*/



//list��С����
/*
size();//���������е�Ԫ�ظ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
resize(int num,elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
*/



//list��ֵ����
/*
assign(begin,end);//��[begin,end)�����е����ݿ�����ֵ������
assign(int n,elem);//��n��elem������ֵ������
list& operator=(const list& L);//���صȺŲ�����
swap(L);//��L��Ԫ����������
*/



//list���ݵĴ�ȡ
/*
front();//���ص�һ��Ԫ��
back();//�������һ��Ԫ��
*/



//list��ת����
/*
reverse();//��ת����
sort();//��������Ĭ�ϴ�С����

ע��:
1.�����Զ������ͱ���ָ���������
2.ֻ�������ĵ�����֧��������ʵ�����£��ſ���ʹ��ϵͳ���׼�㷨
*/


















//set��multiset����

//set����
/*
set������Ԫ�ػ����Ԫ�صļ�ֵ�Զ�����(Ĭ�ϴ�С����)��
set��Ԫ�ؼ��Ǽ�ֵ����ʵֵ��set����������Ԫ������ͬ�ļ�ֵ��
������ͨ���������޸�setԪ�ص�ֵ��set��iterator��һ��const_iterator��
*/

//multiset����
/*
multiset���÷���set����һ�£�Ψһ�������multiset�����ֵ�ظ���
*/





//����API

//set���캯��
/*
set<T>st;//setĬ�Ϲ��캯��
multiset<T>mst;//multisetĬ�Ϲ��캯��
set(const set& st);//�������캯��
*/



//set��ֵ����
/*
set& operator=(const set& st);//���صȺ������
swap(st);//����������������
*/



//set��С����
/*
size();//���������е�Ԫ�ظ���
empty();//�ж������Ƿ�Ϊ��
*/



//set�����ɾ������
/*
insert(elem);//�������в���Ԫ��elem
clear();//�������������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
erase(begin,end);//ɾ������[begin,end)������Ԫ�أ�������һ��Ԫ�صĵ�����
erase(elem);//ɾ��������ֵΪelem��Ԫ��
*/



//set���Ҳ���
/*
find(key);//����key�Ƿ���ڡ������ڣ����ظü���Ԫ�صĵ��������������ڣ�����end();
count(key);//����key��Ԫ�ظ���
lower_bound(keyelem);//���ص�һ��key>=keyelemԪ�صĵ�����,�������ڣ�����end();
upper_bound(keyelem);//���ص�һ��key>keyelemԪ�صĵ�����,�������ڣ�����end();
equal_range(keyelem);//����������key��keyelem��ȵ������޵�����������(������lower_bound��upper_bound),�������ڣ�����set.end();
*/





//����1:
//#include<iostream>
//#include<set>
//using namespace std;
//void test1(set<int>& s)
//{
//    set<int>::iterator pos = s.find(30);
//    if (pos != s.end())
//    {
//        cout << "�ҵ���Ԫ��:" << *pos << endl;
//    }
//    else
//    {
//        cout << "δ�ҵ���Ԫ��" << endl;
//    }
//}
//void test2(set<int>& s)
//{
//    //����set���ԣ�count�Ľ��ҪôΪ0ҪôΪ1(����������Ԫ������ͬ�ļ�ֵ)
//    cout << "keyΪ40�ĸ���Ϊ:" << s.count(40) << endl;
//}
//void test3(set<int>& s)
//{
//    set<int>::iterator it = s.lower_bound(30);
//    if (it != s.end())
//    {
//        cout << *it << endl;//30(�Ѿ���������)
//    }
//
//    set<int>::iterator its = s.upper_bound(30);
//    if (its != s.end())
//    {
//        cout << *its << endl;//40
//    }
//
//    pair<set<int>::iterator,set<int>::iterator>ret = s.equal_range(30);//���ض���
//    if (ret.first != s.end())
//    {
//        cout << "lower_bound��ֵΪ:" << *ret.first << endl;
//    }
//    if (ret.second != s.end())
//    {
//        cout << "upper_bound��ֵΪ:" << *ret.second << endl;
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





//����2:pair����Ĵ���
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    //1.
//    pair<string,int>p1("Tom", 18);
//    cout << "����:" << p1.first << endl;
//    cout << "����:" << p1.second << endl;
//    //2.
//    pair<string, int>p2 = make_pair("Jerry", 1);
//    cout << "����:" << p2.first << endl;
//    cout << "����:" << p2.second << endl;
//    return 0;
//}





//����3:set����Ӵ�С
//#include<iostream>
//#include<set>
//using namespace std;
//class mycompareint//�º���
//{
//public:
//    bool operator()(int a,int b)const//constһ��Ҫ��
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





//����4:�����Զ�����������
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
//        //���������С����
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
//        cout << "����:" << (*it).m_name << endl;
//        cout << "����:" << it->m_age << endl;
//    }
//    return 0;
//}




















                                                   //map��multimap����(�ײ�����)
/*
map������Ԫ�ظ���Ԫ�صļ�ֵ�Զ�����
map������Ԫ�ض���pair,ͬʱӵ�м�ֵ��ʵֵ����pair�ĵ�һԪ�ر���Ϊ��ֵ���ڶ�Ԫ�ر���Ϊʵֵ��map����������Ԫ������ͬ�ļ�ֵ��
����ͨ���������޸�map�ļ�ֵ���������޸�ʵֵ��
multimap��map�Ĳ������ƣ���multimap��ֵ�����ظ���
*/





//����API

//map���캯��
/*
map<T,T>m;//mapĬ�Ϲ��캯��
map(const map& m);//�������캯��
*/



//map��ֵ����
/*
msp& operator=(const map& m);//���صȺ������
swap(m);//����������������
*/



//map��С����
/*
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
*/



//map�������
/*
1.
map.insert(����)��//�������в���Ԫ�ء�����pair<iterator,bool>

2.m.insert(pair<string,int>("Tom",18));//ͨ��pair�ķ�ʽ����

3.m.insert(make_pair("Jerry",1));ͨ��pair�ķ�ʽ����

4.m.insert(map<string,int>::value_type(GG_Bond",18));//ͨ��value_type�ķ�ʽ����

5.m[1]="haha";//ͨ������ķ�ʽ����
*/



//mapɾ������
/*
clear();//ɾ������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
erase(begin,end);//ɾ��[begin,end)���������Ԫ�أ�������һ��Ԫ�صĵ�����
erase(keyelem);//ɾ��������keyΪkeyelem�Ķ���
*/



//map���Ҳ���
/*
find(key);//����key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ��������������ڣ�����end();
count();//����������keyΪkeyelem�Ķ���ĸ���������map��˵��ҪôΪ0��ҪôΪ1
lower_bound(keyelem);//���ص�һ��key>=keyelemԪ�صĵ�����,�������ڣ�����end();
upper_bound(keyelem);//���ص�һ��key>keyelemԪ�صĵ�����,�������ڣ�����end();
equal_range(keyelem);//����key��keyelem��ȵ������޵�����������,�������ڣ�����end();
*/





//����1:�Ӵ�С����
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





//����2:Ա������
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
//        w.m_name = "Ա��";
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
//        //����������ű��
//        int ID = rand() % 3;
//        m.insert(make_pair(ID, *it));
//    }
//}
//void Print(multimap<int, Worker>& m, int bumen)
//{
//    multimap<int, Worker>::iterator pos = m.find(bumen);//�ҵ��ò��ŵ�һ��Ԫ�صĵ�����
//    int num = m.count(bumen);//��������
//    for (int i = 0; pos != m.end() && i < num; pos++, i++)
//    {
//        cout << "����Ϊ:" << pos->second.m_name << endl;
//        cout << "н��Ϊ:" << pos->second.m_money << endl;
//    }
//}
//void showworker(multimap<int, Worker>& m)
//{
//    cout << "������Ա����Ϣ����:" << endl;
//    Print(m, CAIWU);
//    cout << "���²���Ա����Ϣ����:" << endl;
//    Print(m, RENSHI);
//    cout << "�з�����Ա����Ϣ����:" << endl;
//    Print(m, YANFA);
//}
//int main()
//{
//    //���������
//    srand((unsigned int)time(NULL));
//    vector<Worker>v;
//    //��������Ա��
//    createworker(v);
//    //Ա������
//    multimap<int, Worker>m;
//    setgroup(v, m);
//    //�ֲ�����ʾԱ��
//    showworker(m);
//    return 0;
//}




