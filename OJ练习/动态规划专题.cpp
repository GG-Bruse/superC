/*********************************************************** 解码方法（LeetCode）**********************************************************/
/*
一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
要解码已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的非空字符串s ，请计算并返回解码方法的总数 
题目数据保证答案肯定是一个 32 位 的整数
*/

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution_1 {
//public:
//    int numDecodings(string s)
//    {
//        //状态dp[i]: 从下标0到i处的子串，解码方法的总数
//        vector<int> dp(s.size(), 0);
//
//        //初始化
//        dp[0] = (s[0] != '0');
//        if (s.size() == 1) return dp[0];
//
//        int tmp = (s[0] - '0') * 10 + (s[1] - '0');
//        if (s[0] != '0' && s[1] != '0') ++dp[1];
//        if (tmp >= 10 && tmp <= 26) ++dp[1];
//
//        //状态转移方程：
//        //若s[i]可以单独解码, dp[i] += dp[i - 1];
//        //若s[i]和s[i - 1]结合后可以进行解码, dp[i] += dp[i - 2];
//        for (int i = 2; i < dp.size(); ++i)
//        {
//            if (s[i] != '0') dp[i] += dp[i - 1];
//            int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
//            if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
//        }
//        return dp.back();
//    }
//};
//class Solution_2 {//优化: 简化初始化以及边界问题，将初始化操作放入填表操作中
//public:
//    int numDecodings(string s)
//    {
//        //状态dp[i]: 从下标0到i - 1处的子串，解码方法的总数
//        vector<int> dp(s.size() + 1, 0);
//        //初始化
//        dp[0] = 1;//虚拟结点，需确保后面的填表是正确的
//        dp[1] = (s[0] != '0');
//
//        for (int i = 2; i < dp.size(); ++i)
//        {
//            if (s[i - 1] != '0') dp[i] += dp[i - 1];
//            int tmp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
//            if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
//        }
//        return dp.back();
//    }
//};
//int main()
//{
//    string str;
//    cin >> str;
//    Solution_1 s;
//    cout << s.numDecodings(str) << endl;
//    return 0;
//}












/*************************************************************** 不同路径（LeetCode）*******************************************************/
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
*/
//#include <iostream>
//#include <vector>
//using namespace std;
// class Solution_1 {
// public:
//     int uniquePaths(int m, int n) 
//     {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         dp[0][0] = 1;
//         for(int i = 0; i < m; ++i) {
//             for(int j = 0; j < n; ++j) {
//                 if(i - 1 >= 0) dp[i][j] += dp[i - 1][j];
//                 if(j - 1 >= 0) dp[i][j] += dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };
// class Solution_2 {
// public:
//     int uniquePaths(int m, int n)
//     {
//         //多加一行一列, 优化边界问题
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         dp[0][1] = 1;
//         for (int i = 1; i <= m; ++i)
//             for (int j = 1; j <= n; ++j)
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         return dp[m][n];
//     }
// };














/************************************************************* 不同路径II（LeetCode）**********************************************************/
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution_1 {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
//    {
//        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
//        dp[0][0] = 1;
//        for (int i = 0; i < obstacleGrid.size(); ++i)
//        {
//            for (int j = 0; j < obstacleGrid[i].size(); ++j)
//            {
//                if (i - 1 >= 0 && obstacleGrid[i - 1][j] != 1) dp[i][j] += dp[i - 1][j];
//                if (j - 1 >= 0 && obstacleGrid[i][j - 1] != 1) dp[i][j] += dp[i][j - 1];
//                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
//            }
//        }
//        return dp.back().back();
//    }
//};
//class Solution_2 {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
//    {
//        //多出一行一列用于优化边界问题
//        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
//        dp[0][1] = 1;//需确保后续填表正确
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                if (obstacleGrid[i - 1][j - 1] != 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//        return dp[row][col];
//    }
//};


















/************************************************************ 礼物的最大价值（LeetCode）****************************************************/
/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution_1 {
//public:
//    int maxValue(vector<vector<int>>& grid)
//    {
//        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
//        dp[0][0] = grid[0][0];
//        for (int i = 0; i < dp.size(); ++i)
//        {
//            for (int j = 0; j < dp[i].size(); ++j)
//            {
//                int up = 0, left = 0;
//                if (i - 1 >= 0) up = dp[i - 1][j];
//                if (j - 1 >= 0) left = dp[i][j - 1];
//                dp[i][j] = max(up, left) + grid[i][j];
//            }
//        }
//        return dp.back().back();
//    }
//};
//class Solution_2 {
//public:
//    int maxValue(vector<vector<int>>& grid)
//    {
//        //多出一行一列用于优化边界问题
//        int row = grid.size(), col = grid[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//        return dp[row][col];
//    }
//};













/************************************************************ 下降路径最小和（LeetCode）****************************************************/
/*
给你一个n x n的方形整数数matrix ，请你找出并返回通过matrix的下降路径的最小和

下降路径可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列
（即位于正下方或者沿对角线向左或者向右的第一个元素）。
具体来说，位置(row, col)的下一个元素应当是(row + 1, col - 1)、(row + 1, col)或者(row + 1, col + 1) 。
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minFallingPathSum(vector<vector<int>>& matrix)
//    {
//        //状态dp[i][j]: 以matrix[i - 1][j - 1]为结尾元素的下降路径最小和
//        int n = matrix.size();
//        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));//INT_MAX避免选择边界外的元素
//        for (int i = 0; i < n + 2; ++i) dp[0][i] = 0;//确保有效数据的第一行可以正确填充
//
//        int minRet = INT_MAX;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
//                if (i == n) minRet = min(minRet, dp[i][j]);
//            }
//        }
//        return minRet;
//    }
//};















/********************************************************** 最小路径和（LeetCode）*********************************************************/
/*
给定一个包含非负整数的m x n网格grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
说明：每次只能向下或者向右移动一步
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid)
//    {
//        //状态dp[i][j]: 到达grid[i - 1,j - 1]位置时的最小路径和
//        int row = grid.size(), col = grid[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));
//        dp[1][0] = 0;//保证不选择INT_MAX
//        for (int i = 1; i <= row; ++i) {
//            for (int j = 1; j <= col; ++j) {
//                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//            }
//        }
//        return dp[row][col];
//    }
//};















/********************************************************** 地下城游戏（LeetCode）*********************************************************/
/*
恶魔们抓住了公主并将她关在了地下城dungeon的右下角 。地下城是由 m x n 个房间组成的二维网格。
我们英勇的骑士最初被安置在 左上角 的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；
其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快解救公主，骑士决定每次只 向右 或 向下 移动一步。

返回确保骑士能够拯救到公主所需的最低初始健康点数。

注意：任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int calculateMinimumHP(vector<vector<int>>& dungeon)
//    {
//        //状态dp[i][j]: 从dungeon[i][j]到达终点,所需的最低初始健康点数
//        int row = dungeon.size(), col = dungeon[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));//INT_MAX,确保不被选择
//        dp[row][col - 1] = dp[row - 1][col] = 1;//确保能从右下角的房间走出
//        for (int i = row - 1; i >= 0; --i) {
//            for (int j = col - 1; j >= 0; --j) {
//                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
//                dp[i][j] = max(1, dp[i][j]);//初始健康点数最低为1
//            }
//        }
//        return dp[0][0];
//    }
//};








/******************************************************* 按摩师（LeetCode）**************************************************/
/*
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，
因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数
*/
#include <iostream>
#include <vector>
using namespace std;
 class Solution_1 {
 public:
     int massage(vector<int>& nums)
     {
         //状态dp[i]: 选择到nums[i - 1]时的最大预约时长
         int size = nums.size();
         vector<int> dp(size + 1);
         dp[0] = 0;
         if (size > 0) dp[1] = nums[0];
         if (size > 1) dp[2] = nums[1];
         if (size == 0) return dp[0];

         for (int i = 3; i <= size; ++i) 
             dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];

         int maxRet = 0;
         for(auto it : dp) maxRet = max(maxRet, it);
         return maxRet;
     }
 };
class Solution_2 {
public:
    int massage(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0) return 0;

        //状态f(i): 选择到i位置时, 选择nums[i],此时的最大预约时长
        vector<int> f(size);
        //状态g(i): 选择到i位置时, 不选择nums[i],此时的最大预约时长
        vector<int> g(size);

        //初始化
        f[0] = nums[0];
        g[0] = 0;

        for (int i = 1; i < size; ++i)
        {
            f[i] = g[i - 1] + nums[i];//不能选择相邻的,所以i - 1位置一定没有被选择
            g[i] = max(f[i - 1], g[i - 1]);//i - 1的位置,可能被选择也可能没有被选择
        }
        return max(f[size - 1], g[size - 1]);
    }
};