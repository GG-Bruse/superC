#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
        //两个纯虚函数
        virtual void speak() = 0;
        virtual void walk() = 0;
private:
        string m_name;
        int age;
};
class Worker :public Person
{
public:
        //重写父类纯虚函数
        void speak()
        {
                cout << "Work中speak函数调用" << endl;
        }
        void walk()
        {
                cout << "Work中walk函数调用" << endl;
        }
private:
        int m_salary;
};
class Student :public Person
{
public:
        //重写父类纯虚函数
        void speak()
        {
                cout << "Student中speak函数调用" << endl;
        }
        void walk()
        {
                cout << "Student中walk函数调用" << endl;
        }
private:
        string m_school;
};
int main()
{
        //新建Worker和Student对象
        Worker* w = new Worker;
        Student* s = new Student;
        //用父类Perosn的指针指向这两个对象
        Person* p1 = w;
        Person* p2 = s;
        //调用
        p1->speak();
        p1->walk();
        p2->speak();
        p2->walk();
        return 0;
}














/*
给你一个字符串 s ，如果 s 是一个 好 字符串，请你返回 true ，否则请返回 false 。

如果 s 中出现过的 所有 字符的出现次数 相同 ，那么我们称字符串 s 是 好 字符串。

s只包含小写字母
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        vector<int>flag;
        flag.resize(26);
        for (int i = 0; i < 26; ++i)
        {
            flag[i] = 0;
        }
        for (string::iterator it = s.begin(); it != s.end(); ++it)
        {
            ++flag[(*it) - 97];
        }
        sort(flag.begin(), flag.end());
        for (int i = 0; i < 25; ++i)
        {
            if (flag[i] != 0 && flag[i] < flag[25])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string str = "aca";
    Solution s;
    cout<<s.areOccurrencesEqual(str);
        return 0;
}


