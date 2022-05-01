#include"DynamicArray.h"
#include"LinkList.h"
#include"StackArray.h"
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person() = default;
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
int main()
{
	Stack sk;
	Person* p1 = new Person("a", 1);
	Person* p2 = new Person("b", 2);
	Person* p3 = new Person("c", 3);
	Person* p4 = new Person("d", 4);
	Person* p5 = new Person("e", 5);

	sk.top_back(p1);
	sk.top_back(p2);
	sk.top_back(p3);
	sk.top_back(p4);
	sk.top_back(p5);

	cout << sk.isEmpty() << " " << sk.size() << endl;

	cout << ((Person*)sk.top())->m_name << " " << ((Person*)sk.top())->m_age << endl;
	sk.pop_back();
	cout << ((Person*)sk.top())->m_name << " " << ((Person*)sk.top())->m_age << endl;
	sk.pop_back();
	cout << ((Person*)sk.top())->m_name << " " << ((Person*)sk.top())->m_age << endl;
	sk.pop_back();
	cout << ((Person*)sk.top())->m_name << " " << ((Person*)sk.top())->m_age << endl;
	sk.pop_back();
	cout << ((Person*)sk.top())->m_name << " " << ((Person*)sk.top())->m_age << endl;

	return 0;
}