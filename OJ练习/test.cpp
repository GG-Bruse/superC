﻿/******************************************************手套（牛客）*******************************************************************/
/*
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。
现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。

给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。
数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案
*/

//思路：要想包括所有颜色,则需取走（sum - min + 1）个手套


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
//            if (left[i] * right[i] == 0) //有一边手套为0
//                sum += (left[i] + right[i]);
//            else
//            {
//                left_sum += left[i];
//                left_min = left_min < left[i] ? left_min : left[i];
//                right_sum += right[i];
//                right_min = right_min < right[i] ? right_min : right[i];
//            }
//        }
//        //左手套和右手套选一个最小的，再在另一边任取一个即可
//        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
//    }
//};
//int main()
//{
//    int n = 4;
//    vector<int> left{ 0,7,1,6 };
//    vector<int> right{ 1,5,0,6 };//确保5和6中都有一个手套被拿到即可（拿8个）
//    int ret = Gloves().findMinimum(n, left, right);
//    cout << ret << endl;
//    return 0;
//}














/****************************************************查找输入整数二进制中1的个数（牛客）***************************************************/
/*
输入一个正整数，计算它在二进制下的1的个数
*/

//#include <iostream>
//using namespace std;
//size_t Count(size_t num)//算数运算
//{
//    size_t count = 0;
//    while (num)
//    {
//        if (num % 2 == 1) ++count;
//        num /= 2;
//    }
//    return count;
//}
//size_t Count(size_t num)//位运算
//{
//    size_t count = 0;
//    while (num)
//    {
//        if (num & 0x01 == 1) ++count;
//        num >>= 1;
//    }
//    return count;
//}
//size_t Count(size_t num)//位运算优化
//{
//    size_t count = 0;
//    while (num)
//    {
//        num = num & (num - 1);//时间复杂度仅与二进制中1的个数有关
//        ++count;
//    }
//    return count;
//}
//int main() {
//    size_t n = 0;
//    while (cin >> n) {
//        cout << Count(n) << endl;
//    }
//    return 0;
//}
//
//#include <iostream>
//#include <bitset>//位图
//using namespace std;
//int main() {
//    int n = 0;
//    while (cin >> n) {
//        bitset<32> bs(n);
//        cout << bs.count() << endl;
//    }
//    return 0;
//}













/**********************************************************扑克牌大小(牛客)************************************************************/
/*
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
基本规则：
（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，
    由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系
    （如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；
    炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。
*/

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//string GetMAX(const string& str)
//{
//    //有王炸就不需要关心是哪手牌了，反正王炸最大
//    if (str.find("joker JOKER") != string::npos) return "joker JOKER";
//    if (str.find("JOKER joker") != string::npos) return "JOKER joker";
//
//    //将字符串切分为两手
//    int index = str.find("-");
//    string left = str.substr(0, index);
//    string right = str.substr(index + 1);
//
//    //分别计算两手牌的张数
//    int left_num = count(left.begin(), left.end(), ' ') + 1;
//    int right_num = count(right.begin(), right.end(), ' ') + 1;
//
//    //分别取出两手的第一张（顺子已排序，对子、单张、三张、炸弹都无需排序，王炸已处理）
//    string left_first = left.substr(0, left.find(' '));
//    string right_first = right.substr(0, right.find(' '));
//
//
//    if (left_num == right_num) {//两手牌类型相同
//        string map = "345678910JQKA2jokerJOKER";
//        if (map.find(left_first) > map.find(right_first)) return left;
//        else return right;
//    }
//    //两手牌类型不同
//    if (left_num == 4) return left;
//    else if (right_num == 4) return right;
//    else return "ERROR";
//}
//int main() {
//    string str;
//    while (getline(cin, str)) {
//        string ret = GetMAX(str);
//        cout << ret << endl;
//    }
//    return 0;
//}
















/********************************************************杨辉三角的变形（牛客）************************************************************/
/*
第一行只有一个数1，以下每行的每个数，是恰好是它上面的数、左上角数和右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。
例如输入3, 则输出2，输入4则输出3，输入2则输出 - 1
                            1
                        1       1
                    1   2   3   2   1
                1   3   6   7   6   3   1
            1   4   10  16  19  16  10  4   1
*/
/*
解题思路：
再往下写几行即可找出规律
n       1   2   3   4   5   6   7   8   9   
index   -1  -1  2   3   2   4   2   3   2
*/

//#include <iostream>
//using namespace std;
//int GetRet(const int n)
//{
//    if (n <= 2) return -1;
//    else {
//        switch ((n - 2) % 4)
//        {
//        case 1: return 2;
//        case 2: return 3;
//        case 3: return 2;
//        case 0: return 4;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    int n = 0;
//    while (cin >> n) {
//        cout << GetRet(n) << endl;
//    }
//    return 0;
//}















/********************************************************统计每个月兔子的总数（牛客）***********************************************************/
/*
有一种兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子。
例子：假设一只兔子第3个月出生，那么它第5个月开始会每个月生一只兔子。
一月的时候有一只兔子，假如兔子都不死，问第n个月的兔子总数为多少？
数据范围：输入满足1≤n≤31
*/
//解题思路：找规律本质上就是斐波那契数列，递归法、迭代法、动态规划都可以解决问题

//#include <iostream>
//#include <vector>
//using namespace std;
//int GetRabbitNum(int num)//动态规划
//{
//    vector<int> v(num);
//    v[0] = 1;
//    for (int i = 1; i < num; ++i) {
//        if (i - 2 >= 0)
//            v[i] = v[i - 2] + v[i - 1];
//        else
//            v[i] = v[i - 1];
//    }
//    return v[num - 1];
//}
//int main() {
//    int n = 0;
//    while (cin >> n) {
//        cout << GetRabbitNum(n) << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int GetRabbitNum(int num)//迭代法
//{
//    if (num <= 2) return 1;
//    int prev = 1, cur = 1;
//    int next = 0;
//    for (int i = 3; i <= num; ++i)
//    {
//        next = prev + cur;
//        prev = cur;
//        cur = next;
//    }
//    return next;
//}
//int main() {
//    int n = 0;
//    while (cin >> n) {
//        cout << GetRabbitNum(n) << endl;
//    }
//    return 0;
//}















/***********************************************查找两个字符串a,b中的最长公共子串（牛客）***********************************************/
/*
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！
数据范围：字符串长度1≤length≤300
*/
/*
解题思路：
使用动态规划算法
            0   1   2   3   4   5   6   7   8   9
            a   b   y   c   d   e   f   h   z
    0   a   0
    1   b       1   
    2   c           2   0
    3   d                   1
    4   e                       2
    5   f                           3
    6   g                               4
    7
*/

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//string GetPublicSubStr(string str1, string str2)
//{
//    if (str1.size() > str2.size()) swap(str1, str2);
//    vector<vector<int>> v(str1.size() + 1, vector<int>(str2.size() + 1, 0));
//    int start = 0, maxSize = 0;
//    for (int i = 1; i <= str1.size(); ++i)
//    {
//        for (int j = 1; j <= str2.size(); ++j)
//        {
//            if (str1[i - 1] == str2[j - 1])
//                v[i][j] = v[i - 1][j - 1] + 1;
//            if (v[i][j] > maxSize)
//            {
//                maxSize = v[i][j];
//                start = i - maxSize;
//            }
//        }
//    }
//    return str1.substr(start, maxSize);
//}
//int main()
//{
//    string str1, str2;
//    while (cin >> str1 >> str2) {
//        cout << GetPublicSubStr(str1, str2) << endl;
//    }
//    return 0;
//}


















/*********************************************************** MP3光标的位置（牛客）**********************************************************/
/*
MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。
为了简化处理，假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：

1. 歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。
光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。

2. 歌曲总数大于4的时候（以一共有10首歌为例）：
特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，用户按Up键后，屏幕要显示最后一页（即显示第7-10首歌），
同时光标放到最后一首歌上。同样的，屏幕显示最后一页时，光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上

一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，
屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的Down键处理也类似

其他情况，不用翻页，只是挪动光标就行
*/

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//vector<int> GetResult(int num, string& op) {
//    int current = 1;
//
//    int gap = 0;
//    if (num > 4) gap = 3;
//    else gap = num - 1;
//
//    int start = 1, end = start + gap;
//
//    for (int i = 0; i < op.size(); ++i) {
//        if (op[i] == 'U' && current > start) {
//            current--;
//        }
//        else if (op[i] == 'D' && current < end) {
//            current++;
//        }
//        else if (op[i] == 'U' && current == start) {
//            if (current == 1) {
//                current = num;
//                end = num;
//                start = num - gap;
//            }
//            else {
//                current--;
//                start--;
//                end--;
//            }
//        }
//        else if (op[i] == 'D' && current == end) {
//            if (current == num) {
//                start = 1;
//                end = start + gap;
//                current = 1;
//            }
//            else {
//                ++end;
//                ++current;
//                ++start;
//            }
//        }
//    }
//    vector<int> v;
//    for (int i = start; i <= end; ++i) {
//        v.push_back(i);
//    }
//    v.push_back(current);
//    return v;
//}
//int main() {
//    int number = 0;
//    string op;
//    while (cin >> number >> op) {
//        vector<int> ret = GetResult(number, op);
//        for (int i = 0; i < ret.size() - 1; ++i) {
//            cout << ret[i] << " ";
//        }
//        cout << endl;
//        cout << ret[ret.size() - 1];
//    }
//    return 0;
//}

















/************************************************找出字符串中第一个只出现一次的字符（牛客）************************************************/
/*
找出字符串中第一个只出现一次的字符
数据范围：输入的字符串长度满足1≤n≤1000
*/

//#include <iostream>
//#include <unordered_map>
//#include <string>
//using namespace std;
//int GetFirstWord_1(const string& str)
//{
//    unordered_map<char, int> mp;
//    for (int i = 0; i < str.size(); ++i) {
//        mp[str[i]]++;
//    }
//    int index = -1;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (mp[str[i]] == 1) {
//            index = i;
//            break;
//        }
//    }
//    return index;
//}
//int GetFirstWord_2(const string& str)
//{
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str.find_first_of(str[i]) == str.find_last_of(str[i])) {
//            return i;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    string str;
//    while (cin >> str) {
//        int index = GetFirstWord_1(str);
//        if (index == -1) cout << "-1" << endl;
//        else cout << str[index] << endl;
//    }
//    return 0;
//}
















/**************************************************************年终奖（牛客）***************************************************************/
/*
小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，
上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，
到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。

给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//class Bonus {
//public:
//    int getMost(vector<vector<int> > board)
//    {
//        int row = board.size();
//        int col = board[0].size();
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                if (i == 0 && j == 0) continue;
//                if (i == 0)
//                    board[i][j] = board[i][j] + board[i][j - 1];
//                else if (j == 0)
//                    board[i][j] = board[i - 1][j] + board[i][j];
//                else
//                    board[i][j] = max(board[i - 1][j], board[i][j - 1]) + board[i][j];
//            }
//        }
//        return board[row - 1][col - 1];
//    }
//};
















/*************************************************************星际密码（牛客）**************************************************************/
/*
星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，通过一张表里的信息映射成最终4位密码。
表的规则是：n对应的值是矩阵X的n次方的左上角，如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
例如n=2时，
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
即2对应的数是“0002”

输入描述：
输入有多组数据。
每组数据两行：第一行包含一个整数n (1≤n≤100)；第二行包含n个正整数Xi (1≤Xi≤10000) （注意：每个Xi对应上述的n）
输出描述：
对应每一组输入，输出一行相应的密码
*/
/*
解题思路：
列出n = 1,2,3,4,5...的情况，可发现其斐波那契数列的规律
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        vector<int> fib(10001);
//        fib[0] = 0, fib[1] = 1, fib[2] = 2;
//        for (int i = 3; i <= 10000; ++i)
//        {
//            fib[i] = fib[i - 1] + fib[i - 2];
//            fib[i] %= 10000;
//        }
//
//        int num = 0;
//        for (int i = 0; i < n; ++i) {
//            cin >> num;
//            printf("%04d", fib[num]);
//        }
//        cout << endl;
//    }
//    return 0;
//}



















/****************************************************************数根（牛客）***********************************************************/
/*
数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；
如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。

输入描述：
输入包含多组数据。
每组数据数据包含一个正整数n（1≤n≤10E1000）。
输出描述：
对应每一组数据，输出该正整数的数根
*/

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main() {
//    string str;
//    while (cin >> str) {
//        long long num = 0;
//        for (auto it : str) num += (it - '0');//输入太大，字符串接收，进行各位相加处理
//
//        long long sum = 0;
//        while (num)
//        {
//            sum += num % 10;
//            num /= 10;
//            if (num == 0 && sum >= 10) {//一次各位相加并不能得到数根（个位数）
//                num = sum;
//                sum = 0;
//            }
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}



















/*********************************************************跳台扩展问题（牛客）**************************************************************/
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法
*/
/*
解题思路：
对于最后一级台阶，我们可以由倒数第二级台阶跳1步，也可以由倒数第三级太极跳两步，
即 f(n) = f(n−1)+f(n−2)+...+f(n−(n−1))+f(n−n) = f(0)+f(1)+f(2)+...+f(n−1)，
因为f(n−1) = f(n−2)+f(n−3)+...+f((n−1)−(n−2))+f((n−1)−(n−1))，经整理得
f(n) = f(n−1)+f(n−1) = 2∗f(n−1)，因此每级台阶方案数是前面一级台阶方案数的2倍

也可以直接看出规律，当1级台阶时1种跳法，当2级台阶时2种跳法，当3级台阶时4种跳法，即2^(number - 1)
*/

//class Solution {
//public:
//    int jumpFloorII(int number)
//    {
//        if (number == 1) return 1;
//        return 2 * jumpFloorII(number - 1);
//    }
//};
//class Solution {
//public:
//    int jumpFloorII(int number) // 2 ^ (number - 1)
//    {
//        int ret = 1;
//        for (int i = 0; i < number - 1; ++i) ret *= 2;
//        return ret;
//    }
//};

















/*******************************************************不用加减乘除做加法（牛客）**********************************************************/
/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
数据范围：两个数都满足−10≤n≤1000
*/
/*
解题思路：
位运算中两数进行异或运算可以提供两数加和后二进制非进位信息，位运算中的两数进行与运算的结果可以提供两数加和后的二进制进位信息。
因此将两数与运算的结果进行循环左移一位，并在下一轮循环中继续将移位后的进位结果和非进位结果求和，重复此过程，直到不再产生进位为止
5 + 7 = 2 + 10 = 12
0101 + 0111 = 0010 + 1010 = 1000 + 0100 = 1100 + 0000
*/

//class Solution {
//public:
//    int Add(int num1, int num2) {
//        while (num2)//进位的值为0就停止
//        {
//            int tmp = num1 ^ num2;//不算进位的相加值
//            num2 = (num1 & num2) << 1;//进位的值
//            num1 = tmp;
//        }
//        return num1;
//    }
//};
















/*************************************************反转部分单向链表（牛客）*************************************************/
/*
给定一个单链表，在链表中把第 L 个节点到第 R 个节点这一部分进行反转

n 表示单链表的长度
val 表示单链表各个节点的值
L 表示翻转区间的左端点
R 表示翻转区间的右端点

输入：
5
1 2 3 4 5
1 3
输出：
3 2 1 4 5
*/

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct ListNode {
//    int _data;
//    struct ListNode* _next;
//}ListNode;
//void CreateList(ListNode* phead)
//{
//    int length = 0;
//    scanf("%d", &length);
//    ListNode* current = phead;
//    ListNode* node;
//    for (int i = 0; i < length; ++i)
//    {
//        node = (ListNode*)malloc(sizeof (struct ListNode));
//        scanf("%d", &node->_data);
//        node->_next = NULL;
//        current->_next = node;
//        current = current->_next;
//    }
//}
//void PrintList(ListNode* phead)
//{
//    ListNode* current = phead->_next;
//    for (; current->_next != NULL; current = current->_next) {
//        printf("%d ", current->_data);
//    }
//    printf("%d", current->_data);
//    printf("\n");
//}
//
//void ReverseList_1(ListNode* phead, int left, int right)//多指针法
//{
//    ListNode* current = phead;
//
//    ListNode* prevNode = NULL, * leftNode = NULL, * rightNode = NULL, * nextNode = NULL;
//
//    for (int i = 0; i <= right; ++i)
//    {
//        if (i == left - 1) {
//            prevNode = current; 
//            leftNode = prevNode->_next;
//        }
//        if (i == right) {
//            rightNode = current;
//            nextNode = rightNode->_next;
//        }
//        current = current->_next;
//    }
//
//    ListNode* prev = prevNode;
//    current = prev->_next;
//    ListNode* next = current->_next;
//    for (int i = 0; i <= right - left; ++i)
//    {
//        current->_next = prev;
//        prev = current;
//        current = next;
//        if(next != NULL)next = next->_next;
//    }
//    leftNode->_next = nextNode;
//    prevNode->_next = rightNode;
//}
//void ReverseList(ListNode* phead, int left, int right)//头插法
//{
//    ListNode* current = phead;
//    ListNode* prevNode = phead;
//
//    for (int i = 0; i < left - 1; ++i) {
//        prevNode = prevNode->_next;
//    }
//    current = prevNode->_next;
//
//    for (int i = 0; i < right - left; ++i)
//    {
//        ListNode* insert = current->_next;
//        current->_next = insert->_next;
//        insert->_next = prevNode->_next;
//        prevNode->_next = insert;
//    }
//}
//int main()
//{
//    ListNode head;//带头结点便于处理
//    CreateList(&head);
//    int left = 0, right = 0;
//    scanf("%d%d", &left, &right);
//    ReverseList(&head, left, right);
//    PrintList(&head);
//    return 0;
//}


















/*****************************************************猴子分桃（牛客）*****************************************************/
/*
老猴子辛苦了一辈子，给那群小猴子们留下了一笔巨大的财富——一大堆桃子。老猴子决定把这些桃子分给小猴子。
第一个猴子来了，它把桃子分成五堆，五堆一样多，但还多出一个。它把剩下的一个留给老猴子，自己拿走其中的一堆。
第二个猴子来了，它把桃子分成五堆，五堆一样多，但又多出一个。它把多出的一个留给老猴子，自己拿走其中的一堆。
后来的小猴子都如此照办。最后剩下的桃子全部留给老猴子。
这里有n只小猴子，请你写个程序计算一下在开始时至少有多少个桃子，以及最后老猴子最少能得到几个桃子

输入描述：
输入包括多组测试数据
每组测试数据包括一个整数n(1≤n≤20)
输入以0结束，该行不做处理

输出描述：
每组测试数据对应一行输出
包括两个整数a，b
分别代表开始时最小需要的桃子数，和结束后老猴子最少能得到的桃子数
*/

/*
解题思路：设最开始有X个桃子
                得到的桃子数                     剩余的桃子数
第一只猴子      (X - 1)/5                        (X - 1)*4/5
第二只猴子      ((X - 1)*4/5 - 1)/5              ((X - 1)*4/5 - 1)*4/5 = (4/5X - 4/5 - 1)*4/5 = (4/5)^2 * X - (4/5)^2 - 4/5
第三只猴子      ((4/5X - 4/5 - 1)*4/5 - 1)/5     (4/5)^3 * X - (4/5)^3 - (4/5)^2
第n只猴子                                        (4/5)^n * X - (4/5)^n - ... - (4/5)^1

   S =               (4/5)^n + (4/5)^(n - 1) + ... + (4/5)^2 + (4/5)^1
4/5S = (4/5)^(n+1) + (4/5)^n + (4/5)^(n - 1) + ... + (4/5)^2

S - 4/5S = 1/5S = 4/5 - (4/5)^(n+1) = 4/5(1 - (4/5)^n)
S = 4(1 - (4/5)^n)

所以,第n只猴子剩余的桃子数为：(4/5)^n * X + 4*(4/5)^n - 4 = (4/5)^n * (X+4) - 4 = 4^n / 5^n * (X+4) - 4

当X + 4 = 5^n时最小，即X = 5^n - 4
老猴子剩余的数量为：第n个猴子分完剩余的 + 每轮拿到一个
即(4/5)^n * (X+4) - 4 + n，将X代入，(4/5)^n * (5^n-4+4) - 4 + n = 4^n + n - 4
*/

//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        if (n < 1 || n > 20) break;
//
//        long long sum = (long long)pow(5, n);
//        long long lest = (long long)pow(4, n);
//        cout << sum - 4 << " " << lest + n - 4 << endl;
//    }
//    return 0;
//}















/******************************************************有假币（牛客）******************************************************/
/*
居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！
可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，
给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来

输入描述:
1≤n≤2^30,输入0结束程序
输出描述:
最多要称几次一定能把那个假币找出来？
*/

/*
解题思路：
每次将硬币分为三堆,比较个数相同的两堆；若有一堆较轻，则假币在该堆中；若两堆相同，则假币在第三堆中
由于要求最多要称几次，所以默认假币在剩余硬币最多的堆中

1.硬币可平均分为三份,n / 3
2.硬币分为三份后余1个，n/3 + 1, n/3, n/3 ,后两堆比较
3.硬币分为三份后余2个
        n/3 + 1, n/3 + 1, n/3
        n/3 + 2, n/3，n/3
        以8为例，第一种方式最多称2次，3、1
                 第二种方式最多称3次，4、2、1，且当硬币数为2时出现计算出错
*/

//#include <iostream>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        if (n == 0) break;
//
//        int count = 0;
//        while (n > 1)
//        {
//            n = n / 3 + (n % 3 > 0);
//            ++count;
//        }
//        cout << count << endl;
//    }
//    return 0;
//}














/***********************************************正数数组的最小不可组成和（牛客）*******************************************/
/*
给定一个正数数组arr，其中所有的值都为整数，以下是最小不可组成和的概念
把arr每个子集内的所有元素加起来会出现很多值，其中最小的记为min，最大的记为max
在区间[min, max]上，如果有数不可以被arr某一个子集相加得到，那么其中最小的那个数是arr的最小不可组成和
在区间[min, max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max+1是arr的最小不可组成和
请写函数返回正数数组arr的最小不可组成和

输入描述：
第一行一个整数N，表示数组长度
接下来一行N个整数表示数组内的元素
输出描述：
输出一个整数表示数组的最小不可组成和
*/

/*
解题思路：（动态规划）
    
背包的空间      2   3   4   5   6   7   8   9   10
背包当前承重    0   0   0   0   0   0   0   0   0                
v[0]:3          0   3   3   3   3   3   3   3   3
v[1]:2          2   3   3   5   5   5   5   5   5
v[2]:5          2   3   3   5   5   7   8   8   10

if(背包当前承重 > 放入物品之后的承重)
    更新背包当前承重

放入物品后的承重 = 物品的重量 + 与背包剩余空间大小相等的背包的当前承重
*/

//#include <climits>
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        //获取max,min
//        vector<int> v(n);//物品
//        int min = INT_MAX, max = 0;
//        for (int i = 0; i < n; ++i) {
//            cin >> v[i];
//            if (v[i] < min) min = v[i];
//            max += v[i];
//        }
//
//        vector<int> dp(max + 1, 0);//背包当前承重
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = max; j >= v[i]; --j)//逆序更新，
//            {
//                if (dp[j] < v[i] + dp[j - v[i]]) {
//                    dp[j] = v[i] + dp[j - v[i]];
//                }
//            }
//        }
//
//        //背包空间与背包承重进行比对
//        int ret = INT_MIN;
//        for (int i = min; i <= max; ++i) {
//            if (dp[i] != i) {
//                ret = i;
//                break;
//            }
//        }
//        if (ret == INT_MIN) ret = max + 1;
//        cout << ret << endl;
//    }
//    return 0;
//}














/**************************************************** 因子个数(牛客)*******************************************************/
/*
一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，
现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数

注意：质因子！！！
*/

/*
解题思路：
质数：一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做质数
*/

//#include <iostream>
//#include <cmath>
//using namespace std;
//int main() {
//    int n = 0;
//    while (cin >> n)
//    {
//        int count = 0;
//        for (int i = 2; i < sqrt(n); i++)//质因子可能存在的范围
//        {
//            if (n % i == 0)
//            {
//                while (n % i == 0) n /= i;//不断除该质因子，若不能整除了，说明n不由该质因子组成了
//                ++count;
//            }
//        }
//        if (n != 1) ++count; //n没有被整除，n为质数（质因子）
//        cout << count << endl;
//    }
//}

















/***************************************************美国节日（牛客）*******************************************************/
/*
和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
* 1月1日：元旦
* 1月的第三个星期一：马丁·路德·金纪念日
* 2月的第三个星期一：总统节
* 5月的最后一个星期一：阵亡将士纪念日
* 7月4日：美国国庆
* 9月的第一个星期一：劳动节
* 11月的第四个星期四：感恩节
* 12月25日：圣诞节
现在给出一个年份，请你帮忙生成当年节日的日期

输入描述：
输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。
输出描述：
对应每一组数据，以“YYYY-MM-DD”格式输出当年所有的节日日期，每个日期占一行。

每组数据之后输出一个空行作为分隔。
*/

/*
函数 CalculateTheDayOfWeek() 实现思路：

以公元前1年12月31日为基准值，当天为星期7

(year,month,day) - (0000,12,31) = 一共过了多少个整年天数 + 今年过了多少天

"今年过了多少天"可以通过函数GetDaysNumber()进行计算

"一共过了多少个整年天数" = (year - 1) * 365 + 闰年出现的次数                  注：闰年比平年2月多1天
                         = (year - 1) * 365 + (year - 1)/4 - (year - 1)/100 + (year - 1)/400
                         
"今天是星期几" = ((year,month,day) - (0000,12,31)) % 7                    注：若计算结果为0，则代表可以被7整除，即为星期天
               = ((year - 1) * 365 + (year - 1)/4 - (year - 1)/100 + (year - 1)/400 + GetDaysNumber) % 7
365 = 364 + 1 = 52 * 7 + 1,所以可以将上式化简：
               = ((year - 1) + (year - 1)/4 - (year - 1)/100 + (year - 1)/400 + GetDaysNumber) % 7
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//const vector<int> days = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//
//inline bool IsLeapYear(int year) {
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//
//inline int GetDaysNumber(int year, int month, int day) //计算今年过了多少天
//{
//    int sumDays = 0;
//    for (int i = 0; i < month - 1; ++i) {
//        sumDays += days[i];
//    }
//    if (month > 2 && IsLeapYear(year)) ++sumDays;
//    return sumDays + day;
//}
//
//inline int CalculateTheDayOfWeek(int year, int month, int day) {//计算今天是星期几
//    int weak = ((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + GetDaysNumber(year, month, day)) % 7;
//    if (weak == 0) weak = 7;
//    return weak;
//}
//
////已知当月1日是星期w,计算当月第n个星期e是几号
//inline int GetResult(int w, int n, int e) {
//    return 1 + (n - 1) * 7 + (7 - w + e) % 7;
//}
//
////已知6月1号是星期w,计算五月的最后一个星期一是几号
//inline int GetSpecialRet(int w) {
//    return 32 - (w == 1 ? 7 : w - 1);
//}
//
//int main()
//{
//    int year = 0;
//    while (cin >> year)
//    {
//        printf("%d-01-01\n", year);
//
//        int w = CalculateTheDayOfWeek(year, 1, 1);
//        printf("%d-01-%02d\n", year, GetResult(w, 3, 1));
//
//        w = CalculateTheDayOfWeek(year, 2, 1);
//        printf("%d-02-%02d\n", year, GetResult(w, 3, 1));
//
//        w = CalculateTheDayOfWeek(year, 6, 1);
//        printf("%d-05-%02d\n", year, GetSpecialRet(w));
//
//        printf("%d-07-04\n", year);
//
//        w = CalculateTheDayOfWeek(year, 9, 1);
//        printf("%d-09-%02d\n", year, GetResult(w, 1, 1));
//
//        w = CalculateTheDayOfWeek(year, 11, 1);
//        printf("%d-11-%02d\n", year, GetResult(w, 4, 4));
//
//        printf("%d-12-25\n\n", year);
//    }
//    return 0;
//}


















/******************************************************* 抄送列表（牛客）**************************************************/
//#include <iostream>
//#include <unordered_set>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    string name;
//    while (getline(cin, str),getline(cin, name))
//    {
//        unordered_set<string> set;
//        size_t end = 0;
//        int i = 0;
//        while(i < str.size())
//        {
//            if ('\"' == str[i]) //名字包含在双引号中
//            {
//                end = str.find('\"', i + 1);
//                set.insert(str.substr(i + 1, end - i - 1));
//                i = end + 2;
//            }
//            else//该名字没有在引号中
//            {
//                end = str.find(',', i + 1);
//                if (end == string::npos) {
//                    set.insert(str.substr(i, str.size()));//截取末尾
//                    break;
//                }
//                set.insert(str.substr(i, end - i));
//                i = end + 1;
//            }
//        }
//
//        if (set.find(name) == set.end()) {
//            cout << "Important!" << endl;
//        }
//        else {
//            cout << "Ignore" << endl;
//        }
//    }
//    return 0;
//}

















/*************************************************** mkdir（牛客）*********************************************************/
/*
工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。
例如要创建目录“/usr/local/bin”，就需要此次创建“/usr”、“/usr/local”以及“/usr/local/bin”。
好在，Linux下mkdir提供了强大的“-p”选项，只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令

输入：
3
/a
/a/b
/a/b/c
3
/usr/local/bin
/usr/bin
/usr/local/share/bin
输出：
mkdir -p /a/b/c

mkdir -p /usr/bin
mkdir -p /usr/local/bin
mkdir -p /usr/local/share/bin
*/

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        vector<string> v(n);
//        for (auto& it : v) cin >> it;
//        sort(v.begin(), v.end());//按字典顺序排列
//
//        vector<bool> flag(n, true);//伪删除法，erase会导致vector中的数据不断移动，效率较低
//        for (int i = 0; i < n - 1; ++i)
//        {
//            if (v[i] == v[i + 1]) flag[i] = false;//相同目录删除
//            //子目录删除
//            else if (v[i].size() < v[i + 1].size() && v[i] == v[i + 1].substr(0, v[i].size()) &&
//                v[i + 1][v[i].size()] == '/')//避免出现/a和/ab的情况
//                flag[i] = false;
//        }
//
//        for (int i = 0; i < n; ++i) {
//            if (flag[i]) cout << "mkdir -p " << v[i] << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}















/****************************************************** 蘑菇阵（牛客）*****************************************************/
/*
现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1,1),B在(n,m)。
现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，
在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，
那么她不碰到蘑菇走到B的家的概率是多少？
输入描述：
第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有一个蘑菇。
输出描述：
输出一行，代表所求概率(保留到2位小数)

输入：
2 2 1
2 1
输出：
0.50
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    int n = 0, m = 0, k = 0;
//    while (cin >> n >> m >> k)
//    {
//        int x = 0, y = 0;
//        vector<vector<double>> map(n, vector<double>(m, 0));
//        for (int i = 0; i < k; ++i) {//设置蘑菇
//            cin >> x >> y;
//            map[x - 1][y - 1] = -1;
//        }
//
//        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
//        dp[1][1] = 1;
//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 1; j <= m; ++j)
//            {
//                if (i == 1 && j == 1) continue;
//                if (map[i - 1][j - 1] == -1) {//该位置为蘑菇
//                    dp[i][j] = 0;
//                    continue;
//                }
//                // if (i == n && j == m) //左边的位置只能往右走，上面的位置只能往下走
//                //     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                // else if (i == n) //左边的位置只能往右走
//                //     dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1];
//                // else if (j == m) //上面的位置只能往下走
//                //     dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5;
//                // else if (i == 1) //只有左边有位置
//                //     dp[i][j] = dp[i][j - 1] * 0.5;
//                // else if (j == 1) //只有上面有位置
//                //     dp[i][j] = dp[i - 1][j] * 0.5;
//                // else //上下都有位置，且概率相同
//                //     dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1] * 0.5;
//                dp[i][j] = dp[i - 1][j] * (j == m ? 1 : 0.5) + dp[i][j - 1] * (i == n ? 1 : 0.5);//等价上面的代码
//            }
//        }
//        printf("%.2lf\n", dp[n][m]);
//    }
//    return 0;
//}














/**************************************************最长公共子序列(一)（牛客）*************************************************/
/*
给定两个字符串 s1 和 s2，长度为 n 和 m  。求两个字符串最长公共子序列的长度。
所谓子序列，指一个字符串删掉部分字符（也可以不删）形成的字符串。
例如：字符串 "arcaea" 的子序列有 "ara" 、 "rcaa" 等。但 "car" 、 "aaae" 则不是它的子序列。
所谓 s1 和 s2 的最长公共子序列，即一个最长的字符串，它既是 s1 的子序列，也是 s2 的子序列

输入描述：
第一行输入一个整数 n 和 m ，表示字符串 s1 和 s2 的长度
接下来第二行和第三行分别输入一个字符串 s1 和 s2
输出描述：
输出两个字符串的最长公共子序列的长度
*/

//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//using namespace std;
//int main()
//{
//    int n = 0, m = 0;
//    string str1, str2;
//    while (cin >> n >> m >> str1 >> str2)
//    {
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j)
//            {
//                if (str1[i - 1] == str2[j - 1])
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                else
//                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//            }
//        }
//        cout << dp[n][m] << endl;
//    }
//    return 0;
//}













/***************************************************** 最长上升子序列（牛客）***********************************************/
/*
广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你帮忙找出身高依次递增的子序列。 
例如队伍的身高数据是（1、7、3、5、9、4、8），其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，
其中最长的长度为4

输入：
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）
紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高
输出：
对应每一组数据，输出最长递增子序列的长度
*/

/*
输入：
7
1 7 3 5 9 4 8
6
1 3 5 2 4 6
输出：
4
4

定义状态:F(i) 以nums[i]元素为结尾的序列 的最长递增子序列的长度
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        vector<int> nums(n);
//        for (auto& it : nums) cin >> it;
//
//        vector<int> dp(n, 1);
//        for (int i = 1; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);//找到比自己小的，并且递增子序列长度最长的
//            }
//        }
//
//        int max = 0;
//        for (auto it : dp) {
//            if (it > max) max = it;
//        }
//        cout << max << endl;
//    }
//    return 0;
//}















/******************************************************** 发邮件（牛客）****************************************************/
/*
NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B的邮件发给了A。
于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是所有人都收到了错误的邮件？
即没有人收到属于自己的邮件
*/

/*
解题思路：错排问题

当n个编号元素放在n个编号位置，元素编号与位置编号各不对应的方法数用D(n)表示，
那么D(n-1)就表示n-1个编号元素放在n-1个编号位置，各不对应的方法数，其它类推

将n个元素中的一个元素放在一个位置，若让其错放，一共有n-1种方法

放编号为A的元素，有两种情况：
⑴放到位置b，B元素放在位置a，剩下n-2个元素就有D(n-2)种方法
⑵放到位置b, B元素放在任意位置，即剩下n - 1个元素，有D(n - 1)中方法

即D(n) = (n - 1) * (D(n - 1) + D(n - 2))
D(1) = 0, D(2) = 1
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    vector<long long> dp(21, 0);
//    dp[2] = 1;
//    for (int i = 3; i < 21; ++i) {
//        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
//    }
//
//    int n = 0;
//    while (cin >> n) {
//        cout << dp[n] << endl;
//    }
//    return 0;
//}













/********************************************************** 求和（牛客）*****************************************************/
/*
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出

输入描述:
每个测试输入包含2个整数,n和m
输出描述:
按每个组合的字典序排列输出,每行输出一种组合

输入：
5 5
输出：
1 4
2 3
5
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//void GetSum(vector<int>& v, int pos, int currentSum, int n, int m)
//{
//    if (currentSum >= m)
//    {
//        if (currentSum == m)//当前累加和等于基准值
//        {
//            for (int i = 0; i < v.size() - 1; ++i) {
//                cout << v[i] << " ";
//            }
//            cout << v[v.size() - 1] << endl;
//        }
//        return;
//    }
//    //累加的起始位置pos
//    for (int i = pos; i <= n; ++i)
//    {
//        //保存当前数据
//        v.push_back(i);
//        //保证组合内部递增
//        GetSum(v, i + 1, currentSum + i, n, m);
//        //尝试累加其他值，删除当前元素
//        v.pop_back();
//    }
//}
//
//int main()
//{
//    int n = 0, m = 0;
//    while (cin >> n >> m)
//    {
//        vector<int> v;
//        GetSum(v, 1, 0, n, m);
//    }
//    return 0;
//}













/****************************************************** 合唱团（牛客）******************************************************/
/*
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？

每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，
包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        vector<int> ability(n);
//        for (auto& it : ability) cin >> it;
//        int k = 0, d = 0;
//        cin >> k >> d;
//
//        //状态F(i, j) = 当最后一个学生为i 且 共选了j个学生时,所得到的最大乘积
//        vector<vector<long long>> maxValue(n + 1, vector<long long>(k + 1, 0));
//        vector<vector<long long>> minValue(n + 1, vector<long long>(k + 1, 0));
//        //初始化
//        for (int i = 1; i <= n; ++i) {
//            maxValue[i][1] = minValue[i][1] = ability[i - 1];
//        }
//
//        long long ret = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 1; j <= k; ++j)//i,j两层循环，遍历所有情况
//            {
//                //选择相邻学生的范围[i - d, i - 1]
//                for (int m = i - 1; m >= max(i - d, 1); --m) {
//                    maxValue[i][j] = \
//                        max(maxValue[i][j], max(maxValue[m][j - 1] * ability[i - 1], minValue[m][j - 1] * ability[i - 1]));
//                    minValue[i][j] = \
//                        min(minValue[i][j], min(minValue[m][j - 1] * ability[i - 1], maxValue[m][j - 1] * ability[i - 1]));
//                }
//            }
//            ret = max(ret, maxValue[i][k]);
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}















/********************************************************* 马戏团（牛客）******************************************************/
/*
搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，
小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，
站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长想要本次节目中的罗汉塔叠的最高，
由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，
并且很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，
这份表中马戏团员依次编号为1到N

输入描述：
首先一个正整数N，表示人员个数。 之后N行，每行三个数，分别对应马戏团员编号，体重和身高
输出描述：
正整数m，表示罗汉塔的高度
*/

/*
题目设计不合理：
体重相同时，身高必须相等
体重不同时，需体重小，身高低或相同
才能往上叠
*/
//#include <iostream>
//#include <vector>
//#include <utility>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        int number = 0;
//        vector<pair<int, int>> flag(n);//体重、身高
//        for (int i = 0; i < n; ++i) {
//            cin >> number >> flag[i].first >> flag[i].second;
//        }
//
//        sort(flag.begin(), flag.end(), [](const pair<int, int>& d1, const pair<int, int>& d2) {
//            if (d1.first < d2.first) return true;
//            else if (d1.first == d2.first) {//体重相同时，按身高降序排序，排除体重相同、身高矮的情况
//                if (d1.second > d2.second) return true;
//                else return false;
//            }
//            else return false;
//            });
//
//        //求身高的最长升序子序列
//        vector<int> dp(n, 1);
//        int maxHeight = 1;
//        for (int i = 1; i < n; ++i)
//        {
//            for (int j = i - 1; j >= 0; --j)
//            {
//                if (flag[i].second >= flag[j].second) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//            maxHeight = max(maxHeight, dp[i]);
//        }
//        cout << maxHeight << endl;
//    }
//    return 0;
//}














/**************************************************** 最后一块石头的重量（LeetCode）*************************************************/
/*
有一堆石头，每块石头的重量都是正整数
每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//class Solution {
//public:
//    int lastStoneWeight(vector<int>& stones)
//    {
//        priority_queue<int> qe;
//        for (auto& it : stones) qe.push(it);
//
//        while (qe.size() > 1)
//        {
//            int x = qe.top();
//            qe.pop();
//            int y = qe.top();
//            qe.pop();
//            if (x > y) qe.push(x - y);//因为使用的是大堆,不可能出现x < y的情况;若x == y,不处理则相当于丢弃
//        }
//        return qe.empty() ? 0 : qe.top();
//    }
//};











/**************************************************** 有效的数独（LeetCode）*******************************************/
/*
请你判断一个9 x 9的数独是否有效。只需要根据以下规则 ，验证已经填入的数字是否有效即可
数字 1-9 在每一行只能出现一次
数字 1-9 在每一列只能出现一次
数字 1-9 在每一个以粗实线分隔的3x3宫内只能出现一次
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool checkRow[9][9];//数字i - 1在j行是否出现过 
//    bool checkCol[9][9];//数字i - 1在j列是否出现过
//    bool checkArea[3][3][9];//i行j列的区域是否出现过数字k - 1
//
//    bool isValidSudoku(vector<vector<char>>& board)
//    {
//        for (int i = 0; i < 9; ++i)
//        {
//            for (int j = 0; j < 9; ++j)
//            {
//                if (board[i][j] != '.') {
//                    int num = board[i][j] - '0';
//                    if (checkRow[num - 1][i] || checkCol[num - 1][j] || checkArea[i / 3][j / 3][num - 1]) return false;
//                    checkRow[num - 1][i] = checkCol[num - 1][j] = checkArea[i / 3][j / 3][num - 1] = true;
//                }
//            }
//        }
//        return true;
//    }
//};










/******************************************** 最长连续序列（LeetCode）**************************************************/
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度
请你设计并实现时间复杂度为 O(n) 的算法解决此问题
*/
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums)
//    {
//        unordered_set<int> hash;//去重、加快查找速度
//        for (int& it : nums) hash.insert(it);
//
//        int retLength = 0;
//        for (const int& it : hash)
//        {
//            if (!hash.count(it - 1))//不存在刚好比其小1的数,则将其作为头元素
//            {
//                int currentNum = it;
//                int length = 1;
//                while (hash.count(currentNum + 1)) {
//                    ++currentNum;
//                    ++length;
//                }
//                retLength = max(retLength, length);
//            }
//        }
//        return retLength;
//    }
//};










/*********************************************** 缺失的第一个正数（LeetCode）********************************************/
/*
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案
*/
//#include <iostream>
//#include <vector>
//using namespace std;
////原地哈希(负数标记)
// class Solution1 {
// public:
//     int firstMissingPositive(vector<int>& nums) 
//     {
//         int size = nums.size();
//         //将所有负数修改为size + 1
//         for(int& it : nums) 
//             if(it <= 0) 
//                 it = size + 1;
//         for(int i = 0; i < size; ++i)
//         {
//             int number = abs(nums[i]);
//             if(number <= size) //若该元素没有缺失，则将其 应该放置的位置 的前面一个元素转为负数
//                 nums[number - 1] = -abs(nums[number - 1]);
//         }
//         for(int i = 0; i < size; ++i) 
//             if(nums[i] > 0) return i + 1;//若某个位置的元素为正数, 说明后一个位置 应该放置的元素 缺失
//         return size + 1;
//     }
// };
////置换
//class Solution2 {
//public:
//    int firstMissingPositive(vector<int>& nums)
//    {
//        int size = nums.size();
//        for (int i = 0; i < size; ++i) {
//            //在完成交换后,新的nums[i]可能还在[1, N]的范围内,需要继续进行交换操作
//            while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
//                swap(nums[nums[i] - 1], nums[i]);
//        }
//        for (int i = 0; i < size; ++i)
//            if (nums[i] != i + 1)
//                return i + 1;
//        return size + 1;
//    }
//};










/*************************************************** 矩阵置零（LeetCode）**********************************************/
/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用原地算法
*/
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix)
//    {
//        int sizeRow = matrix.size();
//        int sizeCol = matrix[0].size();
//        unordered_set<int> hashRow;//row
//        unordered_set<int> hashCol;//col
//
//        for (int i = 0; i < sizeRow; ++i)
//            for (int j = 0; j < sizeCol; ++j)
//                if (matrix[i][j] == 0) hashRow.insert(i), hashCol.insert(j);
//
//        for (const int& it : hashRow) {
//            for (int j = 0; j < sizeCol; ++j)
//                matrix[it][j] = 0;
//        }
//        for (const int& it : hashCol) {
//            for (int i = 0; i < sizeRow; ++i)
//                matrix[i][it] = 0;
//        }
//    }
//};










/*********************************************** 螺旋矩阵（LeetCode）**************************************************/
/*
给你一个m行n列的矩阵matrix，请按照顺时针螺旋顺序，返回矩阵中的所有元素
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<bool>> visited;//辅助数组, 记录每个元素是否被访问过
//    const int direction[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
//    vector<int> spiralOrder(vector<vector<int>>& matrix)
//    {
//        if (matrix.size() == 0 || matrix[0].size() == 0) return{};
//
//        int row = matrix.size(), col = matrix[0].size();
//        visited = vector<vector<bool>>(row, vector<bool>(col, false));
//
//        int total = row * col;
//        vector<int> ret(total);//记录走过的元素,即结果
//        int directionIndex = 0;//移动方向数组的下标, 从此得知下次移动的移动方向
//        int currentRow = 0, currentCol = 0;//当前处在的行和列
//        for (int i = 0; i < total; ++i)
//        {
//            ret[i] = matrix[currentRow][currentCol];
//            visited[currentRow][currentCol] = true;
//            int nextRow = currentRow + direction[directionIndex][0];
//            int nextCol = currentCol + direction[directionIndex][1];
//            //超出范围或已经访问过
//            if (nextRow < 0 || nextRow >= row || nextCol < 0 || nextCol >= col || visited[nextRow][nextCol])
//                directionIndex = (directionIndex + 1) % 4;//修改移动方向
//            currentRow += direction[directionIndex][0];
//            currentCol += direction[directionIndex][1];
//        }
//        return ret;
//    }
//};











/*********************************************** 翻转二叉树（LeetCode）***************************************************/
/*
给你一棵二叉树的根节点root ，翻转这棵二叉树，并返回其根节点
*/
//#include <iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//}; 
//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root)
//    {
//        if (root == nullptr) return nullptr;
//
//        TreeNode* leftChild = invertTree(root->left);
//        TreeNode* rightChild = invertTree(root->right);
//        root->left = rightChild;
//        root->right = leftChild;
//
//        return root;
//    }
//};








/********************************************** 二叉树的直径（LeetCode）**************************************************/
/*
给你一棵二叉树的根节点，返回该树的直径
二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点root
两节点之间路径的 长度 由它们之间边数表示
*/
//#include <iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    int result = 1;
//    int diameterOfBinaryTree(TreeNode* root) {
//        depth(root);
//        return result - 1;
//    }
//private:
//    int depth(TreeNode* root)
//    {
//        if (root == nullptr) return 0;
//        int leftDepth = depth(root->left);//以左孩子为根结点的子树的深度
//        int rightDepth = depth(root->right);//以右孩子为根结点的子树的深度
//        result = max(result, leftDepth + rightDepth + 1);
//        return max(leftDepth, rightDepth) + 1;
//    }
//};










/************************************************* 排序链表（LeetCode）************************************************/
/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表
*/
//归并排序
//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* sortList(ListNode* head) {
//        return sortList(head, nullptr);
//    }
//    ListNode* sortList(ListNode* head, ListNode* tail)
//    {
//        if (head == nullptr) return head;
//        if (head->next == tail) {
//            head->next = nullptr;
//            return head;
//        }
//        ListNode* fast = head, * slow = head;
//        while (fast != tail)
//        {
//            fast = fast->next;
//            slow = slow->next;
//            if (fast != tail) fast = fast->next;
//        }
//        ListNode* mid = slow;
//        return merge(sortList(head, mid), sortList(mid, tail));
//    }
//    ListNode* merge(ListNode* head1, ListNode* head2)
//    {
//        ListNode* tempHead = new ListNode(-1);
//        ListNode* tmp = tempHead, * tmp1 = head1, * tmp2 = head2;
//        while (tmp1 != nullptr && tmp2 != nullptr)
//        {
//            if (tmp1->val <= tmp2->val) {
//                tmp->next = tmp1;
//                tmp1 = tmp1->next;
//            }
//            else {
//                tmp->next = tmp2;
//                tmp2 = tmp2->next;
//            }
//            tmp = tmp->next;
//        }
//        if (tmp1 != nullptr) tmp->next = tmp1;
//        else if (tmp2 != nullptr) tmp->next = tmp2;
//
//        ListNode* ret = tempHead->next;
//        delete tempHead;
//        return ret;
//    }
//};
//int main()
//{
//    //4, 2, 1, 3
//    ListNode* node1 = new ListNode(4);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(1);
//    ListNode* node4 = new ListNode(3);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    Solution s;
//    ListNode* ret = s.sortList(node1);
//    for (ListNode* current = ret; current != nullptr; current = current->next)
//        cout << current->val << " ";
//    return 0;
//}










/******************************************* 对链表进行插入排序（LeetCode）********************************************/
/*
给定单个链表的头head ，使用插入排序对链表进行排序，并返回排序后链表的头
插入排序 算法的步骤:
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入
重复直到所有输入数据插入完为止
下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素
每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中
对链表进行插入排
*/
//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* insertionSortList(ListNode* head)
//    {
//        if (head == nullptr) return head;
//
//        ListNode* newHead = new ListNode(0);
//        newHead->next = head;//默认直接将第一个结点插入
//
//        ListNode* lastSorted = head;//维护链表已排序的最后一个结点
//        ListNode* current = head->next;//维护待插入的结点
//        while (current != nullptr)
//        {
//            if (lastSorted->val <= current->val) {
//                lastSorted = lastSorted->next;
//            }
//            else {
//                ListNode* prev = newHead;//prev维护current插入位置的前一个结点
//                从前向后遍历, 寻找current插入位置的前一个结点
//                while (prev->next->val <= current->val) {
//                    prev = prev->next;
//                }
//                lastSorted->next = current->next;//更新lastSorted
//                插入current
//                current->next = prev->next;
//                prev->next = current;
//            }
//            current = lastSorted->next;
//        }
//        current = newHead->next;
//        delete newHead;
//        return current;
//    }
//};









/**************************************** 搜索二维矩阵II（LeetCode）*******************************************/
/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列
每列的元素从上到下升序排列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target)
//    {
//        int row = matrix.size(), col = matrix[0].size();
//        int curRow = 0, curCol = col - 1;
//        while (curRow < row && curCol >= 0)
//        {
//            if (matrix[curRow][curCol] > target) --curCol;
//            else if (matrix[curRow][curCol] < target) ++curRow;
//            else return true;
//        }
//        return false;
//    }
//};








/******************************************* 搜索二维矩阵（LeetCode）***********************************************/
/*
给你一个满足下述两条属性的 m x n 整数矩阵：
每行中的整数从左到右按非严格递增顺序排列
每行的第一个整数大于前一行的最后一个整数
给你一个整数 target ，如果 target 在矩阵中，返回true ；否则，返回false
*/
//#include <iostream>
//#include <vector>
//using namespace std;
////线性查找
//class Solution1 {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) 
//    {
//        int row = matrix.size(), col = matrix[0].size();
//        int corRow = 0;
//        for(int i = 0; i < row; ++i) 
//        {
//            if(matrix[i][0] > target) {
//                corRow = i - 1;
//                break;
//            } 
//            else if(matrix[i][0] == target) return true;
//            else corRow = i;
//        }
//        if(corRow >= 0)
//        {
//            for(int j = 0; j < col; ++j)
//                if(matrix[corRow][j] == target) 
//                    return true;
//            return false;
//        }
//        else return false;
//    }
//};
////两次二分查找
//class Solution2 {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target)
//    {
//        int left = 0, right = matrix.size();
//        //找到一个大于target的数
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (matrix[mid][0] > target) right = mid;
//            else if (matrix[mid][0] < target) left = mid + 1;
//            else return true;
//        }
//        int corRow = max(0, right - 1);
//        left = 0, right = matrix[corRow].size();
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (matrix[corRow][mid] > target) right = mid;
//            else if (matrix[corRow][mid] < target) left = mid + 1;
//            else return true;
//        }
//        return matrix[corRow][max(0, right - 1)] == target;
//    }
//};








/******************************************* 搜索旋转排序数组（LeetCode）*******************************************/
/*
整数数组 nums 按升序排列，数组中的值互不相同
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2]
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int search(vector<int>& nums, int target)
//    {
//        int size = nums.size();
//        if (size == 0) return -1;
//        if (size == 1) return nums[0] == target ? 0 : -1;
//
//        int left = 0, right = size - 1;
//        while (left <= right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] == target) return mid;
//            //nums[mid]在第一个区间[k, n - 1]
//            if (nums[0] <= nums[mid])
//            {
//                if (nums[0] <= target && target < nums[mid]) right = mid - 1;
//                else left = mid + 1;
//            }
//            //nums[mid]在第二个区间[0, k - 1]
//            else
//            {
//                if (nums[mid] < target && target <= nums[size - 1]) {
//                    left = mid + 1;
//                }
//                else {
//                    right = mid - 1;
//                }
//            }
//        }
//        return -1;
//    }
//};








/****************************************** 寻找重复数（LeetCode）*********************************************/
/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数
假设 nums 只有 一个重复的整数 ，返回 这个重复的数
你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findDuplicate(vector<int>& nums)
//    {
//        int size = nums.size();
//        int left = 0, right = size - 1, ret = -1;
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            int count = 0;//nums中小于等于mid的元素个数
//            for (int i = 0; i < size; ++i)
//                if (nums[i] <= mid) ++count;
//            if (count <= mid) left = mid + 1;
//            else right = mid; //count > mid
//        }
//        return right;
//    }
//};








/****************************************** 划分字母区间（LeetCode）*******************************************/
/*
给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中
注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s
返回一个表示每个字符串片段的长度的列表
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    vector<int> partitionLabels(string s)
//    {
//        vector<int> ret;
//        int size = s.size();
//        int start = 0, end = -1;
//        while (start < size)
//        {
//            end = s.find_last_of(s[start]);
//            int current = start;
//            while (current < end)
//                end = max(end, (int)s.find_last_of(s[current++]));
//            ret.push_back(end - start + 1);
//            start = end + 1;
//        }
//        return ret;
//    }
//};










/********************************************** 每日温度（LeetCode）*******************************************/
/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替
*/
//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures)
//    {
//        int size = temperatures.size();
//        vector<int> ret(size);
//        stack<int> sk;//单调栈
//        for (int i = 0; i < size; ++i)
//        {
//            while (!sk.empty() && temperatures[i] > temperatures[sk.top()])
//            {
//                int prevIndex = sk.top();
//                sk.pop();
//                ret[prevIndex] = i - prevIndex;
//            }
//            sk.push(i);
//        }
//        return ret;
//    }
//};










/******************************************* 前K个高频元素（LeetCode）*****************************************/
/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    static bool Compare(const pair<int, int>& p1, const pair<int, int>& p2) {
//        return p1.second > p2.second;
//    }
//    vector<int> topKFrequent(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;//num : count
//        for (int i = 0; i < nums.size(); ++i)
//            ++hash[nums[i]];
//        //建小堆
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&Compare)> qe(Compare);
//        int count = 0;
//        for (auto& it : hash)
//        {
//            pair<int, int> tmp = { it.first, it.second };
//            if (count < k) qe.push(tmp);
//            else {
//                qe.push(it);
//                qe.pop();
//            }
//            ++count;
//        }
//
//        vector<int> ret;
//        while (!qe.empty())
//        {
//            pair<int, int> top = qe.top();
//            qe.pop();
//            ret.push_back(top.first);
//        }
//        return ret;
//    }
//};










/********************************************* LRU 缓存（LeetCode）********************************************/
/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value
如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity
则应该 逐出 最久未使用的关键字
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行
*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//struct LinkNode
//{
//    int key = 0, value = 0;
//    LinkNode* prev;
//    LinkNode* next;
//    LinkNode() {}
//    LinkNode(int _key, int _value) :
//        key(_key), value(_value), prev(nullptr), next(nullptr) {}
//};
//class LRUCache {
//public:
//    LRUCache(int _capacity) :capacity(_capacity), size(0)
//    {
//        //伪头结点,伪尾结点
//        head = new LinkNode();
//        tail = new LinkNode();
//        head->next = tail;
//        tail->prev = head;
//    }
//
//    int get(int key)
//    {
//        if (!hash.count(key)) return -1;
//        LinkNode* node = hash[key];
//        moveToHead(node);//该结点移到链表头部
//        return node->value;
//    }
//
//    void put(int key, int value)
//    {
//        if (!hash.count(key))
//        {
//            LinkNode* node = new LinkNode(key, value);
//            hash[key] = node;
//            addToHead(node);//将该结点加入链表头部
//            ++size;
//            if (size > capacity)
//            {
//                LinkNode* del = delTail();
//                hash.erase(del->key);
//                delete del;
//                --size;
//            }
//        }
//        else
//        {
//            LinkNode* node = hash[key];
//            node->value = value;
//            moveToHead(node);//该结点移到链表头部
//        }
//    }
//private:
//    void addToHead(LinkNode* node)
//    {
//        node->prev = head;
//        node->next = head->next;
//        head->next->prev = node;
//        head->next = node;
//    }
//    void removeNode(LinkNode* node)//将该结点移出链表
//    {
//        node->prev->next = node->next;
//        node->next->prev = node->prev;
//    }
//    void moveToHead(LinkNode* node)
//    {
//        removeNode(node);
//        addToHead(node);
//    }
//    LinkNode* delTail()
//    {
//        LinkNode* node = tail->prev;
//        removeNode(node);
//        return node;
//    }
//private:
//    unordered_map<int, LinkNode*> hash;
//    LinkNode* head;
//    LinkNode* tail;
//    int size;
//    int capacity;
//};
///**
// * Your LRUCache object will be instantiated and called as such:
// * LRUCache* obj = new LRUCache(capacity);
// * int param_1 = obj->get(key);
// * obj->put(key,value);
// */










/***************************************** 滑动窗口最大值（LeetCode）******************************************/
/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
返回 滑动窗口中的最大值
*/
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
////堆
//class Solution1 
//{
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k)
//    {
//        priority_queue<pair<int, int>> qe;//nums[i] : i
//        for (int i = 0; i < k; ++i) qe.push({ nums[i], i });
//        vector<int> ret;
//        ret.push_back(qe.top().first);
//        for (int i = k; i < nums.size(); ++i)
//        {
//            qe.push({ nums[i], i });
//            while (qe.top().second <= i - k) qe.pop();
//            ret.push_back(qe.top().first);
//        }
//        return ret;
//    }
//};
////单调队列
///*
//若当前的滑动窗口中有两个下标i和j，其中i在j的左侧(i<j),并且i对应的元素不大于j对应的元素(nums[i] <= nums[j])
//由于nums[j]的存在,nums[i]一定不会是滑动窗口中的最大值了,可以将nums[i]永久地移除
//*/
//class Solution2
//{
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//        deque<int> qe;//双端队列
//        for (int i = 0; i < k; ++i) {
//            while (!qe.empty() && nums[i] >= nums[qe.back()]) qe.pop_back();
//            qe.push_back(i);
//        }
//        vector<int> ret;
//        ret.push_back(nums[qe.front()]);
//        for (int i = k; i < size; ++i)
//        {
//            while (!qe.empty() && nums[i] >= nums[qe.back()]) qe.pop_back();
//            qe.push_back(i);
//            while (qe.front() <= i - k) qe.pop_front();
//            ret.push_back(nums[qe.front()]);
//        }
//        return ret;
//    }
//};










/***************************************** 实现 Trie (前缀树)（LeetCode）**************************************/
/*
前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键
这一数据结构有相当多的应用情景，例如自动补完和拼写检查

请你实现 Trie 类：
Trie() 初始化前缀树对象
void insert(String word) 向前缀树中插入字符串 word
boolean search(String word)如果字符串word在前缀树中，返回true（即在检索之前已经插入）；否则，返回false
boolean startsWith(String prefix)如果之前已经插入的字符串word的前缀之一为 prefix ，返回true ；否则，返回false
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Trie
//{
//public:
//    Trie() :_children(26), isEnd(false) {}
//    void insert(string word)
//    {
//        Trie* current = this;
//        for (int i = 0; i < word.size(); ++i)
//        {
//            int index = word[i] - 'a';//获得下标
//            if (current->_children[index] == nullptr)
//                current->_children[index] = new Trie();
//            current = current->_children[index];
//        }
//        current->isEnd = true;
//    }
//
//    bool search(string word)
//    {
//        Trie* node = searchPrefix(word);
//        return node != nullptr && node->isEnd;
//    }
//
//    bool startsWith(string prefix) {
//        return searchPrefix(prefix) != nullptr;
//    }
//private:
//    Trie* searchPrefix(string prefix)
//    {
//        Trie* current = this;
//        for (int i = 0; i < prefix.size(); ++i)
//        {
//            int index = prefix[i] - 'a';
//            if (current->_children[index] == nullptr)
//                return nullptr;
//            current = current->_children[index];
//        }
//        return current;
//    }
//private:
//    vector<Trie*> _children;
//    bool isEnd;//是否为字符串的结尾
//};
///**
// * Your Trie object will be instantiated and called as such:
// * Trie* obj = new Trie();
// * obj->insert(word);
// * bool param_2 = obj->search(word);
// * bool param_3 = obj->startsWith(prefix);
// */










/************************************* 两数之和II - 输入有序数组（LeetCode）***********************************/
/*
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列，
请你从数组中找出满足相加之和等于目标数 target 的两个数
如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length
以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2
你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素
你所设计的解决方案必须只使用常量级的额外空间
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target)
//    {
//        int size = numbers.size();
//        for (int i = 0; i < size - 1; ++i)//固定左数
//        {
//            int left = i + 1, right = size - 1;
//            while (left <= right)//二分找右数
//            {
//                int mid = left + ((right - left) >> 1);
//                int tmpSum = numbers[mid] + numbers[i];
//                if (tmpSum == target) return { i + 1, mid + 1 };
//                else if (tmpSum < target) left = mid + 1;
//                else right = mid - 1;
//            }
//        }
//        return { -1, -1 };
//    }
//};









/**************************************** 有效的字母异位词（LeetCode）*****************************************/
/*
给定两个字符串s和t ，编写一个函数来判断t是否是s的字母异位词
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词
*/
//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    bool isAnagram(string s, string t)
//    {
//        if (s.size() != t.size()) return false;
//        unordered_map<char, int> hash;
//        for (int i = 0; i < s.size(); ++i) {
//            ++hash[s[i]];
//            --hash[t[i]];
//        }
//        for (auto& it : hash)
//            if (it.second != 0) return false;
//        return true;
//    }
//};