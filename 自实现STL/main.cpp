#include"string.h"
#include"vector.hpp"
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::find;
using namespace bjy;
int main_string()
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





//main_vector
int main1()
{
	vector<int>v;
	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(i + 1);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	v.insert(it, 30);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(i + 1);
	}

	it = find(v.begin(), v.end(), 5);
	v.erase(it);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end();) {
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else {
			++it;
		}
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
int main2()
{
	vector<int>v;
	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	vector<int>v1(v);
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}

	vector<int>v2;
	v2 = v1;
	v1[0] *= 10;
	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}

	return 0;
}
int main3()
{
	vector<int>v(10, 1);//调用vector(size_t n, const_reference val = T())函数
	//C++中内置类型升级，存在构造函数
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	return 0;
}
int main4()
{
	vector<int>v;
	v.resize(10);
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	for (size_t i = 1; i <= 100; ++i)
		v.push_back(i);
	v.resize(20);
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	return 0;
}

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		static vector<vector<int>> ret(numRows);
		for (int i = 0; i < numRows; ++i)
		{
			ret[i].resize(i + 1);//每行大小设置
			ret[i][0] = ret[i][i] = 1;//每行第一个和最后一个元素都为1，其他元素也暂时赋值为1
			for (int j = 1; j < i; ++j)
			{
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];//元素的值等于 上一行该位置的值 加 上一行对应位置前一个的值
			}
		}
		return ret;
	}
};
int main5()
{
	vector<vector<int>>ret = Solution().generate(5);
	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}