//序列式容器: vector、list、deque
//关联式容器: map、set

/*
关联式容器也是用来存储数据的，与序列式容器不同的是，其里面存储的是<key, value>结构的键值对，在数据检索时比序列式容器效率更高
*/


//键值对
/*
用来表示具有一一对应关系的一种结构，该结构中一般只包含两个成员变量key和value，key代表键值，value表示与key对应的信息
template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;
	pair(): first(T1()), second(T2()) {}
	pair(const T1& a, const T2& b): first(a), second(b) {}
};

//make_pair:
template <class T1,class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
}
*/




//set
/*
1. set是按照一定次序存储元素的容器

2. 在set中，元素的value也标识它(value就是key，类型为T)，并且每个value必须是唯一的。
set中的元素不能在容器中修改(元素总是const)，但是可以从容器中插入或删除它们。

3. 在内部，set中的元素总是按照其内部比较对象(类型比较)所指示的特定严格弱排序准则进行排序。 set中的元素默认按照小于来比较

4. set容器通过key访问单个元素的速度通常比unordered_set容器慢，但它们允许根据顺序对子集进行直接迭代。
 set中查找某个元素，时间复杂度为O(log_2 n)

5. set在底层是用二叉搜索树(红黑树)实现的
*/

//multiset
/*
1. multiset是按照特定顺序存储元素的容器，其中元素是可以重复的

2. 在multiset中，元素的value也会识别它
(因为multiset中本身存储的就是<value, value>组成的键值对，因此value本身就是key，key就是value，类型为T)
multiset元素的值不能在容器中进行修改(因为元素总是const的)，但可以从容器中插入或删除。

3. 在内部，multiset中的元素总是按照其内部比较规则(类型比较)所指示的特定严格弱排序准则进行排序

4. multiset容器通过key访问单个元素的速度通常比unordered_multiset容器慢，但当使用迭代器遍历时会得到一个有序序列

5. multiset底层结构为二叉搜索树(红黑树)

6. 在multiset中找某个元素，时间复杂度为O(log_2 N)
*/



//map
/*
1. map是关联容器，它按照特定的次序(按照key来比较)存储由键值key和值value组合而成的元素

2. 在map中，键值key通常用于排序和惟一地标识元素，而值value中存储与此键值key关联的内容
键值key和值value的类型可能不同，并且在map的内部，key与value通过成员类型value_type绑定在一起，为其取别名称为pair
typedef pair<const key, T> value_type;

3. 在内部，map中的元素总是按照键值key进行比较排序的

4. map中通过键值访问单个元素的速度通常比unordered_map容器慢
但map允许根据顺序对元素进行直接迭代(即对map中的元素进行迭代时，可以得到一个有序的序列)

5. map支持下标访问符，即在[]中放入key，就可以找到与key对应的value

6. map通常被实现为平衡二叉搜索树(红黑树)
*/

//multimap
/*
1. multimaps是关联式容器，它按照特定的顺序，存储由key和value映射成的键值对<key,value>，其中多个键值对之间的key是可以重复的

2. 在multimap中，通常按照key排序和惟一地标识元素，而映射的value存储与key关联的内容
key和value的类型可能不同，通过multimap内部的成员类型value_type组合在一起，value_type是组合key和value的键值对:
typedef pair<const Key, T> value_type;

3. 在内部，multimap中的元素总是通过其内部比较对象，按照指定的特定严格弱排序标准对key进行排序的

4. multimap通过key访问单个元素的速度通常比unordered_multimap容器慢，但是使用迭代器直接遍历multimap中的元素可以得到关于key有序的序列

5. multimap在底层用二叉搜索树(红黑树)来实现

注意: multimap和map的唯一不同就是: map中的key是唯一的，而multimap中key是可以重复的
*/