#include"member.h"

member::member(string name, int ID, string address, double cost, int level) :Buyer(name, ID, address, cost)
{
	this->Membership_level = level;
}

void member::print_img()
{
	cout << "����������:       " << this->m_name << endl;
	cout << "�����˱��:       " << this->m_ID << endl;
	cout << "������Ϊ��Ա,����:" << this->Membership_level << endl;
	cout << "�������ʼĵ�ַ:   " << this->m_address << endl;
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
		cout << "�޸õȼ�" << endl;
		break;
	}
}


