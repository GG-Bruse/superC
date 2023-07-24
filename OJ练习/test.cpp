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