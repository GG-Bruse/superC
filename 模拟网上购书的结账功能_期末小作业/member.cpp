#include"member.h"

member::member(string name, int ID, string address, double cost, int level) :Buyer(name, ID, address, cost)
{
	this->Membership_level = level;
}

void member::print_img()
{
	cout << "购书人姓名:       " << this->m_name << endl;
	cout << "购书人编号:       " << this->m_ID << endl;
	cout << "购书人为会员,级别:" << this->Membership_level << endl;
	cout << "购书人邮寄地址:   " << this->m_address << endl;
}

void member::calculation_cost(double temp)
{
	switch (Membership_level)
	{
	case 1:
		this->m_cost = temp * 0.95;
		break;
	case 2:
		this->m_cost = temp * 0.9;
		break;
	case 3:
		this->m_cost = temp * 0.85;
		break;
	case 4:
		this->m_cost = temp * 0.8;
		break;
	case 5:
		this->m_cost = temp * 0.7;
		break;
	default:
		cout << "无该等级" << endl;
		break;
	}
}


