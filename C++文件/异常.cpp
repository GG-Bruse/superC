#define _CRT_SECURE_NO_WARNINGS

//�쳣
/*
��ͳ�Ĵ�������ƣ�
1. ��ֹ������assert��ȱ�ݣ��û����Խ��ܡ��緢���ڴ���󣬳�0����ʱ�ͻ���ֹ����
2. ���ش����룬ȱ�ݣ���Ҫ����Ա�Լ�ȥ���Ҷ�Ӧ�Ĵ�����ϵͳ�ĺܶ��Ľӿں�������ͨ���Ѵ�����ŵ�errno�У���ʾ����
ʵ����C���Ի�������ʹ�÷��ش�����ķ�ʽ������󣬲��������ʹ����ֹ������ǳ����صĴ���

C++�е��쳣�����к������д������û���κδ��������Զ��ж�
*/

//������������ͨ��ʹ�õ��쳣�̳���ϵ
//#include <iostream>
//#include <string>
//#include <windows.h>
//using namespace std;
//
//class Exception
//{
//public:
//	Exception(const string& errmsg, int id) :_errmsg(errmsg), _id(id) {}
//	virtual string what() const {
//		return _errmsg;
//	}
//protected:
//	string _errmsg;
//	int _id;
//};
//class SqlException : public Exception
//{
//public:
//	SqlException(const string& errmsg, int id, const string& sql):Exception(errmsg, id), _sql(sql) {}
//	virtual string what() const {
//		string str = "SqlException:";
//		str += _errmsg;
//		str += "->";
//		str += _sql;
//		return str;
//	}
//private:
//	const string _sql;
//};
//class CacheException : public Exception
//{
//public:
//	CacheException(const string& errmsg, int id) :Exception(errmsg, id) {}
//	virtual string what() const {
//		string str = "CacheException:";
//		str += _errmsg;
//		return str;
//	}
//};
//class HttpServerException : public Exception
//{
//public:
//	HttpServerException(const string& errmsg, int id, const string& type) :Exception(errmsg, id) , _type(type) {}
//	virtual string what() const {
//		string str = "HttpServerException:";
//		str += _type;
//		str += ":";
//		str += _errmsg;
//		return str;
//	}
//private:
//	const string _type;
//};
//
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0){
//		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
//	}
//}
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0){
//		throw CacheException("Ȩ�޲���", 100);
//	}
//	else if (rand() % 6 == 0){
//		throw CacheException("���ݲ�����", 101);
//	}
//	SQLMgr();
//}
//void HttpServer()
//{
//	srand(time(0));
//	if (rand() % 3 == 0){
//		throw HttpServerException("������Դ������", 100, "get");
//	}
//	else if (rand() % 4 == 0){
//		throw HttpServerException("Ȩ�޲���", 101, "post");
//	}
//	CacheMgr();
//}
//
//int main()
//{
//	while (1)
//	{
//		Sleep(1000);
//		try {
//			HttpServer();
//		}
//		catch (const Exception& e) {//��������󼴿�
//			cout << e.what() << endl;// ��̬
//		}
//		catch (...){
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}


//�쳣�Ļ����﷨
/*
1.�����쳣��ͨ��throw��������һ���쳣�����׳�

2.�������׳��쳣�ĳ������try����

3.����try��ִ���ڼ�û�������쳣����ô����try���catch�־�Ͳ���ִ��

4.catch�������˳����ֵ��Ⱥ󱻼�飬ƥ���catch��䲶�񲢴����쳣(������׳�)

5.��ƥ��Ĵ���δ�ҵ��������к���terminate���Զ������ã���ȱʡ���ܵ���abort��ֹ����

6.�����˵��쳣������catch�����һ����֧��ʹ��throw������

C++�쳣����ʹ���쳣���������쳣�Ĵ�������һ�������У������ײ�ĺ����������ؽ���������⣬�����ع���Ŀ����쳣�Ĵ���
�ϲ�����߿������ʵ���λ����ƶԲ�ͬ�����쳣�Ĵ���
*/

//#include<iostream>
//using namespace std;
//int Divsion(int a, int b)
//{
//    if (b == 0)
//    {
//        throw - 1;//�׳�һ��int���͵��쳣
//    }
//    return a / b;
//}
//void test()
//{
//    int a = 10;
//    int b = 0;
//    try
//    {
//        Divsion(a, b);
//    }
//    catch (int)
//    {
//        throw;//�������쳣�����������׳��쳣
//    }
//    catch (...)
//    {
//        cout << "���������쳣����" << endl;
//    }
//}
//int main()
//{
//    try
//    {
//        test();
//    }
//    catch (int)
//    {
//        cout << "main������int�����쳣����" << endl;
//    }
//    return 0;
//}




//ջ����
/*
��try����鿪ʼ����throw�׳��쳣֮ǰ������ջ�ϵ����ݶ��ᱻ�ͷŵ����ͷŵ�˳���봴����˳���෴������������ǳ�Ϊջ����
*/





//�쳣�ӿ�����
/*
1.Ϊ�˼�ǿ����Ŀɶ��ԣ������ں����������г������׳��쳣�������������͡�
����:void func throw(A,B,C);�ú����ܹ���ֻ���׳�����A��B��C���������͵��쳣��
2.������������û�а����쳣�ӿ���������˺��������׳��κ����͵��쳣
3.һ�����׳��κ������쳣�ĺ���������Ϊ:void func()throw()
4.���һ�������׳������쳣�ӿ��������������׳����쳣��unexcepted�����ᱻ���ã��ú���Ĭ����Ϊʹ��terminate�����жϳ���
*/

//#include<iostream>
//using namespace std;
//void func()throw(int)
//{
//    throw  1;
//}
//int main()
//{
//    try
//    {
//        func();
//    }
//    catch (int)
//    {
//        cout << "int�����쳣����" << endl;
//    }
//}










//�쳣�Ķ�̬ʹ��
/*
1.�ṩ�����쳣�࣬�����а������麯�����麯��
2.�����쳣��̳л��࣬����д���麯�����麯��
3.�׳���������쳣���ø������ý��в���
*/
//#include<iostream>
//using namespace std;
//class BaseException
//{
//public:
//    virtual void printError() = 0;
//};
////��ָ���쳣
//class NULLPointException :public BaseException
//{
//public:
//    void printError()
//    {
//        cout << "��ָ���쳣" << endl;
//    }
//};
////Խ���쳣
//class OutofRangeException :public BaseException
//{
//public:
//    void printError()
//    {
//        cout << "Խ���쳣" << endl;
//    }
//};
//void dowork()
//{
//    throw OutofRangeException();
//}
//int main()
//{
//    try
//    {
//        dowork();
//    }
//    catch (BaseException& p)
//    {
//        p.printError();
//    }
//    return 0;
//}







//C++��׼�쳣��<stdexcept>
/*
1.��׼���е��쳣�����޵�
2.���Լ����쳣���У���������Լ�����Ϣ
3.�����Լ���д���쳣��Ҫ�̳б�׼�쳣��
4.���̳б�׼�쳣��ʱ��Ӧ����д�����what����������������
*/

//��д�Լ����쳣��
//#include<iostream>
//#include<stdexcept>
//#include<string>
//using namespace std;
//class MyoutofrangeException: public exception
//{
//public:
//    MyoutofrangeException(const char* str)
//    {
//        //const char*������ʽ����ת��Ϊstring,��֮������
//        this->m_error = str;
//    }
//    MyoutofrangeException(string str)
//    {
//        this->m_error = str;
//    }
//    const char* what() const
//    {
//        //��stringת��Ϊconst char*
//        return this->m_error.c_str();
//    }
//    string m_error;
//};
//class Person
//{
//public:
//    Person(int age)
//    {
//        if (age < 0 || age>180)
//        {
//            throw MyoutofrangeException("���������0��180֮��");
//        }
//        else
//        {
//            this->m_age = age;
//        }
//    }
//    int m_age;
//};
//int main()
//{
//    try
//    {
//        Person p(181);
//    }
//    catch (exception& a)//catch (MyoutofrangeException& a)
//    {
//        cout << a.what() << endl;
//    }
//    return 0;
//}








//noexcept���η�
/*
void func() noexcept(�������ʽ);

�������ʽ�Ľ���ᱻת����һ�� bool ���͵�ֵ,��ֵΪ true,��ʾ���������׳��쳣,��֮������׳��쳣.
�������������ʽ��noexcept�൱�������� noexcept(true)���������׳��쳣��
*/

//#include<iostream>
//using namespace std;
//void func1()
//{
//    throw 1;
//}
//
//void func2()throw()//�޶�������������׳��쳣���޷�����
//{
//    throw 2;
//}
//
//void func3()noexcept//�޶�������������׳��쳣���޷�����
//{
//    throw 3;
//}
//int mian()
//{
//    func1();
//    func2();
//    func3();
//    return 0;
//}

