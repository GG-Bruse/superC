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




/*
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.empty()) return 0;
        const int row = grid.size();
        const int col = grid[0].size();
        for(int i = 1;i < col; ++i) grid[0][i] += grid[0][i - 1];
        for(int i = 1;i < row; ++i) grid[i][0] += grid[i - 1][0];
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[row - 1][col - 1];
    }
};
*/







//class Solution {
//public:
//    int backPackII(int m, vector<int>& a, vector<int>& v) {
//        if (a.empty() || v.empty() || m <= 0) return 0;
//
//        const int row = a.size() + 1;
//        const int col = m + 1;
//
//        vector<vector<int>> ret(row);
//        for (int i = 0; i < row; ++i) {
//            ret[i].resize(col, 0);
//        }
//
//        for (int i = 1; i < row; ++i) {
//            for (int j = 1; j < col; ++j) {
//                if (a[i - 1] > j) ret[i][j] = ret[i - 1][j];
//                else ret[i][j] = max(ret[i - 1][j], ret[i - 1][j - a[i - 1]] + v[i - 1]);
//            }
//        }
//        return ret[row - 1][col - 1];
//    }
//};







//class Solution {
//public:
//    int backPackII(int m, vector<int>& a, vector<int>& v) {
//        if (a.empty() || v.empty() || m <= 0) return 0;
//
//        vector<int> ret(m + 1);
//        for (int i = 1; i < a.size() + 1; ++i) {
//            for (int j = m; j >= 1; --j) {
//                if (a[i - 1] <= j) ret[j] = max(ret[j], ret[j - a[i - 1]] + v[i - 1]);
//            }
//        }
//        return ret[m];
//    }
//};







//class Solution {
//public:
//    bool isPal(string& s, int begin, int end)
//    {
//        while (begin < end) {
//            if (s[begin] != s[end]) return false;
//            ++begin;
//            --end;
//        }
//        return true;
//    }
//    int minCut(string s) {
//        int size = s.size();
//        if (size == 0 || isPal(s, 0, size - 1)) return 0;
//
//        vector<int> ret(size + 1);
//        for (int i = 1; i <= size; ++i) {
//            ret[i] = i - 1;
//        }
//
//        for (int i = 2; i <= size; ++i)
//        {
//            if (isPal(s, 0, i - 1)) {
//                ret[i] = 0;
//                continue;
//            }
//            for (int j = 1; j < i; ++j) {
//                if (isPal(s, j, i - 1)) ret[i] = min(ret[i], ret[j] + 1);
//            }
//        }
//        return ret[size];
//    }
//};




//class Solution {
//public:
//    vector<vector<bool>> GetMat(string& s) {
//        int size = s.size();
//        vector<vector<bool>> ret(size, vector<bool>(size, false));
//        for (int i = size - 1; i >= 0; --i) {
//            for (int j = i; j < size; ++j) {
//                if (i == j) ret[i][j] = true;
//                else if (j == i + 1) ret[i][j] = (s[i] == s[j]);
//                else ret[i][j] = ((s[i] == s[j]) && ret[i + 1][j - 1]);
//            }
//        }
//        return ret;
//    }
//    int minCut(string s) {
//        vector<vector<bool>> Mat = GetMat(s);
//
//        int size = s.size();
//        if (size == 0 || Mat[0][size - 1]) return 0;
//
//
//        vector<int> ret(size + 1);
//        for (int i = 0; i <= size; ++i) {
//            ret[i] = i - 1;
//        }
//
//        for (int i = 2; i <= size; ++i)
//        {
//            for (int j = 0; j < i; ++j) {
//                if (Mat[j][i - 1]) ret[i] = min(ret[i], ret[j] + 1);
//            }
//        }
//        return ret[size];
//    }
//};