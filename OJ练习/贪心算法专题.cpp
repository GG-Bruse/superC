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