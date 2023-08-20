/*********************************************************** ���뷽����LeetCode��**********************************************************/
/*
һ��������ĸ A-Z ����Ϣͨ������ӳ������� ���� ��
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
Ҫ�����ѱ������Ϣ���������ֱ����������ӳ��ķ���������ӳ�����ĸ�������ж��ַ����������磬"11106" ����ӳ��Ϊ��
"AAJF" ������Ϣ����Ϊ (1 1 10 6)
"KJF" ������Ϣ����Ϊ (11 10 6)
ע�⣬��Ϣ���ܷ���Ϊ  (1 11 06) ����Ϊ "06" ����ӳ��Ϊ "F" ���������� "6" �� "06" ��ӳ���в����ȼۡ�

����һ��ֻ�����ֵķǿ��ַ���s ������㲢���ؽ��뷽�������� 
��Ŀ���ݱ�֤�𰸿϶���һ�� 32 λ ������
*/

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution_1 {
//public:
//    int numDecodings(string s)
//    {
//        //״̬dp[i]: ���±�0��i�����Ӵ������뷽��������
//        vector<int> dp(s.size(), 0);
//
//        //��ʼ��
//        dp[0] = (s[0] != '0');
//        if (s.size() == 1) return dp[0];
//
//        int tmp = (s[0] - '0') * 10 + (s[1] - '0');
//        if (s[0] != '0' && s[1] != '0') ++dp[1];
//        if (tmp >= 10 && tmp <= 26) ++dp[1];
//
//        //״̬ת�Ʒ��̣�
//        //��s[i]���Ե�������, dp[i] += dp[i - 1];
//        //��s[i]��s[i - 1]��Ϻ���Խ��н���, dp[i] += dp[i - 2];
//        for (int i = 2; i < dp.size(); ++i)
//        {
//            if (s[i] != '0') dp[i] += dp[i - 1];
//            int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
//            if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
//        }
//        return dp.back();
//    }
//};
//class Solution_2 {//�Ż�: �򻯳�ʼ���Լ��߽����⣬����ʼ������������������
//public:
//    int numDecodings(string s)
//    {
//        //״̬dp[i]: ���±�0��i - 1�����Ӵ������뷽��������
//        vector<int> dp(s.size() + 1, 0);
//        //��ʼ��
//        dp[0] = 1;//�����㣬��ȷ��������������ȷ��
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












/*************************************************************** ��ͬ·����LeetCode��*******************************************************/
/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����
���ܹ��ж�������ͬ��·����
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
//         //���һ��һ��, �Ż��߽�����
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         dp[0][1] = 1;
//         for (int i = 1; i <= m; ++i)
//             for (int j = 1; j <= n; ++j)
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         return dp[m][n];
//     }
// };














/************************************************************* ��ͬ·��II��LeetCode��**********************************************************/
/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������
���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ
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
//        //���һ��һ�������Ż��߽�����
//        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
//        dp[0][1] = 1;//��ȷ�����������ȷ
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                if (obstacleGrid[i - 1][j - 1] != 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//        return dp[row][col];
//    }
//};


















/************************************************************ ���������ֵ��LeetCode��****************************************************/
/*
��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0����
����Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�
����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����
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
//        //���һ��һ�������Ż��߽�����
//        int row = grid.size(), col = grid[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//        return dp[row][col];
//    }
//};













/************************************************************ �½�·����С�ͣ�LeetCode��****************************************************/
/*
����һ��n x n�ķ���������matrix �������ҳ�������ͨ��matrix���½�·������С��

�½�·�����Դӵ�һ���е��κ�Ԫ�ؿ�ʼ������ÿһ����ѡ��һ��Ԫ�ء�����һ��ѡ���Ԫ�غ͵�ǰ����ѡԪ��������һ��
����λ�����·������ضԽ�������������ҵĵ�һ��Ԫ�أ���
������˵��λ��(row, col)����һ��Ԫ��Ӧ����(row + 1, col - 1)��(row + 1, col)����(row + 1, col + 1) ��
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minFallingPathSum(vector<vector<int>>& matrix)
//    {
//        //״̬dp[i][j]: ��matrix[i - 1][j - 1]Ϊ��βԪ�ص��½�·����С��
//        int n = matrix.size();
//        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));//INT_MAX����ѡ��߽����Ԫ��
//        for (int i = 0; i < n + 2; ++i) dp[0][i] = 0;//ȷ����Ч���ݵĵ�һ�п�����ȷ���
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















/********************************************************** ��С·���ͣ�LeetCode��*********************************************************/
/*
����һ�������Ǹ�������m x n����grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С
˵����ÿ��ֻ�����»��������ƶ�һ��
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid)
//    {
//        //״̬dp[i][j]: ����grid[i - 1,j - 1]λ��ʱ����С·����
//        int row = grid.size(), col = grid[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));
//        dp[1][0] = 0;//��֤��ѡ��INT_MAX
//        for (int i = 1; i <= row; ++i) {
//            for (int j = 1; j <= col; ++j) {
//                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//            }
//        }
//        return dp[row][col];
//    }
//};















/********************************************************** ���³���Ϸ��LeetCode��*********************************************************/
/*
��ħ��ץס�˹��������������˵��³�dungeon�����½� �����³����� m x n ��������ɵĶ�ά����
����Ӣ�µ���ʿ����������� ���Ͻ� �ķ���������봩�����³ǲ�ͨ���Կ���ħ�����ȹ�����

��ʿ�ĳ�ʼ��������Ϊһ����������������Ľ���������ĳһʱ�̽��� 0 �����£���������������
��Щ�����ɶ�ħ�����������ʿ�ڽ�����Щ����ʱ��ʧȥ�������������������ֵΪ�����������ʾ��ʿ����ʧ������������
��������Ҫô�ǿյģ��������ֵΪ 0����Ҫô����������ʿ����������ħ�������������ֵΪ�����������ʾ��ʿ�����ӽ�����������

Ϊ�˾����ȹ�������ʿ����ÿ��ֻ ���� �� ���� �ƶ�һ����

����ȷ����ʿ�ܹ����ȵ������������ͳ�ʼ����������

ע�⣺�κη��䶼���ܶ���ʿ�Ľ������������в��Ҳ����������ʿ�Ľ���������������ʿ��������ϽǷ����Լ���������������½Ƿ��䡣
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int calculateMinimumHP(vector<vector<int>>& dungeon)
//    {
//        //״̬dp[i][j]: ��dungeon[i][j]�����յ�,�������ͳ�ʼ��������
//        int row = dungeon.size(), col = dungeon[0].size();
//        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));//INT_MAX,ȷ������ѡ��
//        dp[row][col - 1] = dp[row - 1][col] = 1;//ȷ���ܴ����½ǵķ����߳�
//        for (int i = row - 1; i >= 0; --i) {
//            for (int j = col - 1; j >= 0; --j) {
//                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
//                dp[i][j] = max(1, dp[i][j]);//��ʼ�����������Ϊ1
//            }
//        }
//        return dp[0][0];
//    }
//};








/******************************************************* ��Ħʦ��LeetCode��**************************************************/
/*
һ�������İ�Ħʦ���յ�ԴԴ���ϵ�ԤԼ����ÿ��ԤԼ������ѡ��ӻ򲻽ӡ���ÿ��ԤԼ����֮��Ҫ����Ϣʱ�䣬
��������ܽ������ڵ�ԤԼ������һ��ԤԼ�������У��水Ħʦ�ҵ����ŵ�ԤԼ���ϣ���ԤԼʱ������������ܵķ�����
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
//        //״̬f(i): ѡ��iλ��ʱ, ѡ��nums[i],��ʱ�����ԤԼʱ��
//        vector<int> f(size);
//        //״̬g(i): ѡ��iλ��ʱ, ��ѡ��nums[i],��ʱ�����ԤԼʱ��
//        vector<int> g(size);
//
//        //��ʼ��
//        f[0] = nums[0];
//        g[0] = 0;
//
//        for (int i = 1; i < size; ++i)
//        {
//            f[i] = g[i - 1] + nums[i];//����ѡ�����ڵ�,����i - 1λ��һ��û�б�ѡ��
//            g[i] = max(f[i - 1], g[i - 1]);//i - 1��λ��,���ܱ�ѡ��Ҳ����û�б�ѡ��
//        }
//        return max(f[size - 1], g[size - 1]);
//    }
//};















/**************************************************** ��ҽ���II��LeetCode��**************************************************/
/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�
����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�
ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�����ڲ���������װ�õ������ �������ܹ�͵�Ե�����߽��
*/

/*
���ڷ��ݳʻ�״
1. ��ѡ����0�ŷ���͵������1�ŷ��ݺ�n - 1�ŷ��ݶ����ܽ���͵�������ٽ�2�ŷ��ݵ�n - 2�ŷ���֮��������Դ�ҽ���I
2. ����ѡ��0�ŷ��ݣ���1�ŷ��ݵ�n - 1�ŷ���֮��������Դ�ҽ���I
ѡ����������У���͵�Ե���߽������
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
//        //״̬f(i) : �����i�ŷ���ʱ,͵���˵�i�ŷ���,��ʱ͵�Ե���߽��
//        vector<int> f(size);
//        //״̬g(i) : �����i�ŷ���ʱ,û͵����i�ŷ���,��ʱ͵�Ե���߽��
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















/*************************************************** ɾ������õ�����LeetCode�� **********************************************/
/*
����һ����������nums ������Զ�������һЩ������
ÿ�β����У�ѡ������һ��nums[i] ��ɾ���������nums[i]�ĵ�����֮�������ɾ�����е���nums[i] - 1 �� nums[i] + 1��Ԫ�ء�
��ʼ��ӵ�� 0 ����������������ͨ����Щ������õ�������
*/

/*
��Ŀ����:

ѡ��nums[i]�����е���nums[i]��Ԫ�ض��ᱻѡ�����е���nums[i] - 1��nums[i] + 1��Ԫ�ض����ᱻѡ��
���Կ��Խ�ֵ��ȵ�Ԫ��ͳ����һ��ʹ���±��ʾԪ��

����ɾ�����е���nums[i] - 1 ��nums[i] + 1��Ԫ��
��ʾԤ����󲻿�ѡ�����ڵ�Ԫ��

�磺
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
//        //�ҵ������е����ֵ
//        int maxValue = nums[0];
//        for (auto it : nums) maxValue = max(maxValue, it);
//
//        //v[i] ��ʾi����� ���ֵĴ��� * i
//        vector<int> v(maxValue + 1, 0);
//        for (int i = 0; i < nums.size(); ++i) {
//            v[nums[i]] += nums[i];
//        }
//
//        //����Ϊ��ҽ���������
//        return robI(v, 0, v.size() - 1);
//    }
//};