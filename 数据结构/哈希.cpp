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







/*
#define LINEAR
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
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

template<class K>//Ĭ�Ϸº���
struct hash {
	size_t operator()(const K& key) {
		return (size_t)key;
	}
};
template<>//�ػ�
struct hash<string> {
	//BKDR�㷨
	size_t operator()(const string& key) {
		size_t sum = 0;
		for (auto& e : key) {
			sum = sum * 131 + e;
		}
		return sum;
	}
};

template<class K,class V, class Hash = hash<K>>
class HashTable
{
public:
	bool insert(const pair<K, V>& kv) {
		if (find(kv.first) != nullptr) return false;//�������ֵ����

		if (_table.size() == 0 || 10 * _size / _table.size() >= 5) {//����
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V, Hash> new_table;
			new_table._table.resize(newSize);
			//�ɱ�����ӳ�䵽�±�
			for (auto& e : _table) {
				if (e._state == EXIST) {
					new_table.insert(e._kv);
				}
			}
			_table.swap(new_table._table);
		}

#ifdef LINEAR
		Hash hash;
		size_t index = hash(kv.first) % _table.size();//int����Ϊsize_t
		while (_table[index]._state == EXIST) {//����̽��
			++index;
			index %= _table.size();
		}
#else //SECONDARY
		Hash hash;
		size_t start = hash(kv.first) % _table.size();//int����Ϊsize_t
		size_t index = start,i = 0;
		while (_table[index]._state == EXIST) {//����̽��
			++i;
			index =  start + i * i;
			index %= _table.size();
		}
#endif

		_table[index]._kv = kv;
		_table[index]._state = EXIST;
		++_size;
		return true;
	}

	bool erase(const K& key) {
		HashData<K,V>* ret = find(key);
		if (ret == nullptr) {
			return false;
		}
		else {
			ret->_state = DELETE;
			--_size;
			return true;
		}
	}

	HashData<K,V>* find(const K& key) {
		if (_table.size() == 0) return nullptr;
#ifdef LINEAR
		Hash hash;
		size_t start = hash(key) % _table.size();//int����Ϊsize_t
		size_t index = start;
		while (_table[index]._state != EMPTY) {
			if (_table[index]._state != DELETE && _table[index]._kv.first == key) {
				return &_table[index];
			}
			++index;
			index %= _table.size();
			if (index == start) {//����ϣ����ȫΪDELETE �� EXISTʱ������ѭ��
				break;
			}
		}
#else //SECONDARY
		Hash hash;
		size_t start = hash(key) % _table.size();//int����Ϊsize_t
		size_t index = start, i = 0;
		while (_table[index]._state == EXIST) {//����̽��
			if (_table[index]._state != DELETE && _table[index]._kv.first == key) {
				return &_table[index];
			}
			++i;
			index = start + i * i;
			index %= _table.size();
		}
#endif
		return nullptr;
	}

private:
	vector<HashData<K, V>> _table;
	size_t _size;//��Ч����
};






void  Test1() {
	int array[] = { 1,11,4,15,26,7,44,9 };
	HashTable<int, int> ht;
	for (auto& e : array)
	{
		ht.insert(make_pair(e, e));
	}
	ht.erase(4);
	cout << ht.find(44)->_kv.first << endl;
}
void Test2() {
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

	HashTable<string, int> countHT;
	for (auto& str : arr){
		auto ptr = countHT.find(str);
		if (ptr){
			ptr->_kv.second++;
		}
		else{
			countHT.insert(make_pair(str, 1));
		}
	}
}
int main()
{
	//Test1();
	Test2();
	return 0;
}
*/











