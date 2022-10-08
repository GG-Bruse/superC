#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
        if (a > b)
        {
                int temp = a;
                a = b;
                b = temp;
        }
}
int main()
{
        int num1, num2;
        cin >> num1 >> num2;
        swap(num1, num2);
        cout << num1 << " " << num2 << endl;
        return 0;
}




#include<iostream>
using namespace std;
class B
{
public:
        B() {}
        B(int i, int j)
        {
                x = i;
                y = j;
        }
        void printb()
        {
                cout << x << " " << y << endl;
        }
private:
        int x, y;
};
class A
{
public:
        A() {}
        A(int I, int J);
        void printa();
private:
        B c;
};
A::A(int i, int j) :c(i, j)
{}
void A::printa()
{
        c.printb();
}
int main()
{
        A a(10, 20);
        a.printa();
        return 0;
}







#include<iostream>
using namespace std;
class A
{
public:
        void set(int i, int j)
        {
                x = i;
                y = j;
        }
        int get_y()
        {
                return y;
        }
private:
        int x, y;
};
class box
{
public:
        void set(int l, int w, int s, int p)
        {
                length = l;
                width = w;
                label.set(s, p);
        }
        int get_area()
        {
                return length * width;
        }
private:
        int length, width;
        A label;
};
int main()
{
        box b;
        b.set(4, 6, 1, 20);
        cout << b.get_area() << endl;
        return 0;
}




#include<iostream>
using namespace std;
class counter
{
public:
        counter(int number);
        void increment(); //给原值+1
        void decrement(); //给原值-1
        int getvalue(); //取得计数器值
        int print(); //显示计数
private:
        int value;
};
counter::counter(int num)
{
        this->value = num;
}
void counter::increment()
{
        ++this->value;
}
void counter::decrement()
{
        --this->value;
}
int counter::getvalue()
{
        return this->value;
}
int counter::print()
{
        cout << this->value << endl;
        return 0;
}
int main()
{
        counter a(10);
        a.increment();
        a.print();
        return 0;
}


