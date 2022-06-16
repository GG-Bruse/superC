#include"vip.h"

vip::vip(string name, int ID, string address, double cost, double dis) :Buyer(name, ID, address, cost)
{
	this->Discount_rate = dis;
}

void vip::print_img()
{
	cout << "购书人姓名:         " << this->m_name << endl;
	cout << "购书人编号:         " << this->m_ID << endl;
	cout << "购书人为贵宾,折扣率:" << endl;
	cout << "购书人邮寄地址:     " << this->m_address << endl;
}

void vip::calculation_cost(double temp)
{
	this->m_cost += (1 - temp) * temp;
}