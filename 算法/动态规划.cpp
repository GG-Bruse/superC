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





//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minimumTotal(vector<vector<int> >& triangle) {
//        if (triangle.empty()) return 0;
//        int row = triangle.size();
//
//        for (int i = 1; i < row; ++i) {
//            for (int j = 0; j <= i; ++j) {
//                if (j == 0) triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
//                else if (j == i) triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
//                else triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
//            }
//        }
//        int min_sum = triangle[row - 1][0];
//        for (int j = 1; j < row; ++j) {
//            min_sum = min(min_sum, triangle[row - 1][j]);
//        }
//        return min_sum;
//    }
//};





//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minimumTotal(vector<vector<int> >& triangle) {
//        int row = triangle.size();
//        for (int i = row - 2; i >= 0; --i) {
//            for (int j = 0; j <= i; ++j) {
//                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
//            }
//        }
//        return triangle[0][0];
//    }
//};





//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        if (m < 1 || n < 1) return 0;
//
//        vector<vector<int>> v(m, vector<int>(n, 1));
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                v[i][j] = v[i - 1][j] + v[i][j - 1];
//            }
//        }
//        return v[m - 1][n - 1];
//    }
//};



















