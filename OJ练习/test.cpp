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
























