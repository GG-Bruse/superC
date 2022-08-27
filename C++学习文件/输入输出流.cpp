#define _CRT_SECURE_NO_WARNINGS

//C++输入输出流

//程序的输入指的是从输入文件将数据传送给程序，程序的输出指的是从程序将数据传送给输出文件
/*
C++输入输出包含三个方面的内容:
1.对系统指定的标准设备的输入和输出。即从键盘输入数据，输出到显示屏屏幕。
这种输入输出称为标准的输入输出，简称标准I/O

2.以外存磁盘文件为对象进行输入和输出，即从磁盘文件输入数据，数据输出到磁盘文件。
以外存文件为对象输入输出称为文件的输入输出，简称文件I/O

3.对内存中指定的空间进行输入和输出，通常指定一个字符数组作为存储空间(实际上可以利用该空间存储任何信息)。
这种输入和输出被称为字符串输入输出，简称串I/O
*/










//标准输入流
/*
(1)cin.get()//一次只能读取一个字符
(2)cin.get(一个参数)//读一个字符
(3cin.get(两个参数)//可以读字符串
(4)cin.getline()//读取字符串
(5)cin.ignore()//忽略
(6)cin.peek()//偷窥
(7)cin.putback()//放回
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
//    //利用cin.get()获取字符串时，换行符会遗留在缓冲区中
//    char buf[1024] = { 0 };
//    cin.get(buf, 1024);
//    cout << buf << endl;
//}
//void test3()//(4)
//{
//    //使用cin.getline()获取字符串时，换行符不会遗留在缓冲区，也不会被取走，而是直接扔掉
//    char buf[1024] = { 0 };
//    cin.getline(buf,1024);
//    cout << buf << endl;
//}
//void test4()
//{
//    cin.ignore(2);//忽略缓冲区数据，默认忽略一个字符。参数为X,便忽略缓冲区中X个字符
//    char c = cin.get();//asc
//    cout << "c = " << c << endl;//c
//}
//void test5()
//{
//    char c = cin.peek();//查看缓冲区的一个字符，可以使用，但不从缓冲区取走
//    cout << "c = " << c << endl;
//    c = cin.get();
//    cout << "c = " << c << endl;
//}
//void test6()
//{
//    //将数据放回缓冲区原来的位置
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



//案例1(判断用户输入的是字符串还是数字)
//#include<iostream>
//using namespace std;
//void test()
//{
//    cout << "请输入一个字符串或者数字" << endl;
//    char c = cin.peek();
//    if (c >= '0' && c <= '9')
//    {
//        int num;
//        cin >> num;//取走缓冲区数据
//        cout << "输入的是数字" << endl;
//    }
//    else
//    {
//        char buf[1024];
//        cin >> buf;
//        cout << "输入的是字符串" << endl;
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}


//案例2(用户输入一个0—10之间的数字，如果输入错误则重新输入)
/*
cout<<cin.fail();
如果标志位为0则缓冲区正常，若标志位为1则缓冲区异常
*/

//#include<iostream>
//using namespace std;
//void test()
//{
//    cout << "请输入0—10之间的数字" << endl;
//    int num;
//    while (true)
//    {
//        cin >> num;
//        if (num >= 0 && num <= 10 && cin.fail() == 0)
//        {
//            cout << "输入正确,输入值为:" << num << endl;
//            break;
//        }
//        cin.clear();//重置标志位
//        cin.ignore(1024,'\n');//清除输入缓冲区的当前行
//        cout << "输入错误请重新输入" << endl;
//    }
//}
//int main()
//{
//    test();
//    return 0;
//}

















//标准输出流
/*
(1)cout.flush()//刷新缓冲区 Linux下有效
(2)cout.put()//向缓冲区写字符
(3)cout.write(char* buf,int size)//从buffer中写num个字节到当前输出流中
*/

//#include<iostream>
//using namespace std;
//void test1()//(2)
//{
//    cout.put('h').put('e');//提供链式编程
//    //使用较少
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


//格式化输出
/*
(1)使用控制符的方法:#include<iomanip>
(2)使用流对象的有关成员函数
*/
/*
ios::left           输出数据在本域宽范围内向左对齐
ios::right          输出数据在本域宽范围内向右对齐
ios::internal       数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充
ios::dec            设置整数的基数为10
ios::oct            设置整数的基数为8
ios::hex            设置整数的基数为16
ios::showbase       强制输出整数的基数(八进制以0开头、十六进制以0x开头)
ios::showpoint      强制输出浮点数的小数点和尾数0
ios::uppercase      在以科学计数法格式E和以十六进制输出字母时以大写表示
ios::showpos        对正数显示"+"号
ios::fixed          浮点数以定点格式(小数形式)输出
ios::unitbuf        每次输出后刷新所有的流
ios::stdio          每次输出之后清除stdout,stderr
*/

//流成员函数案例
//#include<iostream>
//using namespace std;
//void test()
//{
//    int num = 99;
//    cout.width(20);//指定宽度
//    cout.fill('*');//将空字符填充
//    cout.setf(ios::left);//左对齐
//    cout.unsetf(ios::dec);//卸载十进制
//    cout.setf(ios::hex);//设置为十六进制
//    cout.setf(ios::showbase);//显示基数
//    cout << num << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}



//使用控制符案例
//#include<iostream>
//#include<iomanip>
//using namespace std;
//void test()
//{
//    int num = 99;
//    cout << setw(20)//设置宽度
//        <<setfill('*')//设置填充
//        <<setiosflags(ios::showbase)//显示基数(十进制无基数)
//        <<setiosflags(ios::left)//设置左对齐
//        <<hex//设置为十六进制
//        <<num
//        << endl;
//}
//int main()
//{
//    test();
//    return 0;
//}

































                                                       //文件读写<fstream>

/*
ios::in             以输入的方式打开文件
ios::out            以输出方式打开文件(这是默认方式)。如果已有此名字的文件，则将其原有内容全部删除
ios::app            以输出的方式打开文件,写入的数据追加在文件末尾
ios::ate            打开一个已有文件，文件指针指向文件末尾
ios::trunc          打开一个文件，若文件已存在，则删除其中全部数据。若文件不存在则建立新文件。
                    若已指定了ios::out方式，并且未指定ios::app、ios::ate、ios::in,则同时默认此方式
ios::binary         以二进制方式打开文件，若不指定此方式则默认为ACSCII方式。(搭配其他方式使用)
ios::nocreate       打开一个已有的文件。若文件不存在则打开失败。:nocreate的意思是不建立新文件
ios::noreplace      若文件不存在则建立新文件，若文件已经存在则操作失败。replace的意思是不更新原有文件
ios::in | ios::out  以输入和输出的方式打开文件，文件可读可写
*/


//#include<iostream>
//#include<string>
//#include<fstream>//文件输入输出流
//using namespace std;
//void test1()//写数据
//{
//    ofstream ofs;
//    ofs.open("test.txt", ios::out | ios::trunc);//设置路径和打开方式
//    if (!ofs.is_open())//判断文件是否打开成功，返回bool值
//    {
//        cout << "文件打开失败" << endl;
//        return;
//    }
//    ofs << "姓名:GG_Bond" << endl;
//    ofs << "年龄:18" << endl;
//    ofs << "性别:男" << endl;
//    ofs.close();
//}
//void test2()
//{
//    ifstream ifs("test.txt", ios::in);
//    if (!ifs.is_open())
//    {
//        cout << "文件打开失败" << endl;
//        return;
//    }
//    //1.
//    /*char buf[1024] = {0};
//    while (ifs >> buf)//循环读取
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
//    //4.(不推荐)
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
