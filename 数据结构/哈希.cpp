/*
˳��ṹ�Լ�ƽ�����У�Ԫ�عؼ�������洢λ��֮��û�ж�Ӧ�Ĺ�ϵ������ڲ���һ��Ԫ��ʱ������Ҫ�����ؼ���Ķ�αȽϡ�
˳�����ʱ�临�Ӷ�ΪO(N)��ƽ������Ϊ���ĸ߶ȣ���O(log_2 N)��������Ч��ȡ��������������Ԫ�صıȽϴ�����
������������������Բ������καȽϣ�һ��ֱ�Ӵӱ��еõ�Ҫ������Ԫ�ء�
�������һ�ִ洢�ṹ��ͨ��ĳ�ֺ���(hashFunc)ʹԪ�صĴ洢λ�������Ĺؼ���֮���ܹ�����һһӳ��Ĺ�ϵ����ô�ڲ���ʱͨ���ú������Ժܿ��ҵ���Ԫ��
*/
/*
����Ԫ��:
���ݴ�����Ԫ�صĹؼ��룬�Դ˺����������Ԫ�صĴ洢λ�ò�����λ�ý��д��
����Ԫ��:
��Ԫ�صĹؼ������ͬ���ļ��㣬����õĺ���ֵ����Ԫ�صĴ洢λ�ã��ڽṹ�а���λ��ȡԪ�رȽϣ����ؼ�����ȣ��������ɹ�

�÷�ʽ��Ϊ��ϣ(ɢ��)��������ϣ������ʹ�õ�ת��������Ϊ��ϣ(ɢ��)��������������Ľṹ��Ϊ��ϣ��(Hash Table)(���߳�ɢ�б�)
*/


//��ϣ��ͻ
/*
��ͬ�ؼ���ͨ����ͬ��ϣ�����������ͬ�Ĺ�ϣ��ַ�����������Ϊ��ϣ��ͻ���ϣ��ײ��
�Ѿ��в�ͬ�ؼ����������ͬ��ϣ��ַ������Ԫ�س�Ϊ��ͬ��ʡ���
*/
//��ϣ����
/*
�����ϣ��ͻ��һ��ԭ�������: ��ϣ������Ʋ�������
��ϣ�������ԭ��:
1. ��ϣ�����Ķ�������������Ҫ�洢��ȫ���ؼ��룬�����ɢ�б�������m����ַʱ����ֵ�������0��m-1֮��
2. ��ϣ������������ĵ�ַ�ܾ��ȷֲ��������ռ���
3. ��ϣ����Ӧ�ñȽϼ�
*/

/*
��ϣ��ͻ�Ľ��:
�����ϣ��ͻ���ֳ����ķ�����: ��ɢ�кͿ�ɢ��

��ɢ��
Ҳ�п��Ŷ�ַ������������ϣ��ͻʱ�������ϣ��δ��װ����˵���ڹ�ϣ���б�Ȼ���п�λ�ã���ô���԰�key��ŵ���ͻλ���е�"��һ��"��λ����ȥ

1. ����̽��: �ӷ�����ͻ��λ�ÿ�ʼ���������̽�⣬ֱ��Ѱ�ҵ���һ����λ��Ϊֹ
����: ͨ����ϣ������ȡ������Ԫ���ڹ�ϣ���е�λ��
	  ����λ����û��Ԫ����ֱ�Ӳ�����Ԫ�أ�����λ������Ԫ�ط�����ϣ��ͻ��ʹ������̽���ҵ���һ����λ�ã�������Ԫ��
ɾ��: ���ñ�ɢ�д����ϣ��ͻʱ�������������ɾ����ϣ�������е�Ԫ�ء�
	  ��ֱ��ɾ��Ԫ�ػ�Ӱ������Ԫ�ص��������������̽����ñ�ǵ�αɾ������ɾ��һ��Ԫ��

2. ����̽��
����̽���ȱ���ǲ�����ͻ�����ݶѻ���һ�飬����������һ����λ���й�ϵ(�������ȥ��)��
��˶���̽��Ϊ�˱�������⣬����һ����λ�õķ���Ϊ: H_i = (H_0 + i^2) % m, ����: H_i = (H_0 - i^2) % m������: i = 0,1,2,3����
H_0��ͨ��ɢ�к���Hash(x)��Ԫ�صĹؼ��� key ���м���õ���λ�ã�m�Ǳ�Ĵ�С��

�о�����: ����ĳ���Ϊ�����ұ�װ������a������0.5ʱ���µı���һ���ܹ����룬�����κ�һ��λ�ö����ᱻ̽�����Ρ�
���ֻҪ������һ��Ŀ�λ�ã�������ʱ���Բ����Ǳ�װ������������ڲ���ʱ����ȷ�����װ������a������0.5�����������뿼������



��ɢ��
�ֳ�����ַ��(������)�����ȶԹؼ��뼯����ɢ�к�������ɢ�е�ַ��������ͬ��ַ�Ĺؼ������ͬһ�Ӽ��ϡ�
ÿһ���Ӽ��ϳ�Ϊһ��Ͱ������Ͱ�е�Ԫ��ͨ��һ�������������������������ͷ���洢�ڹ�ϣ����
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
//	template<class K>//Ĭ�Ϸº���
//	struct hash {
//		size_t operator()(const K& key) {
//			return (size_t)key;
//		}
//	};
//	template<>//�ػ�
//	struct hash<string> {
//		//BKDR�㷨
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
//			if (find(kv.first) != nullptr) return false;//�������ֵ����
//
//			if (_table.size() == 0 || 10 * _size / _table.size() >= 5) {//����
//				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
//				HashTable<K, V, Hash> new_table;
//				new_table._table.resize(newSize);
//				//�ɱ�����ӳ�䵽�±�
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
//			size_t index = hash(kv.first) % _table.size();//int����Ϊsize_t
//			while (_table[index]._state == EXIST) {//����̽��
//				++index;
//				index %= _table.size();
//			}
//#else //SECONDARY
//			Hash hash;
//			size_t start = hash(kv.first) % _table.size();//int����Ϊsize_t
//			size_t index = start, i = 0;
//			while (_table[index]._state == EXIST) {//����̽��
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
//			size_t start = hash(key) % _table.size();//int����Ϊsize_t
//			size_t index = start;
//			while (_table[index]._state != EMPTY) {
//				if (_table[index]._state != DELETE && _table[index]._kv.first == key) {
//					return &_table[index];
//				}
//				++index;
//				index %= _table.size();
//				if (index == start) {//����ϣ����ȫΪDELETE �� EXISTʱ������ѭ��
//					break;
//				}
//			}
//#else //SECONDARY
//			Hash hash;
//			size_t start = hash(key) % _table.size();//int����Ϊsize_t
//			size_t index = start, i = 0;
//			while (_table[index]._state == EXIST) {//����̽��
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
//		size_t _size = 0;//��Ч����
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
//	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
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
//	template<class K>//Ĭ�Ϸº���
//	struct hash {
//		size_t operator()(const K& key) {
//			return (size_t)key;
//		}
//	};
//	template<>//�ػ�
//	struct hash<string> {
//		//BKDR�㷨
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
//			if (find(kv.first) != nullptr) return false;//�������ֵ����
//
//			//�������ӵ���1��������
//			if (_table.size() == 0 || _size == _table.size()) {
//				vector<Node*> new_table;
//				new_table.resize(__stl_next_prime(_table.size()), nullptr);
//				for (size_t i = 0; i < _table.size(); ++i) {
//					Node* cur = _table[i];
//					while (cur != nullptr) {
//						Node* next = cur->_next;
//						size_t hashi = hash(cur->_kv.first) % new_table.size();
//						//ͷ��
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
//			//ͷ��
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
//					if (prev == nullptr) {//ͷɾ
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
//		//�洢��Ԫ�ظ���
//		size_t size() { return _size; }
//
//		// ��ĳ���
//		size_t table_size()
//		{
//			return _tables.size();
//		}
//
//		// Ͱ�ĸ���
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
//	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
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
//	string arr1[] = { "ƻ��", "����", "����", "����", "ƻ��", "�ֽ�", "����", "ƻ��", "�㽶", "ƻ��", "��Ѷ" };
//
//	for (auto& str : arr1){
//		bf.set(str);
//	}
//	for (auto& str : arr1){
//		cout << bf.test(str) << endl;
//	}
//
//	string arr2[] = { "ƻ��111", "����", "����22", "����", "ƻ��adx", "�ֽ�", "����sSX", "ƻ��", "�㽶nj", "ƻ��", "��Ѷ@" };
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






