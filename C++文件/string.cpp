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






