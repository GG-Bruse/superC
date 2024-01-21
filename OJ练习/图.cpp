/******************************************** ʡ��������LeetCode��*********************************************/
/*
�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ��������
�ҳ��� b ����� c ֱ����������ô���� a ����� c ���������
ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�
����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ��������
�� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
���ؾ����� ʡ�� ������
*/
//���鼯
//#include <iostream>
//#include <vector>
//using namespace std;
//class UnionFindSet
//{
//public:
//    UnionFindSet(size_t size) :_ufs(size, -1) {}
//    int FindRoot(int value)
//    {
//        int root = value;
//        while (_ufs[root] >= 0) root = _ufs[root];
//        return root;
//    }
//    bool Union(int value1, int value2)
//    {
//        int root1 = FindRoot(value1);
//        int root2 = FindRoot(value2);
//        //������ͬһ������,����ϲ�
//        if (root1 == root2) return false;
//        //�ϲ�����
//        _ufs[root1] += _ufs[root2];
//        _ufs[root2] = root1;
//        return true;
//    }
//    int IsInSet(int value1, int value2) {
//        return FindRoot(value1) == FindRoot(value2);
//    }
//    size_t GetSetSize()
//    {
//        size_t count = 0;
//        for (int i = 0; i < _ufs.size(); ++i)
//            if (_ufs[i] < 0) ++count;
//        return count;
//    }
//private:
//    vector<int> _ufs;
//};
//class Solution1
//{
//public:
//    int findCircleNum(vector<vector<int>>& isConnected)
//    {
//        UnionFindSet ufs(isConnected.size());
//        for (size_t i = 0; i < isConnected.size(); ++i)
//            for (size_t j = 0; j < isConnected[0].size(); ++j)
//                if (isConnected[i][j] == 1) ufs.Union(i, j);
//        return ufs.GetSetSize();
//    }
//};
//class Solution2
//{
//public:
//    int findCircleNum(vector<vector<int>>& isConnected)
//    {
//        vector<int> ufs(isConnected.size(), -1);
//        auto findRoot = [&ufs](int value) {
//            while (ufs[value] >= 0) value = ufs[value];
//            return value;
//        };
//        auto getSetSize = [&ufs]() {
//            size_t count = 0;
//            for (int i = 0; i < ufs.size(); ++i)
//                if (ufs[i] < 0) ++count;
//            return count;
//        };
//        for (size_t i = 0; i < isConnected.size(); ++i)
//            for (size_t j = 0; j < isConnected[0].size(); ++j)
//                if (isConnected[i][j] == 1)
//                {
//                    int root1 = findRoot(i);
//                    int root2 = findRoot(j);
//                    if (root1 != root2)
//                    {
//                        ufs[root1] += ufs[root2];
//                        ufs[root2] = root1;
//                    }
//                }
//        return getSetSize();
//    }
//};









/**************************************** ��ʽ���̵Ŀ������ԣ�LeetCode��***************************************/
/*
����һ���ɱ�ʾ����֮���ϵ���ַ���������ɵ����飬ÿ���ַ������� equations[i] �ĳ���Ϊ 4��
���������ֲ�ͬ����ʽ֮һ��"a==b" �� "a!=b"�������a �� b ��Сд��ĸ����һ����ͬ������ʾ����ĸ��������
ֻ�е����Խ�������������������Ա��������и����ķ���ʱ�ŷ��� true�����򷵻� false
*/
////���鼯
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool equationsPossible(vector<string>& equations)
//    {
//        vector<int> ufs(26, -1);
//        auto findRoot = [&ufs](int value) {
//            while (ufs[value] >= 0) value = ufs[value];
//            return value;
//        };
//        //��һ��,�Ȱ���ȵ�ֵ�ϲ���һ��������
//        for (auto& str : equations)
//        {
//            if (str[1] == '=')
//            {
//                int root1 = findRoot(str[0] - 'a');
//                int root2 = findRoot(str[3] - 'a');
//                if (root1 != root2)
//                {
//                    ufs[root1] += ufs[root2];
//                    ufs[root2] = root1;
//                }
//            }
//        }
//        //�ڶ���,�鿴����ȵ�ֵ�ڲ���һ������,�ھ����,����false
//        for (auto& str : equations)
//        {
//            if (str[1] == '!')
//            {
//                int root1 = findRoot(str[0] - 'a');
//                int root2 = findRoot(str[3] - 'a');
//                if (root1 == root2) return false;
//            }
//        }
//        return true;
//    }
//};