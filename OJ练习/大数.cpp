#include <iostream>
#include <vector>
#include <string>
using namespace std;

string operator+(const string& num1, const string& num2)
{
    int end1 = num1.size() - 1, end2 = num2.size() - 1;
    int next = 0;//进位标志
    string strRet;
    while (end1 >= 0 || end2 >= 0)
    {
        int value1 = end1 >= 0 ? num1[end1] - '0' : 0;
        int value2 = end2 >= 0 ? num2[end2] - '0' : 0;
        int ret = value1 + value2 + next;
        next = ret > 9 ? 1 : 0;
        strRet += ((ret) % 10 + '0');
        --end1;
        --end2;
    }
    if (next) strRet += '1';
    reverse(strRet.begin(), strRet.end());
    return strRet;
}

string operator-(string& num1, string& num2)
{
    bool isNegative = false;//结果是否为负数
    if (num1.size() < num2.size()) {
        swap(num1, num2);
        isNegative = true;
    }
    if (num1.size() == num2.size())
    {
        int length = num1.size();
        for (int i = 0; i < length; ++i)
        {
            if (num1[i] == num2[i]) continue;
            else if (num1[i] > num2[i]) break;
            else {
                swap(num1, num2);
                isNegative = true;
                break;
            }
        }
    }
    string retNum;
    int sub = 0;//退位标志
    int end1 = num1.size() - 1, end2 = num2.size() - 1;
    while (end1 >= 0 || end2 >= 0)
    {
        int value1 = end1 >= 0 ? num1[end1--] - '0' : 0;
        int value2 = end2 >= 0 ? num2[end2--] - '0' : 0;
        int ret = 0;
        if (value1 >= value2 + sub) {
            ret = value1 - value2 - sub;
            sub = 0;
        }
        else {
            ret = 10 + value1 - value2 - sub;
            sub = 1;
        }
        retNum += to_string(ret);
    }
    while (retNum.size() > 1 && retNum.back() == '0') retNum.pop_back();
    reverse(retNum.begin(), retNum.end());
    if (isNegative) retNum += '-';
    return retNum;
}

string operator*(const string& num1, const string& num2)
{
    if (num1 == "0" || num2 == "0") return "0";
    int size1 = num1.size(), size2 = num2.size();
    vector<int> tmp(size1 + size2 - 1);
    //无进位相乘后相加
    for (int j = size2 - 1; j >= 0; --j)
        for (int i = size1 - 1; i >= 0; --i)
            tmp[i + j] += (num1[i] - '0') * (num2[j] - '0');
    //处理进位
    string ret = "";
    int current = size1 + size2 - 2, tmpNum = 0;
    while (current >= 0 || tmpNum > 0)
    {
        if (current >= 0) tmpNum += tmp[current--];
        ret.insert(ret.begin(), (tmpNum % 10) + '0');
        tmpNum /= 10;
    }
    return ret;
}

//num1是否大于等于num2
bool Compare(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 < len2) return false;
    else if (len1 == len2 && num1 < num2) return false;
    else return true;
}
string operator/(string& num1, string& num2)
{
    if (num2 == "0") return "ERROR";
    if (num1 == "0") return "0";
    if (!Compare(num1, num2)) return "0";//商为0

    string retNum, remainder;
    for (int i = 0; i < num1.size(); ++i)
    {
        int count = 0;

        remainder += num1[i];
        while (remainder.size() > 1 && remainder.front() == '0') remainder.erase(remainder.begin());

        while (Compare(remainder, num2))
        {
            remainder = remainder - num2;
            ++count;
        }
        retNum += to_string(count);
    }
    while (retNum.size() > 1 && retNum.front() == '0') retNum.erase(retNum.begin());
    return retNum;
}

//int main()
//{
//    string num1 = "29029029029058582908701160145";
//    string num2 = "29";
//    string ret = num1 / num2;
//    bool result = (num1 == (ret * num2));
//    cout << result << endl;
//	return 0;
//}