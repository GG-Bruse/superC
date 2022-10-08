
#include<iostream>
using namespace std;
const double pi = 3.14;
class cylinder
{
public:
        cylinder(double r, double h)
        {
                this->ret = pi*r*r*h;
        }
        double vol()
        {
                cout << this->ret << endl;
                return this->ret;
        }
private:
        double ret;
};
int main()
{
        cylinder a1(1.0, 1.0);
        a1.vol();
        return 0;
}










#include<iostream>
#include<string>
using namespace std;
class test
{
public:
        test(string s1, string s2, string s3) :m_s1(s1), m_s3(s2), m_s2(s3) {}
        void ps1()
        {
                cout << this->m_s1 << endl;
        }
        void ps2()
        {
                cout << this->m_s2 << endl;
        }
        void ps3()
        {
                cout << this->m_s3 << endl;
        }
private:

        string m_s1;
        string m_s2;
        string m_s3;
};
int main()
{
        test t1("a","b","c");
        t1.ps1();
        t1.ps2();
        t1.ps3();
        return 0;
}







