#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book
{
public:
	Book(string, string, string, string, double);

	void print_img();

	string GetName();
	string GetID();
	string GetAuthor();
	string GetPress();
	double GetPrice();

private:
	string BookName;
	string BookID;
	string BookAuthor;
	string BookPress;//³ö°æÉç
	double Book_price;
};
