/********************************************* ����ˮ���㣨LeetCode��******************************************/
/*
������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ���˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ��
ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ
������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧��5��Ԫ
ע�⣬һ��ʼ����ͷû���κ���Ǯ
����һ���������� bills ������ bills[i] �ǵ� i λ�˿͸����ˡ�������ܸ�ÿλ�˿���ȷ���㣬���� true �����򷵻� false
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








/*************************************** ������ͼ�������ٲ���������LeetCode��********************************/
/*
����һ������������ nums ��ÿһ�β����У�
����Դ�nums��ѡ������һ������������С��ǡ��һ�루ע�⣬�ں�������������ԶԼ������������ִ�в�����
���㷵�ؽ� nums ����� ���� ����һ��� ���� ������
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
//        double target = 0;//��Ҫɾ���Ĵ�С
//        priority_queue<double> qe;
//        for (int& it : nums) {
//            qe.push(it);
//            target += ((double)it / 2);
//        }
//
//        double del = 0;//��ɾ���Ĵ�С
//        while (del < target) {
//            //ȡ����ʱ�����
//            double tmp = qe.top() / 2;
//            qe.pop();
//            //������� / 2,���²���
//            qe.push(tmp);
//            //������ɾ������
//            del += tmp;
//            //���Ӳ�������
//            ++count;
//        }
//        return count;
//    }
//};









/*********************************************** �������LeetCode��***********************************************/
/*
����һ��Ǹ�����nums����������ÿ������˳��ÿ�������ɲ�֣�ʹ֮���һ����������
ע�⣺���������ܷǳ�����������Ҫ����һ���ַ�������������
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









/******************************************** �ڶ����У�LeetCode��************************************************/
/*
�����������֮��Ĳ��ϸ���������͸���֮�佻�棬���������г�Ϊ �ڶ����� ����һ���������ڵĻ�����������������
����һ��Ԫ�ػ��ߺ���������Ԫ�ص�����Ҳ�����ڶ�����
���磬 [1, 7, 4, 9, 2, 5] ��һ�� �ڶ����� ����Ϊ��ֵ (6, -3, 5, -7, 3) ������������ֵ�
�෴��[1, 4, 7, 2, 5] �� [1, 7, 4, 5, 5] ���ǰڶ����У���һ����������Ϊ����ǰ������ֵ����������
�ڶ�����������Ϊ�������һ����ֵΪ�㡣
������ ����ͨ����ԭʼ������ɾ��һЩ��Ҳ���Բ�ɾ����Ԫ������ã�ʣ�µ�Ԫ�ر�����ԭʼ˳��
����һ���������� nums ������ nums ����Ϊ �ڶ����� �� ������еĳ���
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
//            int right = nums[i + 1] - nums[i];//������������
//            if (right == 0) continue;
//            if (left * right <= 0) ++maxLength;//���������෴,�����ڲ���򲨹�
//            left = right;
//        }
//        return maxLength + 1;
//    }
//};