#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Student
{
public:
	Student() = default;
	Student(string name, int age, int ID, string address, int grades);
	void amend(string name, int age, int ID, string address, int grades);
public:
	string ShowName();
	int ShowAge();
	int ShowID();
	string ShowAddress();
	int ShowGrades();
private:
	string m_name;
	int m_age;
	int m_ID;
	string m_address;
	int m_grades;
};
extern vector<Student*>v;