#pragma once
#include"Buyer.h"

//��ͨ��Ա��
class Ordinary_users :public Buyer
{
public:
	Ordinary_users(string name, int ID, string address, double cost) :Buyer(name, ID, address, cost) {}

	void print_img();

	void calculation_cost(double);
};