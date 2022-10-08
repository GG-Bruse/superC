#include <iostream>
using namespace std;
class B0
{
public:
        virtual void print(char * p)
        {
                cout << p << "print() B0" << endl;
        }
};
class B1 :public B0
{
public:
        virtual void print(char * p)
        {
                cout << p << "print() B1" << endl;
        }
};
class B2 :public B1
{
public:
        virtual void print(char * p)
        {
                cout << p << "print() B2" << endl;
        }
};
int main()
{
        B0 ob0, *op;
        op = &ob0;
        op->print("B0::");
        B1 ob1;
        op = &ob1;
        op->print("B1::");
        B2 ob2;
        op = &ob2;
        op->print("B2::");
        return 0;
}





#include<iostream>
using namespace std;
int main()
{
        const int n = 10;//常量
        int arr[n] = { 0 };
        for (int i = 0; i < n; ++i)
        {
                cout << arr[i] << " ";
        }
        return 0;
}
