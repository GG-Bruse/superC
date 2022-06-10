
#include<iostream>
using namespace std;
class A
{
public:
        static int a;
        void init()
        {
                a = 1;
        }
        A(int a = 2)
        {
                init();
                a++;
        }
};
int A::a = 0;
A obj;
int main()
{
        cout << obj.a;//1
        return 0;
}






#include<iostream>
using namespace std;
class Point
{
public:
        static int numbers;
public:
        Point()
        {
                numbers++;
        }
        ~Point()
        {
                numbers--;
        }
};
int Point::numbers = 0;
int main()
{
        Point* ptr;
        Point A, B;
        {
                Point* ptr_point = new Point[3];
                ptr = ptr_point;
        }
        Point C;
        cout << Point::numbers << endl;
        delete[] ptr;
        return 0;
}


