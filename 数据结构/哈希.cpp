/*
顺序结构以及平衡树中，元素关键码与其存储位置之间没有对应的关系，因此在查找一个元素时，必须要经过关键码的多次比较。
顺序查找时间复杂度为O(N)，平衡树中为树的高度，即O(log_2 N)，搜索的效率取决于搜索过程中元素的比较次数。
理想的搜索方法：可以不经过任何比较，一次直接从表中得到要搜索的元素。
如果构造一种存储结构，通过某种函数(hashFunc)使元素的存储位置与它的关键码之间能够建立一一映射的关系，那么在查找时通过该函数可以很快找到该元素
*/
/*
插入元素:
根据待插入元素的关键码，以此函数计算出该元素的存储位置并按此位置进行存放
搜索元素:
对元素的关键码进行同样的计算，把求得的函数值当做元素的存储位置，在结构中按此位置取元素比较，若关键码相等，则搜索成功

该方式即为哈希(散列)方法，哈希方法中使用的转换函数称为哈希(散列)函数，构造出来的结构称为哈希表(Hash Table)(或者称散列表)
*/


//哈希冲突
/*
不同关键字通过相同哈希哈数计算出相同的哈希地址，该种现象称为哈希冲突或哈希碰撞。
把具有不同关键码而具有相同哈希地址的数据元素称为“同义词”。
*/
//哈希函数
/*
引起哈希冲突的一个原因可能是: 哈希函数设计不够合理。
哈希函数设计原则:
1. 哈希函数的定义域必须包括需要存储的全部关键码，而如果散列表允许有m个地址时，其值域必须在0到m-1之间
2. 哈希函数计算出来的地址能均匀分布在整个空间中
3. 哈希函数应该比较简单
*/

/*
哈希冲突的解决:
解决哈希冲突两种常见的方法是: 闭散列和开散列

闭散列
也叫开放定址法，当发生哈希冲突时，如果哈希表未被装满，说明在哈希表中必然还有空位置，那么可以把key存放到冲突位置中的"下一个"空位置中去

1.线性探测: 从发生冲突的位置开始，依次向后探测，直到寻找到下一个空位置为止
插入: 通过哈希函数获取待插入元素在哈希表中的位置
	  若该位置中没有元素则直接插入新元素，若该位置中有元素发生哈希冲突，使用线性探测找到下一个空位置，插入新元素
删除: 采用闭散列处理哈希冲突时，不能随便物理删除哈希表中已有的元素。
	  若直接删除元素会影响其他元素的搜索。因此线性探测采用标记的伪删除法来删除一个元素





开散列
又称链地址法(开链法)，首先对关键码集合用散列函数计算散列地址，具有相同地址的关键码归于同一子集合。
每一个子集合称为一个桶，各个桶中的元素通过一个单链表链接起来，各链表的头结点存储在哈希表中
*/









#include<iostream>
#include<vector>
using std::pair;
using std::make_pair;
using std::vector;
enum State{
	EMPTY,
	EXIST,
	DELETE
};
template<class K, class V>
struct HashData {
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K,class V>
class HashTable
{
public:
	bool insert(const pair<K, V>& kv) {
		if (find(kv.first) != nullptr) return false;//不允许键值冗余

		if (_table.size() == 0 || 10 * _size / _table.size() >= 7) {//扩容
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V> new_table;
			new_table._table.resize(newSize);
			//旧表数据映射到新表
			for (auto& e : _table) {
				if (e._state == EXIST) {
					new_table.insert(e._kv);
				}
			}
			_table.swap(new_table._table);
		}

		size_t index = kv.first % _table.size();
		while (_table[index]._state == EXIST) {//线性探测
			++index;
			index %= _table.size();
		}
		_table[index]._kv = kv;
		_table[index]._state = EXIST;
		++_size;
		return true;
	}

	void erase(const K& key) {
		
	}

	HashData* find(const K& key) {
		if (_table.size() == 0) return nullptr;
		size_t index = key % _table.size();
		while (_table[index]._state != EMPTY) {
			if (_table[index]._kv.first == key) {
				return &_table[index];
			}
			++index;
			index %= _table.size();
		}
		return nullptr;
	}

private:
	vector<HashData<K, V>> _table;
	size_t _size;//有效数据
};

void  Test() {
	int array[] = { 1,11,4,15,26,7,44,9 };
	HashTable<int, int> ht;
	for (auto& e : array)
	{
		ht.insert(make_pair(e, e));
	}

}
int main()
{
	Test();
	return 0;
}












