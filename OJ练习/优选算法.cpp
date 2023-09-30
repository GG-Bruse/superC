/********************************************** �ƶ��㣨LeetCode��***************************************************/
/*
����һ������nums����дһ������������0�ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
��ע�⣬�����ڲ���������������ԭ�ض�������в���
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    //���з�0Ԫ��һ������ǰ��
//    void moveZeroes(vector<int>& nums) {
//        for (int dest = -1, current = 0; current < nums.size(); ++current)
//            if (nums[current] != 0) swap(nums[++dest], nums[current]);
//    }
//};











/************************************************** ��д�㣨LeetCode��***********************************************/
/*
����һ�����ȹ̶����������� arr �����㽫�������г��ֵ�ÿ���㶼��дһ�飬���������Ԫ������ƽ��
ע�⣺�벻Ҫ�ڳ��������鳤�ȵ�λ��д��Ԫ�ء������������� �͵� ���������޸ģ���Ҫ�Ӻ��������κζ���
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr)
//    {
//        int size = arr.size();
//        //�ҵ���Ҫ��д�����һ����
//        int current = 0, dest = -1;
//        while (current < size)
//        {
//            if (arr[current] == 0) dest += 2;
//            else /*if(arr[current] != 0)*/ ++dest;
//            if (dest >= size - 1) break;
//            ++current;
//        }
//        //����߽����
//        if (dest == size) {
//            arr[size - 1] = 0;
//            dest -= 2, --current;
//        }
//        //�Ӻ���ǰ��д
//        while (current >= 0) {
//            if (arr[current] != 0) arr[dest--] = arr[current--];
//            else /*if(arr[current] == 0)*/ arr[dest] = arr[dest - 1] = arr[current--], dest -= 2;
//        }
//    }
//};











/************************************************* ��������LeetCode��************************************************/
/*
��дһ���㷨���ж�һ���� n �ǲ��ǿ�����
���������� ����Ϊ��
����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ����
Ȼ���ظ��������ֱ���������Ϊ1��Ҳ����������ѭ����ʼ�ձ䲻��1
���������̽��Ϊ1����ô��������ǿ�����
���n�ǿ������ͷ���true�����ǣ��򷵻�false
*/
////˫ָ��ⷨ������ָ��
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int bitSum(int num)
//    {
//        int ret = 0;
//        while (num != 0)
//        {
//            ret += (num % 10) * (num % 10);
//            num /= 10;
//        }
//        return ret;
//    }
//    bool isHappy(int n)
//    {
//        int slow = n, fast = bitSum(n);
//        while (slow != fast) {
//            slow = bitSum(slow);
//            fast = bitSum(bitSum(fast));
//        }
//        return slow == 1;
//    }
//};
////����
//#include <iostream>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    unordered_set<int> Set;
//    bool isHappy(int n)
//    {
//        while (true)
//        {
//            int ret = 0;
//            while (n) {
//                ret += (n % 10) * (n % 10);
//                n /= 10;
//            }
//            if (ret == 1) return true;
//            if (Set.find(ret) != Set.end()) return false;
//            Set.insert(ret);
//            n = ret;
//        }
//    }
//};










/************************************************** ʢ���ˮ��������LeetCode��******************************************/
/*
����һ������Ϊn����������height ����n�����ߣ���i���ߵ������˵��� (i, 0) �� (i, height[i]) 
�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ
�����������Դ�������ˮ��
˵�����㲻����б����
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    V = height * width
//    left��right���м��ƶ�, ����width��С, ������V����, �����ø߶�����, ����ÿ�ν��߶Ƚϵ͵Ķ���
//    */
//    int maxArea(vector<int>& height)
//    {
//        int ret = 0;
//        int left = 0, right = height.size() - 1;
//        while (left < right) {
//            ret = max(ret, (right - left) * min(height[left], height[right]));
//            if (height[left] >= height[right]) --right;
//            else /*if(height[left] < height[right])*/ ++left;
//        }
//        return ret;
//    }
//};











/*********************************************** ��Ч�����εĸ�����LeetCode��*******************************************/
/*
����һ�������Ǹ�����������nums ���������п�����������������ߵ���Ԫ�����
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int triangleNumber(vector<int>& nums)
//    {
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//
//        int ret = 0;
//        for (int i = size - 1; i >= 2; --i)//�ȹ̶�һ�������
//        {
//            int left = 0, right = i - 1;
//            while (left < right)
//            {
//                if (nums[left] + nums[right] > nums[i]) {
//                    ret += right - left;
//                    --right;
//                }
//                else /*if(nums[left] + nums[right] <= nums[i])*/ {
//                    ++left;
//                }
//            }
//        }
//        return ret;
//    }
//};












/******************************************** �����ܼ۸�ΪĿ��ֵ��������Ʒ��LeetCode��**********************************/
/*
���ﳵ�ڵ���Ʒ�۸��������¼������price�����ڹ��ﳵ���ҵ�������Ʒ�ļ۸��ܺ͸պ���target
�����ڶ��������������һ�������
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& price, int target)
//    {
//        int size = price.size();
//        int left = 0, right = size - 1;
//        while (left < right)
//        {
//            int sum = price[left] + price[right];
//            if (sum > target) --right;
//            else if (sum < target) ++left;
//            else /* if(sum == target) */ return { price[left], price[right] };
//        }
//        return { 0,0 };
//    }
//};












/*************************************************** ����֮�ͣ�LeetCode��***********************************************/
/*
����һ����������nums���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��
ͬʱ������ nums[i] + nums[j] + nums[k] == 0
���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ��
ע�⣺���в����԰����ظ�����Ԫ��
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums)
//    {
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//
//        vector<vector<int>> ret;
//        for (int i = size - 1; i >= 2;)//�̶����һ����
//        {
//            if (nums[i] < 0) return ret;//���һ������Ϊ����, ��ʱ�Ѿ��������ҵ�Ϊ0�������
//            int left = 0, right = i - 1;
//            int target = -nums[i];
//            while (left < right)
//            {
//                int sum = nums[left] + nums[right];
//                if (sum > target) --right;
//                else if (sum < target) ++left;
//                else /*sum == 0*/ {
//                    ret.push_back({ nums[left], nums[right], nums[i] });
//                    ++left, --right;
//                    //ȥ��
//                    while (left < right && nums[left] == nums[left - 1]) left++;
//                    while (left < right && nums[right] == nums[right + 1]) right--;
//                }
//            }
//            --i;
//            while (i >= 2 && nums[i] == nums[i + 1]) i--;//ȥ��
//        }
//        return ret;
//    }
//};












/************************************************* ����֮�ͣ�LeetCode��*************************************************/
/*
����һ����n��������ɵ�����nums����һ��Ŀ��ֵtarget
�����ҳ���������������ȫ�������Ҳ��ظ�����Ԫ�� [nums[a], nums[b], nums[c], nums[d]] 
����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����
0 <= a, b, c, d < n
a��b��c �� d ������ͬ
nums[a] + nums[b] + nums[c] + nums[d] == target
����԰�����˳�򷵻ش�
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target)
//    {
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> ret;
//
//        for (int i = size - 1; i >= 3;)//�ȹ̶����һ����
//        {
//            for (int j = i - 1; j >= 2;)//�̶������ڶ�����
//            {
//                //˫ָ��
//                int left = 0, right = j - 1;
//                long long aim = (long long)target - nums[i] - nums[j];
//                while (left < right)
//                {
//                    int sum = nums[left] + nums[right];
//                    if (sum > aim) --right;
//                    else if (sum < aim) ++left;
//                    else /*sum == 0*/ {
//                        ret.push_back({ nums[left++], nums[right--], nums[i], nums[j] });
//                        //ȥ��
//                        while (left < right && nums[left] == nums[left - 1]) left++;
//                        while (left < right && nums[right] == nums[right + 1]) right--;
//                    }
//                }
//                --j;
//                while (j >= 2 && nums[j] == nums[j + 1]) --j;
//            }
//            --i;
//            while (i >= 3 && nums[i] == nums[i + 1]) --i;
//        }
//        return ret;
//    }
//};











/*********************************************** ������С�������飨LeetCode��****************************************/
/*
����һ������ n ���������������һ��������target
�ҳ����������������ܺʹ��ڵ��� target �ĳ�����С�� ���������� [numsl, numsl+1, ..., numsr-1, numsr] ��
�������䳤�ȡ���������ڷ��������������飬���� 0
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums)
//    {
//        int size = nums.size();
//        int ret = INT_MAX, sum = 0;
//        for (int start = 0, end = 0; end < size; ++end)
//        {
//            sum += nums[end];
//            while (sum >= target) {
//                ret = min(ret, end - start + 1);
//                sum -= nums[start++];
//            }
//        }
//        return ret == INT_MAX ? 0 : ret;
//    }
//};










/******************************************* ���ظ��ַ�����Ӵ���LeetCode��****************************************/
/*
����һ���ַ��� s �������ҳ����в������ظ��ַ�����Ӵ��ĳ���
*/
//#include <iostream>
//#include <unordered_map>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    unordered_map<char, int> hash;
//    int lengthOfLongestSubstring(string s)
//    {
//        int size = s.size();
//        int ret = 0;
//        for (int left = 0, right = 0; right < size; ++right)
//        {
//            ++hash[s[right]];
//            while (hash[s[right]] > 1) --hash[s[left++]];
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};











/********************************************* �������1�ĸ��� III��LeetCode��***************************************/
/*
����һ������������nums��һ������ k��������Է�ת���k��0 ���򷵻� ����������1��������
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*����ת�����ҵ����������, ��������0�ĸ���������k��*/
//    int longestOnes(vector<int>& nums, int k)
//    {
//        int size = nums.size();
//        int ret = 0;
//        for (int left = 0, right = 0, zero = 0; right < size; ++right)
//        {
//            if (nums[right] == 0) ++zero;
//            while (zero > k)
//                if (nums[left++] == 0) --zero;
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};












/******************************************** �� x ���� 0 ����С��������LeetCode��***********************************/
/*
����һ���������� nums ��һ������ x ��ÿһ�β���ʱ����Ӧ���Ƴ����� nums ����߻����ұߵ�Ԫ�أ�
Ȼ��� x �м�ȥ��Ԫ�ص�ֵ����ע�⣬��Ҫ �޸� �����Թ��������Ĳ���ʹ��
������Խ� x ǡ�� ���� 0 ������ ��С������ �����򣬷��� -1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*
//    ת�����⣺
//    �ҵ�һ�κ�Ϊsum - x�������
//    */
//    int minOperations(vector<int>& nums, int x)
//    {
//        int sum = 0;
//        for (auto& it : nums) sum += it;
//        int target = sum - x;
//        if (target < 0) return -1;
//
//        int ret = -1;
//        int size = nums.size();
//        for (int left = 0, right = 0, tmp = 0; right < size; ++right)
//        {
//            tmp += nums[right];
//            while (tmp > target) tmp -= nums[left++];
//            if (tmp == target) ret = max(ret, right - left + 1);
//        }
//        return ret == -1 ? -1 : size - ret;
//    }
//};












/********************************************** ˮ��������LeetCode��*************************************************/
/*
������̽��һ��ũ����ũ����������ֲ��һ�Ź�������Щ����һ����������fruits��ʾ������fruits[i]�ǵ�i�����ϵ�ˮ������
����Ҫ�����ܶ���ռ�ˮ����Ȼ����ũ���������趨��һЩ�ϸ�Ĺ�أ�����밴��Ҫ���ժˮ����
��ֻ�� ���� ���ӣ�����ÿ������ֻ��װ ��һ���� ��ˮ����ÿ�������ܹ�װ��ˮ������û������
�����ѡ������һ������ʼ��ժ�������� ÿ�� ����������ʼ��ժ�������� ǡ��ժһ��ˮ��
��ժ��ˮ��Ӧ�����������е�ˮ�����͡�ÿ��ժһ�Σ��㽫�������ƶ�����һ��������������ժ
һ�����ߵ�ĳ����ǰ����ˮ�����������ӵ�ˮ�����ͣ���ô�ͱ���ֹͣ��ժ
����һ���������� fruits ������������ռ���ˮ���������Ŀ
*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    int totalFruit(vector<int>& fruits)
//    {
//        unordered_map<int, int> hash;//���� : ���ִ���
//
//        int size = fruits.size();
//        int ret = 0;
//        for (int left = 0, right = 0; right < size; ++right)
//        {
//            ++hash[fruits[right]];
//            while (hash.size() > 2) {
//                --hash[fruits[left]];
//                if (hash[fruits[left]] == 0) hash.erase(fruits[left]);
//                ++left;
//            }
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};











/***************************************** �ҵ��ַ�����������ĸ��λ�ʣ�LeetCode��***************************************/
/*
���������ַ���s��p���ҵ�s������p����λ�ʵ��Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��
��λ�� ָ����ͬ��ĸ�������γɵ��ַ�����������ͬ���ַ�����
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p)
//    {
//        vector<int> ret;
//        int Shash[26] = { 0 };//��¼������ÿ����ĸ���ֵĴ���
//        int Phash[26] = { 0 };//��¼p��ÿ����ĸ���ֵĴ���
//        for (auto& it : p) ++Phash[it - 'a'];
//
//        int length = p.size();
//        for (int left = 0, right = 0, count = 0; right < s.size(); ++right)
//        {
//            char in = s[right];
//            if (++Shash[in - 'a'] <= Phash[in - 'a']) ++count;//����Ҫ��, ������
//            if (right - left + 1 > length)
//            {
//                char out = s[left++];
//                if (Shash[out - 'a']-- <= Phash[out - 'a']) --count;
//            }
//            if (count == length) ret.push_back(left);
//        }
//        return ret;
//    }
//};











/******************************************* �������е��ʵ��Ӵ���LeetCode��******************************************/
/*
����һ���ַ���s��һ���ַ�������words��words�������ַ���������ͬ
s�еĴ����Ӵ���ָһ������words�������ַ���������˳�����������������Ӵ�
���磬��� words = ["ab","cd","ef"]�� ��ô "abcdef"�� "abefcd"��"cdabef"�� "cdefab"��"efabcd"�� �� "efcdab"
���Ǵ����Ӵ��� "acdbef" ���Ǵ����Ӵ�����Ϊ�������κ� words ���е�����
�������д����Ӵ���s�еĿ�ʼ�����������������˳�򷵻ش�
*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words)
//    {
//        unordered_map<string, int> hash1;//ͳ��words��ÿ�����ʳ��ֵĴ���
//        for (string& it : words) ++hash1[it];
//
//        vector<int> ret;
//        int size = words.size(), length = words[0].size();
//
//        for (int i = 0; i < length; ++i)
//        {
//            unordered_map<string, int> hash2;//ͳ�ƴ�����ÿ�����ʳ��ֵĴ���
//            for (int left = i, right = i, count = 0; right + length <= s.size(); right += length)
//            {
//                string in = s.substr(right, length);
//                ++hash2[in];
//                if (hash1.count(in) && hash2[in] <= hash1[in]) ++count;//�����ڵ���Ϊ��Ч����
//                if (right - left + 1 > length * size)
//                {
//                    string out = s.substr(left, length);
//                    if (hash1.count(out) && hash2[out] <= hash1[out]) --count;//�����ڵ���Ϊ��Ч����
//                    --hash2[out];
//                    left += length;
//                }
//                if (count == size) ret.push_back(left);
//            }
//        }
//        return ret;
//    }
//};












/********************************************* ��С�����Ӵ���LeetCode��**********************************************/
/*
����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ�
��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� ""
*/
//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//    string minWindow(string s, string t)
//    {
//        int kinds = 0;//��¼��Ч�ַ���������
//        int hash1[127] = { 0 };//ͳ��string t�������ַ����ֵĸ���
//        for (char& ch : t) if (hash1[ch]++ == 0) ++kinds;
//
//        int hash2[128] = { 0 };//ά�������������ַ����ֵĸ���
//        int min_length = INT_MAX, begin = -1;
//
//        //count��Ǵ�������ȫ���ֵ���Ч�ַ�������
//        for (int left = 0, right = 0, count = 0; right < s.size(); ++right)
//        {
//            char in = s[right];
//            ++hash2[in];
//            if (hash2[in] == hash1[in]) ++count;
//            while (count == kinds)
//            {
//                if (right - left + 1 < min_length)
//                {
//                    min_length = right - left + 1;
//                    begin = left;
//                }
//                char out = s[left];
//                if (hash2[out] == hash1[out]) --count;
//                ++left, --hash2[out];
//            }
//        }
//        if (begin == -1) return "";
//        else return s.substr(begin, min_length);
//    }
//};













/*********************************** �����������в���Ԫ�صĵ�һ�������һ��λ�ã�LeetCode��***************************/
/*
����һ�����շǵݼ�˳�����е���������nums����һ��Ŀ��ֵtarget�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ��
��������в�����Ŀ��ֵtarget������[-1, -1]
�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨���������
*/
////����һ
//#include <iostream>
//#include <vector>
//using namespace std;
////���������,�˻�ΪO(n),������Ԫ����ͬ�����
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        int beginRet = -1, endRet = -1;
//        int left = 0, right = nums.size() - 1;
//        int index = -1;
//        while (left <= right)
//        {
//            int mid = (left + right) >> 1;
//            if (nums[mid] > target) right = mid - 1;
//            else if (nums[mid] < target) left = mid + 1;
//            else {
//                index = mid;
//                break;
//            }
//        }
//        if (index != -1)
//        {
//            for (int i = index; i >= 0; --i) {
//                if (nums[i] == target) beginRet = i;
//                else break;
//            }
//            for (int i = index; i < nums.size(); ++i) {
//                if (nums[i] == target) endRet = i;
//                else break;
//            }
//        }
//        return { beginRet, endRet };
//    }
//};
////������
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target)
//    {
//        int beginRet = -1, endRet = -1;
//        if (nums.size() == 0) return { beginRet, endRet };
//        //����˵�
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target) left = mid + 1;
//            else /*if(nums[mid] >= target)*/ right = mid;
//        }
//        if (nums[left] == target) beginRet = left;
//        //���Ҷ˵�
//        left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (nums[mid] <= target) left = mid;
//            else /*if((nums[mid] > target)*/ right = mid - 1;
//        }
//        if (nums[left] == target) endRet = right;
//        return { beginRet, endRet };
//    }
//};










/************************************************* ��������λ�ã�LeetCode��**********************************************/
/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ��
�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] >= target) right = mid;
//            else /*if(nums[mid] < target)*/ left = mid + 1;
//        }
//        if (nums[left] < target) return right + 1;
//        else return right;
//    }
//};











/**************************************************** x��ƽ����LeetCode��*********************************************/
/*
����һ���Ǹ�����x�����㲢����x������ƽ����
���ڷ������������������ֻ�����������֣�С�����ֽ�����ȥ
ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5
*/
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//    int mySqrt(int x)
//    {
//        if (x < 1) return 0;
//        int left = 1, right = x;
//        while (left < right)
//        {
//            int mid = left + ((right - left + 1) >> 1);
//            if ((long long)mid * mid <= x) left = mid;
//            else /*if(tmp > x)*/ right = mid - 1;
//        }
//        return left;
//    }
//};











/*********************************************** ɽ������ķ嶥������LeetCode��******************************************/
/*
�����������Ե����� arr ��Ϊ ɽ������ ��
arr.length >= 3
���� i��0 < i < arr.length - 1��ʹ�ã�
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
������������ɵ�ɽ������ arr ���������� arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]���±�i
�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log(n)) �Ľ������
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr)
//    {
//        int left = 1, right = arr.size() - 2;//��һ�������һ��һ�����ǽ��
//        while (left < right)
//        {
//            int mid = left + ((right - left + 1) >> 1);
//            if (arr[mid] > arr[mid - 1]) left = mid;
//            else /*if(arr[mid] <= target)*/ right = mid - 1;
//        }
//        return left;
//    }
//};











/************************************************ Ѱ�ҷ�ֵ��LeetCode��***************************************************/
/*
��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ��
����һ����������nums���ҵ���ֵԪ�ز�������������������ܰ��������ֵ������������£������κ�һ����ֵ����λ�ü���
����Լ��� nums[-1] = nums[n] = -��
�����ʵ��ʱ�临�Ӷ�ΪO(log n)���㷨�����������
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findPeakElement(vector<int>& nums)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] > nums[mid + 1]) right = mid;
//            else /*if(nums[mid] < target)*/ left = mid + 1;
//        }
//        return left;
//    }
//};











/***************************************** Ѱ����ת���������е���Сֵ��LeetCode��****************************************/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int findMin(vector<int>& nums)
//    {
//        int left = 0, right = nums.size() - 1;
//        int flag = nums[right];//��¼��ת�������е����һ����
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (nums[mid] > flag) left = mid + 1;
//            else /*if(nums[mid] < flag)*/ right = mid;
//        }
//        return nums[right];
//    }
//};









/************************************************* ������LeetCode��******************************************************/
/*
ĳ�༶ n λͬѧ��ѧ��Ϊ 0 ~ n-1�����������¼���������� records���ٶ�����һλͬѧȱϯ���뷵������ѧ��
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int takeAttendance(vector<int>& records)
//    {
//        int left = 0, right = records.size() - 1;
//        while (left < right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (records[mid] == mid) left = mid + 1;
//            else right = mid;
//        }
//        return records[left] == left ? left + 1 : left;
//    }
//};