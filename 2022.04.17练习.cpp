/*
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用 单个空格 分隔的单词组成。请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。

如果 searchWord 是某一个单词的前缀，则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。
如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord 不是任何单词的前缀，则返回 -1 。

字符串 s 的 前缀 是 s 的任何前导连续子字符串。
*/

#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int SentSize = sentence.size();
        int WordSize = searchWord.size();
        int count = 1;
        bool flag = true;
        for (int i = 0;i<SentSize;++i)
        {
            for (int j = 0; j < WordSize; ++j)
            {
                if (sentence[i+j] != searchWord[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                return count;
            }
            while (i < SentSize && sentence[i] != ' ')++i;
            ++count;
            flag = true;
        }
        return -1;
    }
};
int main()
{
    string sentence = "hellohello hellohellohello", searchWord = "ell";
    Solution s;
    cout<<s.isPrefixOfWord(sentence,searchWord);
        return 0;
}











/*
有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。

例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 s，考虑将其进行原语化分解，使得：s = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。

对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。
*/
/*
用stack保存 ( 所在的位置从0开始
遍历直到s为空，则截取这一段（去除头和尾的括号）插入到结果里
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        int n = S.size();
        stack<int> s;
        string res = "";
        for (int i = 0; i < n; ++i)
        {
            if (S[i] == '(')
            {
                s.push(i);
            }
            else
            {
                int start = s.top();
                s.pop();
                if (s.empty())
                {
                    res += S.substr(start + 1, i - start - 1);
                }
            }
        }
        return res;
    }
};
