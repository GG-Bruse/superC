//����
/*
1. ASCII����
�涨ʹ��һ���ֽڱ�ʾ��ĸ�������֮��Ķ�Ӧ��ϵ(ֻ�ܱ�ʾӢ��)

2. GB2312:
GB2312�Ժ��ֲ���˫�ֽڱ���

3. GBK:
1995��12�·����ĺ��ֱ�����ұ�׼���Ƕ�GB2312�������չ���Ժ��ֲ���˫�ֽڱ���

4. GBK18030:
�Ƕ�GBK�������չ�����õ��ֽڡ�˫�ֽں����ֽ����ַ�ʽ���ַ����롣����GBK��GB2312�ַ�����

5. Unicode����(�����):
Unicode��һЩ�����ı����ַ����������ױ��뷽ʽ�����Ƿֱ���UTF-8��UTF-16��UTF-32
	(1)UTF-8����:
	UTF-8��Unicode��ʵ�ַ�ʽ֮һ��UTF-8����һ���ص㣬��������һ�ֱ䳤�ı��뷽ʽ��������ʹ��1~4���ֽڱ�ʾһ�����ţ����ݲ�ͬ�ķ��Ŷ��仯�ֽڳ���
	(2)UTF-16:
	����UTF-8��UTF-32֮�䣬ʹ��2������4���ֽڴ洢�����ȼ��̶��ֿɱ䡣
	(3)UTF-32:
	һ�̶ֹ����ȵı��뷽���������Ը���Ŵ�С��ʼ��ʹ��4���ֽ����洢��
*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	const char test1[] = "������";
//	char test2[] = { -80,-4,-68,-47,-46,-29,0 };
//	cout << test1 << endl;
//	cout << test2 << endl;//������
//	return 0;
//}
































//C�����е��ַ���
/*
C�����У��ַ�������'\0'��β��һЩ�ַ��ļ��ϣ�Ϊ�˲������㣬C��׼�����ṩ��һЩstrϵ�еĿ⺯����
������Щ�⺯�����ַ����Ƿ��뿪�ģ���̫����OOP��˼�룬���ҵײ�ռ���Ҫ�û��Լ������Բ�������ܻ���Խ�����
*/



//string��
/*
1.�ַ����Ǳ�ʾ�ַ����е���

2.��׼���ַ������ṩ�˶Դ�������֧�֣���ӿ������ڱ�׼�ַ������Ľӿڣ��������ר�����ڲ������ֽ��ַ��ַ������������

3.string����ʹ��char��Ϊ�����ַ����ͣ�ʹ������Ĭ��char_traits�ͷ���������

4.string����basic_stringģ�����һ��ʵ������ʹ��char��ʵ����basic_stringģ���࣬����char_traits��allocator��Ϊbasic_string��Ĭ�ϲ���

5.������������ʹ�õı����������ֽ�:
������������ֽڻ�䳤�ַ�(��UTF-8)�����У����������г�Ա(�糤�Ȼ��С)�Լ����ĵ�����������Ȼ�����ֽ�(������ʵ�ʱ�����ַ�)��������


�ܽ�:
1.string�Ǳ�ʾ�ַ������ַ�����
2.����Ľӿ��볣�������Ľӿڻ�����ͬ���������һЩר����������string�ĳ��������
3.string�ڵײ�ʵ����:
basic_stringģ����ı�����typedef basic_string<char, char_traits, allocator>string;
4.���ܲ������ֽڻ��߱䳤�ַ������С�
5.��ʹ��string��ʱ���������#includeͷ�ļ��Լ�using namespace std;
*/































//string��ĳ��ýӿ�˵��(��ȫ,���ĵ�)

//string�����ĳ�������
/*
string()						����յ�string����󣬼����ַ���
string(const char* s)			��C-string������string�����
string(size_t n, char c)		string������а���n���ַ�c
string(const string&s)			�������캯��
*/



//string��������������
/*
size		�����ַ�����Ч�ַ�����
length		�����ַ�����Ч�ַ�����
capacity	���ؿռ��ܴ�С
empty		����ַ����Ƿ�Ϊ�մ����Ƿ���true�����򷵻�false
clear		�����Ч�ַ�
reserve		Ϊ�ַ���Ԥ���ռ�(���ռ�)
resize		����Ч�ַ��ĸ����ĳ�n��������Ŀռ����ַ�c���(���ռ�+��ʼ��)

ע��:
1. size()��length()�����ײ�ʵ��ԭ����ȫ��ͬ������size()��ԭ����Ϊ�������������Ľӿڱ���һ�£�һ������»���������size()��

2. clear()ֻ�ǽ�string����Ч�ַ���գ����ı�ײ�ռ��С��

3. resize(size_t n) �� resize(size_t n, char c)���ǽ��ַ�������Ч�ַ������ı䵽n����
��ͬ���ǵ��ַ���������ʱ:
resize(n)��0���������Ԫ�ؿռ䣬resize(size_t n, char c)���ַ�c���������Ԫ�ؿռ䡣
resize�ڸı�Ԫ�ظ���ʱ������ǽ�Ԫ�ظ������࣬���ܻ�ı�ײ������Ĵ�С������ǽ�Ԫ�ظ������٣��ײ�ռ��ܴ�С���䡣

4. reserve(size_t res_arg = 0):
ΪstringԤ���ռ䣬���ı���ЧԪ�ظ�������reserve�Ĳ���С��string�ĵײ�ռ��ܴ�Сʱ��reserve����ı�������С
*/



//string�����ķ��ʼ���������
/*
operator[]			����posλ�õ��ַ���const string��������
at					����posλ�õ��ַ���Խ�����쳣
begin + end			begin��ȡ��һ���ַ��ĵ����� + end��ȡ���һ���ַ���һ��λ�õĵ����� iterator
rbegin + rend		rbegin��ȡ���һ���ַ��ĵ����� +rend��ȡ��һ���ַ�ǰһ��λ�õĵ����� reverse_iterator
cbegin + cend		const_iterator
crbegin + crend		const_reverse_iterator
��Χfor				C++11֧�ָ����ķ�Χfor���±�����ʽ
*/



//string�������޸Ĳ���
/*
push_back		���ַ�����β���ַ�c
append			���ַ�����׷��һ���ַ���
operator+=		���ַ�����׷���ַ���str
c_str			����C��ʽ�ַ���
find + npos		���ַ���posλ�ÿ�ʼ�������ַ�c�����ظ��ַ����ַ����е�λ��
rfind			���ַ���posλ�ÿ�ʼ��ǰ���ַ�c�����ظ��ַ����ַ����е�λ��
substr			��str�д�posλ�ÿ�ʼ����ȡn���ַ���Ȼ���䷵��
erase			���ַ�����ɾ���ַ�

ע��:
1. ��stringβ��׷���ַ�ʱ��s.push_back(c) / s.append(1, c) / s += 'c'���ֵ�ʵ�ַ�ʽ��࣬
һ�������string���+=�����õıȽ϶࣬+=���������������ӵ����ַ��������������ַ�����

2. ��string����ʱ�����ܹ����Ԥ�����Ŷ����ַ���������ͨ��reserve�ѿռ�Ԥ����
*/
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string filename("strig.cpp");
//	filename += '\0';
//	filename += "STL.cpp";
//	cout << filename << endl;//strig.cppSTL.cpp		�Զ����sizeΪ׼
//	cout << filename.c_str() << endl;//strig.cpp	����'\0'��ֹ
//	return 0;
//}



//string��ǳ�Ա����
/*
operator+				�������ã���Ϊ��ֵ���أ��������Ч�ʵ�
operator>>				�������������
operator<<				������������
getline					��ȡһ���ַ���
relational operators	��С�Ƚ�

ת��:
stoi			Convert string to integer (function template )
stol			Convert string to long int (function template )
stoul			Convert string to unsigned integer (function template )
stoll			Convert string to long long (function template )
stoull			Convert string to unsigned long long (function template )
stof			Convert string to float (function template )
stod			Convert string to double (function template )
stold			Convert string to long double (function template )
to_string		Convert numerical value to string (function )
*/


































//vs��g++��string�ṹ��˵��
/*
ע��:�����ṹ����32λƽ̨�½�����֤��32λƽ̨��ָ��ռ4���ֽڡ�

1.vs��string�Ľṹ:
string�ܹ�ռ28���ֽڣ��ڲ��ṹ��΢����һ�㣬������һ�������壬��������������string���ַ����Ĵ洢�ռ�:
(1)���ַ�������С��16ʱ��ʹ���ڲ��̶����ַ����������
(2)���ַ������ȴ��ڵ���16ʱ���Ӷ��Ͽ��ٿռ�
ԭ��:
�����������ַ����ĳ��ȶ�С��16����string���󴴽���֮���ڲ��Ѿ�����16���ַ�����Ĺ̶��ռ䣬����Ҫͨ���Ѵ�����Ч�ʸ�

2.g++��string�Ľṹ:
g++�£�string��ͨ��дʱ����ʵ�ֵģ�string�����ܹ�ռ4���ֽڣ��ڲ�ֻ������һ��ָ�룬��ָ�뽫��ָ��һ��ѿռ䣬�ڲ������������ֶ�:
(1)�ռ��ܴ�С
(2)�ַ�����Ч����
(3)���ü���
(4)ָ��ѿռ��ָ�룬�����洢�ַ���
*/
/*
дʱ����:(˭д˭����)
�ӳٿ���,����ǳ�����Ļ���֮�����������ü����ķ�ʽ��ʵ�ֵġ�
���ü���:
������¼��Դʹ���ߵĸ������ڹ���ʱ������Դ�ļ�������1��ÿ����һ������ʹ�ø���Դ���͸���������1��
��ĳ����������ʱ���ȸ��ü�����1��Ȼ���ټ���Ƿ���Ҫ�ͷ���Դ��
�������Ϊ1��˵���ö���ʱ��Դ�����һ��ʹ���ߣ�������Դ�ͷţ�����Ͳ����ͷţ���Ϊ��������������ʹ�ø���Դ��
*/























//ģ��ʵ��string
/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::ostream;
using std::istream;
namespace bjy
{
	class string
	{
	public:
		//const static size_t npos = -1;//����:const static����ֱ�ӵ��ɶ����ʼ��
		static size_t npos;
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}



		string() :_str(new char[1]), _size(0), _capacity(0)
		{
			_str[0] = '\0';
		}
		//string(const char* str) :_str(new char[strlen(str) + 1]), _size(strlen(str)), _capacity(_size)//��ʼ��˳����������˳��
		//{
		//	strcpy(_str, str);//���ݿ���
		//}
		string(const char* str)
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);//���ݿ���
		}
		


		//��ͳд��
		//string(const string& str)//���
		//{
		//	_size = str._size;
		//	_capacity = str._capacity;
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, str._str);
		//}
		//�ִ�д��
		string(const string& str):_str(nullptr),_size(0),_capacity(0)//ʹ�ó�ʼ���б��ʼ�������⽻��������
		{
			string strTemp(str._str);//���ù��캯��
			swap(strTemp);
		}



		//string& operator=(const string& str)//��ͳд��
		//{
		//	if (this != &str)
		//	{
		//		char* pTemp = new char[strlen(str._str) + 1];
		//		strcpy(pTemp, str._str);
		//		delete[] _str;
		//		_str = pTemp;
		//		_size = str._size;
		//		_capacity = str._capacity;
		//	}
		//	return *this;
		//}
		//string& operator=(const string& str)//�ִ�д��1
		//{
		//	if (this != &str)
		//	{
		//		string strTemp(str._str);
		//		swap(strTemp);
		//	}
		//	return *this;
		//}
		string& operator=(string str)//�ִ�д��2:ͨ����ֵ���Σ�ʹ��str����strTemp
		{
			swap(str);
			return *this;
		}


		
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		bool operator>(const string& str)const
		{
			return strcmp(_str, str._str) > 0;
		}
		bool operator==(const string& str)const
		{
			return strcmp(_str, str._str) == 0;
		}
		bool operator>=(const string& str)const
		{
			return (*this > str || *this == str);
		}
		bool operator<=(const string& str)const
		{
			return !(*this > str);
		}
		bool operator<(const string& str)const
		{
			return !(*this >= str);
		}

		

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size >= _capacity)
				reserve(_capacity == 0 ? 3 : _capacity * 2);
			for (size_t end = _size + 1; end > pos; --end)
			{
				_str[end] = _str[end - 1];
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t lenth = strlen(str);
			if (_size + lenth >= _capacity)
				reserve(_capacity + lenth);
			for (size_t end = _size + lenth; end >= pos + lenth; --end)
			{
				_str[end] = _str[end - lenth];
			}
			strncpy(_str + pos, str, lenth);
			_size += lenth;
			return *this;
		}
		void push_back(char ch)
		{
			insert(_size,ch);
		}
		void append(size_t num, char ch)
		{
			reserve(_size + num);//����������
			for (size_t i = 0; i < num; ++i)
			{
				push_back(ch);
			}
		}
		void append(const char* str)
		{
			insert(_size, str);
		}
		void append(const string& str)
		{
			append(str._str);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(const string& str)
		{
			append(str._str);
			return *this;
		}



		void reserve(size_t num)
		{
			if (num > _capacity)
			{
				char* temp = new char[num + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = num;
			}
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		void erase(size_t pos ,size_t lenth = npos)
		{
			assert(pos < _size);
			if (lenth == npos || pos + lenth >= _size)//��Ҫɾ��
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + lenth);
				_size -= lenth;
			}
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}
		size_t find(char ch, size_t pos = 0)const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (ch == _str[i])
				{ 
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0)
		{
			assert(sub);
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, sub);
			if (ptr == nullptr)
				return npos;
			return ptr - _str;
		}
		string substr(size_t pos = 0, size_t len = npos)const
		{
			assert(pos < _size);
			size_t realLenth = len;
			if (len == npos || len + len > _size)
			{
				realLenth = _size - pos;
			}
			string strTemp;
			for (size_t i = 0; i < realLenth; ++i)
			{
				strTemp += _str[pos + i];
			}
			return strTemp;
		}
		
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
	private:
		void swap(string& strTemp)
		{
			::swap(_str, strTemp._str);
			::swap(_size, strTemp._size);
			::swap(_capacity, strTemp._capacity);
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	size_t string::npos = -1;
	ostream& operator<<(ostream& out, const string& str)
	{
		out << str.c_str();
		return out;
	}
	istream& operator>>(istream& in, string& str)
	{
		str.clear();
		const size_t N = 32;
		char buff[N];
		size_t i = 0;
		for(char chTemp = in.get();chTemp != ' ' && chTemp != '\n'; chTemp = in.get())
		{
			buff[i++] = chTemp;
			if (i == N - 1)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
		}
		buff[i] = '\0';
		str += buff;
		return in;
	}
}



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
	cin >> str6>>str7;
	cout << str6 <<str7<< endl;

	return 0;
}
*/




























































