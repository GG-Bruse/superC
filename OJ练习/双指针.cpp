/************************************* ����֮��II - �����������飨LeetCode��***********************************/
/*
����һ���±�� 1 ��ʼ���������� numbers ���������Ѱ� �ǵݼ�˳�����У�
������������ҳ��������֮�͵���Ŀ���� target ��������
��������������ֱ��� numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length
�Գ���Ϊ 2 ���������� [index1, index2] ����ʽ�����������������±� index1 �� index2
����Լ���ÿ������ ֻ��ӦΨһ�Ĵ� �������� ������ �ظ�ʹ����ͬ��Ԫ��
������ƵĽ����������ֻʹ�ó������Ķ���ռ�
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target)
//    {
//        int size = numbers.size();
//        int left = 0, right = size - 1;
//        while (left < right)
//        {
//            int tmpSum = numbers[left] + numbers[right];
//            if (tmpSum == target) return { left + 1, right + 1 };
//            else if (tmpSum > target) --right;
//            else ++left;
//        }
//        return { -1, -1 };
//    }
//};










/*********************************************** ����ˮ��LeetCode��********************************************/
/*
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ
*/
//#include <iostream>
//#include <vector>
//using namespace std;
////˫ָ��
//class Solution {
//public:
//    int trap(vector<int>& height)
//    {
//        int left = 0, right = height.size() - 1;
//        int leftMax = 0, rightMax = 0;
//        int ret = 0;
//        while (left < right)
//        {
//            leftMax = max(leftMax, height[left]);
//            rightMax = max(rightMax, height[right]);
//            if (height[left] < height[right]) {
//                ret += (leftMax - height[left]);
//                ++left;
//            }
//            else {
//                ret += (rightMax - height[right]);
//                --right;
//            }
//        }
//        return ret;
//    }
//};










/***************************************** ��ӽ�������֮�ͣ�LeetCode��****************************************/
/*
����һ������Ϊ n ���������� nums �� һ��Ŀ��ֵ target������� nums ��ѡ������������ʹ���ǵĺ��� target ��ӽ�
�������������ĺ�
�ٶ�ÿ������ֻ����ǡ��һ����
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target)
//    {
//        sort(nums.begin(), nums.end());
//        int size = nums.size();
//
//        int ret = 0xfffff;
//        auto update = [&](int current) {
//            if (abs(current - target) < abs(ret - target))
//                ret = current;
//        };
//
//        for (int i = 0; i < size; ++i)//ö�ٵ�һ��Ԫ��
//        {
//            if (i > 0 && nums[i] == nums[i - 1]) continue;//��֤����һ��ö�ٵ�Ԫ�ز����
//            int left = i + 1, right = size - 1;
//            while (left < right)
//            {
//                int sum = nums[i] + nums[left] + nums[right];
//                if (sum == target) return target;
//                update(sum);
//
//                if (sum > target)//���ʹ���target,��ǰ�ƶ�right
//                {
//                    int tmpRight = right - 1;
//                    //�ƶ�����һ������ȵ�Ԫ��
//                    while (left < tmpRight && nums[tmpRight] == nums[right]) --tmpRight;
//                    right = tmpRight;
//                }
//                else//sum < target,����ƶ�left
//                {
//                    int tmpLeft = left + 1;
//                    while (tmpLeft < right && nums[tmpLeft] == nums[left]) ++tmpLeft;
//                    left = tmpLeft;
//                }
//            }
//        }
//        return ret;
//    }
//};










/***************************************** ����֮�ͣ�LeetCode��************************************************/
/*
����һ���������� nums 
�ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k 
ͬʱ������ nums[i] + nums[j] + nums[k] == 0
���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ��
ע�⣺���в����԰����ظ�����Ԫ��
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums)
//    {
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//
//        vector<vector<int>> ret;
//        for (int i = size - 1; i >= 2;)//�̶����һ����
//        {
//            if (nums[i] < 0) return ret;//���һ������Ϊ����, ��ʱ�Ѿ��������ҵ�Ϊ0�������
//            int left = 0, right = i - 1;
//            int target = -nums[i];
//            while (left < right)
//            {
//                int sum = nums[left] + nums[right];
//                if (sum > target) --right;
//                else if (sum < target) ++left;
//                else /*sum == 0*/ {
//                    ret.push_back({ nums[left], nums[right], nums[i] });
//                    ++left, --right;
//                    //ȥ��
//                    while (left < right && nums[left] == nums[left - 1]) left++;
//                    while (left < right && nums[right] == nums[right + 1]) right--;
//                }
//            }
//            --i;
//            while (i >= 2 && nums[i] == nums[i + 1]) i--;//ȥ��
//        }
//        return ret;
//    }
//};










/******************************************* �Ƚϰ汾�ţ�LeetCode��********************************************/
/*
���������汾�� version1 �� version2 ������Ƚ�����
�汾����һ�������޶�����ɣ����޶�����һ�� '.' ���ӡ�ÿ���޶����� ��λ���� ��ɣ����ܰ���ǰ����
ÿ���汾�����ٰ���һ���ַ����޶��Ŵ����ұ�ţ��±�� 0 ��ʼ������ߵ��޶����±�Ϊ 0 ����һ���޶����±�Ϊ 1 ��
�Դ����ơ����磬2.5.33 �� 0.1 ������Ч�İ汾��
�Ƚϰ汾��ʱ���밴�����ҵ�˳�����αȽ����ǵ��޶��š��Ƚ��޶���ʱ��ֻ��Ƚ� �����κ�ǰ����������ֵ
Ҳ����˵���޶��� 1 ���޶��� 001 ��� ������汾��û��ָ��ĳ���±괦���޶��ţ�����޶�����Ϊ 0
���磬�汾 1.0 С�ڰ汾 1.1 ����Ϊ�����±�Ϊ 0 ���޶�����ͬ�����±�Ϊ 1 ���޶��ŷֱ�Ϊ 0 �� 1 ��0 < 1
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
////����һ
//class Solution {
//public:
//    int Compare(string str1, string str2)
//    {
//        int ret = atoi(str1.c_str()) - atoi(str2.c_str());
//        if (ret == 0) return ret;
//        return ret > 0 ? 1 : -1;
//    }
//    int compareVersion(string version1, string version2)
//    {
//        int sizeV1 = version1.size(), sizeV2 = version2.size();
//        int currentV1 = 0, prevV1 = currentV1;
//        int currentV2 = 0, prevV2 = currentV2;
//        while (currentV1 < sizeV1 || currentV2 < sizeV2)
//        {
//            while (currentV1 < sizeV1 && version1[currentV1] != '.') ++currentV1;
//            while (currentV2 < sizeV2 && version2[currentV2] != '.') ++currentV2;
//            int tmpRet = 0;
//
//            if (currentV1 > sizeV1)
//                tmpRet = Compare("0", version2.substr(prevV2, currentV2 - prevV2));
//            else if (currentV2 > sizeV2)
//                tmpRet = Compare(version1.substr(prevV1, currentV1 - prevV1), "0");
//            else if (currentV1 <= sizeV1 || currentV2 <= sizeV2)
//                tmpRet = Compare(version1.substr(prevV1, currentV1 - prevV1), version2.substr(prevV2, currentV2 - prevV2));
//            if (tmpRet != 0) return tmpRet;
//            ++currentV1, ++currentV2;
//            prevV1 = currentV1, prevV2 = currentV2;
//        }
//        return 0;
//    }
//};
////������
//class Solution {
//public:
//    int compareVersion(string version1, string version2)
//    {
//        int n = version1.length(), m = version2.length();
//        int i = 0, j = 0;
//        while (i < n || j < m)
//        {
//            long long x = 0;
//            for (; i < n && version1[i] != '.'; ++i)
//                x = x * 10 + version1[i] - '0';
//            ++i; // �������
//
//            long long y = 0;
//            for (; j < m && version2[j] != '.'; ++j)
//                y = y * 10 + version2[j] - '0';
//            ++j; // �������
//            if (x != y) return x > y ? 1 : -1;
//        }
//        return 0;
//    }
//};
