//#include <vector>
//class Solution {
//public:
//    int Fibonacci(int n) {
//        std::vector<int> v(40);
//        v[1] = v[2] = 1;
//        for (int i = 3; i <= n; ++i) {
//            v[i] = v[i - 1] + v[i - 2];
//        }
//        return v[n];
//    }
//};




//class Solution {
//public:
//    int Fibonacci(int n) {
//        if (n == 1 || n == 2) return 1;
//        int Fib1 = 1, Fib2 = 1;
//        int ret = 0;
//        for (int i = 3; i <= n; ++i) {
//            ret = Fib1 + Fib2;
//            Fib1 = Fib2;
//            Fib2 = ret;
//        }
//        return ret;
//    }
//};





//#include <vector>
//#include <string>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    bool wordBreak(string s, unordered_set<string>& dict) {
//        if (s.empty()) return false;
//        if (dict.empty()) return false;
//
//        vector<bool> can_break(s.size() + 1, false);
//        can_break[0] = true;//³õÊ¼×´Ì¬(¸¨Öú×´Ì¬)
//        for (int i = 1; i <= s.size(); ++i)
//        {
//            //j < i && F(j) && [j + 1, i]
//            for (int j = 0; j < i; ++j)
//            {
//                if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end())
//                {
//                    can_break[i] = true;
//                    break;
//                }
//            }
//        }
//        return can_break[s.size()];
//    }
//};






















