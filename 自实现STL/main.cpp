#include"string.h"
#include"vector.hpp"
#include"list.hpp"
#include"stack.hpp"
#include"queue.hpp"
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









//list_main
#include<iostream>
#include<algorithm>
using namespace bjy;
using std::cout;
using std::endl;
using std::find;
struct Pos
{
	int _x;
	int _y;
};
int main_list1()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);

	list<int>::iterator it = l1.begin();
	for (; it != l1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	it = l1.begin();
	for (; it != l1.end(); it++) {
		(*it) *= 2;
	}
	it != l1.begin();
	for (auto e : l1) {
		cout << e << " ";
	}
	cout << endl;

	struct Pos pos1 { 10, 20 };
	struct Pos* p = &pos1;
	cout << p->_x << " " << p->_y << endl;//本质为p->->_x 编译器为了可读性进行了特殊处理
	return 0;
}
void func(const list<int>& l)
{
	list<int>::const_iterator it = l.begin();
	list<int>::const_iterator its = l.end();
	while (it != its)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main_list2()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	func(l1);
	return 0;
}
int main_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = lt.begin();
	while (it != lt.end())
	{
		*it *= 2;
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_front(10);
	lt.push_front(20);
	lt.push_front(30);
	lt.push_front(40);

	lt.pop_back();
	lt.pop_back();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	auto pos = find(lt.begin(), lt.end(), 4);
	if (pos != lt.end())
	{
		// pos是否会失效？不会
		lt.insert(pos, 40);
		//lt.insert(pos, 30);
		*pos *= 100;
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
int main_list4()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);

	list<int> lt2 = lt1;

	*(lt2.begin()) = 100;
	for (list<int>::iterator it = lt1.begin(); it != lt1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (list<int>::iterator it = lt2.begin(); it != lt2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	list<int>lt3;
	lt3 = lt1;
	*(--lt3.end()) = 100;
	for (list<int>::iterator it = lt3.begin(); it != lt3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}





//stack_main
int main_stack()
{
	stack<int> sk;
	for (size_t i = 0; i < 10; ++i) { sk.push(i + 1); }
	while (!sk.empty()) {
		cout << sk.top() << " ";
		sk.pop();
	}
	cout << endl;
	return 0;
}






//queue_main
int main()
{
	priority_queue<int> heap;
	heap.push(5);
	heap.push(3);
	heap.push(2);
	heap.push(0);
	heap.push(4);
	heap.push(1);
	while (!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	priority_queue<int, vector<int>, greater<int>> heap2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	while (!heap2.empty()) {
		cout << heap2.top() << " ";
		heap2.pop();
	}
	cout << endl;

	return 0;
}