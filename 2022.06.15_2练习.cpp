#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
        Student(int i,string n,double g)
        {
                ID = i;
                name = n;
                grades = g;
                ++count;
                total_grades+=g;
        }
        int getID()
        {
                return ID;
        }
        string getName()
        {
                return name;
        }
        double getGrades()
        {
                return grades;
        }
        static int getCount()//学生人数
        {
                return count;
        }
        static double avgGrades()
        {
                return total_grades/count;
        }
private:
        int ID;//学号
        string name;
        double grades;//成绩
        static int count;
        static double total_grades;
};
int Student::count = 0;
double Student::total_grades = 0.0;
int main()
{
        Student s1(1,"haha",100);
        Student s2(2,"hehe",150);
        cout<<"平均成绩为"<<Student::avgGrades()<<endl;
        cout<<"总人数为"<<Student::getCount()<<endl;

        cout<<s1.getID()<<"号学生"<<s1.getName()<<"的成绩为"<<s1.getGrades()<<endl;
        cout<<s2.getID()<<"号学生"<<s2.getName()<<"的成绩为"<<s2.getGrades()<<endl;
        return 0;
}





#include<iostream>
using namespace std;
class Container
{
public:
        virtual double getS() = 0;
        virtual double getV() = 0;
};
class Sphere:public Container
{
public:
        Sphere(double r)
        {
                m_r = r;
        }
        double getS()
        {
                return 4*3.14*m_r*m_r;
        }
        double getV()
        {
                return (4.0/3)*3.14*m_r*m_r*m_r;
        }
private:
        double m_r;
};
class Cylinder:public Container
{
public:
        Cylinder(double r,double h)
        {
                m_r = r;
                m_h = h;
        }
        double getS()
        {
                return 3.14*m_r*m_r*2 + 2*3.14*m_r*m_h;
        }
        double getV()
        {
                return 3.14*m_r*m_r*m_h;
        }
private:
        double m_r;
        double m_h;
};
class Cube:public Container
{
public:
        Cube(double l)
        {
                m_l = l;
        }
        double getS()
        {
                return 6*m_l*m_l;
        }
        double getV()
        {
                return m_l*m_l*m_l;
        }
private:
        double m_l;//边长
};
int main()
{
        Sphere obj1(1);
        cout<<"该球的表面积为:"<<obj1.getS()<<"体积:"<<obj1.getV()<<endl;
        Cylinder obj2(1,1);
        cout<<"该圆柱的表面积为:"<<obj2.getS()<<"体积:"<<obj2.getV()<<endl;
        Cube obj3(10);
         cout<<"该正方体的表面积为:"<<obj3.getS()<<"体积:"<<obj3.getV()<<endl;
        return 0;
}










#include<iostream>
using namespace std;
class Shape
{
public:
        virtual double area() = 0;
};
class Circle:public Shape
{
public:
        Circle(double r)
        {
                radius = r;
        }
        double area()
        {
                return 3.14*radius*radius;
        }
private:
        double radius;//半径
};
class Rectangle:public Shape
{
public:
        Rectangle(double l,double w)
        {
                length = l;
                width = w;
        }
        double area()
        {
                return length*width;
        }
private:
        double length;
        double  width;
};
int main()
{
        Circle circlel(10);
        cout<<"面积为"<<circlel.area()<<endl;

        Rectangle rectangle1(2,3);
        cout<<"面积为"<<rectangle1.area()<<endl;
        return 0;
}






#include<iostream>
using namespace std;
class student
{
public:
        student(int a)
        {
                this->i = a;
        }
private:
        int i;
};
class S:public student
{
public:
        S(int a, int b) :student(a)
        {
                this->j = b;
        }
private:
        int j;
};
int main()
{
        return 0;
}



