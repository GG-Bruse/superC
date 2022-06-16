#pragma once
#include"Buyer.h"

//会员类
class member :public Buyer
{
public:
	member(string name, int ID, string address, double cost, int level);

	void print_img();
	void calculation_cost(double);

private:
	int Membership_level;//会员级别
};










