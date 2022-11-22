#include"Book.h"

Book::Book(string name, string ID, string author, string press, double price)
{
	this->BookName = name;
	this->BookID = ID;
	this->BookAuthor = author;
	this->BookPress = press;
	this->Book_price = price;
}

void Book::print_img()
{
	cout << "���:" << this->BookID << '\t';
	cout << "����:" << this->BookName << '\t';
	cout << "����:" << this->BookAuthor << endl;
	cout << "������:" << this->BookPress << '\t';
	cout << "����:" << this->Book_price << endl;
}

string Book::GetName()
{
	return this->BookName;
}

string Book::GetID()
{
	return this->BookID;
}

string Book::GetAuthor()
{
	return this->BookAuthor;
}

string Book::GetPress()
{
	return this->BookPress;
}

double Book::GetPrice()
{
	return this->Book_price;
}