#include"Student.h"
Student::Student(string name, int age, int ID, string address, int grades)
{
	this->m_name = name;
	this->m_age = age;
	this->m_ID = ID;
	this->m_address = address;
	this->m_grades = grades;
}
void Student::amend(string name, int age, int ID, string address, int grades)
{
	this->m_name = name;
	this->m_age = age;
	this->m_ID = ID;
	this->m_address = address;
	this->m_grades = grades;
}
string Student::ShowName()
{
	return this->m_name;
}
int Student::ShowAge()
{
	return this->m_age;
}
int Student::ShowID()
{
	return this->m_ID;
}
string Student::ShowAddress()
{
	return this->m_address;
}
int Student::ShowGrades()
{
	return this->m_grades;
}