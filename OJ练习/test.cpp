/******************************************************���ף�ţ�ͣ�*******************************************************************/
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














/****************************************************��������������������1�ĸ�����ţ�ͣ�***************************************************/
/*
����һ�����������������ڶ������µ�1�ĸ���
*/

//#include <iostream>
//using namespace std;
//size_t Count(size_t num)//��������
//{
//    size_t count = 0;
//    while (num)
//    {
//        if (num % 2 == 1) ++count;
//        num /= 2;
//    }
//    return count;
//}
//size_t Count(size_t num)//λ����
//{
//    size_t count = 0;
//    while (num)
//    {
//        if (num & 0x01 == 1) ++count;
//        num >>= 1;
//    }
//    return count;
//}
//size_t Count(size_t num)//λ�����Ż�
//{
//    size_t count = 0;
//    while (num)
//    {
//        num = num & (num - 1);//ʱ�临�ӶȽ����������1�ĸ����й�
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
//#include <bitset>//λͼ
//using namespace std;
//int main() {
//    int n = 0;
//    while (cin >> n) {
//        bitset<32> bs(n);
//        cout << bs.count() << endl;
//    }
//    return 0;
//}













/**********************************************************�˿��ƴ�С(ţ��)************************************************************/
/*
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮����"-"���ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���"-"����û�пո��磺4 4 4 4-joker JOKER��
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR��
��������
��1������ÿ���ƿ����Ǹ��ӡ����ӡ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣����������������
    �����뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ
    ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ���
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӡ����ӡ������Ƚ������С��˳�ӱȽ���С�ƴ�С��
    ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������
*/

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//string GetMAX(const string& str)
//{
//    //����ը�Ͳ���Ҫ�������������ˣ�������ը���
//    if (str.find("joker JOKER") != string::npos) return "joker JOKER";
//    if (str.find("JOKER joker") != string::npos) return "JOKER joker";
//
//    //���ַ����з�Ϊ����
//    int index = str.find("-");
//    string left = str.substr(0, index);
//    string right = str.substr(index + 1);
//
//    //�ֱ���������Ƶ�����
//    int left_num = count(left.begin(), left.end(), ' ') + 1;
//    int right_num = count(right.begin(), right.end(), ' ') + 1;
//
//    //�ֱ�ȡ�����ֵĵ�һ�ţ�˳�������򣬶��ӡ����š����š�ը��������������ը�Ѵ���
//    string left_first = left.substr(0, left.find(' '));
//    string right_first = right.substr(0, right.find(' '));
//
//
//    if (left_num == right_num) {//������������ͬ
//        string map = "345678910JQKA2jokerJOKER";
//        if (map.find(left_first) > map.find(right_first)) return left;
//        else return right;
//    }
//    //���������Ͳ�ͬ
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
















/********************************************************������ǵı��Σ�ţ�ͣ�************************************************************/
/*
��һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����
���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1��
��������3, �����2������4�����3������2����� - 1
                            1
                        1       1
                    1   2   3   2   1
                1   3   6   7   6   3   1
            1   4   10  16  19  16  10  4   1
*/
/*
����˼·��
������д���м����ҳ�����
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















/********************************************************ͳ��ÿ�������ӵ�������ţ�ͣ�***********************************************************/
/*
��һ�����ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӡ�
���ӣ�����һֻ���ӵ�3���³�������ô����5���¿�ʼ��ÿ������һֻ���ӡ�
һ�µ�ʱ����һֻ���ӣ��������Ӷ��������ʵ�n���µ���������Ϊ���٣�
���ݷ�Χ����������1��n��31
*/
//����˼·���ҹ��ɱ����Ͼ���쳲��������У��ݹ鷨������������̬�滮�����Խ������

//#include <iostream>
//#include <vector>
//using namespace std;
//int GetRabbitNum(int num)//��̬�滮
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
//int GetRabbitNum(int num)//������
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















/***********************************************���������ַ���a,b�е�������Ӵ���ţ�ͣ�***********************************************/
/*
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
ע���Ӵ��Ķ��壺��һ���ַ���ɾȥǰ׺�ͺ�׺��Ҳ���Բ�ɾ���γɵ��ַ�������͡������С��ĸ���ֿ���
���ݷ�Χ���ַ�������1��length��300
*/
/*
����˼·��
ʹ�ö�̬�滮�㷨
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


















/*********************************************************** MP3����λ�ã�ţ�ͣ�**********************************************************/
/*
MP3 Player��Ϊ��Ļ��С����ʾ�����б��ʱ��ÿ��ֻ����ʾ���׸������û�Ҫͨ�����¼�����������еĸ�����
Ϊ�˼򻯴�������ÿ��ֻ����ʾ4�׸���������ʼ��λ��Ϊ��1�׸衣����Ҫʵ��ͨ�����¼����ƹ���ƶ�����������б������߼����£�

1. ��������<=4��ʱ�򣬲���Ҫ��ҳ��ֻ��Ų�����λ�á�
����ڵ�һ�׸�����ʱ����Up�����Ų�����һ�׸�������������һ�׸���ʱ����Down�����Ų����һ�׸�����

2. ������������4��ʱ����һ����10�׸�Ϊ������
���ⷭҳ����Ļ��ʾ���ǵ�һҳ������ʾ��1 �C 4�ף�ʱ������ڵ�һ�׸����ϣ��û���Up������ĻҪ��ʾ���һҳ������ʾ��7-10�׸裩��
ͬʱ���ŵ����һ�׸��ϡ�ͬ���ģ���Ļ��ʾ���һҳʱ����������һ�׸����ϣ��û���Down������ĻҪ��ʾ��һҳ�����Ų����һ�׸���

һ�㷭ҳ����Ļ��ʾ�Ĳ��ǵ�һҳʱ������ڵ�ǰ��Ļ��ʾ�ĵ�һ�׸���ʱ���û���Up����
��Ļ�ӵ�ǰ��������һ�׿�ʼ��ʾ�����ҲŲ����һ�׸�������굱ǰ��Ļ�����һ�׸�ʱ��Down������Ҳ����

������������÷�ҳ��ֻ��Ų��������
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

















/************************************************�ҳ��ַ����е�һ��ֻ����һ�ε��ַ���ţ�ͣ�************************************************/
/*
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
���ݷ�Χ��������ַ�����������1��n��1000
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
















/**************************************************************���ս���ţ�ͣ�***************************************************************/
/*
С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У�
�������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ����
�������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����

����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000
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
















/*************************************************************�Ǽ����루ţ�ͣ�**************************************************************/
/*
�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������ͨ��һ�ű������Ϣӳ�������4λ���롣
��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�������������4λ����0��䣬�������4λ����ֻ������4λ��
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
����n=2ʱ��
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
��2��Ӧ�����ǡ�0002��

����������
�����ж������ݡ�
ÿ���������У���һ�а���һ������n (1��n��100)���ڶ��а���n��������Xi (1��Xi��10000) ��ע�⣺ÿ��Xi��Ӧ������n��
���������
��Ӧÿһ�����룬���һ����Ӧ������
*/
/*
����˼·��
�г�n = 1,2,3,4,5...��������ɷ�����쳲��������еĹ���
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



















/****************************************************************������ţ�ͣ�***********************************************************/
/*
��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô���������������
����������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������

����������
��������������ݡ�
ÿ���������ݰ���һ��������n��1��n��10E1000����
���������
��Ӧÿһ�����ݣ������������������
*/

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main() {
//    string str;
//    while (cin >> str) {
//        long long num = 0;
//        for (auto it : str) num += (it - '0');//����̫���ַ������գ����и�λ��Ӵ���
//
//        long long sum = 0;
//        while (num)
//        {
//            sum += num % 10;
//            num /= 10;
//            if (num == 0 && sum >= 10) {//һ�θ�λ��Ӳ����ܵõ���������λ����
//                num = sum;
//                sum = 0;
//            }
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}


















