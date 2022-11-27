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

1.����̽��: �ӷ�����ͻ��λ�ÿ�ʼ���������̽�⣬ֱ��Ѱ�ҵ���һ����λ��Ϊֹ
����: ͨ����ϣ������ȡ������Ԫ���ڹ�ϣ���е�λ��
	  ����λ����û��Ԫ����ֱ�Ӳ�����Ԫ�أ�����λ������Ԫ�ط�����ϣ��ͻ��ʹ������̽���ҵ���һ����λ�ã�������Ԫ��
ɾ��: ���ñ�ɢ�д����ϣ��ͻʱ�������������ɾ����ϣ�������е�Ԫ�ء�
	  ��ֱ��ɾ��Ԫ�ػ�Ӱ������Ԫ�ص��������������̽����ñ�ǵ�αɾ������ɾ��һ��Ԫ��





��ɢ��
�ֳ�����ַ��(������)�����ȶԹؼ��뼯����ɢ�к�������ɢ�е�ַ��������ͬ��ַ�Ĺؼ������ͬһ�Ӽ��ϡ�
ÿһ���Ӽ��ϳ�Ϊһ��Ͱ������Ͱ�е�Ԫ��ͨ��һ�������������������������ͷ���洢�ڹ�ϣ����
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
		if (find(kv.first) != nullptr) return false;//�������ֵ����

		if (_table.size() == 0 || 10 * _size / _table.size() >= 7) {//����
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V> new_table;
			new_table._table.resize(newSize);
			//�ɱ�����ӳ�䵽�±�
			for (auto& e : _table) {
				if (e._state == EXIST) {
					new_table.insert(e._kv);
				}
			}
			_table.swap(new_table._table);
		}

		size_t index = kv.first % _table.size();
		while (_table[index]._state == EXIST) {//����̽��
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
	size_t _size;//��Ч����
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












