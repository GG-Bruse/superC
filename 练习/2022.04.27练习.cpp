#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
        Student(string name1, string stu_no1, float score1);
        ~Student();
        void show();
        void show_count_sum_ave();
private:
        string name;
        string stu_no;
        float score;
        static int count;
        static float sum;
        static float ave;
};
Student::Student(string name1, string stu_no1, float score1)
{
        name = name1;
        stu_no = stu_no1;
        score = score1;
        ++count;
        sum += score;
        ave = sum / count;
}
Student::~Student()
{
        --count;
        sum = sum - score;
}
void Student::show()
{
        cout << "\n姓名：" << name;
        cout << "\n学号：" << stu_no;
        cout << "\n成绩：" << score;
}
void Student::show_count_sum_ave()
{
        cout << "\n学生人数：" << count << endl;
        cout << "\n平均成绩：" << ave << endl;
}
int Student::count = 0;
float Student::sum = 0.0;
float Student::ave = 0.0;
int main()
{
        Student stu1("李明", "08150201",90);
        stu1.show();
        stu1.show_count_sum_ave();
        Student stu2("张大伟","08150202",80);
        stu2.show();
        stu2.show_count_sum_ave();
        return 0;
}









#include<iostream>
using namespace std;
class Small_cat
{
public:
        Small_cat(double w);
        void diaplay();
        static void total_disp();
private:
        double weight;
        static double total_weight;
        static double total_number;
};
Small_cat::Small_cat(double w)
{
        weight = w;
        total_weight += w;
        ++total_number;

}
void Small_cat::diaplay()
{
        cout << "这只小猫的重量为：" << this->weight <<"千克"<< endl;
}
void Small_cat::total_disp()
{
        cout << total_number << "只小猫的重量为:";
        cout << total_weight << "千克" << endl;
}
double Small_cat::total_weight = 0;
double Small_cat::total_number = 0;
int main()
{
        Small_cat w1(0.5), w2(0.6), w3(0.4);
        w1.diaplay();
        w2.diaplay();
        w3.diaplay();
        Small_cat::total_disp();
        return 0;
}




#include<iostream>
using namespace std;
class Small_cat
{
public:
        Small_cat(double w);
        static void diaplay(Small_cat& w);
        static void total_disp();
private:
        double weight;
        static double total_weight;
        static double total_number;
};
Small_cat::Small_cat(double w)
{
        weight = w;
        total_weight += w;
        ++total_number;

}
void Small_cat::diaplay(Small_cat& w)
{
        cout << "这只小猫的重量为：" << w.weight << "千克" << endl;
}
void Small_cat::total_disp()
{
        cout << total_number << "只小猫的重量为:";
        cout << total_weight << "千克" << endl;
}
double Small_cat::total_weight = 0;
double Small_cat::total_number = 0;
int main()
{
        Small_cat w1(0.5), w2(0.6), w3(0.4);
        Small_cat::diaplay(w1);
        Small_cat::diaplay(w2);
        Small_cat::diaplay(w3);
        Small_cat::total_disp();
        return 0;
}
