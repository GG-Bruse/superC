/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作
*/





#include<iostream>
#include<stack>
using namespace std;
class MyQueue
{
public:
    MyQueue() = default;
    void push(int x)
    {
        st_in.push(x);
    }
    int pop()
    {
        if (!st_out.empty())
        {
            int val = st_out.top();
            st_out.pop();
            return val;
        }
        else
        {
            while (!st_in.empty())
            {
                int val = st_in.top();
                st_in.pop();
                st_out.push(val);
            }
            if (!st_out.empty())
            {
                int val = st_out.top();
                st_out.pop();
                return val;
            }
            return -1;
        }
    }
    int peek()
    {
        if (!st_out.empty())
        {
            int val = st_out.top();
            return val;
        }
        else
        {
            while (!st_in.empty())
            {
                int val = st_in.top();
                st_in.pop();
                st_out.push(val);
            }
            if (!st_out.empty())
                return st_out.top();
            return -1;
        }
    }
    bool empty()
    {
        if (st_in.empty() && st_out.empty())
        {
            return true;
        }
        return false;
    }
private:
    stack<int> st_in;
    stack<int> st_out;
};







