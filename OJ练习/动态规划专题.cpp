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


















/*************************************************************** ���������ֵ��LeetCode��***************************************************/
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