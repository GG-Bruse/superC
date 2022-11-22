#include"Buyer.h"
#include<string>

Buyer::Buyer(string name, int ID, string address, double cost)
{
	this->m_name = name;
	this->m_ID = ID;
	this->m_address = address;
	this->m_cost = cost;
}

string Buyer::GetName()
{
	return this->m_name;
}

int Buyer::GetId()
{
	return this->m_ID;
}

string Buyer::GetAddress()
{
	return this->m_address;
}

double Buyer::GetCost()
{
	return this->m_cost;
}