#include"string.h"
using namespace bjy;
int main()
{
	string str1("hahaha");
	cout << str1.c_str() << endl;
	string str2;
	cout << str2.c_str() << endl;

	for (size_t i = 0; i < str1.size(); ++i)
	{
		str1[i] = 'b';
	}
	for (size_t i = 0; i < str1.size(); ++i)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	for (string::iterator it = str1.begin(); it != str1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto ch : str1)
	{
		cout << ch << " ";
	}
	cout << endl;

	string str3("1111111111111");
	string str4(str3);
	str3[0] = 'b';
	cout << str3.c_str() << endl;
	cout << str4.c_str() << endl;

	str3 = str4;
	str4[0] = 'j';
	cout << str3.c_str() << endl;
	cout << str4.c_str() << endl;

	str3.push_back('y');
	cout << str3.c_str() << endl;

	str3 += 'y';
	cout << str3.c_str() << endl;

	str3.append("yyy");
	cout << str3.c_str() << endl;

	str3 += "yyy";
	cout << str3.c_str() << endl;

	str3 += str4;
	cout << str3.c_str() << endl;

	str3.insert(3, 'b');
	cout << str3.c_str() << endl;

	str3.insert(4, "jy");
	cout << str3.c_str() << endl;

	str3.erase(6);
	cout << str3.c_str() << endl;

	string str5("bjyhahaha");
	cout << str5 << endl;

	string str8("hello world");
	cout << str8[str8.find('l')] << endl;
	str8 = str8.substr(2);
	cout << str8 << endl;
	str8.resize(100);
	cout << str8.size() << endl;;

	string str6("hello");
	string str7;
	cin >> str6 >> str7;
	cout << str6 << str7 << endl;

	return 0;
}