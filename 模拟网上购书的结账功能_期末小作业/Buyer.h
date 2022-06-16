#pragma once
#include<iostream>
#include<string>
using namespace std;
class Buyer
{
public:
	Buyer() = default;
	Buyer(string, int, string, double);

	string GetName();
	int GetId();
	string GetAddress();
	double GetCost();

	virtual void print_img() = 0;//��������Ϣ
	virtual void calculation_cost(double) = 0;//�������

protected:
	string m_name;
	int m_ID;//��Ա��
	string m_address;
	double m_cost;//����
};