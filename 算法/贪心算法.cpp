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
//            if (i <= maxIndex) //i位置在最大范围内，说明i位置可以到达
//            {
//                maxIndex = max(maxIndex, i + nums[i]);//更新最大范围
//                if (maxIndex >= nums.size() - 1)
//                    return true;//若最大范围包括最后一个位置，说明最后一个位置可以到达
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
//	for (int i = moneyCount.size() - 1; i >= 0; --i)//逆序:先使用面值大的钱币
//	{
//		int count = min(moneyCount[i].second, money / moneyCount[i].first);//需要的数量和拥有的数量中选择较小的
//		money -= moneyCount[i].first * count;
//		num += count;
//	}
//	if (money != 0) return -1;//找不开钱
//	return num;
//}
//int main()
//{
//	//first:面值 second:数量
//	vector<pair<int, int>> moneyCount = { {1,3},{2,1},{5,4},{10,3},{20,0},{50,1},{100,10} };
//	int money = 0;
//	cout << "请输入需要支付多少钱" << endl;
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
//	//按作业时间从大到小排序
//	sort(works.begin(), works.end(), Compare());
//	//若作业数小于等于机器数，直接返回最大的作业时间即可
//	if (works.size() <= machines.size()) return works[0];
//
//	//从大到小为每个作业分配机器
//	for (int i = 0; i < works.size(); ++i) {
//		//假设选择第一个机器
//		int minMachines = 0;
//		int time = machines[minMachines];
//		//从机器中选择作业时间最小的
//		for (int j = 1; j < machines.size(); ++j) {
//			if (time > machines[j]) {
//				minMachines = j;
//				time = machines[j];
//			}
//		}
//		//将当前作业交给作业时间最小的机器
//		machines[minMachines] += works[i];
//	}
//
//	//从所有机器中选择总共作业时间最长的
//	int ret = machines[0];
//	for (int i = 1; i < machines.size(); ++i) {
//		ret = max(ret, machines[i]);
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0, m = 0;
//	cout << "请输入作业数和机器数" << endl;
//	cin >> n >> m;
//
//	vector<int> works(n);
//	vector<int> machines(m, 0);//存储每台机器总共的作业时间
//	cout << "请输入各个作业所需要的时间" << endl;
//	for (int i = 0; i < n; ++i) {
//		cin >> works[i];
//	}
//
//	cout << GreedStrategy(works, machines) << endl;
//	return 0;
//}