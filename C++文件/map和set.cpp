//����ʽ����: vector��list��deque
//����ʽ����: map��set

/*
����ʽ����Ҳ�������洢���ݵģ�������ʽ������ͬ���ǣ�������洢����<key, value>�ṹ�ļ�ֵ�ԣ������ݼ���ʱ������ʽ����Ч�ʸ���
*/


//��ֵ��
/*
������ʾ����һһ��Ӧ��ϵ��һ�ֽṹ���ýṹ��һ��ֻ����������Ա����key��value��key�����ֵ��value��ʾ��key��Ӧ����Ϣ
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
1. set�ǰ���һ������洢Ԫ�ص�����

2. ��set�У�Ԫ�ص�valueҲ��ʶ��(value����key������ΪT)������ÿ��value������Ψһ�ġ�
set�е�Ԫ�ز������������޸�(Ԫ������const)�����ǿ��Դ������в����ɾ�����ǡ�

3. ���ڲ���set�е�Ԫ�����ǰ������ڲ��Ƚ϶���(���ͱȽ�)��ָʾ���ض��ϸ�������׼��������� set�е�Ԫ��Ĭ�ϰ���С�����Ƚ�

4. set����ͨ��key���ʵ���Ԫ�ص��ٶ�ͨ����unordered_set���������������������˳����Ӽ�����ֱ�ӵ�����
 set�в���ĳ��Ԫ�أ�ʱ�临�Ӷ�ΪO(log_2 n)

5. set�ڵײ����ö���������(�����)ʵ�ֵ�
*/

//multiset
/*
1. multiset�ǰ����ض�˳��洢Ԫ�ص�����������Ԫ���ǿ����ظ���

2. ��multiset�У�Ԫ�ص�valueҲ��ʶ����
(��Ϊmultiset�б���洢�ľ���<value, value>��ɵļ�ֵ�ԣ����value�������key��key����value������ΪT)
multisetԪ�ص�ֵ�����������н����޸�(��ΪԪ������const��)�������Դ������в����ɾ����

3. ���ڲ���multiset�е�Ԫ�����ǰ������ڲ��ȽϹ���(���ͱȽ�)��ָʾ���ض��ϸ�������׼���������

4. multiset����ͨ��key���ʵ���Ԫ�ص��ٶ�ͨ����unordered_multiset������������ʹ�õ���������ʱ��õ�һ����������

5. multiset�ײ�ṹΪ����������(�����)

6. ��multiset����ĳ��Ԫ�أ�ʱ�临�Ӷ�ΪO(log_2 N)
*/



//map
/*
1. map�ǹ����������������ض��Ĵ���(����key���Ƚ�)�洢�ɼ�ֵkey��ֵvalue��϶��ɵ�Ԫ��

2. ��map�У���ֵkeyͨ�����������Ωһ�ر�ʶԪ�أ���ֵvalue�д洢��˼�ֵkey����������
��ֵkey��ֵvalue�����Ϳ��ܲ�ͬ��������map���ڲ���key��valueͨ����Ա����value_type����һ��Ϊ��ȡ������Ϊpair
typedef pair<const key, T> value_type;

3. ���ڲ���map�е�Ԫ�����ǰ��ռ�ֵkey���бȽ������

4. map��ͨ����ֵ���ʵ���Ԫ�ص��ٶ�ͨ����unordered_map������
��map�������˳���Ԫ�ؽ���ֱ�ӵ���(����map�е�Ԫ�ؽ��е���ʱ�����Եõ�һ�����������)

5. map֧���±���ʷ�������[]�з���key���Ϳ����ҵ���key��Ӧ��value

6. mapͨ����ʵ��Ϊƽ�����������(�����)
*/

//multimap
/*
1. multimaps�ǹ���ʽ�������������ض���˳�򣬴洢��key��valueӳ��ɵļ�ֵ��<key,value>�����ж����ֵ��֮���key�ǿ����ظ���

2. ��multimap�У�ͨ������key�����Ωһ�ر�ʶԪ�أ���ӳ���value�洢��key����������
key��value�����Ϳ��ܲ�ͬ��ͨ��multimap�ڲ��ĳ�Ա����value_type�����һ��value_type�����key��value�ļ�ֵ��:
typedef pair<const Key, T> value_type;

3. ���ڲ���multimap�е�Ԫ������ͨ�����ڲ��Ƚ϶��󣬰���ָ�����ض��ϸ��������׼��key���������

4. multimapͨ��key���ʵ���Ԫ�ص��ٶ�ͨ����unordered_multimap������������ʹ�õ�����ֱ�ӱ���multimap�е�Ԫ�ؿ��Եõ�����key���������

5. multimap�ڵײ��ö���������(�����)��ʵ��

ע��: multimap��map��Ψһ��ͬ����: map�е�key��Ψһ�ģ���multimap��key�ǿ����ظ���
*/