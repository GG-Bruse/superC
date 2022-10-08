
#include<iostream>
using namespace std;
class base1
{
public:
        base1()
        {
                cout<<"class base1"<<endl;
        }
};
class base2
{
public:
        base2()
        {
                cout<<"class base2"<<endl;
        }
};
class level1:public base2,virtual public base1
{
public:
        level1()
        {
                cout<<"class level1"<<endl;
        }
};
class level2:public base2,virtual public base1
{
public:
        level2()
        {
                cout<<"class level2"<<endl;
        }
};
class toplevel:public level1,virtual public level2
{
public:
        toplevel()
        {
                cout<<"class toplevel"<<endl;
        }
};
int main()
{
        toplevel obj;
        return 0;
}



#include<iostream>
using namespace std;
class base
{
public:
        base(int a)
        {
                this->a= a;
                cout<<"c base"<<" "<<a<<endl;
        }
private:
        int a;
};
class base1:virtual public base
{
public:
        base1(int a,int b):base(a)
        {
                this->b= b;
                cout<<"c base1"<<" "<<b<<endl;
        }
private:
        int b;
};
class base2:virtual public base
{
public:
        base2(int a,int c):base(a)
        {
                this->c= c;
                cout<<"c base2"<<" "<<c<<endl;
        }
private:
        int c;
};
class derived:public base1,public base2
{
public:
        derived(int a,int b,int c,int d):base(a),base1(a,b),base2(a,c)
        {
                this->d = d;
                cout<<"c derive"<<" "<<d<<endl;
        }
private:
        int d;
};
int main()
{
        derived obj(1,2,3,4);
        return 0;
}



