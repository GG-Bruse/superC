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
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int massage(vector<int>& nums)
//    {
//        int size = nums.size();
//        if (size == 0) return 0;
//
//        //状态f(i): 选择到i位置时, 选择nums[i],此时的最大预约时长
//        vector<int> f(size);
//        //状态g(i): 选择到i位置时, 不选择nums[i],此时的最大预约时长
//        vector<int> g(size);
//
//        //初始化
//        f[0] = nums[0];
//        g[0] = 0;
//
//        for (int i = 1; i < size; ++i)
//        {
//            f[i] = g[i - 1] + nums[i];//不能选择相邻的,所以i - 1位置一定没有被选择
//            g[i] = max(f[i - 1], g[i - 1]);//i - 1的位置,可能被选择也可能没有被选择
//        }
//        return max(f[size - 1], g[size - 1]);
//    }
//};















/**************************************************** 打家劫舍II（LeetCode）**************************************************/
/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额
*/

/*
由于房屋呈环状
1. 若选择了0号房屋偷盗，则1号房屋和n - 1号房屋都不能进行偷盗，则再将2号房屋到n - 2号房屋之间进行线性打家劫舍I
2. 若不选择0号房屋，则将1号房屋到n - 1号房屋之间进行线性打家劫舍I
选择两种情况中，能偷窃到最高金额的情况
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int robI(vector<int>& nums, int left, int right)
//    {
//        int size = right - left + 1;
//        if (size <= 0) return 0;
//        //状态f(i) : 到达第i号房屋时,偷盗了第i号房间,此时偷窃的最高金额
//        vector<int> f(size);
//        //状态g(i) : 到达第i号房屋时,没偷盗第i号房间,此时偷窃的最高金额
//        vector<int> g(size);
//
//        f[0] = nums[left];
//        g[0] = 0;
//
//        for (int i = 1; i < size; ++i) {
//            f[i] = g[i - 1] + nums[i + left];
//            g[i] = max(f[i - 1], g[i - 1]);
//        }
//        return max(f[size - 1], g[size - 1]);
//    }
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        return max(robI(nums, 2, n - 2) + nums[0], robI(nums, 1, n - 1));
//    }
//};















/*************************************************** 删除并获得点数（LeetCode） **********************************************/
/*
给你一个整数数组nums ，你可以对它进行一些操作。
每次操作中，选择任意一个nums[i] ，删除它并获得nums[i]的点数。之后，你必须删除所有等于nums[i] - 1 和 nums[i] + 1的元素。
开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数
*/

/*
题目解析:

选择nums[i]后，所有等于nums[i]的元素都会被选择，所有等于nums[i] - 1和nums[i] + 1的元素都不会被选择
所以可以将值相等的元素统计在一起，使用下标表示元素

必须删除所有等于nums[i] - 1 和nums[i] + 1的元素
表示预处理后不可选择相邻的元素

如：
nums 1  1   2   2   4   4   5   8   8   8

v[i]    0   2   4   0   8   5   0   7   24
i       0   1   2   3   4   5   6   7   8
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int robI(vector<int>& nums, int left, int right)
//    {
//        int size = right - left + 1;
//        if (size <= 0) return 0;
//        vector<int> f(size);
//        vector<int> g(size);
//
//        f[0] = nums[left];
//        g[0] = 0;
//
//        for (int i = 1; i < size; ++i) {
//            f[i] = g[i - 1] + nums[i + left];
//            g[i] = max(f[i - 1], g[i - 1]);
//        }
//        return max(f[size - 1], g[size - 1]);
//    }
//    int deleteAndEarn(vector<int>& nums)
//    {
//        int size = nums.size();
//        //找到数组中的最大值
//        int maxValue = nums[0];
//        for (auto it : nums) maxValue = max(maxValue, it);
//
//        //v[i] 表示i这个数 出现的次数 * i
//        vector<int> v(maxValue + 1, 0);
//        for (int i = 0; i < nums.size(); ++i) {
//            v[nums[i]] += nums[i];
//        }
//
//        //变形为打家劫舍问题了
//        return robI(v, 0, v.size() - 1);
//    }
//};










/******************************************************* 粉刷房子（LeetCode）*****************************************************/
/*
假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，
你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。
每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。
请计算出粉刷完所有房子最少的花费成本
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution_1 {
//public:
//    int minCost(vector<vector<int>>& costs)
//    {
//        int size = costs.size();//房子的数量
//        //状态red[i], 位置为i时, 房子刷成红色, 此时的最小花费
//        vector<int> red(size);
//        //状态blue[i], 位置为i时, 房子刷成蓝色, 此时的最小花费
//        vector<int> blue(size);
//        //状态green[i], 位置为i时, 房子刷成绿色, 此时的最小花费
//        vector<int> green(size);
//
//        red[0] = costs[0][0];
//        blue[0] = costs[0][1];
//        green[0] = costs[0][2];
//
//        for (int i = 1; i < size; ++i)
//        {
//            red[i] = min(blue[i - 1], green[i - 1]) + costs[i][0];
//            blue[i] = min(red[i - 1], green[i - 1]) + costs[i][1];
//            green[i] = min(red[i - 1], blue[i - 1]) + costs[i][2];
//        }
//        return min(min(red[size - 1], blue[size - 1]), green[size - 1]);
//    }
//};
//class Solution_2 {
//public:
//    int minCost(vector<vector<int>>& costs)
//    {
//        int size = costs.size();//房子的数量
//        //状态dp[i][j], 位置为i - 1时, 房子刷成对应色(0红1蓝2绿), 此时的最小花费
//        vector<vector<int>> dp(size + 1, vector<int>(3));//前面多开辟一个空间,将初始化操作移到填表操作中
//
//        for (int i = 1; i <= size; ++i) {
//            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
//            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
//            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
//        }
//        return min(min(dp[size][0], dp[size][1]), dp[size][2]);
//    }
//};











/********************************************** 买卖股票的最佳时机含冷冻期（LeetCode）********************************************/
/*
给定一个整数数组prices，其中第prices[i]表示第i天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        int size = prices.size();
//        //状态dp[i] : 在第i天结束时, 处于买入、可交易、冷冻期(0\1\2)状态, 得到的最高利润
//        vector<vector<int>> dp(size, vector<int>(3));
//        dp[0][0] = -prices[0];
//        //状态转移方程
//        /*
//        当天买入  ,前一天可能处于   买入状态(继续持有)   或 可交易状态(减去当天股价,即可进入买入状态)
//        当天可交易,前一天可能处于   可交易状态(无操作)   或 冷冻期(解冻)
//        当天冷冻期,前一天可只能处于 买入\持有状态(当天将股票卖出, 进入冷冻期)
//        */
//        for (int i = 1; i < size; ++i)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
//            dp[i][2] = dp[i - 1][0] + prices[i];
//        }
//        return max(dp[size - 1][1], dp[size - 1][2]);
//    }
//};
















/************************************************ 买卖股票的最佳时机含手续费（LeetCode）*************************************/
/*
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用
你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了
返回获得利润的最大值
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee)
//    {
//        int size = prices.size();
//        //状态dp[i][j] : 在第i天结束时,处于持有、可交易(0/1)状态,获得的最大利润
//        vector<vector<int>> dp(size, vector<int>(2));
//        //卖出时支付手续费
//        dp[0][0] = -prices[0];
//        dp[0][1] = 0;
//        //状态转移方程
//        for (int i = 1; i < size; ++i) {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
//        }
//        return dp[size - 1][1];
//    }
//};













/*************************************************** 买卖股票的最佳时机 III（LeetCode）****************************************/
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        /* 状态 : 在第i天结束时,有可能处于以下五种状态之一,此时能获取的最大利润
//        未有任何操作
//        进行第一次买入(持有)
//        进行第一次卖出(可交易)
//        进行第二次买入(持有)
//        进行第二次卖出(不可交易)
//        */
//        int size = prices.size();
//        vector<vector<int>> dp(size, vector<int>(5));
//        dp[0][1] = dp[0][3] = -prices[0];//允许在同一天买入并且卖出
//
//        for (int i = 1; i < size; ++i) {
//            dp[i][0] = dp[i - 1][0];//始终为0
//            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
//            dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
//            dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
//            dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
//        }
//        return dp[size - 1][4];
//    }
//};












/*************************************************** 买卖股票的最佳时机 IV（LeetCode）****************************************/
/*
给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxProfit(int k, vector<int>& prices)
//    {
//        int size = prices.size();
//        k = min(k, size / 2);
//        int nums = 1 + 2 * k;//共有几种状态
//        vector<vector<int>> dp(size, vector<int>(nums));
//        for (int j = 1; j < nums; j += 2) dp[0][j] = -prices[0];
//
//        for (int i = 1; i < size; ++i) {
//            dp[i][0] = dp[i - 1][0];
//            for (int j = 1; j < nums; ++j) {
//                if (j % 2 != 0) dp[i][j] = max(dp[i - 1][j - 1] - prices[i], dp[i - 1][j]);
//                else dp[i][j] = max(dp[i - 1][j - 1] + prices[i], dp[i - 1][j]);
//            }
//        }
//        return dp[size - 1][nums - 1];
//    }
//};


















/***************************************************** 最大子数组和（LeetCode）***********************************************/
/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态dp[i] : 以nums[i - 1]为结尾的连续子数组的最大和
//        vector<int> dp(size + 1);
//
//        int maxRet = INT_MIN;
//        for (int i = 1; i <= size; ++i) {
//            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
//            maxRet = max(maxRet, dp[i]);
//        }
//        return maxRet;
//    }
//};

















/******************************************************* 环形子数组的最大和（LeetCode）*************************************************/
/*
给定一个长度为n的环形整数数组nums ，返回 nums 的非空子数组的最大可能和 。

环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ，
nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

子数组最多只能包含固定缓冲区nums中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，
不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n
*/
/*
题目解析:
所求环形整数数组 的 非空子数组，有两种情况:
1. 所求子数组没涉及到环，直接当作普通数组求解
2. 所求子数组涉及到了环，求最小和，sum - 最小和 = 最大和，因为此时最小和肯定没涉及环
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxSubarraySumCircular(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态f(i) : 以nums[i - 1]为结尾的非空连续子数组的最大和
//        vector<int> f(size + 1);
//        //状态g(i) : 以nums[i - 1]为结尾的非空连续子数组的最小和
//        vector<int> g(size + 1);
//
//        int maxRet = INT_MIN, minRet = INT_MAX;
//        int sum = 0;
//        for (int i = 1; i <= size; ++i)
//        {
//            f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1]);
//            g[i] = min(g[i - 1] + nums[i - 1], nums[i - 1]);
//            maxRet = max(maxRet, f[i]);
//            minRet = min(minRet, g[i]);
//            sum += nums[i - 1];
//        }
//        return sum == minRet ? maxRet : max(maxRet, sum - minRet);
//    }
//};
















/******************************************************** 乘积最大子数组（LeetCode）*******************************************************/
/*
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积
测试用例的答案是一个 32-位 整数
子数组 是数组的连续子序列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxProduct(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态f(i) : 以nums[i]为结尾的乘积最大子数组的乘积
//        //状态g(i) : 以nums[i]为结尾的乘积最小子数组的乘积
//        vector<int> f(size), g(size);
//        f[0] = g[0] = nums[0];
//
//        int maxRet = f[0];
//        for (int i = 1; i < size; ++i) {
//            f[i] = max(f[i - 1] * nums[i], g[i - 1] * nums[i]);
//            f[i] = max(f[i], nums[i]);
//            g[i] = min(f[i - 1] * nums[i], g[i - 1] * nums[i]);
//            g[i] = min(g[i], nums[i]);
//            maxRet = max(maxRet, f[i]);
//        }
//        return maxRet;
//    }
//};

















/******************************************************** 乘积为正数的最长子数组长度（LeetCode）************************************************/
/*
给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度
一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组
请你返回乘积为正数的最长子数组长度
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int getMaxLen(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态f(i) : 以nums[i - 1]为结尾的,乘积为正数的最长子数组长度
//        vector<int> f(size + 1);
//        //状态g(i) : 以nums[i - 1]为结尾的,乘积为负数的最长子数组长度
//        vector<int> g(size + 1);
//
//        int maxLength = INT_MIN;
//        for (int i = 1; i <= size; ++i)
//        {
//            if (nums[i - 1] > 0) {
//                f[i] = f[i - 1] + 1;
//                g[i] = (g[i - 1] > 0 ? g[i - 1] + 1 : 0);
//            }
//            else if (nums[i - 1] < 0) {
//                f[i] = (g[i - 1] > 0 ? g[i - 1] + 1 : 0);
//                g[i] = f[i - 1] + 1;
//            }
//            else f[i] = g[i] = 0;//nums[i - 1] == 0;
//            maxLength = max(maxLength, f[i]);
//        }
//        return maxLength;
//    }
//};













/*************************************************************** 等差数列划分（LeetCode）********************************************************/
/*
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列

例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的子数组个数

子数组 是数组中的一个连续序列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态dp[i] : 以nums[i]为结尾的所有数组中为等差数组的个数
//        vector<int> dp(size);
//        int totalRet = 0;
//        for (int i = 2; i < size; ++i) {
//            dp[i] = (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1] ? dp[i - 1] + 1 : 0);
//            totalRet += dp[i];
//        }
//        return totalRet;
//    }
//};














/***************************************************** 最长湍流子数组（LeetCode）*********************************************/
/*
给定一个整数数组 arr ，返回 arr 的 最大湍流子数组的长度
如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组

输入：arr = [9,4,2,10,7,8,8,1,9]
输出：5
解释：arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
*/
//#include <iostream>
//#include <vector>
//using namespace std;
// class Solution_1 {
// public:
//     int maxTurbulenceSize(vector<int>& arr) 
//     {
//         int size = arr.size();
//         if(size == 1) return 1;
//         //状态dp[i] : 以arr[i]为结尾的所有子数组中最大湍流子数组的长度
//         vector<int> dp(size);
//         dp[0] = 1;
//         dp[1] = (arr[1] != arr[0]) + dp[0];
//
//         int maxLength = dp[0];
//         for(int i = 2; i < size; ++i)
//         {
//             if((arr[i] > arr[i - 1] && arr[i - 1] < arr[i - 2]) || (arr[i] < arr[i - 1] && arr[i - 1] > arr[i - 2]))
//                 dp[i] = dp[i - 1] + 1;
//             else if(arr[i] == arr[i - 1]) dp[i] = 1;
//             else dp[i] = 2;
//             maxLength = max(maxLength, dp[i]);
//         }
//         return max(maxLength, dp[1]);
//     }
// };
//class Solution_2 {
//public:
//    int maxTurbulenceSize(vector<int>& arr)
//    {
//        int size = arr.size();
//        //状态f[i] : 以arr[i]为结尾的所有子数组中,最后呈现"上升"状态的最大湍流子数组的长度
//        //状态g[i] : 以arr[i]为结尾的所有子数组中,最后呈现"下降"状态的最大湍流子数组的长度
//        vector<int> f(size, 1), g(size, 1);
//
//        int maxLength = 1;
//        for (int i = 1; i < size; ++i) {
//            if (arr[i] > arr[i - 1]) f[i] = g[i - 1] + 1;
//            else if (arr[i] < arr[i - 1]) g[i] = f[i - 1] + 1;
//            maxLength = max(maxLength, max(f[i], g[i]));
//        }
//        return maxLength;
//    }
//};












/******************************************************* 单词拆分（LeetCode） ****************************************************/
/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出s 
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用
*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict)
//    {
//        unordered_set<string> set;
//        for (auto& it : wordDict) set.insert(it);
//
//        int size = s.size();
//        //状态dp[i] : s[0...i]区间的字符串,能否被字典中的单词拼成
//        vector<bool> dp(size + 1);
//        dp[0] = true;
//        s = ' ' + s;//下标统一
//
//        for (int i = 1; i <= size; ++i) {
//            for (int j = i; j >= 1; --j) {//最后一个单词的起始位置
//                if (dp[j - 1] && set.count(s.substr(j, i - j + 1))) {
//                    dp[i] = true;
//                    break;
//                }
//            }
//        }
//        return dp[size];
//    }
//};
















/************************************************** 环绕字符串中唯一的子字符串（LeetCode）*****************************************/
/*
定义字符串base为一个"abcdefghijklmnopqrstuvwxyz"无限环绕的字符串，所以base看起来是这样的：
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
给你一个字符串 s ，请你统计并返回s中有多少不同非空子串也在base中出现
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    int findSubstringInWraproundString(string s)
//    {
//        int size = s.size();
//        //状态dp[i] : 以i位置为结尾的所有非空子字串,在base中出现的次数
//        vector<int> dp(size, 1);
//
//        for (int i = 1; i < size; ++i) {
//            if (s[i] - s[i - 1] == 1 || (s[i] == 'a' && s[i - 1] == 'z'))
//                dp[i] = dp[i - 1] + 1;
//        }
//        //去重 : 相同字符结尾,保存最大的那个dp值即可
//        vector<int> Ret(26);
//        int sumRet = 0;
//        for (int i = 0; i < size; ++i)
//            Ret[s[i] - 'a'] = max(Ret[s[i] - 'a'], dp[i]);
//
//        for (auto& it : Ret) sumRet += it;
//        return sumRet;
//    }
//};















/******************************************************** 最长递增子序列（LeetCode）***********************************************/
/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    int lengthOfLIS(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态dp[i] : 以i为结尾的所有子序列中的,最长递增子序列的长度
//        vector<int> dp(size, 1);
//        int maxLength = 1;
//        for (int i = 1; i < size; ++i)
//        {
//            for (int j = i - 1; j >= 0; --j) {
//                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
//            }s
//            maxLength = max(maxLength, dp[i]);
//        }
//        return maxLength;
//    }
//};














/********************************************************** 摆动序列（LeetCode）**************************************************/
/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。
仅有一个元素或者含两个不等元素的序列也视作摆动序列
例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。

相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序
给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态f[i] : 以i位置为结尾的所有子序列中,最后一个位置呈现"上升"状态,最长的摆动序列长度
//        //状态g[i] : 以i位置为结尾的所有子序列中,最后一个位置呈现"下降"状态,最长的摆动序列长度
//        vector<int> f(size, 1), g(size, 1);
//
//        int maxLength = 1;
//        for (int i = 1; i < size; ++i)
//        {
//            for (int j = 0; j < i; ++j) {
//                if (nums[i] - nums[j] > 0) f[i] = max(f[i], g[j] + 1);
//                if (nums[i] - nums[j] < 0) g[i] = max(g[i], f[j] + 1);
//            }
//            maxLength = max(maxLength, max(f[i], g[i]));
//        }
//        return maxLength;
//    }
//};












/***************************************************** 最长递增子序列的个数（LeetCode）*********************************************/
/*
给定一个未排序的整数数组nums，返回最长递增子序列的个数
注意这个数列必须是严格递增的
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findNumberOfLIS(vector<int>& nums)
//    {
//        int size = nums.size();
//        //状态length[i] : 以i位置为结尾的所有子序列, 最长递增子序列的长度
//        //状态count[i] : 以i位置为结尾的所有子序列, 最长递增子序列的个数
//        vector<int> length(size, 1), count(size, 1);
//
//        int retLen = 1, retCount = 1;
//        for (int i = 1; i < size; ++i)
//        {
//            for (int j = 0; j < i; ++j)
//            {
//                if (nums[i] > nums[j])
//                {
//                    if (length[j] + 1 == length[i]) count[i] += count[j];
//                    else if (length[j] + 1 > length[i])
//                        length[i] = length[j] + 1, count[i] = count[j];
//                }
//            }
//            if (retLen == length[i]) retCount += count[i];//最长递增子序列的长度未改变
//            else if (retLen < length[i])//最长递增子序列的长度改变,重新计数
//                retLen = length[i], retCount = count[i];
//        }
//        return retCount;
//    }
//};
















/******************************************************** 最长数对链（LeetCode）****************************************************/
/*
给你一个由n个数对组成的数对数组pairs ，其中pairs[i] = [lefti, righti] 且lefti < righti
现在，我们定义一种跟随关系，当且仅当b < c时，数对p2 = [c, d]才可以跟在p1 = [a, b]后面。我们用这种形式来构造数对链
找出并返回能够形成的 最长数对链的长度
你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int findLongestChain(vector<vector<int>>& pairs)
//    {
//        int size = pairs.size();
//        sort(pairs.begin(), pairs.end());
//        //状态dp[i] : 以i为结尾的所有子序列中,最长数对链的长度
//        vector<int> dp(size, 1);
//        int maxLength = 1;
//        for (int i = 1; i < size; ++i)
//        {
//            for (int j = 0; j < i; ++j) {
//                if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j] + 1);
//            }
//            maxLength = max(maxLength, dp[i]);
//        }
//        return maxLength;
//    }
//};













/***************************************************** 最长定差子序列（LeetCode）***************************************************/
/*
给你一个整数数组arr和一个整数difference，请你找出并返回arr中最长等差子序列的长度，该子序列中相邻元素之间的差等于difference
子序列是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从arr派生出来的序列
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int longestSubsequence(vector<int>& arr, int difference)
//    {
//        int size = arr.size();
//        //状态dp[i] : 以arr[i]为结尾的所有子序列中,最长等差子序列的长度
//        unordered_map<int, int> dp;
//        int maxLength = 1;
//        for (int i = 0; i < size; ++i) {
//            dp[arr[i]] = dp[arr[i] - difference] + 1;//只需考虑最后一个dp[j]
//            maxLength = max(maxLength, dp[arr[i]]);
//        }
//        return maxLength;
//    }
//};















/************************************************* 最长的斐波那契子序列的长度（LeetCode）*******************************************/
/*
如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是斐波那契式的：n >= 3
对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
给定一个严格递增的正整数数组形成序列arr，找到arr中最长的斐波那契式的子序列的长度。如果一个不存在，返回0

（回想一下，子序列是从原序列 arr 中派生出来的，它从 arr 中删掉任意数量的元素（也可以不删），而不改变其余元素的顺序。
例如， [3, 5, 8] 是 [3, 4, 5, 6, 7, 8] 的一个子序列）
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int lenLongestFibSubseq(vector<int>& arr)
//    {
//        int size = arr.size();
//        unordered_map<int, int> hash;
//        for (int i = 0; i < size; ++i) hash[arr[i]] = i;
//
//        //状态dp[i][j] : 以i位置以及j位置的元素为结尾的所有子序列(i < j)中, 最长的斐波那契子序列的长度
//        vector<vector<int>> dp(size, vector<int>(size, 2));
//
//        int maxLength = 2;
//        for (int j = 2; j < size; ++j)
//        {
//            for (int i = 1; i < j; ++i)
//            {
//                int tmp = arr[j] - arr[i];
//                if (tmp < arr[i] && hash.count(tmp)) dp[i][j] = dp[hash[tmp]][i] + 1;
//                maxLength = max(maxLength, dp[i][j]);
//            }
//        }
//        return maxLength < 3 ? 0 : maxLength;
//    }
//};








/***************************************************** 最长等差数列（LeetCode）**************************************************/
/*
给你一个整数数组 nums，返回 nums 中最长等差子序列的长度
回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ... < ik <= nums.length - 1
并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1) 的值都相同，那么序列 seq 是等差的
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int longestArithSeqLength(vector<int>& nums)
//    {
//        int size = nums.size();
//        unordered_map<int, int> hash;
//        hash[nums[0]] = 0;
//
//        //状态dp[i][j] : 以i位置、j位置元素为结尾的所有子序列中(i < j), 最长等差数列的长度
//        vector<vector<int>> dp(size, vector<int>(size, 2));
//
//        int maxLength = 2;
//        for (int i = 1; i < size; ++i)//先固定倒数第二个数
//        {
//            for (int j = i + 1; j < size; ++j)
//            {
//                int tmp = 2 * nums[i] - nums[j];
//                if (hash.count(tmp)) dp[i][j] = dp[hash[tmp]][i] + 1;
//                maxLength = max(maxLength, dp[i][j]);
//            }
//            hash[nums[i]] = i;//一边dp,一般保存下标(因为可能存在多个相同的数,只需要最后一个即可)
//        }
//        return maxLength;
//    }
//};

















/***************************************************** 等差数列划分 II - 子序列（LeetCode） ***************************************/
/*
给你一个整数数组nums，返回nums中所有等差子序列的数目
如果一个序列中 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该序列为等差序列。

例如，[1, 3, 5, 7, 9]、[7, 7, 7, 7] 和 [3, -1, -5, -9] 都是等差序列
再例如，[1, 1, 2, 5, 7] 不是等差序列
数组中的子序列是从数组中删除一些元素（也可能不删除）得到的一个序列

例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列
题目数据保证答案是一个 32-bit 整数
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& nums)
//    {
//        int size = nums.size();
//        unordered_map<long long, vector<int>> hash;
//        for (int i = 0; i < size; ++i) hash[nums[i]].push_back(i);
//
//        //状态dp[i][j] : 以i位置、j位置元素为结尾的所有子序列(i < j)中,等差子序列的个数
//        vector<vector<int>> dp(size, vector<int>(size));
//
//        int sumNums = 0;
//        for (int j = 2; j < size; ++j)
//        {
//            for (int i = 1; i < j; ++i)
//            {
//                long long tmp = (long long)2 * nums[i] - nums[j];
//                if (hash.count(tmp))
//                {
//                    for (auto it : hash[tmp])
//                        if (it < i) dp[i][j] += (dp[it][i] + 1);
//                }
//                sumNums += dp[i][j];
//            }
//        }
//        return sumNums;
//    }
//};














/********************************************************** 回文子串（LeetCode）***************************************************/
/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目
回文字符串 是正着读和倒过来读一样的字符串
子字符串 是字符串中的由连续字符组成的一个序列
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int countSubstrings(string s)
//    {
//        int size = s.size();
//        //状态dp[i][j] : 以i位置为开始、j位置为结尾的子串，是否为回文子串
//        vector<vector<bool>> dp(size, vector<bool>(size));//默认false
//
//        int ret = 0;
//        for (int i = size - 1; i >= 0; --i)
//        {
//            for (int j = i; j < size; ++j)
//            {
//                if (s[i] == s[j]) dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
//                if (dp[i][j]) ++ret;
//            }
//        }
//        return ret;
//    }
//};













/********************************************************** 最长回文子串（LeetCode）************************************************/
/*
给你一个字符串 s，找到 s 中最长的回文子串
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    string longestPalindrome(string s)
//    {
//        int size = s.size();
//        //状态dp[i][j] : 字符串s[i,j]是否为回文串
//        vector<vector<bool>> dp(size, vector<bool>(size));
//
//        vector<int> flag(2);
//        for (int i = size - 1; i >= 0; --i)
//        {
//            for (int j = i; j < size; ++j)
//            {
//                if (s[i] == s[j]) dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
//                if (dp[i][j] && j - i > flag[1] - flag[0]) flag[0] = i, flag[1] = j;
//            }
//        }
//        return s.substr(flag[0], flag[1] - flag[0] + 1);
//    }
//};













/******************************************************* 分割回文串IV（LeetCode）***************************************************/
/*
给你一个字符串s ，如果可以将它分割成三个非空回文子字符串，那么返回true ，否则返回false
当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    bool checkPartitioning(string s)
//    {
//        int size = s.size();
//        //状态dp[i][j] : s[i,j]是否为回文串
//        vector<vector<bool>> dp(size, vector<bool>(size));
//
//        for (int i = size - 1; i >= 0; --i) {
//            for (int j = i; j < size; ++j) {
//                if (s[i] == s[j]) dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
//            }
//        }
//
//        //[0,i] [i,j] [j,size - 1]
//        for (int i = 1; i < size - 1; ++i) { //第一刀
//            for (int j = i + 1; j < size; ++j) {//第二刀
//                if (dp[0][i - 1] && dp[i][j - 1] && dp[j][size - 1]) return true;
//            }
//        }
//        return false;
//    }
//};











/******************************************************* 分割回文串II（LeetCode）***************************************************/
/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文
返回符合要求的 最少分割次数
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minCut(string s)
//    {
//        int size = s.size();
//        vector<vector<bool>> map(size, vector<bool>(size));//存储每个子串是否为回文串
//        for (int i = size - 1; i >= 0; --i) {
//            for (int j = i; j < size; ++j) {
//                if (s[i] == s[j]) map[i][j] = i + 1 < j ? map[i + 1][j - 1] : true;
//            }
//        }
//
//        //状态dp[i] : s[0,i]字符串的最少分割次数
//        vector<int> dp(size, INT_MAX);
//        for (int i = 0; i < size; ++i)
//        {
//            if (map[0][i]) dp[i] = 0;
//            else
//            {
//                for (int j = 1; j <= i; ++j)
//                    if (map[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
//            }
//        }
//        return dp[size - 1];
//    }
//};



















/******************************************************* 最长回文子序列（LeetCode）*************************************************/
/*
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int longestPalindromeSubseq(string s)
//    {
//        int size = s.size();
//        //状态dp[i][j] : 在[i,j]区间内的所有子序列中,最长的回文子序列的长度
//        vector<vector<int>> dp(size, vector<int>(size, 0));
//
//        for (int i = size - 1; i >= 0; --i) {
//            dp[i][i] = 1;
//            for (int j = i + 1; j < size; ++j) {
//                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
//                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//            }
//        }
//        return dp[0][size - 1];
//    }
//};













/********************************************** 让字符串成为回文串的最少插入次数（LeetCode）****************************************/
/*
给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符
请你返回让 s 成为回文串的 最少操作次数
「回文串」是正读和反读都相同的字符串
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minInsertions(string s)
//    {
//        int size = s.size();
//        //状态dp[i][j] : [i,j]区间的子串,使其成为回文串的最小插入次数
//        vector<vector<int>> dp(size, vector<int>(size));
//
//        for (int i = size - 1; i >= 0; --i) {
//            for (int j = i; j < size; ++j) {
//                if (s[i] == s[j]) dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : 0;
//                else dp[i][j] = min(dp[i][j - 1] + 1, dp[i + 1][j] + 1);
//            }
//        }
//        return dp[0][size - 1];
//    }
//};
















/*************************************************** 最长公共子序列（LeetCode）*****************************************************/
/*
给定两个字符串text1和text2，返回这两个字符串的最长公共子序列的长度。如果不存在公共子序列，返回0
一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符
（也可以不删除任何字符）后组成的新字符串

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2)
//    {
//        int size1 = text1.size(), size2 = text2.size();
//        //dp[i][j] : text1[0,i]区间和text2[0,j]区间的所有子序列中,最长公共子序列
//        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
//
//        for (int i = 1; i <= size1; ++i) {
//            for (int j = 1; j <= size2; ++j) {
//                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//        return dp[size1][size2];
//    }
//};














/******************************************************* 不相交的线（LeetCode）****************************************************/
/*
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：
 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线

以这种方法绘制线条，并返回可以绘制的最大连线数
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
//    {
//        int size1 = nums1.size(), size2 = nums2.size();
//        //状态dp[i][j] : nums1[0,i]区间与nums2[0,j]区间之间不相交的线的最大数量
//        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
//
//        for (int i = 1; i <= size1; ++i) {
//            for (int j = 1; j <= size2; ++j) {
//                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//        return dp[size1][size2];
//    }
//};













/******************************************************* 不同的子序列（LeetCode）****************************************************/
/*
给你两个字符串s和t ，统计并返回在s的子序列中t出现的个数
题目数据保证答案符合 32 位带符号整数范围
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int numDistinct(string s, string t)
//    {
//        int size1 = s.size(), size2 = t.size();
//        if (size1 < size2) return 0;
//
//        s = " " + s, t = " " + t;
//        //状态dp[i][j] : 在s[0,i]的所有子序列中 t[0,j]子串 出现的次数
//        vector<vector<double>> dp(size1 + 1, vector<double>(size2 + 1));
//        for (int i = 0; i <= size1; ++i) dp[i][0] = 1;
//
//        for (int i = 1; i <= size1; ++i) {
//            for (int j = 1; j <= size2; ++j) {
//                //根据s的子序列的最后一个位置是否为s[i],分为两类
//                dp[i][j] += dp[i - 1][j];//否
//                if (s[i] == t[j]) dp[i][j] += dp[i - 1][j - 1]; //是
//            }
//        }
//        return dp[size1][size2];
//    }
//};













/******************************************************** 通配符匹配（LeetCode）*************************************************/
/*
给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符序列（包括空字符序列）
判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool isMatch(string s, string p)
//    {
//        int size1 = s.size(), size2 = p.size();
//        s = " " + s, p = " " + p;
//        //状态dp[i][j] : s[0,i]和p[0,j]之间是否匹配
//        vector<vector<bool>> dp(size1 + 1, vector<bool>(size2 + 1));
//        dp[0][0] = true;
//        for (int j = 1; j <= size2; ++j) {
//            if (p[j] == '*') dp[0][j] = true;
//            else break;
//        }
//
//        for (int i = 1; i <= size1; ++i) {
//            for (int j = 1; j <= size2; ++j) {
//                if (s[i] == p[j] || p[j] == '?') dp[i][j] = dp[i - 1][j - 1];
//                if (p[j] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//            }
//        }
//        return dp[size1][size2];
//    }
//};











/********************************************************* 交错字符串（LeetCode）***************************************************/
/*
给定三个字符串s1、s2、s3，请你帮忙验证s3是否是由s1和s2交错组成的
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3)
//    {
//        int size1 = s1.size(), size2 = s2.size();
//        if (size1 + size2 != s3.size()) return false;
//        s1 = " " + s1, s2 = " " + s2, s3 = " " + s3;
//        //状态dp[i][j] : s1[0,i]和s2[0,j]是否可以交错组成s3[0,i + j]
//        vector<vector<bool>> dp(size1 + 1, vector<bool>(size2 + 1));
//        dp[0][0] = true;
//        for (int j = 1; j <= size2; ++j) { //初始化第一行dp[0][j]
//            if (s2[j] == s3[j]) dp[0][j] = true;
//            else break;
//        }
//        for (int i = 1; i <= size1; ++i) { //初始化第一列dp[i][0]
//            if (s1[i] == s3[i]) dp[i][0] = true;
//            else break;
//        }
//
//        for (int i = 1; i <= size1; ++i) {
//            for (int j = 1; j <= size2; ++j) {
//                if (s1[i] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i - 1][j];
//                if (s2[j] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i][j - 1];
//            }
//        }
//        return dp[size1][size2];
//    }
//};















/************************************************** 两个字符串的最小ASCII删除和（LeetCode）*****************************************/
/*
给定两个字符串s1和s2，返回使两个字符串相等所需删除字符的ASCII值的最小和
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    int minimumDeleteSum(string s1, string s2)
//    {
//        int size1 = s1.size(), size2 = s2.size();
//        s1 = " " + s1, s2 = " " + s2;
//        //dp[i][j] : 要使s1[0,i]和s2[0,j]相等所需删除的字符的ASCII值的最小和
//        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
//        dp[0][0] = 0;
//        for (int j = 1; j <= size2; ++j) dp[0][j] = dp[0][j - 1] + s2[j];//一行
//        for (int i = 1; i <= size1; ++i) dp[i][0] = dp[i - 1][0] + s1[i];//一列
//
//        for (int i = 1; i <= size1; ++i)
//        {
//            for (int j = 1; j <= size2; ++j)
//            {
//                if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
//                if (s1[i] != s2[j]) dp[i][j] = min(dp[i - 1][j] + s1[i], dp[i][j - 1] + s2[j]);
//            }
//        }
//        return dp[size1][size2];
//    }
//};











/****************************************************** 最长重复子数组（LeetCode）**************************************************/
/*
给两个整数数组nums1和nums2，返回两个数组中公共的 、长度最长的子数组的长度
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2)
//    {
//        int size1 = nums1.size(), size2 = nums2.size();
//        //状态dp[i][j] : nums1中以i结尾的 和 nums2中以j结尾的,所有子数组中,最长的公共子数组的长度
//        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
//
//        int maxRet = 0;
//        for (int i = 1; i <= size1; ++i) {
//            for (int j = 1; j <= size2; ++j) {
//                if (nums1[i - 1] == nums2[j - 1])
//                    dp[i][j] = dp[i - 1][j - 1] + 1, maxRet = max(maxRet, dp[i][j]);
//            }
//        }
//        return maxRet;
//    }
//};














/************************************************************** 01背包（LeetCode）***********************************************/
/*
你有一个背包，最多能容纳的体积是V
现在有n个物品，第i个物品的体积为vi,价值为wi​

（1）求这个背包至多能装多大价值的物品？
（2）若背包恰好装满，求至多能装多大价值的物品？

第一行两个整数n和V，表示物品个数和背包体积
接下来n行，每行两个数vi和wi，表示第i个物品的体积和价值
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1010;
//vector<vector<int>> dp(N, vector<int>(N));
//
//int GetMaxValue(vector<vector<int>>& article, int v, int n) {
//    //dp[i][j] : 从前i个物品中挑选,总体积不超过j,所有的选法中,能挑选出来的最⼤价值
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= v; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= article[i][0])
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - article[i][0]] + article[i][1]);
//        }
//    }
//    return dp[n][v];
//}
//int GetMaxValueII(vector<vector<int>>& article, int v, int n) {
//    //从前i个物品中挑选,总体积正好等于j,所有的选法中,能挑选出来的最⼤价值
//    dp = vector<vector<int>>(N, vector<int>(N));
//    for (int j = 1; j <= v; j++) dp[0][j] = -1;
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= v; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= article[i][0] && dp[i - 1][j - article[i][0]] != -1)
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - article[i][0]] + article[i][1]);
//        }
//    }
//    return dp[n][v] == -1 ? 0 : dp[n][v];
//}
//int main() {
//    int n = 0, v = 0;
//    while (cin >> n >> v) {
//        vector<vector<int>> article(n + 1, vector<int>(2));
//        for (int i = 1; i <= n; ++i) cin >> article[i][0] >> article[i][1];
//
//        cout << GetMaxValue(article, v, n) << endl;
//        cout << GetMaxValueII(article, v, n) << endl;
//    }
//    return 0;
//}

////滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1010;
//vector<int> dp(N);
//
//int GetMaxValue(vector<vector<int>>& article, int v, int n) {
//    for (int i = 1; i <= n; ++i)
//        for (int j = v; j >= article[i][0]; --j)
//            dp[j] = max(dp[j], dp[j - article[i][0]] + article[i][1]);
//    return dp[v];
//}
//int GetMaxValueII(vector<vector<int>>& article, int v, int n) {
//    dp = vector<int>(N, -1);
//    dp[0] = 0;
//
//    for (int i = 1; i <= n; ++i)
//        for (int j = v; j >= article[i][0]; --j)
//            if (dp[j - article[i][0]] != -1)
//                dp[j] = max(dp[j], dp[j - article[i][0]] + article[i][1]);
//    return dp[v] == -1 ? 0 : dp[v];
//}
//int main() {
//    int n = 0, v = 0;
//    while (cin >> n >> v) {
//        vector<vector<int>> article(n + 1, vector<int>(2));
//        for (int i = 1; i <= n; ++i) cin >> article[i][0] >> article[i][1];
//
//        cout << GetMaxValue(article, v, n) << endl;
//        cout << GetMaxValueII(article, v, n) << endl;
//    }
//    return 0;
//}













/*********************************************************** 分割等和子集（LeetCode）************************************************/
/*
给你一个只包含正整数的非空数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool canPartition(vector<int>& nums)
//    {
//        int size = nums.size(), sum = 0;
//        for (auto& it : nums) sum += it;
//        if (sum % 2 != 0) return false;
//
//        //状态dp[i][j] : 在前i个数中选择,能否凑成总和为j
//        int aim = sum / 2;
//        vector<vector<bool>> dp(size + 1, vector<bool>(aim + 1));
//        for (int i = 0; i <= size; ++i) dp[i][0] = true;
//
//        for (int i = 1; i <= size; ++i) {
//            for (int j = 1; j <= aim; ++j) {
//                dp[i][j] = dp[i - 1][j];
//                if (nums[i - 1] <= j) dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
//            }
//        }
//        return dp[size][aim];
//    }
//};

////滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    bool canPartition(vector<int>& nums)
//    {
//        int size = nums.size(), sum = 0;
//        for (auto& it : nums) sum += it;
//        if (sum % 2 != 0) return false;
//
//        int aim = sum / 2;
//        vector<bool> dp(aim + 1);
//        dp[0] = true;
//
//        for (int i = 1; i <= size; ++i)
//            for (int j = aim; j >= nums[i - 1]; --j)
//                dp[j] = dp[j] || dp[j - nums[i - 1]];
//        return dp[aim];
//    }
//};














/******************************************************** 目标和（LeetCode）********************************************************/
/*
给你一个非负整数数组nums和一个整数target
向数组中的每个整数前添加'+'或'-'，然后串联起所有整数，可以构造一个表达式：

例如，nums = [2, 1] ，可以在2之前添加'+'，在1之前添加'-'，然后串联起来得到表达式"+2-1"
返回可以通过上述方法构造的、运算结果等于target的不同表达式的数目
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    题目变形：
//    数组中所有数之和为sum
//    前面加"+"的数之和为a,前面加"-"的数之和为b
//    a + b = sum, a - b = target
//    推导：a = (sum + target) / 2
//    */
//    int findTargetSumWays(vector<int>& nums, int target)
//    {
//        int sum = 0;
//        for (auto& it : nums) sum += it;
//        int size = nums.size();
//        int aim = (sum + target) / 2;
//        if (aim < 0 || (sum + target) % 2 != 0) return 0;
//
//        //状态dp[i][j] : 在前i个数中选择,总和正好等于j,共有几种选法
//        vector<vector<int>> dp(size + 1, vector<int>(aim + 1));
//        dp[0][0] = 1;
//
//        for (int i = 1; i <= size; ++i) {
//            for (int j = 0; j <= aim; ++j) {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= nums[i - 1]) dp[i][j] += dp[i - 1][j - nums[i - 1]];
//            }
//        }
//        return dp[size][aim];
//    }
//};

//滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target)
//    {
//        int sum = 0;
//        for (auto& it : nums) sum += it;
//        int size = nums.size();
//        int aim = (sum + target) / 2;
//        if (aim < 0 || (sum + target) % 2 != 0) return 0;
//
//        vector<int> dp(aim + 1);
//        dp[0] = 1;
//
//        for (int i = 1; i <= size; ++i) {
//            for (int j = aim; j >= nums[i - 1]; --j) {
//                dp[j] += dp[j - nums[i - 1]];
//            }
//        }
//        return dp[aim];
//    }
//};










/*********************************************** 最后一块石头的重量II（LeetCode）***************************************************/
/*
有一堆石头，用整数数组stones表示。其中stones[i]表示第i块石头的重量
每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为x和y，且x <= y。那么粉碎的可能结果如下：
如果x == y，那么两块石头都会被完全粉碎
如果x != y，那么重量为x的石头将会完全粉碎，而重量为y的石头新重量为 y-x
最后，最多只会剩下一块石头。返回此石头最小的可能重量 。如果没有石头剩下，就返回 0
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    石头的总重量为sum
//    题意即,尽可能的将石头分为重量都接近sum / 2的两堆
//    */
//    int lastStoneWeightII(vector<int>& stones)
//    {
//        int sum = 0;
//        for (auto& it : stones) sum += it;
//        int size = stones.size();
//        int aim = sum / 2;
//        //dp[i][j] : 在前i个石头中选择,总重量不能超过j,此时的总重量
//        vector<vector<int>> dp(size + 1, vector<int>(aim + 1));
//        for (int i = 0; i <= size; ++i) dp[i][0] = 0;
//
//        for (int i = 1; i <= size; ++i) {
//            for (int j = 1; j <= aim; ++j) {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= stones[i - 1])
//                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
//            }
//        }
//        return sum - 2 * dp[size][aim];
//    }
//};

////滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int lastStoneWeightII(vector<int>& stones)
//    {
//        int sum = 0;
//        for (auto& it : stones) sum += it;
//        int size = stones.size();
//        int aim = sum / 2;
//
//        vector<int> dp(aim + 1);
//        for (int i = 1; i <= size; ++i)
//            for (int j = aim; j >= stones[i - 1]; --j)
//                dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
//
//        return sum - 2 * dp[aim];
//    }
//};














/******************************************************** 完全背包（牛客）**********************************************************/
/*
你有一个背包，最多能容纳的体积是V
现在有n种物品，每种物品有任意多个，第i种物品的体积为vi,价值为wi
（1）求这个背包至多能装多大价值的物品？
（2）若背包恰好装满，求至多能装多大价值的物品？

输入描述：
第一行两个整数n和V，表示物品个数和背包体积
接下来n行，每行两个数vi和wi​，表示第i种物品的体积和价值
1≤n,V≤1000
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<vector<int>> dp;
//
//int GetRetI(int n, int V, vector<int>& v, vector<int>& w)
//{
//    //状态dp[i][j] : 从前i个物品中选择,总体积不超过j,此时的最大价值
//    dp = vector<vector<int>>(n + 1, vector<int>(V + 1));
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= V; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//        }
//    }
//    return dp[n][V];
//}
//int GetRetII(int n, int V, vector<int>& v, vector<int>& w)
//{
//    //状态dp[i][j] : 从前i个物品中选择,总体积刚好等于j,此时的最大价值
//    dp = vector<vector<int>>(n + 1, vector<int>(V + 1));
//    for (int j = 1; j <= V; ++j) dp[0][j] = -1;//设置不合法状态
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= V; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i] && dp[i][j - v[i]] != -1)
//                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//        }
//    }
//    return dp[n][V] == -1 ? 0 : dp[n][V];
//}
//int main()
//{
//    int n = 0, V = 0;
//    while (cin >> n >> V)
//    {
//        vector<int> v(n + 1), w(n + 1);
//        for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
//        cout << GetRetI(n, V, v, w) << endl;
//        cout << GetRetII(n, V, v, w) << endl;
//    }
//    return 0;
//}

//滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> dp;
//
//int GetRetI(int n, int V, vector<int>& v, vector<int>& w)
//{
//    dp = vector<int>(V + 1);
//    for (int i = 1; i <= n; ++i)
//        for (int j = v[i]; j <= V; ++j)
//            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//    return dp[V];
//}
//int GetRetII(int n, int V, vector<int>& v, vector<int>& w)
//{
//    dp = vector<int>(V + 1);
//    for (int j = 1; j <= V; ++j) dp[j] = -1;//设置不合法状态
//
//    for (int i = 1; i <= n; ++i)
//        for (int j = v[i]; j <= V; ++j)
//            if (dp[j - v[i]] != -1) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
//    return dp[V] == -1 ? 0 : dp[V];
//}
//int main()
//{
//    int n = 0, V = 0;
//    while (cin >> n >> V)
//    {
//        vector<int> v(n + 1), w(n + 1);
//        for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
//        cout << GetRetI(n, V, v, w) << endl;
//        cout << GetRetII(n, V, v, w) << endl;
//    }
//    return 0;
//}









/********************************************************* 零钱兑换（LeetCode）****************************************************/
/*
给你一个整数数组coins，表示不同面额的硬币；以及一个整数amount，表示总金额
计算并返回可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1
你可以认为每种硬币的数量是无限的
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    问题转化：(硬币无限,完全背包问题)
//    在coins中选择硬币,使得总金额恰好为amount,此时的最小硬币数
//                (物品)     (体积)                   (价值)
//    */
//    int coinChange(vector<int>& coins, int amount)
//    {
//        int size = coins.size();
//        //状态dp[i][j] : 在前i个物品中选择,总金额刚好为j,此时的最小硬币数
//        vector<vector<int>> dp(size + 1, vector<int>(amount + 1));
//        for (int j = 1; j <= amount; ++j) dp[0][j] = 0x3f3f3f3f;//设置非法状态
//
//        for (int i = 1; i <= size; ++i) {
//            for (int j = 1; j <= amount; ++j) {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= coins[i - 1]) dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
//            }
//        }
//        return dp[size][amount] >= 0x3f3f3f3f ? -1 : dp[size][amount];
//    }
//};

//滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount)
//    {
//        int size = coins.size();
//        vector<int> dp(amount + 1);
//        for (int j = 1; j <= amount; ++j) dp[j] = 0x3f3f3f3f;//设置非法状态
//
//        for (int i = 1; i <= size; ++i)
//            for (int j = coins[i - 1]; j <= amount; ++j)
//                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
//        return dp[amount] >= 0x3f3f3f3f ? -1 : dp[amount];
//    }
//};










/****************************************************** 零钱兑换 II（LeetCode）*****************************************************/
/*
给你一个整数数组coins表示不同面额的硬币，另给一个整数amount表示总金额
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回0
假设每一种面额的硬币有无限个
题目数据保证结果符合 32 位带符号整数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    在coins中选择硬币,总金额凑成恰好amount,共有几种选择
//            (物品)      (体积)
//    */
//    int change(int amount, vector<int>& coins)
//    {
//        int size = coins.size();
//        //状态dp[i][j] : 从前i个硬币选择,总金额刚好为j,共有几种选法
//        vector<vector<int>> dp(size + 1, vector<int>(amount + 1));
//        for (int i = 0; i <= size; ++i) dp[i][0] = 1;
//
//        for (int i = 1; i <= size; ++i) {
//            for (int j = 1; j <= amount; ++j) {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
//            }
//        }
//        return dp[size][amount];
//    }
//};

//滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int change(int amount, vector<int>& coins)
//    {
//        int size = coins.size();
//        vector<int> dp(amount + 1);
//        dp[0] = 1;
//        for (int i = 1; i <= size; ++i)
//            for (int j = coins[i - 1]; j <= amount; ++j)
//                if (j >= coins[i - 1]) dp[j] += dp[j - coins[i - 1]];
//        return dp[amount];
//    }
//};









//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//class Solution {
//public:
//    int numSquares(int n)
//    {
//        int size = sqrt(n);
//        //dp[i][j] : 从n的所有完全平方数中的前i个选择,其和刚好为j,此时完全平方数的最少数量 
//        vector<vector<int>> dp(size + 1, vector<int>(n + 1));
//        for (int j = 1; j <= n; ++j) dp[0][j] = 0x3f3f3f3f;
//
//        for (int i = 1; i <= size; ++i) {//枚举每个数,i * i即枚举所有完全平方数
//            for (int j = 1; j <= n; ++j) {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= i * i) dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
//            }
//        }
//        return dp[size][n];
//    }
//};

//滚动数组优化
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//class Solution {
//public:
//    int numSquares(int n)
//    {
//        int size = sqrt(n);
//        vector<int> dp(n + 1, 0x3f3f3f3f);
//        dp[0] = 0;
//
//        for (int i = 1; i <= size; ++i)
//            for (int j = i * i; j <= n; ++j)
//                dp[j] = min(dp[j], dp[j - i * i] + 1);
//
//        return dp[n];
//    }
//};















/********************************************************* 一和零（LeetCode）*******************************************************/
/*
给你一个二进制字符串数组strs和两个整数m和n
请你找出并返回strs的最大子集的长度，该子集中最多有m个0和n个1
如果x的所有元素也是y的元素，集合x是集合y的子集
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n)
//    {
//        int size = strs.size();
//        //状态dp[i][j][K] : 在strs中前i个元素中选择,0的个数不超过i,1的个数不超过j
//        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
//
//        for (int i = 1; i <= size; ++i)
//        {
//            int a = 0, b = 0;
//            for (auto& it : strs[i - 1]) {
//                if (it == '0') a++;
//                else b++;
//            }
//            for (int j = 0; j <= m; ++j) {
//                for (int k = 0; k <= n; ++k) {
//                    dp[i][j][k] = dp[i - 1][j][k];
//                    if (j >= a && k >= b) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - a][k - b] + 1);
//                }
//            }
//        }
//        return dp[size][m][n];
//    }
//};

//滚动数组优化
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n)
//    {
//        int size = strs.size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//
//        for (int i = 1; i <= size; ++i)
//        {
//            int a = 0, b = 0;
//            for (auto& it : strs[i - 1]) {
//                if (it == '0') a++;
//                else b++;
//            }
//            for (int j = m; j >= a; --j)
//                for (int k = n; k >= b; --k)
//                    dp[j][k] = max(dp[j][k], dp[j - a][k - b] + 1);
//        }
//        return dp[m][n];
//    }
//};













/******************************************************** 盈利计划（LeetCode）******************************************************/
/*
集团里有 n 名员工，他们可以完成各种各样的工作创造利润
第i种工作会产生profit[i]的利润，它要求group[i]名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作
工作的任何至少产生minProfit利润的子集称为盈利计划。并且工作的成员总数最多为n
有多少种计划可以选择？因为答案很大，所以返回结果模10^9 + 7的值
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    const int MOD = 1e9 + 7;
//    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
//    {
//        int size = group.size();
//        //dp[i][j][k] : 在前i个工作中选择,总参加人数j不能大于n,总利润k不能小于minProfit,共有多少种计划
//        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
//        for (int j = 0; j <= n; ++j) dp[0][j][0] = 1;//空集方案
//
//        for (int i = 1; i <= size; ++i)
//        {
//            for (int j = 0; j <= n; ++j)
//            {
//                for (int k = 0; k <= minProfit; ++k)
//                {
//                    dp[i][j][k] = dp[i - 1][j][k];
//                    if (j >= group[i - 1])
//                        dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])];
//                    dp[i][j][k] %= MOD;
//                }
//            }
//        }
//        return dp[size][n][minProfit];
//    }
//};

//滚动数组优化
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    const int MOD = 1e9 + 7;
//    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
//    {
//        int size = group.size();
//        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
//        for (int j = 0; j <= n; ++j) dp[j][0] = 1;
//
//        for (int i = 1; i <= size; ++i)
//            for (int j = n; j >= 0; --j)
//                for (int k = minProfit; k >= 0; --k) {
//                    if (j >= group[i - 1]) dp[j][k] += dp[j - group[i - 1]][max(0, k - profit[i - 1])];
//                    dp[j][k] %= MOD;
//                }
//        return dp[n][minProfit];
//    }
//};













/************************************ 不同的二叉搜索树（LeetCode）****************************************/
/*
给你一个整数n，求恰由n个节点组成且节点值从1到n互不相同的二叉搜索树有多少种？返回满足题意的二叉搜索树的种数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int numTrees(int n)
//    {
//        //状态dp[i] : 当结点的数量为i时,BST的个数
//        vector<int> dp(n + 1);
//        dp[0] = 1;//空数也是二叉搜索树
//        for (int i = 1; i <= n; ++i)//枚举结点的个数
//            for (int j = 1; j <= i; ++j)//选择一个结点为根节点
//                dp[i] += dp[j - 1] * dp[i - j];
//        return dp[n];
//    }
//};











/***************************************** 堆箱子（LeetCode）*********************************************/
/*
堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，
下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子
箱堆的高度为每个箱子高度的总和
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int pileBox(vector<vector<int>>& box)
//    {
//        int size = box.size();
//        //预处理
//        sort(box.begin(), box.end());
//        //dp[i] : 以第i个箱子为结尾的, 严格递增的箱子序列的最高高度总和
//        vector<int> dp(size, 0);
//        //初始化
//        for (int i = 0; i < size; ++i) dp[i] = box[i][2];
//        int ret = dp[0];
//        //状态转移
//        for (int i = 1; i < size; ++i)
//        {
//            for (int j = 0; j < i; ++j)
//            {
//                if (box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2])
//                    dp[i] = max(dp[i], dp[j] + box[i][2]);
//            }
//            ret = max(ret, dp[i]);
//        }
//        return ret;
//    }
//};










/************************************************* 最大正方形（LeetCode）*********************************************/
/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix)
//    {
//        int row = matrix.size(), col = matrix[0].size();
//        if (row == 0 || col == 0) return 0;
//        //dp[i] : 以matrix[i]为右下角元素并且为1的最大正方形的变长
//        vector<vector<int>> dp(row, vector<int>(col, 0));
//        int maxLength = 0;
//        for (int j = 0; j < col; ++j) if (matrix[0][j] == '1') dp[0][j] = 1, maxLength = 1;
//        for (int i = 0; i < row; ++i) if (matrix[i][0] == '1') dp[i][0] = 1, maxLength = 1;
//        for (int i = 1; i < row; ++i) {
//            for (int j = 1; j < col; ++j) {
//                if (matrix[i][j] == '1') {
//                    dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
//                    maxLength = max(maxLength, dp[i][j]);
//                }
//            }
//        }
//        return maxLength * (long long)maxLength;
//    }
//};











/********************************************* 三角形最小路径和（LeetCode）********************************************/
/*
给定一个三角形 triangle ，找出自顶向下的最小路径和
每一步只能移动到下一行中相邻的结点上。相邻的结点在这里指的是下标与上一层结点下标相同或者等于上一层结点下标+1的两个结点
也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
// class Solution1 {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) 
//     {
//         int row = triangle.size(), col = triangle.back().size();
//         //dp[i][j] : 到达triangle[i][j]时的最小路径和
//         vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
//         dp[0][0] = triangle[0][0];
//         for(int i = 1; i < row; ++i)
//         {
//             for(int j = 0; j < triangle[i].size(); ++j)
//             {
//                 if(j - 1 >= 0)
//                     dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
//                 else 
//                     dp[i][j] = dp[i - 1][j] + triangle[i][j];
//             }
//         }
//         int minSum = INT_MAX;
//         for(int j = 0; j < col; ++j)
//             minSum = min(minSum, dp[row - 1][j]);
//         return minSum;
//     }
// };
//class Solution2 {
//public:
//    int minimumTotal(vector<vector<int>>& triangle)
//    {
//        int row = triangle.size();
//        for (int i = row - 2; i >= 0; --i)
//            for (int j = 0; j < triangle[i].size(); ++j)
//                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
//        return triangle[0][0];
//    }
//};











/************************************************* 编辑距离（LeetCode）***********************************************/
/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    int minDistance(string word1, string word2)
//    {
//        int row = word1.size(), col = word2.size();
//        //dp[i][j] : 由word1前i个字母和word2前j字母之间的编辑距离
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
//        //初始化
//        for (int i = 0; i < row + 1; ++i) dp[i][0] = i;
//        for (int j = 0; j < col + 1; ++j) dp[0][j] = j;
//        //dp
//        for (int i = 1; i < row + 1; ++i)
//        {
//            for (int j = 1; j < col + 1; ++j)
//            {
//                int dis1 = dp[i][j - 1] + 1;//i先变成j - 1, 末尾再增加一个字符可变化为j
//                int dis2 = dp[i - 1][j] + 1;//i - 1先变成j, 此时j再变成i会多出一个字符，删去即可
//                int dis3 = dp[i - 1][j - 1];//i - 1变成j - 1, 若最后一个字符不同, 最后一个字符进行修改即可
//                if (word1[i - 1] != word2[j - 1]) dis3 += 1;
//                dp[i][j] = min(dis1, min(dis2, dis3));
//            }
//        }
//        return dp[row][col];
//    }
//};











/************************************ 统计构造好字符串的方案数（LeetCode）************************************/
/*
给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：
将 '0' 在字符串末尾添加 zero  次
将 '1' 在字符串末尾添加 one 次
以上操作可以执行任意次
如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为好字符串
请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 109 + 7 取余 后返回
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    const int MOD = 1e9 + 7;
//    int countGoodStrings(int low, int high, int zero, int one)
//    {
//        //dp[i] : 构造长为i的字符串的方案数
//        vector<int> dp(high + 1);
//        dp[0] = 1;
//        //dp
//        int ret = 0;
//        for (int i = 1; i <= high; ++i)
//        {
//            if (i >= one) dp[i] = dp[i - one] % MOD;
//            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % MOD;
//            if (i >= low) ret = (ret + dp[i]) % MOD;
//        }
//        return ret;
//    }
//};








/******************************************** 最低票价（LeetCode）*********************************************/
/*
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行
在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数
火车票有 三种不同的销售方式 ：
一张 为期一天 的通行证售价为 costs[0] 美元；
一张 为期七天 的通行证售价为 costs[1] 美元；
一张 为期三十天 的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证
那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天
返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费
*/
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//class Solution
//{
//public:
//    int mincostTickets(vector<int>& days, vector<int>& costs)
//    {
//        vector<int> diffDate{ 1, 7, 30 };
//        unordered_set<int> set;
//        for (int& it : days) set.insert(it);
//        //dp[i] : 第i天总共的最低花费
//        int date = days.back();
//        vector<int> dp(date + 1, INT_MAX);
//        dp[0] = 0;
//        for (int i = 1; i <= date; ++i)
//        {
//            if (!set.count(i)) dp[i] = dp[i - 1];
//            else
//            {
//                for (int k = 0; k <= 2; ++k)
//                {
//                    if (i - diffDate[k] >= 0)
//                        dp[i] = min(dp[i], dp[i - diffDate[k]] + costs[k]);
//                    else
//                        dp[i] = min(dp[i], dp[0] + costs[k]);
//                }
//            }
//        }
//        return dp[date];
//    }
//};










/***************************************** 解决智力问题（LeetCode）*******************************************/
/*
给你一个下标从 0 开始的二维整数数组 questions ，其中 questions[i] = [pointsi, brainpoweri] 
这个数组表示一场考试里的一系列题目，你需要 按顺序 （也就是从问题 0 开始依次解决），针对每个问题选择 解决 或者 跳过 操作。解决问题 i 将让你 获得  pointsi 的分数，但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri 个问题）
如果你跳过问题 i ，你可以对下一个问题决定使用哪种操作
比方说，给你 questions = [[3, 2], [4, 3], [4, 4], [2, 5]] ：
如果问题 0 被解决了， 那么你可以获得 3 分，但你不能解决问题 1 和 2
如果你跳过问题 0 ，且解决问题 1 ，你将获得 4 分但是不能解决问题 2 和 3
请你返回这场考试里你能获得的 最高 分数
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution1 {
//public:
//    long long mostPoints(vector<vector<int>>& questions)
//    {
//        int size = questions.size();
//        //dp[i] : 第 i 道题目及以后的题目可以获得的最高分数
//        vector<long long> dp(size);
//        dp[size - 1] = questions[size - 1][0];
//        for (int i = size - 2; i >= 0; --i)
//        {
//            dp[i] = dp[i + 1];
//            if (i + questions[i][1] + 1 < size)
//                dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1], dp[i]);
//            else
//                dp[i] = max(dp[i], (long long)questions[i][0]);
//        }
//        return dp[0];
//    }
//};
////仅仅是简化代码，算法并无优化
//class Solution2 {
//public:
//    long long mostPoints(vector<vector<int>>& questions)
//    {
//        int size = questions.size();
//        //dp[i] : 第 i 道题目及以后的题目可以获得的最高分数
//        vector<long long> dp(size + 1);//dp[size]存储0
//        for (int i = size - 1; i >= 0; --i)
//            dp[i] = max(dp[i + 1], questions[i][0] + dp[min(size, i + questions[i][1] + 1)]);
//        return dp[0];
//    }
//};











/**************************************** 多米诺和托米诺平铺（LeetCode）**************************************/
/*
有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转
给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 109 + 7 取模 的值
平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，
使得恰好有一个平铺有一个瓷砖占据两个正方形
*/
//#include <iostream>
//#include <vector>
//using namespace std;
////找规律
//class Solution1 {
//public:
//    int numTilings(int n)
//    {
//        const int MOD = 1e9 + 7;
//        //dp[i] : 当n == i时, 共有多少中平铺的方法
//        if (n <= 2) return n;
//        vector<long long> dp(n + 1);
//        dp[0] = dp[1] = 1, dp[2] = 2;
//        for (int i = 3; i <= n; ++i)
//            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;
//        return dp[n];
//    }
//};
////动态规划
//class Solution {
//public:
//    int numTilings(int n)
//    {
//        const int MOD = 1e9 + 7;
//        //dp[i][s] 表示平铺到第 i 列时，各个状态 s 对应的平铺方法数量
//        /*
//        一个正方形都没有被覆盖，记为状态 0
//        只有上方的正方形被覆盖，记为状态 1
//        只有下方的正方形被覆盖，记为状态 2
//        上下两个正方形都被覆盖，记为状态 3
//        */
//        vector<vector<long long>> dp(n + 1, vector<long long>(4));
//        dp[1][0] = dp[1][3] = 1;
//        for (int i = 2; i <= n; ++i)
//        {
//            dp[i][0] = dp[i - 1][3];
//            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
//            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
//            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
//        }
//        return dp[n][3];
//    }
//};










/***************************************** 最长有效括号（LeetCode）*****************************************/
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int longestValidParentheses(string s)
//    {
//        int size = s.size();
//        //dp[i] : 以s[i]为结尾的字符串, 最长有效括号子串的长度
//        vector<int> dp(size, 0);
//        int maxLength = 0;
//        for (int i = 1; i < size; ++i)
//        {
//            if (s[i] == ')')
//            {
//                if (s[i - 1] == '(')
//                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
//                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
//            }
//            maxLength = max(maxLength, dp[i]);
//        }
//        return maxLength;
//    }
//};










/******************************************** 接雨水（LeetCode）***********************************************/
/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int trap(vector<int>& height)
//    {
//        int size = height.size();
//
//        vector<int> left(size); //left[i] : i位置以及左边的位置中,height的最大值
//        left[0] = height[0];
//        for (int i = 1; i < size; ++i) left[i] = max(left[i - 1], height[i]);
//
//        vector<int> right(size);//right[i] : i位置以及右边的位置中,height的最大值
//        right[size - 1] = height[size - 1];
//        for (int i = size - 2; i >= 0; --i) right[i] = max(right[i + 1], height[i]);
//
//        int ret = 0;
//        for (int i = 0; i < size; ++i)
//            ret += min(left[i], right[i]) - height[i];
//        return ret;
//    }
//};









/******************************************* 最长有效括号（LeetCode）******************************************/
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    int longestValidParentheses(string s)
//    {
//        int size = s.size();
//        int ret = 0;
//        //dp[i] : 以下标i字符结尾的最长有效括号的长度
//        vector<int> dp(size);
//        for (int i = 1; i < size; ++i)
//        {
//            if (s[i] == ')')
//            {
//                if (s[i - 1] == '(')
//                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
//                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
//                ret = max(ret, dp[i]);
//            }
//        }
//        return ret;
//    }
//};









/************************************* 最大平均值和的分组（LeetCode）******************************************/
/*
给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k 个非空子数组，且数组内部是连续的
分数 由每个子数组内的平均值的总和构成
注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数
返回我们所能得到的最大 分数 是多少。答案误差在 10-6 内被视为是正确的
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    //平均值和最大的分组的子数组数目必定为k
//    double largestSumOfAverages(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//
//        vector<double> prefix(size + 1);
//        for (int i = 0; i < size; ++i)
//            prefix[i + 1] = prefix[i] + nums[i];
//
//        //dp[i][j] : nums[0, i - 1]被切分为j个子数组的最大平均值和
//        vector<vector<double>> dp(size + 1, vector<double>(k + 1));
//        //初始化:  j=1时,dp[i][j]是对应区间[0,i−1]的平均值
//        for (int i = 1; i <= size; ++i)
//            dp[i][1] = prefix[i] / i;
//        //dp
//        for (int j = 2; j <= k; ++j)
//            for (int i = j; i <= size; ++i)
//                for (int x = j - 1; x < i; ++x)//遍历各种切割方法
//                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
//        return dp[size][k];
//    }
//};









/******************************************* 戳气球（LeetCode）*********************************************/
/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中
现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币
这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号
如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球
求所能获得硬币的最大数量
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxCoins(vector<int>& nums)
//    {
//        int size = nums.size();
//        vector<int> newNums(size + 2, 1);
//        for (int i = 1; i <= size; ++i) newNums[i] = nums[i - 1];
//
//        //dp[i][j] 表示填满开区间(i,j)能得到的最多硬币数
//        vector<vector<int>> dp(size + 2, vector<int>(size + 2));
//        for (int i = size - 1; i >= 0; --i)//left
//        {
//            for (int j = i + 2; j <= size + 1; ++j)//right
//            {
//                for (int k = i + 1; k < j; ++k)
//                {
//                    int tmp = newNums[i] * newNums[k] * newNums[j];
//                    tmp += dp[i][k] + dp[k][j];
//                    dp[i][j] = max(dp[i][j], tmp);
//                }
//            }
//        }
//        return dp[0][size + 1];
//    }
//};










/******************************************** 01矩阵（LeetCode）***********************************************/
/*
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵
其中每一个格子是 mat 中对应位置元素到最近的 0 的距离
两个相邻元素间的距离为 1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
//    {
//        int row = mat.size(), col = mat[0].size();
//        //dp[i][j] : mat[i][j]到最近的0的距离,初始化为一个较大值
//        vector<vector<int>> dp(row, vector<int>(col, INT_MAX / 2));
//        //解决0位置
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j)
//                if (mat[i][j] == 0) dp[i][j] = 0;
//        //只能向左移动和向上移动
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                if (i - 1 >= 0)
//                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
//                if (j - 1 >= 0)
//                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
//            }
//        }
//        //只能向左移动和向下移动
//        for (int i = row - 1; i >= 0; --i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                if (i + 1 < row)
//                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
//                if (j - 1 >= 0)
//                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
//            }
//        }
//        //只能向右移动和向上移动
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = col - 1; j >= 0; --j)
//            {
//                if (i - 1 >= 0)
//                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
//                if (j + 1 < col)
//                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
//            }
//        }
//        //只能向右和向下移动
//        for (int i = row - 1; i >= 0; --i)
//        {
//            for (int j = col - 1; j >= 0; --j)
//            {
//                if (i + 1 < row)
//                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
//                if (j + 1 < col)
//                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
//            }
//        }
//        return dp;
//    }
//};
//优化版
//class Solution {
//public:
//    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
//    {
//        int row = mat.size(), col = mat[0].size();
//        //dp[i][j] : mat[i][j]到最近的0的距离,初始化为一个较大值
//        vector<vector<int>> dp(row, vector<int>(col, INT_MAX / 2));
//        //解决0位置
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j)
//                if (mat[i][j] == 0) dp[i][j] = 0;
//        //只能向左移动和向上移动
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                if (i - 1 >= 0)
//                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
//                if (j - 1 >= 0)
//                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
//            }
//        }
//        //只能向右和向下移动
//        for (int i = row - 1; i >= 0; --i)
//        {
//            for (int j = col - 1; j >= 0; --j)
//            {
//                if (i + 1 < row)
//                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
//                if (j + 1 < col)
//                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
//            }
//        }
//        return dp;
//    }
//};





//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int N = 0;
//    cin >> N;
//
//    vector<vector<int>> weight(N + 1, vector<int>(N + 1));
//    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0x7ffffff));
//
//    for (int i = 1; i <= N; ++i)
//        for (int j = 1; j <= N; ++j)
//            cin >> weight[i][j];
//
//    for (int i = 1; i <= N; ++i) {
//        for (int j = 1; j <= N; ++j) {
//            if (i == 1 && j == 1) dp[i][j] = weight[i][j];
//            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + weight[i][j];
//        }
//    }
//
//    cout << dp[N][N] << endl;
//
//    return 0;
//}







//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int T = 0;
//    cin >> T;
//    while (T--)
//    {
//        int row = 0, col = 0;
//        cin >> row >> col;
//
//        vector<vector<int>> peanutField(row + 1, vector<int>(col + 1));
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
//
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                cin >> peanutField[i][j];
//
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + peanutField[i][j];
//
//        cout << dp[row][col] << endl;
//    }
//    return 0;
//}







#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int M = 0, N = 0;
    cin >> M >> N;

    // vector<vector<int>> weight(M + 1, vector<int>(N + 1));
    // vector<vector<vector<int>>> dp(N + M + 2, vector<vector<int>>(M + 1, vector<int>(N + 1)));
    int weight[M + 1][N + 1] = { 0 };
    int dp[N + M + 2][M + 1][N + 1] = { 0 };

    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> weight[i][j];

    for (int k = 2; k <= M + N; ++k)
    {
        for (int i1 = max(1, k - N); i1 <= min(k - 1, M); ++i1)
        {
            for (int i2 = max(1, k - N); i2 <= min(k - 1, M); ++i2)
            {
                int value = weight[i1][k - i1];
                if (i1 != i2) value += weight[i2][k - i2];

                int& tmp = dp[k][i1][i2];
                tmp = max(tmp, dp[k - 1][i1 - 1][i2 - 1] + value);
                tmp = max(tmp, dp[k - 1][i1][i2 - 1] + value);
                tmp = max(tmp, dp[k - 1][i1 - 1][i2] + value);
                tmp = max(tmp, dp[k - 1][i1][i2] + value);
            }
        }
    }
    cout << dp[M + N][M][M] << endl;
    return 0;
}