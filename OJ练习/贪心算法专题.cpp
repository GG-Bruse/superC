/********************************************* 柠檬水找零（LeetCode）******************************************/
/*
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯
每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元
你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付5美元
注意，一开始你手头没有任何零钱
给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false
*/
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool lemonadeChange(vector<int>& bills)
//    {
//        unordered_map<int, int> hash;//money : count
//        for (int i = 0; i < bills.size(); ++i)
//        {
//            if (bills[i] == 5) ++hash[5];
//            else if (bills[i] == 10) {
//                if (hash.count(5)) --hash[5], ++hash[10];
//                else return false;
//            }
//            else {/*bills[i] == 20*/
//                if (hash[5] >= 1 && hash[10] >= 1) --hash[5], --hash[10], ++hash[20];
//                else if (hash[5] >= 3) hash[5] -= 3, ++hash[20];
//                else return false;
//            }
//        }
//        return true;
//    }
//};








/*************************************** 将数组和减半的最少操作次数（LeetCode）********************************/
/*
给你一个正整数数组 nums 。每一次操作中，
你可以从nums中选择任意一个数并将它减小到恰好一半（注意，在后续操作中你可以对减半过的数继续执行操作）
请你返回将 nums 数组和 至少 减少一半的 最少 操作数
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//class Solution {
//public:
//    int halveArray(vector<int>& nums)
//    {
//        int count = 0;
//        double target = 0;//需要删除的大小
//        priority_queue<double> qe;
//        for (int& it : nums) {
//            qe.push(it);
//            target += ((double)it / 2);
//        }
//
//        double del = 0;//已删除的大小
//        while (del < target) {
//            //取出此时最大数
//            double tmp = qe.top() / 2;
//            qe.pop();
//            //将最大数 / 2,重新插入
//            qe.push(tmp);
//            //增加已删除的数
//            del += tmp;
//            //增加操作次数
//            ++count;
//        }
//        return count;
//    }
//};









/*********************************************** 最大数（LeetCode）***********************************************/
/*
给定一组非负整数nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数
注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数
*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    string largestNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end(), [](int num1, int num2) {
//            return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
//        });
//        string ret = "";
//        for (int& it : nums) ret += to_string(it);
//        if (ret[0] == '0') return "0";
//        return ret;
//    }
//};









/******************************************** 摆动序列（LeetCode）************************************************/
/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数
仅有一个元素或者含两个不等元素的序列也视作摆动序列
例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的
相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，
第二个序列是因为它的最后一个差值为零。
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
//        if (size < 2) return size;
//
//        int maxLength = 0, left = 0;
//        for (int i = 0; i < size - 1; ++i)
//        {
//            int right = nums[i + 1] - nums[i];//接下来的趋势
//            if (right == 0) continue;
//            if (left * right <= 0) ++maxLength;//左右趋势相反,即存在波峰或波谷
//            left = right;
//        }
//        return maxLength + 1;
//    }
//};