#pragma once
#include "string.h"
#include <iostream>
#include <fstream>
#include "vector.hpp"
#include <algorithm>
using std::swap;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::pair;
using namespace bjy;

typedef struct book{
	friend ostream& operator<< (ostream&, const struct book&);
	friend istream& operator>> (istream&, struct book&);
	struct book():ISBN(" "),name(" "),supplier(" "),author(" "),_quantity(" "), _price(" ") {}
	string ISBN;
	string name;
	string supplier;
	string author;

	string _quantity;//����
	string _price;//�۸�

	bool operator>(const book& bk)const {
		return atoll(ISBN.c_str()) > atoll(bk.ISBN.c_str());
	}
	bool operator==(const book& bk)const {
		return atoll(ISBN.c_str()) > atoll(bk.ISBN.c_str());
	}
	bool operator<(const book& bk)const {
		return !(operator>(bk) || operator==(bk));
	}
	bool operator>=(const book& bk)const {
		return operator>(bk) || operator==(bk);
	}
	bool operator<=(const book& bk)const {
		return operator<(bk) || operator==(bk);
	}
	
}book;

ostream& operator<< (ostream& out,const struct book& bk) {
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
	cout << "\t\t\t\t\t\t*                                                                     *" << endl;
	cout << "\t\t\t\t\t\t                   ����Ϊ     :" << bk.name << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t                   ISNBN��Ϊ  :" << bk.ISBN << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t                   ������Ϊ   :" << bk.supplier << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t                   ����Ϊ     :" << bk.author << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t                   �������Ϊ :" << bk._quantity << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t                   ����Ϊ     :" << bk._price << endl;
	cout << "\t\t\t\t\t\t*                                                                     *" << endl;
	cout << "\t\t\t\t\t\t************************************************************************" << endl;
	return out;
}
istream& operator>> (istream& in,struct book& bk) {
	in >> bk.ISBN;
	in >> bk.name;
	in >> bk.supplier;
	in >> bk.author;
	in >> bk._quantity;
	in >> bk._price;
	return  in;
}

void load_information(vector<book>& v) {
	char buff[32] = { 0 };
	size_t temp = 0;
	book tmp;
	ifstream fp("information.txt", ios::in);
	if (!fp.is_open()){
		ofstream fp("information.txt");
		fp.close();
		fp.open("information.txt");
	}
	for (int i = 0; fp.getline(buff, sizeof(buff)); ++i) {
		tmp.ISBN = buff;
		fp.getline(buff, sizeof(buff));
		tmp.name = buff;
		fp.getline(buff, sizeof(buff));
		tmp.supplier = buff;
		fp.getline(buff, sizeof(buff));
		tmp.author = buff;
		fp.getline(buff, sizeof(buff));
		tmp._quantity = buff;
		fp.getline(buff, sizeof(buff));
		tmp._price = buff;
		v.push_back(tmp);
	}
	fp.close();
}


bool add_book(vector<book>& v,book& bk,int pos) {
	if (pos < 0 || pos > v.size()) {
		cout << "��λ�ò��ɲ���!!!" << endl;
		return false;
	}
	else {
		vector<book>::iterator it = v.insert(v.begin() + pos, bk);
		return it != v.end();
	}
}




int search(const vector<book>& v, string& tmp) {
	int left = 0, right = (int)v.size() - 1;
	while (left <= right) {
		if (v[left].ISBN == tmp) return left;
		if (v[right].ISBN == tmp) return right;
		++left;
		--right;
	}
	return -1;
}



void show(const vector<book>& v) {
	if (v.size() == 0) {
		cout << endl << "��ͼ����Ϣ!!!" << endl;
	}
	else {
		for (size_t i = 0; i < v.size(); ++i) {
			cout << v[i];
		}
	}
}



//����ʽ1 : ʹ�ÿ�������
void QuickSort(vector<book>& arr, int left, int right)
{
	if (left >= right)return;

	int begin = left, end = right;
	int key = begin;
	while (begin < end)
	{
		while (begin < end && arr[end] >= arr[key])
		{
			--end;
		}
		while (begin < end && arr[begin] <= arr[key])
		{
			++begin;
		}
		swap(arr[begin], arr[end]);
	}
	swap(arr[begin], arr[key]);

	QuickSort(arr, left, begin - 1);
	QuickSort(arr, begin + 1, right);
}
void Sort(vector<book>& v) {
	QuickSort(v,0,v.size() - 1);
}
//����ʽ2 : ͨ���ṩ�º���ʹ���㷨�����㷨
class Compare {
public:
	bool operator()(const book& bk1,const book& bk2) {
		return (bk1 > bk2);
	}
};
void Sort_2(vector<book>& v) {
	sort(v.begin(), v.end(),Compare());
}


pair<size_t, double> statistics(const vector<book>& v) {
	pair<size_t, size_t> ret;
	size_t quantity = 0;
	double price = 0;
	for (vector<book>::const_iterator it = v.begin(); it != v.end(); ++it) {
		quantity += atoll((*it)._quantity.c_str());
		price += atof((*it)._price.c_str()) * atof((*it)._quantity.c_str());
	}
	return { quantity, price };
}

vector<int> find_by_key(vector<book>& bk,string& str) {
	vector<int> ret;
	for (size_t i = 0; i < bk.size(); ++i) {
		if (bk[i].ISBN.find(str.c_str()) != string::npos) {
			ret.push_back(i);
			continue;
		}
		if (bk[i].name.find(str.c_str()) != string::npos) {
			ret.push_back(i);
			continue;
		}
		if (bk[i].author.find(str.c_str()) != string::npos) {
			ret.push_back(i);
			continue;
		}
		if (bk[i].supplier.find(str.c_str()) != string::npos) {
			ret.push_back(i);
			continue;
		}
	}
	return ret;
}

void load_six(vector<book>& v) {
	book tmp[6];
	tmp[0].ISBN = "1";
	tmp[0].name = "���ݽṹ";
	tmp[0].supplier = "�����ʵ������";
	tmp[0].author = "��ε��";
	tmp[0]._quantity = "100";
	tmp[0]._price = "49.8";
	tmp[1].ISBN = "2";
	tmp[1].name = "��ɢ��ѧ";
	tmp[1].supplier = "�廪��ѧ������";
	tmp[1].author = "������";
	tmp[1]._quantity = "101";
	tmp[1]._price = "49.9";
	tmp[2].ISBN = "3";
	tmp[2].name = "ģ����Ӽ������������̳�";
	tmp[2].supplier = "�ߵȽ���������";
	tmp[2].author = "������";
	tmp[2]._quantity = "102";
	tmp[2]._price = "58.6";
	tmp[3].ISBN = "4";
	tmp[3].name = "C++������������ƽ̳�";
	tmp[3].supplier = "�廪��ѧ������";
	tmp[3].author = "��ά��";
	tmp[3]._quantity = "103";
	tmp[3]._price = "68.00";
	tmp[4].ISBN = "5";
	tmp[4].name = "C���Գ������";
	tmp[4].supplier = "���ӿƼ���ѧ������";
	tmp[4].author = "������";
	tmp[4]._quantity = "104";
	tmp[4]._price = "45.8";
	tmp[5].ISBN = "6";
	tmp[5].name = "��ָoffer";
	tmp[5].supplier = "���ӹ�ҵ������";
	tmp[5].author = "�κ���";
	tmp[5]._quantity = "105";
	tmp[5]._price = "65.00";
	for (int i = 0; i < sizeof(tmp) / sizeof(tmp[0]); ++i) {
		v.push_back(tmp[i]);
	}
}

bool save(const vector<book>& v) {
	ofstream fp("information.txt", ios::in | ios::trunc);
	if (!fp.is_open()) {
		fp.close();
		return false;
	}
	for (int i = 0; i < v.size(); ++i){
		fp << v[i].ISBN << endl;
		fp << v[i].name << endl;
		fp << v[i].supplier << endl;
		fp << v[i].author << endl;
		fp << v[i]._quantity << endl;
		fp << v[i]._price << endl;
	}
	fp.close();
	return true;
}