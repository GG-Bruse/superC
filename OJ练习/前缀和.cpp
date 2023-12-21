/************************************ 区域和检索 - 数组不可变（LeetCode）**************************************/
/*
给定一个整数数组  nums，处理以下类型的多个查询:
计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
实现 NumArray 类：
NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j)返回数组nums中索引left和right之间的元素的总和 ，
包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class NumArray {
//public:
//    NumArray(vector<int>& nums)
//    {
//        int size = nums.size();
//        prevSum = vector<int>(size + 1);
//        for (int i = 0; i < size; ++i)
//            prevSum[i + 1] = prevSum[i] + nums[i];
//    }
//
//    int sumRange(int left, int right) {
//        return prevSum[right + 1] - prevSum[left];
//    }
//private:
//    vector<int> prevSum;//前缀和 : prevSum[i] : nums[0]到nums[i]之间所有元素之和 
//};
///**
// * Your NumArray object will be instantiated and called as such:
// * NumArray* obj = new NumArray(nums);
// * int param_1 = obj->sumRange(left,right);
// */










/********************************** 二维区域和检索 - 矩阵不可变（LeetCode）************************************/
/*
给定一个二维矩阵 matrix，以下类型的多个请求：
计算其子矩形范围内元素的总和，该子矩阵的左上角为(row1, col1)，右下角为(row2, col2)
实现 NumMatrix 类：
NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、
右下角 (row2, col2) 所描述的子矩阵的元素 总和
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class NumMatrix {
//public:
//    NumMatrix(vector<vector<int>>& matrix)
//    {
//        row = matrix.size(), col = matrix[0].size();
//        //prevSum[i][j] : matrix[0][0]到matrix[i - 1][j - 1]之间所有元素之和 
//        prevSum = vector<vector<int>>(row + 1, vector<int>(col + 1));
//        prevSum[1][1] = matrix[0][0];
//        for (int i = 1; i <= row; ++i)
//            for (int j = 1; j <= col; ++j)
//                prevSum[i][j] = prevSum[i - 1][j] + prevSum[i][j - 1] - prevSum[i - 1][j - 1] + matrix[i - 1][j - 1];
//    }
//    int sumRegion(int row1, int col1, int row2, int col2)
//    {
//        ++row1, ++row2, ++col1, ++col2;
//        int ret = prevSum[row2][col2];
//        ret -= (prevSum[row2][col1 - 1] + prevSum[row1 - 1][col2]);
//        ret += prevSum[row1 - 1][col1 - 1];
//        return ret;
//    }
//private:
//    vector<vector<int>> prevSum;
//    int row = 0, col = 0;
//};
///**
// * Your NumMatrix object will be instantiated and called as such:
// * NumMatrix* obj = new NumMatrix(matrix);
// * int param_1 = obj->sumRegion(row1,col1,row2,col2);
// */









/****************************** 矩形区域不超过 K 的最大数值和（LeetCode）**************************************/
/*
给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和
题目数据保证总会存在一个数值和不超过 k 的矩形区域
*/
//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//class Solution {
//public:
//    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
//    {
//        int ret = INT_MIN;
//        int row = matrix.size(), col = matrix[0].size();
//        for (int i = 0; i < row; ++i)//枚举上边界
//        {
//            vector<int> sum(col);//边界内 每列的元素和
//            for (int j = i; j < row; ++j)//枚举下边界
//            {
//                for (int k = 0; k < col; ++k)
//                    sum[k] += matrix[j][k];//更新每列的元素和
//
//                set<int> sumSet{ 0 };
//                int sRight = 0;
//                for (int it : sum)
//                {
//                    sRight += it;
//                    auto sLeft = sumSet.lower_bound(sRight - k);
//                    if (sLeft != sumSet.end())
//                        ret = max(ret, sRight - (*sLeft));
//                    sumSet.insert(sRight);
//                }
//            }
//        }
//        return ret;
//    }
//};