/******************************************** 省份数量（LeetCode）*********************************************/
/*
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，
且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
而 isConnected[i][j] = 0 表示二者不直接相连。
返回矩阵中 省份 的数量
*/
//并查集
//#include <iostream>
//#include <vector>
//using namespace std;
//class UnionFindSet
//{
//public:
//    UnionFindSet(size_t size) :_ufs(size, -1) {}
//    int FindRoot(int value)
//    {
//        int root = value;
//        while (_ufs[root] >= 0) root = _ufs[root];
//        return root;
//    }
//    bool Union(int value1, int value2)
//    {
//        int root1 = FindRoot(value1);
//        int root2 = FindRoot(value2);
//        //本身在同一个集合,不需合并
//        if (root1 == root2) return false;
//        //合并操作
//        _ufs[root1] += _ufs[root2];
//        _ufs[root2] = root1;
//        return true;
//    }
//    int IsInSet(int value1, int value2) {
//        return FindRoot(value1) == FindRoot(value2);
//    }
//    size_t GetSetSize()
//    {
//        size_t count = 0;
//        for (int i = 0; i < _ufs.size(); ++i)
//            if (_ufs[i] < 0) ++count;
//        return count;
//    }
//private:
//    vector<int> _ufs;
//};
//class Solution1
//{
//public:
//    int findCircleNum(vector<vector<int>>& isConnected)
//    {
//        UnionFindSet ufs(isConnected.size());
//        for (size_t i = 0; i < isConnected.size(); ++i)
//            for (size_t j = 0; j < isConnected[0].size(); ++j)
//                if (isConnected[i][j] == 1) ufs.Union(i, j);
//        return ufs.GetSetSize();
//    }
//};
//class Solution2
//{
//public:
//    int findCircleNum(vector<vector<int>>& isConnected)
//    {
//        vector<int> ufs(isConnected.size(), -1);
//        auto findRoot = [&ufs](int value) {
//            while (ufs[value] >= 0) value = ufs[value];
//            return value;
//        };
//        auto getSetSize = [&ufs]() {
//            size_t count = 0;
//            for (int i = 0; i < ufs.size(); ++i)
//                if (ufs[i] < 0) ++count;
//            return count;
//        };
//        for (size_t i = 0; i < isConnected.size(); ++i)
//            for (size_t j = 0; j < isConnected[0].size(); ++j)
//                if (isConnected[i][j] == 1)
//                {
//                    int root1 = findRoot(i);
//                    int root2 = findRoot(j);
//                    if (root1 != root2)
//                    {
//                        ufs[root1] += ufs[root2];
//                        ufs[root2] = root1;
//                    }
//                }
//        return getSetSize();
//    }
//};









/**************************************** 等式方程的可满足性（LeetCode）***************************************/
/*
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，
并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false
*/
////并查集
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool equationsPossible(vector<string>& equations)
//    {
//        vector<int> ufs(26, -1);
//        auto findRoot = [&ufs](int value) {
//            while (ufs[value] >= 0) value = ufs[value];
//            return value;
//        };
//        //第一遍,先把相等的值合并到一个集合中
//        for (auto& str : equations)
//        {
//            if (str[1] == '=')
//            {
//                int root1 = findRoot(str[0] - 'a');
//                int root2 = findRoot(str[3] - 'a');
//                if (root1 != root2)
//                {
//                    ufs[root1] += ufs[root2];
//                    ufs[root2] = root1;
//                }
//            }
//        }
//        //第二遍,查看不相等的值在不在一个集合,在就相悖,返回false
//        for (auto& str : equations)
//        {
//            if (str[1] == '!')
//            {
//                int root1 = findRoot(str[0] - 'a');
//                int root2 = findRoot(str[3] - 'a');
//                if (root1 == root2) return false;
//            }
//        }
//        return true;
//    }
//};