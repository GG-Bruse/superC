//AVL树的提出
/*
二叉搜索树虽可以缩短查找的效率，但如果数据有序或接近有序二叉搜索树将退化为单支树，查找元素相当于在顺序表中搜索元素，效率低下

两位俄罗斯的数学家G.M.Adelson-Velskii和E.M.Landis在1962年明了一种解决上述问题的方法:
当向二叉搜索树中插入新结点后，若能保证每个结点的左右子树高度之差的绝对值不超过1(需要对树中的结点进行调整)，即可降低树的高度，从而减少平均搜索长度
*/


/*
一棵AVL树 是空树或者是具有以下性质的二叉搜索树:
1. 它的左右子树都是AVL树
2. 左右子树高度之差(简称平衡因子)的绝对值不超过1(-1/0/1)
3. 若一棵二叉搜索树是高度平衡的，其就是AVL树。若它有n个结点，其高度可保持在O(log_2 n)，搜索时间复杂度O(log_2 n)
*/



#include <utility>
using std::pair;

template<class K,class V>
class AVLTreeNode 
{
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;

	pair<K, V> _data;
	int _balance_factor;//平衡因子
};








