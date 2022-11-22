#include"Ordinary_users.h"

void Ordinary_users::print_img()
{
	cout << endl;
	cout << "购书人姓名:     " << this->m_name << endl;
	cout << "购书人编号:     " << this->m_ID << endl;
	cout << "购书人为普通用户" << endl;
	cout << "购书人邮寄地址: " << this->m_address << endl;
}

void Ordinary_users::calculation_cost(double temp)
{
	this->m_cost += temp;
}