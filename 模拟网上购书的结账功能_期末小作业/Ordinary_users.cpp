#include"Ordinary_users.h"

void Ordinary_users::print_img()
{
	cout << endl;
	cout << "����������:     " << this->m_name << endl;
	cout << "�����˱��:     " << this->m_ID << endl;
	cout << "������Ϊ��ͨ�û�" << endl;
	cout << "�������ʼĵ�ַ: " << this->m_address << endl;
}

void Ordinary_users::calculation_cost(double temp)
{
	this->m_cost += temp;
}