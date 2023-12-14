/*********************************** 蓝桥杯2023年第十四届省赛真题-冶炼金属 *********************************/
/*
小蓝有一个神奇的炉子用于将普通金属 O 冶炼成为一种特殊金属 X
这个炉子有一个称作转换率的属性 V，V 是一个正整数，这意味着消耗 V 个普通金属 O 恰好可以冶炼出一个特殊金属 X，
当普通金属 O 的数目不足 V 时，无法继续冶炼
现在给出了 N 条冶炼记录，每条记录中包含两个整数 A 和 B，这表示本次投入了 A 个普通金属 O，
最终冶炼出了 B 个特殊金属 X。每条记录都是独立的，
这意味着上一次没消耗完的普通金属 O 不会累加到下一次的冶炼当中。
根据这 N 条冶炼记录，请你推测出转换率 V 的最小值和最大值分别可能是多少，题目保证评测数据不存在无解的情况
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<vector<long long>> v(n, vector<long long>(2));
//	for (int i = 0; i < n; ++i) cin >> v[i][0] >> v[i][1];
//
//	long long maxV = 0xfffff, minV = 0xfffff;
//
//	for (int i = 0; i < n; ++i)
//		maxV = min(maxV, v[i][0] / v[i][1]);
//
//	for (long long i = maxV; i >= 1; --i)
//	{
//		for (long long j = 0; j < n; ++j)
//			if ((v[j][0] / i) > v[j][1]) {
//				minV = i + 1;
//				break;
//			}
//		if (minV != 0xfffff) break;
//	}
//	cout << minV << " " << maxV << endl;
//	return 0;
//}