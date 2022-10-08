#include"DynamicArray.h"
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(string n, int a)
	{
		this->name = n;
		this->age = a;
	}
	string name;
	int age;
};
void MyPrint(void* p)
{
	cout << "姓名为" << ((Person*)p)->name << " ";
	cout << "年龄为" << ((Person*)p)->age << endl;
}
bool MyCompare(void* p, void* v)
{
	if (((Person*)p)->age == ((Person*)v)->age)
	{
		return true;
	}
	return false;
}
int main()
{
	dynamicArray dy(100);
	Person* p1 = new Person("a", 3);
	Person* p2 = new Person("b", 2);
	Person* p3 = new Person("c", 3);
	Person* p4 = new Person("d", 1);
	dy.push_back(p1);
	dy.push_back(p2);
	dy.push_back(p3);
	dy.push_back(p4);

	dy.remove(p4, MyCompare);

	dy.for_each(MyPrint);
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	return 0;
}