#define _CRT_SECURE_NO_WARNINGS

//�㷨
/*
�㷨��Ҫ��ͷ�ļ�<algorithm><functional><numeric>���

<algorithm>������STLͷ�ļ�������һ�������г��õĹ����漰���Ƚϡ����������ҡ����������ơ��޸ġ���ת�����򡢺ϲ���

<numeric>�����С��ֻ�����ڼ������������Ͻ��м������ģ�庯��

<functional>������һЩģ���࣬����������������
*/













//���ñ����㷨

//for_each
/*
for_each(iterator begin,iterator end,_callback)
begin��ʼ������
end����������
_callback �ص��������ߺ�������
return ��������
*/
//1.�з���ֵ
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class MyPrint
//{
//public:
//    void operator()(int val)
//    {
//        cout << val << " ";
//        this->m_count++;
//    }
//    int m_count = 0;
//};
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//    }
//    MyPrint print = for_each(v.begin(), v.end(),MyPrint());
//    cout << endl;
//    cout << print.m_count << endl;
//    return 0;
//}

//2.���԰󶨲������
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<functional>
//using namespace std;
//class MyPrint:public binary_function<int,int,void>
//{
//public:
//    void operator()(int val,int start)const
//    {
//        cout << val+start << " ";
//    }
//};
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//    }
//    for_each(v.begin(), v.end(), bind2nd(MyPrint(), 1000));
//    return 0;
//}





//transform
/*
����:��ָ����������Ԫ�ذ��˵���һ������
ע��:transform�����Ŀ�����������ڴ棬����ǰ����������ڴ�

transform(iterator beg1,iterator end1,iterator beg2,_callback);
beg1Դ������ʼ������
end1Դ��������������
beg2Ŀ��������ʼ������
_callback�ص�������������
return ����Ŀ������������
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Mytransform
//{
//public:
//    int operator()(int val)
//    {
//        return val + 1;//�ڰ��˹����п��Ե�������
//    }
//};
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//    }
//    vector<int>vs;
//    vs.resize(v.size());//�����ڴ�
//    transform(v.begin(), v.end(), vs.begin(), Mytransform());
//    for_each(vs.begin(), vs.end(), [](int val) {cout << val << " "; });
//    return 0;
//}





















                                                          //���ò����㷨

//find����Ԫ��
/*
ע��:��Ҫ�����Զ����������ͣ�������==
find(iterator begin,iterator end,value);
begin��ʼ������
end����������
value���ҵ�Ԫ��
return ���ز���Ԫ�صĵ�����
*/



//find_if��������
/*
find_if(iterator beg,iterator end,_callback);
beg��ʼ������
end����������
_callback�ص�������ν��(����bool���͵ĺ�������)
return bool
*/



//adjacent_find���������ظ�Ԫ��
/*
adjacent_find(iterator begin.iterator end,_callback);
begin��ʼ������
end����������
_callback�ص�������ν��(����bool���͵ĺ�������)
return ��������Ԫ�صĵ�һ��λ�õĵ�����
*/



//binary_search���ֲ��ҷ�
/*
�����������в�����ʹ��
bool binary_search(iterator begin,iterator end,value);
begin��ʼ������
end����������
value���ҵ�Ԫ��
return bool
*/



//countͳ��Ԫ�س��ֵĴ���
/*
count(iterator begin,iterator end,value);
begin��ʼ������
end����������
value���ҵ�Ԫ��
return ����Ԫ�ظ���
*/




//count_ifͳ��Ԫ�س��ִ���
/*
count_if(iterator begin,iterator end,_callback);
begin��ʼ������
end����������
_callback�ص�������ν��(����bool���͵ĺ�������)
return int ����Ԫ�ظ���
*/




//����
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    v.push_back(3);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(3);
//    v.push_back(6);
//    v.push_back(3);
//    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
//    if (it != v.end())
//    {
//        cout << "�ҵ���:" << *it << endl;
//    }
//    else
//    {
//        cout << "û�ҵ�" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Greaterthan3
//{
//public:
//    bool operator()(int val)
//    {
//        return val >= 3;
//    }
//};
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//    }
//    v.push_back(3);
//    v.push_back(3);
//    v.push_back(3);
//    //����3�ĳ��ִ���
//    int num = count(v.begin(), v.end(), 3);
//    cout << "3���ֵĴ���Ϊ:" << num << endl;
//    //���Ҵ��ڵ���3�������ֵĴ���
//    num = count_if(v.begin(), v.end(), Greaterthan3());
//    cout << "���ڵ���3����:" << num << endl;
//    return 0;
//}




















                                                        //���õ������㷨

//merge ����Ԫ�غϲ������洢����һ������
/*
merge(iterator beg1,iterator end1.iterator beg2,iterator end2,iterator dest);
destĿ��������ʼ������
ע��:
1.�����������붼�������,����˳��һ��(��Ϊ�����Ϊ����)
2.���Ŀ�����������ڴ�
*/
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//    vector<int>v1;
//    vector<int>v2;
//    vector<int>v_target;
//    for (int i = 0; i < 10; i++)
//    {
//        v1.push_back(i);
//        v2.push_back(i + 1);
//    }
//    v_target.resize(v1.size() + v2.size());
//    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin());
//    for_each(v_target.begin(), v_target.end(), [](int val) {cout << val << " "; });
//    return 0;
//}





//sort ����Ԫ������
/*
sort(iterator beg,iterator end,_callback);
begin��ʼ������
end����������
_callback�ص�������ν��(����bool���͵ĺ�������)
*/
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<functional>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i);
//    }
//    sort(v.begin(), v.end(), greater<int>());
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//    return 0;
//}





//random_shuffle(ϴ��)��ָ����Χ�ڵ�Ԫ�������������
/*
random_shuffle(iterator beg,iterator end);
*/
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<ctime>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    srand((unsigned int)time(NULL));//���������
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i + 1);
//    }
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//    cout << endl;
//    random_shuffle(v.begin(), v.end());
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//    return 0;
//}





//reverse��תָ����Χ��Ԫ��
/*
reverse(iterator begin,iterator end);
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i + 1);
//    }
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//    reverse(v.begin(), v.end());
//    cout << endl;
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//    return 0;
//}


















                                                       //���ÿ������滻�㷨

//copy��������ָ����Χ��Ԫ�ؿ�������һ������
/*
copy(iterator begin,iterator end,iterator dest);
destĿ��������ʼ������
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<iterator>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    vector<int>dest;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i + 1);
//    }
//    dest.resize(v.size());
//    copy(v.begin(), v.end(), dest.begin());
//    copy(dest.begin(), dest.end(), ostream_iterator<int>(cout, " "));//copy���д�ӡ����
//    return 0;
//}





//replace������ָ����Χ�ڵľ�Ԫ���޸�Ϊ��Ԫ��
/*
replace(iterator begin, iterator end, oldvalue, newvalue)
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i + 1);
//    }
//    replace(v.begin(), v.end(), 3, 3000);
//    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
//    return 0;
//}






//replace_if������ָ����Χ������������Ԫ���滻Ϊ��Ԫ��
/*
replace_if(iterator begin,iterator end,_callback,newvalue);
_callback�ص�������ν��(����bool���͵ĺ�������)
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Myreplace
//{
//public:
//    bool operator()(int val)
//    {
//        return val > 3;//����3�����������滻
//    }
//};
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(i + 1);
//    }
//    replace_if(v.begin(), v.end(), Myreplace(), 3000);
//    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
//    return 0;
//}





//swap��������������Ԫ��
/*
swap(container c1,container c2);
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    vector<int>v1;
//    vector<int>v2(10, 100);//10��100
//    for (int i = 0; i < 10; i++)
//    {
//        v1.push_back(i + 1);
//    }
//    swap(v1, v2);
//    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
//    return 0;
//}



















                                                      //���õ����������㷨

//accumulate��������Ԫ���ۼ��ܺ�
/*
accumulate(iterator begin.iterator end,value);
value�ۼӳ�ʼֵ
return �ۼ���ɺ��ֵ
*/
//#include<iostream>
//#include<vector>
//#include<numeric>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    for (int i = 0; i <= 100; i++)
//    {
//        v.push_back(i);
//    }
//    cout << accumulate(v.begin(), v.end(), 0) << endl;
//    return 0;
//}





//fill�����������Ԫ��
/*
fill(iterator begin,iterator end,elem);
elem��ӵ�Ԫ��
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<numeric>
//using namespace std;
//int main()
//{
//    vector<int>v;
//    v.resize(10);
//    fill(v.begin(), v.end(), 100);
//    for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
//    return 0;
//}

















                                                         //���õļ����㷨

//set_intersection ������set���ϵĽ���(�������ϱ���Ϊ��������)
/*
set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
destĿ��������ʼ������
return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/





//set_union ������set���ϵĲ���(�������ϱ���Ϊ��������)
/*
set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
destĿ��������ʼ������
return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/





//set_difference ������set���ϵĲ(�������ϱ���Ϊ��������)
/*
set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
destĿ��������ʼ������
return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/





//����
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    vector<int>v1;
//    vector<int>v2;
//    vector<int>v3;
//    for (int i = 0; i < 10; i++)
//    {
//        v1.push_back(i);
//        v2.push_back(i + 5);
//    }
//
//    //����
//    v3.resize(min(v1.size(), v2.size()));
//    vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });//v3�����ڴ�ʱ���ܹ��󣬱���ʱʹ��itend,���ⳬ������Ԫ�ط�Χ
//    cout << endl;
//
//    //����
//    v3.resize(v1.size() + v2.size());
//    itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });
//    cout << endl;
//
//    //�
//    //1.v1��v2�Ĳ
//    v3.resize(max(v1.size(), v2.size()));
//    itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });
//    cout << endl;
//    //2.v2��v1�Ĳ
//    v3.resize(max(v1.size(), v2.size()));
//    itend = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });
//    cout << endl;
//
//    return 0;
//}
