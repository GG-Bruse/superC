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