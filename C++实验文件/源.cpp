#define _CRT_SECURE_NO_WARNINGS





/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
*/

//初始版本
//#include<iostream>
//#include<string>
//#include<math.h>
//using namespace std;
//class Solution {
//public:
//    bool isPalindrome(int x) {
//        int i = 0;
//        long temp = x;
//        int num = 0;
//        for (; temp > 0; i++)
//        {
//            temp /= 10;
//        }
//        temp = x;
//        if (temp >= 0)
//        {
//            while (temp > 0)
//            {
//                long n = temp % 10;
//                temp /= 10;
//                num += n * (long)pow(10, i-1);
//                i--;
//            }
//            if (num == x)
//            {
//                return true;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        else
//        {
//            return false;
//        }
//    }
//};
//int main()
//{
//    int x = 9;
//    Solution s;
//    bool ret = s.isPalindrome(x);
//    if (ret)
//    {
//        cout << "是" << endl;
//    }
//    else
//    {
//        cout << "不是" << endl;
//    }
//    return 0;
//}


//优化版本
//class Solution {
//public:
//    bool isPalindrome(int x) {
//        if (x < 0)
//            return false;
//        long cur = 0;
//        long num = x;
//        while (num != 0) {
//            cur = cur * 10 + num % 10;
//            num /= 10;
//        }
//        return cur == x;
//    }
//};






















/*
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
*/
//#include<vector>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i <= nums.size(); i++)
//        {
//            if (i != nums.size() && nums[i] == i)
//            {
//                continue;
//            }
//            else
//            {
//                return i;
//            }
//        }
//        return 1;
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(3);
//    v.push_back(0);
//    v.push_back(1);
//    Solution s;
//    cout<<s.missingNumber(v);//2
//    return 0;
//}

















/*
给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分数。另给你一个整数 k 。

从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值 达到 最小化 。

返回可能的 最小差值 。
*/
//class Solution
//{
//public:
//    int minimumDifference(vector<int>& nums, int k)
//    {
//        sort(nums.begin(), nums.end());
//        int mindifferent = INT_MAX;
//        for (int i = 0; i < nums.size() - k + 1; i++)
//        {
//            mindifferent = mindifferent < nums[i + k - 1] - nums[i] ? mindifferent : nums[i + k - 1] - nums[i];
//        }
//        return mindifferent;
//    }
//};























/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        for (int i = 0; i < (int)nums.size() - 1; ++i)
//        {
//            for (int j = i + 1; j < (int)nums.size(); ++j)
//            {
//                if (nums[i] + nums[j] == target)
//                {
//                    return { i,j };
//                }
//            }
//        }
//        return { -1,-1 };
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(3);
//    v.push_back(3);
//    int target = 6;
//    Solution s;
//    vector<int>v2 = s.twoSum(v, target);
//    for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
//    {
//        cout << *it << endl;
//    }
//    return 0;
//}









/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/

//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//class Solution {
//public:
//    bool isValid(string s)
//    {
//        stack<char>st;
//        string::iterator it = s.begin();
//        while (it!=s.end())
//        {
//            if (!st.empty())
//            {
//                if ((st.top() == '(' && (*it == '}' || *it == ']')) ||
//                    (st.top() == '{' && (*it == ')' || *it == ']')) ||
//                    (st.top() == '[' && (*it == ')' || *it == '}')))
//                {
//                    return false;
//                }
//            }
//            if (*it == '{' || *it == '[' || *it == '(')
//            {
//                st.push(*it);
//            }
//            if (st.empty())
//            {
//                return false;
//            }
//            if ((st.top() == '(' && *it == ')') || (st.top() == '{' && *it == '}') || (st.top() == '[' && *it == ']'))
//            {
//                if (!st.empty())
//                {
//                    st.pop();
//                }
//                else
//                {
//                    return false;
//                }
//            }
//            ++it;
//        }
//        if (st.empty())
//        {
//            return true;
//        }
//        return false;
//    }
//};
//int main()
//{
//    string str = "()";
//    Solution s;
//    cout<<s.isValid(str);
//    return 0;
//}

















/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。
*/

/*
解题思路:
1.通常情况下,罗马数字中小的数字在大的数字的右边.若输入的字符串满足该情况,那么可以将每个字符视作一个单独的值,累加每个字符对应的数值即可.
2.若存在小的数字在大的数字的左边的情况,根据规则需要减去小的数字.
对于这种情况,我们也可以将每个字符视作一个单独的值,若一个数字右侧的数字比它大,则将该数字的符号取反。
*/

//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//class Solution {
//private:
//    map<char, int> symbolValues = {
//        {'I', 1},
//        {'V', 5},
//        {'X', 10},
//        {'L', 50},
//        {'C', 100},
//        {'D', 500},
//        {'M', 1000},
//    };
//
//public:
//    int romanToInt(string s) {
//        int ret = 0;
//        int size = s.size();
//        for (int i = 0; i < size; ++i) {
//            int value = symbolValues[s[i]];
//            if (i < size-1 && value < symbolValues[s[i + 1]])//最后一位必然取正号
//            {
//                ret -= value;
//            }
//            else
//            {
//                ret += value;
//            }
//        }
//        return ret;
//    }
//};












/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        int size = nums.size();
//        if (size == 0)return size;
//        int front = 1, back = 1;
//        for (int i = 1; i < size; ++i)
//        {
//            if (nums[front-1] == nums[front])
//            {
//                ++front;
//                continue;
//            }
//            nums[back] = nums[front];
//            ++front;
//            ++back;
//        }
//        return back;
//    }
//};
//int main()
//{
//    vector<int>v;
//    Solution s;
//    v.push_back(0);
//    v.push_back(0);
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(3);
//    s.removeDuplicates(v);
//    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//    {
//        cout << *it << endl;
//    }
//    return 0;
//}












/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
不使用额外空间且时间复杂度为 O(n)
*/


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//1.所用时间过长
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        int size = nums.size();
//        for (vector<int>::iterator it = nums.begin();it!=nums.end()-1;++it)
//        {
//            if (*it == *(it+1))
//            {
//                nums.erase((it+1));
//                it--;
//            }
//        }
//        for (int i = 0; i < size; ++i)
//        {
//            vector<int>::iterator ret = find(nums.begin(), nums.end(), i + 1);
//            if (ret != nums.end())
//            {
//                nums.erase(ret);
//            }
//            else
//            {
//                nums.push_back(i + 1);
//            }
//        }
//        return nums;
//    }
//};
//int main()
//{
//    vector<int>v;
//    Solution s;
//    v.push_back(4);
//    v.push_back(3);
//    v.push_back(2);
//    v.push_back(7);
//    v.push_back(8);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(1);
//    s.findDisappearedNumbers(v);
//    for (int i = 0; i < v.size(); ++i)
//    {
//        cout << v[i] << endl;
//    }
//    return 0;
//}

//2
/*
具体来说，遍历 \textit{nums}nums，每遇到一个数 xx，就让 \textit{nums}[x-1]nums[x−1] 增加 nn。由于 \textit{nums}nums 中所有数均在 [1,n][1,n] 中，
增加以后，这些数必然大于 nn。最后我们遍历 \textit{nums}nums，若 \textit{nums}[i]nums[i] 未大于 nn，就说明没有遇到过数 i+1i+1。这样我们就找到了缺失的数字

注意，当我们遍历到某个位置时，其中的数可能已经被增加过，因此需要对 nn 取模来还原出它本来的值。

即利用下标求解
*/
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        vector<int> res;
//        if (nums.empty()) return nums;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            int index = (nums[i] - 1) % nums.size();
//            nums[index] += nums.size();
//        }
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] <= nums.size())
//                res.push_back(i + 1);
//        }
//        return res;
//    }
//};


























//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, d;
//	cout << "Enter two numbers:";
//	cin >> a >> b;
//	int min = a < b ? a : b;
//	for (d = 2; d < min; ++d)
//	{
//		if (((a % d) == 0) && ((b % d) == 0))
//		{
//			break;
//		}
//	}
//	if (d == min)
//	{
//		cout << "No common denominator";
//		return 0;
//	}
//	cout << "The lowest common denominator is " << d << endl;
//	return 0;
//}




//#include<iostream>
//using namespace std;
//int sum(int, int);
//int main()
//{
//	int a, b;
//	cout << "Enter two numbers:";
//	cin >> a >> b;
//	cout<<sum(a, b)<<endl;
//	return 0;
//}
//int sum (int a, int b)
//{
//	return a + b;
//}










//#include<iostream>
//using namespace std;
//int main()
//{
//	int* p = new int[20];
//	p[0] = p[1] = 1;
//	for (int i = 2; i < 20; ++i)
//	{
//		p[i] = p[i - 1] + p[i - 2];
//	}
//	for (int i = 0; i < 20; ++i)
//	{
//		cout << *(p + i) << endl;
//	}
//	delete[] p;
//	p = nullptr;
//	return 0;
//}





//#include<iostream>
//#include<cmath>
//using namespace std;
//double sroot(double db)
//{
//	return sqrt(db);
//}
//double sroot(int a)
//{
//	return sqrt(a);
//}
//double sroot(long a)
//{
//	return sqrt(a);
//}
//int main()
//{
//	cout << sroot(3.14) << endl;
//	cout << sroot(2) << endl;
//	cout << sroot((long)10) << endl;
//	return 0;
//}






//#include<iostream>
//#include<cmath>
//using namespace std;
//template <class T> struct Checker;
////限制只能使用int,long,double类型
//template <> struct Checker<int> { typedef int Type; };
//template <> struct Checker<long> { typedef long Type; };
//template <> struct Checker<double> { typedef double Type; };
//
//template <class T>
//typename Checker<T>::Type sroot(T t)
//{
//    return sqrt(t);
//}
//int main()
//{
//	auto ret1 = sroot(3.14);
//	cout << ret1 << endl;
//	auto ret2 = sroot(2);
//	cout << ret2 << endl;
//	auto ret3 = sroot((long)10);
//	cout << ret3 << endl;
//	return 0;
//}











/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

返回的nums新的长度
*/



//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val)
//    {
//        int size = nums.size();
//        for (int i = 0; i < size; ++i)
//        {
//            if (nums[i] == val)
//            {
//                for (int j = i; j < size - 1; ++j)
//                {
//                    nums[j] = nums[j + 1];
//                }
//                --size;
//                --i;
//            }
//        }
//        return size;
//    }
//};
//int main()
//{
//    vector<int>nums;
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(0);
//    nums.push_back(4);
//    nums.push_back(2);
//    int val = 2;
//    Solution s;
//    int len = s.removeElement(nums, val);
//    for (int i = 0; i < len; i++) {
//        cout << nums[i];
//    }
//    return 0;
//}



//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val)
//    {
//        int size = nums.size();
//        int left = 0;
//        for (int right = 0; right < size; right++)
//        {
//            if (nums[right] != val)
//            {
//                nums[left] = nums[right];
//                left++;
//            }
//        }
//        return left;
//    }
//};
//int main()
//{
//    vector<int>nums;
//    nums.push_back(3);
//    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(3);
//    int val = 3;
//    Solution s;
//    int len = s.removeElement(nums, val);
//    for (int i = 0; i < len; i++) {
//        cout << nums[i];
//    }
//    return 0;
//}









/*
实现 strStr() 函数。
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。
*/



//方法一:不推荐
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    int strStr(string haystack, string needle)
//    {
//        int count = 0;
//        if (needle == "")
//        {
//            return 0;
//        }
//        for (int i = 0; i < haystack.size(); ++i)
//        {
//            if (haystack[i] == needle[count])
//            {
//                ++count;
//            }
//            else
//            {
//                if (count != 0)
//                {
//                    i -= count;
//                }
//                count = 0;
//            }
//            if (count == needle.size())
//            {
//                return i - needle.size() + 1;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    string haystack = "sississippi";
//    string needle = "ss";
//    Solution s;
//    int ret = s.strStr(haystack, needle);
//    cout << ret << endl;
//	return 0;
//}



//方法二:
/*
我们可以让字符串needle与字符串haystack的所有长度为m的子串均匹配一次。
为了减少不必要的匹配，我们每次匹配失败即立刻停止当前子串的匹配，对下一个子串继续匹配。如果当前子串匹配成功，我们返回当前子串的开始位置即可。
如果所有子串都匹配失败，则返回 -1.
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        int n = haystack.size(), m = needle.size();
//        for (int i = 0; i + m <= n; i++)
//        {
//            bool flag = true;
//            for (int j = 0; j < m; j++)
//            {
//                if (haystack[i + j] != needle[j])
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag) 
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    string haystack = "mississippi";
//    string needle = "";
//    Solution s;
//    int ret = s.strStr(haystack, needle);
//    cout << ret << endl;
//    return 0;
//}










/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

//不可处理过长数据
//#include<iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> plusOne(vector<int>& digits)
//    {
//        int size = digits.size();
//        unsigned long long ret = 0;
//        bool flag = false;
//        for (int i = 0; i < size; ++i)
//        {
//            unsigned long long temp = pow(10, size - i - 1);
//            ret += digits[i] * temp;
//        }
//        ++ret;
//        for (int i = 0; i < size; ++i)
//        {
//            if (digits[i] != 9)
//            {
//                flag = true;
//            }
//        }
//        if (flag)
//        {
//            for (int i = 0; i < size; ++i)
//            {
//                digits[i] = ret / pow(10, size - i - 1);
//                unsigned long long temp = pow(10, size - i - 1);
//                ret = ret % temp;
//            }
//        }
//        else
//        {
//            for (int i = 0; i < size; ++i)
//            {
//                digits[i] = ret / pow(10, size - i);
//                unsigned long long temp = (int)pow(10, size - i - 1);
//                ret = ret % temp;
//            }
//            digits.push_back(ret);
//        }
//        return digits;
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(6);
//    v.push_back(1);
//    v.push_back(4);
//    v.push_back(5);
//    v.push_back(3);
//    v.push_back(9);
//    v.push_back(0);
//    v.push_back(1);
//    v.push_back(9);
//    v.push_back(5);
//    v.push_back(1);
//    v.push_back(8);
//    v.push_back(6);
//    v.push_back(7);
//    v.push_back(0);
//    v.push_back(5);
//    v.push_back(5);
//    v.push_back(4);
//    v.push_back(3);
//    Solution s;
//    s.plusOne(v);
//    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//    {
//        cout << *it << endl;
//    }
//	return 0;
//}







/*
当我们对数组digits 加一时，我们只需要关注digits 的末尾出现了多少个 9即可。我们可以考虑如下的三种情况：

如果digits 的末尾没有9，例如 [1,2,3]，那么我们直接将末尾的数加一，得到 [1,2,4] 并返回；

如果 digits 的末尾有若干个 9，例如 [1,2,3,9,9]，那么我们只需要找出从末尾开始的第一个不为9 的元素，
即 3，将该元素加一，得到 [1,2,4,9,9]。随后将末尾的9 全部置零，得到 [1,2,4,0,0] 并返回。

如果 digits 的所有元素都是 99，例如[9,9,9,9,9]，那么答案为 [1,0,0,0,0,0]。
我们只需要构造一个长度比 digits 多 11 的新数组，将首元素置为 1，其余元素置为 0 即可。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> plusOne(vector<int>& digits)
//    {
//        int size = digits.size();
//        for (int i = size - 1; i >= 0; --i)
//        {
//            if (digits[i] != 9)
//            {
//                ++digits[i];
//                for (int j = i + 1; j < size; ++j)
//                {
//                    digits[j] = 0;
//                }
//                return digits;
//            }
//        }
//        vector<int> ans(size + 1);
//        ans[0] = 1;
//        return ans;
//    }
//};














/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        int size = nums.size();
//        for (int i = 0; i < size-1; ++i)
//        {
//            if (nums[i] != nums[i + 1])
//            {
//                return nums[i];
//            }
//            ++i;
//        }
//        return nums[size-1];
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(4);
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(1);
//    v.push_back(2);
//    Solution s;
//    cout<<s.singleNumber(v);
//	return 0;
//}


/*
异或运算有以下三个性质。

任何数和0做异或运算，结果仍然是原来的数，即 a⊕0=a。
任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。

假设数组中有 2m+12m+1 个数，其中有 mm 个数各出现两次，一个数出现一次。令 a1、a2 … am为出现两次的m个数，a m+1为出现一次的数。

(a1^a1)^(a2^a2)^……^(am^am)^am+1
即0^0^……^0^am+1 = am+1

因此，数组中的全部元素的异或运算结果即为数组中只出现一次的数字。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        int ret = 0;
//        for (int i = 0;i<nums.size();++i) 
//        {
//            int temp = nums[i];
//            ret ^= temp;
//        }
//        return ret;
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(4);
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(1);
//    v.push_back(2);
//    Solution s;
//    cout<<s.singleNumber(v);
//	return 0;
//}















/*
给你一个非负整数x,计算并返回 x 的 算术平方根 。

由于返回类型是整数,结果只保留整数部分,小数部分将被舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/

//二分查找
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//    int mySqrt(int x)
//    {
//        int l = 0, r = x, ans = -1;
//        while (l <= r)
//        {
//            int mid = l + (r - l) / 2;
//            if ((long long)mid * mid <= x)
//            {
//                ans = mid;
//                l = mid + 1;
//            }
//            else
//            {
//                r = mid - 1;
//            }
//        }
//        return ans;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.mySqrt(4);
//	return 0;
//}


//数学转换
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int mySqrt(int x)
//    {
//        if (x == 0)
//        {
//            return 0;
//        }
//        int ans = exp(0.5 * log(x));
//        return (long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.mySqrt(4);
//	return 0;
//}
















/*
猜数字游戏的规则如下：

每轮游戏，我都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，我会告诉你，你猜测的数字比我选出的数字是大了还是小了。
你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）：

-1：我选出的数字比你猜的数字小 pick < num
1：我选出的数字比你猜的数字大 pick > num
0：我选出的数字和你猜的数字一样。恭喜！你猜对了！pick == num
返回我选出的数字。
*/


//二分查找法
//#include<iostream>
//using namespace std;
//int guess(int num);
//class Solution
//{
//public:
//    int guessNumber(int n)
//    {
//        long long mid = n / 2;
//        long long left = 1, right = n;
//        while (left <= right)
//        {
//            if (guess(mid) == 0)
//            {
//                return mid;
//            }
//            else if (guess(mid) == -1)
//            {
//                right = mid - 1;
//                mid = (left + right) / 2;
//            }
//            else if (guess(mid) == 1)
//            {
//                left = mid + 1;
//                mid = (left + right) / 2;
//            }
//        }
//        return -1;
//    }
//};











/*
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

-231 <= n <= 231 - 1

2^30=1,073,741,824
*/

//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    bool isPowerOfTwo(int n)
//    {
//        if (n>0 && 1073741824 % n == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.isPowerOfTwo(0);
//    return 0;
//}
















//重复元素1
/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    bool containsDuplicate(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        for (int i = 1; i < nums.size(); ++i)
//        {
//            if (nums[i - 1] == nums[i])
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//};












//重复元素2
/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
如果存在，返回 true ；否则，返回 false 。
*/

//效率太低
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k)
//    {
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            for (int j = i; j < nums.size(); ++j)
//            {
//                if (i != j && nums[i] == nums[j] && abs(i-j)<=k)
//                {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(1);
//    Solution s;
//    cout<<s.containsNearbyDuplicate(v, 3);
//	return 0;
//}


/*
方法二：滑动窗口
考虑数组nums 中的每个长度不超过k+1 的滑动窗口，同一个滑动窗口中的任意两个下标差的绝对值不超过k。
如果存在一个滑动窗口，其中有重复元素，则存在两个不同的下标 i 和 j 满足 nums[i]=nums[j] 且 ∣i−j∣≤k。
如果所有滑动窗口中都没有重复元素，则不存在符合要求的下标。因此，只要遍历每个滑动窗口，判断滑动窗口中是否有重复元素即可。

如果一个滑动窗口的结束下标是 i，则该滑动窗口的开始下标是 max(0,i−k)。可以使用哈希集合存储滑动窗口中的元素。
从左到右遍历数组nums，当遍历到下标 i 时，具体操作如下：

如果 i>k，则下标 i−k−1 处的元素被移出滑动窗口，因此将nums[i−k−1] 从哈希集合中删除；

判断 nums[i] 是否在哈希集合中，如果在哈希集合中则在同一个滑动窗口中有重复元素，返回true，如果不在哈希集合中则将其加入哈希集合。

当遍历结束时，如果所有滑动窗口中都没有重复元素，返回 false。
*/














/*
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
*/


//循环遍历
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int missingNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        int count = 0;
//        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it,++count)
//        {
//            if (*it != count)
//            {
//                return count;
//            }
//        }
//        return count;
//    }
//};
//int main()
//{
//    vector<int>nums;
//    nums.push_back(3);
//    nums.push_back(0);
//    nums.push_back(1);
//    Solution s;
//    cout<<s.missingNumber(nums);
//    return 0;
//}

//稍优化版
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int missingNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        for (int i = 0; i < n; i++)
//        {
//            if (nums[i] != i)
//            {
//                return i;
//            }
//        }
//        return n;
//    }
//};




//位运算
/*
按位异或运算⊕满足交换律和结合律,且对任意整数x都满足x⊕x=0和x⊕0=x。
由于上述2n+1个整数中,丢失的数字出现了一次,其余的数字都出现了两次,因此对上述2n+1个整数进行按位异或运算,结果即为丢失的数字。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int missingNumber(vector<int>& nums)
//    {
//        int res = 0;
//        int n = nums.size();
//        for (int i = 0; i < n; i++)
//        {
//            res ^= nums[i];
//        }
//        for (int i = 0; i <= n; i++)
//        {
//            res ^= i;
//        }
//        return res;
//    }
//};













/*
给定两个字符串s和t,它们只包含小写字母。
字符串t由字符串s随机重排,然后在随机位置添加一个字母。
请找出在t中被添加的字母。
*/



/*
求和:
将字符串s中每个字符的 ASCII 码的值求和，得到 A_s
对字符串t同样的方法得到 A_t
两者的差值 A_t - A_s即代表了被添加的字符。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    char findTheDifference(string s, string t)
//    {
//        int ret = 0;
//        for (string::iterator it = t.begin(); it != t.end(); ++it)
//        {
//            ret += *it;
//        }
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            ret -= *it;
//        }
//        return (char)ret;
//    }
//};
//int main()
//{
//    string s = "abcd";
//    string t = "abcde";
//    Solution a;
//    cout<<a.findTheDifference(s, t);
//	return 0;
//}



/*
位运算:
按位异或运算⊕满足交换律和结合律
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    char findTheDifference(string s, string t)
//    {
//        int ret = 0;
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            ret ^= *it;
//        }
//        for (string::iterator it = t.begin(); it != t.end(); ++it)
//        {
//            ret ^= *it;
//        }
//        return (char)ret;
//    }
//};
//int main()
//{
//    string s = "abcd";
//    string t = "abcde";
//    Solution a;
//    cout<<a.findTheDifference(s, t);
//	return 0;
//}





/*
计数法:
使用额外空间，遍历字符串s，所遇元素加1。遍历字符串t，所遇元素减1.
若为负数，则该字符为添加的字符
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    char findTheDifference(string s, string t)
//    {
//        vector<int>v(26,0);//26个字母
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            ++v[*it - 'a'];
//        }
//        for (string::iterator it = t.begin(); it != t.end(); ++it)
//        {
//            --v[*it - 'a'];
//            if (v[*it - 'a'] < 0)
//            {
//                return *it;
//            }
//        }
//        return  ' ';
//    }
//};
//int main()
//{
//    string s = "abcd";
//    string t = "abcde";
//    Solution a;
//    cout << a.findTheDifference(s, t);
//    return 0;
//}









/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/

//循环遍历
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//	int searchInsert(vector<int>& nums, int target)
//	{
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			if (target <= nums[i])
//			{
//				return i;
//			}
//		}
//		return nums.size();
//	}
//};
//int main()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(5);
//	v.push_back(6);
//	Solution s;
//	cout<<s.searchInsert(v, 5);
//	return 0;
//}



//二分查找
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//	int searchInsert(vector<int>& nums, int target)
//	{
//		int left = 0, right = nums.size() - 1;
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (nums[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else
//			{
//				right = mid - 1;
//			}
//		}
//		return left;
//	}
//};
//int main()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(5);
//	v.push_back(6);
//	Solution s;
//	cout << s.searchInsert(v, 5);
//	return 0;
//}

















/*
给定一个二进制数组nums.计算其中最大连续1的个数。
nums[i] 不是 0 就是 1
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//	int findMaxConsecutiveOnes(vector<int>& nums)
//	{
//		int count = 0, Max = 0;
//		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
//		{
//			if (*it == 1)
//			{
//				++count;
//			}
//			else
//			{
//				count = 0;
//			}
//			if (Max < count)
//			{
//				Max = count;
//			}
//		}
//		return Max;
//	}
//};
//int main()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(0);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	Solution s;
//	cout<<s.findMaxConsecutiveOnes(v);
//	return 0;
//}














/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
*/

//位运算
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int hammingWeight(uint32_t n)
//    {
//        int ret = 0;
//        for (int i = 0; i < 32; ++i)
//        {
//            if (n & (1 << i))
//            {
//                ++ret;
//            }
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.hammingWeight(1);
//	return 0;
//}


//位运算优化
/*
观察这个运算：n & (n−1)，其运算结果恰为把n的二进制位中的最低位的1变为0之后的结果。
如：6 & (6−1)=4 , 6=(110)_2 , 4=(100)_2​，运算结果4即为把6的二进制位中的最低位的1变为0之后的结果。

这样我们可以利用这个位运算的性质加速我们的检查过程，在实际代码中，
我们不断让当前的n与n−1做与运算，直到 n 变为 0 即可。因为每次运算会使得 n 的最低位的 1 被翻转，因此运算次数就等于 n 的二进制位中 1 的个数。
*/
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int hammingWeight(uint32_t n)
//    {
//        int ret = 0;
//        while (n)
//        {
//            n &= n - 1;
//            ++ret;
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.hammingWeight(1);
//    return 0;
//}















/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 n/2 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int majorityElement(vector<int>& nums)
//    {
//        sort(nums.begin(),nums.end());
//        return nums[nums.size() / 2];
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(3);
//    v.push_back(2);
//    v.push_back(3);
//    Solution s;
//    cout<<s.majorityElement(v);
//	return 0;
//}


//随机化(图一乐)
/*
我们随机挑选一个下标，检查它是否是众数，如果是就返回，否则继续随机挑选。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int majorityElement(vector<int>& nums)
//    {
//        while (1)
//        {
//            int ret = nums[rand() % nums.size()];
//            int count = 0;
//            for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
//            {
//                if (ret == *it)
//                {
//                    ++count;
//                }
//            }
//            if (count > nums.size() / 2)
//            {
//                return ret;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    srand((unsigned int)time(NULL));
//    vector<int>v;
//    v.push_back(3);
//    v.push_back(2);
//    v.push_back(3);
//    Solution s;
//    cout << s.majorityElement(v);
//    return 0;
//}











/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<int>v;
//        /*sort(nums1.begin(), nums1.end());
//        sort(nums2.begin(), nums2.end());*/
//        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
//        {
//            for (vector<int>::iterator its = nums2.begin(); its != nums2.end(); ++its)
//            {
//                if (*it == *its)
//                {
//                    if (!v.size() || *it != v.back())//防止加入重复元素
//                    {
//                        v.push_back(*it);
//                        break;
//                    }
//                }
//            }
//        }
//        //删除重复元素
//        /*sort(v.begin(), v.end());
//        for (int i = 1; i < v.size(); ++i)
//        {
//            if (v[i] == v[i - 1])
//            {
//                vector<int>::iterator it = v.begin() + i - 1;
//                v.erase(it);
//                --i;
//            }
//        }*/
//        return v;
//    }
//};
//int main()
//{
//    vector<int>v1, v2;
//    v1.push_back(4);
//    v1.push_back(9);
//    v1.push_back(5);
//
//    v2.push_back(9);
//    v2.push_back(4);
//    v2.push_back(9);
//    v2.push_back(8);
//    v2.push_back(4);
//    Solution s;
//    vector<int>v3 = s.intersection(v1, v2);
//    for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
//    {
//        cout << *it << " ";
//    }
//	return 0;
//}



//双指针
/*
首先对两个数组进行排序，然后使用两个指针遍历两个数组。可以预见的是加入答案的数组的元素一定是递增的，
为了保证加入元素的唯一性，我们需要额外记录变量 pre 表示上一次加入答案数组的元素。

初始时，两个指针分别指向两个数组的头部。每次比较两个指针指向的两个数组中的数字，如果两个数字不相等，则将指向较小数字的指针右移一位，
如果两个数字相等，且该数字不等于 pre ,同时将两个指针都右移一位。
当至少有一个指针超出数组范围时，遍历结束。
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//    {
//        sort(nums1.begin(), nums1.end());
//        sort(nums2.begin(), nums2.end());
//        int length1 = nums1.size(), length2 = nums2.size();
//        int index1 = 0, index2 = 0;
//        vector<int> intersection;
//        while (index1 < length1 && index2 < length2)
//        {
//            int num1 = nums1[index1], num2 = nums2[index2];
//            if (num1 == num2)
//            {
//                // 保证加入元素的唯一性
//                if (!intersection.size() || num1 != intersection.back())
//                {
//                    intersection.push_back(num1);
//                }
//                index1++;
//                index2++;
//            }
//            else if (num1 < num2)
//            {
//                index1++;
//            }
//            else
//            {
//                index2++;
//            }
//        }
//        return intersection;
//    }
//};
//int main()
//{
//    vector<int>v1, v2;
//    v1.push_back(4);
//    v1.push_back(9);
//    v1.push_back(5);
//
//    v2.push_back(9);
//    v2.push_back(4);
//    v2.push_back(9);
//    v2.push_back(8);
//    v2.push_back(4);
//    Solution s;
//    vector<int>v3 = s.intersection(v1, v2);
//    for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
//    {
//        cout << *it << " ";
//    }
//    return 0;
//}














/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
*/

//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    bool isPowerOfThree(int n)
//    {
//        if (n < 0)
//        {
//            return false;
//        }
//        if (1162261467 % n == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//};
///*
//class Solution
//{
//public:
//    bool isPowerOfThree(int n)
//    {
//        return n > 0 && 1162261467 % n == 0;
//    }
//};
//*/
//int main()
//{
//    Solution s;
//    cout<<s.isPowerOfThree(-3);
//	return 0;
//}


//试除法
/*
我们不断地将n除以33,直到n=1.如果此过程中n无法被3整除,就说明n不是3的幂。
本题中的n可以为负数或0,可以直接提前判断该情况并返回False,也可以进行试除，因为负数或0也无法通过多次除以3得到1。
*/
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    bool isPowerOfThree(int n)
//    {
//        while (n && n % 3 == 0)
//        {
//            n /= 3;
//        }
//        return n == 1;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.isPowerOfThree(-3);
//	return 0;
//}











/*
对于一个正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为完美数。

给定一个整数 n， 如果是完美数，返回true；否则返回false。
*/
//#include<iostream>
//#include<cmath>
//using namespace std;
////超过时间限制
////class Solution
////{
////public:
////    bool checkPerfectNumber(int num)
////    {
////        int ret = 0;
////        for (int i = 1; i < num; ++i)
////        {
////            if (num % i == 0)
////            {
////                ret += i;
////            }
////        }
////        return ret == num;
////    }
////};
//class Solution {
//public:
//    bool checkPerfectNumber(int num)
//    {
//        if (num == 1)
//        {
//            return false;
//        }
//        int sum = 1;
//        for (int d = 2; d * d <= num; ++d)
//        {
//            if (num % d == 0)
//            {
//                sum += d;
//                if (d * d < num)
//                {
//                    sum += num / d;
//                }
//            }
//        }
//        return sum == num;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.checkPerfectNumber(28);
//	return 0;
//}
























/*
给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x
*/

/*
如果 n 是 4 的幂，那么它可以表示成 4^x的形式，我们可以发现它除以 3 的余数一定为 1，即：

如果 n 是 2 的幂却不是 4 的幂，那么它可以表示成 4^x×2 的形式，此时它除以 3 的余数一定为 2。

因此我们可以通过 n 除以 3 的余数是否为 1 来判断 n 是否是 4 的幂。
*/
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    bool isPowerOfFour(int n)
//    {
//        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.isPowerOfFour(16);
//	return 0;
//}




/*
如果 n 是 4 的幂，那么 n 的二进制表示中有且仅有一个 1，并且这个 1 出现在从低位开始的第偶数个二进制位上（这是因为这个 1 后面必须有偶数个 0）。
这里我们规定最低位为第 0 位，例如 n=16 时，n 的二进制表示为(10000)_2​

唯一的 1 出现在第 4 个二进制位上，因此 n 是 4 的幂。

由于题目保证了 n 是一个 32 位的有符号整数，因此我们可以构造一个整数mask，它的所有偶数二进制位都是0，所有奇数二进制位都是1。
这样一来，我们将 n 和 mask 进行按位与运算，如果结果为 0，说明 n 二进制表示中的 1 出现在偶数的位置，否则说明其出现在奇数的位置。

根据上面的思路,mask 的二进制表示为：
mask=(10101010101010101010101010101010)2

我们也可以将其表示成 1616 进制的形式，使其更加美观：
mask=(AAAAAAAA)16
*/
//#include<iostream>
//#include<math.h>
//using namespace std;
//class Solution
//{
//public:
//    bool isPowerOfFour(int n)
//    {
//        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.isPowerOfFour(8);
//    return 0;
//}









//二分查找
/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int search(vector<int>& nums, int target)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left <= right)
//        {
//            int mid = (left + right) / 2;
//            if (nums[mid] == target)
//            {
//                return mid;
//            }
//            else if (nums[mid] < target)
//            {
//                left = mid + 1;
//            }
//            else if(nums[mid] > target)
//            {
//                right = mid - 1;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int>v;
//    v.push_back(-1);
//    v.push_back(0);
//    v.push_back(3);
//    v.push_back(5);
//    v.push_back(9);
//    v.push_back(12);
//    cout<<s.search(v, 9);
//	return 0;
//}













//删除链表中的节点
/*
请编写一个函数，用于删除单链表中某个特定节点 。在设计函数时需要注意，你无法访问链表的头节点 head ，只能直接访问要被删除的节点 。

题目数据保证需要删除的节点不是末尾节点 。
*/

/*
删除链表中的节点的常见的方法是定位到待删除节点的上一个节点，修改上一个节点的 next 指针，使其指向待删除节点的下一个节点，即可完成删除操作。

这道题中，传入的参数 node 为要被删除的节点，无法定位到该节点的上一个节点。
注意到要被删除的节点不是链表的末尾节点，因此 node.next 不为空，可以通过对 node 和 node.next 进行操作实现删除节点。

在给定节点 node 的情况下，可以通过修改 node 的 next 指针的指向，删除 node 的下一个节点。
但是题目要求删除 node，为了达到删除 node 的效果，只要在删除节点之前，将 node 的节点值修改为 node.next 的节点值即可。

例如，给定链表 4→5→1→9，要被删除的节点是 5，即链表中的第 2 个节点。可以通过如下两步操作实现删除节点的操作。

将第 2 个节点的值修改为第 3 个节点的值，即将节点 5 的值修改为 1，此时链表如下：
4→1→1→9

删除第 3 个节点，此时链表如下：
4→1→9
*/

//class Solution
//{
//public:
//    void deleteNode(ListNode* node)
//    {
//        node->val = node->next->val;
//        node->next = node->next->next;
//    }
//};









//合并两个有序数组
/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/

//先合并后排序
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//    {
//        vector<int>v;
//        for (int i = 0; i < max(m, n); ++i)
//        {
//            if (i < m)
//            {
//                v.push_back(nums1[i]);
//            }
//            if (i < n)
//            {
//                v.push_back(nums2[i]);
//            }
//        }
//        nums1.clear();
//        for (vector<int>::iterator it =v.begin();it != v.end();++it)
//        {
//            nums1.push_back(*it);
//        }
//        sort(nums1.begin(), nums1.end());
//    }
//};


//时间优化版
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//    {
//        for (int i = 0; i != n; ++i)
//        {
//            nums1[m + i] = nums2[i];
//        }
//        sort(nums1.begin(), nums1.end());
//    }
//};

//双指针
/*
将两个数组看作队列，每次从两个数组头部取出比较小的数字放到结果中
为两个数组分别设置 p_1与 p_2来作为队列的头部指针
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//    {
//        int p1 = 0, p2 = 0;
//        int* sorted = new (int [m + n]);
//        if (sorted == NULL)
//        {
//            return;
//        }
//        int cur;
//        while (p1 < m || p2 < n)
//        {
//            if (p1 == m)
//            {
//                cur = nums2[p2++];
//            }
//            else if (p2 == n)
//            {
//                cur = nums1[p1++];
//            }
//            else if (nums1[p1] < nums2[p2])
//            {
//                cur = nums1[p1++];
//            }
//            else
//            {
//                cur = nums2[p2++];
//            }
//            sorted[p1 + p2 - 1] = cur;
//        }
//        for (int i = 0; i != m + n; ++i)
//        {
//            nums1[i] = sorted[i];
//        }
//        delete[]sorted;
//    }
//};




















/*
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
给定 n ，请计算 F(n) 。
*/

//使用数组或递归也可解决问题，但堆区内存有限，使用动态开辟空间存在局限性，递归效率太低

//动态规划
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int fib(int n)
//    {
//        if (n < 2)
//        {
//            return n;
//        }
//        int left = 0, right = 1;
//        for (int i = 2; i <= n; ++i)
//        {
//            int temp = right;
//            right = left + right;
//            left = temp;
//        }
//        return right;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.fib(3) << endl;
//	return 0;
//}

//数组(不具有普适性，但由于leetcode无法进行动态内存开辟，只能使用该笨方法)
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int fib(int n)
//    {
//        int a[31] = { 0,1 };
//        for (int i = 2; i < 31; i++)
//        {
//            a[i] = a[i - 1] + a[i - 2];
//        }
//        return a[n];
//    }
//};













/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int thirdMax(vector<int>& nums)
//    {
//        if (nums.size() < 2)
//        {
//            return nums[0];
//        }
//        sort(nums.begin(), nums.end());
//        int temp = *(nums.rbegin()), count = 0;
//        for (vector<int>::reverse_iterator it = nums.rbegin()+1; it != nums.rend(); ++it)
//        {
//            if (temp != *it)
//            {
//                ++count;
//            }
//            if (count == 2)
//            {
//                return *it;
//            }
//            temp = *it;
//        }
//        return nums[nums.size() - 1];
//    }
//};
//int main()
//{
//    vector<int>v;
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(2);
//    v.push_back(5);
//    v.push_back(3);
//    v.push_back(5);
//    /*v.push_back(3);
//    v.push_back(2);
//    v.push_back(1);*/
//    Solution s;
//    cout<<s.thirdMax(v);
//    return 0;
//}

//优化版
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int thirdMax(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end(), greater<>());
//        for (int i = 1, diff = 1; i < nums.size(); ++i)
//        {
//            if (nums[i] != nums[i - 1] && ++diff == 3)
//            { 
//                // 此时 nums[i] 就是第三大的数
//                return nums[i];
//            }
//        }
//        return nums[0];
//    }
//};



//有序遍历
/*
遍历数组，同时用一个有序集合来维护数组中前三大的数。具体做法是每遍历一个数，就将其插入有序集合，
若有序集合的大小超过 3，就删除集合中的最小元素。这样可以保证有序集合的大小至多为 3，且遍历结束后，
若有序集合的大小为 3，其最小值就是数组中第三大的数；若有序集合的大小不足 3，那么就返回有序集合中的最大值。
*/

//#include<iostream>
//#include<set>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int thirdMax(vector<int>& nums)
//    {
//        set<int> s;
//        for (int num : nums)
//        {
//            if (s.find(num) == s.end())
//            {
//                s.insert(num);
//            }
//            if (s.size() > 3)
//            {
//                s.erase(s.begin());
//            }
//        }
//        return s.size() == 3 ? *s.begin() : *s.rbegin();
//    }
//};
















/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    int countSegments(string s)
//    {
//        if (s == "")
//        {
//            return 0;
//        }
//        int count = 0;
//        for (string::iterator it = s.begin()+1; it != s.end(); ++it)
//        {
//            if (*(it-1) != ' ' && *it == ' ')
//            {
//                ++count;
//            }
//        }
//        if (*(s.end() - 1) != ' ')
//        {
//            return count + 1;
//        }
//        return count;
//    }
//};
//int main()
//{
//    Solution s;
//    string str = "";
//    cout<<s.countSegments(str);
//	return 0;
//}



//优化版
/*
计算字符串中单词的数量，就等同于计数单词的第一个下标的个数。因此，我们只需要遍历整个字符串，统计每个单词的第一个下标的数目即可。

满足单词的第一个下标有以下两个条件：

该下标对应的字符不为空格；

该下标为初始下标或者该下标的前下标对应的字符为空格；
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    int countSegments(string s)
//    {
//        int segmentCount = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
//            {
//                segmentCount++;
//            }
//        }
//        return segmentCount;
//    }
//};











/*
给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。
*/
//#include<iostream>
//#include<string>
//using namespace std;
////class Solution
////{
////public:
////    string toLowerCase(string s)
////    {
////        for (string::iterator it = s.begin(); it != s.end(); ++it)
////        {
////            if (*it >= 65 && *it <= 90)
////            {
////                *it += 32;
////            }
////        }
////        return s;
////    }
////};
//class Solution
//{
//public:
//    string toLowerCase(string s)
//    {
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            *it = tolower(*it);
//        }
//        return s;
//    }
//};
//int main()
//{
//    Solution sol;
//    string str = "LOVELY";
//    cout<<sol.toLowerCase(str);
//	return 0;
//}










/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
*/

/*
反转每个下标从 2k 的倍数开始的，长度为 k 的子串。若该子串长度不足 k，则反转整个子串。
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    string reverseStr(string s, int k)
//    {
//        int n = s.length();
//        for (int i = 0; i < n; i += 2 * k)
//        {
//            reverse(s.begin() + i, s.begin() + min(i + k, n));
//        }
//        return s;
//    }
//};
//int main()
//{
//    string str = "abcdefg";
//    Solution s;
//    cout<<s.reverseStr(str, 2);
//	return 0;
//}











/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> sortArrayByParity(vector<int>& nums)
//    {
//        vector<int>v;
//        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
//        {
//            if ((*it) % 2 == 0)
//            {
//                v.push_back(*it);
//            }
//        }
//        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
//        {
//            if ((*it) % 2 != 0)
//            {
//                v.push_back(*it);
//            }
//        }
//        return v;
//    }
//};
//int main()
//{
//    vector<int>v = {3,1,2,4};
//    Solution s;
//    v = s.sortArrayByParity(v);
//    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//    {
//        cout << *it << " ";
//    }
//	return 0;
//}







/*
给你一个整数数组 nums ，该数组具有以下属性：

nums.length == 2 * n.
nums 包含 n + 1 个 不同的 元素
nums 中恰有一个元素重复 n 次
找出并返回重复了 n 次的那个元素。
*/

//存在空间限制
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int repeatedNTimes(vector<int>& nums)
//    {
//        int arr[1024] = { 0 };
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            ++arr[nums[i]];
//        }
//        int max = arr[0];
//        int count = 0;
//        for (int i = 1; i < 1024; ++i)
//        {
//            if (arr[i] > max)
//            {
//                max = arr[i];
//                count = i;
//            }
//        }
//        return count;
//    }
//};
//int main()
//{
//    vector<int>v = {7,8,7,0};
//    Solution s;
//    cout<<s.repeatedNTimes(v);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int repeatedNTimes(vector<int>& nums)
//    {
//        int size = nums.size();
//        if (size == 2) {
//            return nums[0];
//        }
//        sort(nums.begin(), nums.end());
//        if (nums[size / 2] == nums[size / 2 + 1])
//        {
//            return nums[size / 2]; // 在右半边
//        }
//        else
//        {
//            return nums[size / 2 - 1]; // 在左半边
//        }
//    }
//};













/*
泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
*/
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int tribonacci(int n)
//    {
//        if (n < 2)
//        {
//            return n;
//        }
//        int left = 0,mid = 1,right = 1;
//        for (int i = 3; i <= n; ++i)
//        {
//            int temp1 = right;
//            int temp2 = mid;
//            right = left + mid + right;
//            mid = temp1;
//            left = temp2;
//        }
//        return right;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.tribonacci(4);
//	return 0;
//}










/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
s只包含小写字母
*/

//超过时间限制(目前所知方法)
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    int firstUniqChar(string s)
//    {
//        int size = s.size();
//        for (int i = 0; i < size; ++i)
//        {
//            int count = 0;
//            for (int j = 0; j < size; ++j)
//            {
//                if (s[i] == s[j])
//                {
//                    ++count;
//                    continue;
//                }
//            }
//            if (count == 1)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    string str = "loveleetcode";
//    Solution s;
//    cout<<s.firstUniqChar(str);
//	return 0;
//}












/*
给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。

矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<vector<int>> transpose(vector<vector<int>>& matrix)
//    {
//        int m = matrix.size(), n = matrix[0].size();
//        vector<vector<int>> transposed(n, vector<int>(m));
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                transposed[j][i] = matrix[i][j];
//            }
//        }
//        return transposed;
//    }
//};
//int main()
//{
//    vector<vector<int>>matrix = { {1, 2, 3},{4, 5, 6 }, { 7, 8, 9 } };
//    Solution s;
//    matrix = s.transpose(matrix);
//    for (vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); ++it)
//    {
//        for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); ++its)
//        {
//            cout << *its << " ";
//        }
//        cout << endl;
//    }
//	return 0;
//}








/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
*/

//初始版
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    bool isPalindrome(string s)
//    {
//        if (s == "")
//        {
//            return true;
//        }
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            if ((*it >= 97 && *it <= 122) || (*it >= 65 && *it <= 90) || (*it >= 48 && *it <= 57))
//            {
//                *it = tolower(*it);
//                continue;
//            }
//            s.erase(it);
//            s.resize(s.size()-1,' ');
//            if (it != s.begin())
//            {
//                --it;
//            }
//        }
//        string::iterator left = s.begin();
//        string::iterator right = s.end() - 1;
//        while (left <= right)
//        {
//            if (*left == ' ' || *left == '.')
//            {
//                ++left;
//            }
//            if (*right == ' ' || *left == '.')
//            {
//                --right;
//            }
//            if (*left == *right)
//            {
//                ++left;
//                --right;
//                continue;
//            }
//            return false;
//        }
//        return true;
//    }
//};
//int main()
//{
//    string str = "......a.....";
//    Solution s;
//    cout<<s.isPalindrome(str);
//	return 0;
//}

//优化版
//class Solution
//{
//public:
//    bool isPalindrome(string s)
//    {
//        string sgood;
//        for (char ch : s)
//        {
//            if (isalnum(ch))
//            {
//                sgood += tolower(ch);
//            }
//        }
//        int n = sgood.size();
//        int left = 0, right = n - 1;
//        while (left < right)
//        {
//            if (sgood[left] != sgood[right])
//            {
//                return false;
//            }
//            ++left;
//            --right;
//        }
//        return true;
//    }
//};


/*
最简单的方法是对字符串 s 进行一次遍历，并将其中的字母和数字字符进行保留，放在另一个字符串sgood 中。
这样我们只需要判断 sgood 是否是一个普通的回文串即可。

判断的方法有两种。第一种是使用语言中的字符串翻转 API 得到 sgood 的逆序字符串}sgood_rev，
只要这两个字符串相同，那么sgood 就是回文串。
*/
//class Solution
//{
//public:
//    bool isPalindrome(string s)
//    {
//        string sgood;
//        for (char ch : s) {
//            if (isalnum(ch))
//            {
//                sgood += tolower(ch);
//            }
//        }
//        string sgood_rev(sgood.rbegin(), sgood.rend());
//        return sgood == sgood_rev;
//    }
//};














/*
如果数组是单调递增或单调递减的，那么它是 单调 的。

如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> = nums[j]，那么数组 nums 是单调递减的。

当给定的数组 nums 是单调数组时返回 true，否则返回 false。
*/

//#include<algorithm>
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    bool isMonotonic(vector<int>& nums)
//    {
//        vector<int>Greater;
//        Greater.resize(nums.size());
//        vector<int>Less;
//        Less.resize(nums.size());
//        int ret1 = true , ret2 = true;
//        copy(nums.begin(), nums.end(), Greater.begin());
//        copy(nums.begin(), nums.end(), Less.begin());
//        sort(Greater.begin(), Greater.end(), greater<int>());
//        sort(Less.begin(), Less.end(), less<int>());
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            if (nums[i] != Greater[i])
//            {
//                ret1 = false;
//            }
//            if (nums[i] != Less[i])
//            {
//                ret2 = false;
//            }
//        }
//        return ret1 || ret2;
//    }
//};
//int main()
//{
//    vector<int>v{ 1,2,2,3 };
//    Solution s;
//    cout<<s.isMonotonic(v);
//	return 0;
//}


//优化版
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    bool isMonotonic(vector<int>& nums)
//    {
//        bool inc = true, dec = true;
//        int n = nums.size();
//        for (int i = 0; i < n - 1; ++i)
//        {
//            if (nums[i] > nums[i + 1])
//            {
//                inc = false;
//            }
//            if (nums[i] < nums[i + 1])
//            {
//                dec = false;
//            }
//        }
//        return inc || dec;
//    }
//};



/*
//判断 [first, last) 区域内的数据是否符合 std::less<T> 排序规则，即是否为升序序列
bool is_sorted (ForwardIterator first, ForwardIterator last);
//判断 [first, last) 区域内的数据是否符合 comp 排序规则
bool is_sorted (ForwardIterator first, ForwardIterator last, Compare comp);
*/
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    bool isMonotonic(vector<int>& nums)
//    {
//        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.rbegin(), nums.rend());
//    }
//};
















/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
*/

//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int addDigits(int num)
//    {
//        if (num < 10)
//            return num;
//        while (num >= 10)
//        {
//            int sum = 0;
//            while (num > 0)
//            {
//                sum += num % 10;
//                num /= 10;
//            }
//            num = sum;
//        }
//        return num;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.addDigits(38);
//	return 0;
//}









//#include <iostream>
//#include<string>
//#include<memory>
//using namespace std;
//class Student
//{
//public:
//    Student(string, int, double);
//    void account(double);
//    static double sum();
//    static double average();
//private:
//    static double total_score;
//    static int count;
//    string m_name;
//    int m_age;
//    double m_score;
//};
//double Student::total_score = 0.0;
//int Student::count = 0;
//Student::Student(string name, int age, double score) : m_name(name), m_age(age), m_score(score)
//{
//    ++count;
//    total_score += score;
//}
//void Student::account(double score)
//{
//    total_score = total_score - this->m_score + score;
//    this->m_score = score;
//}
//double Student::sum()
//{
//    return total_score;
//}
//double Student::average()
//{
//    return total_score / count;
//}
//int main()
//{
//    unique_ptr<Student>s1(new Student("a", 17, 59.9));
//    unique_ptr<Student>s2(new Student("b", 18, 100.0));
//    unique_ptr<Student>s3(new Student("c", 19, 60));
//    cout << "总分为" << s1->sum() << endl;
//    s1->account(79);
//    cout << "总分为:" << s1->sum() << endl;
//    cout << "平均分为:" << s2->average() << endl;
//    return 0;
//}










//#include<iostream>
//using namespace std;
//int main()
//{
//	for (int i = 0; i < 100; ++i)
//	{
//		cout << "hello world" << endl;
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	for (int i = 0; i < 100; i++)
//	{
//		cout << "hello world" << endl;
//	}
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int main()
//{
//00552540  push        ebp
//00552541  mov         ebp,esp
//00552543  sub         esp,0CCh
//00552549  push        ebx
//0055254A  push        esi
//0055254B  push        edi
//0055254C  lea         edi,[ebp-0Ch]
//0055254F  mov         ecx,3
//00552554  mov         eax,0CCCCCCCCh
//00552559  rep stos    dword ptr es:[edi]
//0055255B  mov         ecx,offset _57B8321F_源@cpp (055F029h)
//00552560  call        @__CheckForDebuggerJustMyCode@4 (055137Fh)
//	for (int i = 0; i < 100; ++i)
//00552565  mov         dword ptr [ebp-8],0
//0055256C  jmp         __$EncStackInitStart+2Bh (0552577h)
//0055256E  mov         eax,dword ptr [ebp-8]
//00552571  add         eax,1
//00552574  mov         dword ptr [ebp-8],eax
//00552577  cmp         dword ptr [ebp-8],64h
//0055257B  jge         __$EncStackInitStart+5Ch (05525A8h)
//	{
//		cout << "hello world" << endl;
//0055257D  mov         esi,esp
//0055257F  push        offset std::endl<char,std::char_traits<char> > (055103Ch)
//00552584  push        offset string "hello world" (0559B30h)
//00552589  mov         eax,dword ptr [__imp_std::cout (055D0D4h)]
//0055258E  push        eax
//0055258F  call        std::operator<<<std::char_traits<char> > (05511A9h)
//00552594  add         esp,8
//00552597  mov         ecx,eax
//00552599  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (055D0A0h)]
//0055259F  cmp         esi,esp
//005525A1  call        __RTC_CheckEsp (055128Fh)
//	}
//005525A6  jmp         __$EncStackInitStart+22h (055256Eh)
//	return 0;
//005525A8  xor         eax,eax
//}





//
//#include<iostream>
//using namespace std;
//int main()
//{
//008B2540  push        ebp
//008B2541  mov         ebp,esp
//008B2543  sub         esp,0CCh
//008B2549  push        ebx
//008B254A  push        esi
//008B254B  push        edi
//008B254C  lea         edi,[ebp-0Ch]
//008B254F  mov         ecx,3
//008B2554  mov         eax,0CCCCCCCCh
//008B2559  rep stos    dword ptr es:[edi]
//008B255B  mov         ecx,offset _57B8321F_源@cpp (08BF029h)
//008B2560  call        @__CheckForDebuggerJustMyCode@4 (08B137Fh)
//	for (int i = 0; i < 100; i++)
//008B2565  mov         dword ptr [ebp-8],0
//008B256C  jmp         __$EncStackInitStart+2Bh (08B2577h)
//008B256E  mov         eax,dword ptr [ebp-8]
//008B2571  add         eax,1
//008B2574  mov         dword ptr [ebp-8],eax
//008B2577  cmp         dword ptr [ebp-8],64h
//008B257B  jge         __$EncStackInitStart+5Ch (08B25A8h)
//	{
//		cout << "hello world" << endl;
//008B257D  mov         esi,esp
//008B257F  push        offset std::endl<char,std::char_traits<char> > (08B103Ch)
//008B2584  push        offset string "hello world" (08B9B30h)
//008B2589  mov         eax,dword ptr [__imp_std::cout (08BD0D4h)]
//008B258E  push        eax
//008B258F  call        std::operator<<<std::char_traits<char> > (08B11A9h)
//008B2594  add         esp,8
//008B2597  mov         ecx,eax
//008B2599  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (08BD0A0h)]
//008B259F  cmp         esi,esp
//008B25A1  call        __RTC_CheckEsp (08B128Fh)
//	}
//008B25A6  jmp         __$EncStackInitStart+22h (08B256Eh)
//	return 0;
//008B25A8  xor         eax,eax
//}





//#include<iostream>
//using namespace std;
//class MyInt
//{
//	friend ostream& operator<<(ostream& cout, MyInt& a);//友元
//public:
//	MyInt();
//	MyInt& operator++();//前置++
//	MyInt& operator++(int);//使用占位参数区别前后置++，使之可以发生函数重载
//private:
//	int m_num;
//};
//MyInt::MyInt()
//{
//	this->m_num = 0;
//}
//MyInt& MyInt::operator++()
//{
//	this->m_num++;
//	return *this;
//}
//MyInt& MyInt::operator++(int)
//{
//	static MyInt temp = *this;
//	this->m_num++;
//	return temp;
//}
//ostream& operator<<(ostream& cout, MyInt& a)
//{
//	cout << a.m_num;
//	return cout;
//}









/*
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int findLengthOfLCIS(vector<int>& nums)
//    {
//        int count = 0;
//        vector<int>v;
//        for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); ++it)
//        {
//            if (*(it - 1) < *it)
//            {
//                ++count;
//            }
//            else
//            {
//                v.push_back(count);
//                count = 0;
//            }
//        }
//        v.push_back(count);
//        sort(v.begin(), v.end());
//        return v[v.size() - 1] + 1;
//    }
//};
//int main()
//{
//    vector<int>nums{ 1,3,5,7};
//    Solution s;
//    cout<<s.findLengthOfLCIS(nums);
//	return 0;
//}


//#include<cmath>
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int findLengthOfLCIS(vector<int>& nums)
//    {
//        int ans = 0;
//        int n = nums.size();
//        int start = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (i > 0 && nums[i] <= nums[i - 1])
//            {
//                start = i;
//            }
//            ans = max(ans, i - start + 1);
//        }
//        return ans;
//    }
//};












/*
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<int>v;
//        int count = 0;
//        bool flag = false;
//        for (int i = 0; i < nums1.size(); ++i)
//        {
//            for (int j = 0; j < nums2.size(); ++j)
//            {
//                if (nums1[i] == nums2[j])
//                {
//                    count = j;
//                    break;
//                }
//            }
//            for (int j = count + 1; j < nums2.size(); ++j)
//            {
//                if (nums2[count] < nums2[j])
//                {
//                    v.push_back(nums2[j]);
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag == false)
//            {
//                v.push_back(-1);
//            }
//            flag = false;
//        }
//        return v;
//    }
//};
//int main()
//{
//    vector<int>nums1{ 4, 1, 2 }, nums2{ 1, 3, 4, 2 };
//    Solution s;
//    vector<int>ret = s.nextGreaterElement(nums1, nums2);
//    for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
//    {
//        cout << *it << " ";
//    }
//	return 0;
//}






//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
//    {
//        int m = nums1.size();
//        int n = nums2.size();
//        vector<int> res(m);
//        for (int i = 0; i < m; ++i)
//        {
//            int j = 0;
//            while (j < n && nums2[j] != nums1[i])
//            {
//                ++j;
//            }//找到元素相同时的下标
//            int k = j + 1;
//            while (k < n && nums2[k] < nums2[j])
//            {
//                ++k;
//            }//找到nums2[k]>nums2[j]
//            res[i] = k < n ? nums2[k] : -1;
//        }
//        return res;
//    }
//};








/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    int lengthOfLastWord(string s)
//    {
//        int count = 0;
//        for (string::reverse_iterator its = s.rbegin(); its != s.rend(); ++its)
//        {
//            if (*its != ' ')
//            {
//                ++count;
//            }
//            if (*its != ' ' && *(its + 1) == ' ')
//            {
//                break;
//            }
//        }
//        return count;
//    }
//};
//int main()
//{
//    string str = "   fly me   to   the moon  ";
//    Solution s;
//    cout<<s.lengthOfLastWord(str);
//	return 0;
//}











/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
*/

/*
充分理解题意后，我们可以发现，当字符串中同时有多组相邻重复项时，我们无论是先删除哪一个，都不会影响最终的结果。因此我们可以从左向右顺次处理该字符串。

而消除一对相邻重复项可能会导致新的相邻重复项出现，如从字符串abba 中删除bb 会导致出现新的相邻重复项}aa 出现。
因此我们需要保存当前还未被删除的字符。一种显而易见的数据结构呼之欲出：栈。我们只需要遍历该字符串，如果当前字符和栈顶字符相同，我们就贪心地将其消去，否则就将其入栈即可。
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    string removeDuplicates(string s)
//    {
//        string stk;
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            if (!stk.empty() && stk.back() == *it)
//            {
//                stk.pop_back();
//            }
//            else
//            {
//                stk.push_back(*it);
//            }
//        }
//        return stk;
//    }
//};
//int main()
//{
//    string str = "abbaca";
//    Solution s;
//    cout<<s.removeDuplicates(str);
//    return 0;
//}












/*
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用 单个空格 分隔的单词组成。请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。

如果 searchWord 是某一个单词的前缀，则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。
如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord 不是任何单词的前缀，则返回 -1 。

字符串 s 的 前缀 是 s 的任何前导连续子字符串。
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    int isPrefixOfWord(string sentence, string searchWord)
//    {
//        int SentSize = sentence.size();
//        int WordSize = searchWord.size();
//        int count = 1;
//        bool flag = true;
//        for (int i = 0;i<SentSize;++i)
//        {
//            for (int j = 0; j < WordSize; ++j)
//            {
//                if (sentence[i+j] != searchWord[j])
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag == true)
//            {
//                return count;
//            }
//            while (i < SentSize && sentence[i] != ' ')++i;
//            ++count;
//            flag = true;
//        }
//        return -1;
//    }
//};
//int main()
//{
//    string sentence = "hellohello hellohellohello", searchWord = "ell";
//    Solution s;
//    cout<<s.isPrefixOfWord(sentence,searchWord);
//	return 0;
//}











/*
有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。

例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 s，考虑将其进行原语化分解，使得：s = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。

对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。
*/
/*
用stack保存 ( 所在的位置从0开始
遍历直到s为空，则截取这一段（去除头和尾的括号）插入到结果里
*/
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//class Solution
//{
//public:
//    string removeOuterParentheses(string S)
//    {
//        int n = S.size();
//        stack<int> s;
//        string res = "";
//        for (int i = 0; i < n; ++i)
//        {
//            if (S[i] == '(')
//            {
//                s.push(i);
//            }
//            else
//            {
//                int start = s.top();
//                s.pop();
//                if (s.empty())
//                {
//                    res += S.substr(start + 1, i - start - 1);
//                }
//            }
//        }
//        return res;
//    }
//};





















/*
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
*/

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        int size = nums.size();
//        if (size < 3)
//        {
//            return nums[size - 1];
//        }
//        for (vector<int>::iterator it = nums.begin(); it != nums.end() - 2; ++it, --size)
//        {
//            if (*it == *(it + 1) && *it == *(it + 2))
//            {
//                it += 2;
//                size -= 2;
//            }
//            else
//            {
//                if (*it == *(it + 1))
//                {
//                    return *(it + 2);
//                }
//                else if (*it == *(it + 2))
//                {
//                    return *(it + 1);
//                }
//                else
//                {
//                    return *it;
//                }
//            }
//            if (size < 3)
//            {
//                return nums[nums.size() - 1];
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    vector<int>v{ 1};
//    Solution s;
//    cout<<s.singleNumber(v);
//	return 0;
//}












/*
给你一个混合字符串 s ，请你返回 s 中 第二大 的数字，如果不存在第二大的数字，请你返回 -1 。

混合字符串 由小写英文字母和数字组成。
*/
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int secondHighest(string s)
//    {
//        sort(s.begin(), s.end());
//        for (string::iterator it = s.begin(); it != s.end();)
//        {
//            if (*it >= 97 && *it <= 122)
//            {
//                it = s.erase(it);
//            }
//            else
//            {
//                ++it;
//            }
//        }
//        if (s.size() == 0)
//        {
//            return -1;
//        }
//        for (string::reverse_iterator it = s.rbegin()+1; it != s.rend(); ++it)
//        {
//            if (*it != s[s.size() - 1])
//            {
//                return (int)((*it) - 48);
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    string str = "xyz";
//    Solution s;
//    cout << s.secondHighest(str);
//	return 0;
//}
















/*
给定一个非负整数 x ，计算并返回 x 的平方根，即实现 int sqrt(int x) 函数。

正数的平方根有两个，只输出其中的正数平方根。

如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。
*/

/*
由于 x 平方根的整数部分 ans 是满足 k^2 ≤x 的最大 k 值，因此我们可以对 k 进行二分查找，从而得到答案。
二分查找的下界为 0，上界可以粗略地设定为 x。在二分查找的每一步中，我们只需要比较中间元素 mid 的平方与 x 的大小关系，
并通过比较的结果调整上下界的范围。由于我们所有的运算都是整数运算，不会存在误差，因此在得到最终的答案 ans 后，也就不需要再去尝试 1ans+1 了。
*/
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int mySqrt(int x)
//    {
//        int left = 0, right = x, ans = -1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if ((long long)mid * mid <= x)
//            {
//                ans = mid;
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//        return ans;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.mySqrt(4) << endl;
//	return 0;
//}











/*
一个字符串如果没有 三个连续 相同字符，那么它就是一个 好字符串 。

给你一个字符串 s ，请你从 s 删除 最少 的字符，使它变成一个 好字符串 。

请你返回删除后的字符串。题目数据保证答案总是 唯一的 。
*/

//算法思想
/*
如果想使得好字符串对应的删除字符数量最少，那么最佳的删除策略是：对于 s 中每一个长度为 k(k≥3) 的连续相同字符子串，删去其中任意 k−2 个字符。

我们可以用一个新字符串 res 来维护删除最少字符后得到的好字符串，并从左至右遍历字符串 s 模拟删除过程。
每当遍历至一个新的字符时，我们检查 res 中的最后两个字符（如有）是否均等于当前字符：

如果是，则该字符应被删除，我们不将该字符添加进 res；

如果不是，则不需要删除该字符，我们应当将该字符添加进 res。

当遍历完成 ss 后，res 即为删除最少字符后得到的好字符串，我们返回 res 作为答案。
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    string makeFancyString(string s)
//    {
//        string res;   // 删除后的字符串
//        // 遍历 s 添加元素模拟删除过程
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            int n = res.size();
//            if (n >= 2 && res[n - 1] == *it && res[n - 2] == *it)
//            {
//                // 如果 res 最后两个字符与当前字符均相等，则不添加
//                continue;
//            }
//            // 反之则添加
//            res.push_back(*it);
//        }
//        return res;
//    }
//};
//int main()
//{
//    string str = "leeetcode";
//    Solution s;
//    cout << s.makeFancyString(str) << endl;
//	return 0;
//}















/*
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表
*/

/*
由于给定的链表是排好序的，因此重复的元素在链表中出现的位置是连续的，因此我们只需要对链表进行一次遍历，就可以删除重复的元素。

具体地，我们从指针 cur 指向链表的头节点，随后开始对链表进行遍历。如果当前 cur 与 cur.next 对应的元素相同，
那么我们就将 cur.next 从链表中移除；否则说明链表中已经不存在其它与 cur 对应的元素相同的节点，因此可以将 cur 指向 cur.next。

当遍历完整个链表之后，我们返回链表的头节点即可。

细节

当我们遍历到链表的最后一个节点时，cur.next 为空节点，如果不加以判断，访问 cur.next 对应的元素会产生运行错误。
因此我们只需要遍历到链表的最后一个节点，而不需要遍历完整个链表。
*/

//#include<iostream>
//using namespace std;
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution
//{
//public:
//    ListNode* deleteDuplicates(ListNode* head)
//    {
//        if (!head)//若头结点为空，则直接返回
//        {
//            return head;
//        }
//        ListNode* cur = head;
//        while (cur->next)//遍历链表
//        {
//            if (cur->val == cur->next->val)//发现重复元素
//            {
//                cur->next = cur->next->next;//通过间隔连接实现删除元素
//            }
//            else
//            {
//                cur = cur->next;//移动到下一元素
//            }
//        }
//        return head;
//    }
//};











//本质为斐波那契数
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/


//动态规划
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int climbStairs(int n)
//    {
//        int left = 0, right = 0, ret = 1;
//        for (int i = 1; i <= n; ++i)
//        {
//            left = right;
//            right = ret;
//            ret = left + right;
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.climbStairs(3) << endl;
//	return 0;
//}


//矩阵快速幂
//通项公式





//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//class Book
//{
//	friend bool Search_Book(Book* ,string name);
//public:
//	Book(string name,string author,string press,int price)
//	{
//		this->m_BookName = name;
//		this->m_BookAuthor = author;
//		this->m_BookPress = press;
//		this->m_price = price;
//	}
//	string reName()
//	{
//		return this->m_BookName;
//	}
//	void Print()const
//	{
//		cout << this->m_BookName << " " << this->m_BookAuthor << " " << this->m_BookPress << endl;
//	}
//private:
//	string m_BookName;
//	string m_BookAuthor;
//	string m_BookPress;
//	int m_price;
//};
//bool Search_Book(Book* b,string name)
//{
//	if (name == b->reName())
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	vector<Book*>v;
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; ++i)
//	{
//		int price;
//		string name, author, press;
//		cin >> name >> author >> press;
//		cin >> price;
//		Book* bp = new Book(name, author, press, price);
//		v.push_back(bp);
//	}
//	string test_book;
//	cin >> test_book;
//	bool ret;
//	for (vector<Book*>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		ret = Search_Book(*it, test_book);
//		if (ret == true)
//		{
//			(*it)->Print();
//			break;
//		}
//	}
//	if (ret == false)
//	{
//		cout << "没有该书" << endl;
//	}
//	return 0;
//}














/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串
*/

//贪心法
/*
在允许最多删除一个字符的情况下，同样可以使用双指针，通过贪心实现。初始化两个指针 low 和 high 分别指向字符串的第一个字符和最后一个字符。
每次判断两个指针指向的字符是否相同，如果相同，则更新指针，将 low 加 1，high 减 1，然后判断更新后的指针范围内的子串是否是回文字符串。
如果两个指针指向的字符不同，则两个字符中必须有一个被删除，此时我们就分成两种情况：即删除左指针对应的字符，留下子串 s[low+1:high]，
或者删除右指针对应的字符，留下子串 s[low:high−1]。当这两个子串中至少有一个是回文串时，就说明原始字符串删除一个字符之后就以成为回文串。
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    bool validPalindrome(string s)
//    {
//        int low = 0, high = s.size() - 1;
//        while (low < high)
//        {
//            char c1 = s[low], c2 = s[high];
//            if (c1 == c2)
//            {
//                ++low;
//                --high;
//            }
//            else
//            {
//                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
//            }
//        }
//        return true;
//    }
//private:
//    bool checkPalindrome(const string& s, int low, int high)//判断是否为回文串
//    {
//        for (int i = low, j = high; i < j; ++i, --j)
//        {
//            if (s[i] != s[j])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//int main()
//{
//    string str = "aba";
//    Solution s;
//    cout<<s.validPalindrome(str);
//    return 0;
//}















/*
给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。
水平翻转图片就是将图片的每一行都进行翻转，即逆序。
反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
//    {
//        vector<vector<int>>ret;
//        for (vector<vector<int>>::iterator it = image.begin(); it != image.end(); ++it)
//        {
//            vector<int>v;
//            for (vector<int>::reverse_iterator its = (*it).rbegin(); its != (*it).rend(); ++its)
//            {
//                if (*its == 1)
//                {
//                    v.push_back(0);
//                }
//                else
//                {
//                    v.push_back(1);
//                }
//            }
//            ret.push_back(v);
//        }
//        
//        return ret;
//    }
//};
//int main()
//{
//    vector<vector<int>>image = { {1, 1, 0},{1, 0, 1},{0, 0, 0} };
//    Solution s;
//    vector<vector<int>> ret = s.flipAndInvertImage(image);
//    for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); ++it)
//    {
//        for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); ++its)
//        {
//            cout << *its << " ";
//        }
//        cout << endl;
//    }
//	return 0;
//}









//#include<iostream>
//#include<string>
//using namespace std;
//class Person
//{
//public:
//	//两个纯虚函数
//	virtual void speak() = 0;
//	virtual void walk() = 0;
//private:
//	string m_name;
//	int age;
//};
//class Worker :public Person
//{
//public:
//	//重写父类纯虚函数
//	void speak()
//	{
//		cout << "Work中speak函数调用" << endl;
//	}
//	void walk()
//	{
//		cout << "Work中walk函数调用" << endl;
//	}
//private:
//	int m_salary;
//};
//class Student :public Person
//{
//public:
//	//重写父类纯虚函数
//	void speak()
//	{
//		cout << "Student中speak函数调用" << endl;
//	}
//	void walk()
//	{
//		cout << "Student中walk函数调用" << endl;
//	}
//private:
//	string m_school;
//};
//int main()
//{
//	//新建Worker和Student对象
//	Worker* w = new Worker;
//	Student* s = new Student;
//	//用父类Perosn的指针指向这两个对象
//	Person* p1 = w;
//	Person* p2 = s;
//	//调用
//	p1->speak();
//	p1->walk();
//	p2->speak();
//	p2->walk();
//	return 0;
//}














/*
给你一个字符串 s ，如果 s 是一个 好 字符串，请你返回 true ，否则请返回 false 。

如果 s 中出现过的 所有 字符的出现次数 相同 ，那么我们称字符串 s 是 好 字符串。

s只包含小写字母
*/
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    bool areOccurrencesEqual(string s)
//    {
//        vector<int>flag;
//        flag.resize(26);
//        for (int i = 0; i < 26; ++i)
//        {
//            flag[i] = 0;
//        }
//        for (string::iterator it = s.begin(); it != s.end(); ++it)
//        {
//            ++flag[(*it) - 97];
//        }
//        sort(flag.begin(), flag.end());
//        for (int i = 0; i < 25; ++i)
//        {
//            if (flag[i] != 0 && flag[i] < flag[25])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//int main()
//{
//    string str = "aca";
//    Solution s;
//    cout<<s.areOccurrencesEqual(str);
//	return 0;
//}






/*
丑数 就是只包含质因数 2、3 和 5 的正整数。

给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
*/

/*
当 n>0 时，若 n 是丑数，则 n 可以写成 n = 2^a x 3^b x 5^c 的形式，其中 a,b,c 都是非负整数。特别地，当 a,b,c 都是 0 时,n=1。

为判断 n 是否满足上述形式，可以对 n 反复除以 2,3,5，直到 n 不再包含质因数 2,3,5。
若剩下的数等于 1，则说明 n 不包含其他质因数，是丑数；否则，说明 n 包含其他质因数，不是丑数。

*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    bool isUgly(int n)
//    {
//        if (n <= 0)
//        {
//            return false;
//        }
//        vector<int> factors = { 2, 3, 5 };
//        for (vector<int>::iterator it = factors.begin(); it != factors.end(); ++it)
//        {
//            while (n % (*it) == 0)
//            {
//                n /= (*it);
//            }
//        }
//        return n == 1;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.isUgly(7);
//	return 0;
//}









/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    bool isSubsequence(string s, string t)
//    {
//        int n = s.length(), m = t.length();
//        int i = 0, j = 0;
//        while (i < n && j < m)
//        {
//            if (s[i] == t[j])
//            {
//                i++;
//            }
//            j++;
//        }
//        return i == n;
//    }
//};
//int main()
//{
//    string s = "abc", t = "ahbgdc";
//    Solution sol;
//    cout<<sol.isSubsequence(s, t);
//	return 0;
//}






//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    int mySqrt(int num)
//    {
//        int left = 0, right = num, ret = -1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if ((long long)mid * mid <= num)
//            {
//                ret = mid;
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//        return ret;
//    }
//};
//int main()
//{
//    int num;
//    cin >> num;
//    Solution s;
//    cout << s.mySqrt(num) << endl;
//    return 0;
//}












/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        int size = nums.size();
//        if (size < 2)return size;
//        int slow = 2, fast = 2;
//        while (fast < size)
//        {
//            if (nums[slow - 2] != nums[fast])
//            {
//                nums[slow] = nums[fast];
//                ++slow;
//            }
//            ++fast;
//        }
//        return slow;
//    }
//};
//int main()
//{
//    vector<int>nums{ 1, 1, 1, 2, 2, 3 };
//    Solution s;
//    int num = s.removeDuplicates(nums);
//    for (int i = 0; i < num; ++i)
//    {
//        cout << nums[i] << " ";
//    }
//    return 0;
//}









/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/
//#include<iostream>
//using namespace std;
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution
//{
//public:
//    ListNode* deleteDuplicates(ListNode* head)
//    {
//        if (head == nullptr)
//        {
//            return head;
//        }
//        ListNode* dummy = new ListNode(0, head);
//        ListNode* cur = dummy;
//        while (cur->next && cur->next->next)
//        {
//            if (cur->next->val == cur->next->next->val)
//            {
//                int x = cur->next->val;
//                while (cur->next && cur->next->val == x)
//                {
//                    cur->next = cur->next->next;
//                }
//            }
//            else {
//                cur = cur->next;
//            }
//        }
//        return dummy->next;
//    }
//};







/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即x^n ）。
*/

//超出时间限制
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    double myPow(double x, int n)
//    {
//        if (n < 0)
//        {
//            x = 1 / x;
//            n = -n;
//        }
//        double ret = 1;
//        for (int i = 0; i < n; ++i)
//        {
//            ret *= x;
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.myPow(2.00000,10);
//}




//快速幂+递归
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    double quickMul(double x, long long N)
//    {
//        if (N == 0)
//        {
//            return 1.0;
//        }
//        double y = quickMul(x, N / 2);
//        return N % 2 == 0 ? y * y : y * y * x;
//    }
//    double myPow(double x, int n)
//    {
//        long long N = n;
//        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
//    }
//};




//快速幂+递归
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    double quickMul(double x, long long N)
//    {
//        double ans = 1.0;
//        // 贡献的初始值为 x
//        double x_contribute = x;
//        // 在对 N 进行二进制拆分的同时计算答案
//        while (N > 0)
//        {
//            if (N % 2 == 1)
//            {
//                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
//                ans *= x_contribute;
//            }
//            // 将贡献不断地平方
//            x_contribute *= x_contribute;
//            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
//            N /= 2;
//        }
//        return ans;
//    }
//
//    double myPow(double x, int n)
//    {
//        long long N = n;
//        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
//    }
//};












/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/

//递归
//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution
//{
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
//    {
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        else if (list2 == nullptr)
//        {
//            return list1;
//        }
//        else if (list1->val < list2->val)
//        {
//            list1->next = mergeTwoLists(list1->next, list2);
//            return list1;
//        }
//        else
//        {
//            list2->next = mergeTwoLists(list1, list2->next);
//            return list2;
//        }
//    }
//};




//迭代
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
//    {
//        ListNode* preHead = new ListNode(-1);
//        ListNode* prev = preHead;
//        while (list1 != nullptr && list2 != nullptr)
//        {
//            if (list1->val < list2->val)
//            {
//                prev->next = list1;
//                list1 = list1->next;
//            }
//            else
//            {
//                prev->next = list2;
//                list2 = list2->next;
//            }
//            prev = prev->next;
//        }
//        // 合并后 list1 和 list2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
//        prev->next = list1 == nullptr ? list2 : list1;
//        return preHead->next;
//    }
//};













/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/

//递归
//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution
//{
//public:
//	ListNode* removeElements(ListNode* head, int val)
//	{
//		if (head == nullptr) return head;
//		head->next = removeElements(head->next, val);
//		return head->val == val ? head->next : head;
//	}
//};




//迭代
//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution
//{
//public:
//    ListNode* removeElements(ListNode* head, int val)
//	{
//        struct ListNode* dummyHead = new ListNode(0, head);
//        struct ListNode* temp = dummyHead;
//        while (temp->next != NULL)
//		{
//            if (temp->next->val == val)
//			{
//                temp->next = temp->next->next;
//            }
//            else
//			{
//                temp = temp->next;
//            }
//        }
//        return dummyHead->next;
//    }
//};









/*
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。
*/

//暴力破解
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    bool isPerfectSquare(int num)
//    {
//        for (long long i = 1; i <= num ; ++i)
//        {
//            if (i * i == (long long)num)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.isPerfectSquare(1);
//	return 0;
//}



//二分查找
//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    bool isPerfectSquare(int num)
//    {
//        int left = 0, right = num;
//        while (left <= right)
//        {
//            int mid = (right - left) / 2 + left;
//            long square = (long)mid * mid;
//            if (square < num)
//            {
//                left = mid + 1;
//            }
//            else if (square > num)
//            {
//                right = mid - 1;
//            }
//            else
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.isPerfectSquare(16);
//    return 0;
//}












/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作
*/

//#include<iostream>
//#include<stack>
//using namespace std;
//class MyQueue
//{
//public:
//    MyQueue() = default;
//    void push(int x)
//    {
//        st_in.push(x);
//    }
//    int pop()
//    {
//        if (!st_out.empty())
//        {
//            int val = st_out.top();
//            st_out.pop();
//            return val;
//        }
//        else
//        {
//            while (!st_in.empty())
//            {
//                int val = st_in.top();
//                st_in.pop();
//                st_out.push(val);
//            }
//            if (!st_out.empty())
//            {
//                int val = st_out.top();
//                st_out.pop();
//                return val;
//            }
//            return -1;
//        }
//    }
//    int peek()
//    {
//        if (!st_out.empty())
//        {
//            int val = st_out.top();
//            return val;
//        }
//        else
//        {
//            while (!st_in.empty())
//            {
//                int val = st_in.top();
//                st_in.pop();
//                st_out.push(val);
//            }
//            if (!st_out.empty())
//                return st_out.top();
//            return -1;
//        }
//    }
//    bool empty()
//    {
//        if (st_in.empty() && st_out.empty())
//        {
//            return true;
//        }
//        return false;
//    }
//private:
//    stack<int> st_in;
//    stack<int> st_out;
//};






///*
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//*/
//
///*
//在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。
//这样一来，我们就不需要对头节点进行特殊的判断了
//我们可以从哑节点开始遍历 L−n+1 个节点。当遍历到第 L-n+1L−n+1 个节点时，它的下一个节点就是我们需要删除的节点，
//这样我们只需要修改一次指针，就能完成删除操作
//*/
//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution
//{
//public:
//    int getLength(ListNode* head)
//    {
//        int length = 0;
//        while (head)
//        {
//            ++length;
//            head = head->next;
//        }
//        return length;
//    }
//    ListNode* removeNthFromEnd(ListNode* head, int n)
//    {
//        ListNode* dummy = new ListNode(0, head);
//        int length = getLength(head);
//        ListNode* cur = dummy;
//        for (int i = 1; i < length - n + 1; ++i)
//        {
//            cur = cur->next;
//        }
//        cur->next = cur->next->next;
//        ListNode* ans = dummy->next;
//        delete dummy;
//        return ans;
//    }
//};













/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    
//    vector<vector<int>> permute(vector<int>& nums)
//    {
//        vector<int> temp;
//        dfs(nums, temp);
//        return ret;
//    }
//private:
//    vector<vector<int>>ret;
//    void dfs(vector<int>& nums, vector<int>& temp)
//    {
//        if (temp.size() == nums.size())
//        {
//            ret.push_back(temp);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (count(temp.begin(), temp.end(), nums[i])) continue;
//            temp.push_back(nums[i]);
//            dfs(nums, temp);
//            temp.pop_back();
//        }
//    }
//};
//int main()
//{
//    vector<int>v{ 0,1 };
//    Solution s;
//    vector<vector<int>>ret = s.permute(v);
//    for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); ++it)
//    {
//        for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); ++its)
//        {
//            cout << *its << " ";
//        }
//        cout << endl;
//    }
//
//    for_each(ret.begin(), ret.end(), [&](vector<int>temp) {
//        for_each(temp.begin(), temp.end(), [&](int n) {
//            cout << n << " ";
//            });
//        cout << endl;
//        });
//    return 0;
//}












/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>> ret(numRows);
//        for (int i = 0; i < numRows; ++i)
//        {
//            ret[i].resize(i + 1);//每行大小设置
//            ret[i][0] = ret[i][i] = 1;//每行第一个和最后一个元素都为1，其他元素也暂时赋值为1
//            for (int j = 1; j < i; ++j)
//            {
//                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];//元素的值等于 上一行该位置的值 加 上一行对应位置前一个的值
//            }
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<vector<int>>v = s.generate(5);
//    for_each(v.begin(), v.end(), [&](vector<int>temp) {
//        for_each(temp.begin(), temp.end(), [&](int num) {
//            cout << num << " ";
//            });
//        cout << endl;
//        });
//	return 0;
//}







//#include<iostream>
//using namespace std;
//int main()
//{
//	char ret;
//	while (1)
//	{
//		cout << "现在正在下雨吗?(请输入'Y'或'N'):";
//		cin >> ret;
//		if (ret == 'Y')
//		{
//			cout << "现在正在下雨";
//			break;
//		}
//		else if(ret == 'N')
//		{
//			cout << "现在没有下雨";
//			break;
//		}
//	}
//	return 0;
//}





//#include<iostream>
//using namespace std;
//int main()
//{
//	int ret;
//	cout << "你考试考了多少分?(0-100)" << endl;
//	cin >> ret;
//	if (ret >= 90 && ret <= 100)
//	{
//		cout << "优" << endl;
//	}
//	else if (ret >= 80 && ret < 90)
//	{
//		cout << "良" << endl;
//	}
//	else if(ret >= 60 && ret < 80)
//	{
//		cout << "中" << endl;
//	}
//	else if (ret >= 0 && ret < 60)
//	{
//		cout << "差" << endl;
//	}
//	else
//	{
//		cout << "输入错误,请输入0到100之间的数字" << endl;
//	}
//	return 0;
//}




//#include<iostream>
//using namespace std;
//int main()
//{
//	int intOne;
//	int& rSomeRef = intOne;
//	intOne = 5;
//	cout << "intOne:\t" << intOne << endl;
//	cout << "rSomeRef:\t" << rSomeRef << endl;
//
//	int intTwo = 8;
//	rSomeRef = intTwo;
//	cout << "\nintOne:\t" << intOne << endl;
//	cout << "intTwo:\t" << intTwo << endl;
//	cout << "rSomeRef:\t" << rSomeRef << endl;
//	system("pause");//阻塞
//	return 0;
//}

//intOne:	5
//rSomeRef:	5
//
//intOne:	8
//intTwo:	8
//rSomeRef:	8








//#include<iostream>
//#include<string>
//using namespace std;
//void test(int a)
//{
//	cout << a << endl;
//}
//void test(double b)
//{
//	cout << b << endl;
//}
//void test(string b)
//{
//	cout << b << endl;
//}
//int main() {
//	test(6);
//	test(6.01);
//	test("六点零");
//	system("pause");
//	return 0;
//}

//6
//6.01
//六点零



/*
编写函数把华氏温度转化为相应的摄氏温度，公式为 C = 5(F-32)/9，在主程序中提示
用户输入一个华氏温度，转化后输出相应的摄氏温度，保留两位小数
*/
//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//	double fahrenheit;
//	cin >> fahrenheit;
//	double C_temperature = 5 * (fahrenheit - 32) / 9;
//	cout << setiosflags(ios::fixed) << setprecision(2) << C_temperature<< endl;
//	return 0;
//}









//#include<iostream>
//using namespace std;
//void swap(int& a, int& b)
//{
//	if (a > b)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//}
//int main()
//{
//	int num1, num2;
//	cin >> num1 >> num2;
//	swap(num1, num2);
//	cout << num1 << " " << num2 << endl;
//	return 0;
//}




//#include<iostream>
//using namespace std;
//class B
//{
//public:
//	B() {}
//	B(int i, int j)
//	{
//		x = i;
//		y = j;
//	}
//	void printb()
//	{
//		cout << x << " " << y << endl;
//	}
//private:
//	int x, y;
//};
//class A
//{
//public:
//	A() {}
//	A(int I, int J);
//	void printa();
//private:
//	B c;
//};
//A::A(int i, int j) :c(i, j)
//{}
//void A::printa()
//{
//	c.printb();
//}
//int main()
//{
//	A a(10, 20);
//	a.printa();
//	return 0;
//}







//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void set(int i, int j)
//	{
//		x = i;
//		y = j;
//	}
//	int get_y()
//	{
//		return y;
//	}
//private:
//	int x, y;
//};
//class box
//{
//public:
//	void set(int l, int w, int s, int p)
//	{
//		length = l;
//		width = w;
//		label.set(s, p);
//	}
//	int get_area()
//	{
//		return length * width;
//	}
//private:
//	int length, width;
//	A label;
//};
//int main()
//{
//	box b;
//	b.set(4, 6, 1, 20);
//	cout << b.get_area() << endl;
//	return 0;
//}




//#include<iostream>
//using namespace std;
//class counter
//{
//public:
//	counter(int number);
//	void increment(); //给原值+1
//	void decrement(); //给原值-1
//	int getvalue(); //取得计数器值
//	int print(); //显示计数
//private:
//	int value;
//};
//counter::counter(int num)
//{
//	this->value = num;
//}
//void counter::increment()
//{
//	++this->value;
//}
//void counter::decrement()
//{
//	--this->value;
//}
//int counter::getvalue()
//{
//	return this->value;
//}
//int counter::print()
//{
//	cout << this->value << endl;
//	return 0;
//}
//int main()
//{
//	counter a(10);
//	a.increment();
//	a.print();
//	return 0;
//}











/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
////1.
//class Solution
//{
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
//    {
//        sort(nums1.begin(), nums1.end());
//        sort(nums2.begin(), nums2.end());
//        vector<int>nums3;
//        vector<int>ret;
//        nums3.resize(min(nums1.size(), nums2.size()));
//        vector<int>::iterator itend = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());//程序在这一行崩溃
//        for_each(nums3.begin(), itend, [&](int val){
//            ret.push_back(val);
//            });
//        return ret;
//    }
//};
////2.
//class Solution
//{
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
//    {
//        sort(nums1.begin(), nums1.end());
//        sort(nums2.begin(), nums2.end());
//        int length1 = nums1.size(), length2 = nums2.size();
//        vector<int> intersection;
//        int index1 = 0, index2 = 0;
//        while (index1 < length1 && index2 < length2)
//        {
//            if (nums1[index1] < nums2[index2])
//            {
//                index1++;
//            }
//            else if (nums1[index1] > nums2[index2])
//            {
//                index2++;
//            }
//            else
//            {
//                intersection.push_back(nums1[index1]);
//                index1++;
//                index2++;
//            }
//        }
//        return intersection;
//    }
//};
//int main()
//{
//    vector<int>nums1{ 1,2,2,1 };
//    vector<int>nums2{2,2};
//    Solution s;
//    vector<int>ret = s.intersect(nums1, nums2);
//    for_each(ret.begin(), ret.end(), [=](int val) {
//        cout << val << " ";
//        });
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//	int Get_Max(int a, int b, int c)
//	{
//		int max = a;
//		if (max < b)
//			max = b;
//		if (max < c)
//			max = c;
//		return max;
//	}
//};
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	Solution s;
//	int max = s.Get_Max(a,b,c);
//	cout << "最大值为" << max << endl;
//	return 0;
//}





//#include<iostream>
//#include<string>
//using namespace std;
//class Base
//{
//public:
//	void setx(int n)
//	{
//		x = n;
//	}
//	void showx()
//	{
//		cout << x << endl;
//	}
//private:
//	int x;
//};
//class Derived :private Base
//{
//public: 
//	void setxy(int n, int m)
//	{ 
//		setx(n);
//		y = m;
//	}
//	void showxy()
//	{ 
//		this->showx();
//		cout << y << endl; 
//	}
//private:
//	int y;
//};
//int main()
//{
//	Derived obj; 
//	obj.setxy(20, 30); 
//	obj.showxy();
//	return 0;
//}






//#include<iostream> 
//#include<string> 
//using namespace std; 
//class Base
//{
//public:
//	void seta(int sa)
//	{
//		a = sa;
//	}
//	void showa()
//	{
//		cout << "a = " << a << endl;
//	}
//protected:
//	int a;
//};
//class Derived1 :private Base
//{
//public:
//
//	void setab(int sa, int sd)
//	{
//		a = sa;
//		b = sd;
//	}
//	void showab()
//	{
//		this->showa();
//		cout << "b = " << b << endl;
//	}
//protected:
//	int b;
//};
//class Derived2 :private Derived1
//{
//public:
//	void setabc(int sa, int sd, int sc)
//	{
//		setab(sa, sd);
//		c = sc;
//	}
//	void showabc()
//	{
//		this->showab();
//		cout << "c = " << c << endl;
//	}
//private:
//	int c;
//};
//int main()
//{
//	Base op1;
//	op1.seta(1);
//	op1.showa();
//	Derived1 op2;
//	op2.setab(2, 3);
//	op2.showab();
//	Derived2 op3;
//	op3.setabc(4, 5, 6);
//	op3.showabc();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Constructing base class\n";
//	}~Base()
//	{
//		cout << "Destructing base class\n";
//	}
//};
//class Derived :public Base
//{
//public:
//	Derived()
//	{
//		cout << "Constructing derived class" << endl;
//	}~Derived()
//	{
//		cout << "Destructing derived class" << endl;
//	}
//};
//int main()
//{
//	Derived obj;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//class Student
//{
//public:
//	Student(int number1, string name1, float score1)
//	{
//		number = number1;
//		name = name1;
//		score = score1;
//	}
//	void print()
//	{
//		cout << "number:" << number << endl;
//		cout << "name:" << name << endl;
//		cout << "score:" << score << endl;
//	}
//protected:
//	int number;
//	string name;
//	float score;
//};
//class UStudent :public Student
//{
//public:
//	UStudent(int number1, string name1, float score1, string
//		major1) :Student(number1, name1, score1)
//	{
//		major = major1;
//	}
//	void printl()
//	{
//		print();
//		cout << "major:" << major << endl;
//	}
//private:
//	string major;
//};
//int main()
//{
//	UStudent stu(22116, "张志", 95, "面向对象程序设计实验");
//	stu.printl();
//	return 0;
//}
















/*
建立 cylinder，cylinder 的构造函数被传递了两个 double 值，分别表示圆柱体的半径和
高度。用 cylinder 计算圆柱体的体积，并存储在一个 double 变量中。在类 cylinder 中包含一
个成员函数 vol，用来显示每个 cylinder
*/
//#include<iostream>
//using namespace std;
//const double pi = 3.14;
//class cylinder
//{
//public:
//	cylinder(double r, double h)
//	{
//		this->m_V = pi * r * r * h;
//	}
//	void vol()
//	{
//		cout << "体积为" << this->m_V << endl;
//	}
//private:
//	double m_V;
//};
//int main()
//{
//	cylinder c(3.1, 4.1);
//	c.vol();
//	return 0;
//}








/*
构建一个类 book，其中含有两个私有数据成员 qu 和 price，将 qu 初始化为 1~5，将 price
初始化为 qu 的 10 倍，建立一个有 5 个元素的数组对象。显示每个对象数组元素的 qu*price
值。
*/
//#include<iostream>
//using namespace std;
//class Book
//{
//public:
//	Book(int q)
//	{
//		this->qu = q;
//		this->price = q * 10;
//	}
//	int get_qp()
//	{
//		return this->price * this->qu;
//	}
//private:
//	int qu;
//	int price;
//};
//int main()
//{
//	Book arr[5] = { Book(1),Book(2),Book(3),Book(4),Book(5) };
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << arr[i].get_qp() << endl;
//	}
//	return 0;
//}






/*
通过对象指针访问对象数组，使程序以相反的顺序显示每个对象数组元素
的 qu*price 值
*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Book
//{
//public:
//	Book(int q)
//	{
//		this->qu = q;
//		this->price = q * 10;
//	}
//	int get_qp()
//	{
//		return this->price * this->qu;
//	}
//private:
//	int qu;
//	int price;
//};
//int main()
//{
//	Book arr[5] = {Book(1),Book(2),Book(3),Book(4),Book(5)};
//	for (Book* ptr = arr + 4; ptr != arr; --ptr)
//	{
//		cout << (*ptr).get_qp() << endl;
//	}
//	return 0;
//}







//#include<iostream>
//#include<string>
//using namespace std;
//class Student
//{
//public:
//	Student(int number1, string name1, float score1)
//	{
//		number = number1;
//		name = name1;
//		score = score1;
//	}
//	void print()
//	{
//		cout << "学号：" << number << endl;
//		cout << "姓名：" << name << endl;
//		cout << "成绩：" << score << endl;
//	}
//protected:
//	int number;
//	string name;
//	float score;
//};
//class UStudent :public Student
//{
//public:
//	UStudent(int number1, string name1, float score1, int number2, string name2, float
//		score2, int number3, string name3, float score3, string major1)
//		:Student(number1, name1, score1), auditor2(number3, name3, score3), auditor1(number2, name2, score2)
//	{
//		major = major1;
//	}
//	void print()
//	{
//		cout << "正式生是：" << endl;
//		Student::print();
//		cout << "专业：" << major << endl;
//	}
//	void print_auditor1()
//	{
//		cout << "旁听生是：" << endl;
//		auditor1.print();
//	}
//	void print_auditor2()
//	{
//		cout << "旁听生是：" << endl;
//		auditor2.print();
//	}
//private:
//	string major;
//	Student auditor1;
//	Student auditor2;
//};
//int main()
//{
//	UStudent stu(2001, "张志", 95, 3001, "王大宝", 66, 3002, "李倩倩", 50, "面向对象程序设计");
//	stu.print();
//	stu.print_auditor1();
//	stu.print_auditor2();
//	return 0;
//}





//#include<iostream>
//using namespace std;
//class B1
//{
//public:
//	B1(int i)
//	{
//		b1 = i;
//		cout << "Constructor B1." << endl;
//	}
//	void print()
//	{
//		cout << b1 << endl;
//	}
//private:
//	int b1;
//};
//class B2
//{
//public:
//	B2(int i)
//	{
//		b2 = i;
//		cout << "Constructor B2." << endl;
//	}
//	void print()
//	{
//		cout << b2 << endl;
//	}
//private:
//	int b2;
//};
//class A :public B2, public B1
//{
//public:
//	A(int i, int j, int l);
//	void print();
//private:
//	int a;
//};
//A::A(int i, int j, int l) :B1(i), B2(j)
//{
//	a = l;
//	cout << "Constructor A1." << endl;
//}
//void A::print()
//{
//	B1::print();
//	B2::print();
//	cout << a << endl;
//}
//int main()
//{
//	A aa(50, 60, 70);
//	aa.print();
//	return 0;
//}


//#include<iostream>
//#include<iomanip>
//using namespace std;
//inline double f(double x)
//{
//	return 2 * x * x * x - 4 * x * x + 3 * x - 6;
//}
//double SeachRet(double a, double b, double n)
//{
//	if (f(a) * f(b) > 0)
//		return 0;
//	while (1)
//	{
//		double x = (a + b) * 0.5;
//		double y = abs(f(x));
//		if (y < n)
//			return x;
//		if (f(x) * f(b) < 0)
//			a = x;
//		else
//			b = x;
//	}
//}
//int main()
//{
//	double a, b;
//	cout << "输入区间范围:";
//	cin >> a >> b;
//	double m = SeachRet(a, b, 0.001);
//	int i = 0;
//	cout << "函数 f(x) = 2x^3 - 4x^2 + 3x - 6 在区间[" << a << "," << b << "]上的根为：";
//	cout << setiosflags(ios::fixed) << setprecision(3) << m << endl;
//	return 0;
//}








//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char* p = (char*)malloc(123 * sizeof(char));
//	if (p != nullptr)
//	{
//		memset(p, 0x000,13);
//		memcpy(p, "hello world!\0", sizeof("hello world!"));
//	}
//	cout << p << endl;
//	printf("%p", p);
//	return 0;
//}


//#include<iostream>
//#include<cmath>
//using namespace std;
//inline float f(float x)
//{
//	return 2 * x * x * x - 4 * x * x + 3 * x - 6;
//}
//int main()
//{
//	float left, right, middle, ym, yl, yr;
//	cout << "please two number:" << endl;
//	cin >> left >> right;
//	yl = f(left);
//	yr = f(right);
//	do
//	{
//		middle = (right + left) / 2;
//		ym = f(middle);
//		if (yr * ym > 0)
//		{
//			right = middle;
//			yr = ym;
//		}
//		else
//		{
//			left = middle;
//			yl = ym;
//		}
//	} while (fabs(ym) > 1e-6);
//	cout << "\nRoot is:" << middle;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	static int a;
//	void init()
//	{
//		a = 1;
//	}
//	A(int a = 2)
//	{
//		init();
//		a++;
//	}
//};
//int A::a = 0;
//A obj;
//int main()
//{
//	cout << obj.a;//1
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Point
//{
//public:
//	static int numbers;
//public:
//	Point()
//	{
//		numbers++;
//	}
//	~Point()
//	{
//		numbers--;
//	}
//};
//int Point::numbers = 0;
//int main()
//{
//	Point* ptr;
//	Point A, B;
//	{
//		Point* ptr_point = new Point[3];
//		ptr = ptr_point;
//	}
//	Point C;
//	cout << Point::numbers << endl;
//	delete[] ptr;
//	return 0;
//}







//#include<iostream>
//using namespace std;
//class Myclass
//{
//public:
//	Myclass()
//	{
//		cout << 1;
//	}
//};
//int main()
//{
//	Myclass a, b[2], * p[2];
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class test
//{
//private:
//	int a;
//public:
//	test()
//	{
//		cout << "constructor" << endl;
//	}
//	test(int a) { cout << a << endl; }
//	test(const test& _test)
//	{
//		a = _test.a;
//		cout << "copy constructor" << endl;
//	}
//	~test() { cout << "destructor" << endl; }
//};
//int main()
//{
//	test A(3);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	Base(int x = 0)
//	{
//		cout << x;
//	}
//};
//class Derived:public Base
//{
//public:
//	Derived(int x = 0)
//	{
//		cout << x;
//	}
//private:
//	Base val;
//};
//int main()
//{
//	Derived d(1);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class B
//{
//	void fun1() {}
//protected:
//	double var;
//public:
//	void fun2() {}
//};
//class D :public B
//{
//protected:
//	void func3() {}
//};
//int main()
//{
//	D obj;
//	obj.fun2();
//}



//#include<iostream>
//using namespace std;
//class Part
//{
//public:
//	Part(int x = 0):val(x)
//	{
//		cout << val;
//	}
//	~Part()
//	{
//		cout << val;
//	}
//private:
//	int val;
//};
//class Whole
//{
//public:
//	Whole(int x, int y, int z = 0) :p2(x), p1(y), val(z)
//	{
//		cout << val;
//	}
//	~Whole()
//	{
//		cout << val;
//	}
//private:
//	Part p1, p2;
//	int val;
//};
//int main()
//{
//	Whole obj(1, 2, 3);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//	Test() {}
//	Test(const Test& t)
//	{
//		cout << 1;
//	}
//};
//Test fun(Test& u)
//{
//	Test t = u;
//	return t;
//}
//int main()
//{
//	Test x, y;
//	x = fun(y);
//	return 0;
//}


//#include<iostream>
//#include<iomanip>
//using namespace std;
//class Myclass
//{
//public:
//	Myclass()
//	{
//		cout << 'A';
//	}
//	Myclass(char c)
//	{
//		cout << c;
//	}
//	~Myclass()
//	{
//		cout << 'B';
//	}
//};
//int main()
//{
//	Myclass p1, * p2;
//	p2 = new Myclass('X');
//	delete p2;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int i = 0;
//class Fun
//{
//public:
//	static int i;
//	int value()
//	{
//		return i - 1;
//	}
//	int value()const
//	{
//		return i + 1;
//	}
//};
//int Fun::i = 2;
//int main()
//{
//	int i = 3;
//	Fun fun1;
//	const Fun fun2;
//	cout << fun1.value() << Fun::i << fun2.value();
//	return 0*/;
//}


//#include<iostream>
//using namespace std;
//class Obj
//{
//	static int i;
//public:
//	Obj()
//	{
//		i++;
//	}
//	~Obj()
//	{
//		i--;
//	}
//	static int getVal()
//	{
//		return i;
//	}
//};
//int Obj::i = 0;
//void f()
//{
//	Obj ob2;
//	cout << ob2.getVal();
//}
//int main()
//{
//	Obj ob1;
//	f();
//	Obj* ob3 = new Obj;
//	cout << ob3->getVal();
//	delete ob3;
//	cout << Obj::getVal();
//	return 0;
//}





//#include<iostream>
//#define MAX 1024
//using namespace std;
//template<class type>
//class Solution
//{
//public:
//	Solution()
//	{
//		arr[0] = 0;
//		this->size = 0;
//	}
//	type getMax()//获取最大值
//	{
//		type max = arr[0];
//		for (int i = 0; i < size; ++i)
//		{
//			if (max < arr[i])
//				max = arr[i];
//		}
//		return max;
//	}
//	void push_back(type temp)//尾插
//	{
//		if (MAX > size)
//		{
//			++size;
//			arr[size - 1] = temp;
//		}
//	}
//	void MySort()//排序
//	{
//		for (int i = 1; i < size; ++i)
//		{
//			for (int j = 0; j < size - i; ++j)
//			{
//				if (arr[j] > arr[j+1])
//				{
//					type temp = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = temp;
//				}
//			}
//		}
//	}
//	void forEach()
//	{
//		for (int i = 0; i < size; ++i)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//private:
//	type arr[MAX];
//	int size;
//};
//int main()
//{
//	Solution<int> s;
//	for (int i = 0; i < 10; ++i)
//	{
//		s.push_back(10 - i);//插入数据10-1
//	}
//	s.MySort();//从小到大排序
//	s.forEach();//遍历输出数组
//	cout<<s.getMax();//输出最大值
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<list>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	vector<int>v;
//	list<int>l;
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		int temp = 0;
//		cin >> temp;
//		v.push_back(temp);
//		l.push_back(temp);
//	}
//
//	sort(v.begin(), v.end());
//	l.sort();
//
//	for_each(v.begin(), v.end(), [&](int val) {
//		cout << val << " ";
//		});
//	cout << endl;
//	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A1";
//	}
//	void func2()
//	{
//		cout << "A2";
//	}
//};
//class B :public A
//{
//public:
//	void func1()
//	{
//		cout << "B1";
//	}
//	void func2()
//	{
//		cout << "B2";
//	}
//};
//int main()
//{
//	A* p = new B;
//	p->func1();
//	p->func2();
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class Base
//{
//protected:
//	Base()
//	{
//		cout << 'A';
//	}
//	Base(char c)
//	{
//		cout << c;
//	}
//};
//class Derived :public Base
//{
//public:
//	Derived(char c)
//	{
//		cout << c;
//	}
//};
//int main()
//{
//	Derived d1('B');
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	void print() { cout << 'B'; }
//};
//class Derived :public Base
//{
//public:
//	void print() { cout << 'D'; }
//};
//int main()
//{
//	Derived* pd = new Derived();
//	Base* pb = pd;
//	pb->print();
//	pd->print();
//	delete pd;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	Base(int x = 0) :valB(x)
//	{
//		cout << valB;
//	}
//	~Base()
//	{
//		cout << valB;
//	}
//private:
//	int valB;
//};
//class Derived :public Base
//{
//public:
//	Derived(int x = 0, int y = 0) :Base(x), valD(y)
//	{
//		cout << valD;
//	}
//	~Derived()
//	{
//		cout << valD;
//	}
//private:
//	int valD;
//};
//int main()
//{
//	Derived obj(2, 3);
//	return 0;
//}




//#include<iostream>
//using namespace std;
//class B
//{
//public:
//	B(int xx) :x(xx)
//	{
//		++count;
//		x += 10;
//	}
//	virtual void show()const
//	{
//		cout << count << '_' << x << endl;
//	}
//protected:
//	static int count;
//private:
//	int x;
//};
//class D :public B
//{
//public:
//	D(int xx, int yy) :B(xx), y(yy)
//	{
//		++count;
//		y += 100;
//	}
//	virtual void show()const
//	{
//		cout << count << '_' << y << endl;
//	}
//private:
//	int y;
//};
//int B::count = 0;
//int main()
//{
//	B* ptr = new D(10, 20);
//	ptr->show();
//	delete ptr;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Base
//{
//	int a, b;
//public:
//	Base(int x, int y)
//	{
//		a = x;
//		b = y;
//	}
//	void show()
//	{
//		cout << a << ',' << b << endl;
//	}
//};
//class Derived :public Base
//{
//	int c, d;
//public:
//	Derived(int x, int y, int z, int m) :Base(x, y)
//	{
//		c = z;
//		d = m;
//	}
//	void show()
//	{
//		cout << c << ',' << d << endl;
//	}
//};
//int main()
//{
//	Base B1(50, 50), * pb;
//	Derived D1(10, 20, 30, 40);
//	pb = &D1;
//	pb->show();
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int i) { x = i; }
//	void dispa() { cout << x << ','; }
//private:
//	int x;
//};
//class B :public A
//{
//public:
//	B(int i) :A(i + 10) { x = i; }
//	void dispb() { dispa(); cout << x << endl; }
//private:
//	int x;
//};
//int main()
//{
//	B b(2);
//	b.dispb();
//	return 0;
//}







//T1
//#include<iostream>
//using namespace std;
//class Commodity
//{
//public:
//	Commodity()
//	{
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//	}
//	Commodity(long n, char* p, double e)
//	{
//		this->number = n;
//		this->p_name = p;
//		this->price = e;
//	}
//	Commodity(const Commodity& temp)
//	{
//		this->number = temp.number;
//		this->p_name = temp.p_name;
//		this->price = temp.price;
//	}
//	~Commodity()
//	{
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//	}
//private:
//	long number;//商品号
//	char* p_name;//商品名
//	double price;//商品价格
//};


//T2
//#include<iostream>
//using namespace std;
//class Commodity
//{
//	friend char* getName(Commodity& temp);
//public:
//	Commodity()
//	{
//		this->count = 0;
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//	}
//	Commodity(long n, char* p, double e,int c)
//	{
//		this->number = n;
//		this->p_name = p;
//		this->price = e;
//		this->count = c;
//	}
//	Commodity(const Commodity& temp)
//	{
//		this->number = temp.number;
//		this->p_name = temp.p_name;
//		this->price = temp.price;
//		this->count = temp.count;
//	}
//	int getCount()
//	{
//		return count;
//	}
//	~Commodity()
//	{
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//		this->count = 0;
//	}
//private:
//	long number;//商品号
//	char* p_name;//商品名
//	double price;//商品价格
//	int count;//商品总数
//};
//char* getName(Commodity& temp)
//{
//	return temp.p_name;
//}




//T3
//#include<iostream>
//using namespace std;
//class Commodity
//{
//	friend char* getName(Commodity& temp);
//public:
//
//	bool operator<(const Commodity& temp)const
//	{
//		return (this->price < temp.price);
//	}
//	bool operator>=(const Commodity& temp)const
//	{
//		return this->price >= temp.price;
//	}
//
//	Commodity()
//	{
//		this->count = 0;
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//	}
//	Commodity(long n, char* p, double e, int c)
//	{
//		this->number = n;
//		this->p_name = p;
//		this->price = e;
//		this->count = c;
//	}
//	Commodity(const Commodity& temp)
//	{
//		this->number = temp.number;
//		this->p_name = temp.p_name;
//		this->price = temp.price;
//		this->count = temp.count;
//	}
//	int getCount()
//	{
//		return count;
//	}
//	~Commodity()
//	{
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//		this->count = 0;
//	}
//private:
//	long number;//商品号
//	char* p_name;//商品名
//	double price;//商品价格
//	int count;//商品总数
//};
//char* getName(Commodity& temp)
//{
//	return temp.p_name;
//}
//int main()
//{
//	Commodity obj1((long)1, (char*)"haha", 10, 10), obj2((long)2, (char*)"hehe", 20, 20);
//	cout << (obj1 >= obj2) << endl;
//	return 0;
//}




//T4
//#include<iostream>
//using namespace std;
//class Commodity
//{
//	friend char* getName(Commodity& temp);
//public:
//
//	bool operator<(const Commodity& temp)const
//	{
//		return (this->price < temp.price);
//	}
//	bool operator>=(const Commodity& temp)const
//	{
//		return this->price >= temp.price;
//	}
//
//	Commodity()
//	{
//		this->count = 0;
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//	}
//	Commodity(long n, char* p, double e, int c)
//	{
//		this->number = n;
//		this->p_name = p;
//		this->price = e;
//		this->count = c;
//	}
//	Commodity(const Commodity& temp)
//	{
//		this->number = temp.number;
//		this->p_name = temp.p_name;
//		this->price = temp.price;
//		this->count = temp.count;
//	}
//	int getCount()
//	{
//		return count;
//	}
//	~Commodity()
//	{
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//		this->count = 0;
//	}
//private:
//	long number;//商品号
//	char* p_name;//商品名
//	double price;//商品价格
//	int count;//商品总数
//};
//class CClothes:public Commodity//服装类
//{
//public:
//	CClothes(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
//	{
//		this->p_brand = cl;
//	}
//	void usedFor()
//	{
//		cout << "服装可用于穿" << endl;
//	}
//	~CClothes()
//	{
//		this->p_brand = nullptr;
//	}
//private:
//	char* p_brand;//品牌
//};
//class CFood:public Commodity//食品类
//{
//public:
//	CFood(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
//	{
//		this->p_brand = cl;
//	}
//	void usedFor()
//	{
//		cout << "食品可用于吃" << endl;
//	}
//	~CFood()
//	{
//		this->p_brand = nullptr;
//	}
//private:
//	char* p_brand;//品牌
//};
//
//char* getName(Commodity& temp)
//{
//	return temp.p_name;
//}
//
//int main()
//{
//	Commodity obj1((long)1, (char*)"haha", 10, 10), obj2((long)2, (char*)"hehe", 20, 20);
//	cout << (obj1 >= obj2) << endl;
//	return 0;
///}





//T5
//#include<iostream>
//using namespace std;
//class Commodity
//{
//	friend char* getName(Commodity& temp);
//public:
//
//	bool operator<(const Commodity& temp)const
//	{
//		return (this->price < temp.price);
//	}
//	bool operator>=(const Commodity& temp)const
//	{
//		return this->price >= temp.price;
//	}
//
//	Commodity(long n, char* p, double e, int c)
//	{
//		this->number = n;
//		this->p_name = p;
//		this->price = e;
//		this->count = c;
//
//		++total_goods;
//		total_price += e;
//	}
//	Commodity(const Commodity& temp)
//	{
//		this->number = temp.number;
//		this->p_name = temp.p_name;
//		this->price = temp.price;
//		this->count = temp.count;
//
//		++total_goods;
//		total_price += this->price;
//	}
//	int getCount()
//	{
//		return count;
//	}
//
//	long getTotalGoods()
//	{
//		return this->total_goods;
//	}
//	double getTotalPrice()
//	{
//		return this->total_price;
//	}
//	virtual void usedFor() = 0;
//
//	~Commodity()
//	{
//		this->number = 0;
//		this->p_name = nullptr;
//		this->price = 0.0;
//		this->count = 0;
//	}
//private:
//	long number;//商品号
//	char* p_name;//商品名
//	double price;//商品价格
//	int count;//商品总数
//
//	static long total_goods;//总商品数
//	static double total_price;//商品总价格
//};
//class CClothes :public Commodity//服装类
//{
//public:
//	CClothes(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
//	{
//		this->p_brand = cl;
//	}
//	void usedFor()
//	{
//		cout << "服装可用于穿" << endl;
//	}
//	~CClothes()
//	{
//		this->p_brand = nullptr;
//	}
//private:
//	char* p_brand;//品牌
//};
//class CFood :public Commodity//食品类
//{
//public:
//	CFood(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
//	{
//		this->p_brand = cl;
//	}
//	void usedFor()
//	{
//		cout << "食品可用于吃" << endl;
//	}
//	~CFood()
//	{
//		this->p_brand = nullptr;
//	}
//private:
//	char* p_brand;//品牌
//};
//
//char* getName(Commodity& temp)
//{
//	return temp.p_name;
//}
//long Commodity::total_goods = 0;
//double Commodity::total_price = 0.0;
//int main()
//{
//	Commodity* ptr = new CClothes((long)111, (char*)"卫衣", 500, 10,(char*)"耐克");
//	ptr->usedFor();
//	Commodity* ptr2 = new CClothes((long)222, (char*)"卫衣", 200, 5, (char*)"匹克");
//	cout << (*ptr >= *ptr2) << endl;
//	return 0;
//}



//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//	cout << setprecision(3) << fixed << setfill('*') << setw(8);
//	cout << 12.345 << setw(8) << 34.567;
//	return 0;
//}




//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	int m;
//	int* p = &m;
//	void show()
//	{
//		cout << m << endl;
//	}
//};
//int main()
//{
//	A A1;
//	*A1.p = 5;  //.比*优先级高，相当于*(A1.p)=5
//	A1.show();
//}



//#include <iostream>
//using namespace std;
//class A {
//	int* q;
//public:
//	int m;
//};
//int main()
//{
//	A A1;
//	int A::* p = &A::m;  // 对象的对象非静态成员指针
//	A1.*p = 5;
//	cout << A1.m << endl;
//	return 0;
//}




//#include<iostream>
//#include<cstring>
//using namespace std;
//class String
//{
//public:
//	String(char* pstr);
//	friend ostream& operator<<(ostream& out, String s);
//private:
//	char* str;
//	int size;
//};
//String::String(char* pstr)
//{
//	str = pstr;
//	size = strlen(pstr);
//}
//ostream& operator<<(ostream& out, String s)
//{
//	out << s.str;
//	return out;
//}
//int main()
//{
//	char arr[] = { 'h','z','x','y','\0' };
//	char* p = arr;
//	String obj(p);
//	cout << obj << endl;
//	return 0;
//}










//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//typedef int QDataType;
//typedef struct QueueNode
//{
//    QDataType data;
//    struct QueueNode* next;
//}QNode;
//typedef struct Queue
//{
//    QNode* head;
//    QNode* tail;
//}Queue;
//
//void QueueInit(Queue* pq)
//{
//    assert(pq);
//    pq->head = pq->tail = NULL;
//}
//void QueueDestory(Queue* pq)
//{
//    assert(pq);
//    QNode* cur = pq->head;
//    while (cur != NULL)
//    {
//        QNode* next = cur->next;
//        free(cur);
//        cur = next;
//    }
//    pq->head = pq->tail = NULL;
//}
//void QueuePush(Queue* pq, QDataType d)//队尾入
//{
//    assert(pq);
//    QNode* newNode = (QNode*)malloc(sizeof(QNode));
//    if (newNode == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    newNode->next = NULL;
//    newNode->data = d;
//
//    if (pq->tail == NULL)
//    {
//        pq->head = pq->tail = newNode;
//    }
//    else
//    {
//        pq->tail->next = newNode;
//        pq->tail = newNode;
//    }
//}
//void QueuePop(Queue* pq)//队头出
//{
//    assert(pq);
//    assert(pq->head);//队列不为空
//    if (pq->head->next == NULL)//只有一个结点的情况
//    {
//        free(pq->head);
//        pq->head = pq->tail = NULL;
//    }
//    else
//    {
//        QNode* next = pq->head->next;
//        free(pq->head);
//        pq->head = next;
//    }
//}
//QDataType QueueFront(Queue* pq)
//{
//    assert(pq);
//    assert(pq->head);
//    return pq->head->data;
//}
//QDataType QueueBack(Queue* pq)
//{
//    assert(pq);
//    assert(pq->tail);
//    return pq->tail->data;
//}
//int QueueSize(Queue* pq)
//{
//    assert(pq);
//    int size = 0;
//    QNode* cur = pq->head;
//    while (cur != NULL)
//    {
//        ++size;
//        cur = cur->next;
//    }
//    return size;
//}
//bool QueueIsEmpty(Queue* pq)
//{
//    assert(pq);
//    return pq->head == NULL;
//}
//
//typedef struct {
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
//    if (ps == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    QueueInit(&ps->q1);
//    QueueInit(&ps->q2);
//    return ps;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    if (!QueueIsEmpty(&obj->q1))
//    {
//        QueuePush(&obj->q1, x);
//    }
//    else
//    {
//        QueuePush(&obj->q2, x);
//    }
//}
//
//int myStackPop(MyStack* obj) {
//    Queue* emptyQ = &obj->q1;
//    Queue* noemptyQ = &obj->q2;
//    if (!QueueIsEmpty(&obj->q1))
//    {
//        emptyQ = &obj->q2;
//        noemptyQ = &obj->q1;
//    }
//    while (QueueSize(noemptyQ) > 1)//倒数据
//    {
//        QueuePush(emptyQ, QueueFront(noemptyQ));
//        QueuePop(noemptyQ);
//    }
//    int top = QueueFront(noemptyQ);
//    QueuePop(noemptyQ);
//    return top;
//}
//
//int myStackTop(MyStack* obj) {
//    if (!QueueIsEmpty(&obj->q1))
//    {
//        return QueueBack(&obj->q1);
//    }
//    else
//    {
//        return QueueBack(&obj->q2);
//    }
//}
//
//bool myStackEmpty(MyStack* obj) {
//    return (QueueIsEmpty(&obj->q1) && QueueIsEmpty(&obj->q2));
//}
//
//void myStackFree(MyStack* obj) {
//    QueueDestory(&obj->q1);
//    QueueDestory(&obj->q2);
//    free(obj);
//    obj = NULL;
//}
//int main()
//{
//    MyStack* sk = myStackCreate();
//    myStackPush(sk, 1);
//    printf("%d\n", myStackPop(sk));
//    myStackPush(sk, 2);
//    printf("%d\n", myStackTop(sk));
//    
//    printf("%d\n", myStackEmpty(sk));
//    return 0;
//}



//#include<stdio.h>
//#define N 3
//int main()
//{
//	int arr[N] = { 0 };
//	for (int i = 0; i < N; ++i)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < N-1;++i)
//	{
//		for (int j = 0; j < N-1-i; ++j)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < N; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i = 0, j = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i % j != 0)
//		{
//			printf("%d为素数\n", i);
//		}
//	}
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	for (int i = 1000; i <= 2000; ++i)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int m, n;
//    scanf("%d%d", &m, &n);
//    for (int i = (m < n ? m : n); i > 0; --i)
//    {
//        if (m % i == 0 && n % i == 0)
//        {
//            printf("最大公约数为%d\n", i);
//            break;
//        }
//    }
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//	for (int i = 1; i < 10; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			printf("%d * %d = %d\t", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//#include<stdio.h>
//#define N 10
//int main()
//{
//	int arr[N] = { 0 };
//	for (int i = 0; i < 10; ++i)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (int i = 1; i < N; ++i)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d", max);
//	return 0;
//}



//猜数字
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("***********************************\n");
//	printf("***********   1.Play  *************\n");
//	printf("***********   0.exit  *************\n");
//	printf("***********************************\n");
//}
//void Game()
//{
//	int guess = 0;
//	int ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("输入你所猜的数字:");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请输入你的选择:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int check = 0;
//	scanf("%d", &check);
//
//	int left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1, mid = 0;
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (arr[mid] > check)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < check)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("该数据下标为%d\n",mid);
//			return 0;
//		}
//	}
//	printf("找不到\n");
//	return 0;
//}








//#include<stdio.h>
//#include<math.h>
//int func(int num)
//{
//	int ret = sqrt(num);
//	for (int i = 2; i <= ret; ++i)
//	{
//		if (num % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	for (int i = 101; i < 200; i += 2)
//	{
//		if (func(i))
//		{
//			printf("%d为素数\n", i);
//		}
//	}
//	return 0;
//}




//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//void Get_Max1(int* arr,int* maxi)
//{
//	int begin = 0, end = 99999999;
//	int maxb = arr[begin], maxe = arr[end];
//	for (int i = 0; i < 100000000 / 2; ++i)
//	{
//		if (maxb < arr[i])
//		{
//			maxb = arr[i];
//			begin = i;
//		}
//		if (maxe < arr[99999999 - i])
//		{
//			maxe = arr[99999999 - i];
//			end = 99999999-i;
//		}
//	}
//	*maxi = maxb < maxe ? end : begin;
//}
//void Get_Max2(int* arr, int* maxi)
//{
//	int max = arr[0], max_i = 0;
//	for (int i = 0; i < 100000000; ++i)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//			max_i = i;
//		}
//	}
//	*maxi = max_i;
//}
//int main()
//{
//	int* arr = (int*)malloc(sizeof(int)*100000000);
//	if (arr != NULL)
//	{
//		for (int i = 0; i < 100000000; ++i)
//		{
//			arr[i] = i + 1;
//		}
//		int maxi = 0;
//		clock_t begin1 = clock();
//		Get_Max1(arr, &maxi);
//		clock_t end1 = clock();
//		printf("%d\n", arr[maxi]);
//		printf("func1:%d\n", end1 - begin1);
//
//		clock_t begin2 = clock();
//		Get_Max2(arr, &maxi);
//		clock_t end2 = clock();
//		printf("%d\n", arr[maxi]);
//		printf("func2:%d\n", end2 - begin2);
//	}
//	return 0;
//}









/*
求1+2+3+...+n，要求不能使用乘除法、位运算、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
*/

//#include<iostream>
//using std::cout;
//using std::endl;
//int i = 1;
//int ret = 0;
//class Sum
//{
//public:
//    Sum()
//    {
//        ret += i;
//        ++i;
//    }
//};
//class Solution
//{
//public:
//    int Sum_Solution(int n)
//    {
//        //Sum arr[n];//变长数组
//        return ret;
//    }
//};

//#include<iostream>
//using namespace std;
//class Sum
//{
//public:
//    Sum()
//    {
//        _sum += _i;
//        ++_i;
//    }
//    static int GetSum()
//    {
//        return _sum;
//    }
//private:
//    static int _sum;
//    static int _i;
//};
//int Sum::_sum = 0;
//int Sum::_i = 1;
//class Solution
//{
//public:
//    int Sum_Solution(int n)
//    {
//        //Sum arr[n];
//        return Sum::GetSum();
//    }
//};

//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//    class Sum
//    {
//    public:
//        Sum()
//        {
//            _sum += _i;
//            ++_i;
//        }
//        static int GetSum()
//        {
//            return _sum;
//        }
//    };
//
//    int Sum_Solution(int n)
//    {
//        //Sum arr[n];
//        return Sum::GetSum();
//    }
//private:
//    static int _sum;
//    static int _i;
//};
//int Solution::_sum = 0;
//int Solution::_i = 1;












/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式
*/

//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    string addStrings(string num1, string num2)
//    {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0;
//        string strRet;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int value1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int value2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = value1 + value2 + next;
//            next = ret > 9 ? 1 : 0;
//            strRet.insert(strRet.begin(), (ret % 10) + '0');
//            --end1;
//            --end2;
//        }
//        if (next)
//            strRet.insert(strRet.begin(), '1');
//        return strRet;
//    }
//};

//优化版
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    string addStrings(string num1, string num2)
//    {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0;
//        string strRet;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int value1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int value2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = value1 + value2 + next;
//            next = ret > 9 ? 1 : 0;
//            strRet += ((ret) % 10 + '0');
//            --end1;
//            --end2;
//        }
//        if (next)
//            strRet += '1';
//        reverse(strRet.begin(), strRet.end());
//        return strRet;
//    }
//};






/*
计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
*/
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    //cin>> str;//流提取符遇到空格或换行停止
//    getline(cin, str);
//    size_t pos = str.rfind(' ');
//    if (pos != string::npos)
//    {
//        cout << str.size() - pos - 1 << endl;
//    }
//    else
//    {
//        cout << str.size() << endl;
//    }
//    return 0;
//}







/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    int firstUniqChar(string s)
//    {
//        size_t countArray[26] = { 0 };
//        for (auto ch : s)
//            ++countArray[ch - 'a'];
//        for (size_t i = 0; i < s.size(); ++i)
//        {
//            if (countArray[s[i] - 'a'] == 1)
//                return i;
//        }
//        return -1;
//    }
//};





/*
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个回文串。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是回文串，返回 true ；否则，返回 false
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    bool CheckNumLetter(char ch)
//    {
//        return ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
//    }
//    bool isPalindrome(string s)
//    {
//        for (size_t i = 0; i < s.size(); ++i)
//        {
//            if (s[i] >= 'A' && s[i] <= 'Z')
//                s[i] += 32;
//            if (!CheckNumLetter(s[i]))
//            {
//                s.erase(s.begin() + i);
//                --i;
//            }
//        }
//        int begin = 0, end = s.size() - 1;
//        while (begin <= end)
//        {
//            if (s[begin] != s[end])
//            {
//                return false;
//            }
//            ++begin;
//            --end;
//        }
//        return true;
//    }
//};
//int main()
//{
//    string str("0P");
//    Solution s;
//    bool ret = s.isPalindrome(str);
//    cout << ret << endl;
//    return 0;
//}









/*
给定一个非负整数 numRows，生成「杨辉三角」的前numRows行
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>>vv;
//        vv.resize(numRows);
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            vv[i].resize(i + 1, 0);
//            vv[i].front() = vv[i].back() = 1;
//        }
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            for (size_t j = 0; j < vv[i].size(); ++j)
//            {
//                if (vv[i][j] == 0)
//                {
//                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//                }
//            }
//        }
//        return vv;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<vector<int>> vv = s.generate(5);
//    for (size_t i = 0; i < vv.size(); ++i)
//    {
//        for (size_t j = 0; j < vv[i].size(); ++j)
//        {
//            cout << vv[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}







/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        size_t src = 0, dst = 0;
//        while (src < nums.size())
//        {
//            if (nums[src] == nums[dst])
//                ++src;
//            else
//                nums[++dst] = nums[src++];
//        }
//        return dst + 1;
//    }
//};



//#include<iostream>
//#include<vector>
//using namespace std;
////1
//class Solution
//{
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        size_t src = 0, dst = 0;
//        while (src < nums.size())
//        {
//            if (nums[src] == nums[dst])
//                ++src;
//            else
//                nums[++dst] = nums[src++];
//        }
//        nums.resize(dst + 1);
//        return nums.size();
//    }
//};
////2(低效)
//class Solution
//{
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        size_t src = 0, dst = 0;
//        while (src < nums.size())
//        {
//            if (nums[src] == nums[dst])
//                ++src;
//            else
//                nums[++dst] = nums[src++];
//        }
//        nums.erase(nums.begin() + dst + 1, nums.end());
//        return nums.size();
//    }
//};
//int main()
//{
//    vector<int>nums{ 1,1,2,2,3,4,4 };
//    Solution s;
//    size_t size = s.removeDuplicates(nums);
//    for (size_t i = 0; i < size; ++i)
//    {
//        cout << nums[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}






/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//class Solution
//{
//    const char* numToStr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };//缺省值声明
//public:
//    void Combine(string digits, size_t di, vector<string>& retV, string combineStr)
//    {
//        if (di == digits.size())
//        {
//            retV.push_back(combineStr);
//            return;
//        }
//        //取数字字符映射字符串
//        size_t num = digits[di] - '0';
//        string str = numToStr[num];
//
//        for (auto ch : str)
//        {
//            Combine(digits, di + 1, retV, combineStr + ch);
//        }
//    }
//    vector<string> letterCombinations(string digits)
//    {
//        vector<string> retV;
//        if (digits.empty())return retV;
//        string str;
//        Combine(digits, 0, retV, str);
//        return retV;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<string> retV = s.letterCombinations("238");
//    for (vector<string>::iterator it = retV.begin(); it != retV.end(); ++it)
//    {
//        cout << *it << endl;
//    }
//    return 0;
//}







//#include<iostream>
//using namespace std;
//struct A {
//
//	long a1;
//
//	short a2;
//
//	int a3;
//
//	int* a4;
//
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(long long) << endl;
//	return 0;
//}







/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素
算法应该具有线性时间复杂度，不使用额外空间来实现
*/
//#include<iostream>
//#include<vector>
//using std::vector;
//class Solution
//{
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        int ret = 0;
//        for (size_t i = 0; i < nums.size(); ++i)
//        {
//            ret ^= nums[i];
//        }
//        return ret;
//    }
//};













/*
给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> singleNumber(vector<int>& nums)
//    {
//        int mask = 0;
//        for (size_t i = 0; i < nums.size(); ++i)
//            mask ^= nums[i];
//
//        int type1 = 0, type2 = 0;
//        int lsb = (mask == INT_MIN ? mask : mask & (-mask));
//
//        for (size_t i = 0; i < nums.size(); ++i)
//        {
//            if (nums[i] & lsb) type1 ^= nums[i];
//            else type2 ^= nums[i];
//        }
//        return { type1, type2 };
//    }
//};
//int main()
//{
//    vector<int>v{ 1,2,1,3,2,5 };
//    Solution s;
//    vector<int> ret = s.singleNumber(v);
//    for (size_t i = 0; i < ret.size(); ++i)
//    {
//        cout << ret[i] << " ";
//    }
//    return 0;
//}







/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
*/
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//class Solution
//{
//    const char* numToStr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };//缺省值声明
//public:
//    void Combine(string digits, size_t di, vector<string>& retV, string combineStr)
//    {
//        if (di == digits.size())
//        {
//            retV.push_back(combineStr);
//            return;
//        }
//        size_t num = digits[di] - '0';
//        string str = numToStr[num];
//
//        for (auto ch : str)
//        {
//            Combine(digits, di + 1, retV, combineStr + ch);
//        }
//    }
//    vector<string> letterCombinations(string digits)
//    {
//        vector<string> retV;
//        if (digits.empty())return retV;
//        string str;
//        Combine(digits, 0, retV, str);
//        return retV;
//    }
//};







//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cassert>
//namespace bjy
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T value_type;
//		typedef value_type* iterator;
//		typedef const value_type* const_iterator;
//		typedef value_type& reference;
//		typedef const value_type& const_reference;
//	public:
//		iterator begin() { return _start; }
//		iterator end() { return _finish; }
//		const_iterator begin()const { return _start; }
//		const_iterator end()const { return _finish; }
//
//		vector() :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
//		~vector() {
//			delete[] _start;
//			_start = _finish = _end_of_storage = nullptr;
//		}
//
//		size_t capacity()const { return _end_of_storage - _start; }
//		size_t size()const { return _finish - _start; }
//
//		reference operator[](size_t pos) {
//			assert(pos < size());
//			return _start[pos];
//		}
//		const_reference& operator[](size_t pos)const {
//			assert(pos < size());
//			return _start[pos];
//		}
//
//		void reserve(size_t n) {
//			size_t previous_size = size();
//			if (n > capacity()) {
//				value_type* temp = new value_type[n];
//				if (_start) {
//					memcpy(temp, _start, sizeof(value_type) * size());
//					delete[] _start;
//				}
//				_start = temp;
//				_finish = _start + previous_size;
//				_end_of_storage = _start + n;
//			}
//		}
//		void insert(iterator pos, const_reference data) {
//			assert((pos >= _start) && (pos <= _finish));
//			if (_finish >= _end_of_storage) {
//				size_t lenth = pos - _start;//记录,避免迭代器失效
//				reserve(capacity() == 0 ? 6 : capacity() * 2);
//				pos = _start + lenth;//更新
//			}
//			for (iterator cur = _finish - 1; cur >= pos; --cur)
//				*(cur + 1) = *cur;
//			*pos = data;
//			++_finish;
//		}
//		iterator erase(iterator pos) {
//			assert((pos >= _start) && (pos < _finish));
//			for (iterator cur = pos + 1; cur < _finish; ++cur)
//				*(cur - 1) = *cur;
//			--_finish;
//			return pos;
//		}
//		void push_back(const_reference data) {
//			if (_finish >= _end_of_storage)
//				reserve(capacity() == 0 ? 6 : capacity() * 2);
//			*(_finish++) = data;
//		}
//		void pop_back() {
//			assert(_finish > _start);
//			--_finish;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _end_of_storage;
//	};
//}
//
//#include<algorithm>
//using namespace bjy;
//using std::cout;
//using std::endl;
//using std::find;
//int main()
//{
//	vector<int>v;
//	for (size_t i = 0; i < 10; ++i)
//	{
//		v.push_back(i + 1);
//	}
//
//	vector<int>::iterator it = find(v.begin(), v.end(), 5);
//	v.insert(it, 30);
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < 10; ++i)
//	{
//		v.push_back(i + 1);
//	}
//
//	it = find(v.begin(), v.end(), 5);
//	v.erase(it);
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (vector<int>::iterator it = v.begin(); it != v.end();) {
//		if (*it % 2 == 0)
//		{
//			it = v.erase(it);
//		}
//		else {
//			++it;
//		}
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}





//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string str;
//    getline(cin,str);
//    size_t count = 0;
//    for (int i = str.size() - 1; i >= 0; --i, ++count)
//    {
//        if (str[i] == ' ')
//            break;
//    }
//    cout << count << endl;
//    return 0;
//}











//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    bool isPalindrome(string s)
//    {
//        for (size_t i = 0; i < s.size(); ++i)
//        {
//            if (isalnum(s[i]))
//            {
//                if (isupper(s[i]))
//                    s[i] = tolower(s[i]);
//            }
//            else
//            {
//                s.erase(i,1);
//                --i;
//            }
//        }
//        if (s.size() == 0)return true;
//        size_t begin = 0;
//        size_t end = s.size() - 1;
//        while (begin < end)
//        {
//            if (s[begin] != s[end])
//                return false;
//            ++begin;
//            --end;
//        }
//        return true;
//    }
//};
//int main()
//{
//    Solution s;
//    string str = "0P";
//    bool ret = s.isPalindrome(str);
//    cout << ret << endl;
//    return 0;
//}












/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    void _reverseStr(string& s, size_t begin, size_t end)
//    {
//        while (begin < end)
//        {
//            char temp = s[begin];
//            s[begin] = s[end];
//            s[end] = temp;
//            ++begin;
//            --end;
//        }
//    }
//    string reverseStr(string s, int k)
//    {
//        size_t begin = 0;
//        size_t end = 0;
//        size_t count = 0;
//        while (count < s.size())
//        {
//            if ((count + 2 * k) <= s.size())
//            {
//                count += 2 * k;
//                begin = count - 2 * k;
//                end = count - k - 1;
//                _reverseStr(s, begin, end);
//            }
//            else if ((count + k) <= s.size() && (count + 2 * k) > s.size())
//            {
//                count += 2 * k;
//                begin = count - 2 * k;
//                end = count - k - 1;
//                _reverseStr(s, begin, end);
//                break;
//            }
//            else if ((count + k) > s.size())
//            {
//                count += k;
//                begin = count - k;
//                end = s.size() - 1;
//                _reverseStr(s, begin, end);
//                break;
//            }
//        }
//        return s;
//    }
//};
//int main()
//{
//    string str = "abcdefg";
//    int k = 2;
//    Solution s;
//    string ret = s.reverseStr(str, k);
//    cout << ret << endl;
//    return 0;
//}












/*
给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
*/
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution
//{
//public:
//    void _reverseWords(string& s, size_t begin, size_t end)
//    {
//        while (begin < end)
//        {
//            char temp = s[begin];
//            s[begin] = s[end];
//            s[end] = temp;
//            ++begin;
//            --end;
//        }
//    }
//    string reverseWords(string s)
//    {
//        size_t begin = 0;
//        size_t end = 0;
//        while (end < s.size())
//        {
//            for (; s[end] != ' '; ++end)
//            {
//                if (end == s.size())break;
//            }
//            _reverseWords(s, begin, end - 1);
//            ++end;
//            begin = end;
//        }
//        return s;
//    }
//};
//int main()
//{
//    string str = "Let's take LeetCode contest";
//    Solution s;
//    string ret = s.reverseWords(str);
//    cout << ret << endl;
//    return 0;
//}













/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
*/
//#include<string>
//#include<iostream>
//using namespace std;
////计算过程中不可将字符串整个转换为任何形式的整型
//class Solution
//{
//public:
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0")
//        {
//            return "0";
//        }
//        string ret = "0";
//        int m = num1.size(), n = num2.size();
//        for (int i = n - 1; i >= 0; i--)
//        {
//            string curr;
//            int add = 0;
//            for (int j = n - 1; j > i; j--)
//            {
//                curr.push_back(0);
//            }
//            int y = num2.at(i) - '0';
//            for (int j = m - 1; j >= 0; j--)
//            {
//                int x = num1.at(j) - '0';
//                int product = x * y + add;
//                curr.push_back(product % 10);
//                add = product / 10;
//            }
//            while (add != 0)
//            {
//                curr.push_back(add % 10);
//                add /= 10;
//            }
//            reverse(curr.begin(), curr.end());
//            for (auto& c : curr)
//            {
//                c += '0';
//            }
//            ret = addStrings(ret, curr);
//        }
//        return ret;
//    }
//
//    string addStrings(string& num1, string& num2)
//    {
//        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
//        string ret;
//        while (i >= 0 || j >= 0 || add != 0)
//        {
//            int x = i >= 0 ? num1.at(i) - '0' : 0;
//            int y = j >= 0 ? num2.at(j) - '0' : 0;
//            int result = x + y + add;
//            ret.push_back(result % 10);
//            add = result / 10;
//            i--;
//            j--;
//        }
//        reverse(ret.begin(), ret.end());
//        for (auto& c : ret)
//        {
//            c += '0';
//        }
//        return ret;
//    }
//};












//#include<iostream>
//#include<vector>
//using namespace std;
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}










//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = sizeof(ar) / sizeof(int);//10
//	vector<int>v(ar, ar + n);
//	cout << v.size() << ":" << v.capacity() << endl;
//	v.reserve(100);
//	v.resize(20);
//	cout << v.size() << ":" << v.capacity() << endl;
//	v.reserve(50);
//	v.resize(5);
//	cout << v.size() << ":" << v.capacity() << endl;
//	return 0;
//}





//#include<iostream>
//#include<cassert>
//namespace bjy
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T value_type;
//		typedef value_type* iterator;
//		typedef const value_type* const_iterator;
//		typedef value_type& reference;
//		typedef const value_type& const_reference;
//	public:
//		iterator begin() { return _start; }
//		iterator end() { return _finish; }
//		const_iterator begin()const { return _start; }
//		const_iterator end()const { return _finish; }
//
//		vector() :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
//		~vector() {
//			delete[] _start;
//			_start = _finish = _end_of_storage = nullptr;
//		}
//
//		size_t capacity()const { return _end_of_storage - _start; }
//		size_t size()const { return _finish - _start; }
//
//		reference operator[](size_t pos) {
//			assert(pos < size());
//			return _start[pos];
//		}
//		const_reference& operator[](size_t pos)const {
//			assert(pos < size());
//			return _start[pos];
//		}
//
//		void reserve(size_t n) {
//			size_t previous_size = size();
//			if (n > capacity()) {
//				value_type* temp = new value_type[n];
//				if (_start) {
//					memcpy(temp, _start, sizeof(value_type) * size());
//					delete[] _start;
//				}
//				_start = temp;
//				_finish = _start + previous_size;
//				_end_of_storage = _start + n;
//			}
//		}
//		void insert(iterator pos, const_reference data) {
//			assert((pos >= _start) && (pos <= _finish));
//			if (_finish >= _end_of_storage) {
//				size_t lenth = pos - _start;//记录,避免迭代器失效
//				reserve(capacity() == 0 ? 6 : capacity() * 2);
//				pos = _start + lenth;//更新
//			}
//			for (iterator cur = _finish - 1; cur >= pos; --cur)
//				*(cur + 1) = *cur;
//			*pos = data;
//			++_finish;
//		}
//		iterator erase(iterator pos) {
//			assert((pos >= _start) && (pos < _finish));
//			for (iterator cur = pos + 1; cur < _finish; ++cur)
//				*(cur - 1) = *cur;
//			--_finish;
//			return pos;
//		}
//		void push_back(const_reference data) {
//			if (_finish >= _end_of_storage)
//				reserve(capacity() == 0 ? 6 : capacity() * 2);
//			*(_finish++) = data;
//		}
//		void pop_back() {
//			assert(_finish > _start);
//			--_finish;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _end_of_storage;
//	};
//}
//
//#include<iostream>
//#include<algorithm>
//using std::cout;
//using std::cin;
//using std::endl;
//using std::sort;
//using namespace bjy;
//void MergeData(vector<int>& v1, vector<int>& v2, vector<int>& v3)
//{
//	sort(v1.begin(), v1.end());
//	sort(v2.begin(), v2.end());
//	size_t begin1 = 0, begin2 = 0;
//	size_t end1 = v1.size() - 1;
//	size_t end2 = v2.size() - 1;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (v1[begin1] < v2[begin2]) {
//			v3.push_back(v1[begin1]);
//			++begin1;
//		}
//		else{
//			v3.push_back(v2[begin2]);
//			++begin2;
//		}
//	}
//	for (; begin1 <= end1; ++begin1)
//	{
//		v3.push_back(v1[begin1]);
//	}
//	for (; begin2 <= end2; ++begin2)
//	{
//		v3.push_back(v2[begin2]);
//	}
//}
//int main()
//{
//	//输入两个有序顺序表
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>ret;
//	cout << "输入第一个有10个元素的有序顺序表" << endl;
//	for (size_t i = 0; i < 10; ++i){
//		int input = 0;
//		cin >> input;
//		v1.push_back(input);
//	}
//	cout << "输入第一个有10个元素的有序顺序表" << endl;
//	for (size_t i = 0; i < 10; ++i) {
//		int input = 0;
//		cin >> input;
//		v2.push_back(input);
//	}
//	MergeData(v1, v2, ret);
//
//	cout << "两个有序顺序表合并后表的元素为" << endl;
//	for (size_t i = 0; i < ret.size(); ++i)
//	{
//		cout << ret[i] << " ";
//	}
//	cout << endl;
//
//	//输入item，并删除该线性表中所有值为item的数据元素
//	cout << "输入item" << endl;
//	int item = 0;
//	cin >> item;
//	for (size_t i = 0; i < ret.size(); ++i)
//	{
//		if (ret[i] == item)
//		{
//			ret.erase(ret.begin() + i);
//			--i;
//		}
//	}
//	cout << "输出删除后的结果" << endl;
//	for (size_t i = 0; i < ret.size(); ++i)
//	{
//		cout << ret[i] << " ";
//	}
//	return 0;
//}












/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        if (nums.size() == 1 && nums[0] == target)return { 0,0 };
//        vector<int> ret;
//        int left = 0;
//        int right = (int)nums.size() - 1;
//        while (left <= right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] > target)
//            {
//                right = mid - 1;
//            }
//            else if (nums[mid] < target)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                int flag = mid;
//                while (flag > 0 && nums[flag] == target)
//                {
//                    --flag;
//                }
//                if (nums[flag] != target)
//                {
//                    ++flag;
//                }
//                ret.push_back(flag);
//                flag = mid;
//                for (; flag < nums.size() && nums[flag] == target; ++flag);
//                ret.push_back(flag - 1);
//                break;
//            }
//        }
//        if (ret.size() == 0)
//        {
//            ret.push_back(-1);
//            ret.push_back(-1);
//        }
//        return ret;
//    }
//};
//int main()
//{
//    vector<int>v{ 1,4};
//    Solution s;
//    vector<int> ret = s.searchRange(v, 4);
//    for (size_t i = 0; i < ret.size(); ++i)
//    {
//        cout << ret[i] << " ";
//    }
//    return 0;
//}














/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明:你不能倾斜容器。
*/
//暴力求解超出时间限制
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int maxArea(vector<int>& height)
//    {
//        size_t maxRet = 0;
//        for (size_t i = 0; i < height.size() - 1; ++i)
//        {
//            size_t maxNum = 0;
//            for (size_t j = i + 1; j < height.size(); ++j)
//            {
//                size_t temp = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
//                if (temp > maxNum)maxNum = temp;
//            }
//            if (maxNum > maxRet)maxRet = maxNum;
//        }
//        return (int)maxRet;
//    }
//};
//int main()
//{
//    vector<int>v{ 1,8,6,2,5,4,8,3,7 };
//    Solution s;
//    int ret = s.maxArea(v);
//    cout << ret << endl;
//    return 0;
//}


//双指针
//每轮向内移动短板，所有消去的状态都 不会导致面积最大值丢失
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//    int maxArea(vector<int>& height)
//    {
//        size_t i = 0, j = height.size() - 1, res = 0;
//        while (i < j)
//            res = height[i] < height[j] ? max(res, (j - i) * height[i++]) : max(res, (j - i) * height[j--]);
//        return (int)res;
//    }
//};
//int main()
//{
//    vector<int>v{ 1,8,6,2,5,4,8,3,7 };
//    Solution s;
//    int ret = s.maxArea(v);
//    cout << ret << endl;
//    return 0;
//}








/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回反转后的链表
*/
/*
思想:在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置
*/
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        ListNode* dummyNode = new ListNode(-1);
//        dummyNode->next = head;
//        ListNode* pre = dummyNode;
//        for (int i = 0; i < left - 1; i++) {
//            pre = pre->next;
//        }
//        ListNode* cur = pre->next;
//        ListNode* next;
//        for (int i = 0; i < right - left; i++) {
//            next = cur->next;
//            cur->next = next->next;
//            next->next = pre->next;
//            pre->next = next;
//        }
//        return dummyNode->next;
//    }
//};














//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cassert>
//using std::bidirectional_iterator_tag;
//namespace bjy
//{
//	template<class T>
//	struct list_node {
//		list_node(const T& data = T()) : _next(nullptr), _prev(nullptr), _data(data) {}
//		list_node<T>* _next;
//		list_node<T>* _prev;
//		T _data;
//	};
//
//	template<class T, class Ref, class Ptr>
//	struct __list_iterator {
//		typedef list_node<T> list_node;
//		typedef __list_iterator<T, Ref, Ptr> iterator;
//
//		typedef bidirectional_iterator_tag iterator_category;
//		typedef T value_type;
//		typedef Ptr pointer;
//		typedef Ref reference;
//		typedef ptrdiff_t difference_type;
//
//		__list_iterator(list_node* node) :_node(node) {}
//		bool operator!=(const iterator& it)const { return _node != it._node; }
//		bool operator==(const iterator& it)const { return _node == it._node; }
//		Ref operator*() { return _node->_data; }
//		Ptr operator->() { return &(operator*()); }
//		iterator& operator++() {
//			_node = _node->_next;
//			return *this;
//		}
//		iterator operator++(int) {
//			iterator temp(*this);
//			_node = _node->_next;
//			return temp;
//		}
//		iterator& operator--() {
//			_node = _node->_prev;
//			return *this;
//		}
//		iterator operator--(int) {
//			iterator temp(*this);
//			_node = _node->_prev;
//			return temp;
//		}
//		iterator operator+(int num) {
//			iterator temp(_node);
//			if (num < 0) temp = operator-(-num);
//			else for (int i = 0; i < num - 1; ++i) temp._node = temp._node->_next;
//			return temp;
//		}
//		iterator operator-(int num) {
//			iterator temp(_node);
//			if (num < 0) temp = operator+(-num);
//			else for (int i = 0; i < num; ++i) temp._node = temp._node->_prev;
//			return temp;
//		}
//		list_node* _node;
//	};
//
//	template<class T>
//	class list
//	{
//		typedef T value_type;
//		typedef list_node<value_type> list_node;
//		typedef value_type& reference;
//		typedef const value_type& const_reference;
//	public:
//		typedef __list_iterator<T, T&, T*> iterator;
//		typedef __list_iterator<T, const T&, const T*> const_iterator;
//
//		iterator begin() { return iterator(_head->_next); }
//		const_iterator begin()const { return const_iterator(_head->_next); }
//		iterator end() { return iterator(_head); }
//		const_iterator end()const { return const_iterator(_head); }
//
//		void empty_initialize() {
//			_head = new list_node;
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//		void swap(list<value_type>& lt) { std::swap(_head, lt._head); }
//		void clear() { for (list<int>::iterator it = begin(); it != end(); ) it = erase(it); }
//		list() { empty_initialize(); }
//		template<class InputIterator>
//		list(InputIterator first, InputIterator last) {
//			empty_initialize();
//			for (; first != last; ++first) {
//				push_back(*first);
//			}
//		}
//		list(const list<value_type>& lt) {
//			empty_initialize();
//			list<value_type> temp(lt.begin(), lt.end());
//			swap(temp);
//		}
//		~list() {
//			clear();
//			delete _head;
//			_head = nullptr;
//		}
//		list<value_type>& operator=(list<value_type> lt) {
//			swap(lt);
//			return *this;
//		}
//
//		iterator insert(iterator pos, const_reference data) {
//			list_node* newnode = new list_node(data);
//			list_node* cur = pos._node;
//			list_node* prev = cur->_prev;
//
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//		void push_back(const_reference data) {
//#if 0
//			list_node* new_node = new list_node(data);
//			list_node* tail = _head->_prev;
//			tail->_next = new_node;
//			new_node->_prev = tail;
//			new_node->_next = _head;
//			_head->_prev = new_node;
//#else
//			insert(end(), data);
//#endif
//		}
//		void push_front(const_reference x) { insert(begin(), x); }
//
//		iterator erase(iterator pos) {
//			assert(pos != end());
//			list_node* prev = (pos._node)->_prev;
//			list_node* next = (pos._node)->_next;
//			prev->_next = next;
//			next->_prev = prev;
//			delete (pos._node);
//			return iterator(next);
//		}
//		void pop_back() { erase(--end()); }
//		void pop_front() { erase(begin()); }
//
//	private:
//		list_node* _head;
//	};
//}
//
//#define NUM 10
//using namespace bjy;
//using std::cin;
//using std::cout;
//using std::endl;
//
//int main()
//{
//	list<int>lt;
//	cout << "输入十个元素" << endl;
//	for (size_t i = 0; i < NUM; ++i){
//		int temp = 0;
//		cin >> temp;
//		lt.push_back(temp);
//	}
//	cout << "查找第i个位置的元素,输入i:";
//	int i = 0;
//	cin >> i;
//	cout << *(lt.begin() + i) << endl;
//	cout << "删除第i个位置的元素,并输入i" << endl;
//	cin >> i;
//	lt.erase((lt.begin() + i));
//	cout << "链表中的元素:" << endl;
//	for (list<int>::iterator it = lt.begin(); it != lt.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	return 0;
//}














/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素
*/

//class MinStack {
//public:
//    MinStack() {}
//    void push(int val) {
//        _stValue.push(val);
//        if (_stMinValue.empty() || val <= _stMinValue.top())
//            _stMinValue.push(val);
//    }
//    void pop() {
//        if (_stValue.top() == _stMinValue.top())
//            _stMinValue.pop();
//        _stValue.pop();
//    }
//    int top() { return _stValue.top(); }
//    int getMin() { return _stMinValue.top(); }
//private:
//    stack<int> _stValue;
//    stack<int> _stMinValue;
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */









/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
1. 0<=pushV.length == popV.length <=1000
2. -1000<=pushV[i]<=1000
3. pushV 的所有数字均不相同
*/
//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//class Solution
//{
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV)
//    {
//        stack<int> st;
//        int popi = 0;
//        for (auto pushVal : pushV)
//        {
//            st.push(pushVal);
//            while (!st.empty() && popV[popi] == st.top())
//            {
//                ++popi;
//                st.pop();
//            }
//        }
//        //return popi == popV.size();
//        return st.empty();
//    }
//};







/*
根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况
*/
//#include<iostream>
//#include<vector>
//#include<string>
//#include<stack>
//using namespace std;
//class Solution
//{
//public:
//    int evalRPN(vector<string>& tokens)
//    {
//        stack<long long> st;
//        for (size_t i = 0; i < tokens.size(); ++i)
//        {
//            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
//            {
//                long long right = st.top();
//                st.pop();
//                long long left = st.top();
//                st.pop();
//                switch (tokens[i][0])
//                {
//                case '+':st.push(left + right); break;
//                case '-':st.push(left - right); break;
//                case '*':st.push(left * right); break;
//                case '/':st.push(left / right); break;
//                }
//            }
//            else
//            {
//                st.push(stoll(tokens[i]));
//            }
//        }
//        return st.top();
//    }
//};














/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题
*/
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//class Solution
//{
//public:
//    int findKthLargest(vector<int>& nums, int k)
//    {
//        priority_queue<int> heap(nums.begin(), nums.end());
//        for (int i = 0; i < k - 1; ++i) { heap.pop(); }
//        return heap.top();
//    }
//};




//#include<iostream>
//#include<queue>
//#include<string>
//using namespace std;
//int main()
//{
//	priority_queue<int> a;//3210
//	priority_queue<int, vector<int>, greater<int> > c;//0123
//	priority_queue<string> b;//大堆
//
//	for (int i = 0; i < 5; i++)
//	{
//		a.push(i);
//		c.push(i);
//	}
//
//	while (!a.empty())
//	{
//		cout << a.top() << ' ';
//		a.pop();
//	}
//	cout << endl;//43210
//
//	while (!c.empty())
//	{
//		cout << c.top() << ' ';
//		c.pop();
//	}
//	cout << endl;//01234
//
//	b.push("abc");
//	b.push("abcd");
//	b.push("cbd");
//
//	while (!b.empty())
//	{
//		cout << b.top() << ' ';
//		b.pop();
//	}//cbd abcd abc
//
//	cout << endl;
//	return 0;
//}
//4321001234cbdabcdabc








//#include<iostream>
//#include<vector>
//using std::vector;
//using std::cout;
//using std::endl;
//
//int main()
//{
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it != 0)
//			cout << *it;
//		else
//			v.erase(it);
//		it++;
//	}
//	return 0;
//}




//#include<iostream>
//#include<string>
//using std::cout;
//using std::endl;
//using std::string;
//int main(int argc, char* argv[])
//{
//	string a = "hello world";
//	string b = a;
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//
//	string c = b;
//	c = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//
//	a = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//
//	return 0;
//}//false false false







//#include<iostream>
//#include<string>
//using std::cout;
//using std::endl;
//using std::string;
//int main()
//{
//	string str("Hello Bit.");
//	str.reserve(111);
//	str.resize(5);
//	str.reserve(50);
//	cout << str.size() << ":" << str.capacity() << endl;
//	return 0;
//}//5 111









//#include<iostream>
//#include<string>
//using std::cout;
//using std::endl;
//using std::string;
//int main(int argc, char* argv[])
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//
//	int size_pos = 0;
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}//How are you?















//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//typedef int SLDataType;
//typedef struct SListNode
//{
//	SLDataType data;
//	struct SListNode* next;
//}SLNode;
//
//SLNode* buy_list_node(SLDataType d) {//创建一个结点
//	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
//	if (newNode == NULL)
//		return NULL;
//	newNode->data = d;
//	newNode->next = NULL;
//	return newNode;
//}
//
//void SListPushBack(SLNode** ppheader, SLDataType d) {//尾插
//	SLNode* newNode = buy_list_node(d);
//	if (*ppheader == NULL)
//		*ppheader = newNode;
//	else{
//		SLNode* tail = *ppheader;
//		while (tail->next != NULL){
//			tail = tail->next;
//		}
//		tail->next = newNode;
//	}
//}
//
//void seqlist_print(SLNode* pheader){
//	for (SLNode* cur = pheader; cur != NULL; cur = cur->next)
//		printf("%d ", cur->data);
//	printf("\n");
//}
//
//void seqlist_init(SLNode** ppheader, int size, int num) {
//	for (int i = 0; i < size; ++i) {
//		SListPushBack(ppheader, num);
//	}
//}
//
//int main(){
//	int size = 0;
//	scanf("%d", &size);
//	SLNode* pheader = NULL;
//	seqlist_init(&pheader, size, 0);
//	seqlist_print(pheader);
//	return 0;
//}



//#include<stdio.h>
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode, * LinkList;
//void SListPushBack(LinkList& L, int d) {//尾插
//	LNode* newNode = new(LNode);//new是用于开辟内存，有失败的可能
//	newNode->data = d;
//	newNode->next = NULL;
//	if (newNode != NULL) {
//		if (L == NULL)
//			L = newNode;
//		else {
//			LNode* tail = L;
//			while (tail->next != NULL) {
//				tail = tail->next;
//			}
//			tail->next = newNode;
//		}
//	}
//}
//void CreateListNode(LinkList& L, int size, int num) {
//	for (int i = 0; i < size; ++i) {
//		SListPushBack(L, num);
//	}
//}
//void SeqlistPrint(LinkList& L){
//	for (LNode* cur = L; cur != NULL; cur = cur->next)
//		printf("%d ", cur->data);
//	printf("\n");
//}
//int main()
//{
//	int size = 0;
//	scanf("%d", &size);
//	int num = 0;
//	scanf("%d", &num);
//	LinkList L = NULL;
//	CreateListNode(L, size, num);
//	SeqlistPrint(L);
//	return 0;
//}








//#include<stdio.h>
//#include<stdlib.h>
//int compare(const void* a, const void* b)
//{
//    return (*(size_t*)b - *(size_t*)a);
//}
//int main()
//{
//    size_t n = 0;
//    scanf("%zd", &n);
//    size_t* arr = (size_t*)malloc(sizeof(size_t) * 3 * n);
//    if (arr == NULL) return 0;
//    for (int i = 0; i < 3 * n; ++i) {
//        scanf("%zd", &arr[i]);
//    }
//    qsort(arr, 3 * n, sizeof(size_t), compare);
//
//    if (n >= 2) {
//        size_t ret = 0;
//        size_t count = 0;
//        for (int i = 1; i < 3 * n; i += 2) {
//            if (count == n)break;
//            ret += arr[i];
//            ++count;
//        }
//        printf("%zu", ret);
//    }
//    else{
//        printf("%zu", arr[1]);
//    }
//    free(arr);
//    arr = NULL;
//    return 0;
//}




//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    /*string ret_str = "They are students.";
//    string delete_str = "aeiou";*/
//    string ret_str;
//    string delete_str;
//    getline(cin,ret_str);
//    getline(cin, delete_str);
//   /* if (ret_str == " " || delete_str == " ") {
//        cout << ret_str << endl;
//        return 0;
//    }
//    for (string::iterator itd = delete_str.begin(); itd != delete_str.end(); ++itd) {
//        for (string::iterator it = ret_str.begin(); it != ret_str.end();) {
//            if (*it == *itd) {
//                it = ret_str.erase(it);
//            }
//            else {
//                ++it;
//            }
//        }
//    }*/
//    std::size_t found = ret_str.find_first_of(delete_str);
//    while (found != std::string::npos)
//    {
//        ret_str.erase(found,1);
//        found = ret_str.find_first_of(delete_str, found);
//    }
//    cout << ret_str << endl;
//    return 0;
//}





//#include<iostream>
//using std::cout;
//using std::endl;
//int main()
//{
//	const char* str = "compare";
//	printf("%5.3s", str);
//	return 0;
//}











//#include<iostream>
//using namespace std;
//int checkzj(int* array, int n,int left) {
//    int flag = 0;
//    for (int i = left; i < n - 1; ++i) {
//        if (array[i] > array[i + 1]) {
//            flag = 1;//非递增
//            break;
//        }
//        else if (array[i] < array[i + 1]) {
//            flag = 0;//非递减
//            break;
//        }
//    }
//    return flag;
//}
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int* array = new(int[n]);
//    for (int i = 0; i < n; ++i) {
//        cin >> array[i];
//    }
//    if (n == 1) cout << 1 << endl;
//    else {
//        int ret = 1;
//        int left = 0;
//        int right = 1;
//        int flag = checkzj(array,n,left);
//        
//        for (int i = 0; i < n - 1; ++i,++right,++left) {
//            if (flag == 0 && array[left] > array[right]) {
//                ++ret;
//                left = i;
//                right = left + 1;
//                flag = checkzj(array, n, left + 1);
//            }
//            else if (flag == 1 && array[left] < array[right]) {
//                ++ret;
//                left = i;
//                right = left + 1;
//                flag = checkzj(array, n, left + 1);
//            }
//        }
//        cout << ret << endl;
//    }
//    delete[] array;
//    array = nullptr;
//    return 0;
//}







//#include<iostream>
//#include<string>
//using namespace std;
//void change(string& str, size_t left, size_t right) {
//	while (left < right) {
//		char temp = str[left];
//		str[left] = str[right];
//		str[right] = temp;
//		++left;
//		--right;
//	}
//}
//int main()
//{
//	string str = "I like beijing";
//	//getline(cin, str);
//	size_t left = 0, right = 0;
//	for (size_t i = 0; i < str.size(); ++i) {
//		if (str[i] == ' ' || str[i] == '.' || i == str.size() - 1) {
//			if (str[i] == '.' || i == str.size() - 1)right = i;
//			else right = i - 1;
//			change(str, left, right);
//			left = i + 1;
//		}
//	}
//	change(str, 0, str.size() - 1);
//	cout << str << endl;
//	return 0;
//}












//#include <iostream>
//#include <string>
//#include<cctype>
//using namespace std;
//int main()
//{
//    string str = "abcd12345ed125ss123456789";
//    int count = 0, max = 0;
//    for (size_t i = 0; i < str.size(); ++i) {
//        if (isdigit(str[i])) {
//            ++count;
//        }
//        else count = 0;
//        if (count > max) {
//            max = count;
//        }
//    }
//    count = 0;
//    for (size_t i = 0; i < str.size(); ++i) {
//        if (isdigit(str[i])) {
//            ++count;
//        }
//        else count = 0;
//        if (count == max) {
//            for (size_t j = i + 1; j < i + max; ++j) {
//                cout << str[j - max];
//            }
//        }
//    }
//    return 0;
//}




//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    int MoreThanHalfNum_Solution(vector<int>& numbers) {
//        if (numbers.size() == 1) return numbers[0];
//        int half_size = numbers.size() / 2 + 1;
//        int left = 0;
//        int right = 1;
//        int count = 1;
//        while (left < half_size) {
//            if (numbers[left] == numbers[right]) {
//                ++count;
//            }
//            if (count == half_size) return numbers[left];
//            if (right == numbers.size() - 1) {
//                ++left;
//                right = left + 1;
//                count = 1;
//                continue;
//            }
//            ++right;
//        }
//        return -1;
//    }
//};
//int main()
//{
//    vector<int>v{ 1,2,3,2,2,2,5,4,2};
//    Solution s;
//    int ret = s.MoreThanHalfNum_Solution(v);
//    cout << ret << endl;
//    return 0;
//}









//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string ret;
//    int M = 0, N = 0;
//    while (cin >> M >> N) {
//        int flag = 1;
//        if (M < 0) {
//            flag = 0;
//            M = abs(M);
//        }
//        char temp = 0;
//        while (M / N != 0) {
//            if (M % N < 10)
//                ret.insert(0, 1, (M % N) + '0');
//            else
//                ret.insert(0, 1, (M % N) - 10 + 'A');
//            M = M / N;
//        }
//        if (M % N < 10)
//            ret.insert(0, 1, (M % N) + '0');
//        else
//            ret.insert(0, 1, (M % N) - 10 + 'A');
//        if (flag == 0) ret.insert(0, 1, '-');
//        cout << ret << endl;
//        ret = "";
//    }
//    return 0;
//}






//#include<iostream>
//#include<vector>
//using namespace std;
//bool check(int data) {
//    return ((data >= -30) && (data <= 30));
//}
//int main()
//{
//    //A_B B_C AjB BjC
//    vector<int>v;
//    v.resize(4);
//    for (size_t i = 0; i < v.size(); ++i) {
//        cin >> v[i];
//    }
//    int A = (v[0] + v[2]) / 2;
//    int B = (v[1] + v[3]) / 2;
//    int C = (v[3] - v[1]) / 2;
//    if (A - B == v[0] && B - C == v[1] && A + B == v[2] && B + C == v[3]) {
//        if (check(A) && check(B) && check(C)) {
//            cout << A << " " << B << " " << C << " " << endl;
//        }
//        else cout << "No" << endl;
//    }
//    else cout << "No" << endl;
//    return 0;
//}







//#include<iostream>
//#include<string>
//using namespace std;
//bool check(string& str) {
//    size_t left = 0, right = str.size() - 1;
//    while (left < right) {
//        if (str[left] != str[right])
//        {
//            return false;
//        }
//        ++left;
//        --right;
//    }
//    return true;
//}
//int main()
//{
//    string A, B;
//    getline(cin, A);
//    getline(cin, B);
//    size_t count = 0;
//    for (size_t i = 0; i < A.size(); ++i) {
//        string temp = A;
//        A.insert(i, B);
//        if (check(A)) {
//            ++count;
//        }
//        A = temp;
//    }
//    A += B;
//    if (check(A)) {
//        ++count;
//    }
//    cout << count << endl;
//    return 0;
//}






//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//    int n;
//    cin >> n;
//    vector<int>v;
//    v.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//    }
//    int sum = v[0];
//    int max = v[0];
//    for (int i = 1; i < n; ++i) {
//        if (sum >= 0) {
//            sum += v[i];
//        }
//        else {
//            sum = v[i];
//        }
//        if (max < sum)max = sum;
//    }
//    cout << max << endl;
//    return 0;
//}













//#include<stdio.h>
//struct ListNode {
//    int val;
//    struct ListNode* next;
//    
//};

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL) return list2;
//    if (list2 == NULL) return list1;
//
//    struct ListNode* head = NULL, * tail = head;
//    while (list1 != NULL && list2 != NULL) {
//        if (list1->val < list2->val) {
//            if (head == NULL) {//首个元素插入
//                head = tail = list1;
//                list1 = list1->next;
//            }
//            else {
//                tail->next = list1;
//                list1 = list1->next;
//                tail = tail->next;
//            }
//        }
//        else {//list1->val >= list2->val
//            if (head == NULL) {//首个元素插入
//                head = tail = list2;
//                list2 = list2->next;
//            }
//            else {
//                tail->next = list2;
//                list2 = list2->next;
//                tail = tail->next;
//            }
//        }
//    }
//    if (list1 != NULL)
//        tail->next = list1;
//    if (list2 != NULL)
//        tail->next = list2;
//    return head;
//}

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL) return list2;
//    if (list2 == NULL) return list1;
//
//    struct ListNode* head = NULL, * tail = head;
//    if (list1->val < list2->val) {
//        head = tail = list1;
//        list1 = list1->next;
//    }
//    else {
//        head = tail = list2;
//        list2 = list2->next;
//    }
//    while (list1 != NULL && list2 != NULL) {
//        if (list1->val < list2->val) {
//            tail->next = list1;
//            list1 = list1->next;
//        }
//        else {//list1->val >= list2->val
//            tail->next = list2;
//            list2 = list2->next;
//        }
//        tail = tail->next;
//    }
//    if (list1 != NULL)
//        tail->next = list1;
//    if (list2 != NULL)
//        tail->next = list2;
//    return head;
//}

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* head, * tail;
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    tail->next = NULL;
//    while (list1 != NULL && list2 != NULL) {
//        if (list1->val < list2->val) {
//            tail->next = list1;
//            list1 = list1->next;
//        }
//        else {//list1->val >= list2->val
//            tail->next = list2;
//            list2 = list2->next;
//        }
//        tail = tail->next;
//    }
//    if (list1 != NULL)
//        tail->next = list1;
//    if (list2 != NULL)
//        tail->next = list2;
//
//    struct ListNode* del = head;
//    head = head->next;
//    free(del);
//    return head;
//}











/*
现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
*/
//#include<iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        struct ListNode* less_head, * less_tail;
//        less_head = less_tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        less_tail->next = NULL;
//
//        struct ListNode* greater_head, * greater_tail;
//        greater_head = greater_tail = (struct ListNode*)malloc(sizeof(struct ListNode*));
//        greater_tail->next = NULL;
//
//        struct ListNode* current = pHead;
//        while (current != NULL) {
//            if (current->val < x) {
//                less_tail->next = current;
//                less_tail = less_tail->next;
//            }
//            else {
//                greater_tail->next = current;
//                greater_tail = greater_tail->next;
//            }
//            current = current->next;
//        }
//
//        less_tail->next = greater_head->next;
//        greater_tail->next = NULL;
//        ListNode* head = less_head->next;
//        free(less_head);
//        free(greater_head);
//
//        return head;
//    }
//};










/*
对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
*/
//#include<iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
////利用快慢指针找到中间结点
////反转后半部分链表
//class PalindromeList {
//public:
//    struct ListNode* middleNode(struct ListNode* head) {
//        struct ListNode* slow = head, * fast = head;
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//    struct ListNode* reverseList(struct ListNode* head) {
//        struct ListNode* cur = head;
//        struct ListNode* newhead = NULL;
//        while (cur != NULL) {
//            struct ListNode* next = cur->next;
//            cur->next = newhead;
//            newhead = cur;
//            cur = next;
//        }
//        return newhead;
//    }
//
//    bool chkPalindrome(ListNode* A) {
//        struct ListNode* mid = middleNode(A);
//        struct ListNode* newhead = reverseList(mid);
//
//        while (A && newhead) {
//            if (A->val != newhead->val) {
//                return false;
//            }
//            A = A->next;
//            newhead = newhead->next;
//        }
//        return true;
//    }
//};










/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null
题目数据 保证 整个链式结构中不存在环
注意:函数返回结果后，链表必须保持其原始结构
*/

//长链表先走长度之差步
//#include<stdio.h>
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    int lenth_A = 0, lenth_B = 0;
//    struct ListNode* current_A = headA;
//    struct ListNode* current_B = headB;
//    while (current_A->next != NULL) {
//        ++lenth_A;
//        current_A = current_A->next;
//    }
//    while (current_B->next != NULL) {
//        ++lenth_B;
//        current_B = current_B->next;
//    }
//
//    if (current_A != current_B) return NULL;//尾结点不同，肯定不为相交链表
//
//    current_A = headA;
//    current_B = headB;
//    if (lenth_A > lenth_B) {
//        for (int i = 0; i < lenth_A - lenth_B; ++i) {
//            current_A = current_A->next;
//        }
//    }
//    else {//lenth_A <= lenth_B
//        for (int i = 0; i < lenth_B - lenth_A; ++i) {
//            current_B = current_B->next;
//        }
//    }
//    while (current_A != current_B) {//此时肯定为相交链表
//        current_A = current_A->next;
//        current_B = current_B->next;
//    }
//    return current_A;
//}













//#include<iostream>
//#include<cctype>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    int StrToInt(string str) {
//        int flag = 1;//默认为正数
//        long long ret = 0;
//        for (size_t i = 0; i < str.size(); ++i) {
//            if (isdigit(str[i])) {
//                ret += str[i] - '0';
//                ret *= 10;
//            }
//            else {
//                if (str[i] == '+') {}
//                else if (str[i] == '-') {
//                    flag = -1;
//                }
//                else {
//                    return 0;
//                }
//            }
//        }
//        ret /= 10;
//        ret *= flag;
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    long long ret = s.StrToInt("+2147483647");
//    cout << ret << endl;
//    return 0;
//}







//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    int wigth = 0, heigth = 0, count = 0;
//    cin >> wigth >> heigth;
//    vector<vector<int>> v;
//    v.resize(wigth);
//    for (size_t i = 0; i < v.size(); ++i) {
//        v[i].resize(heigth, 1);
//    }
//    for (int i = 0; i < wigth; ++i) {
//        for (int j = 0; j < heigth; ++j) {
//            if (v[i][j] == 1) {
//                ++count;
//                if (i + 2 < wigth)
//                    v[i + 2][j] = 0;
//                if (j + 2 < heigth)
//                    v[i][j + 2] = 0;
//            }
//        }
//    }
//    cout << count << endl;
//    return 0;
//}






//#include<iostream>
//using namespace std;
//int main()
//{
//    int N = 0;
//    cin >> N;
//    int temp = 0;
//    int left = 0, right = 1;
//    while (left < N) {
//        temp = left;
//        left = right;
//        right = temp + right;
//    }
//    int ret = min(abs(left - N), abs(N - temp));
//    cout << ret << endl;
//    return 0;
//}








//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstring>
//using namespace std;
//bool check_dictionary(vector<string>& v) {
//    for (size_t i = 0; i < v.size() - 1; ++i)
//    {
//        if ((strcmp(v[i].c_str(), v[i + 1].c_str()) > 0))
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool check_lenth(vector<string>& v) {
//    for (size_t i = 0; i < v.size() - 1; ++i)
//    {
//        if (v[i].size() > v[i + 1].size())
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<string>v;
//    v.resize(n);
//    for (size_t i = 0; i < n; ++i) {
//        cin >> v[i];
//    }
//
//    if (check_dictionary(v) && !check_lenth(v)) {
//        cout << "lexicographically" << endl;
//    }
//    else if (!check_dictionary(v) && check_lenth(v)) {
//        cout << "lengths" << endl;
//    }
//    else if (check_dictionary(v) && check_lenth(v)) {
//        cout << "both" << endl;
//    }
//    else {
//        cout << "none" << endl;
//    }
//    return 0;
//}





//#include<iostream>
//using namespace std;
//int  main()
//{
//    size_t A = 0, B = 0;
//    cin >> A >> B;
//    size_t min_num = min(A, B);
//    size_t ret = 0;
//    for (size_t i = min_num; i <= A * B; ++i) {
//        if (i % A == 0 && i % B == 0) {
//            ret = i;
//            break;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}





//#include<iostream>
//using namespace std;
//int get_num(int n, int m) {
//    static int count = 0;
//    if (m == 0 || n == 0)
//    {
//        ++count;
//        return 0;
//    }
//    get_num(n - 1, m);
//    get_num(n, m - 1);
//    return count;
//}
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    int ret = get_num(n, m);
//    cout << ret << endl;
//    return 0;
//}







//#include<iostream>
//using namespace std;
//class UnusualAdd
//{
//public:
//    int addAB(int A, int B)
//    {
//        if (0 == A) return B;
//        else if (0 == B) return A;
//        else return addAB(A ^ B, (A & B) << 1);
//    }
//};
//int main()
//{
//    UnusualAdd u;
//    cout << u.addAB(1580198, 2537294) << endl;
//    return 0;
//}










//#include<iostream>
//#include<cctype>
//using namespace std;
//int check_length(const string& str)
//{
//    size_t length = str.size();
//    if (length <= 4) return 5;
//    else if (length >= 5 && length <= 7) return 10;
//    else return 25;
//}
//int check_letter(const string& str)
//{
//    int flag_only_small = 1;
//    int flag_only_big = 1;
//    for (size_t i = 0; i < str.size(); ++i) {
//        if (islower(str[i])) {
//            flag_only_big = 0;
//        }
//        if (isupper(str[i])) {
//            flag_only_small = 0;
//        }
//        if (flag_only_small == 0 && flag_only_big == 0) return 20;
//    }
//    if (flag_only_small == 1 && flag_only_big == 1) return 0;
//    else return 10;
//}
//int check_num(const string& str)
//{
//    int count = 0;
//    for (size_t i = 0; i < str.size(); ++i) {
//        if (isdigit(str[i])) ++count;
//    }
//    if (count > 1) return 20;
//    else if (count == 1) return 10;
//    else return 0;
//}
//int check_sign(const string& str)
//{
//    int count = 0;
//    for (size_t i = 0; i < str.size(); ++i) {
//        if (ispunct(str[i])) ++count;
//    }
//    if (count > 1) return 25;
//    else if (count == 1) return 10;
//    else return 0;
//}
//int check_award(const string& str)
//{
//    if (check_letter(str) == 20 && check_num(str) != 0 && check_sign(str) != 0) return 5;
//    else if (check_letter(str) != 0 && check_num(str) != 0 && check_sign(str) != 0) return 3;
//    else return 2;
//}
//void print_ret(int ret)
//{
//    if (ret >= 90) cout << "VERY_SECURE" << endl;
//    else if (ret >= 80) cout << "SECURE" << endl;
//    else if (ret >= 70) cout << "VERY_STRONG" << endl;
//    else if (ret >= 60) cout << "STRONG" << endl;
//    else if (ret >= 50) cout << "AVERAGE" << endl;
//    else if (ret >= 25) cout << "WEAK" << endl;
//    else cout << "VERY_WEAK" << endl;
//}
//
//int main()
//{
//    string str;
//    cin >> str;
//    int ret = 0;
//    ret += check_length(str);
//    ret += check_letter(str);
//    ret += check_num(str);
//    ret += check_sign(str);
//    ret += check_award(str);
//    print_ret(ret);
//    return 0;
//}












//class Board {
//public:
//    bool checkWon(vector<vector<int> > board) {
//        for (size_t i = 0; i < board.size(); ++i)
//        {
//            if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
//            {
//                if (board[i][0] == 1) return true;
//                else return false;
//            }
//        }
//        for (size_t j = 0; j < board[0].size(); ++j)
//        {
//            if (board[0][j] == board[1][j] && board[2][j] == board[2][j])
//            {
//                if (board[0][j] == 1) return true;
//                else return false;
//            }
//        }
//        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
//        {
//            if (board[0][0] == 1) return true;
//            else return false;
//        }
//        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
//        {
//            if (board[0][2] == 1) return true;
//            else return false;
//        }
//        return false;
//    }
//};






//#include<iostream>
//using namespace std;
//int main()
//{
//    int num = 0;
//    cin >> num;
//    int count = 0;
//    int max = 0;
//    for (int i = 0; i < 32; ++i) {
//        if (max < count) max = count;
//        if ((num & 1) == 1) {
//            ++count;
//        }
//        else {
//            count = 0;
//        }
//        num = num >> 1;
//    }
//    cout << max << endl;
//    return 0;
//}





//class LCA {
//public:
//    int getLCA(int a, int b) {
//        while (a != b){
//            if (a > b) a = a / 2;
//            else b = b / 2;
//        }
//        return a;
//    }
//};









//#include<iostream>
//#include<cmath>
//#include<cassert>
//#include<cstdlib>
//#include<climits>
//#include<vector>
//using namespace std;
//bool check_prime(int num)
//{
//    for (int i = 2; i <= sqrt(num); ++i) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//int main()
//{
//    int ou = 0;
//    cin >> ou;
//    vector<int>v;
//
//    int count = 0;
//    for (int i = 2; i < ou - 1; ++i) {
//        if (check_prime(i)) v.push_back(i);
//    }
//    vector<vector<int>>vv;
//    for (size_t i = 0; i < v.size(); ++i) {
//        for (size_t j = 0; j < v.size(); ++j) {
//            if (v[i] + v[j] == ou)
//                vv.push_back({ v[i],v[j] });
//        }
//    }
//    int min = INT_MAX;
//    int ret_left = 0, ret_right = 0;
//    for (size_t i = 0; i < vv.size(); ++i) {
//        if (abs(vv[i][0] - vv[i][1]) < min) {
//            min = abs(vv[i][0] - vv[i][1]);
//            ret_left = vv[i][0];
//            ret_right = vv[i][1];
//        }
//    }
//    cout << ret_left << endl;
//    cout << ret_right << endl;
//    return 0;
//}







//#include<iostream>
//using namespace std;
//int main()
//{
//	const int ret = 10;
//	int* p = (int*)&ret;
//	*p = 20;
//	cout << "ret = " << ret << " " << "*p = " << *p << endl;//ret = 10 *p = 20
//	return 0;
//}
/*
见volatile关键字
*/






//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//    string get_str;
//    getline(cin, get_str);
//
//    vector<string>v;
//    int count = 0;
//    for (size_t i = 0; i < get_str.size(); ++i) {
//        if (get_str[i] == ' ') {
//            ++count;
//        }
//        else if (get_str[i] == '"') {
//            ++i;
//            string temp;
//            while (get_str[i] != '"') {
//                temp.push_back(get_str[i]);
//                ++i;
//            }
//            v.push_back(temp);
//        }
//        else {
//            if (v.size() != count + 1) v.resize(v.size() + 1);
//            v[count].push_back(get_str[i]);
//        }
//    }
//    cout << count + 1 << endl;
//    for (size_t i = 0; i < v.size(); ++i) {
//        cout << v[i] << endl;
//    }
//    return 0;
//}







//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <climits>
//#include <cmath>
//using namespace std;
//int main()
//{
//    int N = 0, M = 0;
//    cin >> N >> M;
//    vector<int> v(M + 1, INT_MAX);
//    v[N] = 0;
//    for (int i = N; i <= M; i++) {
//        if (v[i] == INT_MAX) {
//            continue;
//        }
//        for (int j = 2; (j * j) <= i; j++) {
//            if (i % j == 0) {
//                if (i + j <= M) {
//                    v[i + j] = min(v[i] + 1, v[i + j]);
//                }
//                if (i + (i / j) <= M) {
//                    v[i + (i / j)] = min(v[i] + 1, v[i + (i / j)]);
//                }
//            }
//        }
//    }
//    if (v[M] == INT_MAX) {
//        v[M] = -1;
//    }
//    cout << v[M] << endl;
//    return 0;
//}










//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//int n = 0;
//int nums[1000] = { 0 };
//
//int cmp(const void* a, const void* b) {
//	return *(int*)a - *(int*)b;
//}
//int findall(int nums[], int index, long sum, long multi) {
//	int count = 0;
//	for (int i = index; i < n; i++) {
//		sum += nums[i];
//		multi *= nums[i];
//		if (sum > multi) count += 1 + findall(nums, i + 1, sum, multi);
//		else if (nums[i] == 1) count += findall(nums, i + 1, sum, multi);
//		else break;
//		sum -= nums[i];
//		multi /= nums[i];
//		while (i < n - 1 && nums[i] == nums[i + 1]) i++;
//	}
//	return count;
//}
//
//int main()
//{
//	while (cin >> n) {
//		for (int i = 0; i < n; i++) cin >> nums[i];
//		qsort(nums, n, sizeof(int), cmp);
//		cout << findall(nums, 0, 0, 1) << endl;
//	}
//	return 0;
//}









//#include<iostream>
//using namespace std;
//int main()
//{
//    long long num = 0;
//    while (cin >> num) {
//        long long temp = 1;
//        size_t count = 0;
//        for (size_t i = 0; i < 64; ++i) {
//            if ((num & temp) != 0) {
//                ++count;
//            }
//            temp <<= 1;
//        }
//        cout << count << endl;
//    }
//    return 0;
//}







//#include<iostream>
//#include<climits>
//#include<cmath>
//#include<vector>
//using namespace std;
//vector<int> get_div_num(int num) {
//    vector<int> temp;
//    for (int i = 2; i <= sqrt(num); ++i) {
//        if (num % i == 0) {
//            temp.push_back(i);
//            if (num / i != i) temp.push_back(num / i);
//        }
//    }
//    return temp;
//}
//int jump(int n, int m) {
//    vector<int>step(m + 1, INT_MAX);
//    step[n] = 0;
//    for (int i = n; i <= m; ++i) {
//        if (step[i] == INT_MAX) continue;
//        vector<int> div_num = get_div_num(i);
//        for (int j = 0; j < div_num.size(); ++j) {
//            if (div_num[j] + i <= m)
//                step[i + div_num[j]] = step[i + div_num[j]] < step[i] + 1 ? step[i + div_num[j]] : step[i] + 1;
//        }
//    }
//    return step[m] < INT_MAX ? step[m] : -1;
//}
//int main()
//{
//    int n = 0, m = 0, min_step = INT_MAX;
//    while (cin >> n >> m) {
//        min_step = jump(n, m);
//        cout << min_step << endl;
//    }
//    return 0;
//}











//#include <iostream>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<string> split(string str, char sep) {
//    stringstream ss(str);
//    string temp;
//    vector<string> res;
//    while (getline(ss, temp, sep)) {
//        res.push_back(temp);
//    }
//    return res;
//}
//int judgePoker(vector<string> poker) {
//    int flag = -1;
//    if (poker.size() == 1) {
//        flag = 0;//个子
//    }
//    else if (poker.size() == 2) {
//        if (poker[0] == string("joker") || poker[1] == string("joker")) flag = 5;//对王
//        else flag = 1;
//    }
//    else if (poker.size() == 3) flag = 2;
//    else if (poker.size() == 4) flag = 3;
//    else if (poker.size() == 5) flag = 4;
//    return flag;
//}
//
//int main() {
//    string str;
//    vector<string> table = { "3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER" };
//    while (getline(cin, str)) {
//        int win = -1;
//        vector<string> vec = split(str, '-');
//        vector<string> poker1 = split(vec[0], ' ');
//        vector<string> poker2 = split(vec[1], ' ');
//        int flag1 = -1, flag2 = -1;
//        flag1 = judgePoker(poker1);
//        flag2 = judgePoker(poker2);
//        if (flag1 == 5 || flag2 == 5 || flag1 == 3 || flag2 == 3) {
//            if (flag1 == 5) win = 1;
//            else if (flag2 == 5) win = 2;
//            else if (flag1 == flag2 && flag1 == 3) {
//                auto it1 = find(table.begin(), table.end(), poker1[0]);
//                auto it2 = find(table.begin(), table.end(), poker2[0]);
//                if (it1 < it2) win = 2;
//                else win = 1;
//            }
//            else if (flag1 == 3 && flag2 != 3) win = 1;
//            else if (flag1 != 3 && flag2 == 3) win = 2;
//        }
//        else if (flag1 == flag2) {
//            auto it1 = find(table.begin(), table.end(), poker1[0]);
//            auto it2 = find(table.begin(), table.end(), poker2[0]);
//            if (it1 < it2) win = 2;
//            else win = 1;
//        }
//        else win = 0;
//        if (!win) cout << "ERROR" << endl;
//        else if (win == 1) {
//            int i = 0;
//            for (; i < poker1.size() - 1; i++)
//                cout << poker1[i] << " ";
//            cout << poker1[i] << endl;
//        }
//        else if (win == 2) {
//            int i = 0;
//            for (; i < poker2.size() - 1; i++)
//                cout << poker2[i] << " ";
//            cout << poker2[i] << endl;
//        }
//    }
//    return 0;
//}









//#include<iostream>
//using namespace std;
//int main()
//{
//    int n = 0;
//    cin >> n;
//    if (n <= 2) {
//        cout << -1 << endl;
//    }
//    else {
//        if (n % 2 == 1) {
//            cout << 2 << endl;
//        }
//        else {
//            if (n % 4 == 0) cout << 3 << endl;
//            else cout << 4 << endl;
//        }
//    }
//    return 0;
//}







//#include<iostream>
//#include<string>
//#include<cctype>
//#include<cstring>
//using namespace std;
//int main()
//{
//    string str;
//    getline(cin, str);
//
//    char target = 0;
//    cin >> target;
//    target = toupper(target);
//
//    size_t count = 0;
//    size_t left = 0, right = str.size() - 1;
//    while (left < right) {
//        if (target == toupper(str[left])) ++count;
//        if (target == toupper(str[right])) ++count;
//        ++left;
//        --right;
//    }
//    cout << count << endl;
//    return 0;
//}




//#include<iostream>
//using namespace std;
//int get_rabbit_num(int n) {
//    if (n == 1 || n == 2) return 1;
//    return get_rabbit_num(n - 1) + get_rabbit_num(n - 2);
//}
//int main()
//{
//    int n = 0;
//    while (cin >> n) {
//        cout << get_rabbit_num(n) << endl;
//    }
//    return 0;
//}





//#include <iostream> 
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//bool match(int i, int j, string& a, string& b) {
//    if (i == a.length() && j == b.length()) return true;
//    else if (i > a.length() || j > b.length()) return false;
//    if (a[i] == b[j]) return match(i + 1, j + 1, a, b);
//    else if (a[i] == '?') {
//        if (!(isdigit(b[j]) || isalpha(b[j]))) return false;
//        return match(i + 1, j + 1, a, b);
//    }
//    else if (a[i] == '*') {
//        while (a[i + 1] == '*') i++;
//        return match(i, j + 1, a, b) || match(i + 1, j, a, b) || match(i + 1, j + 1, a, b);
//    }
//    return false;
//}
//int main() {
//    string a, b;
//    while (cin >> a >> b) {
//        for (int i = 0; i < a.length(); i++) a[i] = toupper(a[i]);
//        for (int i = 0; i < b.length(); i++) b[i] = toupper(b[i]);
//        if (match(0, 0, a, b)) cout << "true" << endl;
//        else cout << "false" << endl;
//    }
//}






//#include<iostream>
//#include<string>
//#include<vector>
//#include<cctype>
//using namespace std;
//vector<string> section(const string&  str) {
//	vector<string> ret;
//	string str1, str2;
//	for (size_t i = 0; i < str.size(); ++i) {
//		if (isdigit(str[i])) str1.push_back(str[i]);
//		if (isalpha(str[i])) str2.push_back(str[i]);
//	}
//	ret.push_back(str1);
//	ret.push_back(str2);
//	return ret;
//}
//int main()
//{
//	string str;
//	cin >> str;
//	vector<string> ret = section(str);
//	cout << ret[0] << endl;
//	cout << ret[1] << endl;
//	return 0;
//}





//#include<stdio.h>
//#include<ctype.h>
//#define MAX_SIZE 100
//void section(const char* str, char* str1, char* str2) {
//	int length1 = 0, length2 = 0;
//	for (size_t i = 0; str[i] != '\0'; ++i) {
//		if (isdigit(str[i])) str1[length1++] = str[i];
//		if (isalpha(str[i])) str2[length2++] = str[i];
//	}
//}
//int main()
//{
//	char str[MAX_SIZE] = {0};
//	scanf("%s", str);
//	char str1[100] = { 0 }, str2[100] = { 0 };
//	section(str, str1, str2);
//	printf("%s\n", str1);
//	printf("%s\n", str2);
//	return 0;
//}








//#include<iostream>
//#include<string>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    string tree2str(TreeNode* root) {
//        if (root == nullptr) {
//            return string();
//        }
//        string str;
//
//        str += to_string(root->val);
//
//        if (root->left != nullptr || root->right != nullptr) {
//            str += '(';
//            str += tree2str(root->left);
//            str += ')';
//        }
//
//        if (root->right != nullptr) {
//            str += '(';
//            str += tree2str(root->right);
//            str += ')';
//        }
//        return str;
//    }
//};










/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* newhead = NULL;
//    struct ListNode* fast = head, * slow = head;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast) {
//            newhead = fast->next;
//            fast->next = NULL;
//        }
//    }
//    if (newhead == NULL) return NULL;
//
//    int length1 = 0, length2 = 0;
//    struct ListNode* cur = head;
//    while (cur->next != NULL) {
//        ++length1;
//        cur = cur->next;
//    }
//    cur = newhead;
//    while (cur->next != NULL) {
//        ++length2;
//        cur = cur->next;
//    }
//    if (length1 > length2) {
//        for (int i = 0; i < length1 - length2; ++i) {
//            head = head->next;
//        }
//    }
//    if (length1 < length2) {
//        for (int i = 0; i < length2 - length1; ++i) {
//            newhead = newhead->next;
//        }
//    }
//    while (head != newhead) {
//        head = head->next;
//        newhead = newhead->next;
//    }
//    if (head == newhead) return head;
//    return NULL;
//}









/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* fast = head, * slow = head;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast) {
//            struct ListNode* meet = fast;
//            while (meet != head) {
//                meet = meet->next;
//                head = head->next;
//            }
//            return meet;
//        }
//    }
//    return NULL;
//}









//#include<iostream>
//using namespace std;
//int get_ret(int num) {
//    int drunk_num = 0;
//    while (1) {
//        while (num >= 3) {
//            num -= 3;
//            ++drunk_num;
//            ++num;
//        }
//        if (num == 2) return drunk_num + 1;
//        if (num < 3) return drunk_num;
//    }
//}
//int main()
//{
//    int num = 0;
//    while (cin >> num) {
//        if (num == 0) break;
//        cout << get_ret(num) << endl;
//    }
//    return 0;
//}









//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//    string str1, str2;
//    cin >> str1 >> str2;
//    if (str1.size() > str2.size()) {
//        string tmp = str1;
//        str1 = str2;
//        str2 = tmp;
//    }
//    size_t begin1 = 0, begin2 = 0;
//    string temp = "";
//    vector<string> v;
//    while (begin1 < str1.size()) {
//        while (str1[begin1] != str2[begin2] && begin2 < str2.size()) {
//            ++begin2;
//        }
//        if (begin2 == str2.size()) {
//            ++begin1;
//            begin2 = 0;
//        }
//        if (str1[begin1] == str2[begin2])
//        {
//            int flag1 = begin1,flag2 = begin2;
//            while (str1[begin1] == str2[begin2]) {
//                temp += str1[begin1];
//                ++begin1;
//                ++begin2;
//            }
//            if (temp.size() >= 2) {
//                v.push_back(temp);
//            }
//            temp = "";
//            begin1 = flag1;
//            begin2 = flag2 + 1;
//        }
//    }
//    if (v.size() != 0) {
//        int max = v[0].size();
//        int max_pos = 0;
//        for (size_t i = 1; i < v.size(); ++i) {
//            if (v[i].size() > max) {
//                max = v[i].size();
//                max_pos = i;
//            }
//        }
//        cout << v[max_pos] << endl;
//    }
//
//    return 0;
//}









//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//    string str1, str2;
//    cin >> str1 >> str2;
//    size_t begin1 = 0, begin2 = 0;
//    vector<string> v;
//    while (begin1 < str1.size()) {
//        while (str2[begin2] != str1[begin1] && begin1 < str1.size() && begin2 < str2.size()) {
//            ++begin2;
//            if (begin2 == str2.size()) {
//                ++begin1;
//                begin2 = 0;
//            }
//        }
//
//        if (str1[begin1] == str2[begin2]) {
//            int flag1 = begin1, flag2 = begin2;
//            string temp = "";
//            while (str1[begin1] == str2[begin2] && begin1 < str1.size()) {
//                temp += str1[begin1];
//                ++begin1;
//                ++begin2;
//            }
//            v.push_back(temp);
//            temp = "";
//            begin1 = flag1;
//            if ((flag2 + 1) >= str2.size()) {
//                begin2 = 0;
//                begin1++;
//            }
//            else {
//                begin2 = flag2 + 1;
//            }
//        }
//    }
//    size_t max = 0;
//    for (size_t i = 0; i < v.size(); ++i) {
//        if (v[i].size() > max) {
//            max = v[i].size();
//        }
//    }
//    cout << max << endl;
//    return 0;
//}














//#include<iostream>
//#include<vector>
//using namespace std;
//void _shuffle(vector<int>& v)
//{
//    vector<int> first;
//    vector<int> second;
//    for (int i = 0; i < v.size() / 2; ++i) {
//        first.push_back(v[i]);
//        second.push_back(v[i + v.size() / 2]);
//    }
//    for (int j = v.size() - 1; j >= 0; j -= 2) {
//        v[j] = second[j / 2];
//        v[j - 1] = first[j / 2];
//
//    }
//}
//void shuffle(vector<int>& v, int k)
//{
//    for (int i = 0; i < k; ++i) {
//        _shuffle(v);
//    }
//}
//int main()
//{
//    int T = 0;
//    cin >> T;
//    for (int i = 0; i < T; ++i)
//    {
//        int n = 0, k = 0;
//        cin >> n >> k;
//        vector<int> v;
//        v.resize(2 * n);
//        for (int j = 0; j < 2 * n; ++j) {
//            cin >> v[j];
//        }
//        shuffle(v, k);
//        for (int count = 0; count < v.size(); ++count) {
//            cout << v[count] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}










//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    string str;
//    cin >> str;
//    vector<char> v_char;
//    vector<int> v_count;
//    for (int i = 0; i < str.size(); ++i) {
//        if (find(v_char.begin(), v_char.end(), str[i]) == v_char.end()) {
//            v_char.push_back(str[i]);
//            v_count.push_back(1);
//        }
//        else {//有该元素
//            vector<char>::iterator it = find(v_char.begin(), v_char.end(), str[i]);
//            int count = 0;
//            for (int i = 0; i < v_char.size(); ++i) {
//                if (it == v_char.begin() + i) {
//                    count = i;
//                    break;
//                }
//            }
//            ++v_count[count];
//        }
//    }
//    int pos = -1;
//    for (int i = 0; i < v_count.size(); ++i) {
//        if (v_count[i] == 1) {
//            pos = i;
//            break;
//        }
//    }
//    if (pos != -1) {
//        cout << v_char[pos] << endl;
//    }
//    else {
//        cout << -1 << endl;
//    }
//
//    return 0;
//}










//#include<iostream>
//#include<vector>
//using namespace std;
//int CommonDivisor(int x, int y)
//{
//    int max = 0;
//    for (int i = 1; i <= min(x, y); ++i) {
//        if (x % i == 0 && y % i == 0) max = i;
//    }
//    return max;
//}
//int ability(const vector<int>& v, int a)
//{
//    for (size_t i = 0; i < v.size(); ++i) {
//        if (v[i] <= a) a += v[i];
//        if (v[i] > a) a += CommonDivisor(v[i], a);
//    }
//    return a;
//}
//int main()
//{
//    int n = 0, a = 0;
//    while (cin >> n >> a)
//    {
//        vector<int>v;
//        v.resize(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> v[i];
//        }
//
//        cout << ability(v, a) << endl;
//    }
//    return 0;
//}








//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Gift {
//public:
//    int getValue(vector<int> gifts, int n) {
//        sort(gifts.begin(), gifts.end());
//        int ret = gifts[n / 2];
//        for (size_t i = 0; i < gifts.size();) {
//            if (gifts[i] != ret) {
//                gifts.erase(gifts.begin() + i);
//            }
//            else {
//                ++i;
//            }
//        }
//        if (gifts.size() >= n / 2) return ret;
//        else return 0;
//    }
//};









//bool PrevOrderCompare(struct TreeNode* root, int BenchMark)
//{
//    if (root == NULL) return true;
//    return (root->val == BenchMark)
//        && PrevOrderCompare(root->left, BenchMark)
//        && PrevOrderCompare(root->right, BenchMark);
//}
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL) return true;
//    return PrevOrderCompare(root, root->val);
//}







//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL) return true;
//    if (root->left != NULL && root->left->val != root->val) return false;
//    if (root->right != NULL && root->right->val != root->val) return false;
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//}








/*
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的
*/
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL) return true;
//    if (p == NULL && q != NULL) return false;
//    if (p != NULL && q == NULL) return false;
//    if (p->val != q->val) return false;
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}










/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/
//bool Symmetric(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL) return true;
//    if (p == NULL && q != NULL) return false;
//    if (p != NULL && q == NULL) return false;
//    if (p->val != q->val) return false;
//    return Symmetric(p->left, q->right) && Symmetric(p->right, q->left);
//}
//bool isSymmetric(struct TreeNode* root) {
//    return Symmetric(root->left, root->right);
//}






/*
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树
*/
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL) return true;
//    if (p == NULL && q != NULL) return false;
//    if (p != NULL && q == NULL) return false;
//    if (p->val != q->val) return false;
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL) return false;
//    if (isSameTree(root, subRoot)) return true;
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}











//class Bonus {
//public:
//    int _getMost(vector<vector<int>>& board, int row, int col) {
//        if (row == 5 && col == 5) return board[row][col];
//        if (row == 6 || col == 6) return 0;
//        int ret1 = 0, ret2 = 0;
//        ret1 = _getMost(board, row + 1, col) + board[row][col];
//        ret2 = _getMost(board, row, col + 1) + board[row][col];
//        return max(ret1, ret2);
//    }
//    int getMost(vector<vector<int>> board) {
//        return _getMost(board, 0, 0);
//    }
//};




/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
*/
//class Solution {
//public:
//    bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& sk) {
//        if (root == nullptr) return false;
//
//        sk.push(root);
//        if (root == x) return true;
//
//        if (FindPath(root->left, x, sk)) return true;
//        if (FindPath(root->right, x, sk)) return true;
//
//        sk.pop();
//        return false;
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        stack<TreeNode*> pPath, qPath;
//        FindPath(root, p, pPath);
//        FindPath(root, q, qPath);
//
//        while (pPath.size() != qPath.size()) {
//            if (pPath.size() > qPath.size()) pPath.pop();
//            else qPath.pop();
//        }
//        while (pPath.top() != qPath.top()) {
//            pPath.pop();
//            qPath.pop();
//        }
//        return pPath.top();
//    }
//};

//class Solution {
//public:
//    bool Find(TreeNode* sub, TreeNode* x) {
//        if (sub == nullptr) return false;
//        return sub == x || Find(sub->left, x) || Find(sub->right, x);
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == nullptr) return nullptr;
//        if (root == p || root == q) return root;
//
//        bool pInLeft, pInRight, qInLeft, qInRight;
//        pInLeft = Find(root->left, p);
//        pInRight = !pInLeft;
//        qInLeft = Find(root->left, q);
//        qInRight = !qInLeft;
//
//        if ((pInLeft && qInRight) || (pInRight && qInLeft)) {
//            return root;
//        }
//        else if (pInLeft && qInLeft) {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else {//pInRight && qInRight
//            return lowestCommonAncestor(root->right, p, q);
//        }
//    }
//};











/*二叉树创建字符串*/
//class Solution {
//public:
//    string tree2str(TreeNode* root) {
//        if (root == nullptr) return string();
//
//        string str;
//        str += to_string(root->val);
//
//        if (root->left != nullptr || root->right != nullptr) {
//            str += '(';
//            str += tree2str(root->left);
//            str += ')';
//        }
//
//        if (root->right != nullptr) {
//            str += '(';
//            str += tree2str(root->right);
//            str += ')';
//        }
//        return str;
//    }
//};






/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历
*/
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        queue<TreeNode*> q;
//        size_t levelSize = 0;
//        if (root != nullptr) {
//            q.push(root);
//            levelSize = 1;
//        }
//        vector<vector<int>>vv;
//        while (!q.empty()) {
//            vector<int>v;
//            for (size_t i = 0; i < levelSize; ++i) {
//                TreeNode* front = q.front();
//                v.push_back(front->val);
//                q.pop();
//
//                if (front->left != nullptr) q.push(front->left);
//                if (front->right != nullptr) q.push(front->right);
//            }
//            vv.push_back(v);
//            levelSize = q.size();
//        }
//        return vv;
//    }
//};









/*
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历
*/
//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        queue<TreeNode*> q;
//        size_t levelSize = 0;
//        if (root != nullptr) {
//            q.push(root);
//            levelSize = 1;
//        }
//        vector<vector<int>>vv;
//        while (!q.empty()) {
//            vector<int>v;
//            for (size_t i = 0; i < levelSize; ++i) {
//                TreeNode* front = q.front();
//                v.push_back(front->val);
//                q.pop();
//
//                if (front->left != nullptr) q.push(front->left);
//                if (front->right != nullptr) q.push(front->right);
//            }
//            vv.push_back(v);
//            levelSize = q.size();
//        }
//        reverse(vv.begin(), vv.end());
//        return vv;
//    }
//};





//非递归后序遍历
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root) {
//        stack<TreeNode*> sk;
//        vector<int>v;
//        TreeNode* cur = root;
//        TreeNode* prev = nullptr;
//        while (cur != nullptr || !sk.empty()) {
//            //左路结点
//            while (cur != nullptr) {
//                sk.push(cur);
//                cur = cur->left;
//            }
//            //左路结点的右子树
//            TreeNode* top = sk.top();
//            if (top->right == nullptr || top->right == prev) {
//                v.push_back(top->val);
//                prev = top;
//                sk.pop();
//            }
//            else {
//                cur = top->right;//子问题 访问右子树
//            }
//        }
//        return v;
//    }
//};





//非递归中序遍历
//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        stack<TreeNode*> sk;
//        vector<int>v;
//        TreeNode* cur = root;
//        while (cur != nullptr || !sk.empty()) {
//            //左路结点入栈
//            while (cur != nullptr) {
//                sk.push(cur);
//                cur = cur->left;
//            }
//            //左路结点的右子树
//            TreeNode* top = sk.top();
//            v.push_back(top->val);
//            sk.pop();
//            cur = top->right;//子问题 访问右子树
//        }
//        return v;
//    }
//};






//非递归后序遍历
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//        stack<TreeNode*> sk;
//        vector<int>v;
//        TreeNode* cur = root;
//        while (cur != nullptr || !sk.empty()) {
//            //左路结点
//            while (cur != nullptr) {
//                v.push_back(cur->val);
//                sk.push(cur);
//                cur = cur->left;
//            }
//            //左路结点的右子树
//            TreeNode* top = sk.top();
//            sk.pop();
//            cur = top->right;//子问题 访问右子树
//        }
//        return v;
//    }
//};








//前序与中序
//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inBegin, int inEnd) {
//        if (inBegin > inEnd) return nullptr;
//
//        TreeNode* node = new TreeNode(preorder[previ++]);
//        int ini = inBegin;
//        while (ini <= inEnd) {
//            if (inorder[ini] == node->val) break;
//            else ++ini;
//        }
//        node->left = _buildTree(preorder, inorder, previ, inBegin, ini - 1);
//        node->right = _buildTree(preorder, inorder, previ, ini + 1, inEnd);
//        return node;
//
//    }
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        int i = 0;
//        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
//    }
//};








//后序与中序
//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posti, int inBegin, int inEnd) {
//        if (inBegin > inEnd) return nullptr;
//        TreeNode* node = new TreeNode(postorder[posti--]);
//        int ini = inBegin;
//        while (ini <= inEnd) {
//            if (inorder[ini] == node->val) break;
//            else ++ini;
//        }
//        node->right = _buildTree(inorder, postorder, posti, ini + 1, inEnd);
//        node->left = _buildTree(inorder, postorder, posti, inBegin, ini - 1);
//        return node;
//    }
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        int i = postorder.size() - 1;
//        return _buildTree(inorder, postorder, i, 0, inorder.size() - 1);
//    }
//};






//#include <iostream>
//using namespace std;
//int main()
//{
//    string str;
//    str.resize(10001);
//    while (cin >> str)
//    {
//        int sum = 0;
//        for (int i = 0; i < str.size(); ++i)
//            sum += (str[i] - '0');
//        int tmp = sum / 10;
//        while (tmp)
//        {
//            int k = sum;
//            sum = 0;
//            while (k)
//            {
//                int j = k % 10;
//                k = k / 10;
//                sum += j;
//            }
//            tmp = sum / 10;
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}







/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点
*/
//class Solution {
//public:
//    void construct_paths(TreeNode* root, string path, vector<string>& paths) {
//        if (root == nullptr) return;
//        path += to_string(root->val);
//        if (root->left == nullptr && root->right == nullptr) {
//            paths.push_back(path);
//        }
//        else {
//            path += "->";
//            construct_paths(root->left, path, paths);
//            construct_paths(root->right, path, paths);
//        }
//    }
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<string> paths;
//        construct_paths(root, "", paths);
//        return paths;
//    }
//};






//void swap_lr(TreeNode* root) {
//	if (root == NULL) return;
//	if (root->lchild == NULL && root->rchild == NULL) return;
//
//	TreeNode* tmp = root->lchild;
//	root->lchild = root->rchild;
//	root->rchild = tmp;
//
//	swap_lr(root->lchild);
//	swap_lr(root->rchild);
//}





//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//int main()
//{
//    string length, radius;
//    while (cin >> length >> radius) {
//
//        double _length = 0, _radius = 0;
//        for (int i = length.size() - 1;i >= 0; --i) {
//            _length += (length[i] - (double)'0') * pow(10, length.size() - i) / 100;
//        }
//        for (int i = radius.size() - 1; i >= 0; --i) {
//            _radius += (radius[i] - (double)'0') * pow(10, radius.size() - i) / 100;
//        }
//
//        if (_radius < _length / 6.28) cout << "No" << endl;
//        else cout << "Yes" << endl;
//    }
//    return 0;
//}







//class Solution {
//public:
//    int _jumpFloorII(int number, int* sum) {
//        if (number == 0) return 1;
//        for (int i = 1; i <= number; ++i) {
//            *sum += jumpFloorII(number - i);
//        }
//        return *sum;
//    }
//    int jumpFloorII(int number) {
//        int sum = 0;
//        return _jumpFloorII(number, &sum);
//    }
//};








/*
给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序
*/
//class Solution {
//public:
//    struct Less {
//        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2) const {
//            if (kv1.second < kv2.second) return true;
//            else if (kv1.second > kv2.second) return false;
//            else {//kv1.first == kv2.first
//                return kv1.first > kv2.first;
//            }
//        }
//    };
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> count;
//        for (size_t i = 0; i < words.size(); ++i) {
//            ++count[words[i]];
//        }
//        priority_queue<pair<string, int>, vector<pair<string, int>>, Less> maxHeap;
//        for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it) {
//            maxHeap.push(*it);
//        }
//
//        vector<string>v;
//        while (k--) {
//            v.push_back(maxHeap.top().first);
//            maxHeap.pop();
//        }
//        return v;
//    }
//};



//#include<vector>
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//class Solution {
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> count;
//        for (size_t i = 0; i < words.size(); ++i) {
//            ++count[words[i]];
//        }
//
//        multimap<int, string, greater<int>> sortMap;
//        for (auto& kv : count) {
//            sortMap.insert(make_pair(kv.second, kv.first));
//        }
//
//        vector<string> v;
//        multimap<int, string, greater<int>>::iterator it = sortMap.begin();
//        for (size_t i = 0; i < k; ++i) {
//            v.push_back(it->second);
//            ++it;
//        }
//        return v;
//    }
//};
//int main() 
//{
//    vector<string >words = { "i", "love", "leetcode", "i", "love", "coding" };
//    int k = 2;
//    Solution s;
//    vector<string> ret = s.topKFrequent(words, k);
//
//    return 0;
//}








/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序
*/
//#include<iostream>
//#include<map>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> ret;
//
//        map<int, int> mp1;
//        for (auto& v : nums1) {
//            mp1.insert(make_pair(v, 1));
//        }
//
//        map<int, int> mp2;
//        for (auto& v : nums2) {
//            mp2.insert(make_pair(v, 1));
//        }
//
//        map<int, int> mp;
//        for (auto& kv : mp1) {
//            ++mp[kv.first];
//        }
//        for (auto& kv : mp2) {
//            ++mp[kv.first];
//        }
//        for (auto& kv : mp) {
//            if (kv.second > 1) ret.push_back(kv.first);
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> nums1 = {1,2,2,1};
//    vector<int> nums2 = {2,2};
//    vector<int> ret = s.intersection(nums1, nums2);
//    for (size_t i = 0; i < ret.size(); ++i) {
//        cout << ret[i] << " ";
//    }
//    return 0;
//}











//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	v.resize(10);
//	for (int i = 0; i < 10; ++i) {
//		cin >> v[i];
//	}
//	int high = 0;
//	cin >> high;
//	high += 30;
//
//	int count = 0;
//	for (int i = 0; i < 10; ++i) {
//		if (high >= v[i]) ++count;
//	}
//	cout << count << endl;
//
//	return 0;
//}






//#include<iostream>
//using namespace std;
//int main()
//{
//    double a = 0, b = 0, c = 0;
//    while (cin >> a >> b >> c) {
//        if (a + b > c && a + c > b && b + c > a) {
//            cout << "Yes" << endl;
//        }
//        else cout << "No" << endl;
//    }
//    return 0;
//}







//class Solution {
//public:
//    int Add(int num1, int num2)
//    {
//        int n1 = (num1 & num2) << 1;
//        int n2 = num1 ^ num2;
//        while (n1 & n2){
//            num1 = n1; num2 = n2;
//            n1 = (num1 & num2) << 1;
//            n2 = num1 ^ num2;
//        }
//        return n1 | n2;
//    }
//};





//#include <bits/stdc++.h>
//using namespace std;
//
//struct list_node {
//    int val;
//    struct list_node* next;
//};
//
//list_node* input_list(void)
//{
//    int n, val;
//    list_node* phead = new list_node();
//    list_node* cur_pnode = phead;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; ++i) {
//        scanf("%d", &val);
//        if (i == 1) {
//            cur_pnode->val = val;
//            cur_pnode->next = NULL;
//        }
//        else {
//            list_node* new_pnode = new list_node();
//            new_pnode->val = val;
//            new_pnode->next = NULL;
//            cur_pnode->next = new_pnode;
//            cur_pnode = new_pnode;
//        }
//    }
//    return phead;
//}
//
//
//list_node* reverse_list(list_node* head, int L, int R)
//{
//    list_node* dummyNode = (list_node*)malloc(sizeof(list_node));
//    dummyNode->next = head;
//    list_node* pre = dummyNode;
//    for (int i = 0; i < L - 1; i++) {
//        pre = pre->next;
//    }
//    list_node* cur = pre->next;
//    list_node* next;
//    for (int i = 0; i < R - L; i++) {
//        next = cur->next;
//        cur->next = next->next;
//        next->next = pre->next;
//        pre->next = next;
//    }
//    return dummyNode->next;
//}
//
//void print_list(list_node* head)
//{
//    while (head != NULL) {
//        printf("%d ", head->val);
//        head = head->next;
//    }
//    puts("");
//}
//
//
//int main()
//{
//    int L, R;
//    list_node* head = input_list();
//    scanf("%d%d", &L, &R);
//    list_node* new_head = reverse_list(head, L, R);
//    print_list(new_head);
//    return 0;
//}






//#include <iostream>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n) {
//        if (n == 0) break;
//        size_t total = 0, sum = 0;
//        sum = pow(5, n) - 4;
//        total = pow(4, n) + n - 4;
//        cout << sum << " " << total << endl;
//    }
//    return 0;
//}







//class Solution {
//public:
//    int getFirstUnFormedNum(vector<int> arr, int len) {
//        int sum = 0, min = arr[0];
//        for (int i = 0; i < len; ++i) {
//            sum += arr[i];
//            if (arr[i] < min) min = arr[i];
//        }
//        vector<int> dp(sum + 1, 0);
//        for (int i = 0; i < len; ++i) {
//            for (int j = sum; j >= arr[i]; --j) {
//                if (dp[j - arr[i]] + arr[i] > dp[j]) {
//                    dp[j] = dp[j - arr[i]] + arr[i];
//                }
//            }
//        }
//
//        for (int i = min; i <= sum; ++i) {
//            if (i != dp[i])
//                return i;
//        }
//        return sum + 1;
//    }
//};








//#include <iostream>
//using namespace std;
//int main() {
//    int n = 0;
//    while (cin >> n) {
//        if (n == 0) continue;
//        int count = 0;
//        while (n > 1) {
//            n = n / 3 + (n % 3 > 0);
//            count += 1;
//        }
//        cout << count << endl;
//    }
//    return 0;
//}











//#include <iostream>
//#include <string>
//using namespace std; 
//int main() {
//    const string flag = "ABCDEFGHIJKLMNOPQRSTUVWSYZ";
//    string str;
//    while (getline(cin, str)) {
//        for (int i = 0; i < str.size(); ++i) {
//            if (isalpha(str[i])) {
//                if ('A' <= str[i]) {
//                    str[i] = 'E' < str[i] ? (str[i] - 5) : (str[i] + 21);
//                }
//            }
//        }
//        cout << str << endl;
//    }
//    return 0;
//}









//#include <iostream>
//using namespace std;
//bool isPrime(int num)
//{
//    if (num < 2) return false;
//    if (num == 2) return true;
//    if (num % 2 == 0) return false;
//    for (int i = 3; i * i <= num; i += 2) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//
//int countFactors(int num, int start)
//{
//    int count = 0;
//    if (isPrime(num)) {
//        ++count;
//        return count;
//    }
//    else {
//        for (int i = start; i < num; ++i) {
//            if (0 == num % i) {
//                ++count;
//                while (0 == num % i) {
//                    num /= i;
//                }
//                return count + countFactors(num, i + 1);
//            }
//        }
//    }
//    return count;
//}
//
//int main()
//{
//    int num = 0;
//    while (cin >> num) {
//        int count = countFactors(num, 2);
//        cout << count << endl;
//    }
//    return 0;
//}













//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	map<string,int> mp;
//	int count = 0;
//	while (cin >> str) {
//		if (str == "0") break;
//		if(mp.insert(make_pair(str, count)).second)
//			++count;
//	}
//	map<int, string> ret;
//	for (auto& e : mp) {
//		ret.insert(make_pair(e.second, e.first));
//	}
//	for (auto& e : ret) {
//		cout << e.second;
//	}
//	return 0;
//}






//#include<iostream>
//#include<string>
//using namespace std;
//inline bool good_time(register string& str) {
//	if (str[0] != '0') {
//		int ch = str[0] - str[1];
//		return str[1] - str[2] == ch && str[2] - str[3] == ch;
//	}
//	else {
//		int ch = str[1] - str[2];
//		return str[2] - str[3] == ch;
//	}
//}
//int main()
//{
//	string str = "0000";
//	long long minuter = 0;
//	cin >> minuter;
//	int count = 0;
//	for (long long i = 0; i < minuter; ++i) {
//		if (good_time(str)) ++count;
//
//		if (str[0] == '2' && str[1] == '3' && str[2] == '5' && str[3] == '9') {
//			str[0] = str[1] = str[2] = str[3] = '0';
//		}
//		else if (str[1] == '9' && str[2] == '5' && str[3] == '9') {
//			++str[0];
//			str[1] = str[2] = str[3] = '0';
//		}
//		else if (str[2] == '5' && str[3] == '9') {
//			str[1]++;
//			str[2] = str[3] = '0';
//		}
//		else if (str[3] == '9') {
//			++str[2];
//			str[3] = '0';
//		}
//		else {
//			++str[3];
//		}
//	}
//	if (good_time(str)) ++count;
//	cout << count << endl;
//	return 0;
//}







//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	double n = 0;
//	cin >> n;
//	vector<double>v;
//	v.resize(n);
//	for (double i = 0; i < n; ++i) {
//		cin >> v[i];
//	}
//	double w = 0;
//	cin >> w;
//	sort(v.begin(), v.end());
//
//	double max = v[0];
//	for (double i = 0; i < v.size(); ++i) {
//		if (w > v[i]) max = v[i];
//	}
//
//
//	double count = 0;
//	vector<double> ge;
//	for (double i = 0; i < v.size() - 1; ++i) {
//		max -= v[i];
//		ge.push_back(v[i]);
//		if (max >= 0) ++count;
//		if (ge.size() == 0 && max == 0) break;
//	}
//	cout << count << endl;
//	return 0;
//}
//









//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int get_fac(int min) {
//	int sum = 0;
//	for (int i = 1; i <= min; ++i) {
//		sum += i;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0, m = 0, x = 0, y = 0;
//	cin >> n >> m >> x >> y;
//	string str;
//	cin >> str;
//	vector<vector<int>> vv;
//	for (int i = 0; i < n; ++i) {
//		vector<int> temp;
//		for (int j = 0; j < n; ++j) {
//			temp.push_back(0);
//		}
//		vv.push_back(temp);
//		temp.clear();
//	}
//
//	int pos1 = vv.size() - y, pos2 = x - 1;
//
//	vector<vector<int>> time = vv;
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			for (int k = 0; k < n; ++k) {
//				if (j == pos1 && k == pos2) {
//					vv[j][k] += get_fac(time[j][k]);
//					time[j][k] = 0;
//					continue;
//				}
//				time[j][k]++;
//			}
//		}
//		if (str[i] == 'N') {
//			pos1--;
//		}
//		else if (str[i] == 'S') {
//			pos1++;
//		}
//		else if (str[i] == 'W') {
//			pos2--;
//		}
//		else {
//			pos2++;
//		}
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j) {
//			vv[i][j] += get_fac(time[i][j]);
//		}
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j) {
//			cout << vv[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}











//#include<queue>
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//int main()
//{
//	int n = 0,nmax = 0;
//	cin >> n >> nmax;
//	vector<pair<int, int>> q;
//	int lastans = 0;
//	for (int i = 0; i < n; ++i) {
//		int op = 0, x = 0, y = 0;
//		cin >> op >> x >> y;
//		x ^= lastans;
//		y ^= lastans;
//		if (op == 1) {
//			q.push_back(make_pair(x, y));
//		}
//		else if(op == 2) {
//			if(!q.empty())
//				q.erase(q.end() - 1);
//		}
//		else if (op == 3) {
//			if (q.size() == 0) {
//				lastans = 0;
//				cout << lastans << endl;
//				continue;
//			}
//			vector<pair<int, int>>tmp = q;
//			multimap<int, int> mp;
//			for (int i = 0; i < q.size(); ++i) {
//				mp.insert(q[i]);
//			}
//			multimap<int, int>ret;
//			for (auto& e : mp) {
//				ret.insert(make_pair(e.second, e.first));
//			}
//			int i = 0;
//			for (auto& e : ret) {
//				q[i] = make_pair(e.second, e.first);
//				++i;
//			}
//			int count = 0;
//			for (int i = 0; i < q.size(); ++i) {
//				x -= q[i].first;
//				if(x >= 0) ++count;
//			}
//			int sum = 0;
//			for (int i = 0; i < count; ++i) {
//				sum += q[i].second;
//			}
//			lastans = sum;
//			q = tmp;
//			cout << lastans << endl;
//		}
//
//	}
//	return 0;
//}










//#include<iostream>
//#include<map>
//#include<vector>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    bool repeat(string::iterator first, string::iterator second)
//    {
//        map<char, int> mp;
//        for (; first != second; ++first) {
//            ++mp[*first];
//        }
//        ++mp[*first];
//        for (auto& e : mp) {
//            if (e.second != 1) return false;
//        }
//        return true;
//    }
//    int lengthOfLongestSubstring(string s) {
//        string ret;
//        for (int length = s.size() - 1; length >= 0; --length)
//        {
//            for (int i = 0; i + length < s.size(); ++i)
//            {
//                if (repeat(s.begin() + i, s.begin() + i + length)) {
//                    ret = string(s.begin() + i, s.begin() + i + length + 1);
//                }
//            }
//            if (ret.size() != 0) break;
//        }
//        return ret.size();
//    }
//};
//int main()
//{
//    Solution s;
//    string str = "cjgtykwpawkaofxvegafbleamibtikekvkguuelwbwwpdwkhemphyvimflhnxlzsxforkaqlymcbknl";
//    cout << s.lengthOfLongestSubstring(str) << endl;
//    return 0;
//}






//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int minprice = INT_MAX;
//        int ret = 0;
//        //第一天不可能作为卖出天
//        for (size_t i = 0; i < prices.size(); ++i) {
//            ret = max(ret, prices[i] - minprice);
//            minprice = min(minprice, prices[i]);
//        }
//        return ret;
//    }
//};





//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    int hammingDistance(int x, int y) {
//        int XOR = x ^ y;
//        int count = 0;
//        while (XOR) {
//            if (XOR & 1) ++count;
//            XOR >>= 1;
//        }
//        return count;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.hammingDistance(4, 1);
//    return 0;
//}
////优化
//class Solution {
//public:
//    int hammingDistance(int x, int y) {
//        int s = x ^ y, ret = 0;
//        while (s) {
//            s &= s - 1;
//            ret++;
//        }
//        return ret;
//    }
//};










//#include<iostream>
//#include<string>
//#include<iomanip>
//#include<cstdlib>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define MAXN 9999      //每一位的数
//#define MAXSIZE 10     //10*9999四位，共40位
//#define DLEN 4
//
//class BigNum
//{
//private:
//    int a[500];    //可以控制大数的位数
//    int len;       //大数长度
//public:
//    BigNum() { len = 1; memset(a, 0, sizeof(a)); }   //构造函数
//    BigNum(const int);       //将一个int类型的变量转化为大数
//    BigNum(const char*);     //将一个字符串类型的变量转化为大数
//    BigNum(const BigNum&);  //拷贝构造函数
//    BigNum& operator=(const BigNum&);   //重载赋值运算符，大数之间进行赋值运算
//
//    friend istream& operator>>(istream&, BigNum&);   //重载输入运算符
//    friend ostream& operator<<(ostream&, BigNum&);   //重载输出运算符
//
//    BigNum operator+(const BigNum&) const;   //重载加法运算符，两个大数之间的相加运算
//    BigNum operator-(const BigNum&) const;   //重载减法运算符，两个大数之间的相减运算
//    BigNum operator*(const BigNum&) const;   //重载乘法运算符，两个大数之间的相乘运算
//    BigNum operator/(const int&) const;    //重载除法运算符，大数对一个整数进行相除运算
//
//    BigNum operator^(const int&) const;    //大数的n次方运算
//    int    operator%(const int&) const;    //大数对一个int类型的变量进行取模运算
//    bool   operator>(const BigNum& T)const;   //大数和另一个大数的大小比较
//    bool   operator>(const int& t)const;      //大数和一个int类型的变量的大小比较
//
//    void print();       //输出大数
//};
//BigNum::BigNum(const int b)     //将一个int类型的变量转化为大数
//{
//    int c, d = b;
//    len = 0;
//    memset(a, 0, sizeof(a));
//    while (d > MAXN)
//    {
//        c = d - (d / (MAXN + 1)) * (MAXN + 1); cout << endl << "TEMP:" << c << endl;
//        d = d / (MAXN + 1);
//        a[len++] = c;
//    }
//    a[len++] = d;
//}
//BigNum::BigNum(const char* s)     //将一个字符串类型的变量转化为大数
//{
//    int t, k, index, l, i;
//    memset(a, 0, sizeof(a));
//    l = strlen(s);
//    len = l / DLEN;
//    if (l % DLEN)
//        len++;
//    index = 0;
//    for (i = l - 1; i >= 0; i -= DLEN)
//    {
//        t = 0;
//        k = i - DLEN + 1;
//        if (k < 0)
//            k = 0;
//        for (int j = k; j <= i; j++)
//            t = t * 10 + s[j] - '0';
//        a[index++] = t;
//    }
//}
//BigNum::BigNum(const BigNum& T) : len(T.len)  //拷贝构造函数
//{
//    int i;
//    memset(a, 0, sizeof(a));
//    for (i = 0; i < len; i++)
//        a[i] = T.a[i];
//}
//BigNum& BigNum::operator=(const BigNum& n)   //重载赋值运算符，大数之间进行赋值运算
//{
//    int i;
//    len = n.len;
//    memset(a, 0, sizeof(a));
//    for (i = 0; i < len; i++)
//        a[i] = n.a[i];
//    return *this;
//}
//istream& operator>>(istream& in, BigNum& b)   //重载输入运算符
//{
//    char ch[MAXSIZE * 4];
//    int i = -1;
//    in >> ch;
//    int l = strlen(ch);
//    int count = 0, sum = 0;
//    for (i = l - 1; i >= 0;)
//    {
//        sum = 0;
//        int t = 1;
//        for (int j = 0; j < 4 && i >= 0; j++, i--, t *= 10)
//        {
//            sum += (ch[i] - '0') * t;
//        }
//        b.a[count] = sum;
//        count++;
//    }
//    b.len = count++;
//    return in;
//
//}
//ostream& operator<<(ostream& out, BigNum& b)   //重载输出运算符
//{
//    int i;
//    cout << b.a[b.len - 1];
//    for (i = b.len - 2; i >= 0; i--)
//    {
//        cout.width(DLEN);
//        cout.fill('0');
//        cout << b.a[i];
//    }
//    return out;
//}
//
//BigNum BigNum::operator+(const BigNum& T) const   //两个大数之间的相加运算
//{
//    BigNum t(*this);
//    int i, big;      //位数
//    big = T.len > len ? T.len : len;
//    for (i = 0; i < big; i++)
//    {
//        t.a[i] += T.a[i];
//        if (t.a[i] > MAXN)
//        {
//            t.a[i + 1]++;
//            t.a[i] -= MAXN + 1;
//        }
//    }
//    if (t.a[big] != 0)
//        t.len = big + 1;
//    else
//        t.len = big;
//    return t;
//}
//BigNum BigNum::operator-(const BigNum& T) const   //两个大数之间的相减运算
//{
//    int i, j, big;
//    bool flag;
//    BigNum t1, t2;
//    if (*this > T)
//    {
//        t1 = *this;
//        t2 = T;
//        flag = 0;
//    }
//    else
//    {
//        t1 = T;
//        t2 = *this;
//        flag = 1;
//    }
//    big = t1.len;
//    for (i = 0; i < big; i++)
//    {
//        if (t1.a[i] < t2.a[i])
//        {
//            j = i + 1;
//            while (t1.a[j] == 0)
//                j++;
//            t1.a[j--]--;
//            while (j > i)
//                t1.a[j--] += MAXN;
//            t1.a[i] += MAXN + 1 - t2.a[i];
//        }
//        else
//            t1.a[i] -= t2.a[i];
//    }
//    t1.len = big;
//    while (t1.a[len - 1] == 0 && t1.len > 1)
//    {
//        t1.len--;
//        big--;
//    }
//    if (flag)
//        t1.a[big - 1] = 0 - t1.a[big - 1];
//    return t1;
//}
//
//BigNum BigNum::operator*(const BigNum& T) const   //两个大数之间的相乘运算
//{
//    BigNum ret;
//    int i, j, up;
//    int temp, temp1;
//    for (i = 0; i < len; i++)
//    {
//        up = 0;
//        for (j = 0; j < T.len; j++)
//        {
//            temp = a[i] * T.a[j] + ret.a[i + j] + up;
//            if (temp > MAXN)
//            {
//                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
//                up = temp / (MAXN + 1);
//                ret.a[i + j] = temp1;
//            }
//            else
//            {
//                up = 0;
//                ret.a[i + j] = temp;
//            }
//        }
//        if (up != 0)
//            ret.a[i + j] = up;
//    }
//    ret.len = i + j;
//    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
//        ret.len--;
//    return ret;
//}
//BigNum BigNum::operator/(const int& b) const   //大数对一个整数进行相除运算
//{
//    BigNum ret;
//    int i, down = 0;
//    for (i = len - 1; i >= 0; i--)
//    {
//        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
//        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
//    }
//    ret.len = len;
//    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
//        ret.len--;
//    return ret;
//}
//int BigNum::operator %(const int& b) const    //大数对一个int类型的变量进行取模运算
//{
//    int i, d = 0;
//    for (i = len - 1; i >= 0; i--)
//    {
//        d = ((d * (MAXN + 1)) % b + a[i]) % b;
//    }
//    return d;
//}
//BigNum BigNum::operator^(const int& n) const    //大数的n次方运算
//{
//    BigNum t, ret(1);
//    int i;
//    if (n < 0)
//        exit(-1);
//    if (n == 0)
//        return 1;
//    if (n == 1)
//        return *this;
//    int m = n;
//    while (m > 1)
//    {
//        t = *this;
//        for (i = 1; i << 1 <= m; i <<= 1)
//        {
//            t = t * t;
//        }
//        m -= i;
//        ret = ret * t;
//        if (m == 1)
//            ret = ret * (*this);
//    }
//    return ret;
//}
//bool BigNum::operator>(const BigNum& T) const   //大数和另一个大数的大小比较
//{
//    int ln;
//    if (len > T.len)
//        return true;
//    else if (len == T.len)
//    {
//        ln = len - 1;
//        while (a[ln] == T.a[ln] && ln >= 0)
//            ln--;
//        if (ln >= 0 && a[ln] > T.a[ln])
//            return true;
//        else
//            return false;
//    }
//    else
//        return false;
//}
//bool BigNum::operator >(const int& t) const    //大数和一个int类型的变量的大小比较
//{
//    BigNum b(t);
//    return *this > b;
//}
//
//void BigNum::print()    //输出大数
//{
//    int i;
//    cout << a[len - 1];
//    for (i = len - 2; i >= 0; i--)
//    {
//        cout.width(DLEN);
//        cout.fill('0');
//        cout << a[i];
//    }
//    cout << endl;
//}
//int main()
//{
//    BigNum num = 0;
//    cin >> num;
//    string ret = "";
//    while (num > 0)
//    {
//        ret += (num % 2) + '0';
//        num = num / 2;
//    }
//
//    long long count = 0;
//    for (size_t i = 0; i < ret.size(); ++i)
//    {
//        if (ret[i] == '1') ++count;
//    }
//    cout << count << endl;
//    return 0;
//}




//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	map<int, int> mp;
//	for (int i = 0; i < n; ++i) {
//		int temp = 0;
//		cin >> temp;
//		++mp[temp];
//	}
//	for (auto& e : mp) {
//		if (e.second > 1) cout << e.first << " ";
//	}
//	return 0;
//}





//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int m = 0;
//	cin >> m;
//	vector<int> max, min, total;
//	for (int i = 0; i < m; ++i) {
//		int tmp = 0;
//		cin >> tmp;
//		if (tmp >= 0) max.push_back(tmp);
//		if (tmp < 0) min.push_back(tmp);
//		total.push_back(tmp);
//	}
//	if (min.size() != 0) {
//		if (min.size() % 2 != 0) {
//			int min_num = min[0];
//			for (int i = 1; i < min.size(); ++i) {
//				if (abs(min[i]) > abs(min_num)) {
//					min_num = min[i];
//				}
//			}
//			for (int i = 0; i < total.size(); ++i) {
//				if (total[i] == min_num) {
//					total.erase(total.begin() + i);
//					break;
//				}
//			}
//
//			multimap<int, int> mp;
//			for (int i = 0; i < total.size(); ++i) {
//				mp.insert(make_pair(abs(total[i]), total[i]));
//			}
//			vector<int>ret;
//			for (auto& e : mp) {
//				ret.push_back(e.second);
//			}
//			int sum = min_num;
//			for (int i = ret.size() - 1; i > ret.size() - 5; --i) {
//				sum *= ret[i];
//			}
//
//			cout << sum << endl;
//		}
//		else {
//			multimap<int, int> mp;
//			for (int i = 0; i < total.size(); ++i) {
//				mp.insert(make_pair(abs(total[i]), total[i]));
//			}
//			for()
//		}
//	}
//	else {//min.size() == 0
//		sort(total.begin(), total.end());
//		int sum = total[0];
//		for (int i = 1; i < 5; ++i) {
//			sum *= total[i];
//		}
//		cout << sum << endl;
//	}
//
//	return 0;
//}



//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <climits>
//using namespace std;
//vector<vector <int>> zuhe(vector<int> in, int target) {//target 是希望选择M个作组合,in是选择的范围，长度为N
//	vector<vector <int>> output;
//	for (int i = 0; i < pow(2, in.size()); i++) {
//		int temp = 0, count = 0;
//		vector<int> weishu;
//		for (int j = 0; j < in.size(); j++) {
//			if ((i & (1 << j)) != 0) {
//				weishu.push_back(j); count++;
//			}//找出二进制为1的位数以及它们的位置
//		}
//		if (count == target) {//位数等于M
//			vector<int> one_case;
//			for (int j = 0; j < count; j++) {
//				temp = in.size() - 1 - weishu[j];
//				one_case.push_back(in[temp]);
//			}
//			output.push_back(one_case);
//		}
//	}
//	return output;
//}
//int main()
//{
//	int m = 0;
//	cin >> m;
//	vector<int> total;
//	for (int i = 0; i < m; ++i) {
//		int tmp = 0;
//		cin >> tmp;
//		total.push_back(tmp);
//	}
//	vector<vector <int>> output;
//	output = zuhe(total, 5);
//
//	int min = INT_MAX;
//	for (size_t i = 0; i < output.size(); ++i) {
//		int fac = 1;
//		for (size_t j = 0; j < 5; ++j) {
//			fac *= output[i][j];
//		}
//		if (min > fac) min = fac;
//	}
//	cout << min << endl;
//	return 0;
//}





//竖式模拟
//#include <algorithm>
//#include <iostream>
//#include <string>
//using namespace std;
//string conversion(int m, string num, int n) {
//    int length = num.size(), remain;
//    string ret = "";
//    for (int i = 0; i < length; ) {
//        remain = 0;
//        for (int j = i; j < length; j++) {
//            int temp = (remain * m + num[j] - '0') % n;
//            num[j] = (remain * m + num[j] - '0') / n + '0';
//            remain = temp;
//        }
//        ret += char(remain + '0');
//        while (num[i] == '0') i++;
//    }
//    reverse(ret.begin(), ret.end());
//    return ret;
//}
//int main() {
//    int sum = 0;
//    string num;
//    cin >> num;
//    string ret = conversion(10, num, 2);
//    for (int i = 0; i < ret.size(); i++) {
//        if (ret[i] == '1') {
//            ++sum;
//        }
//    }
//    cout << sum;
//    return 0;
//}






//#include<iostream>
//using namespace std;
//const int N = 1010;
//int dp[N][N][2], a[N][N];
//int n, m, k;
//void solve()
//{
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][1] - k) + a[i][j];
//			dp[i][j][1] = max(dp[i - 1][j][0] - k, dp[i][j - 1][1]) + a[i][j];
//		}
//	}
//	cout << max(dp[n][m][0], dp[n][m][1]) - k << endl;
//}
//
//signed main()
//{
//	int t = 1;
//	while (t--) {
//		solve();
//	}
//	return 0;
//}





//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	cin >> str;
//	int flag = str[0] - '0';
//	int count = 1;
//	for (int i = 1; i < str.size(); ++i)
//	{
//		if (count >= 7) {
//			cout << "Yes" << endl;
//			return 0;
//		}
//		if (str[i] == '0' && flag == 0) {
//			++count;
//		}
//		else if (str[i] == '1' && flag == 1)
//		{
//			++count;
//		}
//		else if (str[i] == '1' && flag == 0)
//		{
//			flag = 1;
//			count = 1;
//		}
//		else if (str[i] == '0' && flag == 1)
//		{
//			flag = 0;
//			count = 1;
//		}
//
//		if (count >= 7) {
//			cout << "Yes" << endl;
//			return 0;
//		}
//	}
//	cout << "No" << endl;
//	return 0;
//}








//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	cin >> str;
//	int count0 = 0;
//	int count1 = 0;
//	for (int i = 0; i < str.size() ; ++i)
//	{
//		if (str[i] == '0'){
//			count0++;
//			if (count0 == 7)
//			{
//				cout << "Yes";
//				return 0;
//			}
//		}
//		else{
//			count0 = 0;
//
//		}
//
//		if (str[i] == '1'){
//			count1++;
//			if (count1 == 7)
//			{
//				cout << "Yes";
//				return 0;
//			}
//		}
//		else{
//			count1 = 0;
//		}
//	}
//	cout << "No";
//	return 0;
//}

















//#include<iostream>
//#include<cmath>
//#include<vector>
//using namespace std;
//int main()
//{
//	int T = 0;
//	cin >> T;
//	for (int i = 0; i < T; ++i) {
//		long long n = 0;
//		cin >> n;
//		vector<pair<long long, long long>> v;
//		long long x = 0, y = 0;
//		for (long long x = 0; x <= n / 2; ++x) {
//			v.push_back(make_pair(x, n - x));
//		}
//		vector<int> ret;
//		for (size_t j = 0; j < v.size(); ++j) {
//			ret.push_back(v[j].first * v[j].second);
//		}
//		for (size_t j = 0; j < v.size(); ++j) {
//			get_ret()
//		}
//
//	}
//	
//
//	return 0;
//}










//#include<iostream>
//#include<vector>
//using namespace std;
//int get_stat_count(vector<vector<int>>& v, int x1, int y1, int x2, int y2) {
//	int count = 0;
//	for (int i = x1 - 1; i <= x2 - 1; ++i) {
//		for (int j = y1 - 1; j <= y2 - 1; ++j) {
//			if (v[i][j] == 1) ++count;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int N = 0, M = 0;
//	cin >> N >> M;
//	vector<vector<int>> v;
//	for (int i = 0; i < N; ++i) {
//		vector<int> temp;
//		temp.resize(M);
//		for (int j = 0; j < M; ++j) {
//			cin >> temp[j];
//		}
//		v.push_back(temp);
//		temp.clear();
//	}
//	int Q = 0;
//	cin >> Q;
//	for (int tmp = 0; tmp < Q; ++tmp) {
//		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//		cin >> x1 >> y1 >> x2 >> y2;
//		cout << get_stat_count(v, x1, y1, x2, y2) << endl;
//	}
//	return 0;
//}





//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	int N = 0, M = 0;
//	cin >> N >> M;
//	vector<pair<int, int>> flag;
//	for (int i = 0; i < N; ++i) {
//		int temp = 0;
//		for (int j = 0; j < M; ++j) {
//			cin >> temp;
//			if (temp == 1) flag.push_back(make_pair(i + 1, j + 1));
//		}
//	}
//	int Q = 0;
//	cin >> Q;
//	for (int tmp = 0; tmp < Q; ++tmp) {
//		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//		cin >> x1 >> y1 >> x2 >> y2;
//		int count = 0;
//		int left = 0, right = flag.size() - 1;
//		while (left < right) {
//			if (flag[left].first >= x1 && flag[left].first <= x2 && flag[left].second >= y1 && flag[left].second <= y2) {
//				++count;
//			}
//			if (flag[right].first >= x1 && flag[right].first <= x2 && flag[right].second >= y1 && flag[right].second <= y2) {
//				++count;
//			}
//			++left;
//			--right;
//		}
//		if (left == right) {
//			if (flag[left].first >= x1 && flag[left].first <= x2 && flag[left].second >= y1 && flag[left].second <= y2) {
//				++count;
//			}
//		}
//		cout << count << '\n';
//	}
//	return 0;
//}












//#include<iostream>
//using namespace std;
//long long sgn(long long num) {
//	return num > 0 ? 1 : -1;
//}
//int main()
//{
//	long long a = 0, b = 0;
//	cin >> a >> b;
//	cout << sgn(b) * abs(a) << endl;
//	return 0;
//}







//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<string> get_ret(vector<string>& num1, vector<string>& num2) {
//	vector<string> ret;
//	int num1_i = num1.size() - 1, num2_i = num2.size() - 1;
//	int jingzhi = 2;
//	while (num1_i >=0 && num2_i >= 0) {
//		long long sum = atoll(num1[num1_i].c_str()) + atoll(num2[num2_i].c_str());
//		ret.push_back(to_string(sum % jingzhi));
//		if (num1_i - 1 >= 0)
//			num1[num1_i - 1] = to_string(atoll(num1[num1_i - 1].c_str()) + sum / jingzhi);
//		else if(sum / jingzhi != 0)
//		{
//			num1.insert(num1.begin(), to_string(sum / jingzhi));
//			++num1_i;
//		}
//		num1_i--;
//		num2_i--;
//		jingzhi++;
//	}
//	if (num1_i < 0) {
//		while (num2_i >= 0) {
//			ret.push_back(num2[num2_i]);
//			--num2_i;
//		}
//	}
//	else {//num2_i == 0
//		while (num1_i >= 0) {
//			ret.push_back(num1[num1_i]);
//			--num1_i;
//		}
//	}
//	reverse(ret.begin(), ret.end());
//	return ret;
//}
//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	vector<string> num1, num2;
//	for (int i = 0; i < n; ++i) {
//		int tmp = 0;
//		cin >> tmp;
//		num1.push_back(to_string(tmp));
//	}
//	for (int i = 0; i < m; ++i) {
//		int tmp = 0;
//		cin >> tmp;
//		num2.push_back(to_string(tmp));
//	}
//
//	vector<string> ret = get_ret(num1, num2);
//	for (size_t i = 0; i < ret.size(); ++i) {
//		cout << ret[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
//
//




//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int q = 0;
//	cin >> q;
//	for (int i = 0; i < q; ++i) {
//		long long k = 0;
//		cin >> k;
//
//		long long com = 1;
//		long long flag_i = 1;
//		long long count = 0;//第几个周期
//		for (long long i = 2;;i += 2) {
//			if (com >= k) {
//				flag_i = i - 2;
//				break;
//			}
//			++count;
//			com++;
//			com += (i * 2);
//		}
//
//		long long ret = 0;
//		if (k == com) {
//			cout << 0 << endl;
//			continue;
//		}
//		else {//k < com
//			if (k >= com - (long long)flag_i / 2) {//4
//				while (k != com - (long long)flag_i / 2) {
//					--k;
//					++ret;
//				}
//				ret = count * (-1) + ret;
//			}
//			else if (k >= com - (long long)flag_i) {// 3
//				while (k != com - (long long)flag_i / 2) {
//					++k;
//					++ret;
//				}
//				ret = (-1) * (count - ret);
//			}
//			else if(k >= com - (long long)flag_i - (long long)flag_i / 2){//2
//				while (k != com - (long long)flag_i) {
//					++k;
//					++ret;
//				}
//			}
//			else if (k > com - (long long)flag_i * 2) {
//				while (k != com - (long long)flag_i - (long long)flag_i / 2) {
//					++k;
//					++ret;
//				}
//				ret = count - ret;
//			}
//			else {//k == com - (long long)flag_i
//				cout << 0 << endl;
//				continue;
//			}
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}














//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        size_t total_size = nums1.size() + nums2.size();
//        for (size_t i = 0; i < nums1.size(); ++i) {
//            nums2.push_back(nums1[i]);
//        }
//        sort(nums2.begin(), nums2.end());
//        if (total_size % 2 == 0) {
//            int index1 = total_size / 2;
//            int index2 = total_size / 2 + 1;
//            double ret = ((double)nums2[index1 - 1] + (double)nums2[index2 - 1]) / 2;
//            return ret;
//        }
//        else {
//            int index = total_size / 2 + 1;
//            return (double)nums2[index - 1];
//        }
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v1{ 1, 2 };
//    vector<int> v2{ 3, 4 };
//    double ret = s.findMedianSortedArrays(v1, v2);
//    cout << ret << endl;
//    return 0;
//}






//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        if (nums.empty()) {
//            return 0;
//        }
//        int size = nums.size();
//        if (size == 1) {
//            return nums[0];
//        }
//        vector<int> dp = vector<int>(size, 0);
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//        for (int i = 2; i < size; i++) {
//            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//        }
//        return dp[size - 1];
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v{ 2,7,9,3,1 };
//    int ret = s.rob(v);
//    cout << ret << endl;
//    return 0;
//}










//超过时间
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    bool IsPalindrome(string& str, int i, int j) {
//        while (i <= j) {
//            if (str[i] != str[j]) return false;
//            ++i;
//            --j;
//        }
//        return true;
//    }
//    string longestPalindrome(string s) {
//        vector< pair<int, string>> v;
//        for (size_t i = 0; i < s.size(); ++i) {
//            for (size_t j = i; j < s.size(); ++j) {
//                if (IsPalindrome(s, i, j)) {
//                    v.push_back(make_pair(j - i + 1, string(s.begin() + i, s.begin() + j + 1)));
//                }
//            }
//        }
//        size_t max = 0;
//        string ret;
//        for (auto& e : v) {
//            if (max < e.first) {
//                ret = e.second;
//                max = e.first;
//            }
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    string ret = s.longestPalindrome(string("babad"));
//    cout << ret << endl;
//    return 0;
//}








//
//
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int get_ten_six(int num) {
//	string ret;
//	while (num > 0) {
//		ret += num % 16 + '0';
//		num /= 16;
//	}
//	reverse(ret.begin(), ret.end());
//	return atoi(ret.c_str());
//}
//int main()
//{
//	for (int i = 10; i < 10000; ++i) {
//		if (get_ten_six(i) % i == 0) {
//			cout << i << endl;
//		}
//	}
//	return 0;
//}







//#include<iostream>
//#include<vector>
//using namespace std;
//bool isPrime(int n) {
//    for (int i = 2; i < n; i++) {//如果n被i整除，则返回false
//        if (n % i == 0) {
//            return false;
//            break;
//        }
//    }
//    return true;	// 反之则返回true 
//}
//int main()
//{
//    vector<int> v;
//    vector<int> flag;
//    vector<pair<int, int>> ret;
//    int num = 2022;
//    for (int i = 2; i < num / 2; ++i) {
//        if (isPrime(i)) v.push_back(i);
//    }
//    for (int i = 0; i < v.size(); ++i) {
//        flag.push_back(num - v[i]);
//    }
//    for (int i = 0; i < flag.size(); ++i) {
//        if (isPrime(flag[i])) {
//            ret.push_back(make_pair(v[i],flag[i]));
//        }
//    }
//    for (auto& e : ret) {
//        cout << e.first << " " << e.second << endl;
//    }
//    cout << ret.size() << endl;
//    return 0;
//}









//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	double t = 0, c = 0, s = 0;
//	cin >> t >> c >> s;
//	double xiao = c / t;
//	cout << long long((s - c) / xiao) << endl;
//	return 0;
//}









//#include<iostream>
//#include<unordered_map>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	unordered_map<string,int> mp;
//	for (int i = 0; i < n; ++i) {
//		string tmp;
//		cin >> tmp;
//		++mp[tmp];
//	}
//	for (unordered_map<string,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
//		cout << (*it).first << endl;
//	}
//	return 0;
//}








//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//string handle(string ret) {
//	string add = "";
//	string::iterator it = ret.begin();
//	string::iterator itend = ret.end() - 1;
//	while (*it != *itend) {
//		add += *(it);
//		++it;
//	}
//	reverse(add.begin(), add.end());
//	ret += add;
//	return ret;
//}
//int main()
//{
//	string str;
//	cin >> str;
//	if (str.size() == 1) {
//		cout << str << endl;
//		return 0;
//	}
//	string ret = handle(str);
//	cout << ret << endl;
//	return 0;
//}





//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	long long n = 0;
//	cin >> n;
//	vector<long long> v(n);
//	for (long long i = 0; i < n; ++i) {
//		cin >> v[i];
//	}
//	long long sum = 0;
//	bool flag = true;
//	for (long long i = 0; i < n - 1; ++i) {
//		flag = true;
//		for (long long j = 0; j < n - i - 1; ++j) {
//			if (v[j] > v[j + 1]) {
//				sum += v[j];
//				swap(v[j], v[j + 1]);
//				flag = false;
//			}
//		}
//		if (flag == true) {
//			break;
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}











//#include <iostream>
//#include <vector>
//using namespace std;
//int binary_search(const vector<int>& v, const int key) {
//	int left = 0, right = v.size() - 1;
//	while (left <= right) {
//		int mid = ((left - right) >> 1) + right;
//		if (v[mid] == key) {
//			return mid + 1;
//		}
//		else if (v[mid] > key) {
//			right = mid - 1;
//		}
//		else if(v[mid] < key) {
//			left = mid + 1;
//		}
//		else {
//			exit(-1);
//		}
//	}
//	return - 1;
//}
//int main()
//{
//	vector<int>v;
//	v.resize(10);
//
//	cout << "输入10个从小到大的元素:";
//	for (size_t i = 0; i < v.size(); ++i) {
//		cin >> v[i];
//	}
//
//	cout << "输入要查找的元素:";
//	int tmp = 0;
//	cin >> tmp;
//	int index = binary_search(v, tmp);
//	cout << "要查找的元素的位置为:" << index << endl;
//	return 0;
//}






//#include <stdio.h>
//int main(int argc,char* argv[])
//{
//	for (int i = 0; i < argc; ++i) {
//		printf("%s", argv[i]);
//	}
//	return 0;
//}





/*
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。
现在让你编程计算一下你可以获得的多少种不同的幸运的袋子
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//size_t GetLucklyPacketNum(vector<size_t>& v, size_t n, size_t pos, size_t sum, size_t mul)
//{
//    size_t count = 0;
//    for (size_t i = pos; i < n; ++i) {
//        sum += v[i];
//        mul *= v[i];
//        if (sum > mul)
//            count += 1 + GetLucklyPacketNum(v, n, i + 1, sum, mul);
//        else if (v[i] == 1) //当前不幸运，但由于v[i]=1,后面可能存在幸福的方案
//            count += GetLucklyPacketNum(v, n, i + 1, sum, mul);
//        else break;//回溯
//        sum -= v[i];
//        mul /= v[i];
//
//        while (i < n - 1 && v[i] == v[i + 1]) ++i;
//    }
//    return count;
//}
//int main() {
//    /*size_t n = 0;
//    cin >> n;
//    vector<size_t> v(n);
//    for (size_t i = 0; i < n; ++i) {
//        cin >> v[i];
//    }*/
//    vector<size_t> v{ 1,1,3,5,7 };
//    size_t n = 5;
//    sort(v.begin(), v.end());
//    cout << GetLucklyPacketNum(v, n, 0, 0, 1) << endl;
//}




//#include <iostream>
//#include <thread>
//using namespace std;
//void func(int num)
//{
//	for (int i = 0; i < num; ++i) {
//		cout << i << endl;
//	}
//}
//int main()
//{
//	thread t;
//	//...
//	t = thread(func, 100);
//	t.join();
//	return 0;
//}




//#include <iostream>
//#include <thread>
//using namespace std;
//void func(int num)
//{
//	for (int i = 0; i < num; ++i) {
//		cout << i << endl;
//	}
//}
//int main()
//{
//	thread t = thread(func, 10);
//	t.join();
//	return 0;
//}


//#include <iostream>
//#include <thread>
//using namespace std;
//void func(int n)
//{
//	for (int i = 0; i < n; i++) {
//		cout << i << endl;
//	}
//}
//int main()
//{
//	thread t(func, 10);
//	t.join();
//	t = thread(func, 10);
//	t.join();
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include <windows.h>
//using namespace std;
//void func(int num)
//{
//	for (int i = 0; i < num; i++) {
//		cout << i << endl;
//	}
//}
//bool DoSomething(){ return false; }
//int main()
//{
//	thread t(func, 10);
//	Sleep(3);
//	if (!DoSomething()) return -1;
//
//	t.join(); //不会被执行
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include <windows.h>
//using namespace std;
//class Thread
//{
//public:
//	Thread(thread& t):_thread(t) {}
//	~Thread() {
//		if (_thread.joinable()) _thread.join();
//	}
//private:
//	//防拷贝
//	Thread(const Thread&) = delete;
//	Thread& operator=(const Thread&) = delete;
//private:
//	thread& _thread;
//};
//
//void func(int num)
//{
//	for (int i = 0; i < num; i++) {
//		cout << i << endl;
//	}
//}
//bool DoSomething(){ return false; }
//int main()
//{
//	thread t(func, 10);
//	Thread T(t);
//	Sleep(3);
//	if (!DoSomething()) return 1;
//	return 0;
//}



//#include <iostream>
//#include <thread>
//using namespace std;
//void func()
//{
//	cout << this_thread::get_id() << endl;
//}
//int main()
//{
//	thread t(func);
//	t.join();
//	return 0;
//}


//#include <iostream>
//#include <thread>
//using namespace std;
//void add(int& num) {
//	num++;
//}
//int main()
//{
//	int num = 0;
//	thread t(add, ref(num));
//	t.join();
//	cout << num << endl;
//	return 0;
//}



//#include <iostream>
//#include <thread>
//using namespace std;
//void add(int* num) {
//	++(*num);
//}
//int main()
//{
//	int num = 0;
//	thread t(add, &num);
//	t.join();
//	cout << num << endl;
//	return 0;
//}



//#include <iostream>
//#include <thread>
//using namespace std;
//int main()
//{
//	int num = 0;
//	thread t([&num](){ ++num; });
//	t.join();
//	cout << num << endl;
//	return 0;
//}


//#include <iostream>
//#include <mutex>
//using namespace std;
//mutex mtx;
//void func()
//{
//	//匿名局部域
//	{
//		lock_guard<mutex> lg(mtx); //调用构造函数加锁
//		if (true) {
//			return; //调用析构函数解锁
//		}
//	} //调用析构函数解锁
//}
//int main()
//{
//	func();
//	return 0;
//}




//template<class Mutex>
//class lock_guard
//{
//public:
//	lock_guard(Mutex& mtx) :_mtx(mtx) {
//		mtx.lock(); //加锁
//	}
//	~lock_guard() {
//		mtx.unlock(); //解锁
//	}	
//private:
//	lock_guard(const lock_guard&) = delete;
//	lock_guard& operator=(const lock_guard&) = delete;
//private:
//	Mutex& _mtx;
//};


//#include <iostream>
//#include <mutex>
//using namespace std;
//void func(int& num, int count)
//{
//	for (int i = 0; i < count; i++) {
//		++num;
//	}
//}
//int main()
//{
//	int num = 0;
//	int count = 100000; //每个线程对num++的次数
//	thread t1(func, ref(num), count);
//	thread t2(func, ref(num), count);
//	t1.join();
//	t2.join();
//
//	cout << num << endl;
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//void func(int& num, int count, mutex& mtx)
//{
//	mtx.lock();
//	for (int i = 0; i < count; i++) 
//	{
//		//mtx.lock();
//		++num;
//		//mtx.unlock();
//	}
//	mtx.unlock();
//}
//int main()
//{
//	int num = 0;
//	int count = 100000; //每个线程对num++的次数
//	mutex mtx;
//	thread t1(func, ref(num), count, ref(mtx));
//	thread t2(func, ref(num), count, ref(mtx));
//	t1.join();
//	t2.join();
//
//	cout << num << endl;
//	return 0;
//}

//#include <iostream>
//#include <thread>
//#include <atomic>
//using namespace std;
//void func(atomic_int& num, int count)
//{
//	for (int i = 0; i < count; i++) {
//		++num;
//	}
//}
//int main()
//{
//	atomic_int num = { 0 };
//	int count = 100000; //每个线程对n++的次数
//	thread t1(func, ref(num), count);
//	thread t2(func, ref(num), count);
//	t1.join();
//	t2.join();
//	cout << num << endl; //打印n的值
//	return 0;
//}





//#include <iostream>
//#include <thread>
//#include <atomic>
//#include <condition_variable>
//using namespace std;
//int main()
//{
//	int i = 1;
//	int n = 100;
//	mutex mtx;
//	condition_variable cv;
//	size_t flag = 1;//1 or 2 代表哪个线程可以打印
//	//奇数
//	thread t1([&]() {
//		while (i < n)//最大99
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&flag]()->bool { return flag == 1; });
//			cout << this_thread::get_id() << ":" << i << endl;
//			i += 1;
//			flag = 2;
//			cv.notify_one();
//		}
//	});
//	//偶数
//	thread t2([&]() {
//		while (i <= n)//最大100
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&flag]()->bool { return flag == 2; });
//			cout << this_thread::get_id() << ":" << i << endl;
//			i += 1;
//			flag = 1;
//			cv.notify_one();
//		}
//	});
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "t1:" << t1.get_id() << endl;
//	cout << "t2:" << t2.get_id() << endl;
//	t1.join();
//	t2.join();
//	return 0;
//}





//#include <iostream>
//#include <string>
//using namespace std;
//const string tempPath = "./TempFile/";
//class PathTool
//{
//public:
//    //将文件名字符串构建成包含路径、源文件后缀的完整字符串
//    static string StructureCompletePath_Source(const string& fileName) {
//        return StructureCompletePath(fileName, ".cpp");
//    }
//    //将文件名字符串构建成包含路径、编译错误文件后缀的完整字符串
//    static string StructureCompletePath_CompileErr(const string& fileName) {
//        return StructureCompletePath(fileName, ".ComErr");
//    }
//    //将文件名字符串构建成包含路径、可执行文件后缀的完整字符串
//    static string StructureCompletePath_Exe(const string& fileName) {
//        return StructureCompletePath(fileName, ".exe");
//    }
//    //将文件名字符串构建成包含路径、标准输入文件后缀的完整字符串
//    static string StructureCompletePath_Stdin(const string& fileName) {
//        return StructureCompletePath(fileName, ".in");
//    }
//    //将文件名字符串构建成包含路径、标准输出文件后缀的完整字符串
//    static string StructureCompletePath_Stdout(const string& fileName) {
//        return StructureCompletePath(fileName, ".out");
//    }
//    //将文件名字符串构建成包含路径、标准错误文件后缀的完整字符串
//    static string StructureCompletePath_Stderr(const string& fileName) {
//        return StructureCompletePath(fileName, ".errMsg");
//    }
//private:
//    static string StructureCompletePath(const string& fileName, const string& suffix) {
//        return tempPath + fileName + suffix;
//    }
//};
//int main()
//{
//    string fileName = "code";
//    string ret1 = PathTool::StructureCompletePath_Source(fileName);
//    const char* str1 = ret1.c_str();
//    string ret2 = PathTool::StructureCompletePath_Exe(fileName).c_str();
//    const char* str2 = ret1.c_str();
//
//    const char* argvs[] = { "g++", str1 , "-o", str2, "-std=c++11", NULL };
//    for (int i = 0; i < 5; ++i) {
//        std::cout << argvs[i] << std::endl;
//    }
//    return 0;
//}




//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//    bool IsPalindrome(int x) {
//        //write code
//        return true;
//    }
//};
//
//
//bool Test1()
//{
//    bool ret = Solution().IsPalindrome(121);
//    if (ret) {
//        return true;
//    }
//    else {
//        std::cout << "未通过测试用例1 : 121" << std::endl;
//        return false;
//    }
//}
//bool Test2()
//{
//    bool ret = Solution().IsPalindrome(-10);
//    if (!ret) {
//        return true;
//    }
//    else {
//        std::cout << "未通过测试用例1 : -10" << std::endl;
//        return false;
//    }
//}
//
//int main()
//{
//    int ret1 = Test1();
//    int ret2 = Test2();
//    if (ret1 && ret2) {
//        std::cout << "通过全部测试用例" << endl;
//    }
//    return 0;
//}





//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//using namespace std;
//
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//
//    }
//};
//
//bool Test1() {
//    vector<int> nums{ 2,3,1,1,4 };
//    bool tmp = Solution().canJump(nums);
//    if (tmp == true) return true;
//    else {
//        std::cout << "测试用例 [2,3,1,1,4] 未通过" << std::endl;
//        return false;
//    }
//}
//
//bool Test2() {
//    vector<int> nums{ 3,2,1,0,4 };
//    bool tmp = Solution().canJump(nums);
//    if (tmp == false) return true;
//    else {
//        std::cout << "测试用例 [3,2,1,0,4] 未通过" << std::endl;
//        return false;
//    }
//}
//
//int main() 
//{
//    bool ret1 = Test1();
//    bool ret2 = Test2();
//    if (ret1 && ret2) {
//        std::cout << "通过全部测试用例" << endl;
//    }
//    return 0;
//}





//#include <iostream>
//#include <string>
//using namespace std;
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



//bool Test1() {
//    string str = "RLRRRLLRLL";
//    int tmp = Solution().balancedStringSplit(str);
//    if (tmp == 2) return true;
//    else {
//        std::cout << "测试用例 RLRRRLLRLL 未通过" << std::endl;
//        return false;
//    }
//}
//
//bool Test2() {
//    string str = "RLRRLLRLRL";
//    int tmp = Solution().balancedStringSplit(str);
//    if (tmp == 4) return true;
//    else {
//        std::cout << "测试用例 RLRRLLRLRL 未通过" << std::endl;
//        return false;
//    }
//}
//
//bool Test3() {
//    string str = "LLLLRRRR";
//    int tmp = Solution().balancedStringSplit(str);
//    if (tmp == 1) return true;
//    else {
//        std::cout << "测试用例 LLLLRRRR 未通过" << std::endl;
//        return false;
//    }
//}
//
//int main()
//{
//    bool ret1 = Test1();
//    bool ret2 = Test2();
//    bool ret3 = Test3();
//    if (ret1 && ret2 && ret3) {
//        std::cout << "通过全部测试用例" << endl;
//    }
//    return 0;
//}









//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1; // 编译器将调用自动生成的默认构造函数对d1进行初始化
//	d1.Print();
//	return 0;
//}


//
//
//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)// 构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2021, 5, 30);
//	Date d2(d1); // 用已存在的对象d1创建对象d2
//	d1.Print();
//	d2.Print();
//	return 0;
//}





//#include <iostream>
//#include <vector>
//using namespace std;
//void bublle(vector<int>& v) 
//{
//	for (int i = 0; i < v.size() - 1; ++i) 
//	{
//		for (int j = 0; j < v.size() - i - 1; ++j)
//		{
//			if (v[j] > v[j + 1]) 
//			{
//				int tmp = v[j];
//				v[j] = v[j + 1];
//				v[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	vector<int> v{2,3,1,4,5};
//	bublle(v);
//	for (int i = 0; i < v.size(); ++i) {
//		cout << v[i] << " ";
//	}
//	return 0;
//}




//#include <iostream>
//#include <vector>
//using namespace std;
//int GreatestCommonDivisor(int num1, int num2) {
//    if (num2 == 0) return num1;
//    return GreatestCommonDivisor(num2, num1 % num2);
//}
//int main() {
//    int n = 0, a = 0;
//    while (cin >> n >> a) {
//        vector<int> v(n);
//        for (int i = 0; i < n; ++i) cin >> v[i];
//
//        for (auto it : v) {
//            if (a > it) a += it;
//            else a += GreatestCommonDivisor(it, a);
//        }
//        cout << a << endl;
//    }
//    return 0;
//}




//class Gift {
//public:
//    int getValue(vector<int> gifts, int n) {
//        map<int, int> mp;
//        for (int i = 0; i < n; ++i) {
//            mp[gifts[i]]++;
//        }
//        for (auto it : mp)
//        {
//            if (it.second > n / 2) {
//                return it.first;
//            }
//        }
//        return 0;
//    }
//};

















//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//struct Goods
//{
//    string _name;  //名字
//    double _price; //价格
//    int _num;      //数量
//};
//struct ComparePriceLess {
//	bool operator()(const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price;
//	}
//};
//struct ComparePriceGreater {
//	bool operator()(const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price;
//	}
//};
//struct CompareNumLess {
//	bool operator()(const Goods& g1, const Goods& g2) {
//		return g1._num < g2._num;
//	}
//};
//struct CompareNumGreater {
//	bool operator()(const Goods& g1, const Goods& g2) {
//		return g1._num > g2._num;
//	}
//};
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
//	sort(v.begin(), v.end(), ComparePriceLess());    //按价格升序排序
//	sort(v.begin(), v.end(), ComparePriceGreater()); //按价格降序排序
//	sort(v.begin(), v.end(), CompareNumLess());      //按数量升序排序
//	sort(v.begin(), v.end(), CompareNumGreater());   //按数量降序排序
//	return 0;
//}




//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 0;
//    //auto f1 = [=] { return a++; };             // error，修改按值捕获的外部变量
//    auto f2 = [&](){
//        ++a;
//        cout << "a = " << a << endl;//值传递
//    };
//    f2();//1
//    cout << "a = " << a << endl;//0
//    return 0;
//}



//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    void test(int& val)const
//    {
//        val = 1000;
//    }
//private:
//    int _val = 10;
//};
//int main()
//{
//    Base b;
//    int a = 100;
//    b.test(a);
//    return 0;
//}


//#include <iostream>
//#include <functional>
//#include <map>
//using namespace std;
//
//int Plus(int a, int b) {
//    return a + b;
//}
//
//int Mul(int a, int b) {
//    return a * b;
//}
//
//class Sub
//{
//public:
//    int sub(int a, int b) {
//        return a - b;
//    }
//};
//
//int main()
//{
//    //无法用同种function包装器接收
//    function<int(int, int)> funcPlus = Plus;
//    function<int(Sub, int, int)> funcSub = &Sub::sub;
//    function<int(int, int)> funcMul = Mul;
//
//
//    //通过bind调整Sub参数个数
//    map<string, function<int(int, int)>> opFuncMap =
//    {
//        { "+", Plus},
//        { "-", bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2)},
//        { "*", Mul}
//    };
//
//    cout << opFuncMap["+"](1, 2) << endl;
//    cout << opFuncMap["-"](1, 2) << endl;
//    cout << opFuncMap["*"](1, 2) << endl;
//
//    return 0;
//}









//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//vector<int> GetFactor(int number)
//{
//    vector<int> ret;
//    for (int i = 2; i <= sqrt(number); ++i)
//    {
//        while (number % i == 0) {
//            number /= i;
//            ret.push_back(i);
//        }
//    }
//    if (number != 1) ret.push_back(number);
//    return ret;
//}
//int main()
//{
//    int number = 0;
//    while (cin >> number)
//    {
//        vector<int> ret = GetFactor(number);
//
//        cout << number << " = ";
//        for (int i = 0; i < ret.size() - 1; ++i) {
//            cout << ret[i] << " * ";
//        }
//        cout << ret[ret.size() - 1] << endl;
//    }
//    return 0;
//}






//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    vector<long long> dp(81);
//    dp[0] = 0, dp[1] = 1;
//    for (long long i = 2; i < 81; ++i) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//
//    long long from = 0, to = 0;
//    while (cin >> from >> to)
//    {
//        long long sum = 0;
//        for (long long i = from; i <= to; ++i) {
//            sum += dp[i];
//        }
//        cout << sum << endl;
//    }
//    return 0;
//}





//#include <iostream>
//#include <string>
//using namespace std;
//
//int GetResult(string& str1, string& str2)
//{
//    int count = 0;
//    size_t index = str1.find(str2);
//    while (index != string::npos)
//    {
//        str1.erase(index, str2.size());
//        ++count;
//        index = str1.find(str2);
//    }
//    return count;
//}
//
//int main()
//{
//    string strBase, str;
//    while (cin >> strBase >> str) {
//        cout << GetResult(strBase, str) << endl;
//    }
//    return 0;
//}




//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    int n = 0;
//    vector<long long> dp(90);
//    dp[0] = 1, dp[1] = 2;
//    for (int i = 2; i < 90; ++i) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//
//    while (cin >> n) {
//        cout << dp[n - 1] << endl;
//    }
//    return 0;
//}






//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        getchar();
//        vector<string> v(n);
//        for (auto& it : v) getline(cin, it);
//
//        for (int i = 0; i < v.size(); ++i) {
//            if (v[i].find(' ') != string::npos || v[i].find(',') != string::npos) {
//                if (i == v.size() - 1)
//                    cout << "\"" << v[i] << "\"" << endl;
//                else
//                    cout << "\"" << v[i] << "\", ";
//            }
//            else {
//                if (i == v.size() - 1)
//                    cout << v[i] << endl;
//                else
//                    cout << v[i] << ", ";
//            }
//        }
//    }
//    return 0;
//}










//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//char id, op[100];
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int _max = 0, _now = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            getchar();
//            scanf("%c %s", &id, op);
//            if (strcmp("connect", op) == 0) ++_now;
//            else --_now;
//            _max = _max > _now ? _max : _now;
//        }
//        printf("%d\n", _max);
//    }
//    return 0;
//}









//将str1、str2看作26进制的数据
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//using namespace std;
//int main()
//{
//    string str1, str2;
//    int length1, length2;
//    while (cin >> str1 >> str2 >> length1 >> length2)
//    {
//        //补位
//        str1.append(length2 - str1.size(), 'a');
//        str2.append(length2 - str2.size(), (char)('z' + 1));
//        //计算两个字符串之间的差值
//        vector<int> tmp;
//        for (int i = 0; i < length2; ++i) {
//            tmp.push_back(str2[i] - str1[i]);
//        }
//        //计算两者之间的数目
//        long long ret = 0;
//        for (int i = length1; i <= length2; ++i) {
//            for (int j = 0; j < i; ++j) {
//                ret += tmp[j] * pow(26, i - 1 - j);
//            }
//        }
//        //不包含s2
//        cout << (ret - 1) % 1000007 << endl;
//    }
//    return 0;
//}











//#include <iostream>
//#include <vector>
//using namespace std;
//bool LeftUpIsFive(vector<vector<char>>& map, int i, int j)
//{
//    char base = map[i][j];
//    int count = 1;
//    for (int num = 0; num < 4; ++num) {
//        if ((--i) >= 0 && (--j) >= 0 && map[i][j] == base)  ++count;
//    }
//    return count >= 5;
//}
//bool RightUpIsFive(vector<vector<char>>& map, int i, int j)
//{
//    char base = map[i][j];
//    int count = 1;
//    for (int num = 0; num < 4; ++num) {
//        if ((--i) >= 0 && (++j) < 20 && map[i][j] == base)  ++count;
//    }
//    return count >= 5;
//}
//bool UpFive(vector<vector<char>>& map, int i, int j)
//{
//    char base = map[i][j];
//    int count = 1;
//    for (int num = 0; num < 4; ++num) {
//        if ((--i) >= 0 && map[i][j] == base)  ++count;
//    }
//    return count >= 5;
//}
//bool LeftIsFive(vector<vector<char>>& map, int i, int j)
//{
//    char base = map[i][j];
//    int count = 1;
//    for (int num = 0; num < 4; ++num) {
//        if ((--j) >= 0 && map[i][j] == base)  ++count;
//    }
//    return count >= 5;
//}
//bool RightIsFive(vector<vector<char>>& map, int i, int j)
//{
//    char base = map[i][j];
//    int count = 1;
//    for (int num = 0; num < 4; ++num) {
//        if ((++j) < 20 && map[i][j] == base)  ++count;
//    }
//    return count >= 5;
//}
//bool GetResult(vector<vector<char>>& map)
//{
//    bool result = false;
//    for (int i = 0; i < 20; ++i)
//    {
//        for (int j = 0; j < 20; ++j)
//        {
//            if (map[i][j] != '.')
//                result = LeftUpIsFive(map, i, j) || RightUpIsFive(map, i, j) || UpFive(map, i, j) || LeftIsFive(map, i, j) || RightIsFive(map, i, j);
//            if (result == true) return result;
//        }
//    }
//    return result;
//}
//int main()
//{
//    vector<vector<char>> map(20, vector<char>(20));
//    while (cin >> map[0][0])
//    {
//        for (int i = 1; i < 20; ++i) cin >> map[0][i];
//        for (int i = 1; i < 20; ++i) {
//            for (int j = 0; j < 20; ++j) {
//                cin >> map[i][j];
//            }
//        }
//        if (GetResult(map)) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}











//#include <iostream>
//#include <string>
//#include <stack>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    const unordered_set<string> _set{ "+","-","*","/" };
//    int evalRPN(vector<string>& tokens)
//    {
//        stack<string> sk;
//        for (auto it : tokens)
//        {
//            if (_set.find(it) == _set.end())//数字
//                sk.push(it);
//            else//运算符
//            {
//                string rightStr = sk.top();
//                sk.pop();
//                string leftStr = sk.top();
//                sk.pop();
//
//                int left = atoi(leftStr.c_str());
//                int right = atoi(rightStr.c_str());
//                char op = it.c_str()[0];
//                int ret = 0;
//                switch (op)
//                {
//                case '+':
//                    ret = left + right;
//                    break;
//                case '-':
//                    ret = left - right;
//                    break;
//                case '*':
//                    ret = left * right;
//                    break;
//                case '/':
//                    ret = left / right;
//                    break;
//                }
//                sk.push(to_string(ret));
//            };
//        }
//        string ret = sk.top();
//        sk.pop();
//        return atoi(ret.c_str());
//    }
//};
//int main()
//{
//    vector<string> v{ "20","10","+","30","*" };
//    int ret = Solution().evalRPN(v);
//    cout << ret << endl;
//    return 0;
//}










//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        for (auto it : str) {
//            if (isdigit(it)) cout << it;
//        }
//        cout << endl;
//    }
//    return 0;
//}








//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//const unordered_map<char, char> map = { {'A','2'},{'B','2'},{'C','2'},
//                                        {'D','3'},{'E','3'},{'F','3'},
//                                        {'G','4'},{'H','4'},{'I','4'},
//                                        {'J','5'},{'K','5'},{'L','5'},
//                                        {'M','6'},{'N','6'},{'O','6'},
//                                        {'P','7'},{'Q','7'},{'R','7'},{'S','7'},
//                                        {'T','8'},{'U','8'},{'V','8'},
//                                        {'W','9'},{'X','9'},{'Y','9'},{'Z','9'} };
//void Handle(string& str)
//{
//    for (int i = 0; i < str.size(); ++i)
//    {
//        auto iter = map.find(str[i]);
//        if (iter != map.end()) str[i] = iter->second;
//        if (str[i] == '-') str[i] = ' ';
//    }
//
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] == ' ') {
//            str.erase(str.begin() + i);
//            --i;
//        }
//    }
//    str.insert(3, "-");
//}
//int main()
//{
//    int n = 0;
//    while (std::cin >> n)
//    {
//        vector<string> ret(n);
//        string tmp;
//        for (int i = 0; i < n; ++i)
//        {
//            cin >> tmp;
//            Handle(tmp);
//            ret[i] = tmp;
//        }
//        sort(ret.begin(), ret.end());
//
//        cout << ret[0] << endl;
//        for (int i = 1; i < ret.size(); ++i) {
//            if (ret[i] != ret[i - 1]) cout << ret[i] << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}












//#include <cctype>
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        vector<string> ret;
//        string tmp;
//        for (auto it : str)
//        {
//            if (isalpha(it)) tmp.push_back(it);
//            else {
//                if (tmp.size() != 0) ret.push_back(tmp);
//                tmp.clear();
//            }
//        }
//        if(tmp.size() != 0) ret.push_back(tmp);
//        for (int i = ret.size() - 1; i >= 0; --i)
//        {
//            cout << ret[i] << " ";
//        }
//    }
//    return 0;
//}








//#include <cctype>
//#include <iostream>
//#include <string>
//#include <cstdio> 
//using namespace std;
//int main()
//{
//    string str;
//    while (cin >> str)
//    {
//        for (int i = 0; i < str.size() - 1; ++i) {
//            if (str[i] == '_') {
//                str[i + 1] = toupper(str[i + 1]);
//                str.erase(str.begin() + i);
//                --i;
//            }
//        }
//        cout << str << endl;
//    }
//    return 0;
//}










//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//bool IsBrother(string& str1, string& str2)
//{
//    unordered_map<char, int> mp;
//    for (auto it : str1) ++mp[it];
//    for (auto it : str2) --mp[it];
//
//    int flag = true;
//    for (auto it : mp) {
//        if (it.second != 0) flag = false;
//    }
//
//    return flag && str1 != str2;
//}
//vector<string> GetRet(vector<string>& words, string str)
//{
//    vector<string> ret;
//    for (auto it : words) {
//        if (IsBrother(it, str)) ret.push_back(it);
//    }
//    return ret;
//}
//
//int main()
//{
//    int n = 0, k = 0;
//    while (cin >> n)
//    {
//        vector<string> words(n);
//        for (auto& it : words) cin >> it;
//
//        string x;
//        cin >> x;
//        cin >> k;
//
//        vector<string> brother = GetRet(words, x);
//        sort(brother.begin(), brother.end());
//
//        cout << brother.size() << endl;
//        if ((k - 1) < brother.size()) cout << brother[k - 1] << endl;
//    }
//    return 0;
//}









//#include <iostream>
//#include <unordered_map>
//using namespace std;
//bool GetRet(string& A, string& B)
//{
//    unordered_map<char, int> mp;
//    for (auto it : B) { ++mp[it]; }
//    for (auto it : A) { --mp[it]; }
//    for (auto it : mp) {
//        if (it.second > 0) return false;
//    }
//    return true;
//}
//int main()
//{
//    string A, B;
//    while (cin >> A >> B)
//    {
//        if (GetRet(A, B)) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//    return 0;
//}