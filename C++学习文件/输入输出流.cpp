#define _CRT_SECURE_NO_WARNINGS

//C++���������

//���������ָ���Ǵ������ļ������ݴ��͸����򣬳�������ָ���Ǵӳ������ݴ��͸�����ļ�
/*
C++������������������������:
1.��ϵͳָ���ı�׼�豸���������������Ӽ����������ݣ��������ʾ����Ļ��
�������������Ϊ��׼�������������Ʊ�׼I/O

2.���������ļ�Ϊ��������������������Ӵ����ļ��������ݣ���������������ļ���
������ļ�Ϊ�������������Ϊ�ļ����������������ļ�I/O

3.���ڴ���ָ���Ŀռ��������������ͨ��ָ��һ���ַ�������Ϊ�洢�ռ�(ʵ���Ͽ������øÿռ�洢�κ���Ϣ)��
����������������Ϊ�ַ��������������ƴ�I/O
*/










//��׼������
/*
(1)cin.get()//һ��ֻ�ܶ�ȡһ���ַ�
(2)cin.get(һ������)//��һ���ַ�
(3cin.get(��������)//���Զ��ַ���
(4)cin.getline()//��ȡ�ַ���
(5)cin.ignore()//����
(6)cin.peek()//͵��
(7)cin.putback()//�Ż�
*/

//#include<iostream>
//using namespace std;
//void test1()//(1)(2)
//{
//    char c = cin.get();
//    cout << "c = " << c << endl;
//    cin.get(c);
//    cout << "c = " << c << endl;
//}
//void test2()//(3)
//{
//    //����cin.get()��ȡ�ַ���ʱ�����з��������ڻ�������
//    char buf[1024] = { 0 };
//    cin.get(buf, 1024);
//    cout << buf << endl;
//}
//void test3()//(4)
//{
//    //ʹ��cin.getline()��ȡ�ַ���ʱ�����з����������ڻ�������Ҳ���ᱻȡ�ߣ�����ֱ���ӵ�
//    char buf[1024] = { 0 };
//    cin.getline(buf,1024);
//    cout << buf << endl;
//}
//void test4()
//{
//    cin.ignore(2);//���Ի��������ݣ�Ĭ�Ϻ���һ���ַ�������ΪX,����Ի�������X���ַ�
//    char c = cin.get();//asc
//    cout << "c = " << c << endl;//c
//}
//void test5()
//{
//    char c = cin.peek();//�鿴��������һ���ַ�������ʹ�ã������ӻ�����ȡ��
//    cout << "c = " << c << endl;
//    c = cin.get();
//    cout << "c = " << c << endl;
//}
//void test6()
//{
//    //�����ݷŻػ�����ԭ����λ��
//    char c = cin.get();
//    cin.putback(c);
//    char buf[1024] = { 0 };
//    cin.getline(buf, 1024);
//    cout << buf << endl;
//}
//int main()
//{
//    //test1();
//    //test2();
//    //test3();
//    //test4();
//    //test5();
//    test6();
//    return 0;
//}



//����1(�ж��û���������ַ�����������)
//#include<iostream>
//using namespace std;
//void test()
//{
//    cout << "������һ���ַ�����������" << endl;
//    char c = cin.peek();
//    if (c >= '0' && c <= '9')
//    {
//        int num;
//        cin >> num;//ȡ�߻���������
//        cout << "�����������" << endl;
//    }
//    else
//    {
//        char buf[1024];
//        cin >> buf;
//        cout << "��������ַ���" << endl;
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}


//����2(�û�����һ��0��10֮������֣���������������������)
/*
cout<<cin.fail();
�����־λΪ0�򻺳�������������־λΪ1�򻺳����쳣
*/

//#include<iostream>
//using namespace std;
//void test()
//{
//    cout << "������0��10֮�������" << endl;
//    int num;
//    while (true)
//    {
//        cin >> num;
//        if (num >= 0 && num <= 10 && cin.fail() == 0)
//        {
//            cout << "������ȷ,����ֵΪ:" << num << endl;
//            break;
//        }
//        cin.clear();//���ñ�־λ
//        cin.ignore(1024,'\n');//������뻺�����ĵ�ǰ��
//        cout << "�����������������" << endl;
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}

















//��׼�����
/*
(1)cout.flush()//ˢ�»����� Linux����Ч
(2)cout.put()//�򻺳���д�ַ�
(3)cout.write(char* buf,int size)//��buffer��дnum���ֽڵ���ǰ�������
*/

//#include<iostream>
//using namespace std;
//void test1()//(2)
//{
//    cout.put('h').put('e');//�ṩ��ʽ���
//    //ʹ�ý���
//}
//void test2()//(3)
//{
//    char buf[] = "hello world";
//    cout.write(buf, strlen(buf));
//}
//int main()
//{
//    //test1();
//    test2();
//    return 0;
//}


//��ʽ�����
/*
(1)ʹ�ÿ��Ʒ��ķ���:#include<iomanip>
(2)ʹ����������йس�Ա����
*/
/*
ios::left           ��������ڱ����Χ���������
ios::right          ��������ڱ����Χ�����Ҷ���
ios::internal       ��ֵ�ķ���λ�����������룬��ֵ�Ҷ��룬�м�������ַ����
ios::dec            ���������Ļ���Ϊ10
ios::oct            ���������Ļ���Ϊ8
ios::hex            ���������Ļ���Ϊ16
ios::showbase       ǿ����������Ļ���(�˽�����0��ͷ��ʮ��������0x��ͷ)
ios::showpoint      ǿ�������������С�����β��0
ios::uppercase      ���Կ�ѧ��������ʽE����ʮ�����������ĸʱ�Դ�д��ʾ
ios::showpos        ��������ʾ"+"��
ios::fixed          �������Զ����ʽ(С����ʽ)���
ios::unitbuf        ÿ�������ˢ�����е���
ios::stdio          ÿ�����֮�����stdout,stderr
*/

//����Ա��������
//#include<iostream>
//using namespace std;
//void test()
//{
//    int num = 99;
//    cout.width(20);//ָ�����
//    cout.fill('*');//�����ַ����
//    cout.setf(ios::left);//�����
//    cout.unsetf(ios::dec);//ж��ʮ����
//    cout.setf(ios::hex);//����Ϊʮ������
//    cout.setf(ios::showbase);//��ʾ����
//    cout << num << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}



//ʹ�ÿ��Ʒ�����
//#include<iostream>
//#include<iomanip>
//using namespace std;
//void test()
//{
//    int num = 99;
//    cout << setw(20)//���ÿ��
//        <<setfill('*')//�������
//        <<setiosflags(ios::showbase)//��ʾ����(ʮ�����޻���)
//        <<setiosflags(ios::left)//���������
//        <<hex//����Ϊʮ������
//        <<num
//        << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}

































                                                       //�ļ���д<fstream>

/*
ios::in             ������ķ�ʽ���ļ�
ios::out            �������ʽ���ļ�(����Ĭ�Ϸ�ʽ)��������д����ֵ��ļ�������ԭ������ȫ��ɾ��
ios::app            ������ķ�ʽ���ļ�,д�������׷�����ļ�ĩβ
ios::ate            ��һ�������ļ����ļ�ָ��ָ���ļ�ĩβ
ios::trunc          ��һ���ļ������ļ��Ѵ��ڣ���ɾ������ȫ�����ݡ����ļ��������������ļ���
                    ����ָ����ios::out��ʽ������δָ��ios::app��ios::ate��ios::in,��ͬʱĬ�ϴ˷�ʽ
ios::binary         �Զ����Ʒ�ʽ���ļ�������ָ���˷�ʽ��Ĭ��ΪACSCII��ʽ��(����������ʽʹ��)
ios::nocreate       ��һ�����е��ļ������ļ����������ʧ�ܡ�:nocreate����˼�ǲ��������ļ�
ios::noreplace      ���ļ��������������ļ������ļ��Ѿ����������ʧ�ܡ�replace����˼�ǲ�����ԭ���ļ�
ios::in | ios::out  �����������ķ�ʽ���ļ����ļ��ɶ���д
*/


//#include<iostream>
//#include<string>
//#include<fstream>//�ļ����������
//using namespace std;
//void test1()//д����
//{
//    ofstream ofs;
//    ofs.open("test.txt", ios::out | ios::trunc);//����·���ʹ򿪷�ʽ
//    if (!ofs.is_open())//�ж��ļ��Ƿ�򿪳ɹ�������boolֵ
//    {
//        cout << "�ļ���ʧ��" << endl;
//        return;
//    }
//    ofs << "����:GG_Bond" << endl;
//    ofs << "����:18" << endl;
//    ofs << "�Ա�:��" << endl;
//    ofs.close();
//}
//void test2()
//{
//    ifstream ifs("test.txt", ios::in);
//    if (!ifs.is_open())
//    {
//        cout << "�ļ���ʧ��" << endl;
//        return;
//    }
//    //1.
//    /*char buf[1024] = {0};
//    while (ifs >> buf)//ѭ����ȡ
//    {
//        cout << buf << endl;
//    }*/
//
//    //2.
//    /*char buf[1024] = { 0 };
//    while (ifs.getline(buf,sizeof(buf)))
//    {
//        cout << buf << endl;
//    }*/
//
//    //3.
//    /*string buf;
//    while (getline(ifs,buf))
//    {
//        cout << buf << endl;
//    }*/
//
//    //4.(���Ƽ�)
//    /*char c;
//    while ((c = ifs.get()) != EOF)
//    {
//        cout << c;
//    }*/
//    ifs.close();
//}
//int main()
//{
//    test2();
//    return 0;
//}
