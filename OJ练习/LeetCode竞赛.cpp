/*********************************** Ԫ�غ���С��ɽ����Ԫ��II��LeetCode��**************************************/
/*
����һ���±��0��ʼ����������nums 
����±���Ԫ�� (i, j, k) ��������ȫ������������Ϊ����һ��ɽ����Ԫ�飺i < j < k
nums[i] < nums[j] �� nums[k] < nums[j]
�����ҳ�nums��Ԫ�غ���С��ɽ����Ԫ�飬��������Ԫ�غ͡����������������������Ԫ�飬����-1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minimumSum(vector<int>& nums)
//    {
//        int size = nums.size();
//        //dp[i] : ��nums[i]��nums[n - 1]����Сֵ
//        vector<int> dp(size);
//        dp[size - 1] = nums[size - 1];
//        for (int i = size - 2; i >= 0; --i)
//            dp[i] = min(dp[i + 1], nums[i]);
//
//        int prev = nums[0];//��¼ɽ����ǰ��С��Ԫ��
//        int minTop = INT_MAX;
//        for (int i = 1; i < size - 1; ++i)//ö��ɽ��
//        {
//            if (prev < nums[i] && nums[i] > dp[i + 1])
//                minTop = min(minTop, prev + nums[i] + dp[i + 1]);
//            prev = min(prev, nums[i]);
//        }
//        return minTop == INT_MAX ? -1 : minTop;
//    }
//};










/****************************************** �Ϸ����������������LeetCode��*************************************/
/*
����һ������Ϊn�±��0��ʼ����������nums
�����뽫�±���з��飬ʹ�� [0, n - 1] �������±�i��ǡ�ñ��ֵ�����һ��
���������������������˵������鷽���ǺϷ��ģ�
����ÿ���� g ��ͬһ���������±���nums�ж�Ӧ����ֵ�����
�������������� g1 �� g2 �����������±������Ĳ�ֵ������1
���㷵��һ����������ʾ�õ�һ���Ϸ����鷽���� ���� ����
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int minGroupsForValidAssignment(vector<int>& nums)
//    {
//        unordered_map<int, int> counts;//��¼ÿ�������ֵ�Ƶ��
//        for (auto& it : nums) ++counts[it];
//        //�����С����Ԫ�صĸ���
//        int minSize = INT_MAX;
//        for (auto& [_, cnt] : counts) minSize = min(minSize, cnt);
//        //ö��ÿһ�ַ������
//        for (int k = minSize; k > 0; --k)//����ΪminSize��, ÿ����һ��Ԫ��
//        {
//            int ret = 0;
//            for (auto& [_, cnt] : counts)
//            {
//                if (cnt / k < cnt % k) {//�޷��ֳ�k��k+1��
//                    ret = 0;
//                    break;
//                }
//                ret += (cnt + k) / (k + 1);
//            }
//            if (ret) return ret;
//        }
//        return -1;
//    }
//};









/************************************* �������С��Ⱥͣ�LeetCode��***********************************************/
/*
������������������0��ɵ�����nums1��nums2 
����뽫���������е�����0�滻Ϊ�ϸ�������������������������������Ԫ�صĺ���� 
������С��Ⱥͣ�����޷�ʹ��������ȣ��򷵻�-1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    long long minSum(vector<int>& nums1, vector<int>& nums2)
//    {
//        long long ret1 = 0;
//        bool flag1 = false;
//        for (auto& it : nums1) {
//            if (it == 0) ret1 += 1, flag1 = true;
//            else ret1 += it;
//        }
//        long long ret2 = 0;
//        bool flag2 = false;
//        for (auto& it : nums2) {
//            if (it == 0) ret2 += 1, flag2 = true;
//            else  ret2 += it;
//        }
//        if (flag1 && !flag2 && ret1 > ret2) return -1;
//        else if (!flag1 && flag2 && ret1 < ret2) return -1;
//        else if (!flag1 && !flag2 && ret1 != ret2) return -1;
//        else return max(ret1, ret2);
//    }
//};









/********************************** ʹ�����������С������������LeetCode��****************************************/
/*
����һ���±�� 0 ��ʼ������Ϊn����������nums����һ������k
�����ִ������������������Σ������� 0 �Σ�
�ӷ�Χ [0, n - 1] ��ѡ��һ���±� i ������nums[i]��ֵ��1
����������κγ��ȴ��ڻ����3�������飬�����Ԫ�ض����ڻ����k������Ϊ������һ����������
��������ʽ����ʹ�����Ϊ����������Ҫִ�е���С����������
�������������е�һ������ �ǿ� Ԫ������
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    long long minIncrementOperations(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//        //dp[i] : ��nums[0] �� nums[i]��Ϊ��������, ������nums[i] >= k����С����������
//        vector<long long> dp(size);
//        for (int i = 0; i < 3; ++i)
//            dp[i] = max(k - nums[i], 0);
//        for (int i = 3; i < size; ++i)
//            dp[i] = min({ dp[i - 1], dp[i - 2], dp[i - 3] }) + max(k - nums[i], 0);
//        return min({ dp[size - 1], dp[size - 2], dp[size - 3] });
//    }
//};










/***************************************** �ҳ������е�K-orֵ��LeetCode��*****************************************/
/*
����һ���±��0��ʼ����������nums��һ������k
nums �е� K-or ��һ���������������ķǸ�������
ֻ����nums�У����ٴ���k��Ԫ�صĵ�iλֵΪ1����ôK-or�еĵ�iλ��ֵ����1
����nums��K-orֵ
ע�⣺��������x ����� (2i AND x) == 2i ����x�еĵ�iλֵΪ1 ������ANDΪ��λ�������
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int findKOr(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;//bitNum : Count
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            int tmp = nums[i];
//            for (int j = 0; j < 32; ++j) {
//                if ((tmp & (1 << j)) != 0)
//                    ++hash[j];
//            }
//        }
//        int ret = 0;
//        for (auto& it : hash) {
//            if (it.second >= k) ret += pow(2, it.first);
//        }
//        return ret;
//    }
//};









/***************************************** �ҵ��ھ�I��LeetCode��******************************************/
/*
һ�������й���n֧���飬����0�� n - 1���
����һ���±�� 0 ��ʼ����СΪ n * n �Ķ�ά��������grid
��������0 <= i, j <= n - 1��i != j������ i, j�����grid[i][j] == 1����ôi�ӱ�j��ǿ������j�ӱ�i��ǿ 
���ⳡ�����У����������ĳ֧ǿ�� a �ӵĶ��飬����Ϊ a �ӽ����ǹھ�
�����ⳡ�����н����Ϊ�ھ��Ķ���
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findChampion(vector<vector<int>>& grid)
//    {
//        int size = grid.size();
//        //����� j �е�Ԫ��ֵ���� 0, ˵��û�ж�����Ի����������� j
//        for (int i = 0; i < size; ++i)//ö�ٸ���
//        {
//            bool flag = false;//�Ƿ����1 
//            for (int j = 0; j < size; ++j)//��������Ԫ��
//                if (grid[j][i] == 1) flag = true;
//            if (flag == false) return i;
//        }
//        return -1;
//    }
//};