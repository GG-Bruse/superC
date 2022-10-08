#include<iostream>
#define MAX 1024
using namespace std;
template<class type>
class Solution
{
public:
        Solution()
        {
                arr[0] = 0;
                this->size = 0;
        }
        type getMax()//获取最大值
        {
                type max = arr[0];
                for (int i = 0; i < size; ++i)
                {
                        if (max < arr[i])
                                max = arr[i];
                }
                return max;
        }
        void push_back(type temp)//尾插
        {
                if (MAX > size)
                {
                        ++size;
                        arr[size - 1] = temp;
                }
        }
        void MySort()//排序
        {
                for (int i = 1; i < size; ++i)
                {
                        for (int j = 0; j < size - i; ++j)
                        {
                                if (arr[j] > arr[j+1])
                                {
                                        type temp = arr[j];
                                        arr[j] = arr[j + 1];
                                        arr[j + 1] = temp;
                                }
                        }
                }
        }
        void forEach()
        {
                for (int i = 0; i < size; ++i)
                {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
private:
        type arr[MAX];
        int size;
};
int main()
{
        Solution<int> s;
        for (int i = 0; i < 10; ++i)
        {
                s.push_back(10 - i);//插入数据10-1
        }
        s.MySort();//从小到大排序
        s.forEach();//遍历输出数组
        cout<<s.getMax();//输出最大值
        return 0;
}





#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
        vector<int>v;
        list<int>l;
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
                int temp = 0;
                cin >> temp;
                v.push_back(temp);
                l.push_back(temp);
        }

        sort(v.begin(), v.end());
        l.sort();

        for_each(v.begin(), v.end(), [&](int val) {
                cout << val << " ";
                });
        cout << endl;
        for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
        {
                cout << *it << " ";
        }
        return 0;
}
