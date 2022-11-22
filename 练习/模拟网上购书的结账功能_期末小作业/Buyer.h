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

	virtual void print_img() = 0;//输出相关信息
	virtual void calculation_cost(double) = 0;//计算费用

protected:
	string m_name;
	int m_ID;//会员号
	string m_address;
	double m_cost;//费用
};