#include"vip.h"

vip::vip(string name, int ID, string address, double cost, double dis) :Buyer(name, ID, address, cost)
{
	this->Discount_rate = dis;
}

void vip::print_img()
{
	cout << "����������:         " << this->m_name << endl;
	cout << "�����˱��:         " << this->m_ID << endl;
	cout << "������Ϊ���,�ۿ���:" << endl;
	cout << "�������ʼĵ�ַ:     " << this->m_address << endl;
}

void vip::calculation_cost(double temp)
{
	this->m_cost += (1 - temp) * temp;
}