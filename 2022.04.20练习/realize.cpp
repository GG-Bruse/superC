#include<iostream>
#include"realize.h"
#include"Student.h"
using namespace std;
void display(Student* p)
{
	cout << "������" << p->ShowName() << endl;
	cout << "���䣺" << p->ShowAge() << endl;
	cout << "ѧ�ţ�" << p->ShowID() << endl;
	cout << "��ͥ��ַ��" << p->ShowAddress() << endl;
	cout << "��ѧ����ĩ�ɼ�" << p->ShowGrades() << endl;
}
void AddStudent(string name, int age, int ID, string address, int grades)
{
	Student* p = new Student(name,age,ID,address,grades);
	v.push_back(p);
}

void DeleteStudent(string name)
{
	for (vector<Student*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if ((*it)->ShowName() == name)
		{
			v.erase(it);
			v.resize(v.size() - 1);
			break;
		}
	}
}
void DeleteStudent(int ID)
{
	for (vector<Student*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if ((*it)->ShowID() == ID)
		{
			v.erase(it);
			v.resize(v.size() - 1);
			break;
		}
	}
}

void SearchStudent(string name)
{
	for (vector<Student*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if ((*it)->ShowName() == name)
		{
			display(*it);
		}
	}
}

void AmendStudent(string name)
{
	vector<Student*>::iterator its;
	int age, ID, grades;
	string address;
	for (vector<Student*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if ((*it)->ShowName() == name)
		{
			its = it;
		}
	}
	cout << "����������" << endl;

	cout << "������ѧ��" << endl;

	cout << "�������ַ" << endl;

	cout << "������ɼ�" << endl;

}