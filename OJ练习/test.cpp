//���ף�ţ�ͣ�
/*
�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��
A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡�
�����������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס�
���ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�

������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵�������
���ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�����
*/
//˼·��Ҫ�����������ɫ,����ȡ�ߣ�sum - min + 1��������

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Gloves {
//public:
//    int findMinimum(int n, vector<int> left, vector<int> right) {
//        int left_sum = 0, left_min = INT_MAX;
//        int right_sum = 0, right_min = INT_MAX;
//
//        int sum = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            if (left[i] * right[i] == 0) //��һ������Ϊ0
//                sum += (left[i] + right[i]);
//            else
//            {
//                left_sum += left[i];
//                left_min = left_min < left[i] ? left_min : left[i];
//                right_sum += right[i];
//                right_min = right_min < right[i] ? right_min : right[i];
//            }
//        }
//        //�����׺�������ѡһ����С�ģ�������һ����ȡһ������
//        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
//    }
//};
//int main()
//{
//    int n = 4;
//    vector<int> left{ 0,7,1,6 };
//    vector<int> right{ 1,5,0,6 };//ȷ��5��6�ж���һ�����ױ��õ����ɣ���8����
//    int ret = Gloves().findMinimum(n, left, right);
//    cout << ret << endl;
//    return 0;
//}