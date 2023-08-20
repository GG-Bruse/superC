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