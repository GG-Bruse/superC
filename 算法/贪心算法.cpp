//#include <iostream>
//void Swap(int* num1, int* num2) 
//{
//	if (num1 == num2) return;
//	*num1 += (*num2);//a = a+b
//	*num2 = (*num1) - (*num2);//b = a
//	*num1 -= (*num2);
//}
//void SelectSort(int* arr, int size)
//{
//	for (int i = 0; i < size - 1; ++i) 
//	{
//		int minIndex = i;
//		for (int j = i + 1; j < size; ++j)
//		{
//			if (arr[j] < arr[minIndex]) minIndex = j;
//		}
//		Swap(&arr[i], &arr[minIndex]);
//	}
//}
//int main()
//{
//	int arr[] = { 10,8,6,20,9,77,32,91 };
//	SelectSort(arr, sizeof(arr) / sizeof(int));
//	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) {
//		std::cout << arr[i] << " ";
//	}
//	return 0;
//}






//class Solution {
//public:
//    int balancedStringSplit(string s) {
//        int count = 0;
//        int balance = 0;
//        for (int i = 0; i < s.size(); ++i) {
//            if (s[i] == 'L') --balance;
//            if (s[i] == 'R') ++balance;
//            if (balance == 0) ++count;
//        }
//        return count;
//    }
//};



//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int ret = 0;
//        for (int i = 1; i < prices.size(); ++i) {
//            int profit = prices[i] - prices[i - 1];
//            if (profit > 0) ret += profit;
//        }
//        return ret;
//    }
//};




//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int maxIndex = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (i <= maxIndex) //iλ�������Χ�ڣ�˵��iλ�ÿ��Ե���
//            {
//                maxIndex = max(maxIndex, i + nums[i]);//�������Χ
//                if (maxIndex >= nums.size() - 1)
//                    return true;//�����Χ�������һ��λ�ã�˵�����һ��λ�ÿ��Ե���
//            }
//        }
//        return false;
//    }
//};




//#include <iostream>
//#include <vector>
//using namespace std;
//int Solve(int money, vector<pair<int, int>>& moneyCount)
//{
//	int num = 0;
//	for (int i = moneyCount.size() - 1; i >= 0; --i)//����:��ʹ����ֵ���Ǯ��
//	{
//		int count = min(moneyCount[i].second, money / moneyCount[i].first);//��Ҫ��������ӵ�е�������ѡ���С��
//		money -= moneyCount[i].first * count;
//		num += count;
//	}
//	if (money != 0) return -1;//�Ҳ���Ǯ
//	return num;
//}
//int main()
//{
//	//first:��ֵ second:����
//	vector<pair<int, int>> moneyCount = { {1,3},{2,1},{5,4},{10,3},{20,0},{50,1},{100,10} };
//	int money = 0;
//	cout << "��������Ҫ֧������Ǯ" << endl;
//	cin >> money;
//
//	int ret = Solve(money, moneyCount);
//	if (ret == -1) cout << "No" << endl;
//	else cout << ret << endl;
//	return 0;
//}








//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Compare {
//public:
//	bool operator()(int x, int y) {
//		return x > y;
//	}
//};
//int GreedStrategy(vector<int>& works, vector<int>& machines) 
//{
//	//����ҵʱ��Ӵ�С����
//	sort(works.begin(), works.end(), Compare());
//	//����ҵ��С�ڵ��ڻ�������ֱ�ӷ���������ҵʱ�伴��
//	if (works.size() <= machines.size()) return works[0];
//
//	//�Ӵ�СΪÿ����ҵ�������
//	for (int i = 0; i < works.size(); ++i) {
//		//����ѡ���һ������
//		int minMachines = 0;
//		int time = machines[minMachines];
//		//�ӻ�����ѡ����ҵʱ����С��
//		for (int j = 1; j < machines.size(); ++j) {
//			if (time > machines[j]) {
//				minMachines = j;
//				time = machines[j];
//			}
//		}
//		//����ǰ��ҵ������ҵʱ����С�Ļ���
//		machines[minMachines] += works[i];
//	}
//
//	//�����л�����ѡ���ܹ���ҵʱ�����
//	int ret = machines[0];
//	for (int i = 1; i < machines.size(); ++i) {
//		ret = max(ret, machines[i]);
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0, m = 0;
//	cout << "��������ҵ���ͻ�����" << endl;
//	cin >> n >> m;
//
//	vector<int> works(n);
//	vector<int> machines(m, 0);//�洢ÿ̨�����ܹ�����ҵʱ��
//	cout << "�����������ҵ����Ҫ��ʱ��" << endl;
//	for (int i = 0; i < n; ++i) {
//		cin >> works[i];
//	}
//
//	cout << GreedStrategy(works, machines) << endl;
//	return 0;
//}