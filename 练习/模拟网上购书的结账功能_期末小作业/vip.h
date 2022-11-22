#pragma once
#include"Buyer.h"

//¹ó±öÀà
class vip :public Buyer
{
public:
	vip(string name, int ID, string address, double cost, double dis);

	void print_img();
	void calculation_cost(double);

private:
	double Discount_rate;//ÕÛ¿ÛÂÊ
};

