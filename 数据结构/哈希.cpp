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

1. 线性探测: 从发生冲突的位置开始，依次向后探测，直到寻找到下一个空位置为止
插入: 通过哈希函数获取待插入元素在哈希表中的位置
	  若该位置中没有元素则直接插入新元素，若该位置中有元素发生哈希冲突，使用线性探测找到下一个空位置，插入新元素
删除: 采用闭散列处理哈希冲突时，不能随便物理删除哈希表中已有的元素。
	  若直接删除元素会影响其他元素的搜索。因此线性探测采用标记的伪删除法来删除一个元素

2. 二次探测
线性探测的缺陷是产生冲突的数据堆积在一块，这与其找下一个空位置有关系(逐个往后去找)。
因此二次探测为了避免该问题，找下一个空位置的方法为: H_i = (H_0 + i^2) % m, 或者: H_i = (H_0 - i^2) % m。其中: i = 0,1,2,3……
H_0是通过散列函数Hash(x)对元素的关键码 key 进行计算得到的位置，m是表的大小。

研究表明: 当表的长度为质数且表装载因子a不超过0.5时，新的表项一定能够插入，而且任何一个位置都不会被探查两次。
因此只要表中有一半的空位置，在搜索时可以不考虑表装满的情况，但在插入时必须确保表的装载因子a不超过0.5，若超出必须考虑增容



开散列
又称链地址法(开链法)，首先对关键码集合用散列函数计算散列地址，具有相同地址的关键码归于同一子集合。
每一个子集合称为一个桶，各个桶中的元素通过一个单链表链接起来，各链表的头结点存储在哈希表中
*/






//#include <iostream>
//#include <vector>
//#include <string>
//using std::string;
//using std::vector;
//using std::pair;
//using std::make_pair;
//using std::cout;
//using std::endl;

//namespace CloseHash {
//#define LINEAR
//	enum State {
//		EMPTY,
//		EXIST,
//		DELETE
//	};
//	template<class K, class V>
//	struct HashData {
//		pair<K, V> _kv;
//		State _state = EMPTY;
//	};
//
//	template<class K>//默认仿函数
//	struct hash {
//		size_t operator()(const K& key) {
//			return (size_t)key;
//		}
//	};
//	template<>//特化
//	struct hash<string> {
//		//BKDR算法
//		size_t operator()(const string& key) {
//			size_t sum = 0;
//			for (auto& e : key) {
//				sum = sum * 131 + e;
//			}
//			return sum;
//		}
//	};
//
//	template<class K, class V, class Hash = hash<K>>
//	class HashTable
//	{
//	public:
//		bool insert(const pair<K, V>& kv) {
//			if (find(kv.first) != nullptr) return false;//不允许键值冗余
//
//			if (_table.size() == 0 || 10 * _size / _table.size() >= 5) {//扩容
//				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
//				HashTable<K, V, Hash> new_table;
//				new_table._table.resize(newSize);
//				//旧表数据映射到新表
//				for (auto& e : _table) {
//					if (e._state == EXIST) {
//						new_table.insert(e._kv);
//					}
//				}
//				_table.swap(new_table._table);
//			}
//
//#ifdef LINEAR
//			Hash hash;
//			size_t index = hash(kv.first) % _table.size();//int提升为size_t
//			while (_table[index]._state == EXIST) {//线性探测
//				++index;
//				index %= _table.size();
//			}
//#else //SECONDARY
//			Hash hash;
//			size_t start = hash(kv.first) % _table.size();//int提升为size_t
//			size_t index = start, i = 0;
//			while (_table[index]._state == EXIST) {//二次探测
//				++i;
//				index = start + i * i;
//				index %= _table.size();
//			}
//#endif
//
//			_table[index]._kv = kv;
//			_table[index]._state = EXIST;
//			++_size;
//			return true;
//		}
//
//		bool erase(const K& key) {
//			HashData<K, V>* ret = find(key);
//			if (ret == nullptr) {
//				return false;
//			}
//			else {
//				ret->_state = DELETE;
//				--_size;
//				return true;
//			}
//		}
//
//		HashData<K, V>* find(const K& key) {
//			if (_table.size() == 0) return nullptr;
//#ifdef LINEAR
//			Hash hash;
//			size_t start = hash(key) % _table.size();//int提升为size_t
//			size_t index = start;
//			while (_table[index]._state != EMPTY) {
//				if (_table[index]._state != DELETE && _table[index]._kv.first == key) {
//					return &_table[index];
//				}
//				++index;
//				index %= _table.size();
//				if (index == start) {//当哈希表中全为DELETE 和 EXIST时避免死循环
//					break;
//				}
//			}
//#else //SECONDARY
//			Hash hash;
//			size_t start = hash(key) % _table.size();//int提升为size_t
//			size_t index = start, i = 0;
//			while (_table[index]._state == EXIST) {//二次探测
//				if (_table[index]._state != DELETE && _table[index]._kv.first == key) {
//					return &_table[index];
//				}
//				++i;
//				index = start + i * i;
//				index %= _table.size();
//			}
//#endif
//			return nullptr;
//		}
//
//	private:
//		vector<HashData<K, V>> _table;
//		size_t _size = 0;//有效数据
//	};
//}
//using CloseHash::HashTable;
//void  Test1() {
//	int array[] = { 1,11,4,15,26,7,44,9 };
//	HashTable<int, int> ht;
//	for (auto& e : array)
//	{
//		ht.insert(make_pair(e, e));
//	}
//	ht.erase(4);
//	cout << ht.find(44)->_kv.first << endl;
//}
//void Test2() {
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
//
//	HashTable<string, int> countHT;
//	for (auto& str : arr) {
//		auto ptr = countHT.find(str);
//		if (ptr) {
//			ptr->_kv.second++;
//		}
//		else {
//			countHT.insert(make_pair(str, 1));
//		}
//	}
//}
//int main()
//{
//	//Test1();
//	Test2();
//	return 0;
//}












//#include <iostream>
//#include <vector>
//#include <string>
//using std::string;
//using std::vector;
//using std::pair;
//using std::make_pair;
//using std::cout;
//using std::endl;

//namespace OpenHash {
//	template<class K>//默认仿函数
//	struct hash {
//		size_t operator()(const K& key) {
//			return (size_t)key;
//		}
//	};
//	template<>//特化
//	struct hash<string> {
//		//BKDR算法
//		size_t operator()(const string& key) {
//			size_t sum = 0;
//			for (auto& e : key) {
//				sum = sum * 131 + e;
//			}
//			return sum;
//		}
//	};
//
//	template<class K, class V>
//	struct HashNode {
//		HashNode() = default;
//		HashNode(const pair<K,V>& kv):_kv(kv),_next(nullptr) {}
//		pair<K, V> _kv;
//		HashNode<K, V>* _next;
//	};
//
//	template<class K, class V, class Hash = hash<K>>
//	class HashBucket
//	{
//		typedef HashNode<K, V> Node;
//		
//		inline size_t __stl_next_prime(unsigned long n)
//		{
//			static const size_t __stl_num_primes = 28;
//			static const size_t __stl_prime_list[__stl_num_primes] =
//			{
//			  53,         97,         193,       389,       769,
//			  1543,       3079,       6151,      12289,     24593,
//			  49157,      98317,      196613,    393241,    786433,
//			  1572869,    3145739,    6291469,   12582917,  25165843,
//			  50331653,   100663319,  201326611, 402653189, 805306457,
//			  1610612741, 3221225473, 4294967291
//			};
//			for (size_t i = 0; i < __stl_num_primes; ++i) {
//				if (__stl_prime_list[i] > n) return __stl_prime_list[i];
//			}
//			return -1;
//		}
//	public:
//		bool insert(const pair<K, V>& kv) {
//			Hash hash;
//			if (find(kv.first) != nullptr) return false;//不允许键值冗余
//
//			//荷载因子到达1进行扩容
//			if (_table.size() == 0 || _size == _table.size()) {
//				vector<Node*> new_table;
//				new_table.resize(__stl_next_prime(_table.size()), nullptr);
//				for (size_t i = 0; i < _table.size(); ++i) {
//					Node* cur = _table[i];
//					while (cur != nullptr) {
//						Node* next = cur->_next;
//						size_t hashi = hash(cur->_kv.first) % new_table.size();
//						//头插
//						cur->_next = new_table[hashi];
//						new_table[hashi] = cur;
//						cur = next;
//					}
//					_table[i] = nullptr;
//				}
//				_table.swap(new_table);
//			}
//			
//			size_t hashi = hash(kv.first) % _table.size();
//			//头插
//			Node* newNode = new Node(kv);
//			newNode->_next = _table[hashi];
//			_table[hashi] = newNode;
//			++_size;
//			return true;
//		}
//
//		bool erase(const K& key) {
//			Hash hash;
//
//			if (_table.size() == 0) return false;
//			size_t hashi = hash(key) % _table.size();
//			Node* cur = _table[hashi];
//			Node* prev = nullptr;
//			while (cur != nullptr) {
//				if (cur->_kv.first == key) {
//					if (prev == nullptr) {//头删
//						_table[hashi] = cur->_next;
//					}
//					else {
//						prev->_next = cur->_next;
//					}
//					delete cur;
//					--_size;
//					return true;
//				}
//				prev = cur;
//				cur = cur->_next;
//			}
//			return false;
//		}
//
//
//		Node* find(const K& key) {
//			Hash hash;
//			if (_table.size() == 0) return nullptr;
//			size_t hashi = hash(key) % _table.size();
//			Node* cur = _table[hashi];
//			while (cur != nullptr) {
//				if (cur->_kv.first == key) {
//					return cur;
//				}
//				cur = cur->_next;
//			}
//			return nullptr;
//		}
//
//		~HashBucket(){
//			for (size_t i = 0; i < _table.size(); ++i) {
//				Node* cur = _table[i];
//				while (cur != nullptr) {
//					Node* next = cur->_next;
//					delete cur;
//					cur = next;
//				}
//				_table[i] = nullptr;
//			}
//		}
//
//		//存储的元素个数
//		size_t size() { return _size; }
//
//		// 表的长度
//		size_t table_size()
//		{
//			return _tables.size();
//		}
//
//		// 桶的个数
//		size_t bucket_num(){
//			size_t num = 0;
//			for (size_t i = 0; i < _tables.size(); ++i) {
//				if (_tables[i]) {
//					++num;
//				}
//			}
//			return num;
//		}
//
//		size_t max_bucket_length() {
//			size_t maxLen = 0;
//			for (size_t i = 0; i < _tables.size(); ++i) {
//				size_t len = 0;
//				Node* cur = _tables[i];
//				while (cur){
//					++len;
//					cur = cur->_next;
//				}
//				if (len > maxLen) maxLen = len;
//			}
//			return maxLen;
//		}
//
//	private:
//		vector<Node*> _table;
//		size_t _size = 0;
//	};
//
//}
//using OpenHash::HashBucket;
//void Test1()
//{
//	int array[] = { 1,11, 4,15,26,7,44,55,99,78 };
//	HashBucket<int, int> ht;
//	for (auto& e : array) {
//		ht.insert(make_pair(e, e));
//	}
//	ht.insert(make_pair(22, 22));
//	ht.erase(44);
//	ht.erase(4);
//
//}
//void Test2() {
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
//
//	HashBucket<string, int> countHT;
//	for (auto& str : arr) {
//		auto ptr = countHT.find(str);
//		if (ptr) {
//			ptr->_kv.second++;
//		}
//		else {
//			countHT.insert(make_pair(str, 1));
//		}
//	}
//}
//int main() {
//	//Test1();
//	Test2();
//	return 0;
//}



















//#include <iostream>
//#include <vector>
//using std::vector;
//using std::cout;
//using std::endl;
//
//namespace bjy {
//	template<size_t N>
//	class bitset {
//	public:
//		bitset() {
//			if (N % 8 == 0) _bits.resize(N / 8, 0);
//			else _bits.resize(N / 8 + 1, 0);
//		}
//		void set(size_t which){
//			size_t i = which / 8, j = which % 8;
//			_bits[i] |= (1 << j);
//		}
//
//		void reset(size_t which) {
//			size_t i = which / 8, j = which % 8;
//			_bits[i] &= ~(1 << j);
//		}
//
//		bool test(size_t which)const {
//			size_t i = which / 8, j = which % 8;
//			return _bits[i] & (1 << j);
//		}
//	private:
//		vector<char> _bits;
//	};
//}
//
//
//
//using namespace bjy;
//void test_bit_set()
//{
//	bitset<100> bs;
//	bs.set(8);
//	bs.set(9);
//	bs.set(20);
//
//	cout << bs.test(8) << endl;
//	cout << bs.test(9) << endl;
//	cout << bs.test(20) << endl;
//
//	bs.reset(8);
//	bs.reset(9);
//	bs.reset(20);
//
//	cout << bs.test(8) << endl;
//	cout << bs.test(9) << endl;
//	cout << bs.test(20) << endl;
//
//	bitset<UINT_MAX> bss;
//}
//int main()
//{
//	test_bit_set();
//	return 0;
//}









//#include <iostream>
//#include <bitset>
//using namespace std;
//
//namespace bjy {
//	struct HashBKDR {
//		size_t operator()(const string& key) {
//			size_t sum = 0;
//			for (auto& e : key) {
//				sum = sum * 131 + e;
//			}
//			return sum;
//		}
//	};
//	struct HashAP {
//		size_t operator()(const string& key) {
//			size_t hash = 0;
//			for (size_t i = 0; i < key.size(); i++) {
//				if ((i & 1) == 0) {
//					hash ^= ((hash << 7) ^ key[i] ^ (hash >> 3));
//				}
//				else {
//					hash ^= (~((hash << 11) ^ key[i] ^ (hash >> 5)));
//				}
//			}
//			return hash;
//		}
//	};
//	struct HashDJB {
//		size_t operator()(const string& key) {
//			size_t hash = 5381;
//			for (auto ch : key) {
//				hash += (hash << 5) + ch;
//			}
//			return hash;
//		}
//	};
//
//	template<size_t N, class K, class Hash1 = HashBKDR, class Hash2 = HashAP, class Hash3 = HashDJB>
//	class Bloon_filter
//	{
//	public:
//		void set(const K& key) {
//			size_t pos1 = Hash1()(key) % (_ratio * N);
//			size_t pos2 = Hash2()(key) % (_ratio * N);
//			size_t pos3 = Hash3()(key) % (_ratio * N);
//			_bits.set(pos1);
//			_bits.set(pos2);
//			_bits.set(pos3);
//		}
//
//		void reset(const K& key) {
//
//		}
//
//		bool test(const K& key) {
//			size_t pos1 = Hash1()(key) % (_ratio * N);
//			size_t pos2 = Hash2()(key) % (_ratio * N);
//			size_t pos3 = Hash3()(key) % (_ratio * N);
//			if (_bits.test(pos1) && _bits.test(pos2) && _bits.test(pos3)) return true;
//			else return false;
//		}
//	private:
//		const static size_t _ratio = 5;
//		bitset<_ratio* N> _bits;
//	};
//
//
//	
//
//}
//
//using namespace bjy;
//void test()
//{
//	Bloon_filter<10, string> bf;
//	string arr1[] = { "苹果", "西瓜", "阿里", "美团", "苹果", "字节", "西瓜", "苹果", "香蕉", "苹果", "腾讯" };
//
//	for (auto& str : arr1){
//		bf.set(str);
//	}
//	for (auto& str : arr1){
//		cout << bf.test(str) << endl;
//	}
//
//	string arr2[] = { "苹果111", "西瓜", "阿里22", "美团", "苹果adx", "字节", "西瓜sSX", "苹果", "香蕉nj", "苹果", "腾讯@" };
//
//	for (auto& str : arr2){
//		cout << str << ":" << bf.test(str) << endl;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}






