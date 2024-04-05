/********************************* B蓝桥杯2023年第十四届省赛真题-冶炼金属 *********************************/
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









/******************************* B蓝桥杯2023年第十四届省赛真题-飞机降落 **********************************/
/*
N 架飞机准备降落到某个只有一条跑道的机场。其中第 i 架飞机在 Ti 时刻到达机场上空,
到达时它的剩余油料还可以继续盘旋 Di 个单位时间，即它最早可以于 Ti 时刻开始降落，最晚可以于 Ti + Di 时刻开始降落。
降落过程需要 Li个单位时间。一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，
但是不能在前一架飞机完成降落前开始降落。请你判断 N 架飞机是否可以全部安全降落
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<bool> status;//记录飞机是否已经降落 
//
////count : 已有count架飞机降落 ， time : 当前时间 
//bool dfs(vector<vector<int>>& nums, int count, int time)
//{
//	int size = nums.size();
//	if (count == size) return true;
//
//	for (int i = 0; i < size; ++i)
//	{
//		if (status[i] == false)//该飞机目前没有降落 
//		{
//			status[i] = true;
//
//			if (nums[i][0] + nums[i][1] < time) {
//				status[i] = false;
//				return false;
//			}
//			int t = max(time, nums[i][0]) + nums[i][2];
//			if (dfs(nums, count + 1, t)) return true;
//
//			status[i] = false;
//		}
//	}
//	return false;
//}
//int main()
//{
//	int T = 0;
//	cin >> T;
//
//	while (T--)
//	{
//		int N = 0;
//		cin >> N;
//
//		vector<vector<int>> nums(N, vector<int>(3));
//		for (int i = 0; i < N; ++i)
//			cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
//
//		status = vector<bool>(N);
//
//		if (dfs(nums, 0, 0)) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	return 0;
//}










/***************************************** 欺诈克星（校内训练赛） *********************************************/
/*
给定一个含未知字符的长度为9字符串，未知字符用'*'表示（不含引号）
下面给出n个长度为9字符串，如果下面输入的字符串与一开始输入的字符串除未知部分的其他部分完全相同，
则该字符串符合要求,输出符合要求的字符串的数量和每个符合要求的字符串
举例：假设一开始输入的字符串为A58**52*1,则字符串A58ZS52T1符合要求，而字符串A589992G1不符合要求
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	string bench;
//	cin >> bench;
//	int n = 0;
//	cin >> n;
//	vector<string> v(n);
//	for (int i = 0; i < n; ++i) cin >> v[i];
//
//	int size = bench.size();
//	vector<bool> flag(n, true);
//	for (int i = 0; i < n; ++i)
//	{
//		string tmp = v[i];
//		if (size != tmp.size()) {
//			flag[i] = false;
//		}
//		else
//		{
//			for (int j = 0; j < size; ++j)
//			{
//				if (bench[j] != '*' && bench[j] != tmp[j]) {
//					flag[i] = false;
//					break;
//				}
//			}
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < n; ++i)
//		if (flag[i]) ++count;
//	cout << count << endl;
//	for (int i = 0; i < n; ++i)
//		if (flag[i]) cout << v[i] << endl;
//
//	return 0;
//}









/**************************************** 纳萨力克大坟墓（校内训练赛） ****************************************/
/*
在一块长方形的墓地上，有一个长方形的教堂，现在给出一个长宽已知的墓碑，墓碑不能与教堂重叠，
询问这块墓地上能否放下这块墓碑

一共n组输入，对于每i组输入，输入文件:

第1行一个数n
第(i-1)*3+2行包含两对整数: x1,y1,x2,y2(−1e9≤x1<x2≤1e9;−1e9≤y1<y2≤1e9) — 墓地左下角和右上角的坐标
（先 x 轴再 y 轴）
第(i-1)*3+3行还包含两对整数x3,y3,x4,y4(x1<x3<x4<x2;y1<y3<y4<y2) — 教堂左下角和右上角的坐标
（先 x 轴再 y 轴）（保证教堂完全在墓地内部且边缘不重叠）
第(i-1)*3+4行包含两个整数 w,h — 新坟墓的宽度和高度 (1≤w,h≤1e9). 边长w应沿OX轴放置，边长h沿OY轴
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int leftX = 0, leftY = 0;
//		cin >> leftX >> leftY;
//		int rightX = 0, rightY = 0;
//		cin >> rightX >> rightY;
//
//		int leftsx = 0, leftsy = 0;
//		cin >> leftsx >> leftsy;
//		int rightsx = 0, rightsy = 0;
//		cin >> rightsx >> rightsy;
//
//		int width = 0, height = 0;
//		cin >> width >> height;
//
//		int W = abs(rightsx - leftsx), H = abs(rightsy - leftsy);//教堂的宽高
//		int rightW = abs(rightX - rightsx);//右边剩余宽度
//		int leftW = abs(leftsx - leftX);//左边剩余宽度
//		int upH = abs(rightY - rightsy);//上面剩余高度
//		int downH = abs(leftsx - leftX);//下面剩余高度
//		if ((rightW >= width || leftW >= width) && (upH >= height || downH >= height))
//			cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//}









/******************************************* 奶牛聚餐（校内训练赛） *******************************************/
/*
K(1≤K≤100) 只奶牛分散在 (1≤N≤1000) 个牧场．现在她们要集中起来进餐。牧场之间有M(1≤M≤10000) 条有向路连接，
而且不存在起点和终点相同的有向路．她们进餐的地点必须是所有奶牛都可到达的地方。那么，有多少这样的牧场可供进食呢？

输入格式
第 1 行：三个空格分隔的整数，分别为：K、N 和 M
第 2…K+1 行：第 i+1 行包含一个整数 （1...N），它是奶牛 i 放牧的牧场编号
第 K+2...M+K+1行：每行包含两个空格分隔的整数，分别为 A 和 B（均为 1...N 和 A ！= B），
表示从牧场 A 到牧场 B 的单向路径
输出格式
1 行: 单整数，即所有奶牛通过单向路径可到达的牧场数量
*/
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//#include <queue>
//using namespace std;
//unordered_set<int> bfs(int pos, unordered_map<int, vector<int>>& hash, unordered_map<int, int>& count, int n)
//{
//	unordered_set<int> pass;//访问过的牧场
//	queue<int> qe;
//	qe.push(pos);
//	pass.insert(pos);
//	while (!qe.empty())
//	{
//		int front = qe.front();
//		qe.pop();
//		if (hash.count(front))
//		{
//			vector<int> tmp = hash[front];
//			for (int i = 0; i < tmp.size(); ++i)
//				if (!pass.count(tmp[i])) {
//					pass.insert(tmp[i]);
//					qe.push(tmp[i]);
//				}
//		}
//	}
//	return pass;
//}
//int main()
//{
//	int k = 0, n = 0, m = 0;
//	cin >> k >> n >> m;
//	vector<int> v(k);//v[i] : 奶牛i放牧的位置
//	for (int i = 0; i < k; ++i) cin >> v[i];
//
//	unordered_map<int, vector<int>> hash;
//	for (int i = 0; i < m; ++i) {
//		int tmp1 = 0, tmp2 = 0;
//		cin >> tmp1 >> tmp2;
//		hash[tmp1].push_back(tmp2);
//	}
//
//	unordered_map<int, int> count;//f牧场，到达过s次
//	for (int i = 0; i < k; ++i)
//	{
//		if (hash.count(v[i]))
//		{
//			unordered_set<int> pass = bfs(v[i], hash, count, n);
//			for (auto& it : pass) {
//				count[it]++;
//			}
//		}
//	}
//	int ret = 0;
//	for (auto& it : count)
//		if (it.second == k) ++ret;
//	cout << ret << endl;
//	return 0;
//}









/************************************ 蓝桥杯2017年第八届真题-K倍区间 ******************************************/
/*
给定一个长度为 N 的数列，1,2,⋯A1,A2,⋯AN，如果其中一段连续的子序列 Ai,Ai+1,⋯Aj(i≤j) 之和是 K 的倍数，
我们就称这个区间 [i,j] 是 K 倍区间。 聪明的你能求出数列中总共有多少个 K 倍区间吗？
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n = 0, k = 0;
//	cin >> n >> k;
//
//	vector<int> mod(n + 1);//前缀和mod[i] : v[0] 到 v[i]之和, 再求余
//	vector<int> flag(k);//同余的个数,余数由 0 到 k-1
//	int tmpNum = 0;
//	for (int i = 1; i <= n; ++i) {
//		cin >> tmpNum;
//		mod[i] = (mod[i - 1] + tmpNum) % k;
//		++flag[mod[i]];
//	}
//
//	long long count = 0;
//	for (int i = 0; i < k; ++i) {//余数由0到k-1
//		//假设所有前缀和中%k = 1的有3个，任意选2个可的一个k倍区间，Cm2（m在上，2在下）即C32 3 * (3 - 1) / 2 = 3
//		count += (long long)flag[i] * ((long long)flag[i] - 1) / 2;
//	}
//	cout << count + flag[0] << endl;
//	return 0;
//}











/***************************** A蓝桥杯2023年第十四届省赛真题-平方差 ****************************************/
/*
给定 L, R，问 L ≤ x ≤ R 中有多少个数 x 满足存在整数 y,z 使得 x = y^2 − z^2
对于所有评测用例，1 ≤ L ≤ R ≤ 109
*/
/*
解析:
x  =  y^2 - z^2  =  (y + z)(y - z)

令 m = y + z, n = y - z
x = m * n
所以 m、n 为 x 的一对因子

解得 y = (m + n) / 2 , z = (m - n) / 2
可以得出: 要存在正整数y、z，(m + n)、(m - n)必须为偶数

奇数 + 奇数 = 偶数
奇数 - 奇数 = 偶数
偶数 + 偶数 = 偶数
偶数 - 偶数 = 偶数
所以: m、n的奇偶性必须要一致

当m、n都为偶数时，即m % 2 == 0并且n % 2 == 0，那么 x % 4 == 0
或者m、n都为奇数

综上所述：一个数有平方差，那么该数是4的倍数或者该数是奇数
*/
//#include <stdio.h>
//int main()
//{
//	int left = 0, right = 0;
//	int count = 0;
//	scanf("%d%d", &left, &right);
//
//	for (int i = left; i <= right; ++i)
//		if (i % 2 == 0 && i % 4 != 0) ++count;
//	printf("%d\n", right - left + 1 - count);
//}

