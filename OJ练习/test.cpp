/******************************************************手套（牛客）*******************************************************************/
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
