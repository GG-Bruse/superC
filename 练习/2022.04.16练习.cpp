/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
*/
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        for (string::reverse_iterator its = s.rbegin(); its != s.rend(); ++its)
        {
            if (*its != ' ')
            {
                ++count;
            }
            if (*its != ' ' && *(its + 1) == ' ')
            {
                break;
            }
        }
        return count;
    }
};
int main()
{
    string str = "   fly me   to   the moon  ";
    Solution s;
    cout<<s.lengthOfLastWord(str);
        return 0;
}











/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
*/

/*
充分理解题意后，我们可以发现，当字符串中同时有多组相邻重复项时，我们无论是先删除哪一个，都不会影响最终的结果。因此我们可以从左向右顺次处理该字符串。

而消除一对相邻重复项可能会导致新的相邻重复项出现，如从字符串abba 中删除bb 会导致出现新的相邻重复项}aa 出现。
因此我们需要保存当前还未被删除的字符。一种显而易见的数据结构呼之欲出：栈。我们只需要遍历该字符串，如果当前字符和栈顶字符相同，我们就贪心地将其消去，否则就将其入栈即可。
*/
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string stk;
        for (string::iterator it = s.begin(); it != s.end(); ++it)
        {
            if (!stk.empty() && stk.back() == *it)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(*it);
            }
        }
        return stk;
    }
};
int main()
{
    string str = "abbaca";
    Solution s;
    cout<<s.removeDuplicates(str);
    return 0;
}
