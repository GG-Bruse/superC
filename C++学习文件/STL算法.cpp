#define _CRT_SECURE_NO_WARNINGS

//算法
/*
算法主要由头文件<algorithm><functional><numeric>组成

<algorithm>是所有STL头文件中最大的一个，其中常用的功能涉及到比较、交换、查找、遍历、复制、修改、反转、排序、合并等

<numeric>体积很小，只包括在几个序列容器上进行简单运算的模板函数

<functional>定义了一些模板类，用以声明函数对象
*/













//常用遍历算法

//for_each
/*
for_each(iterator begin,iterator end,_callback)
begin开始迭代器
end结束迭代器
_callback 回调函数或者函数对象
return 函数对象
*/
//1.有返回值
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

//2.可以绑定参数输出
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
作用:将指定容器区间元素搬运到另一容器中
注意:transform不会给目标容器分配内存，需提前主动分配好内存

transform(iterator beg1,iterator end1,iterator beg2,_callback);
beg1源容器开始迭代器
end1源容器结束迭代器
beg2目标容器开始迭代器
_callback回调函数或函数对象
return 返回目标容器迭代器
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
//        return val + 1;//在搬运过程中可以调整数据
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
//    vs.resize(v.size());//分配内存
//    transform(v.begin(), v.end(), vs.begin(), Mytransform());
//    for_each(vs.begin(), vs.end(), [](int val) {cout << val << " "; });
//    return 0;
//}





















                                                          //常用查找算法

//find查找元素
/*
注意:若要查找自定义数据类型，需重载==
find(iterator begin,iterator end,value);
begin开始迭代器
end结束迭代器
value查找的元素
return 返回查找元素的迭代器
*/



//find_if条件查找
/*
find_if(iterator beg,iterator end,_callback);
beg开始迭代器
end结束迭代器
_callback回调函数或谓词(返回bool类型的函数对象)
return bool
*/



//adjacent_find查找相邻重复元素
/*
adjacent_find(iterator begin.iterator end,_callback);
begin开始迭代器
end结束迭代器
_callback回调函数或谓词(返回bool类型的函数对象)
return 返回相邻元素的第一个位置的迭代器
*/



//binary_search二分查找法
/*
在无序序列中不可以使用
bool binary_search(iterator begin,iterator end,value);
begin开始迭代器
end结束迭代器
value查找的元素
return bool
*/



//count统计元素出现的次数
/*
count(iterator begin,iterator end,value);
begin开始迭代器
end结束迭代器
value查找的元素
return 返回元素个数
*/




//count_if统计元素出现次数
/*
count_if(iterator begin,iterator end,_callback);
begin开始迭代器
end结束迭代器
_callback回调函数或谓词(返回bool类型的函数对象)
return int 返回元素个数
*/




//案例
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
//        cout << "找到了:" << *it << endl;
//    }
//    else
//    {
//        cout << "没找到" << endl;
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
//    //查找3的出现次数
//    int num = count(v.begin(), v.end(), 3);
//    cout << "3出现的次数为:" << num << endl;
//    //查找大于等于3的数出现的次数
//    num = count_if(v.begin(), v.end(), Greaterthan3());
//    cout << "大于等于3的数:" << num << endl;
//    return 0;
//}




















                                                        //常用的排序算法

//merge 容器元素合并，并存储到另一容器中
/*
merge(iterator beg1,iterator end1.iterator beg2,iterator end2,iterator dest);
dest目标容器开始迭代器
注意:
1.两个容器必须都是有序的,并且顺序一致(都为升序或都为降序)
2.需给目标容器分配内存
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





//sort 容器元素排序
/*
sort(iterator beg,iterator end,_callback);
begin开始迭代器
end结束迭代器
_callback回调函数或谓词(返回bool类型的函数对象)
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





//random_shuffle(洗牌)对指定范围内的元素随机调整次序
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
//    srand((unsigned int)time(NULL));//随机数种子
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





//reverse反转指定范围的元素
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


















                                                       //常用拷贝和替换算法

//copy将容器内指定范围的元素拷贝到另一容器中
/*
copy(iterator begin,iterator end,iterator dest);
dest目标容器起始迭代器
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
//    copy(dest.begin(), dest.end(), ostream_iterator<int>(cout, " "));//copy进行打印操作
//    return 0;
//}





//replace将容器指定范围内的旧元素修改为新元素
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






//replace_if将容器指定范围内满足条件的元素替换为新元素
/*
replace_if(iterator begin,iterator end,_callback,newvalue);
_callback回调函数或谓词(返回bool类型的函数对象)
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
//        return val > 3;//大于3的数都进行替换
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





//swap互换两个容器的元素
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
//    vector<int>v2(10, 100);//10个100
//    for (int i = 0; i < 10; i++)
//    {
//        v1.push_back(i + 1);
//    }
//    swap(v1, v2);
//    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
//    return 0;
//}



















                                                      //常用的算数生成算法

//accumulate计算容器元素累计总和
/*
accumulate(iterator begin.iterator end,value);
value累加初始值
return 累加完成后的值
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





//fill向容器中添加元素
/*
fill(iterator begin,iterator end,elem);
elem添加的元素
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

















                                                         //常用的集合算法

//set_intersection 求两个set集合的交集(两个集合必须为有序序列)
/*
set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
dest目标容器开始迭代器
return 目标容器的最后一个元素的迭代器地址
*/





//set_union 求两个set集合的并集(两个集合必须为有序序列)
/*
set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
dest目标容器开始迭代器
return 目标容器的最后一个元素的迭代器地址
*/





//set_difference 求两个set集合的差集(两个集合必须为有序序列)
/*
set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
dest目标容器开始迭代器
return 目标容器的最后一个元素的迭代器地址
*/





//案例
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
//    //交集
//    v3.resize(min(v1.size(), v2.size()));
//    vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });//v3扩容内存时可能过大，遍历时使用itend,避免超出交集元素范围
//    cout << endl;
//
//    //并集
//    v3.resize(v1.size() + v2.size());
//    itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });
//    cout << endl;
//
//    //差集
//    //1.v1与v2的差集
//    v3.resize(max(v1.size(), v2.size()));
//    itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });
//    cout << endl;
//    //2.v2与v1的差集
//    v3.resize(max(v1.size(), v2.size()));
//    itend = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
//    for_each(v3.begin(), itend, [](int val) {cout << val << " "; });
//    cout << endl;
//
//    return 0;
//}
