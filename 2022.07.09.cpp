#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0,right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right)/2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else 
            {
                return mid;
            }
        }
        return -1;
    }
};
int main()
{
	vector<int>nums;
	nums.push_back(-1);
	nums.push_back(0);
	Solution s;
	int num = s.search(nums,13);
	if(num == -1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<nums[num]<<endl;
	return 0;
}






//��������
//����˼·�����ö�ά�������е�������
//
//�������е��������Եó���
//a.��һ���е�ĳ�����֣����ϵ����ֶ�����С
//b.��һ���е�ĳ�����֣����ҵ����ֶ�������
//�������̣�
//a.���ȴ��������½�����.
//b.�����ǰ���ִ���target,��ô����������һλ,�����ǰ����С��target,��ô����������һλ��
//c.���ҵ�target,����true; ���Խ�磬����false;
#include<iostream>
using namespace std;
class Solution
{
public:
    bool Find(int target, vector<vector<int> > array)
	{
        if(array.size() == 0)  return false;
        int r = array.size();//�� 
        int l = array[0].size();//�� 
        int left = 0, down = r - 1;
        while(left<l && down>=0)
        {
            int tmp = array[down][left];
            if( tmp == target) return true;
            else if(tmp < target) left++;
            else down--;
        }
        return false;
    }
};








//����һ������Ϊn������nums�������ҵ���ֵ��������������������ܰ��������ֵ������������£������κ�һ������λ�ü��ɡ�
//1.��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء��ϸ���ڼ������е���
//2.���� nums[-1] = nums[n] = ��С 
//3.����������Ч�� i ���� nums[i] != nums[i + 1]
class Solution
{
public:
    int findPeakElement(vector<int>& nums)
	{
        int left = 0;
        int right = nums.size() - 1;
        //���ַ�
        while(left < right){
            int mid = (left + right) / 2;
            //�ұ������£���һ�����·�
            if(nums[mid] > nums[mid + 1])
                right = mid;
            //�ұ������ϣ�һ�����ҵ�����
            else
                left = mid + 1;
        }
        //����һ������
        return right;
    }
};




//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
//����һ������,�����������е�����Ե�����P��
//����P��1000000007ȡģ�Ľ������� �����P mod 1000000007


//�����ⷨ
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int kmod = 1000000007;
class Solution
{
public:
    int InversePairs(vector<int> data)
	{
        int ret = 0;
        int n = data.size();
        for (int i = 0; i < n; ++i)
		{
            for (int j = i + 1; j < n; ++j)
			{
                if (data[i] > data[j])
				{
                    ret += 1;
                    ret %= kmod;
                }
            }
        }
 
        return ret;
    }
};
int main()
{
	vector<int>data;
	for(int i = 1;i<=3;++i)
	{
		data.push_back(i);
	}
	Solution s;
	cout<<s.InversePairs(data)<<endl;;
	return 0;
}





